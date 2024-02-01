/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/07 10:28:11 by dickklouwer   #+#    #+#                 */
/*   Updated: 2020/12/16 14:23:29 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		out_check(int ret, int nbytes, char *buf, char **line)
{
	*buf = *buf_move(buf);
	if (nbytes < 0)
	{
		free(*line);
		return (GNL_ERROR);
	}
	return (ret);
}

char	*buf_move(char *buf)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	i++;
	while (i < BUFFER_SIZE)
	{
		buf[j] = buf[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

int		next_line(char *buf, char **line)
{
	char	*temp;
	int		len;

	len = (ft_strlen(buf) + ft_strlen(*line));
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (GNL_ERROR);
	ft_memccpy(temp, *line, '\0', ft_strlen(*line));
	ft_memccpy(temp + ft_strlen(*line), buf, '\n', ft_strlen(buf));
	temp[len] = '\0';
	free(*line);
	*line = temp;
	len = ft_strchr(buf, '\n') == NULL ? 0 : 1;
	return (len);
}

int		get_next_line(int fd, char **line)
{
	static char		buf[OPEN_MAX][BUFFER_SIZE + 1];
	int				nbytes;
	int				ret;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (GNL_ERROR);
	nbytes = 1;
	*line = ft_strdup("");
	ret = next_line(buf[fd], line);
	if (ret)
		return (out_check(ret, nbytes, buf[fd], line));
	while (nbytes > 0)
	{
		nbytes = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][BUFFER_SIZE] = '\0';
		if (nbytes < 0)
			return (GNL_ERROR);
		ret = next_line(buf[fd], line);
		if (ret)
			return (out_check(ret, nbytes, buf[fd], line));
	}
	return (0);
}
