/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:23:38 by dickklouwer   #+#    #+#                 */
/*   Updated: 2022/11/29 14:47:06 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE    1054
# define GNL_ERROR      -1
# define READING        1

int		out_check(int ret, int nbytes, char *buf, char **line);
int		get_next_line(int fd, char **line);
char	*ft_memcccpy(char *dst, char *src, int c, size_t n);
size_t	ft_strlen_g(const char *s);
char	*ft_strdup_g(const char *s1);
char	*ft_strchr_g(const char *s, int c);
char	*buf_move(char *buf);
int		next_line(char *buf, char **line);

#endif
