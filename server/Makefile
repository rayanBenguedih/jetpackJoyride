##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/checkers.c \
		src/connecition.c \
		src/firer.c \
		src/server.c \
		src/senders.c \
		src/error_handler.c \
		src/deplacer.c

OBJ	=	$(SRC:.c=.o)

NAME	=	serverJ2T3

CFLAGS	=	-lpthread -g -Wall -Wextra -I./include

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:    	fclean	\
		all
