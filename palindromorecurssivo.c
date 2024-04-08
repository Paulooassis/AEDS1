#include <stdio.h>
#include <string.h>

int palindromo(char str[], int left, int right){
  if(left >= right){
    return 1;
  }
  if(str[left] != str[right]){
    return 0;
  }

  return palindromo(str, left + 1, right - 1);
}

int main(void) {
  int pad, tam;
  char str[40];

  printf("Digite uma frase: ");
  scanf(" %[^\n]", str);

  tam = strlen(str);

  pad = palindromo(str, 0, tam-1);

  if(pad == 1){
    printf("A palavra %s e palindromo.\n", str);
  }
  else{
    printf("A palavra nao e uma palindromo.\n");
  }
  return 0;
}
