#include <stdio.h>

int v[] = {1, 2, 3, 4, 5};
// primeiro se deve ordenar
// desconsiderar os negativos
// ir um por um
// começar contando em 0 verificando se o primeiro é 0 e assim por diante  

int* ordenaVetorExcluiNeg(int *v, int inicio, int fim){
    int *ordenado, inicio, fim;
    int pivo = v[inicio];

    while (inicio < fim){

        while(v[inicio] < v[pivo]) inicio++;
        while(v[fim] > v[pivo]) fim--;

        if (v[inicio] > v[fim]){
            
            v[fim] = v[inicio];
        }
    }
    return v;
}

int main(){
    int *j = ordenaVetorExcluiNeg(v, 0, 4);

    printf("%i" ,j[1]);
}