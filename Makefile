#LIBRARY INFO#
CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c
PRINTF = ./ft_printf/libftprintf.a
PRINTF_DIR = ./ft_printf

INC		=	-I. -I$(PRINTF_DIR) -I$(PRINTF_DIR)/stack \
			-I$(PRINTF_DIR)/ft_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all: $(SERVER) $(CLIENT)

$(NAME) : all

$(SERVER): $(LIBFT)
	$(CC) $(D_FLAG) $(CFLAG) $(SRC_S) $(PRINTF) $(INC) -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(D_FLAG) $(CFLAG) $(SRC_C) $(PRINTF) $(INC) -o $(CLIENT)

clean:
	$(RM) $(CLIENT) $(SERVER)
