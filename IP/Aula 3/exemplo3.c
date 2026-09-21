#include <math.h>
#include <stdio.h>

void areaCasa(){
    float lateral = 11;
    float cquarto = 7;
    float areaq;
    float areas;
    float areat;
    printf("Programa para calculo da Area da casa\n");
    areas = lateral*lateral;
    printf("A Area da sala: %f\n", areas);
    areaq = cquarto*(lateral/2);
    printf("A Area do quarto: %f\n", areaq);
    printf("A Area do banheiro: %f\n", areaq);
    areat = areas + 2*areaq;
    printf("A Area total: %f\n", areat);
}

double areaPiscina(double raio){
    return M_PI * pow(raio,2);
}

int main() {
    double areap;
    areaCasa();

    double raio = 2;
    areap = areaPiscina(raio);
    printf("A Area da piscina: %f\n", areap);
	return 0;
}
