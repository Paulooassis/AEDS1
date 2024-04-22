#include <stdio.h>

int main(){
  int anos, qnt, total;
  float preco;

  printf("Digite a quantos anos voce fuma: ");
  scanf("%d", &anos);
  printf("Digite quantos cigarros vc fuma por dia: ");
  scanf("%d", &qnt);
  printf("Digite o preco medio do maco de cigarro: ");
  scanf("%f", &preco);

  total = (anos*365)*qnt;

  printf("Foram fumados %d cigarros e o valor gasto e %.2f", total, total/20 * preco);
}
