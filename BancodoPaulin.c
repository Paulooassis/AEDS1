#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct{
  char nome[60], cpf[20];
  int numconta;
  float saldo;
}cliente;

void menu(){
  for(int i =0; i<50; i++){
    printf("-");
  }
  printf("\n\n\t\tBEM VINDO AO BANCO DO PAULIN\n");

  for(int i=0; i<50; i++){
    printf("-");
  }
  printf("\n\n");
  printf("\t\tMENU DE OPCOES !!");
  printf("\n\n1. CRIAR CONTA\n2. EXIBIR CADASTRADOS\n3. DEPOSITAR\n4. SACAR\n5. EXIBIR SALDO\n6. SAIR DO PROGRAMA\n\nDigite a opcao desejada: ");
}

void cadastrarcliente(cliente cli[], int *total){

  printf("Digite o nome do cliente: ");
  scanf(" %[^\n]", cli[*total].nome);
  printf("Digite o seu cpf: ");
  scanf(" %[^\n]", cli[*total].cpf);
  printf("Digite o numero da conta: ");
  scanf("%d", &cli[*total].numconta);
  printf("Digite o valor na sua conta: ");
  scanf("%f", &cli[*total].saldo);

  (*total)++;
}

void exibircadastrados(cliente cli[], int *total){

  if(*total == 0){
    printf("\nNao existem clientes cadastrados.\n\n");
  }
  else{
    printf("Possui(em) %d pessoa(s) cadastradas.\n\n", *total);
    for(int i=0; i<*total; i++){
      printf("O nome e %s\n", cli[i].nome);
      printf("O cpf e %s\n", cli[i].cpf);
      printf("O numeo da conta e %d\n", cli[i].numconta);
      printf("O saldo e %.2f\n\n", cli[i].saldo);
    }
  }

}

void deposito(cliente cli[], int *total){
  int num;
  float valor;
  bool achou = false;

  printf("Digite o numero da conta que deseja fazer o deposito: ");
  scanf("%d", &num);
  printf("Digite o valor que deseja depositar: ");
  scanf("%f", &valor);

  for(int i=0; i<*total; i++){
    if(num == cli[i].numconta){
      cli[i].saldo += valor;
      achou = true;
    }
  }

  if(achou == false){
    printf("\nNumero da conta digitado nao foi encontrado.\n\n");
  }
}

void sacar(cliente cli[], int *total){
  int cnt;
  float valor;
  bool achou = false;

  printf("Digite a conta que sedeja sacar: ");
  scanf("%d", &cnt);

  printf("Digite o valor qe deseja sacar: ");
  scanf("%f", &valor);

  for(int i = 0; i<*total; i++){
    if(cnt == cli[i].numconta){
      achou = true;
      if(valor > cli[i].saldo){
        printf("\nNao e possivel realizar o saque, saldo indisponivel.\n\n");
      }
      else{
        cli[i].saldo-=valor;
      }
    }
  }

  if(achou == false){
    printf("\nNumero da conta digitado inválido.\n\n");
  }
}

void exibirsaldo(cliente cli[], int *total){
  int num;
  bool achou = false;

  printf("\nDigite o numer da conta que deseja saber o saldo: ");
  scanf("%d", &num);

  for(int i=0; i<*total; i++){
    if(num == cli[i].numconta){
      printf("O saldo da conta e %.2f\n", cli[i].saldo);
      achou = true;
    }
  }

  if(achou == false){
    printf("Nenhum cadastro encontrado com o numero digitado.\n\n");
  }
}

int main(void) {
  int opcao = 1, total=0;
  int *ptr = &total;

  cliente cli[*ptr];
  while(opcao != 6){

  menu();
  scanf("%d", &opcao);

  switch(opcao){
    case 1:
      cadastrarcliente(cli, ptr);
    break;
    case 2:
      exibircadastrados(cli, ptr);
    break;
    case 3:
      deposito(cli, ptr);
    break;
    case 4:
      sacar(cli, ptr);
    break;
    case 5:
      exibirsaldo(cli, ptr);
    break;
    case 6:
      printf("Programa encerrado com sucesso !!");
      return 0;
    break;
    default:
      printf("\nOpcao digitada invalida, selecione outra. \n\n");
    break;
  }
  }
}
