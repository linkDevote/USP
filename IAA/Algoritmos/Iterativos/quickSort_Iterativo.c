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
    if (p >= r) return;

    int stack_size = r - p + 1;
    int* stack = (int*)malloc(sizeof(int) * stack_size);
    if (stack == NULL) return;

    int top = -1;

    stack[++top] = p;
    stack[++top] = r;

    while (top >= 0) {
        r = stack[top--];
        p = stack[top--];

        int q = partion(a, p, r);

        if (q - 1 > p) {
            stack[++top] = p;
            stack[++top] = q - 1;
        }

        if (q + 1 < r) {
            stack[++top] = q + 1;
            stack[++top] = r;
        }
    }

    free(stack);
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