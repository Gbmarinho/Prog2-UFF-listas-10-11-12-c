#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


struct usuario{
    int num;    
    char nome[50];  
    char telefone[20];
    char email[20]; 
    char endere[20];
};

FILE *arquivo;

struct usuario C;

// Função que exibe o menu de opções
char menu(){

    system("cls");
    printf("\n- - - - - - - - AGENDA DE CONTATOS - - - - - - - -\n\n");

    printf("Opcoes:\n");
    printf("1 - Cadastrar contato.\n");
    printf("2 - Listar contatos cadastrados.\n");
    printf("3 - Procurar contato. \n");
    printf("4 - Editar contato.\n");
    printf("5 - Excluir contato.\n");
    printf("6 - Sair.\n\n");
    printf("Digite a opcao:");

    return (getche());
}

// Função de pesquisa pelo número de inscrição
int BuscaInsc(int n){
    fread(&C,sizeof(C),1,arquivo);

    while(!feof(arquivo)){      
        if(C.num == n){     
            fseek(arquivo,sizeof(C),SEEK_CUR);      
            return 1;       
        }       
    fread(&C,sizeof(C),1,arquivo);  
    }   
    return 0;
}

// Função de cadastro de usuário
void cadastrarUsuario(){    
    int i;  
    arquivo = fopen("agenda.txt","a+b");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\n\nDigite o codigo de inscricao: "); 
    scanf("%d",&C.num);

    if(C.num != 0){ 
        printf("\nDigite o nome: ");    
        fflush(stdin);  
        gets(C.nome);   
        printf("\nDigite o telefone: ");    
        fflush(stdin);  
        gets(C.telefone);
        printf("\nDigite o e-mail: ");  
        fflush(stdin);  
        gets(C.email);  
        printf("\nDigite o endereco: ");    
        fflush(stdin);  
        gets(C.endere); 
        fwrite(&C,sizeof(C),1,arquivo); 
        getchar();
    }

    else{
        printf("\nCodigo de inscricao ja cadastrado.\n");   
    }
    fclose(arquivo);

}

// Função que lista usuários cadastrados
void listarUsuario(){   
    int i=0;    
    arquivo = fopen("cliente.txt","rw");

    if(arquivo == NULL){    
        printf("\nErro ao abrir arquivo\n");    
        return; 
    }

    fread(&C,sizeof(C),1,arquivo);  
    printf("\n\n\nCadastros:\n\n\n");

    while(!feof(arquivo)){  
        i++;    
        printf("\n- - - - - - - - AGENDA - - - - - - - -"); 
        printf("\n____________________________________\n\n");   
        printf("Codigo de inscricao: %d\n Nome: %s\n Telefone: %s\n E-mail: %s\n Endereco: %s\n"    
        ,C.num,C.nome,C.telefone,C.email,C.endere);     
        printf("\n____________________________________\n\n");

        fread(&C,sizeof(C),1,arquivo);  

        if(feof(arquivo) || (i == 20)){
            break;  
            getchar();  
            getchar();  
        }
    }
    fclose(arquivo);

}

// Função que busca usuário pelo código
void buscarUsuario(){
    int insc;
    arquivo = fopen("agenda.txt","rw");

    if(arquivo == NULL){
        printf("\nErro ao abrir o arquivo\n");
    }

    printf("\n");
    printf("\n Digite o codigo de inscricao: ");
    scanf("%d",&insc);

    if(BuscaInsc(insc) == 0)
        printf("\nCodigo de Inscricao invalido!\n");
    else {
        fread(&C,sizeof(C),1,arquivo);
        printf("\n- - - - - - - - AGENDA - - - - - - - -\n");
        printf("\n____________________________________\n\n");
        printf("\nInscricao: %d\n",C.num);
        printf("Nome: %s\n",C.nome);
        printf("Telefone: %s\n",C.telefone);
        printf("E-mail: %s\n",C.email);
        printf("Endereco:%s\n",C.endere);
        printf("\n____________________________________\n\n");

        getchar();
        getchar();
    }

    fclose(arquivo);

}

// Função de edição de usuário
void editarUsuario()
{
    int insc;
    arquivo = fopen("agenda.txt","rw");
    if(arquivo == NULL){
        printf("\nErro ao abrir o arquivo\n");
    }
    printf("\n");
    printf("\n Digite o codigo de inscricao: ");
    scanf("%d",&insc);

    //BuscaInsc(insc);

    if(BuscaInsc(insc) == 0)
        printf("\nCodigo de inscricao invalido!\n");
    else
        arquivo = fopen("agenda.txt","wb");

    if(arquivo == NULL){
        printf("Erro ao abrir arquivo\n");
        return;
    }

    printf("\n\nInscricao: ");
    scanf("%d",&C.num);

    if(C.num !=0){
        printf("\nNome: ");
        fflush(stdin);
        gets(C.nome);
        printf("\nDigite o telefone: ");
        fflush(stdin);
        gets(C.telefone);
        printf("\nDigite o e-mail: ");
        fflush(stdin);
        gets(C.email);
        printf("\nDigite o endereco: ");
        fflush(stdin);
        gets(C.endere);
        printf("\nAlteracao realizada com sucesso!");
        fwrite(&C,sizeof(C),1,arquivo);
        getchar();
    }

    else
        printf("\nCodigo de inscricao ja cadastrado.\n");
    fclose(arquivo);

}


// Função de edição de usuário
void apagarUsuario()
{
    FILE* arquivo = fopen("agenda.txt", "rw");
    FILE* novoArquivo = fopen("temp.txt", "w");
    char nome[50];

    printf("Digite o nome do usuário a ser excluido: ");
    scanf("%s", nome);

    while(!feof(arquivo)){
        fread(&C, sizeof(C), 1, arquivo);
        if(strcmp(nome, C.nome)){
            fwrite(&C, sizeof(C), 1, novoArquivo);
        }
    }
    fclose(novoArquivo);
    fclose(arquivo);
    remove("agenda.txt");
    rename("temp.txt", "agenda.txt");


}


// Função principal
main(){
    char op;
    while(op!='6'){
        op = menu();
        switch(op){
            case '1':cadastrarUsuario();
            break;

            case '2':listarUsuario();
            break;

            case '3':buscarUsuario();
            break;

            case '4':editarUsuario();
            break;

            case '5':apagarUsuario();
            break;
        }
        printf("\n");
        system("pause");
    }

}