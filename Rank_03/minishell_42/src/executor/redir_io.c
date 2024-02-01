/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redir_io.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: verdant <verdant@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/29 16:26:30 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/31 15:59:10 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	process_redirection(t_cmds *cmd, int *pipe_fd)
{
	int	heredoc_fd;

	heredoc_fd = -1;
	handle_heredoc(cmd, &heredoc_fd);
	if (heredoc_fd >= 0)
	{
		if (close(heredoc_fd) < 0)
			p_error("close", EXIT_FAILURE);
	}
	if (!heredoc_fd)
		cmd->in_fd = pipe_fd[0];
	cmd->out_fd = pipe_fd[1];
	redirect_command_fd(cmd);
}

int	redirect_command_fd(t_cmds *head)
{
	int	i;

	i = 0;
	while (i < head->redircnt)
	{
		if (head->redir[i].type == TRUNC || head->redir[i].type == APPEND)
			redirect_output(&head->redir[i]);
		else
			redirect_input(&head->redir[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	redirect_input(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir == NULL)
		p_error("NULL redir", EXIT_FAILURE);
	if (redir->type == INPUT)
		fd = open(redir->filename, O_RDONLY);
	else if (redir->type == INPUT_EOF)
		return (EXIT_SUCCESS);
	if (fd < 0)
		p_error("open", EXIT_FAILURE);
	if (dup2(fd, STDIN_FILENO) < 0)
		wr_dup2(fd, STDIN_FILENO);
	if (close(fd) < 0)
		p_error("close", EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	redirect_output(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir == NULL)
		p_error("NULL redir", EXIT_FAILURE);
	if (redir->type == TRUNC)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (redir->type == APPEND)
		fd = open(redir->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		p_error("open", EXIT_FAILURE);
	if (dup2(fd, STDOUT_FILENO) < 0)
		wr_dup2(fd, STDOUT_FILENO);
	if (close(fd) < 0)
		p_error("close", EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
