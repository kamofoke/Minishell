# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 07:54:33 by kamofoke          #+#    #+#              #
#    Updated: 2020/02/21 10:35:43 by kamofoke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell

FLAGS	=	gcc -Wall -Wextra -Werror

SRC 	=	ft_functions.c ft_cd.c ft_unsetenv.c ft_echo.c \
		   	execute_cmd.c main.c ft_setenv.c

OBJ 	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:
		@make -C libft/
		@$(FLAGS) -c $(SRC)
		@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean	:
		@make clean -C libft/
		@rm -rf $(OBJ)

fclean	: 	clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re	: 	fclean all

