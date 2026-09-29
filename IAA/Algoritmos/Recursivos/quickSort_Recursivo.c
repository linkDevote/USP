#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void trocar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partion(int a[], int p, int r){
    int x = a[r];
    int i = p - 1;

    for(int j = p; j <= r - 1; j++){
        if(a[j] <= x){
            i++;
            trocar(&a[i], &a[j]);
        }
    }
    trocar(&a[i + 1], &a[r]);
    return i + 1;
}

void quicksort(int a[], int p, int r){
    if(p < r){
        int q = partion(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

int main(){
    int len = 10;
    int* array = criarArray(len);
    
    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);

    quicksort(array, 0, len - 1);
    
    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);
    
    free(array);
    return 0;
}