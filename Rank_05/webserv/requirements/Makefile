#=== Variables ===#

NAME 		:= 		webserv

SRCSDIR 	:= 		srcs
OBJDIR 		:= 		obj

CPP_FLAGS	:= 		-Wall -Werror -Wextra -std=c++17 -fsanitize=address
# CPP_FLAGS	:= 		-Wall -Werror -Wextra -std=c++17 -g

INC_DIR		:= 		includes
INC_FLAGS	:= 		$(addprefix -I, $(shell find $(INC_DIR) -type d))

SRCS		:=		$(shell find $(SRCSDIR) -type f)

OBJ			:= 		$(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

#=== COLORS ===#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@printf "$(GREEN)compiling '$(NAME)'...$(RESET)\n"
	c++ $(CPP_FLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)compilation completed$(RESET)\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@printf "building %-75s" $@
	@c++ $(CPP_FLAGS) $(INC_FLAGS) -c $< -o $@
	@printf "[$(GREEN)%s$(RESET)]\n" ✓

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@printf "$(RED)cleaning...$(RESET)\n"
	rm -rf $(OBJDIR)
	@printf "$(RED)cleaning completed$(RESET)\n"

fclean: 
	@printf "$(RED)cleaning...$(RESET)\n"
	rm -rf $(NAME) $(OBJDIR)
	@printf "$(RED)cleaning completed$(RESET)\n"

re: fclean all

PHONY.: all clean fclean re