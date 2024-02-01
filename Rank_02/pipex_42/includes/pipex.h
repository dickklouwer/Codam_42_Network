/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/02 13:50:49 by tklouwer      #+#    #+#                 */
/*   Updated: 2022/12/22 09:03:06 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_data
{
	char	**path_vars;
	char	**argv;
	char	*path;
	char	**cmd1;
	char	**cmd2;
}			t_data;

/* 
	PIPEX.C
*/
int		pipex(t_data *data, char **envp);

/* 
	PARSING.C
*/
char	*command_path(t_data *data, char *cmd);
int		parse_path(t_data *data, char **argv, char **envp);

/* 
	UTILS.C
*/
int		arraylen(char **arr);
int		wr_dup2(int fd1, int fd2);
int		p_error(char *str, int fd);

#endif