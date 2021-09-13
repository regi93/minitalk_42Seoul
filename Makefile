SERVER=server
CLIENT=client

all: server client

server:
	gcc server.c utils.c -o $(SERVER)

client:
	gcc client.c utils.c -o $(CLIENT)

clean: 
	rm $(SERVER) $(CLIENT)

fclean: clean

re: clean all


# B_SERVER=server_bonus
# B_CLIENT=client_bonus

# b_all: b_test

# b_test: b_server b_client

# b_server:
# 	gcc server_bonus.c utils.c -o $(B_SERVER)

# b_client:
# 	gcc client_bonus.c utils.c -o $(B_CLIENT)

# b_clean: 
# 	rm $(B_SERVER) $(B_CLIENT)

# b_fclean: b_clean

# b_re: b_clean b_all