/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 10:41:39 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/22 13:20:02 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	execute_command(t_data *data, char **cmd, char **envp)
{
	char	*file_cmd;

	file_cmd = command_path(data, *cmd);
	if (!file_cmd)
	{
		p_error("Command not found", 127);
	}
	if (execve(file_cmd, cmd, envp) == -1)
	{
		p_error("Execve failed", 127);
	}
}

void	child_process(t_data *data, int *end, char **envp)
{
	int	infile;

	infile = open(data->argv[1], O_RDONLY);
	if (infile < 0)
		p_error("", 1);
	if (dup2(infile, STDIN_FILENO) < 0)
		wr_dup2(infile, end[1]);
	if (dup2(end[1], STDOUT_FILENO) < 0)
		wr_dup2(infile, end[1]);
	close(end[0]);
	close(infile);
	execute_command(data, data->cmd1, envp);
}

void	child_process2(t_data *data, int *end, char **envp)
{
	int	outfile;

	outfile = open(data->argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (outfile < 0)
		p_error("", 1);
	if (dup2(end[0], STDIN_FILENO) < 0)
		wr_dup2(outfile, end[0]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		wr_dup2(outfile, end[0]);
	close(end[1]);
	close(outfile);
	execute_command(data, data->cmd2, envp);
}

int	parent_process(int *end, pid_t child1, pid_t child2)
{
	int	exit_code;

	close(end[0]);
	close(end[1]);
	waitpid(child1, &exit_code, 0);
	waitpid(child2, &exit_code, 0);
	if (WIFEXITED(exit_code) > 0)
	{
		return (WEXITSTATUS(exit_code));
	}
	return (exit_code);
}

int	pipex(t_data *data, char **envp)
{
	int		end[2];
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) < 0)
		perror("pipe");
	child1 = fork();
	if (child1 < 0)
		perror("Fork:");
	else if (child1 == 0)
		child_process(data, end, envp);
	child2 = fork();
	if (child2 < 0)
		perror("Fork");
	else if (child2 == 0)
		child_process2(data, end, envp);
	return (parent_process(end, child1, child2));
}
