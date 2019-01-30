#include "connections.h"

struct conlist *init_conlist(int size)
{
    struct conlist *cl = malloc(sizeof(struct conlist));
    cl->arr = malloc(size * sizeof(struct connection *));
    cl->cur_size = 0;
    cl->max_size = size;
    return cl;
}

void free_connection(struct connection *c)
{
}

void free_conlist(struct conlist *cl)
{
}
