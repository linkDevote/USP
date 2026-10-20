#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
    int maior = i;
    
    while (1) {
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;
        maior = i;

        // Verifica o filho da esquerda
        if (esq < n && arr[esq] > arr[maior]) {
            maior = esq;
        }

        // Verifica o filho da direita
        if (dir < n && arr[dir] > arr[maior]) {
            maior = dir;
        }

        if (maior == i) {
            break;
        }

        swap(&arr[i], &arr[maior]);
        i = maior; 
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int len = 10;
    int* array = criarArray(len);

    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);

    heapSort(array, len);

    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);

    free(array);
    return 0;
}