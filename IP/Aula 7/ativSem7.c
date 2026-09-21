#include <stdio.h>
#include <stdlib.h>

double* somaPolinomios(double* p, double* q, int n) {
    double* resultadoSoma = (double*) malloc(sizeof(*resultadoSoma) * n);

    for(int i = 0; i < n; i++){        
        resultadoSoma[i] = p[i] + q[i];
    }
    
    return resultadoSoma;
}

int main(){
  int i, j;
  double* p1, * p2, * r;
  int n = 5;
  p1 = (double*) malloc(sizeof(double)*n);
  p2 = (double*) malloc(sizeof(double)*n);
  p1[0] = 1;
  p1[1] = 0;
  p1[2] = 2;
  p1[3] = 0;
  p1[4] = 4;

  p2[0] = 3;
  p2[1] = 2;
  p2[2] = 3;
  p2[3] = -2;
  p2[4] = 3;

  r = somaPolinomios(p1,p2,n);
  for (i=0;i<n;i++){
    if (r[i]>=0) printf(" +");
    else printf(" ");
    printf("%.2f*x^%i", r[i], i);
  }
  printf("\n");

  free(p1);
  free(p2);
  free(r)

  return 0;
}

/* SAIDA: 
+4.00*x^0 +2.00*x^1 +5.00*x^2 -2.00*x^3 +7.00*x^4

Dados dois polinômios $p(x) = a_0 + a_1x + a_2x^2 + \dots + a_nx^n$ e $q(x) = b_0 + b_1x + b_2x^2 + \dots + b_mx^n$,
escreva uma função que retorne a soma destes polinômios na forma de um arranjo de elementos.Os três arranjos que
representarão os polinômios de entrada e de saída (retorno) deverão ser arranjos de elementos do tipo double, alocados
dinamicamente e representados por ponteiros para double, nos quais:A primeira posição (índice zero) contém o termo 
constante (que não multiplica $x$);A segunda posição contém o coeficiente de $x^1$;A terceira posição contém o 
coeficiente de $x^2$, e assim por diante.Assuma que os dois arranjos de entrada têm o mesmo tamanho, indicado pelo terceiro 
parâmetro da função, chamado de n (o arranjo de saída também deverá ter o mesmo tamanho).
*/
