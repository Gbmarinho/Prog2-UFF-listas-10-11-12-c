#include <stdio.h>
#include <stdlib.h>

struct elemento {
    int info; /* Valor inteiro armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

Elemento* criaLista(){
    return NULL;
}
Elemento* lstInsere(Elemento* lst, int valor){
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = valor;
    novo->prox = lst;
    return novo;
}
void lstImprime(Elemento* lst){
    Elemento* p;
    for (p = lst; p != NULL; p = p->prox){
        printf("info = %d\n", p->info);
    }
}

Elemento* copia(Elemento* lst){
    Elemento* p;
    Elemento* lstnova;
    Elemento* lstnovaContrario;
    int b;
    lstnova = criaLista();
    lstnovaContrario = criaLista();
    for (p = lst; p != NULL; p = p->prox){{
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
    lst = lstInsere(lst, 23);
    lst = lstInsere(lst, 53);
    lst = lstInsere(lst, 23);
    lst = lstInsere(lst, 53);
    lst = lstInsere(lst, 5);
    lst = lstInsere(lst, 6);
    lst = lstInsere(lst, 45);
    lst = lstInsere(lst, 32);
    lst = lstInsere(lst, 68);
    lst = lstInsere(lst, 92);
    lstImprime(lst);
    printf("\n------------------------------------------------\n\n");
    Elemento *lstCopia;
    lstCopia = criaLista();
    lstCopia = copia(lst);
    lstImprime(lstCopia);
    return 0;
}
