CC 				= cc
FLAGS 			=	-Wall -Wextra -Werror
ClIENT 			= client.c
SERVER 			= server.c
CNAME 			= client
SNAME 			= server
HELPER 			= utils.c

all: $(CNAME) $(SNAME)

$(CNAME): $(ClIENT)
	$(CC) $(FLAGS) $(ClIENT) $(HELPER) -o $(CNAME)

$(SNAME): $(SERVER)
	$(CC) $(FLAGS) $(SERVER) $(HELPER) -o $(SNAME)

clean:
	rm -f $(CNAME) $(SNAME)
fclean: clean

re: fclean all