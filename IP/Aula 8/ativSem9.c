#include <stdio.h>
#include <stdlib.h>

int contaCaracteres(char** palavras, int n){
  int total = 0;
  int letra = 0;

  for(int i = 0; i < 4; i++){
    while(palavras[i][letra] != '\0'){
      letra++;
      total++;
    }
    letra = 0;
  }

  return total;
}
  
int main() {
  char** nomes2 = (char**) malloc(sizeof(char*)*4);
  nomes2[0] = (char*) malloc(sizeof(char)*10);
  nomes2[1] = (char*) malloc(sizeof(char)*6);
  nomes2[2] = (char*) malloc(sizeof(char)*6);
  nomes2[3] = (char*) malloc(sizeof(char)*9);
  
  nomes2[0][0] = 'A';
  nomes2[0][1] = 'l';
  nomes2[0][2] = 'v';
  nomes2[0][3] = 'e';
  nomes2[0][4] = 'n';
  nomes2[0][5] = 'a';
  nomes2[0][6] = 'r';
  nomes2[0][7] = 'i';
  nomes2[0][8] = 'a';
  nomes2[0][9] = '\0';
  nomes2[1][0] = 'V';
  nomes2[1][1] = 'i';
  nomes2[1][2] = 'n';
  nomes2[1][3] = 'i';
  nomes2[1][4] = 'l';
  nomes2[1][5] = '\0';
  nomes2[2][0] = 'F';
  nomes2[2][1] = 'i';
  nomes2[2][2] = 'b';
  nomes2[2][3] = 'r';
  nomes2[2][4] = 'a';
  nomes2[2][5] = '\0';
  nomes2[3][0] = 'P';
  nomes2[3][1] = 'l';
  nomes2[3][2] = 'a';
  nomes2[3][3] = 's';
  nomes2[3][4] = 't';
  nomes2[3][5] = 'i';
  nomes2[3][6] = 'c';
  nomes2[3][7] = 'o';
  nomes2[3][8] = '\0';

  printf("Total de caracteres: %i\n", contaCaracteres(nomes2,4));

  return 0;
}


/* SAIDA
Total de caracteres: 27
*/

/*
Escreva uma função chamada contaCaracteres que recebe como parâmetro um
arranjo que contém (aponta para) n arranjos de caracteres chamado palavras (o
qual representa um conjunto de palavras) e deverá retornar o número total de
caracteres presentes nesse arranjo de arranjos. Considere que cada arranjo de
caracteres é encerrado pelo caractere '\0' (este caractere não deverá ser com-
putado). A assinatura da função é apresentada a seguir:

int contaCaracteres(char** palavras, int n)
*/