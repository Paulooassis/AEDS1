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

for(int i = 1; i <= n-1; i++){
    X = a + i*deltaX;
    f = 12 / sqrt(9- (X * X));
    soma += f*deltaX;
}

printf("A soma e %f", soma);
}