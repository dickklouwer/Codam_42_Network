/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mwilsch <mwilsch@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 11:45:38 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/23 08:41:23 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	handle_heredoc(t_cmds *cmd, int *heredoc_fd)
{
	if (cmd->redir && cmd->redir->type == INPUT_EOF)
	{
		*heredoc_fd = heredoc(cmd->redir->filename);
		if (*heredoc_fd >= 0)
		{
			if (dup2(*heredoc_fd, STDIN_FILENO) < 0)
				perror("dup2 heredoc");
		}
	}
}

int	heredoc(const char *delimiter)
{
	int		pipefd[2];
	char	*line;

	line = NULL;
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		{
			free(line);
			break ;
		}
		write(pipefd[1], line, ft_strlen(line));
		write(pipefd[1], "\n", 1);
		free(line);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
