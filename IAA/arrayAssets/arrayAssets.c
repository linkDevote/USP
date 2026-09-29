#include <stdio.h>
#include <stdlib.h>

#include "arrayAssets.h"

int* criarArray(int tamanho){
    int* array = (int*) malloc(sizeof(*array)*tamanho);
    for(int i = 0; i < tamanho; i++){
        array[i] = rand() % 100;
    }
    
    return array;
}

void imprimeArray(int* array, int tamanho){
     for(int i = 0; i < tamanho; i++){
        printf("(%i) -> %i\n", i, array[i]);
    }
}