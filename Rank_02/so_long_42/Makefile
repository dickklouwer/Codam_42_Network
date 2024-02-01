
#= Vars =#

NAME = so_long
SRCS :=	so_long.c \
		parse_map.c \
		build_map.c \
		movements.c \
		game_control.c \
		flood_fill.c \
		utils.c

SRCSDIR = srcs
OBJDIR = obj
OBJ := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
CFLAGS := -Wall -Werror -Wextra -g
LIBMLX := ./libs/MLX42
LIBFT := ./libs/libft
GNL := ./libs/get_next_line
FT_PRINTF := ./libs/ft_printf
LIBS :=  -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a $(FT_PRINTF)/libftprintf.a 
INCLUDES := -I libs/mlx42/include/MLX42/ -I $(LIBFT) -I $(FT_PRINTF) -I includes
#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets=#

all: libft mlx ft_printf $(NAME)

libft:
	@echo "$(GREEN)Building LIBFT$(RESET)"
	@$(MAKE) -C $(LIBFT) WITH_BONUS=1

ft_printf:
	@echo "$(GREEN)Building PRINTF$(RESET)"
	@$(MAKE) -C $(FT_PRINTF)

mlx:
	@echo "$(GREEN)Building MLX$(RESET)"
	@$(MAKE) -C $(LIBMLX) DEBUG=1

$(NAME): $(OBJDIR) $(OBJ)
	@$(CC) $(OBJ) $(LIBS) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)Building SO_LONG$(RESET)"

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.c)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@echo "$(RED)Cleaning $< $(RESET)"
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(FT_PRINTF) clean
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "$(RED)Cleaning $(RESET)"
	@rm -rf $(NAME) $(OBJ_DIR)

re: fclean all

.DEFAULT_GOAL := all
.PHONY: all clean fclean re