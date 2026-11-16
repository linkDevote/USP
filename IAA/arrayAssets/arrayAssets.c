#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arrayAssets.h"

int* criarArray(int tamanho){
    int* array = (int*) malloc(sizeof(*array)*tamanho);
    for(int i = 0; i < tamanho; i++){
        array[i] = rand() % 100;
    }
    
    return array;
}

void imprimeArray(int* array, int tamanho){
     for(int i = 0; i < tamanho; i++){
        printf("(%i) -> %i\n", i, array[i]);
    }
}

void testarOrdenador(int quantidade, void (*algoritmo)(int* array, int len)){
    // Cria os numeros aleatorios
    FILE* fp = fopen("/dev/urandom", "rb");

    if(!fp){
        fprintf(stderr, "Erro ao abrir o /dev/urandom\n");
        return;
    }

    unsigned int* randNum = (unsigned int*) malloc(sizeof(unsigned int) * quantidade);

    if(!randNum){
        fprintf(stderr, "Falha ao alocar array de %d elementos\n", quantidade);
        fclose(fp);
        return;
    }

    size_t read = fread(randNum, sizeof(int), quantidade, fp);

    fclose(fp);

    if(read != quantidade){
        fprintf(stderr, "Erro ao criar os numeros aleatorios\n");
        free(randNum);
        return;
    }

    FILE* desordenado = fopen("desordenado.txt", "w");
    if(!desordenado){
        fprintf(stderr, "Erro ao criar o arquivo desordenado.txt\n");
        return;
    }
    
    for(int i = 0; i < quantidade; i++){
        fprintf(desordenado, "%d \n", randNum[i]);
    }
    fclose(desordenado);

    // Testa o ordenador e cria um arquivo com os valores ordenados
    struct timespec initTime, endTime;
    clock_gettime(CLOCK_MONOTONIC, &initTime);
    clock_t initClock = clock();

    algoritmo(randNum, quantidade);

    clock_t endClock = clock();
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    double tempoSegundos = (endTime.tv_sec - initTime.tv_sec) +
                           (endTime.tv_nsec - initTime.tv_nsec) / 1e9;
    clock_t totalClocks = endClock - initClock;

    FILE* ordenado = fopen("ordenado.txt", "w");
    if(!ordenado){
        fprintf(stderr, "Erro ao criar o arquivo ordenado.txt\n");
        return;
    }
    
    for(int i = 0; i < quantidade; i++){
        fprintf(ordenado, "%d \n", randNum[i]);
    }
    fclose(ordenado);
    
    fprintf(stdout, "Arquivo ordenado com sucesso!\n ");
    fprintf(stdout, "Foi alocado um array com %d inteiros\n ", quantidade);
    fprintf(stdout, "O tamanho do array alocado em Kb e %d\n ", quantidade*4);
    fprintf(stdout, "O processo de ordenacao durou %.6f segundos\n ", tempoSegundos);
    fprintf(stdout, "Foram feitos %ld clocks do processador\n ", (long)totalClocks);

    free(randNum);
}
