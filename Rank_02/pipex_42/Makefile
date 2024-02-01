
#= Vars =#

NAME := pipex

SRCS := pipex.c parsing.c main.c utils.c

SRCSDIR := srcs

OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))

CFLAGS := -Wall -Wextra -Werror -g

LIBFT := libft/libft.a

INCLUDES := -I $(LIBFT) -I includes 

#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all: libft $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT)
	@echo "$(GREEN)Building pipex ...$(RESET)"
	@$(CC) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.c)
	@echo "$(GREEN)Building object files ...$(RESET)"
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@echo "$(GREEN)Building libft ...$(RESET)"
	@$(MAKE) -C libft WITH_BONUS=1

clean:
	@echo "$(RED)Cleaning ...$(RESET)"
	@$(MAKE) -C libft clean
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)
	@$(MAKE) -C libft fclean


re: fclean all