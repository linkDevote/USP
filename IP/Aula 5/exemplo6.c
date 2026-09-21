/*
	Programa que apresenta exemplos dos endereÃ§os de memÃ³rias das variÃ¡veis.
	Uso de alocaÃ§Ã£o dinÃ¢mica de memÃ³ria com a funÃ§Ã£o malloc e liberaÃ§Ã£o com
	a funÃ§Ã£o free.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
   int* end3 = (int*) malloc(sizeof(int));
   *end3 = 11;
   free(end3);
   printf("Valor de end3: %p\n",end3);
   printf("EndereÃ§o de end3: %p\n",&end3);
   printf("ConteÃºdo apontado por end3: %i\n",*end3);
   return 0;
}


/* SAIDA (o conteÃºdo de end3 pode variar de acordo com a execuÃ§Ã£o)
Valor de end3: 0x1f3c260
EndereÃ§o de end3: 0x7ffd1ccd1f20
ConteÃºdo apontado por end3: 0
*/