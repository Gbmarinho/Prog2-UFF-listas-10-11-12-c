#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float media (char* mat, char* nome_arquivo);
main(){
    float result;
    result = media("8820324-3", "alunos.txt");
    printf("%.1f", result);

}
float media(char* mat, char* nome_arquivo){
    FILE *file;
    int i, j, c;
    float n1, n2, n3, media;
    char a[9], b[9];
    strcpy(b, mat);

    file = fopen(nome_arquivo, "r");
    if(file == NULL){
        printf("ERRO");
        exit(1);
    }
    while(!feof(file)){
        fscanf(file, "%s %f %f %f", &a, &n1, &n2, &n3);
        fflush(stdin);
        c = strcmp(b, a);
        if(c==1){
            media = (n1+n2+n3) / 3;
            return media;
        }
        else{
            c = 0;
        }

    }
}
