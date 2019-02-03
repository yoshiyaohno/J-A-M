#include "connections.h"

struct conlist *init_conlist(int size)
{
    struct conlist *cl = malloc(sizeof(struct conlist));
    cl->arr = malloc(size * sizeof(struct connection *));
    cl->filled = 0;
    cl->max_size = size;
    return cl;
}

int add_connection(struct conlist *cl, int sd, char *plname)
{
    // no space
    if(cl->filled == cl->max_size) return -1;

    struct connection *new_c = malloc(sizeof(struct connection));
    new_c->sd = sd;
    new_c->plname = malloc(sizeof(char) * strlen(plname));
    strcpy(new_c->plname, plname);

    cl->arr[cl->filled++] = new_c;
    return 0;
}

int close_connection(struct conlist *cl, int sd)
{
    int i = 0;
    while(cl->arr[i++]->sd != sd) {
        if(i == filled) return -1;
    }
    free_connection(cl->arr[--i]);
    cl->arr[i] = cl->arr[--filled];
    return 0;
}

void free_connection(struct connection *c)
{
    free(c->plname);
    free(c);
}

void free_conlist(struct conlist *cl)
{
    int i;
    for(i = 0; i < cl->filled; ++i)
        free_connection(cl->arr[i]);
    free(cl->arr);
    free(cl);
}
