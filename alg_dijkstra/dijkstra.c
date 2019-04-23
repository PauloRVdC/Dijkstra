#include <stdlib.h>
#include <stdio.h>
#include "dijkstra.h"
#define N 6

v create_vertice(int r, int e) {
	v new_vertice;
	new_vertice.rotulo = r;
	new_vertice.estimativa = e; 
	new_vertice.fechado = 0;
	return new_vertice;
}

void dijkstra(int matriz[N][N], int inicial, int final) {
	int qtdeFechados = 0;
	v abertos[N]; 
	for (int i = 0; i < N; i++) {
		abertos[i] = create_vertice(i,1073741822);
	}

	abertos[inicial].estimativa = 0;

	while (qtdeFechados < N) {
		v menor;
		menor.estimativa = 1073741823;
		for(int i = 0; i < N; i++) {
			if (abertos[i].fechado == 0) {
				if (abertos[i].estimativa < menor.estimativa) {
					menor = abertos[i];
				}
			}
		}
		abertos[menor.rotulo].fechado = 1;
		qtdeFechados++;

		for(int j = 0; j < N; j++) {
			if (matriz[menor.rotulo][j] != 0 ) {
				if (abertos[j].fechado == 0){
					if (abertos[j].estimativa > (matriz[menor.rotulo][j] + menor.estimativa)) {
						abertos[j].estimativa = (matriz[menor.rotulo][j] + menor.estimativa);
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d\n", abertos[i].estimativa);
	}
	encontra_caminho(abertos,inicial,final,matriz);
}

void encontra_caminho(v abertos[N], int inicial, int final, int matriz[N][N]) {
	v temp = abertos[final];
	while (temp.rotulo != inicial) {
		for (int j = 0; j < N; j++) {
			if (matriz[temp.rotulo][j] != 0) {
				if (temp.estimativa - matriz[temp.rotulo][j] == abertos[j].estimativa) {
					temp = abertos[j];
					printf(" %d", temp.rotulo);
				}
			}
		}
	}
}