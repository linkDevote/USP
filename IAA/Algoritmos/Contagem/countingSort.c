#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void countingSort(int A[], int n) {
    if (n <= 0) return;

    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }

    int *C = (int *)calloc(max + 1, sizeof(int));
    int *B = (int *)malloc(n * sizeof(int));

    for (int j = 0; j < n; j++) {
        C[A[j]]++;
    }

    for (int i = 1; i <= max; i++) {
        C[i] += C[i - 1];
    }

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(C);
    free(B);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int len = 10;
    int* array = criarArray(len);

    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);

    countingSort(array, len);

    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);

    free(array);
    return 0;
}