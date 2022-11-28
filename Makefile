define HEADER

          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@
         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@
        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@
                  @@@@@@@@                                   @@@@@@@@
                 @@@@@@@@  @@@@@@@@  @@@@@@@@      @@@@@@@  @@@@@@@@
                @@@@@@@@  @@@@@@@@  @@@@@@@@@@    @@@@@@@  @@@@@@@@
               @@@@@@@@  @@@@@@@@  @@@@@@@@@@@@  @@@@@@@  @@@@@@@@
              @@@@@@@@  @@@@@@@@  @@@@@@@@@@@@@@@@@@@@@  @@@@@@@@
             @@@@@@@@  @@@@@@@@  @@@@@@@   @@@@@@@@@@@  @@@@@@@@
            @@@@@@@@  @@@@@@@@  @@@@@@@     @@@@@@@@@  @@@@@@@@
           @@@@@@@@  @@@@@@@@  @@@@@@@       @@@@@@@  @@@@@@@@

endef
export HEADER

CC = gcc
CFLAGS 	= -Wall -Werror -Wextra

all : client server
	@echo "$$HEADER"
	@echo "Minitalk Compiled"
server:
	@$(MAKE) -C ./libft_extra
	@$(CC) $(CFLAGS) server.c libft_extra/libft_extra.a -o server

client:
	@$(MAKE) -C ./libft_extra
	@$(CC) $(CFLAGS) client.c libft_extra/libft_extra.a -o client

clean:
	$(MAKE) -C ./libft_extra clean

fclean:
	$(MAKE) -C ./libft_extra fclean
	rm -f client server

re: fclean all

.PHONY : all clean fclean re