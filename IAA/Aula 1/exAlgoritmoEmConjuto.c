#include <stdio.h>
#include <stdlib.h>

void geradorArrayAleatorio(int arraySize, int* array);
void ordenadorArray(int arraySize, int* array, int maior);
int maior(int arraySize, int* array);

int main(){
    int tamanho = 5;
    int arranjo[5];

    geradorArrayAleatorio(tamanho, arranjo);
    int maiorIndice = maior(tamanho, arranjo);

    ordenadorArray(tamanho, arranjo, maiorIndice);

    for(int i = 0; i < tamanho; i++){
        printf("(%i)\n", arranjo[i]);
    }

    return 0;
}


void geradorArrayAleatorio(int arraySize, int* array){    
    for(int i = 0; i < arraySize; i++){
        array[i] = rand() % 100;
    }
}

int maior(int arraySize, int* array){
    int maiorNum = 0;
    int maiorIndice = 0;

    for(int i = 0; i < arraySize; i++){
        if(maiorNum < array[i]){
            maiorNum = array[i];
            maiorIndice = i;
        }
    }

    return maiorIndice;
}

void ordenadorArray(int arraySize, int* array, int maior){
    int temp = 0;

    for(int i = 0; i < arraySize - 1; i++){
        for(int j = 0; j < arraySize - 1 - i; j++){
            if(array[j] < array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}