<<<<<<< HEAD
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int menorElem(int *vet, int m){
    int i, pos=-1;
    for(i=0; i<m; i++){
        if (vet[i] < vet[pos]){
            pos = i;
        }
    }
    return pos;
}

void doisAcinco(int *vetM, int *arq, int m, int *j, int **ps, int *k, int *res, int n, int *l){
    int i, r;
    //passo 2
    int pos = menorElem(vetM, m);

    int valor = vetM[pos];
    *ps = realloc(*ps, (*k + 1) * sizeof(int)); //aumenta uma posição no vetor de saída
    //passo 3
    (*ps)[*k] = valor; 
    (*k)++;//quantidade de posicoes na saida

    //passo 4
    if(!(l == n)){//cheio
        vetM[pos] = arq[*j];
        //passo5
        if(arq[*j] < valor){
            res[*l] = arq[*j];
            *l++;
        }
        (*j)++;
    }
}

int main()
{
    int i, m = 7, j = 0, k = 0, r, n = 6, l=0;
    int **particoes = malloc(sizeof(int *));
    int qtdPart = 0;

    int *ps = NULL;
    if (ps == NULL)
    {
        printf("Erro de alocacao PS");
        return 1;
    }

    int *vetM = malloc(m * sizeof(int));
    if (vetM == NULL)
    {
        printf("Erro de alocação vetM\n");
        return 1;
    }

    int *res = malloc(n * sizeof(int));
    if (res == NULL)
    {
        printf("Erro de alocacao res");
    }

    int arq[] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18,
                 56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8, 12,
                 44, 9, 7, 81, 23, 19, 1, 78, 13, 16, 51, 8};

    //passo 1
    for(i=0; i < m; i++){
        vetM[i] = arq[j];
        j++;
    }
    while(j < 36){
        
        if(!(l==n)){//passo 6
            doisAcinco(vetM, arq, m, &j, &ps, &k, res, n, &l);

        }else{
            //passo7.1
            particoes[qtdPart] = ps;
            free(ps);
            
            //passo 7.2
            for(i=0; i<l; i++){
                vetM[i]=res[i];
            }
            //passo 7.3
            free(res);
            res = malloc(n * sizeof(int));
            if(res == NULL){
                printf("Erro de alocacao res");
            }
            //passo 7.4
            ps = malloc(sizeof(int));
            if (ps == NULL){
                printf("Erro de alocacao\n");
            }
            qtdPart++;
        }
    }

}
=======
#include <stdio.h>
#include <stdlib.h>

int menorElem(int *vet, int m){
    int i, pos = 0;
    for(i = 1; i < m; i++){
        if(vet[i] < vet[pos]){
            pos = i;
        }
    }
    return pos;
}

int main(){
    int m = 7;   // memória
    int n = 6;   // reservatório

    int arq[] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18,
                 56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8, 12,
                 44, 9, 7, 81, 23, 19, 1, 78, 13, 16, 51, 8};

    int tamArq = 36;

    int *vetM = malloc(m * sizeof(int));
    int *res = calloc(n, sizeof(int));
    int *ps = NULL;
    int *tamPart = NULL;
    

    int **particoes = NULL;

    int j = 0; // leitura do arquivo
    int k = 0; // tamanho da partição
    int l = 0; // tamanho do reservatório
    int qtdPart = 0;

    // Passo 1: carregar memória
    for(int i = 0; i < m; i++){
        vetM[i] = arq[j++];
    }

    ps = malloc(sizeof(int));

    while(1){

        // enquanto ainda tem elementos na memória
        int pos = menorElem(vetM, m);
        int valor = vetM[pos];

        // adiciona na partição
        int *tmp = realloc(ps, (k + 1) * sizeof(int));
        if(tmp == NULL){
            printf("Erro realloc\n");
            exit(1);
        }
        ps = tmp;

        ps[k++] = valor;

        // ainda tem entrada?
        if(j < tamArq){

            if(arq[j] < valor){
                // vai pro reservatório
                res[l++] = arq[j];
                vetM[pos] = 999999;
            } else {
                // substitui na memória
                vetM[pos] = arq[j];
            }

            j++;

        } else {
            // não tem mais entrada → esvazia memória
            vetM[pos] = 999999; // "infinito"
        }

        // se reservatório enche → fecha partição
        if(l == n){
            particoes = realloc(particoes, (qtdPart + 1) * sizeof(int *));
            particoes[qtdPart++] = ps;

            // copia reservatório para memória
            for(int i = 0; i < m; i++){
                if(i < l){
                    vetM[i] = res[i];
                } else {
                    vetM[i] = 999999;
                }
            }
            tamPart = realloc(tamPart, qtdPart * sizeof(int));
            tamPart[qtdPart-1] = k;
            // reinicia
            ps = malloc(sizeof(int));
            k = 0;
            l = 0;
            for(int i = 0; i < n; i++) res[i] = 0;
        }

        // condição de parada: tudo processado
        int terminou = 1;
        for(int i = 0; i < m; i++){
            if(vetM[i] != 999999){
                terminou = 0;
                break;
            }
        }

        if(terminou && j >= tamArq){
            break;
        }
    }

    // salva última partição
    if(k > 0){
        particoes = realloc(particoes, (qtdPart + 1) * sizeof(int *));
        particoes[qtdPart] = ps;
        
        tamPart = realloc(tamPart, (qtdPart + 1) * sizeof(int));
        tamPart[qtdPart] = k;
        qtdPart++;
    }

    // imprimir resultado
    printf("\nPartições geradas:\n");
    for(int i = 0; i < qtdPart; i++){
        printf("Particao %d: ", i+1);
        for(int j = 0; j < tamPart[i]; j++){
            printf("%d ", particoes[i][j]);
        }
        printf("\n");
    }

    free(vetM);
    free(res);

    return 0;
}
>>>>>>> 46a185794c1968d0ab16ee46cb5c0f0437e9eb5f
