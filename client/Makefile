##
## EPITECH PROJECT, 2020
## makefile for print
## File description:
## Makefile
##

SRC	=	client_src/additional.c	\
		client_src/boolier.c \
		client_src/content.c \
		client_src/data.c \
		client_src/main.c \
		client_src/parsing.c \
		graphical_src/display.c	\
		graphical_src/scenes.c \
		graphical_src/scenes_control.c \
		graphical_src/create_assets.c	\
		graphical_src/create_assets_2.c	\
		graphical_src/create_screens.c	\
		graphical_src/create_obstacles.c	\
		graphical_src/create_obstacles_two.c	\
		graphical_src/set_rect.c	\
		graphical_src/set_obstacles_rects.c	\
		graphical_src/set_rect2.c	\
		graphical_src/destroyer.c	\
		graphical_src/create_players.c	\
		graphical_src/create_clocks.c \
		graphical_src/simple_controls.c	\
		graphical_src/str_managment.c \
		graphical_src/map.c \
		graphical_src/map_2.c \
		graphical_src/read_file.c	\
		graphical_src/obstacles_hitboxes.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	clientJ2T3

CFLAGS	= -lcsfml-system -g -Wall -Wextra -I./include

CFLAGS2 = -lcsfml-graphics -lcsfml-window -lcsfml-audio

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS2) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:    	fclean	\
		all
