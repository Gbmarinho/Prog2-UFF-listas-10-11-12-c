#include <stdio.h>
#include <stdlib.h>

float med(char *nomeArquivo){
    FILE *p,*h;
    float media, soma = 0, cont = 0, pegador, *vetor;
    int i, verifica;
    p = fopen(nomeArquivo, "r");
    if (p == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    for(i=0;i<40;i++){
        verifica = fscanf(p,"%f", &pegador);
        if(verifica == -1){
            break;
        }
        cont = cont + 1;
        fflush(stdin);
    }
    fclose(p);
    h = fopen(nomeArquivo, "r");
    if (h == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    vetor = (float*) malloc(cont*sizeof(float));
    for(i=0;i<cont;i++){
        fscanf(p,"%f", &pegador);
        vetor[i] = pegador;
        fflush(stdin);
    }
    for(i=0;i<cont;i++){
        soma = soma + vetor[i];
    }
    fclose(h);
    media = soma/cont;
    return media;
}

int main(){
    char nomeArquivo[81];
    FILE* p;
    float media;
    printf("Digite o nome do arquivo: ");
    scanf(" %80[^\n]", &nomeArquivo);
    media = med(nomeArquivo);
    printf("A media eh: %g", media);
    return 0;
}

