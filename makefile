client: client.o networking.o draw.o movement.o diff.o map.o player.h blocks.h
	gcc -o client client.o networking.o draw.o movement.o diff.o map.o -lncursesw

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
