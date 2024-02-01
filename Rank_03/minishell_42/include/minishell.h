/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:38:21 by verdant           #+#    #+#             */
/*   Updated: 2023/05/31 09:49:03 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "errno.h"
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "executor.h"

/**
 * @brief Gives high level meaning to the tokens
 * 
 * @param OPERATOR a token which includes a redirect or a pipe
 * @param ARG a token which can be a command (if it's the first) or a argument
 * @param QUOTE_ARG Chained arguments.
*/

typedef enum s_tokens {
	OPERATOR,
	ARG,
	PIPE,
	QUOTE_ARG,
	CMD,
	BUILT_IN,
	REDIR,
	REPROMPT,
}	t_type_tok;

typedef enum s_err_toks {
	OK,
	NO_CMD,
	NO_FILE_DIR,
	TO_MANY,
	NO_ALNUM_BETWEEN,
	NEWLINE_ERR,
	ENV_REDIRECT_ERR,
}	t_err_tok;

typedef struct t_args {
	char			*arg;
	t_type_tok		type;
	t_err_tok		err_tok;
	struct t_args	*next;
	struct t_args	*prev;
}	t_args;

typedef struct s_env {
	char			*key;
	char			*value;
	bool			export_only;
	struct s_env	*next;
}	t_env;

/*			Helper_1			*/
void		free_list(t_args *head);
bool		incl_char(char c, char *search_str);
bool		are_quotes_even(char *input);
char		*del_substr(char *str, int start, int len);
int			cnt_len_between(char *str, char c, int index);
char		*del_quotes(char *str);
int			cnt_occur(char *str, char c);
int			ft_lstsize_shell(t_env *env);
bool		is_valid_pipe(char *input);
t_args		*create_delimiter_node(t_args *temp, char *str);

/*			Tokenizer			*/
char		*get_tok(char *input, int start, t_type_tok type);
int			add_tok(char *str, t_args **head, t_type_tok type);
t_args		*create_node(char *str, t_type_tok type);
t_args		*create_tok_list(char *input, t_args *head);
t_args		*process_tok(t_args *head, char *input, t_env **env);

/*			Command Resolution			*/
bool		is_builtin(t_args *node);
char		*cmd_err(t_args *node, t_env **env);
char		*prep_cmd(char *str);
char		*resolute_cmd(t_args *node, char *cmd, t_env **env);

/*			Environment Subsitution			*/
int			get_env_len(char *str);
char		*sub_env(char *str, int env_len, t_env **env);

/*			Redirect Checking			*/
int			err_msg(t_err_tok err);
int			env_var_case(char *str, int env_len, int cnt, t_env **env);
int			c_red(char *str, int cnt, t_args *node, t_env **env);

/*			Environment			*/
char		**convert_data(t_env *env);
t_env		*get_key_value(t_env *node, char *str);
t_env		*add_first_node(t_env *env_head, char *str);
void		add_end(t_env **head, char *str, bool export_only);
void		env_init(t_env **env, char **envp);

#endif