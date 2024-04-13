# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 13:58:11 by chmadran          #+#    #+#              #
#    Updated: 2023/10/03 10:01:36 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------VARIABLES-----------
NAME		= easyfind
SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)
HEADER		= easyfind.tpp
COMP		= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98
EXEC		= easyfind

#---------COLORS--------------

GREEN 		= \033[32m
NO_COLOR	= \033[0m

#---------RULES---------------

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(EXEC)
	@echo "\n$(GREEN) EXECUTABLE READY ! $(NO_COLOR)\n"

object: $(HEADER)
	@${COMP} ${FLAGS} -c $< -o ${<:.cpp=.o}

clean:
	@rm -rf $(OBJ)
	@echo "\n$(GREEN)OBJECT FILES DELETED.$(NO_COLOR)"

fclean: clean
	@rm -rf $(EXEC)
	@echo "\n$(GREEN)EXECUTABLE DELETED.$(NO_COLOR)"

re: clean fclean all

.PHONY: all object clean fclean re