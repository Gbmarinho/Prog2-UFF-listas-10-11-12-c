#include <stdio.h>
#include <stdlib.h>

struct funcionario {
    char nome[81]; /* nome do funcionário */
    float valor_hora; /* valor da hora de trabalho em Reais */
    int horas_mes; /* horas trabalhadas em um mês */
};
typedef struct funcionario Funcionario;

void carrega(int n,Funcionario *func, char *nome){
    FILE *p;
    int i;
    p = fopen(nome, "r");
    if(p == NULL){
        exit(1);
    }
    for(i=0;i<n;i++){
        fscanf(p," %80[^\n]", &func[i].nome);
        fflush(stdin);
        fscanf(p,"%f %d", &func[i].valor_hora, &func[i].horas_mes);
    }
    fclose(p);
}

int main(){
    int i;
    Funcionario func[3];
    carrega(3,func, "exercicio1.txt");
    for(i=0;i<3;i++){
        printf("%s %g %d\n", func[i].nome, func[i].valor_hora, func[i].horas_mes);
    }
    return 0;
}
