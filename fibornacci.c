#include <stdio.h>

int fibor(int num1){
  if(num1 <= 1){
    return num1;
  }
  if(num1 > 1){
    return fibor(num1-1) + fibor(num1-2);
  }
}


int main(void) {
  int num;
  
  printf("Digite quantos termos vai ter a sua sequência: ");
  scanf("%d", &num);

  fibor(num);
  printf("A sequência de %d termos é ", num);

  for(int i=0; i< num; i++){
    printf("%d ", fibor(i));
  }
  return 0;
}
