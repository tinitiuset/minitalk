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

CLIENT = client
SERVER = server

CC = gcc
CFLAGS 	= -Wall -Werror -Wextra

CLIENT_C =	client.c
SERVER_C =	server.c

CLIENT_OBJ = $(CLIENT_C:.c=.o)
SERVER_OBJ = $(SERVER_C:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@$(MAKE) -C ./libft_extra
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) libft_extra/libft_extra.a -o $(CLIENT)
	@echo "$$HEADER"
	@echo "Client Compiled"

$(SERVER): $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) libft_extra/libft_extra.a -o $(SERVER)
	@echo "Server Compiled"

clean:
	$(MAKE) -C ./libft_extra clean
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	@echo "All .o files removed"

fclean: clean
	$(MAKE) -C ./libft_extra fclean
	@rm -f $(CLIENT) $(SERVER)
	@echo "Bye Bye"

re: fclean all

.PHONY : all clean fclean re