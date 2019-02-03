#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "map.h"
#include "networking.h"
#include "server/connections.h"

void save_map(struct map *m, char *filename);

void send_map(int sd, struct map *m);

#endif
