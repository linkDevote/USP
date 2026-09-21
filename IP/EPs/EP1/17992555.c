/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2026                          **/
/**   Prof. Luciano Digiampietri                                    **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Eduardo Nascimento Soares>                   <17992555>      **/
/**   <04>                                                          **/
/*********************************************************************/


#include <stdio.h>

#define true 1
#define false 0

#define PEDRA 0
#define PAPEL 1
#define TESOURA 2

typedef int bool;


/*
Funcao usada em testes da correcao automatica
   NAO APAGAR OU MODIFICAR 
*/
void print123(){
}


/* Funcao que retorna o fatorial de n, caso n seja maior ou igual que zero ou
   -1 caso contario. */
double fatorial(int n){
	double res = 0;
	double fatResult = n;

	//Casos base tratados
	if(n < 0) return -1;
	if(n == 0) return 1;

	for(int i = n; i != 1; i--){
		fatResult *= (i-1);
	}

	res = fatResult;
	return res;
}


/* Funcao que retorna -1 caso os parametros base e exp sejam iguais a zero ou 
  caso o expoente seja menor que zero. Caso contrario, retorna o valor de 
  base elevada ao expoente (exp).
*/
long potencia(int base, int exp){
	long res = 0;
	long initBase = base;

	//Casos base tratados
	if(base == 0 && exp == 0) return -1;
	if(exp < 0) return -1;
	if(exp == 0) return 1;

	for(int i = 1; i < exp; i++){
		base *= initBase;
	}

	res = base;

	return res;
}


/* Funcao que calcular o numero aproximado de Euler por meio da 
   soma de k termos. */
double aproximarEuler(int k) {
	double e = 0.0;

	//Caso base tratado
	if (k < 1) return -1;

	for (int i = 0; i <= (k-1); i++){
		e += 1/fatorial(i);
	}

	return e;
}


/* Funcao que verifica a vitoria em uma rodade de Pedra, Papel e Tesoura.
   Em caso de empate retorna 0, se o jogador 1 ganhar retorna 1 e se o 
   jogador 2 ganhar retorna 2. */
int verificarVitoriaRodada(int j1, int j2) {
	int res = -1;

	//Casos Pedra
	if(j1 == PEDRA && j2 == PEDRA) res = 0;
	if(j1 == PEDRA && j2 == TESOURA) res = 1;
	if(j1 == PEDRA && j2 == PAPEL) res = 2;

	//Casos Tesoura
	if(j1 == TESOURA && j2 == TESOURA) res = 0;
	if(j1 == TESOURA && j2 == PAPEL) res = 1;
	if(j1 == TESOURA && j2 == PEDRA) res = 2;

	//Casos Papel
	if(j1 == PAPEL && j2 == PAPEL) res = 0;
	if(j1 == PAPEL && j2 == PEDRA) res = 1;
	if(j1 == PAPEL && j2 == TESOURA) res = 2;

	return res;
}


/* Funcao que verifica o ganhador de uma sequencia de 'melhor de tres'
   rodadas de Pedra, Papel e Tesoura. Em caso de empate retorna 0, se o
   jogador 1 ganhar retorna 1, se o jogador 2 ganhar retorna 2. */
int melhorDeTres(int j1_r1, int j2_r1, int j1_r2, int j2_r2, int j1_r3, int j2_r3) {
	int res = -1;

	int j1Count, j2Count = 0;

	//Casos do Round 1
	if((j1_r1 == PEDRA && j2_r1 == TESOURA) || (j1_r1 == TESOURA && j2_r1 == PAPEL) || (j1_r1 == PAPEL && j2_r1 == PEDRA));
	else if(j1_r1 != j2_r1) j2Count++;

	//Casos do Round 2
	if((j1_r1 == PEDRA && j2_r1 == TESOURA) || (j1_r2 == TESOURA && j2_r2 == PAPEL) || (j1_r3 == PAPEL && j2_r3 == PEDRA));
	else if(j1_r2 != j2_r2) j2Count++;

	//Casos Round 3
	if((j1_r1 == PEDRA && j2_r1 == TESOURA) || (j1_r2 == TESOURA && j2_r2 == PAPEL) || (j1_r3 == PAPEL && j2_r3 == PEDRA));
	else if(j1_r3 != j2_r3) j2Count++;

	//Resposta
	if(j1Count == j2Count) res = 0;
	res = j1Count > j2Count ? 1 : 2;

	return res;
}


/* Funcao que verifica se o numero passado como parametro eh narcisista. */
bool ehNarcisista(int n) {
	int res = -1;

	int initN = n; //Primeiro valor de n
	int exp = 0;
	int lastAlg = 0; //Pega sempre o ultimo algarismo
	int finalN = 0; //Valor final apos o algoritmo

	while(n != 0){
		n = n / 10;
		exp++;
	}

	n = initN;

	for(int i = 0; i < exp; i++){
		lastAlg = n % 10;
		n = n / 10;
		finalN += potencia(lastAlg, exp);
	}

	if(finalN == initN){
		res = true;
	}else{
		res = false;
	}

	return res;
}

/*
	Funcao main criada apenas para seus testes.
	Voce pode adicionar novos testes se quiser.
	ESTA FUNCAO SERA IGNORADA NA CORRECAO
*/
void main() {
	int x;

	printf("########### Fatorial ###########\n");
	for (x=-1;x<=20;x++){
		printf("O fatorial de %2i eh %20.0f\n", x, fatorial(x));
	}

	printf("\n########### Potencia ###########\n");
	for (x=-3;x<=20;x++){
		printf("3 elevado a %2i eh %15li\n", x, potencia(3,x));
	}


	printf("\n########### Euler ###########\n");
	for (x=-1;x<=10;x++){
		printf("A aproximacao do numero de Euler com %2i termo(s) eh: %.20f\n", x, aproximarEuler(x));
	}

	printf("\n########### Pedra, Papel e Tesoura ###########\n");
	printf("Pedra vence Papel?\t%s\n", verificarVitoriaRodada(PEDRA, PAPEL) == 1 ? "Sim!" : "Nao.");
	printf("Pedra vence Pedra?\t%s\n", verificarVitoriaRodada(PEDRA, PEDRA) == 1 ? "Sim!" : "Nao.");
	printf("Pedra vence Tesoura?\t%s\n", verificarVitoriaRodada(PEDRA, TESOURA) == 1 ? "Sim!" : "Nao.");
	printf("Tesoura vence Papel?\t%s\n", verificarVitoriaRodada(TESOURA, PAPEL) == 1 ? "Sim!" : "Nao.");

	printf("\n");
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PEDRA, PEDRA, TESOURA, TESOURA, PAPEL, TESOURA));	
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PAPEL, TESOURA, TESOURA, TESOURA, PEDRA, TESOURA));
	printf("Quem ganhou a melhor de tres foi: %i\n", melhorDeTres(PEDRA, TESOURA, PAPEL, PEDRA, TESOURA, PAPEL));

	printf("\n########### Numeros Narcisistas ###########\n");
	// printf("153 eh narcisista? %i", ehNarcisista(153));
	for (x=1;x<1000;x++){
		if (ehNarcisista(x)) printf("O numero %4i eh narcisista!\n", x);
	}

}
