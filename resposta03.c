//Caio Yamada RA: CV309510X

#include<stdio.h>

int main(){
    int array[5], finalarray[5], index[5], i;

    for(i = 0; i < 5; i++){
        printf("Insira um valor inteiro para inserir no array[0, 1, 2, 3, 4]: \n");
        scanf("%i",&array[i]);
        printf("Agora insira um valor para o indice que quer inserir o valor (0-4): \n");
        scanf("%i",&index[i]);
    }
    for(i = 0; i < 5; i++){
        finalarray[index[i]] = array[i];
        printf("array final[%i] = %i\n", i, finalarray[index[i]]);
    }

    return 0;
}