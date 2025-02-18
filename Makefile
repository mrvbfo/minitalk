CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = minitalk
SERVER = server
SRC_SERVER = server.c

CLIENT = client
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

$(NAME): $(SERVER) $(CLIENT)

all: $(NAME)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) 

fclean: clean 
	$(RM) $(SERVER) $(CLIENT) 

re: fclean all

.PHONY: all clean fclean re