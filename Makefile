##
## SYSTEM PROJECT, 2021
## makefile
## File description:
## file
##


SRC_MAIN =	src/main.c							\
			src/data.c							\
			src/error.c							\
			src/proba.c							\
			src/itoa.c							\

CC =	gcc

OBJ =	$(SRC_MAIN:.c=.o)

NAME =		huffman

CFLAGS = -Wall -Wextra -Werror -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf src/*.o
	rm -rf tests/*.o*

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re