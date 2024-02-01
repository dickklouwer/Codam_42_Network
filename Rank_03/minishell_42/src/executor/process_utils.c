/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/22 11:12:21 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/31 15:50:47 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	execute_cmd_or_builtin(t_cmds *cmd)
{
	if (cmd->cmd_type == BUILT_IN_EXE)
		exec_builtin(cmd->cmd_path, cmd->argc, cmd->argv, cmd->env);
	else
		execute_command(cmd);
	exit(EXIT_SUCCESS);
}

int	*create_pipes(int cmd_cnt)
{
	int	*pipe_fd;
	int	i;

	i = 0;
	pipe_fd = (int *)calloc(2 * cmd_cnt, sizeof(int));
	if (pipe_fd == NULL)
		p_error("calloc", EXIT_FAILURE);
	while (i < cmd_cnt)
	{
		if (pipe(pipe_fd + 2 * i) < 0)
			p_error("pipe", EXIT_FAILURE);
		i++;
	}
	return (pipe_fd);
}
