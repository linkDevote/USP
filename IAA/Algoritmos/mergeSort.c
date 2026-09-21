#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* criarArray(int tamanho);
void merge(int* array, int ini, int mid, int end);
void mergeSort(int* array, int ini, int end);

int main()
{
    int len = 10;
    int* array = criarArray(len);
    
    printf("--------NÃO ORDENADO--------\n");
    for(int i = 0; i < len; i++){
        printf("(%i) -> %i\n", i, array[i]);
    }

    mergeSort(array, 0, len - 1);
    
    printf("----------ORDENADO----------\n");
    for(int i = 0; i < len; i++){
        printf("(%i) -> %i\n", i, array[i]);
    }
    
    free(array);
    return 0;
}

int* criarArray(int tamanho){
    int* array = (int*) malloc(sizeof(*array)*tamanho);
    for(int i = 0; i < tamanho; i++){
        array[i] = rand() % 100;
    }
    
    return array;
}

void merge(int* array, int ini, int mid, int end){
    int n1 = mid - ini + 1;
    int n2 = end - mid;
    
    int* left = malloc(sizeof(*left) * (n1 + 1));
    int* right = malloc(sizeof(*right) * (n2 + 1));
    
    for(int i = 0; i < n1; i++){
        left[i] = array[ini + i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = array[mid + 1 + j];
    }
    
    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    
    int i = 0; 
    int j = 0;
    
    for(int k = ini; k <= end; k++){
        if(left[i] <= right[j]){
            array[k] = left[i];
            i++;
        }else{
            array[k] = right[j];
            j++;
        }
    }
    
    free(left);
    free(right);
}

void mergeSort(int* array, int ini, int end){
    if(ini < end){
        int mid = (ini + end)/2;
        mergeSort(array, ini, mid);
        mergeSort(array, mid + 1, end);
        merge(array, ini, mid, end);
    }
}