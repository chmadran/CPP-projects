# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 14:17:38 by chmadran          #+#    #+#              #
#    Updated: 2023/06/21 09:39:26 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------VARIABLES--------------

NAME		=	phonebook
SRC			=	Phonebook.class.cpp Contact.class.cpp main.cpp
OBJ		=	$(SRC:.cpp=.o)
COMPILE		=	clang++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
EXE_NAME	=	-o phonebook
EXEC		=	phonebook

# ------------COLORS--------------

GREEN		=	\033[32m
YELLOW		=	\033[33m
NO_COLOR	=	\033[0m

# ------------RULES---------------

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(OBJ) $(EXE_NAME)
	@echo "\n$(GREEN)Executable ready!$(NO_COLOR)"

object:
	${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

	
clean:
	rm -rf $(OBJ)
	@echo "\n$(YELLOW)Object file removed.$(NO_COLOR)"

fclean: clean
	rm -rf $(EXEC)
	@echo "\n$(YELLOW)Executable deleted.$(NO_COLOR)"

re:	clean fclean all

.PHONY:	all object clean fclean re
