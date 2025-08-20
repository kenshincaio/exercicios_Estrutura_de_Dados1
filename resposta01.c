//Caio Yamada RA: CV309510X

#include<stdio.h>

int main() {
    
    int array1[50], array2[25], i;

    printf("Insira 50 valores inteiros para o primeiro array\n");
    for(i = 0; i <50; i++){
        printf("Insira um valor para o array1[%i]: \n",i);
        scanf("%i",&array1[i]);
    }
    for(i = 0; i < 25; i++){
        array2[i] = array1[2 * i] * array1[2 * i + 1];  
    }
    for(i = 0; i < 25; i++){
        printf("O valor do array2[%i] = %i\n", i, array2[i]);
    }
    return 0;
}



