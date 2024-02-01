# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tklouwer <tklouwer@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/05/30 13:24:22 by tklouwer      #+#    #+#                  #
#    Updated: 2022/10/24 16:02:59 by tklouwer      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c \
		stack_utils.c \
		sort.c \
		sort_utils.c \
		commands.c \
		input_parsing.c \
		index_stack.c \
		radix_sort.c

SRCSDIR = srcs
OBJDIR = obj
INCLUDES = includes 
OBJ = $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT = libft/libft.a 
OBJ_LIBFT := $(shell find libft -name '.o')

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.c)
	$(CC) -c $(CFLAGS) $(LIBS) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):	
	$(MAKE) -C libft WITH_BONUS=1
	cp $(LIBFT) $(NAME) 

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJDIR)

fclean:
	$(MAKE) -C libft fclean
	rm -f $(NAME) $(OBJ) $(PUSH_SWAP)
	rm -r $(OBJDIR)

re:	fclean all