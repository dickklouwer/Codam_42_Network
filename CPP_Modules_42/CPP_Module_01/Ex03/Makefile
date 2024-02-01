#= Variables =#

NAME := UnnecessaryViolence

SRCS :=  Weapon.cpp main.cpp HumanA.cpp HumanB.cpp

SRCSDIR := srcs

OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES := includes/HumanA.hpp includes/HumanB.hpp includes/Weapon.hpp

#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(INCLUDES)
	@echo "$(GREEN)Building Unnecessary Violence ...$(RESET)"
	@g++ $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: $(addprefix $(SRCSDIR)/, %.cpp) $(INCLUDES)
	@g++ $(CPP_CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED)Cleaning ...$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(OBJDIR)

re: fclean all
