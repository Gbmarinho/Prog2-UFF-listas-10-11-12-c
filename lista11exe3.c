#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    int sala;
    char nome[81];
}Aluno;

typedef struct lista Lista;
struct lista{
    int matricula;
    int sala;
    char nome[81];
    Lista *prox;
};
Lista* lstCria(){
    return NULL;
}

Lista* lstIncluir (Lista* lst, int matricula, int sala, char nome[81]){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    novo->sala = sala;
    novo->prox = lst;
    return novo;
}
void lstImprime (Lista* lst){
    Lista* p;
    for (p = lst; p != NULL; p = p->prox){
        printf("matricula = %d\n", p->matricula);
        printf("sala = %d\n", p->sala);
        printf("nome = %s\n", p->nome);
        printf("\n");
    }
}

Lista* lstExcluir (Lista* lst, int matricula){
    Lista* ant = NULL;
    Lista* p = lst;
    while (p != NULL && p->matricula != matricula) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    return lst;
    if (ant == NULL){
    lst = p->prox;
    }
    else{
    ant->prox = p->prox;
    }
    free(p);
    return lst;
}

void lstAltera (Lista* lst, int novaMatricula, int novaSala, char novoNome[81], int matriculaParaAlterar){
    Lista* p;
    for (p=lst; p!=NULL; p = p->prox) {
        if (p->matricula == matriculaParaAlterar){
            strcpy(p->nome, novoNome);
            p->matricula = novaMatricula;
            p->sala = novaSala;
        }
    }
}

int main (){
    Lista* lst;
    FILE *p;
    int c = 0, cont = 0;

    int i, a, b;
    char nome[81];
    p = fopen("tentativa.txt", "r");
    if (p == NULL) {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    lst = lstCria();
    for(i=0;i<3;i++){
        fscanf(p, "%d %d %s", &a, &b, &nome);
        lst = lstIncluir(lst, a, b, nome);
        fflush(stdin);
    }
    lst = lstIncluir(lst, 5313, 3001, "Joelson");
    lst = lstIncluir(lst, 1354, 3005, "Marcos");
    lst = lstIncluir(lst, 1234, 3007, "Juan");
    lstImprime(lst);
    printf("\n--------------------------------------------------------\n");
    lst = lstExcluir(lst,4645);
    lst = lstExcluir(lst,1234);
    lstImprime(lst);
    printf("\n--------------------------------------------------------\n");
    lstAltera(lst, 5321, 1023, "Geovana", 5313);
    lstAltera(lst, 5212, 2354, "Maria", 1354);
    lstAltera(lst, 4231, 1321, "Jeova", 1023);
    lstImprime(lst);
    return 0;
}
