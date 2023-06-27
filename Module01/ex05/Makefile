# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 13:08:24 by chmadran          #+#    #+#              #
#    Updated: 2023/06/21 14:49:47 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------VARIABLES-----------
NAME		= harl
SRC			= main.cpp Harl.cpp
OBJ			= $(SRC:.cpp=.o)
COMP		= c++
FLAGS		= -Wall -Werror -Wextra
EXEC		= harl

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