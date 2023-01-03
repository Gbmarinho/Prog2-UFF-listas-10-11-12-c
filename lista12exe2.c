#include <stdio.h>
#include <stdlib.h>


float somaNumImpares(int vet[], int tam, int soma){
    if(tam == 0)
        return soma;
    else{
        if(vet[tam - 1] % 2 == 1)
            return somaNumImpares(vet, tam - 1, soma + vet[tam - 1]);
        else
            return somaNumImpares(vet, tam - 1, soma);
    }
}

int main(){
    int vet[6] = {2,3,38,7,11,9};
    printf("A soma dos numeros impares: %f\n", somaNumImpares(vet, 6, 0));
    return 0;
}
