##
## EPITECH PROJECT, 2022
## Visual Studio Live Share (Workspace)
## File description:
## Makefile
##

client_bin_name = "clientJ2T3"

server_bin_name = "serverJ2T3"

client_dir = "client"

server_dir = "server"

all:
	$(MAKE) -C $(client_dir) && mv $(client_dir)/$(client_bin_name) .
	$(MAKE) -C $(server_dir) && mv $(server_dir)/$(server_bin_name) .

.PHONY: client
client:
	$(MAKE) -C $(client_dir) && mv $(client_dir)/$(client_bin_name) .

.PHONY: server
server:
	$(MAKE) -C $(server_dir) && mv $(server_dir)/$(server_bin_name) .

clean:
	$(MAKE) -C $(client_dir) clean
	$(MAKE) -C $(server_dir) clean

fclean: clean
	rm -f $(client_bin_name) $(server_bin_name)

re: fclean all
