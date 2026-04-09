#include <stdio.h>
#include <stdlib.h>

int degrau(int n){
    int resposta = 0, i;

    if(n<= 1){
        return n;
    }

    for(i=1; i<=2 && i <= n; i++){
        resposta = resposta + degrau(n-1); 
        //r = 0 + degrau(3) 
    }
    // degrau(3)
    // r = 0 + degrau(2)
    // r = 0 + 4 ====
    // r = 

    //degrau(2)
    //r = 0 + degrau(1)
    //r = 1; ======== 0
    //r = 1 + degrau(1)
    //r = 1 + 1 -> 2 ====== 1
    //r = 2 + degrau (1)
    //r = 3 ====== 2
    //

    //degrau(1)
    //retorna 1
}

int main(){

}