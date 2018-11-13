NAME = 		ft_ssl

INC =		ft_ssl.h

SRC =		testssl.c \
			check_err.c \
			flags.c \
			structs.c \
			input_args.c \
			main.c \
			md5.c \
			padding.c \
			md5_rounds.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(OBJ): $(SRC)
	@gcc $(CFLAGS) -c $(SRC) -Ilibft/

$(NAME): $(OBJ) libft_compile
	@gcc $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

libft_compile:
	@+$(MAKE) -C libft/

clean:
	@/bin/rm -rf $(OBJ)

fclean:	clean
	@/bin/rm -rf ft_ssl
	@+$(MAKE) fclean -C libft/

re:	fclean	all

