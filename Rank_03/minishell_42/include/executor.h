/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executor.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 11:18:31 by mwilsch       #+#    #+#                 */
/*   Updated: 2023/05/31 15:52:42 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

int						g_status;

typedef struct t_args	t_args;
typedef struct s_env	t_env;

typedef enum e_cmd_type {
	CMD_EXE,
	BUILT_IN_EXE,
	NO_CMD_EXE,
}	t_cmd_type;

typedef enum e_redirect_type {
	TRUNC,
	APPEND,
	INPUT,
	INPUT_EOF,
	ERR,
}	t_redirect_type;

typedef struct s_redir {
	char			*filename;
	int				redirc;
	t_redirect_type	type;
}	t_redir;

typedef struct s_cmds {
	char		*cmd_path;
	char		**argv;
	int			argc;
	int			redircnt;
	int			in_fd;
	int			out_fd;
	int			status;
	t_env		**env;
	t_redir		*redir;
	t_cmd_type	cmd_type;
}	t_cmds;

/* 			INIT_STRUCTS		 */
t_cmds	*create_structs(t_args *head, int *cmd_cnt, t_env **env);

/* 			BUILT-INS			 */
int		echo(int argc, char **argv);
int		cd(int argc, char *path, t_env *env_list);
int		pwd(void);
int		env(t_env **env_list, bool export);
int		export(int argc, char *argv[], t_env **env_list);
int		unset(int argc, char *argv[], t_env **env_list);
int		exec_builtin(char *func, int argc, char **argv, t_env **env_list);
int		exisit_env(t_env **env_list, char *str, t_env **found);
int		mini_exit(t_cmds *cmd);

/* 				UTILS			 */
int		count_args(char **argv);
void	execute_command(t_cmds *head);
int		p_error(char *str, int status);
int		wr_dup2(int fd1, int fd2);
void	cleanup(int cmd_cnt, t_cmds *cmd, int *pipe_fd);
bool	check_flag(char *argv[], int *i);
void	execute_cmd_or_builtin(t_cmds *cmd);

/* 				EXECUTE	 */
int		executor(t_args *head, t_env **env);
void	child_process(t_cmds *cmd, int i, int cmd_cnt, int *pipe_fd);
void	parent_process(pid_t child_pid);
void	exec_pipeline(t_cmds *cmd, int cmd_cnt, int *pipe_fd, pid_t *pid);

/* 				HEREDOC			 */
void	handle_heredoc(t_cmds *cmd, int *heredoc_fd);
int		heredoc(const char *delimiter);

/* 				REDIR IO		 */
void	redirect_pipe_fd(int i, int cmd_cnt, int *pipe_fd);
int		redirect_command_fd(t_cmds *head);
int		redirect_input(t_redir *redir);
int		redirect_output(t_redir *redir);
int		*create_pipes(int cmd_cnt);
void	process_redirection(t_cmds *cmd, int *pipe_fd);

/* 				REDIR_UTILS		 */
void	child_signal_handler(int signum);
void	close_pipes(int *pipe_fd, int cmd_cnt, int current_cmd, int used);

#endif