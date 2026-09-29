#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../../arrayAssets/arrayAssets.h"
#include "../../arrayAssets/arrayAssets.c"

void merge(int* array, int ini, int mid, int end);
void mergeSort(int* array, int ini, int end);

int main()
{
    int len = 10;
    int* array = criarArray(len);
    
    printf("--------NÃO ORDENADO--------\n");
    imprimeArray(array, len);

    mergeSort(array, 0, len - 1);
    
    printf("----------ORDENADO----------\n");
    imprimeArray(array, len);
    
    free(array);
    return 0;
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
    for (int curr_size = 1; curr_size <= end - ini; curr_size = 2 * curr_size) {
        
        for (int left_start = ini; left_start < end; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            
            if (mid < end) {
                int right_end = (left_start + 2 * curr_size - 1 < end) ? (left_start + 2 * curr_size - 1) : end;
                merge(array, left_start, mid, right_end);
            }
        }
    }
}