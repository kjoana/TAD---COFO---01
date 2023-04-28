#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "cofo.h"

int main(){

    setlocale(LC_ALL, "Portuguese");

    Cofo *meuCofo;
    int tamanhoCofo;

    while(TRUE){
        printf("\n Digite o tamanho do cofo : ");
        scanf("%d", &tamanhoCofo);
        if(tamanhoCofo < 1){
            printf("Valor inválido!");
        }else{
            break;
        }
    }

    meuCofo = criarCofo(tamanhoCofo);

    // menu
    int opcao = 0 ;
    int funcionou, item;

    while(TRUE){
        printf("\n");
        printf("\n------------------------\n");
        printf("1 - INSERIR ITEM\n");
        printf("2 - REMOVER ITEM\n");
        printf("3 - VERIFICAR ITEM\n");
        printf("4 - APAGAR O COFO\n");
        printf("5 - MOSTRAR COFO\n");
        printf("6 - SAIR\n");
        printf("------------------------");

        printf("\nO QUE DESEJA FAZER? ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("\nInsira o elemento : ");
                scanf("%d", &item);
                funcionou = inserirCofo(meuCofo, item);
                if(funcionou){
                    printf("\nValor foi inserido no cofo! \n");
                }else{
                    printf("\nValor nao foi inserido no cofo!\n");
                }
                break;

            case 2:
                printf("\nRemova o elemento:");
                scanf("%d", &item);
                funcionou = removerCofo(meuCofo, item);
                if(funcionou){
                    printf("\nValor removido do cofo!\n");
                }else{
                    printf("\nValor nao removido, pois nao esta no cofo!\n");
                }
                break;

            case 3:
                printf("\nVerifique elemento :");
                scanf("%d",&item);
                funcionou = verificarCofo(meuCofo, item);
                if(funcionou){
                    printf("\nValor esta no cofo!\n");
                }else{
                    printf("\nValor nao esta no cofo!\n");

                }
                break;

            case 4:
                funcionou = destruirCofo(meuCofo);
                if(funcionou){
                    printf("\nSeu cofo foi excluido.\n");
                }else{
                    printf("\nNão foi posssível excluir o cofo!\n");

                }
                break;

            case 5:
                mostrarCofo(meuCofo);
                break;
            
            case 6:
                printf("\nATE MAIS!");
                return FALSE;
                break;

            default:
                printf("\nOpçao invalida!");
                break;

        }
        printf(" ");
    }


return 0;


}

// taskkill -im main.exe -f 

