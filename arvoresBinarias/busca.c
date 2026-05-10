#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* cria(){
    Arvore *arvore;
    arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No* adicionar(Arvore* arvore, No* pai, int valor){
    No *no = malloc(sizeof(No));
    
    no->pai=pai;
    no->esquerda = NULL;
    no->direita= NULL;
    no->valor=valor;

    if(pai==NULL){
        arvore->raiz=no;
    }
    return no;
}


void percorrerProfundidadeInOrder(No* no, void(callback)(int)){
    if(no != NULL){
        percorrerProfundidadeInOrder(no->esquerda, callback);
        callback(no->valor);
        percorrerProfundidadeInOrder(no->direita, callback);
    }
}

void percorrerProfundidadePreOrder(No* no, void (callback)(int)){
    if (no != NULL){
        callback(no->valor);
        percorrerProfundidadePreOrder(no->esquerda, callback);
        percorrerProfundidadePreOrder(no->direita, callback);
    }
}

void percorrerProfundidadePosOrder(No* no, void (callback)(int)){
    if(no != NULL){
        percorrerProfundidadePosOrder(no->esquerda, callback);
        percorrerProfundidadePosOrder(no->direita, callback);
        callback(no->valor);
    }
}

void visitar(int valor){
    printf("%d ", valor);
}

int main(){
    Arvore *a = cria();
    
    return 0;
}