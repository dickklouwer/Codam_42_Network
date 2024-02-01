#= Variables =#

NAME := Brain

CC := g++

CPP_CFLAGS := -Wall -Werror -Wextra -std=c++98

#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all : $(NAME)

$(NAME): main.o
	@$(CC) main.o -o brain
	@echo "$(GREEN)Executable ready...$(RESET)"

main.o: main.cpp
	@$(CC) $(CPP_CFLAGS) -c main.cpp -o main.o

clean:
	@rm -rf main.o 
	@echo "$(RED)Cleaning ...$(RESET)"

fclean: clean
	@rm -rf $(NAME)

re: fclean all
	