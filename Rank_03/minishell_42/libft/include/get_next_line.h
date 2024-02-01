/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: verdant <verdant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:38 by mwilsch           #+#    #+#             */
/*   Updated: 2022/12/25 13:11:56 by verdant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

int		ft_strclen_bool(char *buf, bool search_newline);
char	*ft_concat(char *s1, char *s2, int s1_len);
char	*get_next_line(int fd);
int		check_char(char *buf);

#endif
