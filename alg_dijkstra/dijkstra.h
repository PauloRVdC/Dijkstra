#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include <stdlib.h>
#include <stdio.h>
#define N 6

typedef struct vertice {
	int rotulo, estimativa, fechado;
} v;

v create_vertice(int r, int e);
void dijkstra(int matriz[N][N], int inicial, int final);
void encontra_caminho(v abertos[N], int inicial, int final, int matriz[N][N]);

#endif