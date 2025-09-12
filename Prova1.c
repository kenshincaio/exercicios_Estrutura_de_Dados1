//Caio Yamada CV309510X
#include<stdio.h>
#include<string.h>

int main()
{
    char forca[11] = {'/0'}, pInserida[11], tentativa, tentativaFinal[11], *check;
    int i, j, len, repetido = 0, max_tentativas = 6;
    printf("\nDigite uma palavra com no minimo 4 letras  sem repeticao de caractere para comecar o jogo: ");
    fgets(pInserida, 11, stdin);
    len = strlen(pInserida);

    for(i = 0; i < len; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(pInserida[i] == pInserida[j])
            {
                repetido = 1;
            }
        }
    }
    if(strlen(pInserida) < 5)
    {
        printf("\nQuantidade de letras invalida.");
    }
    else if(repetido)
    {
        printf("\nPalavra invalida.");
    }
    else
    {
        for(i = 0; i < len - 1; i++){
            forca[i] = '_';
        }
        printf("%s",forca);

        while(max_tentativas != 0)
        {
            printf("\nJogador 2, digite uma letra para a tentativa: ");
            fflush(stdin);
            scanf("%c", &tentativa);
            check = strchr(pInserida, tentativa);

            if(check == NULL)
            {
                printf("\nEssa letra nao esta na palavra.");
            }
            else
            {
                for(i = 0; i < len; i++)
                {
                    if(pInserida[i] == tentativa){
                        forca[i] = tentativa;
                    }
                }
                printf("forca: %s",forca);
            }

            check = strchr(forca, '_');
            if(check == NULL){
                printf("\nPalavra certa!!!");
                break;
            }
            max_tentativas--;
        }
        if(max_tentativas == 0){
            printf("\nTentativa final de acertar a palavra: ");
            fflush(stdin);
            fgets(tentativaFinal, 11, stdin);
            if(strcmp(tentativaFinal, pInserida) == 0){
                printf("\nAcertou!!");
            } else{
                printf("\nErrou!!");
            }
        }
    }
    return 0;
}
