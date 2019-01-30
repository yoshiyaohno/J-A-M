#include "server.h"

void send_map(int sd, struct map *m)
{
    printf("transmitting map....\n");
    // SEND MAP
    int y, z;
    for(y = 0; y < m->y_size; ++y) {
        for(z = 0; z < m->z_size; ++z) {
            write(sd, m->arr[y][z], sizeof(char) * (m->x_size));
        }
        printf("transmitted depth [%i]\n", y);
    }
    printf("map transmitted.\n");
}

int main()
{
    int f;
    int listen_socket, client_socket;
    struct map *main_map = read_map("map.map");

    listen_socket = server_setup();

    while(1) {
        client_socket = server_connect(listen_socket);
        send_map(client_socket, main_map);
    }
    
    return 0;
}
