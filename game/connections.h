#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef CONNECTIONS_H
#define CONNECTIONS_H

struct connection
{
    int plid;     // player id
    int sd;       // socket descriptor for the connection
    char *plname; // player name
};

// connection list
struct conlist
{
    struct connection **arr;
    int cur_size;
    int max_size;
};

struct conlist *init_conlist(int size);

void free_conlist(struct conlist *cl);

void free_connection(struct connection *c);

#endif
