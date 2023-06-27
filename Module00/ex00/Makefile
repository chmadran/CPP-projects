# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmadran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 14:17:38 by chmadran          #+#    #+#              #
#    Updated: 2023/06/21 09:39:39 by chmadran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------VARIABLES--------------

NAME		=	megaphone
SRC			=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)
COMPILE		=	clang++
FLAGS		=	-Wall -Wextra -Werror -std=c++98
EXE_NAME	=	-o megaphone
EXEC		=	megaphone

# ------------COLORS--------------

GREEN		=	\033[32m
YELLOW		=	\033[33m
NO_COLOR	=	\033[0m

# ------------RULES---------------

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(FLAGS) $(OBJ) $(EXE_NAME)
	@echo "\n$(GREEN)Executable ready!$(NO_COLOR)"

.cpp.o:
	${COMPILE} ${FLAGS} -c $< -o ${<:.cpp=.o}

	
clean:
	rm -rf $(OBJ)
	@echo "\n$(YELLOW)Object file removed.$(NO_COLOR)"

fclean: clean
	rm -rf $(EXEC)
	@echo "\n$(YELLOW)Executable deleted.$(NO_COLOR)"

re:	fclean all

.PHONY:	all clean fclean re