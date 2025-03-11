#include <stdio.h>
#include "lista_estatica.h"

void cria(Lista *p_l){
    int i;
    p_l->tam = 0;
    for(i=0; i < MAX; i++){
        p_l->vet[i] = -1;
    }
}

int vazia(Lista *p_l){
    int i;
    if(p_l->tam != 0)
        return 0;
    for(i=0; i<MAX; i++){
        if(p_l->vet[i] != -1){
            return 0;
        }
    }
    return 1;
}

void insere_inicio(Lista *p_l, elem_t e){
    int i;

    for(i = p_l->tam; i > 0; i--){
        p_l->vet[i] = p_l->vet[i-1];
    }
    p_l->vet[0] = e;
    p_l->tam ++;
}

void insere_fim(Lista *p_l, elem_t e){
    if(p_l->tam < MAX){
        p_l->vet[p_l->tam] = e;
        p_l->tam ++;
    }
}

int insere_ordenado(Lista *p_l, elem_t e){
    int i, j;
    for(i=0; i<p_l->tam; i++){
        if(p_l->vet[i] == e) return 0;
        if(e > p_l->vet[i] && e < p_l->vet[i+1]){
            for(j=(i+1); j<=p_l->tam; j++){
                p_l->vet[j+1] = p_l->vet[j];
            }
            p_l->vet[i+1] = e;
            p_l->tam++;
            return 1;
        }
    }
    return 0;
}
int ordenada(Lista *p_l){
    int i;
    for(i=0; i<p_l->tam; i++){
        if(!(p_l->vet[i] <= p_l->vet[i+1])){
            return 0;
        }
    }
    return 1;
}

void ordena(Lista *p_l){
    int i, j, temp;
    if(!ordenada(p_l)){
        for(i=0; i< p_l->tam; i++){
            for(j=(i+1); j<p_l->tam; j++){
                if(p_l->vet[i] > p_l->vet[j]){
                    temp = p_l->vet[i];
                    p_l->vet[i] = p_l->vet[j];
                    p_l->vet[j] = temp;
                }
            }
        }
    }
}

int remove_inicio(Lista *p_l, elem_t *p_e){
    int i;

    for(i=1; i<=p_l->tam; i++){
        p_l->vet[i-1] = p_l->vet[i];
    }

    p_l->tam--;

}

int remove_fim(Lista *p_l, elem_t *p_e){
    p_l->vet[p_l->tam-1] = -1;
    p_l->tam --;
}

int remove_valor(Lista *p_l, elem_t e){
    int i, j;
    for(i=0; i<p_l->tam; i++){
        if(p_l->vet[i] == e){
            p_l->vet[i] = -1;
            for(j=(i+1); i<p_l->tam; i++){
                p_l->vet[j-1] = p_l->vet[j];
            }
            p_l->tam --;
        }
    }

}

void inverte(Lista *p_l){
    int i, temp;
    for(i=0; i<(p_l->tam / 2); i++){
        temp = p_l->vet[i];
        p_l->vet[i] = p_l->vet[p_l->tam - i - 1];
        p_l->vet[p_l->tam - i - 1] = temp;
    }
}

void libera(Lista *p_l){
    int i;
    for(i=0;i<p_l->tam ; i++){
        p_l->vet[i] = -1;
    }
    p_l->tam = 0;
}

void exibe(Lista *p_l){
    int i;
    for(i=0; i<p_l->tam; i++){
        printf("\t%d", p_l->vet[i]);
    }
}
