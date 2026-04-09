#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int *v, int n){
    int inicio, i, novo, excl = 0;

    inicio = v[0];
    //5 1 1 5
    //inicio = 5
    for(i = 1; i < n; i++){
        novo = inicio > excl ? inicio : excl; 
        // novo = 5 > 0 -> 5
        // novo = 5 > 5 -> 5
        // novo = 6 > 5 -> 6
        // novo = 6 > 6 -> 6
        inicio = excl + v[i]; 
        // inicio = 0 + 5 -> 5
        // inicio = 5 + 1 -> 6
        // inicio = 5 + 1 -> 6
        // inicio = 6 + 5 -> 11
        excl = novo; 
        // excl = 5
        // excl = 5
        // excl = 6
        // excl = 6
    }

    return inicio > excl ? inicio : excl; // 11 > 6 -> 11
}

int main(){
    int *v = NULL;
    int n;

    srand(time(NULL));

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    v = malloc(n * sizeof(int));
    if(v==NULL){
        printf("Alocação deu errado");
        return 1;
    }
    
    for(i=0; i<n; i++){
        v[i] = (rand() % 100) - 50; // -50 a 99
    }

    free(v);
    return 0;
    
}