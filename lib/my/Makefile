##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compiles libmy
##

SRC	=	my_isneg.c			\
		my_strcpy.c			\
		my_str_isnum.c			\
		my_strlen.c			\
		my_getnbr.c			\
		my_strdup.c

OBJ	=	$(SRC:.c=.o)

NAME =	libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include
		cp $(NAME) ../
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
