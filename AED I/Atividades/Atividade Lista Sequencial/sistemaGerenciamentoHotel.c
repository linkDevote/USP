#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0

typedef int bool;

typedef struct {
    int id;
    char nome[50];
    int numeroQuarto;
} Cliente;

typedef struct {
    Cliente *clientes; // Ponteiro para o vetor
    int qtdClientes; // Quantidade atual de clientes
    int capacidade; // Capacidade máxima
} ListaClientes;

// Tarefa 1: Inicializacao da lista sequencial
ListaClientes* criarLista(int cap){
    ListaClientes* lista =(ListaClientes*) malloc(sizeof(ListaClientes));

    lista->capacidade = cap;
    lista->qtdClientes = 0;
    lista->clientes = (Cliente*) malloc(sizeof(Cliente) * cap);

    return lista;
}

// Tarefa 2: Insercao Ordenada por Quarto
bool inserirClienteOrdenado(ListaClientes* lista, Cliente cliente){
    if((lista->qtdClientes + 1 ) > lista->capacidade) return False;

    int i;
    for(i = 0; i < lista->qtdClientes; i++){
        if(lista->clientes[i].numeroQuarto > cliente.numeroQuarto) break;
    }

    for(int j = lista->capacidade; j > i; j--){
        lista->clientes[j] = lista->clientes[j - 1];
    }

    lista->clientes[i] = cliente;
    lista->qtdClientes++;
    return True;
}

// Tarefa 3: Busca Por Quarto
int buscarCliente(ListaClientes* lista, int quartoBuscado){
   int ini = 0;
   int fim = lista->qtdClientes - 1;
   int meio;

   while(ini <= fim){
        meio = (ini + fim)/2;

        if(quartoBuscado == lista->clientes[meio].numeroQuarto) return meio;
        if(quartoBuscado < lista->clientes[meio].numeroQuarto) fim = meio - 1;
        if(quartoBuscado > lista->clientes[meio].numeroQuarto) ini = meio + 1;
   }

   return -1;
}

// Tarefa 4: Busca Por Nome
bool nomeIgual(char* nome1, char* nome2){
    int lenNome1 = 0;
    int lenNome2 = 0;

    int i = 0;
    while(nome1[i] != '\0'){
        lenNome1++;
        i++;
    }

    int j = 0;
    while(nome2[j] != '\0'){
        lenNome2++;
        j++;
    }

    if(lenNome1 != lenNome2) return False;
    for(int c = 0; c < lenNome1; c++){
        if(nome1[c] != nome2[c]) return False;
    }

    return True;
}

int buscarClienteNome(ListaClientes* lista, char* nome){
    for(int i = 0; i < lista->qtdClientes; i++){
        if(nomeIgual(lista->clientes[i].nome, nome)) return i;
    }

    return -1;
}

int main() {
    // Tarefa 1: Criação da lista
    printf("--- Testando Tarefa 1: Criacao da Lista ---\n");
    ListaClientes* minhaLista = criarLista(5);
    if (minhaLista != NULL) {
        printf("Lista criada com sucesso! Capacidade: %d\n\n", minhaLista->capacidade);
    }

    // Clientes de teste
    Cliente c1 = {1, "Alice", 105};
    Cliente c2 = {2, "Bob", 102};
    Cliente c3 = {3, "Carlos", 108};

    // Tarefa 2: Insercao Ordenada
    printf("--- Testando Tarefa 2: Insercao Ordenada ---\n");
    printf("Inserindo Alice (Quarto 105)... Retorno: %d\n", inserirClienteOrdenado(minhaLista, c1));
    printf("Inserindo Bob (Quarto 102)... Retorno: %d\n", inserirClienteOrdenado(minhaLista, c2));
    printf("Inserindo Carlos (Quarto 108)... Retorno: %d\n\n", inserirClienteOrdenado(minhaLista, c3));
    
    // Tarefa 3: Busca por Quarto
    printf("--- Testando Tarefa 3: Busca por Quarto ---\n");
    int quartoParaBuscar = 105;
    int indiceQuarto = buscarCliente(minhaLista, quartoParaBuscar);
    if (indiceQuarto != -1) {
        printf("Quarto %d encontrado no indice: %d\n", quartoParaBuscar, indiceQuarto);
    } else {
        printf("Quarto %d nao encontrado.\n", quartoParaBuscar);
    }
    printf("\n");

    // Tarefa 4: Busca por Nome
    printf("--- Testando Tarefa 4: Busca por Nome ---\n");
    char nomeParaBuscar[] = "Bob";
    int indiceNome = buscarClienteNome(minhaLista, nomeParaBuscar);
    if (indiceNome != -1) {
        printf("Cliente '%s' encontrado no indice: %d\n", nomeParaBuscar, indiceNome);
    } else {
        printf("Cliente '%s' nao encontrado.\n", nomeParaBuscar);
    }
    printf("\n");

    free(minhaLista->clientes);
    free(minhaLista);

    return 0;
}