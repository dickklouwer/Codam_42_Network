# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tklouwer <tklouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/28 12:50:10 by tklouwer      #+#    #+#                  #
#    Updated: 2022/03/29 11:13:39 by tklouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
		parsing.c \
		conversions.c

SRCSDIR = srcs
OBJDIR = obj
INCLUDES = includes
OBJ = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -I $(INCLUDES)
OPTIONS = ar -rcT
LIBFT = libft/libft.a
OBJ_LIBFT := $(shell find libft -name '.o')

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBFT) $(OBJ)
	$(OPTIONS) $(NAME) $(OBJ_LIBFT) $(OBJ)

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.c)
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	$(MAKE) -C libft
	cp $(LIBFT) $(NAME) 

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJDIR)

fclean:
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(OBJ) $(PRINTF)
	rm -r $(OBJDIR)

re:	fclean all