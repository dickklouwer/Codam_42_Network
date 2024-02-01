#= Variables =#

CPP_FLAGS = -Wall -Werror -Wextra

COMPILE_CODE = -std=c++98

OBJ = megaphone.o
#= COLORS =#

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

#= Targets =#

all: megaphone

megaphone: megaphone.o
	@g++ $(CPP_FLAGS) $(COMPILE_CODE) megaphone.o -o megaphone
	@echo "$(GREEN)Megaphone build ...$(RESET)"

megaphone.o: megaphone.cpp
	@g++ -c $(CPP_FLAGS) $(COMPILE_CODE) megaphone.cpp

clean:
	@rm $(OBJ)
	@echo "$(RED)Cleaning ...$(RESET)"

fclean: clean
	@rm megaphone

re: fclean all
