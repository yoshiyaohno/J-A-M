.PHONY: clean client server

default: 
	@echo "please make client or server"

client: client.o networking.o draw.o movement.o diff.o map.o player.h blocks.h
	gcc -o start_client client.o networking.o draw.o movement.o diff.o map.o -lncursesw

server: server.o networking.o map.o connections.o server.h
	gcc -o start_server server.o connections.o networking.o map.o

connections.o: server/connections.c server/connections.h
	gcc -c server/connections.c

client.o: client.c client.h
	gcc -c client.c

networking.o: networking.c networking.h
	gcc -c networking.c

draw.o: draw.c draw.h
	gcc -c draw.c

movement.o: movement.c movement.h
	gcc -c movement.c

diff.o: diff.c diff.h
	gcc -c diff.c

map.o: map.c map.h
	gcc -c map.c

server.o: server.c server.h
	gcc -c server.c

clean:
	-rm *.o
	-rm start_server
	-rm start_client
