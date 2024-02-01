NAME = minishell
LIBFT = libft/libft.a
LIBFT_CMD = $(MAKE) -C libft WITH_BONUS=1
CC = gcc
INCFLAGS = -I include -I $(LIBFT)
# RL_PATH = /Users/$(USER)/.brew/Cellar/readline/8.2.1 
RL_PATH = /Users/dklouwer/.brew/opt/readline
# RL_PATH = /opt/homebrew/opt/readline
RL_LIB = -lreadline -L$(RL_PATH)/lib
RL_INC = -I $(RL_PATH)/include
CFLAGS = -g  -Wall -Werror -Wextra
PRSR_DIR = parser/
XCTR_DIR = executor/
SRC_DIR = src/
OBJ_DIR = obj/

PRSR_SRCS = tokenizer env_sub cmd_res helper tokenizer_utils redirect_checking environment parse_utils main
XCTR_SRCS = init_structs execute shell_builtins env_builtins builtins_utils exec_utils redir_io heredoc  child_utils process_utils

SRC_FILES = $(addprefix $(PRSR_DIR),$(PRSR_SRCS)) $(addprefix $(XCTR_DIR),$(XCTR_SRCS))
SRC = $(addprefix $(SRC_DIR),$(addsuffix .c,$(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR),$(addsuffix .o,$(SRC_FILES)))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

ifdef DEBUG
	CFLAGS += -fsanitize=address 
endif

all: libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RL_LIB) $(INCFLAGS) $(LIBFT)  -o $(NAME)
	@echo "$(GREEN)Minishell Compiled.$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCFLAGS) $(RL_INC) -c $< -o $@

$(LIBFT):
	@echo "$(GREEN)Building libft ...$(RESET)"
	@$(LIBFT_CMD)

clean:
	@rm -rf $(OBJ_DIR)
	@$(LIBFT_CMD) fclean

fclean: clean
	@rm -rf $(NAME)
	@find . -name ".DS_Store" -delete
	@echo "$(RED)Cleaning ...$(RESET)"

re: fclean all

.PHONY: all clean fclean re
