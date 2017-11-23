NAME	= fillit
LIB 	= libft
OBJ		= $(SRC:.c=.o)
WOP 	= -g -Wall -Wextra -Werror

INC 	= fillit.h 

SRC 	= scan_dono.c verify_dono.c position_dono.c checknplace.c

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C ./libft/
		gcc $(OBJ) ./libft/libft.a -o $(NAME)

$(OBJ): $(SRC)
		gcc $(WOP) -c $(SRC) -I $(INC)

$(LIB):


clean:
		/bin/rm -rf *.o

fclean: clean
		/bin/rm -rf $(NAME)

re:
		fclean all


