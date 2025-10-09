#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXC 10000
#define MAXE 500

int main(){
    struct cliente{
        char cpf[12], nome[30];
    };

    typedef struct cliente Cliente;

    struct exame{
        char codigo[20], nome[30];
        float valor;
    };

    typedef struct exame Exame;

    Cliente clientes[MAXC];
    Exame exames[MAXE];
    int clientCounter = 0;
    int examCounter = 0;

    char opcao;
    
    do{
        printf("*************Menu da Clinica*************\n\n");
        printf("C -- Cadastrar Cliente\n");
        printf("E -- Cadastrar Exame\n");
        printf("A -- Agendar Exame\n");
        printf("I -- Imprimir relatorio\n");
        printf("S -- Sair\n");

        printf("Qual opcao deseja? ");
        fflush(stdin);
        scanf("%c", &opcao);

        switch(toupper(opcao)){

            case 'C':{
                if(clientCounter == MAXC){
                    printf("\nLimite de clientes cadastrado foi excedido. Cadastro nao realizado.");
                } else{
                    bool CPFduplo = false;

                    printf("\nCadastrar cliente: ");
                    printf("\nDigite o seu CPF: ");
                    fflush(stdin);
                    fgets(clientes[clientCounter].cpf, 12, stdin);
                    for(int i = 0; i < clientCounter && !CPFduplo; i++){
                        if(strcmp(clientes[i].cpf, clientes[clientCounter].cpf) == 0){
                            printf("\nEste CPF ja foi cadastrado.");
                            CPFduplo = true;
                        } 
                    }
                    if(!CPFduplo){
                        printf("\nDigite o seu nome:");
                        fflush(stdin);
                        fgets(clientes[clientCounter].nome, 30, stdin);
                    }

                    clientCounter++;
                }
                break;
            }

            case 'E':{
                if(examCounter == MAXE){
                    printf("\nLimite de exames cadastrado foi excedido. Cadastro nao realizado.");
                } else{
                    bool codDuplo = false;
                    printf("\nCadastrar exame: ");
                    printf("\nDigite o codigo do exame: ");
                    fflush(stdin);
                    fgets(exames[examCounter].codigo, 12, stdin);
                    for(int i = 0; i < examCounter && !codDuplo; i++){
                        if(strcmp(exames[i].codigo, exames[examCounter].codigo) == 0){
                            printf("\nJa existe um exame com esse codigo.");
                            codDuplo = true;
                        } 
                    }
                    if(!codDuplo){
                        printf("\nDigite o nome do exame: ");
                        fflush(stdin);
                        fgets(exames[examCounter].nome, 30, stdin);
                        printf("\nDigite o valor do exame: ");
                        scanf("%f", &exames[examCounter].valor);
                    }

                    examCounter++;
                }
                break;
            }
        }
    } while(toupper(opcao) != 'S');
}