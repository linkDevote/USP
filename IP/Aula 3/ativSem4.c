

#include <stdio.h>

double areaTrapezio(double baseMaior, double baseMenor, double altura){
    double area = 0;

    area = ((baseMaior + baseMenor) * altura/2);
	
    return area;
}

double areaRetangulo(double base, double altura){
   double area = areaTrapezio(base,base,altura);
   printf("Area do retangulo: %f\n", area);
   return area;
}

double areaQuadrado(double lado){
    double area = 0;

    area = lado * lado;
	
    return area;
}

int main(){
    printf("%f\n",areaTrapezio(3,2,1));
    areaRetangulo(11,27);
    printf("%f\n",areaQuadrado(5));
    return 0;
}

/*
Exercício 1: Criar uma função chamada areaTrapezio que receba três números reais (baseMaior, baseMenor e altura) e retorne o cálculo da área de um trapézio.

Exercício 2: Analisar o comportamento da função areaRetangulo (que reutiliza a lógica do trapézio). Se os parâmetros de entrada forem 11 e 27, a função calculará 11×27 e imprimirá: Area do retangulo: 297.000000.

Exercício 3: Criar uma função chamada areaDoQuadrado que receba apenas o lado. O requisito obrigatório é que ela chame a função areaRetangulo para realizar o cálculo, demonstrando o conceito de funções que invocam outras funções.
*/