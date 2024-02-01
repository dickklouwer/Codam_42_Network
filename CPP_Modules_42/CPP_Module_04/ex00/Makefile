#= Variables =#

NAME := Animal

SRCS :=  Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
SRCSDIR := srcs

OBJDIR := obj

OBJ := $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

CPP_FLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES := includes/Animal.hpp includes/Cat.hpp includes/Dog.hpp includes/WrongCat.hpp includes/WrongAnimal.hpp

#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(INCLUDES)
	@echo "$(GREEN)Building Animal ...$(RESET)"
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