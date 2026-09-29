#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void insertionSort(int* array, int tamanho) {
    if (tamanho <= 1) {
        return;
    }

    insertionSort(array, tamanho - 1);

    int key = array[tamanho - 1];
    int j = tamanho - 2;

    while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
    }
    array[j + 1] = key;
}

int main() {
    int len = 10;
    int* array = criarArray(len);
    
    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);
    
    insertionSort(array, len);
    
    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);
    
    free(array);
    return 0;
}