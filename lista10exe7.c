#include <stdio.h>
void bolha(int n, float* v);
int main(){
    int i, tam;
    float *numeross;
    FILE* numeros;
    numeros = fopen("numeros.txt", "r");
    if (numeros==NULL){
        return (1);
    }
    fscanf (numeros, "%d", &tam);
    numeross = (float*)malloc(tam*sizeof(float));
    for (i=0;i<tam;i++){
        fscanf(numeros, "%f", numeross[i]);
    }
    fclose(numeros);
    bolha(tam,numeross);
    FILE* numbin;
    numbin = fopen("numeros.bin", "wb");
    if (numbin==NULL){
        return (1);
    }
    fwrite(numeross,sizeof(float),tam,numbin);
    fclose(numbin);
}
void bolha (int n, float* v){
    int fim,i;
    for (fim=n-1; fim>0; fim--){
        for (i=0; i<fim; i++){
            if (v[i]>v[i+1]) {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }
    }
}

