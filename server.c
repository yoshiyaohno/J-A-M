#include "server.h"

#define MAX_PLRS    8

void send_map(int sd, struct map *m)
{
    // SEND MAP
    int y, z;
    for(y = 0; y < m->y_size; ++y) {
        for(z = 0; z < m->z_size; ++z) {
            write(sd, m->arr[y][z], sizeof(char) * (m->x_size));
        }
    }
    printf("[server] map transmitted to p%i\n", sd);
}

int main()
{
    int f;
    int listen_socket, client_socket;
    struct map *main_map = read_map("map0.map");
    struct conlist *conns = init_conlist(MAX_PLRS);

    listen_socket = server_setup();

    while(1) {
        client_socket = server_connect(listen_socket);
        if(-1 == add_connection(conns, client_socket, "jef")) {
            printf("[server] connection [%i] added at %i\n",
                    conns->filled-1, client_socket); 
        }
        else {
            printf("[server] server full, refused connection from %i"
                    client_socket);
        }
        send_map(client_socket, main_map);
    }
    
    return 0;
}
