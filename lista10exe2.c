#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compara (char* s1, char* s2){
    int i;
    int a = strlen(s1), b = strlen(s2);
    if(a>b || b>a){
        return 1;
    }
    for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++) {
        if (s1[i] != s2[i]){
            return 1;
        }
    }
    return 0;
}

float busca (char* arquivo, char* matricula){
    FILE *p;
    int i, j = 0;
    char verificaMatricula[81];
    float nota, notasaida = -1;
    p = fopen(arquivo, "r");
    if(p == NULL){
        printf("ERRO");
        exit(1);
    }else{
        for(i=0;i<3;i++){
            fscanf(p ,"%80[^' '] %f", &verificaMatricula, &nota);
            j = strcmp(verificaMatricula,matricula);
            fflush(stdin);
            if(j==0){
                notasaida = nota;
                return notasaida;
            }
        }
    }
    fclose(p);
    return notasaida;
}

int main(){
    char nomeArquivo[81] = "exercicio2.txt";
    float notaAluno;
    char matricula[81] = "9010087-2";
    notaAluno = busca(nomeArquivo, matricula);
    if(notaAluno < 0){
        printf("Matricula nao existente!");
    }else{
    printf("Nota do aluno: %g", notaAluno);}
    return 0;
}
