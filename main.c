#include <stdio.h>
#include <time.h>

//gerar partições classificadas segundo o método de seleção com substituição
//m=7, capacidade memoria, registros simultanemante
//as partições são vetores
//36 elementos no 'arquivo'

int menorElem(int *vet, int m){
    int i, r;
    
    r=vet[0];
    for(i=0; i<m; i++){
        if(r>vet[i]){
            r = vet[i];
        }
    }
    return r;//re
}

int main()
{
    int i, m=7, j=0, k=0, r;
    int ps[7];
    int vetM[7];
    int arq[] = {30, 14, 15, 75, 32, 6, 5, 81, 48, 41, 87, 18,
56, 20, 26, 4, 21, 65, 22, 49, 11, 16, 8, 12,
44, 9, 7, 81, 23, 19, 1, 78, 13, 16, 51, 8};


    //ler 7 registros,
    for(i=0; i<m; i++){
        vetM[i] = arq[j];
        j++;
    }
    //pegando o menor entre 7 elementos
    int menor = menorElem(vetM, m);
    ps[k] = menor;
    k++;
    printf("ps[0]=%d\n", ps[0]);
    
    printf("vetM = {\n");
    for(i=0; i<m; i++){
        printf("%d,", vetM[i]);
    }
    printf("\n");
    for(i=0; i<m; i++){
        if(vetM[i] == menor){
            vetM[i] = arq[j];
        }
    }
    printf("Após substituição pelo oitavo elemento de arq[]: vetM = {\n");
    for(i=0; i<m; i++){
        printf("%d,", vetM[i]);
    }
    printf("\n");
    
    
    //o próximo registro registro eh 81
    //o ultimo r foi 5 
    //caso 81 < 5 considerá-lo congelado
    
    
    return 0;
}