##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile for bsq
##

SRC_DIR		=	../src/
INC_DIR		=	../include/
LIB_DIR		=	../lib/my/

SRC		=	src/main.c				\
			$(SRC_DIR)load_2d_arr_from_str.c	\
			$(SRC_DIR)mem_alloc_2d_array.c		\
			$(SRC_DIR)bsq.c				\
			$(SRC_DIR)buffer.c			\
			src/graphicals_functions.c		\
			src/pixels_functions.c			\
			src/bsq_graphics.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bonus_bsq

CFLAGS		+=	-Wall -Wextra -I $(INC_DIR) -I./include

LDLFLAGS	+=	-L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) $(CFLAGS) -g -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

clean:
		@make clean -C $(LIB_DIR) --no-print-directory
		@rm -f $(OBJ)

fclean:		clean
		@make fclean -C $(LIB_DIR) --no-print-directory
		@rm -f $(NAME)

re:	fclean all

run:	all
	./$(NAME)

tests_run:	fclean
		make -C tests/

.PHONY: all clean fclean re run
