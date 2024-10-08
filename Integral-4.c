#include <stdio.h>
#include <math.h>

int main(){

float a, b, n;
double deltaX, soma = 0, X, f;

printf("Digite o valor de a: ");
scanf("%f", &a);

printf("Digite o valor de b: ");
scanf("%f", &b);

printf("Digite o valor de n: ");
scanf("%f", &n);

deltaX = (b-a)/n;

for(int i = 1; i <= n; i++){
    X = a + i*deltaX;
    f = 4 * 3.14 * X * sqrt(-(X*X)+(8*X)-12);
    soma += f*deltaX;
}

printf("A soma e %f", soma);
}
