#include <stdlib.h>
#include <stdio.h>

typedef struct fila {
    struct elemento* cabeca;
    struct elemento* cauda;
} Fila;

Fila* criarFila(){
    Fila *fila = malloc(sizeof(Fila));
    fila->cabeca = NULL;
    fila->cauda =NULL;
}

void adicionarFila(Fila* fila, No* valor){
    Elemento* elemento = malloc(sizeof(Elemento));
    
    elemento->valor = valor;
    elemento->proximo = NULL;

    if(fila)
}

void percorrerLargura(No* no, void (callback)(int)){
    Fila* fila = criarFila();
    adicionarFila(fila, no);

}

int main() {
    Arvore* a = criarArvore();

    No* no4 = adicionarArvore(a, NULL, 4);
    
    No* no2 = adicionarArvore(a, no4, 2);
    no4->esquerda = no2;

    No* no8 = adicionarArvore(a, no4, 8);
    no4->direita = no8;

    No* no1 = adicionarArvore(a, no2, 1);
    no2->esquerda = no1;

    No* no3 = adicionarArvore(a, no2, 3);
    no2->direita = no3;

    No* no6 = adicionarArvore(a, no8, 6);
    no8->esquerda = no6;

    No* no9 = adicionarArvore(a, no8, 9);
    no8->direita = no9;

    No* no5 = adicionarArvore(a, no6, 5);
    no6->esquerda = no5;

    No* no7 = adicionarArvore(a, no6, 7);
    no6->direita = no7;

    printf("Largura: ");
    percorrerLargura(a->raiz,visitar);
    printf("\n");

}