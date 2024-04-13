# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 14:08:03 by chmadran          #+#    #+#              #
#    Updated: 2023/09/26 16:55:31 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------VARIABLES-----------
NAME		= brainz
SRC			= main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ			= $(SRC:.cpp=.o)
COMP		= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98
EXEC		= brainz

#---------COLORS--------------

GREEN 		= \033[32m
NO_COLOR	= \033[0m

#---------RULES---------------

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP) $(FLAGS) $(OBJ) -o $(EXEC)
	@echo "\n$(GREEN) EXECUTABLE READY ! $(NO_COLOR)\n"

object:
	@${COMP} ${FLAGS} -c $< -o ${<:.cpp=.o}

clean:
	@rm -rf $(OBJ)
	@echo "\n$(GREEN)OBJECT FILES DELETED.$(NO_COLOR)"

fclean: clean
	@rm -rf $(EXEC)
	@echo "\n$(GREEN)EXECUTABLE DELETED.$(NO_COLOR)"

re: clean fclean all

.PHONY: all object clean fclean re