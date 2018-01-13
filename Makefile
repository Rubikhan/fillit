# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ztisnes <ztisnes@student.42.us.org>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 18:41:19 by ztisnes           #+#    #+#              #
#    Updated: 2017/11/25 12:50:58 by smaddux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit
LIB 	= libft
OBJ		= $(SRC:.c=.o)
CCFLAGS	= -Wall -Wextra -Werror

INC 	= fillit.h 

SRC 	= scan_dono.c verify_dono.c position_dono.c checknplace.c error.c

all: $(NAME)

$(NAME): $(OBJ)
		@$(MAKE) -C ./libft/
		@gcc $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ): $(SRC)
		@gcc $(CCFLAGS) -c $(SRC) -I $(INC)

$(LIB):

clean:
		@make -C ./libft/ clean
		@rm -rf $(OBJ)

fclean: clean
		@make -C ./libft/ fclean
		@/bin/rm -rf $(NAME)

re:		fclean all

.PHONY: all clean fclean re
