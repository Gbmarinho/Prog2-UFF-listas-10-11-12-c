#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int retornarIndex(char *lista){
        int i=0, j=0;
        for(i = 0; i<strlen(lista);++i){
            if(lista[i] == '/'&& lista[i+1] == '/' || lista[i] == '\n'){
                return i ;
            }else j = i;
        }return j;
}

int main(){
    char arquivo[100];
    printf("Digite o nome do arquivo(ex. arquivo.c): ");
    gets(arquivo);
    FILE * file;
    FILE * file2;
    file = fopen( arquivo , "r");
    file2 = fopen( "saida.c" , "w");
    char strr[999];

    while (fgets(strr, 999, file) != NULL)  {
        char *linha = (char*) malloc(strlen(strr)*sizeof(char));
        for(int i=0;i<strlen(strr);++i){
            linha[i] = strr[i];
        }
        int n = retornarIndex(linha);
         if(n != 0){
            char aux[strlen(strr)];
            strncpy(aux,strr,n);
            fprintf(file2,"%s\n",aux);
         } 
        free(linha);
    }
    fclose(file);
    fclose(file2);
    
   return 0;
}