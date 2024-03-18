#include <stdio.h>

void menu() {
  printf("Qual a forma de pagamento ?\n\n1. A vista\n2. Parcelado 2x\n3. "
         "Parcelado de 3x a 10x\n\nDigite o opcao "
         "desejada: ");
}

void avista(float total) {
  printf("\nMuito bem, voce selecionou o pagamento a vista !!\n\n");
  printf("O preco do produto sera %.2f\n\n", total * 0.9);
}

void parcelado2(float total) {
  printf("\nMuito bem, voce selecionou o pagamento parcelado em 2x !!\n\n");
  printf("O preco do produto e %.2f, e o valor das parcelas e %.2f\n\n", total,
         total / 2);
}

void parcelado3(float total) {
  int parcelas;
  printf(
      "\nMuito bem, voce selecionou o pagamento parcelado em 3x ou mais !!\n\n");
  printf("Digite a quantidade de parcelas: ");
  scanf("%d", &parcelas);
  printf("O preco do produto e %.2f, e o valor das parcelas e %.2f e o total a "
         "ser pago e %.2f\n\n",
         total, ((parcelas * 0.03 +1) * total)/parcelas, (parcelas * 0.03 + 1) * total);
}

int main() {
  float total;
  int opcao = 1;

  while (total != -999) {
    for (int i = 0; i < 50; i++) {
      printf("-");
    }
    printf("\n");
    printf("\t\tBem Vindo a loja do Paulin !!\n");
    for (int i = 0; i < 50; i++) {
      printf("-");
    }
    printf("\n\n");

    printf("Digite o valor gasto na loja de roupas: ");
    scanf("%f", &total);

    if(total == -999){
      return 0;
    }

    menu();
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      avista(total);
      break;
    case 2:
      parcelado2(total);
      break;
    case 3:
      if (total < 300) {
        printf(
            "Escolha uma nova forma de pagamento, pois o valor e muito baixo.");
      } else {
        parcelado3(total);
      }
      break;
    default:
      printf("\nOpcao invalida, digite outro opcao\n\n");
      break;
    }
  }
}
