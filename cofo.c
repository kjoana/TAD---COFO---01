#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "cofo.h"

typedef struct _cofo_
{
    int numItens; // numero de itens dentro do cofo
    int maxItens; // numero de itens que posso  colocar dentro do cofo
    int *itens; // vetor para guardar os itens

} Cofo;

Cofo *criarCofo(int n){

    Cofo *c;

    if (n > 0 ){
        c = (Cofo*)malloc(sizeof(Cofo));
        if (c != NULL){
            c->itens = (int*)malloc(sizeof(int)*n);
            if(c->itens != NULL ){
                c->numItens = 0;
                c->maxItens = n ;
                return c;
            }
            free(c);
        }
    }
    return NULL;
}

int destruirCofo( Cofo *c ){

    if( c != NULL ){
        if(c->numItens == 0){
            free(c->itens);
            free(c);
            return TRUE;
        }
    }
      return FALSE;
}

int inserirCofo (Cofo *c, int item){
    if(c!=NULL){
        if(c->numItens < c->maxItens){
            c->itens[c->numItens] = item;
            c->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

int removerCofo (Cofo *c, int key){

    int i, aux;
    if(c!=NULL){
        if(c-> numItens> 0){
            i = 0;
            while( i < c->numItens && c->itens[i] != key){
                i++;
            }
            if(c->itens[i]==key){
                aux = c->itens[i];
                for(int j=i ; j < c->numItens; j++){
                    c->itens[j] = c-> itens[j+1];
                }
                c->numItens--;
                return TRUE;
            }
        }
        return FALSE;
    }
}

int verificarCofo (Cofo *c, int key){
    int i;
    if(c!= NULL){
        if(c->numItens > 0){
            i = 0;
            while( i < c-> numItens && c->itens[i] != key){
                i++;
            }
            if(c->itens[i]== key){
                return TRUE;
            }
        }
        return FALSE;
    }
}

void mostrarCofo(Cofo *c){
  printf("\nCOFO = [ ");
  for(int i=0; i < c->numItens; i++){
    printf("%d,", c->itens[i]);
  }
  printf("]\n");
}


