#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;         // aqui vamos lidar com um struct pra ser só o nó cabeça
} Lista;

// Funções a serem implementadas:
int inicializar(Lista *l);  // retorna 0 se tiver algo errado
void inserirInicio(Lista *l, int valor);
void imprimirLista(Lista *l);
int remover(Lista *l, int valor); // retorna 1 se removeu, 0 caso contrário
void inverter(Lista *l); // DESAFIO
void destruir(Lista *l);
No* busca(Lista* l, int target);
No* buscaSentinela(Lista* l, int target);


int main() {
    Lista l;
    inicializar(&l);

    printf("Lista vazia: ");
    imprimirLista(&l);

    inserirInicio(&l, 40);
    inserirInicio(&l, 30);
    inserirInicio(&l, 20);
    inserirInicio(&l, 10);
    
    printf("Lista original: ");
    imprimirLista(&l);

    inverter(&l);
    printf("Lista invertida: ");
    imprimirLista(&l);

    remover(&l, 40);
    remover(&l, 20);
    printf("Apos remocoes: ");
    imprimirLista(&l);

    destruir(&l);
    return 0;
}

// IMPLEMENTACAO DAS FUNCOES

int inicializar(Lista *l){
    if(!l) return 0;

    l->cabeca = (No*) malloc(sizeof(No));
    l->cabeca->valor = -1;
    l->cabeca->prox = l->cabeca;
};

void inserirInicio(Lista *l, int valor){
    if(l == NULL) return;
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = l->cabeca->prox;
    l->cabeca->prox = novo;
}

void imprimirLista(Lista *l){
    if(l == NULL) return;
    No* atual = l->cabeca->prox;

    printf("Lista: ");
    while(atual){
        printf("(%d) -> ", atual->valor);
        atual = atual->prox;
    }
    printf(" \n");
}

int remover(Lista *l, int valor){
    if(l == NULL) return 0;

    No* atual = l->cabeca->prox;
    No* anterior = l->cabeca;

    while(atual != NULL){
        if(atual->valor == valor){
            break;
        }
        atual = atual->prox;
        anterior = anterior->prox;
    }

    if(atual == NULL){
        return 0;
    }

    anterior->prox = atual->prox;
    free(atual);

    return 1;
}

void destruir(Lista *l){
    if(l == NULL) return;

    No* atual = l->cabeca->prox;
    while(atual){
        No* aux = atual;
        atual = atual->prox;
        free(aux);
    }

    free(l->cabeca);
    l->cabeca = NULL;
}

void inverter(Lista *l){
    if(l == NULL) return;

    No* anterior = NULL;
    No* atual = l->cabeca->prox;
    No* prox = NULL;

    while(atual){
        prox = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = prox;
    }

    l->cabeca->prox = anterior;
    return;
}

No* busca(Lista* l, int target){
    if(l == NULL) return NULL;

    No* atual = l->cabeca->prox;
    while(atual != NULL){
        if(atual->valor == target){ 
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

No* buscaSentinela(Lista* l, int target){
    if(l == NULL) return -1;

    l->cabeca->valor = target;
    No* atual = l->cabeca->prox;
    while(atual->valor != target){
        atual = atual->prox;
    }

    if(atual == l->cabeca){
        l->cabeca->valor = -1;
        return NULL;
    }else{
        l->cabeca->valor = -1;
        return atual;
    }

}