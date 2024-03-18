#include <stdio.h>

void area(){

float raio;

printf("Digite o raio: ");
scanf("%f", &raio);

printf("O valor da area e %.2f\nO valor do perimetro e %.2f", 3.14*raio*raio, 2*3.14*raio);
}

int main(){
area();
}
