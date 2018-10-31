NAME = 		ft_ssl

INC =		ft_ssl.h

SRC =		testssl.c \
			check_err.c \
			flags.c \
			init_structs.c \
			input_args.c \
			main.c \
			md5.c \
			padding.c \
			md5_rounds.c \

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): libft_compile
	@gcc $(CFLAGS) -c $(SRC)
	@gcc $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

libft_compile:
	@+$(MAKE) -C ./libft

libft_clean:
	@+$(MAKE) clean -C ./libft

libft_fclean:
	@+$(MAKE) fclean -C ./libft

clean:	libft_clean
	@/bin/rm -rf $(OBJ)

fclean:	clean libft_fclean
	@/bin/rm -rf ft_ssl

re:	fclean	all

.PHONY: all clean fclean re libft_clean libft_compile libft_fclean
