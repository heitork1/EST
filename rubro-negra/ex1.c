#include <stdlib.h>
#include <stdio.h>

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no{
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    Cor cor;
    int valor;
} No;

typedef struct arvore{
    struct no* raiz;
    struct no* nulo;
}Arvore;

Arvore* criaArvore();
No* criaNo(Arvore* arvore, int valor);
void adicionaNo(Arvore* arvore, No* no);
void rotacionarEsquerda(Arvore* arvore, No* no);
void rotacionarDireita(Arvore* arvore, No* no);
void balancear(Arvore* arvore, No* no);

Arvore* criaArvore(){
    Arvore* arvore = malloc(sizeof(Arvore));
    No* nulo = malloc(sizeof(No));
    nulo->cor = Preto;
    nulo->esquerda = nulo->direita = nulo->pai = NULL;
    
    arvore->raiz = nulo;
    arvore->nulo = nulo;
    
    return arvore;
}


No* criaNo(Arvore* arvore, int valor){
    No* no = malloc(sizeof(No));
    no->cor = Vermelho;
    no->valor = valor;
    no->esquerda = arvore->nulo;
    no->direita = arvore->nulo;
    no->pai = arvore->nulo;

    adicionaNo(arvore, no);

    balancear(arvore, no);
    return no;
}

void adicionaNo(Arvore* arvore, No* no){
    // if(arvore->raiz == NULL){
    //     arvore->raiz = no; 
    //     no->pai = arvore->nulo;
    //     no->esquerda = arvore->nulo;
    //     return;
    // }
    
    No* atual = arvore->raiz;
    No* pai = arvore->nulo;
    
    while(atual != arvore->nulo){
        pai=atual;
        if(no->valor < atual->valor){
            atual = atual->esquerda;
        }else{
            atual=atual->direita;
        }
    }
    
    no->pai = pai;
    no->esquerda = arvore->nulo;
    no->direita = arvore->nulo;
    
    if (pai == arvore->nulo){
        arvore->raiz = no;
    } else if(no->valor < pai->valor){
        pai->esquerda = no;
    } else {
        pai->direita = no;
    }
}

void rotacionarEsquerda(Arvore* arvore, No* no){
    No* direita = no->direita;
    no->direita = direita->esquerda;

    if(direita->esquerda != arvore->nulo){
        direita->esquerda->pai = no; //se houver filho à esquerda em direita, ele será pai do nó
    }

    direita->pai = no->pai; //ajusta no pai do nó a direita

    if(no->pai == arvore->nulo){
        arvore->raiz = direita; //se nó for raiz, o nó direita será a nova raiz da árvore
    }else if(no == no->pai->esquerda){
        no->pai->esquerda = direita; //corrige relação pai-filho do novo pai (esquerda)
    } else {
        no->pai->direita = direita; //corrige relação pai-filho do novo pai (direita)
    }

    direita->esquerda = no; //corrige relação pai-filho entre o nó pivô e o nó à direita
    no->pai = direita;
}

void rotacionarDireita(Arvore* arvore, No* no){
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;

    if(esquerda->direita != arvore->nulo){
        esquerda->direita->pai = no; //se houver filho à direita em esquerda, ele será pai do nó
    }

    esquerda->pai = no->pai; //ajusta no pai do nó a esquerda

    if(no->pai == arvore->nulo){
        arvore->raiz = esquerda;
    }else if(no == no->pai->esquerda){
        no->pai->esquerda = esquerda;
    }else{
        no->pai->direita = esquerda;
    }

    esquerda->direita = no;
    no->pai = esquerda;
}


void balancear(Arvore* arvore, No* no){
    while(no->pai->cor == Vermelho){ //Garante que todos os níveis foram balanceados
        if(no->pai == no->pai->pai->esquerda){ //verifica se nó pai é igual ao nó tio esquerdo
            No *tio = no->pai->pai->direita; //tio recebe tio direito

            if(tio->cor == Vermelho) {
                tio->cor = Preto; //resolve caso 2
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho;
                no = no->pai->pai; //vai para o nivel anterior
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //vai para o nivel anterior
                    rotacionarEsquerda(arvore, no); //resolve caso 3
                } else {
                    no->pai->cor = Preto; //resolve caso 4
                    no->pai->pai->cor = Vermelho;
                    rotacionarDireita(arvore, no->pai->pai);
                }
            }
        } else {
            //Repete o mesmo código do bloco if, invertendo o lado dos direita e esquerda
            No *tio = no->pai->pai->esquerda; 

            if(tio->cor == Vermelho) {
                tio->cor = Preto; 
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho;
                no = no->pai->pai; 
            } else {
                if (no == no->pai->esquerda) {
                    no = no->pai; 
                    rotacionarDireita(arvore, no); 
                } else {
                    no->pai->cor = Preto; 
                    no->pai->pai->cor = Vermelho;
                    rotacionarEsquerda(arvore, no->pai->pai);
                }
            }
        }
    }
    arvore->raiz->cor = Preto; //resolve caso 1
}

int main(){
    Arvore* arvore = criaArvore();
    criaNo(arvore, 10);
    criaNo(arvore, 20);
    criaNo(arvore, 30);
    
    printf("Raiz: %d\n", arvore->raiz->valor);
}
