##
## EPITECH PROJECT, 2019
## CPE_BSQ_2019
## File description:
## Makefile for bsq
##

SRC_DIR		=	src/
INC_DIR		=	include/
LIB_DIR		=	lib/my/

SRC		=	$(SRC_DIR)main.c			\
			$(SRC_DIR)load_2d_arr_from_str.c	\
			$(SRC_DIR)mem_alloc_2d_array.c		\
			$(SRC_DIR)bsq.c				\
			$(SRC_DIR)buffer.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CFLAGS		+=	-Wall -Wextra -I./include

LDLFLAGS	+=	-L $(LIB_DIR) -lmy

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIB_DIR)
		gcc -o $(NAME) $(OBJ) $(LDLFLAGS) -g

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

bonus:		fclean
		make -C bonus/
		cp bonus/bonus_bsq .

.PHONY: all clean fclean re run bonus
