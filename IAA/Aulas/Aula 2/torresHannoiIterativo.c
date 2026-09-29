#include <stdio.h>
#include <stdlib.h>

void solve(const int QTD_DISCOS){
  const int ALPHA[2][3][2] = {
      { { 1, 3 }, { 3, 2 }, { 2, 1 } },   /* PARES */
      { { 1, 2 }, { 2, 3 }, { 3, 1 } }    /* ÍMPARES */
    };

  const int MAX_ITER = 1 << QTD_DISCOS;

  int **lista = malloc( (MAX_ITER - 1) * sizeof(*lista) );

  int start, gap, disco, k, rank;

  for (start = 1, gap = 2, disco = 1;
       disco <= QTD_DISCOS; ++disco, start <<= 1, gap <<= 1){
    int R = MAX_ITER + (disco % 2);

    int **duplas = (int **) &ALPHA[(QTD_DISCOS + disco) % 2];

    for (k = 0, rank = start; rank < R; rank += gap, ++k){
      lista[rank - 1] = (int *) &duplas[k % 3];
    }
  }

  for (rank = 0; rank < (MAX_ITER - 1); ++rank){
    char origem  = lista[rank][0] + 64;
    char destino = lista[rank][1] + 64;
    printf("%4d ) %c --> %c\n", (rank + 1), origem, destino);
  }

  free(lista);
}

int main(){
  int d = 4;

  solve(d);

  return 0;
}