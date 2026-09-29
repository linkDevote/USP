#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void selectionSortHelper(int* array, int ini, int tamanho){
    if(ini >= tamanho - 1){
        return;
    }
    
    int minIndex = ini;

    for(int j = ini + 1; j < tamanho; j++){
        if(array[j] < array[minIndex]){
            minIndex = j;
        }
    }

    if(minIndex != ini){
        int temp = array[ini];
        array[ini] = array[minIndex];
        array[minIndex] = temp;
    }

    selectionSortHelper(array, ini + 1, tamanho);
}

void selectionSort(int* array, int tamanho){
    selectionSortHelper(array, 0, tamanho);
}

int main(){
    int len = 10;
    int* array = criarArray(len);
    
    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);
    
    selectionSort(array, len);
    
    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);
    
    free(array);
    return 0;
}