#include <stdio.h>

void calculoDoValorDePi(int iteracoes){
    double meuPI = 4; // valor inicial de pi ("primeira iteracao")
    int sinal = -1;
    double divisor = 3;

    for (int i = 2; i <= iteracoes; i++){
      meuPI += sinal * 4.0/divisor; // atualiza o valor de pi
      divisor += 2; // incrementa o valor do divisor
      sinal *= -1; // inverte o sinal da variavel sinal
    }
    
    printf("(%i) pi: %f\n", iteracoes, meuPI);
}

int main() {
    for (int i = 0; i <= 1000; i++){
        calculoDoValorDePi(i);
    }
    return 0;
}
  

/*
Existem diversas funções computacionais para calcular valores aproximados de diferentes constantes ou funções. A função a seguir computa uma aproximação para o valor de π. Escreva o que será impresso ao se executar a seguinte função com os parâmetros: 1, 2, 3, 4, 5, 10 e 1000.

Resp:

1 -> 4.000000
2 -> 2.666667
3 -> 3.466667
4 -> 2.895238
5 -> 3.339683
10 -> 3.041840
1000 -> 3.140593
*/