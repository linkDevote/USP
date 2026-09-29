#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void selectionSort(int* array, int tamanho){
    for(int i = 0; i < tamanho - 1; i++){    
        int minIndex = i;

        for(int j = i + 1; j < tamanho; j++){
            if(array[j] < array[minIndex]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
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