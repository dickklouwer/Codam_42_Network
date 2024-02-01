/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mwilsch <mwilsch@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/24 11:27:54 by mwilsch       #+#    #+#                 */
/*   Updated: 2023/05/22 12:16:01 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	init_members(t_cmds *cmd)
{
	cmd->in_fd = 0;
	cmd->out_fd = 0;
	cmd->status = 0;
	cmd->argv = NULL;
	cmd->redir = NULL;
	if (cmd->cmd_path == NULL)
		cmd->cmd_type = NO_CMD_EXE;
	cmd->argv = (char **)malloc(sizeof(char *) * (cmd->argc + 1));
	if (cmd->redircnt > 0)
		cmd->redir = (t_redir *)malloc(sizeof(t_redir) * cmd->redircnt);
	if (!cmd->argv || (cmd->redircnt > 0 && !cmd->redir))
		return ;
	cmd->argv[0] = cmd->cmd_path;
	cmd->argv[cmd->argc] = NULL;
}

void	arg_counter(t_args *head, t_cmds *cmd)
{
	cmd->cmd_path = NULL;
	cmd->argc = 1;
	cmd->redircnt = 0;
	cmd->cmd_type = CMD_EXE;
	while (head && head->type != PIPE)
	{
		if ((head->type == CMD || head->type == BUILT_IN)
			&& head->err_tok == OK)
		{
			cmd->cmd_path = head->arg;
			if (head->type == BUILT_IN)
				cmd->cmd_type = BUILT_IN_EXE;
		}
		if (head->type == ARG || head->type == QUOTE_ARG)
			cmd->argc++;
		if (head->type == REDIR)
			cmd->redircnt++;
		head = head->next;
	}
	init_members(cmd);
}

bool	redir_init(t_redir *redir, char *str, t_err_tok err_type)
{
	const char	c = str[0];
	const int	cnt = cnt_occur(str, str[0]);
	int			file_length;

	redir->filename = NULL;
	file_length = ft_strlen(str) - cnt;
	if (err_type == ENV_REDIRECT_ERR)
		return (redir->type = ERR, true);
	redir->filename = ft_substr(str, cnt, file_length);
	if (!redir->filename)
		return (false);
	if (c == '>' && cnt == 1)
		redir->type = TRUNC;
	if (c == '>' && cnt == 2)
		redir->type = APPEND;
	if (c == '<' && cnt == 1)
		redir->type = INPUT;
	if (c == '<' && cnt == 2)
		redir->type = INPUT_EOF;
	return (true);
}

t_args	*fill_struct(t_cmds *cmd, t_args *head)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (cmd->argc == 0 && cmd->redircnt == 0)
		return (head);
	while (true)
	{
		if (i < cmd->argc && (head->type == ARG || head->type == QUOTE_ARG))
			cmd->argv[i++] = head->arg;
		if (k < cmd->redircnt && head->type == REDIR)
			redir_init(&cmd->redir[k++], head->arg, head->err_tok);
		head = head->next;
		if (i == cmd->argc && k == cmd->redircnt)
			break ;
	}
	if (head && head->type == PIPE)
		head = head->next;
	return (head);
}

t_cmds	*create_structs(t_args *head, int *cmd_cnt, t_env **env)
{
	t_args	*tmp;
	t_cmds	*cmds;
	int		i;

	tmp = head;
	i = 0;
	while (tmp)
	{
		if (tmp->type == PIPE)
			(*cmd_cnt)++;
		tmp = tmp->next;
	}
	cmds = (t_cmds *)malloc(sizeof(t_cmds) * (*cmd_cnt));
	if (!cmds)
		return (NULL);
	while (i < (*cmd_cnt))
	{
		arg_counter(head, &cmds[i]);
		head = fill_struct(&cmds[i], head);
		cmds[i].env = env;
		i++;
	}
	return (cmds);
}
