# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tklouwer <tklouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/13 10:02:57 by tklouwer      #+#    #+#                  #
#    Updated: 2022/03/23 14:28:03 by tklouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 			ft_memset.c $\
				ft_bzero.c $\
				ft_memcpy.c $\
				ft_memccpy.c $\
				ft_memmove.c $\
				ft_memchr.c $\
				ft_memcmp.c $\
				ft_strlen.c $\
				ft_strlcpy.c $\
				ft_strlcat.c $\
				ft_strchr.c $\
				ft_strrchr.c $\
				ft_strnstr.c $\
				ft_strncmp.c $\
				ft_atoi.c $\
				ft_isalpha.c $\
				ft_isdigit.c $\
				ft_isalnum.c $\
				ft_isascii.c $\
				ft_isprint.c $\
				ft_toupper.c $\
				ft_tolower.c $\
				ft_calloc.c $\
				ft_strdup.c $\
				ft_substr.c $\
				ft_strjoin.c $\
				ft_strtrim.c $\
				ft_split.c $\
				ft_itoa.c $\
				ft_strmapi.c $\
				ft_putchar_fd.c $\
				ft_putstr_fd.c $\
				ft_putendl_fd.c $\
				ft_putnbr_fd.c $\
				ft_isset.c $\
				ft_itoa_base.c $\

BONUS_SRCS =	ft_lstnew.c $\
				ft_lstadd_front.c $\
				ft_lstsize.c $\
				ft_lstlast.c $\
				ft_lstadd_back.c $\
				ft_lstdelone.c $\
				ft_lstclear.c $\
				ft_lstiter.c $\

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
OPTIONS = ar -rcs
HEADER = libft.h

ifdef WITH_BONUS
OBJ_FILES = $(OBJ) $(BONUS_OBJ)
else
OBJ_FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(OPTIONS) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
