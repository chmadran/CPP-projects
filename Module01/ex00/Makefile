# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 09:27:25 by chmadran          #+#    #+#              #
#    Updated: 2023/09/22 13:44:59 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------VARIABLES-----------
NAME		= zombie
SRC			= Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ			= $(SRC:.cpp=.o)
COMP		= c++
FLAGS		= -Wall -Werror -Wextra -std=c++98
EXEC		= zombie

#---------COLORS--------------

YELLOW 		= \033[32m
NO_COLOR	= \033[0m

#---------RULES---------------

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(FLAGS) $(OBJ) -o $(EXEC)
	@echo "\n$(YELLOW) EXECUTABLE READY ! $(NO_COLOR)\n"

object:
	${COMP} ${FLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -rf $(OBJ)
	@echo "\n$(YELLOW)OBJECT FILES DELETED.$(NO_COLOR)"

fclean: clean
	rm -rf $(EXEC)
	@echo "\n$(YELLOW)EXECUTABLE DELETED.$(NO_COLOR)"

re: clean fclean all

.PHONY: all object clean fclean re