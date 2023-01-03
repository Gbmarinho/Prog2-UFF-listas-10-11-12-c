#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *p;
  int i;
  char texto[81] = "teste", texto2[81] = "teste0", num[81], txt[5] = ".txt", recebe[100];
  char textoDentroArquivo[81] = "Texto do arquivo 0", textoDentroArquivo2[81] = "Texto do arquivo ", recebe2[100];
  int cont = 1;
  for(i=0;i<10;i++){
    if(cont>9){
        sprintf(num, "%d", cont);
        strcat(strcat(strcpy(recebe, texto), num),txt);
        p = fopen(recebe, "a");
        if(p==NULL){
            printf("ERRO");
            exit(1);
        }
        strcat(strcpy(recebe2, textoDentroArquivo2), num);
        fprintf(p, "%s", recebe2);
        fclose(p);
    }else{
        sprintf(num, "%d", cont);
        strcat(strcat(strcpy(recebe, texto2), num),txt);
        p = fopen(recebe, "a");
        if(p==NULL){
            printf("ERRO");
            exit(1);
        }
        strcat(strcpy(recebe2, textoDentroArquivo), num);
        fprintf(p, "%s", recebe2);
        fclose(p);
    }
    cont++;
  }
  return(0);
}


