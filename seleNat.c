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
