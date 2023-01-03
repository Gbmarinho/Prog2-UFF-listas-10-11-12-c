#include <stdio.h>
#include <stdlib.h>

struct elemento {
    float info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

Elemento* criaLista(){
    return NULL;
}
Elemento* lstInsere(Elemento* lst, float valor){
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = lst;
    return novo;
}
void lstImprime(Elemento* lst){
    Elemento* p;
    for (p = lst; p != NULL; p = p->prox){
        printf("info = %g\n", p->info);
    }
}

Elemento* filtra(Elemento *lst, float min, float max){
    Elemento* p;
    Elemento* lstnova;
    Elemento* lstnovaContrario;
    float b;
    lstnova = criaLista();
    lstnovaContrario = criaLista();
    for (p = lst; p != NULL; p = p->prox){
        if(p->info <= max && p->info >= min){
            b = p->info;
            lstnova = lstInsere(lstnova,b);
        }
    }
    for (p = lstnova; p != NULL; p = p->prox){
        b = p->info;
        lstnovaContrario = lstInsere(lstnovaContrario,b);
    }
    return lstnovaContrario;
}

int main(){
    Elemento *lst;
    lst = criaLista();
    lst = lstInsere(lst, 23.1);
    lst = lstInsere(lst, 53.53);
    lst = lstInsere(lst, 23.13);
    lst = lstInsere(lst, 53.54);
    lst = lstInsere(lst, 5.1);
    lst = lstInsere(lst, 6.31);
    lst = lstInsere(lst, 45.5);
    lst = lstInsere(lst, 32.42);
    lst = lstInsere(lst, 68.512);
    lst = lstInsere(lst, 92.5);
    lstImprime(lst);
    printf("\n------------------------------------------------\n\n");
    lst = filtra(lst, 24.3, 67.1);
    lstImprime(lst);
    return 0;
}
