#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#ifndef CONNECTIONS_H
#define CONNECTIONS_H

struct connection
{
    int sd;       // socket descriptor for the connection (also plid)
    char *plname; // player name
};

// connection list
struct conlist
{
    struct connection **arr;
    int filled;
    int max_size;
};

struct conlist *init_conlist(int size);

// returns -1 if no space
int add_connection(struct conlist *cl, int sd, char *plname);

// returns -1 if no such connection (shouldn't happen???)
int close_connection(struct conlist *cl, int sd);

void free_conlist(struct conlist *cl);

void free_connection(struct connection *c);

#endif
