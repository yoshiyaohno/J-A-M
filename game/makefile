server: server.o map.o networking.o server.h
	gcc -o server server.o map.o networking.o

client: client.o map.o networking.o movement.o draw.o diff.o player.h client.h
	gcc -o client client.o map.o networking.o movement.o draw.o diff.o -lncursesw

client.o: client.c client.h
	gcc -c client.c

server.o: server.c server.h
	gcc -c server.c

guest.o: guest.c
	gcc -c guest.c

diff.o: diff.c diff.h
	gcc -c diff.c

networking.o: networking.c networking.h
	gcc -c networking.c

main.o: main.c
	gcc -c main.c

draw.o: draw.c draw.h
	gcc -c draw.c

movement.o: movement.c movement.h
	gcc -c movement.c

map.o: map.c map.h
	gcc -c map.c

clean:
	rm *.o server client
