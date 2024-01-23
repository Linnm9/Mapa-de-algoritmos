#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct cadastro {
    char cpf[50]; 
    char nome[100];
    int setor;
};

struct cadastro cliente[999];
int cont = 0;

void menu(){
    printf("Bem-vindo ao nosso sistema! Escolha uma das seguintes opções\n");
    printf("1 - Solicitar Atendimento\n");
    printf("2 - Listar Atendimentos Registrados\n");
    printf("3 - Listar Atendimento por Setor\n");
    printf("4 - Sair\n");
}

void setores(){
	printf("\n\n1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa Jurídica\n");
}

void cadastrar(){
    printf("Digite o seu nome: ");
    fgets(cliente[cont].nome, sizeof(cliente[0].nome), stdin);
    printf("Digite o seu cpf: ");
    fgets(cliente[cont].cpf, sizeof(cliente[0].cpf), stdin); 
    printf("\nDigite o setor pelo qual deseja ser atendido:");  
    setores();
   	scanf("%d", &cliente[cont].setor);
   	
    while(cliente[cont].setor < 1 || cliente[cont].setor > 4){
    	system("cls");
    	printf("Esse não é um setor válido!\n");
    	printf("Por favor, digite novamente o setor pelo qual você deseja ser atendido: ");
    	setores();
    	scanf("%d", &cliente[cont].setor);
	}
    cont++;
    system("cls");
}
    

void listar_atendimentos(){
    int i;
    for(i = 0; i < cont; i++){
        printf("Nome: %s", cliente[i].nome);
        printf("CPF: %s", cliente[i].cpf);
        printf("Tipo Atendimento - %d\n", cliente[i].setor);
        printf("===============================\n\n");
    }
    if(cont == 0){
        printf("Nenhum atendimento registrado ainda!\n");
    }
}

void filtrar_setor(){
    int setor, i, testa = 0;
    printf("Digite o setor que você deseja verificar: ");
    setores();
    scanf("%d", &setor); 
    
    while(setor < 1 || setor > 4){
    	system("cls");
    	printf("Esse não é um setor válido!");
    	setores();
    	printf("\nPor favor, digite novamente o setor que você deseja verificar: ");
    	scanf("%d", &setor);
	}

    for(i = 0; i < cont; i++){	
        if(cliente[i].setor == setor){
            printf("\nNome: %s", cliente[i].nome);
            printf("CPF: %s", cliente[i].cpf);
            printf("Tipo Atendimento - %d\n", cliente[i].setor);
            printf("===============================\n\n");
            testa = 1;
        } 
    }
    if(testa == 0){
    	printf("===============================\n");
        printf("Nenhum atendimento registrado nesse setor!\n");
	}
}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");
    int opc;

    do{
        menu();
        scanf("%d", &opc);
        system("cls");
        fflush(stdin);
        switch (opc){
            case 1: {
                cadastrar();
                break;
            }
            case 2: {
                listar_atendimentos();
                system("pause");
                system("cls");
                break;
            }
            case 3: {
                filtrar_setor();
                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("Saindo...\n");
                break;
            }
            default : {
                printf("Opção inválida! Por favor, tente novamente.\n");
                system("pause");

                system("cls");
                break;
            }
            
        }
        
    } while(opc != 4); 

    return 0;
}
