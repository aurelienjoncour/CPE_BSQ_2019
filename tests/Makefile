##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile for BSQ
##

SRC_DIR		=	../src/
INC_DIR		=	../include/
LIB_DIR		=	../lib/my

SRC		=	tests.c					\
			$(SRC_DIR)bsq.c				\
			$(SRC_DIR)load_2d_arr_from_str.c	\
			$(SRC_DIR)mem_alloc_2d_array.c		\
			$(SRC_DIR)buffer.c

OBJ		=	$(SRC:.c=.o)

NAME		=	test

CFLAGS		+=	-Wall -Wextra --coverage -I $(INC_DIR)

LDFLAGS		=	-L $(LIB_DIR) -lmy --coverage -lcriterion

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR) --no-print-directory
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)
		./$(NAME)
clean:
		rm -f $(OBJ)
		rm -f $(OBJ:.o=.gcno)
		rm -f $(OBJ:.o=.gcda)

fclean:		clean
		rm	-f	$(NAME)

re:		fclean all
