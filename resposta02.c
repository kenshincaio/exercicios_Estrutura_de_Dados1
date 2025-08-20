//Caio Yamada RA: CV309510X
#include<stdio.h>

int main(){
    int array[5], i, crescente = 1, decrescente = 1;
    
    printf("Insira 20 valores inteiros: \n");
    for(i = 0; i < 5; i++){
        printf("Valor para o array[%i]: \n", i);
        scanf("%i",&array[i]);
    }

    for(i = 0; i < 4; i++){
        if(array[i] < array[i+1]){
            decrescente = 0;
        } else if(array[i] > array[i+1]){
            crescente = 0;
        } else {
            crescente = 0;
            decrescente = 0;
        }
    }
    if(crescente){
        printf("Os numeros estao em ordem crescente.\n");
    } else if(decrescente){
        printf("Os numeros estao em ordem decrescente.\n");
    } else {
        printf("Os numeros nao estao em ordem.\n");
    }
}