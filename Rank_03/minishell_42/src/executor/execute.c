/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/22 16:40:17 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/01 08:47:47 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <sys/wait.h>

void	parent_process(pid_t child_pid)
{
	int	status;

	waitpid(child_pid, &status, 0);
	if (WIFEXITED(status))
	{
		g_status = WEXITSTATUS(status);
	}
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			g_status = 130;
		else if (WTERMSIG(status) == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_status = 131;
		}
		else
			g_status = 130;
	}
}

void	child_process(t_cmds *cmd, int i, int cmd_cnt, int *pipe_fd)
{
	if (i > 0)
	{
		if (dup2(pipe_fd[2 * (i - 1)], STDIN_FILENO) == -1)
			p_error("dup2", EXIT_FAILURE);
	}
	if (i < cmd_cnt - 1)
	{
		if (dup2(pipe_fd[2 * i + 1], STDOUT_FILENO) == -1)
			p_error("dup2", EXIT_FAILURE);
	}
	close_pipes(pipe_fd, cmd_cnt, i, 1);
	if (cmd->redir)
		process_redirection(cmd, pipe_fd);
	if (cmd->cmd_type == BUILT_IN_EXE)
	{
		exec_builtin(cmd->cmd_path, cmd->argc, cmd->argv, cmd->env);
		exit (0);
	}
	else
		execute_command(cmd);
}

void	exec_pipeline(t_cmds *cmd, int cmd_cnt, int *pipe_fd, pid_t *pid)
{
	int	i;

	i = 0;
	while (i < cmd_cnt)
	{
		pid[i] = fork();
		if (pid[i] < 0)
			p_error("fork", 1);
		else if (pid[i] == 0)
		{
			signal(SIGINT, child_signal_handler);
			signal(SIGQUIT, child_signal_handler);
			child_process(&cmd[i], i, cmd_cnt, pipe_fd);
		}
		i++;
	}
}

void	shell_process(t_cmds *cmd, int cmd_cnt, int *pipe_fd)
{
	pid_t	*pid;
	int		i;

	i = 0;
	pid = malloc(sizeof(pid_t) * cmd_cnt);
	if (pid == NULL)
		p_error("malloc", EXIT_FAILURE);
	exec_pipeline(cmd, cmd_cnt, pipe_fd, pid);
	close_pipes(pipe_fd, cmd_cnt, cmd_cnt, 1);
	while (i < cmd_cnt)
	{
		parent_process(pid[i]);
		i++;
	}
	free(pid);
}

/* RESPONSIBLE FOR SETTING UP THE NECESSARY STRUCTURES FOR HANDLING COMMANDS
	AND MANAGING THE CHILD PROCESSES.
	- CMND_CNT = NUMBER OF COMMANDS.
	- PIPE_FD = ARRAY OF FILE DESCRIPTORS FOR THE PIPES
	- BUILT-INS NEED TO BE EXECUTED IN THE PARENT PROCESS. SO WE DONT FORK THEM. 
 */
int	executor(t_args *head, t_env **env_l)
{
	t_cmds			*cmd;
	int				cmd_cnt;
	int				*pipe_fd;

	cmd_cnt = 1;
	pipe_fd = NULL;
	cmd = create_structs(head, &cmd_cnt, env_l);
	if (ft_strcmp("exit", head->arg) == 0)
	{
		if (mini_exit(cmd))
			return (EXIT_FAILURE);
	}
	if (cmd->cmd_type == BUILT_IN_EXE && cmd_cnt == 1
		&& ft_strcmp("echo", head->arg) != 0)
		exec_builtin(cmd->cmd_path, cmd->argc, cmd->argv, cmd->env);
	else
	{
		pipe_fd = create_pipes(cmd_cnt);
		shell_process(cmd, cmd_cnt, pipe_fd);
	}
	cleanup(cmd_cnt, cmd, pipe_fd);
	return (g_status);
}
