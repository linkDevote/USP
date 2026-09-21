#include <stdio.h>

void criarRetangulo(int altura, int largura){
    for(int a = 0; a < altura; a++){
        for(int l = 0; l < largura; l++ ){
            printf("#");
        }
        printf("\n");
    }
}

int main(){
    criarRetangulo(3, 2);
    return 0;
}



/*
Escreva uma função chamada retangulo que recebe como parâmetro duas variáveis
do tipo inteiro chamadas largura e altura e imprime um retângulo de '#' com 
as respectivas dimensões. Utilize dois laços aninhados (encadeados) para resolver
este problema. Veja o exemplo de saída:

##
##
##
*/