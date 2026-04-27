#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    int valor;
} No;

typedef struct fila {
    No** dados;
    int inicio, fim;
}Fila;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* cria(){
    Arvore *arvore;
    arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

Fila* criaFila(int tamanho){
    Fila *f = malloc(sizeof(Fila)); //ponteiro da struct da fila
    f->dados = malloc(sizeof(No*) * tamanho); //aloca o tamanho para os dados, Tamanho de cada nó * quantidade possível de elementos na fila
    f->inicio = f->fim = 0; //inicio e fim da fila começam em 0
    return f; //retorna a fila
}

void enfileira(Fila* f, No* n){
    f->dados[f->fim++] = n; //avança uma posição em dados, incrementa fim e insere n (raiz passada como parametro) nessa nova posição 
}

No* desenfileira(Fila* f){
    return f->dados[f->inicio++]; //incrementa início, vai diminuindo a quantidade de elementos
}

int vazia(Fila* f){
    return f->inicio == f->fim; //se inicio é igual ao fim então fila esvaziou
}

No* inserirNivel(No* raiz, int valor){
    No* novo = novoNo(valor); //cria novo nó zerado

    if(raiz==NULL) return novo; //retorna novo se a arvore não tem nenhum elemento ainda

    Fila* f = criaFila(100); //cria fila com tamanho 100
    enfileira(f, raiz); //enfileira a raiz passada na fila

    while(!vazia(f)){ //enquanto a filha não estiver vazia
        No* atual = desenfileira(f); //atual recebe o novo nó de inicio

        if(atual->esquerda == NULL){ //verifica se o filho esquerdo é nulo
            atual->esquerda = novo; //insere como filho esquerdo de atual
            break;
        } else {
            enfileira(f, atual->esquerda); //já havia um elemento, então enfileira esse elemento que já existia
        }

        if(atual->direita == NULL){
            atual->direita = novo;
            break;
        } else {
            enfileira(f, atual->direita);
        }
    }
    return raiz;
}

void imprimirEmOrdem(No* raiz){
    if(raiz){
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

No* adiciona(Arvore* arvore, No* pai, float valor){
    No *no = malloc(sizeof(No));

    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;

    if (pai == NULL){
        arvore->raiz = no;
    }

    return no;
}


int main(){
    Arvore *a = cria();
    float valores[] = {4, 2, 8, 1, 3, 6, 9, 5, 7};
    int n = 9;
    No *raiz = NULL;
 
    for(int i = 0; i < n; i++){
        raiz = inserirNivel(raiz, valores[i]); //insere os valores, a cada iteração o ponto de partida da inserção muda
    }
    printf("Em ordem: ");
    imprimirEmOrdem(raiz);

    return 0;
}