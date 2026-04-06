#include <stdio.h>
#include <time.h>

// gerar partições classificadas segundo o método de seleção com substituição
// m=7, capacidade memoria, registros simultanemante
// as partições são vetores
// 36 elementos no 'arquivo'

int menorElem(int *vet, int m)
{
    int i, r;

    r = vet[0];
    for (i = 0; i < m; i++)
    {
        if (r > vet[i])
        {
            r = vet[i];
        }
    }
    return r; // re
}

void doisAcinco(int *vetM, int *arq, int *congelado, int m, int *j, int *ps, int *k)
{
    int i, r;
    //PASSO 2 - pegando o menor entre 7 elementos
    int menor = menorElem(vetM, m);

    //PASSO 3
    ps[*k] = menor;
    (*k)++;
    ps = realloc(ps, (((sizeof(ps)) / (sizeof(int))) + 1) * sizeof(int));
    printf("ps[0]=%d\n", ps[0]);

    printf("vetM = {\n");
    for (i = 0; i < m; i++)
    {
        printf("%d,", vetM[i]);
    }
    printf("\n");

    //PASSO 4
    for (i = 0; i < m; i++)
    {
        if (vetM[i] == menor)
        {
            vetM[i] = arq[(*j)];
        }
    }

    printf("Após substituição pelo oitavo elemento de arq[]: vetM = {\n");
    for (i = 0; i < m; i++)
    {
        printf("%d,", vetM[i]);
    }
    printf("\n");

    // o próximo registro registro eh 81
    // o ultimo r foi 5
    // caso 81 < 5 considerar congelado

    //PASSO 5
    if (arq[(*j)] < menor)
    {
        *congelado = 1;
    }
}

int main()
{
    int i, m = 7, j = 0, k = 0, r, congelado = 0;
    int **particoes = malloc(sizeof(int*)); 
    int qtdPart = 0;
    
    int *ps = malloc(sizeof(int));
    if (ps == NULL)
    {
        printf("Erro de alocação\n");
    }
    particoes[qtdPart] = malloc(sizeof(*ps));
    if (particoes[qtdPart] == NULL)
    {
        printf("Erro de alocação\n");
    }
    int *vetM = malloc(m * sizeof(int));
    if (vetM == NULL)
            {
                printf("Erro de alocação\n");
            }
    int arq[] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18,
                 56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8, 12,
                 44, 9, 7, 81, 23, 19, 1, 78, 13, 16, 51, 8};
    ;
    //PASSO 1 - ler 7 registros,
    for (i = 0; i < m; i++)
    {
        vetM[i] = arq[j];
        j++;
    }
    while (j < 36)
    {
        if (!congelado)//passo 6
        {
            doisAcinco(vetM, arq, &congelado, m, &j, ps, &k);
        }
        else //PASSO 7
        {
            *particoes[qtdPart] = *ps;

            //PASSO 7.1
            free(ps);
            ps = malloc(sizeof(int));
            if (ps == NULL)
            {
                printf("Erro de alocação\n");
            }
            qtdPart++;
            //PASSO 7.2
            congelado = 0;
            //PASSO 7.3
            particoes = malloc((qtdPart + 1) * sizeof(ps));
            //PASSO 7.4
        }
    }

    for(i=0; i<qtdPart; i++){
        free(particoes[i]);
    }
    free(particoes);
    free(vetM);
    
    return 0;
}
