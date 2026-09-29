
#include <stdio.h>
#include <stdlib.h>

void solve(int QTD_DISCOS, int origem, int destino, int temp){
  static int rank = 0;

  if (QTD_DISCOS > 0){
    solve(QTD_DISCOS-1, origem, temp, destino);
    printf("%4d ) %c --> %c\n", ++rank, '@' + origem, '@' + destino);
    solve(QTD_DISCOS-1, temp, destino, origem);
  }
}

int main(){
  int d = 4;

  solve(d, 1, 3, 2);

  return 0;
}