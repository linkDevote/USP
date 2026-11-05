/*
As questoes puladas sao questoes teoricas.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../../Listas Ligadas/listaLigada/listaLigada.c"

#define LISTA_ORDENADA

// 1 - Implemente uma funcao valorIndice que, receba um ponteiro, um indice e 
// devolva o valor armazenado neste indice

// #include "../../Listas Lineares/listaSequencialDinamica/listaSequencialDinamica.c"
// int valorIndiceSequencial(ListaSequencial* lista, int indice){
//     if(indice >= 0 && indice < lista->livre){\
//         return lista->a[indice];
//     }

//     return -1;
// }

int valorIndiceLigada(ListaLigada* lista, int indice){
    No* p = lista->primeiro;
    int i = 0;

    if(indice < 0) return -1;

    while(p != NULL && i < indice){
        p->proximo;
        i++;
    }

    return p->valor ? (p != NULL) : -1;
}

// 3a - Crie a função juntaListas1 que recebe o ponteiro para duas listas, junta o
// conteúdo das duas listas em uma única lista, e devolve o endereço da lista
// resultante. Implemente a função de modo que o conteúdo das listas
// passadas como parâmetro da função não sejam alterados.

#ifdef LISTA_ORDENADA
ListaLigada* juntaListas1(ListaLigada* lista1, ListaLigada* lista2) {
    ListaLigada* novaLista = cria_lista();
    No* p1 = lista1->primeiro;
    No* p2 = lista2->primeiro;

    int i =0;
    while(p1 != NULL && p2 != NULL){
        if(p1->valor < p2->valor){
            insere(novaLista, p1->valor, i);
            p1 = p1->proximo;
        }else {
            insere(novaLista, p2->valor, i);
            p2 = p2->proximo;
        }

        i++;
    }

    while(p1 != NULL){
        insere(novaLista, p1->valor, i);
        p1->proximo;
        i++;
    }

    while(p2 != NULL){
        insere(novaLista, p2->valor, i);
        p2->proximo;
        i++;
    }

    return novaLista;
}
#else
ListaLigada* juntaListas1(ListaLigada* lista1, ListaLigada* lista2) {
    ListaLigada* novaLista = cria_lista();
    int i = 0;
    
    No* p = lista1->primeiro;
    while (p != NULL) {
        insere(novaLista, p->valor, i);
        p = p->proximo;
        i++;
    }

    p = lista2->primeiro;
    while (p != NULL) {
        insere(novaLista, p->valor, i);
        p = p->proximo;
        i++;
    }

    return novaLista;
}
#endif

// 3b - Crie uma função junta_listas_2 que recebe o ponteiro para duas listas, junta
// o conteúdo das duas listas em uma única lista, e devolve o endereço da lista
// resultante. Para esta segunda versão, é permitido alterar o conteúdo de uma
// das listas passadas como parâmetro para a função.
#ifdef LISTA_ORDENADA
ListaLigada* juntaListas2(ListaLigada* lista1, ListaLigada* lista2) {
    if (lista1->primeiro == NULL) {
        lista1->primeiro = lista2->primeiro;
        lista2->primeiro = NULL;
        return lista1;
    }
    if (lista2->primeiro == NULL) {
        return lista1;
    }

    No* p1 = lista1->primeiro;
    No* p2 = lista2->primeiro;
    No* atual = NULL;

    if (p1->valor <= p2->valor) {
        lista1->primeiro = p1;
        atual = p1;
        p1 = p1->proximo;
    } else {
        lista1->primeiro = p2;
        atual = p2;
        p2 = p2->proximo;
    }

    while (p1 != NULL && p2 != NULL) {
        if (p1->valor <= p2->valor) {
            atual->proximo = p1;
            atual = p1;  
            p1 = p1->proximo;
        } else {
            atual->proximo = p2;
            atual = p2;
            p2 = p2->proximo;
        }
    }

    if (p1 != NULL) {
        atual->proximo = p1;
    } else {
        atual->proximo = p2;
    }

    lista2->primeiro = NULL;

    return lista1;
}
#else
ListaLigada* juntaListas2(ListaLigada* lista1, ListaLigada* lista2) {
    if (lista1->primeiro == NULL) {
        lista1->primeiro = lista2->primeiro;
        return lista1;
    }

    No* temp = lista1->primeiro;

    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }

    temp->proximo = lista2->primeiro;
    lista2->primeiro = NULL;

    return lista1;
}
#endif