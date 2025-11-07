//Caio Yamada - CV309510X
///Perdao pelos muitos fflushs, nao confio nesse codeblocks.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAXMUS 10000

struct musica{
    char titulo[100];
    char artista[30];
    float duracaoSeg;
    int idMus;
};

typedef struct musica Musica;

struct playlist{
    char nome[100];
    int qtdMus;
    int quaisMus[100];
    float totalSeg;
};

typedef struct playlist Playlist;

void cadastraMusica(Musica musicas[], int *contMus){ ///Cadastro
    Musica umaMusica;

    if((*contMus) < MAXMUS){
        printf("\nDigite o titulo da musica: ");
        fflush(stdin);
        fgets(umaMusica.titulo, 100, stdin);
        fflush(stdin);
        printf("\nDigite o artista: ");
        fflush(stdin);
        fgets(umaMusica.artista, 30, stdin);
        fflush(stdin);
        printf("\nDigite a duracao da musica em segundos: ");
        scanf("%f", &umaMusica.duracaoSeg);
        fflush(stdin);

        musicas[*contMus] = umaMusica;
        musicas[*contMus].idMus++;
        (*contMus)++;

    }else{
        printf("\nLimite de cadastro atingido, musica nao inserida!");
        return;
    }
}

void criaPlaylist(Playlist listas[], int *qtdPlaylist, int *contMus, Musica musicas[]) { ///Playlists
    Playlist novaLista;
    char resposta;
    char nomeMus[100];
    int i, j = 0;
    int musEncontrada = 0;
    novaLista.qtdMus = 0;
    novaLista.totalSeg = 0;

    printf("\nDigite o nome da playlist: ");
    fflush(stdin);
    fgets(novaLista.nome, 100, stdin);
    fflush(stdin);
    do{
        printf("\nDeseja inserir uma musica na playlist (%i/100)? (S/N) ", novaLista.qtdMus);
        scanf(" %c", &resposta);
        fflush(stdin);
        if(resposta == 'S' || resposta == 's'){
            printf("\nDigite o nome da musica: ");
            fflush(stdin);
            fgets(nomeMus, 100, stdin);
            fflush(stdin);
            for(i = 0; i < (*contMus); i++){
                if(strcmp(nomeMus,musicas[i].titulo) == 0){
                    printf("Musica encontrada, inserindo...\n");
                    novaLista.quaisMus[j] = musicas[i].idMus;
                    novaLista.totalSeg += musicas[i].duracaoSeg;
                    j++;
                    novaLista.qtdMus++;
                    listas[*qtdPlaylist] = novaLista;
                    musEncontrada = 1;
                    break;
                }
            }
            if(musEncontrada != 1){
                printf("\nMusica nao encontrada :(");
            }
        }
    } while(resposta == 'S'  || resposta == 's'&& novaLista.qtdMus < 100);


    listas[*qtdPlaylist] = novaLista;
    (*qtdPlaylist)++;
}

void imprimirRelatorio(Musica musicas[], int *contMus, Playlist listas[], int *qtdPlaylist){ ///Relatorio
    int i, j;

    printf("\n\n----- Impressao do Relatorio -----\n\n");
    for(i = 0; i < (*qtdPlaylist); i++){
        printf("Playlist %i: %-30s  (%.2f segundos)\n", (i + 1), listas[i].nome, listas[i].totalSeg);
        for(j = 0; j < listas[i].qtdMus; j++){
            printf("\t %i. %-30s %-30s %.2f\n", (j + 1), musicas[j].titulo, musicas[j].artista, musicas[j].duracaoSeg);
        }
        printf("\n");
    }
}

int main(){
    Musica musicas[MAXMUS];
    Playlist listas[100];
    int contMus = 0;
    int qtdPlaylist = 0;
    int opcao;
    do{
        printf("\n\n----- Menu Spotifinho -----\n\n");
        printf("1 - Cadastrar Musica.\n");
        printf("2 - Criar Playlist.\n");
        printf("3 - Imprimir Relatorio.\n");
        printf("4 - Sair.\n");

        printf("\nO que deseja fazer? ");
        scanf("%i", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1: {
                cadastraMusica(musicas, &contMus);
                break;
            }
            case 2: {
                criaPlaylist(listas, &qtdPlaylist, &contMus, musicas);
                break;
            }
            case 3: {
                imprimirRelatorio(musicas, &contMus, listas, &qtdPlaylist);
                break;
            }
            case 4: {
                printf("Saindo...\n");
                break;
            }
            default: printf("Opcao invalida!\n");
        }
    }while(opcao != 4);
    return 0;
}
