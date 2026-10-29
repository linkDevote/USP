#include <stdio.h>
#include <stdlib.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void countingSortByDigit(int A[], int n, int exp) {
    int *B = (int *)malloc(n * sizeof(int));
    int C[10] = {0};

    for (int i = 0; i < n; i++) {
        int digito = (A[i] / exp) % 10;
        C[digito]++;
    }

    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digito = (A[i] / exp) % 10;
        B[C[digito] - 1] = A[i];
        C[digito]--;
    }

    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }

    free(B);
}

void radixSort(int A[], int n) {
    if (n <= 0) return;

    int max = A;
    for (int i = 1; i < n; i++) {
        if (A[i] > max)
            max = A[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSortByDigit(A, n, exp);
    }
}

int main() {
    int len = 10;
    int* array = criarArray(len);

    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);

    radixSort(array, len);

    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);

    free(array);
    return 0;
}