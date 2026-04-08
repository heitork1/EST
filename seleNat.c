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