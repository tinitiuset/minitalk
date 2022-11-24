CC = cc
CFLAGS 	= -Wall -Werror -Wextra

all : client server

server:
	$(MAKE) -C ./libft_extra
	$(CC) $(CFLAGS) server.c libft_extra/libft_extra.a -o server

client:
	$(MAKE) -C ./libft_extra
	$(CC) $(CFLAGS) client.c libft_extra/libft_extra.a -o client

clean:
	$(MAKE) -C ./libft_extra clean

fclean:
	$(MAKE) -C ./libft_extra fclean
	rm client server

re: fclean all

.PHONY : all clean fclean re