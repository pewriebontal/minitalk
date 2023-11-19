# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhaing <0x@bontal.net>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 02:17:10 by mkhaing           #+#    #+#              #
#    Updated: 2023/11/20 07:40:38 by mkhaing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC = server.c
CLIENT_SRC = client.c
BIN_ENCO_SRC = binary_converter.c

CC = cc 
RM = rm -f

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Werror -Wextra

SERVER = server
CLIENT = client

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT): 
	make -C $(LIBFT_PATH) all

$(SERVER): $(SERVER_SRC) $(BIN_ENCO_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(BIN_ENCO_SRC) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(BIN_ENCO_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(BIN_ENCO_SRC) $(LIBFT) -o $(CLIENT)

clean :
	make -C $(LIBFT_PATH) clean 
	$(RM) $(SERVER) $(CLIENT)

fclean : clean 
	make -C $(LIBFT_PATH) fclean

re : fclean all

.PHONY : all fclean clean re