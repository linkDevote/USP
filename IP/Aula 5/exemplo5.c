/*
	Programa para calcular a Ã¡rea de uma casa com piscina, conforme
	projeto especÃ­fico.
	Uso de diferentes materiais com o faÃ§o FOR.
*/
#include <stdio.h>
#include <math.h>
#define false 0
#define true 1

#define ALVENARIA 0
#define VINIL 1
#define FIBRA 2
#define PLASTICO 3
typedef int bool;

int valorM2 = 1500;

double valorPiscina(double area, int material) {
  switch (material) {
    case ALVENARIA: return area*1500;
    case VINIL: return area*1100;
    case FIBRA: return area*750;
    case PLASTICO: return area*500;
    default: return -1;    
  }
}

void areaCasa(float lateral, float cquarto){
   float areaq;
   float areas;
   float areat;
   if (!(lateral>=0 && cquarto>=0))
      printf("Erro: parÃ¢metro < 0\\n");
   else {
      printf("Programa para cÃ¡lculo da Ã¡rea da casa\n");
      areas = lateral*lateral;
      printf("A Ã¡rea da sala Ã© %f\n", areas);
      areaq = cquarto*(lateral/2);
      printf("A Ã¡rea do quarto Ã© %f\n", areaq);
      printf("A Ã¡rea do banheiro Ã© %f\n", areaq);
      areat = areas + 2*areaq;
      printf("A Ã¡rea total Ã© %f\n", areat);
   }
}

double areaPiscina(double raio){
   return((raio >= 0) ? M_PI*raio*raio : -1);
}

double valor(double area) {
   if (area >= 0) {
      return valorM2*area;
   }
   return -1;
}

int main() {
   double area = 100;
   printf("Material\tValor\n");
   int tipo;
   for(tipo = ALVENARIA; tipo <= PLASTICO; tipo = tipo+1) {
      printf("%8i\t%9.2f\n", tipo, valorPiscina(area,tipo));
   }
   return 0;
}