SRC = my_printf.c my_parser.c my_processor.c my_type_d_and_i.c my_type_u.c \
	my_type_x.c my_type_p.c my_type_c_and_s.c
OBJ = $(SRC:.c=.o)
HED = my_printf.h
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	${CC} $(CFLAGS) -I/$(HED) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) $(HED)
	ar rc $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
