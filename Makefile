# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pceccoli <pceccoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 15:40:17 by pceccoli          #+#    #+#              #
#    Updated: 2021/06/14 14:37:06 by pceccoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

CC	     = gcc $(FLAGS)

FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = src/server.c src/utils.c src/utils2.c src/stringhe.c 

CLIENT_SRC = src/client.c src/stringhe.c src/utils.c src/utils2.c

SERVER_BONUS_SRC = bonus/server_bonus.c bonus/stringhe_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c

CLIENT_BONUS_SRC = bonus/client_bonus.c bonus/stringhe_bonus.c bonus/utils_bonus.c bonus/utils2_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

all :	fclean $(SERVER_SRC_OBJ) $(CLIENT_SRC_OBJ)
		@$(CC) $(SERVER_SRC) -I minitalk.h -o server
		@$(CC) $(CLIENT_SRC) -I minitalk.h -o client

bonus:	fclean $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
		@$(CC) $(SERVER_BONUS_SRC) -I minitalk_bonus.h -o server_bonus
		@$(CC) $(CLIENT_BONUS_SRC) -I minitalk_bonus.h -o client_bonus

clean :
	@rm -rf ./src/*.o ./bonus/*.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY : bonus all clean fclean
