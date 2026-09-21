/*********************************************************************/
/**   ACH2001 - Introducao a Programacao                            **/
/**   EACH-USP - Primeiro Semestre de 2026                          **/
/**   <04> - <Prof. Luciano Digiampietri>                           **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   <Eduardo Nascimento Soares>                   <17992555>      **/
/**   <04>                                                          **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

#define MAX_TURMAS 18
#define DISCIPLINAS_NECESSARIAS 5
#define MAX_ALUNOS_CURSO 20
#define MAX_TURMAS_CURSO 25

#define SEGUNDA 1
#define TERCA 2
#define QUARTA 3
#define QUINTA 4
#define SEXTA 5

#define MANHA 1
#define TARDE 2
#define NOITE 3

typedef int bool;

/*
TURMA: tem por objetivo representar uma turma. E uma estrutura que possui sete campos: codigoDisciplina do tipo inteiro que corresponde ao codigo numerico da disciplina, nomeDisciplina do tipo ponteiro para caracteres que aponta para o nome da disciplina; totalVagas do tipo inteiro que contem o numero de vagas oferecidas na turma; numAlunos do tipo inteiro que contem o numero atual de alunos na turma; nusps do tipo ponteiro para inteiro que aponta para um arranjo que contem o numero USP de cada um dos alunos da turma; diaDaSemana do oferecimento da turma (de 1 a 5, correspondendo de segunda a sexta e periodo (de 1 a 3, correspondendo a manha, tarde ou noite).
*/
typedef struct{
	int codigoDisciplina;
	char* nomeDisciplina;
	int totalVagas;
	int* nusps;
	int numAlunos;
	int diaDaSemana;
	int periodo;
}TURMA;

/*
DESEMPENHO: tem por objetivo representar o desempenho de um aluno em uma turma.  Possui quatro campos: turma que e do tipo ponteiro para TURMA e aponta para a turma a que o desempenho se refere; nota do tipo inteiro que contem a nota do aluno na respectiva turma (de 0 [zero] a 100); frequencia do tipo inteiro que contem a frequencia do aluno na respectiva turma (de 0 [zero] a 100); e status do tipo char cujo valor sera 'M' para o aluno recem matriculado na turma e podera ter outros dois valores possiveis dependendo da nota e da frequencia do aluno ('A' para aprovado e 'R' para reprovado).
*/
typedef struct{
	TURMA* turma;
	int nota;
	int frequencia;
	char status;
} DESEMPENHO;


/*
ALUNO: tem por objetivo representar um aluno e seu historico escolar. Possui cinco campos: nome do tipo ponteiro para caracteres que aponta para o nome do aluno; nusp do tipo inteiro que representa o numero USP do aluno; historico do tipo arranjo de DESEMPENHO que corresponde ao historico escolar do aluno, com suas matriculas e desempenho nas turmas; turmasNoHistorico do tipo inteiro que indica em quantas turmas o aluno ja se matriculou; e status do tipo char cujo valor sera 'M' para o aluno que ainda nao conclui seu curso e podera ter outros dois valores possiveis dependendo de seu desempenho no conjunto de turmas ('F' para formado e 'J' para jubilado).
*/
typedef struct{
	char* nome;
	int nusp;
	DESEMPENHO historico[MAX_TURMAS];
	int turmasNoHistorico;
	char status;
} ALUNO;

/*
CURSO: tem por objetivo representar um curso que e composto por turmas e alunos. Possui quatro campos: alunos do tipo arranjo de ponteiros para ALUNOs; numAlunos do tipo inteiro que armazena a quantidade de alunos no curso; turma do tipo arranjo de ponteiros para TURMAs; e numTurmas do tipo inteiro que armazena a quantidade de turmas no curso.
*/
typedef struct{
	ALUNO* alunos[MAX_ALUNOS_CURSO];
	int numAlunos;
	TURMA* turmas[MAX_TURMAS_CURSO]; 
	int numTurmas;
} CURSO;


/******** FUNCOES PARA CRIAR ALUNOS, DESEMPENHOS, TURMAS OU CURSOS ********/

/* Funcao para a criacao de um novo ALUNO.
   A funcao preenche todos os valores de seus campos e retorna esse novo ALUNO.
*/
ALUNO novoAluno(char* nome, int nusp){
	ALUNO novo;
	novo.nome = nome;
	novo.nusp = nusp;
	novo.turmasNoHistorico = 0;
	novo.status = 'M';
	return novo;
}


/* Funcao para a criacao de uma nova turma.
   A funcao preenche os valores de seus campos e retorna essa nova turma.
*/
TURMA novaTurma(int codigoDisciplina, char* nomeDisciplina, int totalVagas, int diaDaSemana, int periodo){
	TURMA nova;
	nova.codigoDisciplina = codigoDisciplina;
	nova.nomeDisciplina = nomeDisciplina;
	nova.nusps = (int*)malloc(sizeof(int)*totalVagas);
	nova.totalVagas = totalVagas;
	nova.diaDaSemana = diaDaSemana;
	nova.periodo = periodo;	
	nova.numAlunos = 0;
	return nova;
}


/* Funcao para a criacao de um novo curso.
   A funcao preenche os valores de seus campos e retorna esse novo curso.
*/
CURSO novoCurso(){
	CURSO novo;
	novo.numAlunos = 0;
	novo.numTurmas = 0;
	return novo;
}


/* Funcao para a criacao de um novo desempenho.
   A funcao preenche os valores de seus campos e retorna esse novo desempenho.
*/
DESEMPENHO novoDesempenho(TURMA* turma){
	DESEMPENHO novo;
	novo.turma = turma;
	novo.nota = 0;
	novo.frequencia = 0;
	novo.status = 'M';
	return novo;
}




/******** FUNCOES QUE VOCE DEVERA IMPLEMENTAR/COMPLETAR *******************/


/*
Funcao para adicionar um aluno (ou mais especificamente uma referencia a um aluno) no arranjo de alunos do curso cuja referencia/endereco de memoria foi passado como parametro (curso). A funcao devera retornar false caso o valor do endereco do parametro aluno ou do parametro curso seja igual a NULL. Tambem devera retornar false caso o numero de alunos no curso ja seja igual a MAX_ALUNOS_CURSO ou se o aluno referenciado por aluno ja pertenca ao arranjo de alunos do curso (verifique isso com base no numero USP do aluno). Caso contrario, o endereco do aluno passado como parametro deve ser inserido no arranjo de alunos, na posicao numAlunos e este campo (apontado por curso) deve ser incrementado em 1 e a funcao deve retornar true.
*/
bool adicionarAlunoAoCurso(ALUNO* aluno, CURSO* curso){
	
	// Verifica se o parametro e valido
    if(aluno == NULL || curso == NULL) return false;

    // Verifica se o curso ja ta cheio
    if(curso->numAlunos == MAX_ALUNOS_CURSO) return false;

    // Verifica se o aluno ja ta cadastrado
    for(int i = 0; i < curso->numAlunos; i++){
        if(aluno->nusp == curso->alunos[i]->nusp) return false;
    }

    // Adciona Aluno no curso
    curso->alunos[curso->numAlunos] = aluno;
    curso->numAlunos++;

    return true;
}


/*
Funcao para adicionar uma turma (ou mais especificamente uma referencia a uma turma) no arranjo de turmas do curso cuja referencia/endereco de memoria foi passado como parametro (curso). A funcao devera retornar false caso o valor do parametro turma ou do parametro curso seja igual a NULL. Tambem devera retornar false caso o numero de turmas no curso ja seja igual a MAX_TURMAS_CURSO ou se a turma referenciado por turma ja pertenca ao arranjo de turmas do curso (verifique isso com base no endereco de memoria que consta na variavel turma, pois a mesma turma nao deve ser inserida duas vezes, mas e possivel haver duas turmas diferentes de uma mesma disciplina). Caso contrario, a turma passada como parametro deve ser inserida no arranjo de turmas, na posicao numTurmas e este campo (apontado por curso) deve ser incrementado em 1 e a funcao deve retornar true.
*/
bool adicionarTurmaAoCurso(TURMA* turma, CURSO* curso){

	// Verifica se o parametro e valido
    if(turma == NULL || curso == NULL) return false;

    // Verifica se a turma ja esta cheia
	if(curso->numTurmas == MAX_TURMAS_CURSO) return false;

    // Verifica se a turma ja existe no curso
	for(int i = 0; i < curso->numTurmas; i++){
		if(turma == curso->turmas[i]) return false;
	}

    // Adciona a Turma no Curso
	curso->turmas[curso->numTurmas] = turma;
	curso->numTurmas++;

	return true;
}


/*
Funcao para atualizar o desempenho do aluno em uma turma. Esta funcao devera retornar false caso o endereco recebido como parametro (aluno) tenha valor NULL ou se o parametro nota ou o parametro frequencia tenha valor menor do que zero ou maior do que 100. Adicionalmente, a funcao tambem devera retornar false se o aluno referenciado pelo parametro aluno nao possuir um DESEMPENHO em seu historico escolar (historico) para a disciplina com codigo igual ao valor do parametro codigoDisciplina e cujo status seja igual a 'M' (matriculado). Caso contrario, o respectivo DESEMPENHO dentro do historico escolar do aluno dever ser atualizado com a respectiva nota e frequencia (passadas como parametro) e o status do DESEMPENHO deve ser atualizado para 'A' em caso de aprovacao (nota maior ou igual a 50 e frequencia maior ou igual a 70) ou para 'R' (reprovado), caso contrario, e a funcao devera retornar true.
*/
bool cadastrarNota(ALUNO* aluno, int codigoDisciplina, int nota, int freq){

	// Verifica se os parametros sao validos
	if(aluno == NULL) return false;
	if(nota < 0 || nota > 100) return false;
	if(freq < 0 || freq > 100) return false;

	
	for (int i = 0; i < aluno->turmasNoHistorico; i++){
		// Verifica se o aluno esta corretamente cadastrado
		if(aluno->historico[i].turma->codigoDisciplina == codigoDisciplina && aluno->historico[i].status == 'M'){
			// Atualizando dados do aluno
			aluno->historico[i].frequencia = freq;
			aluno->historico[i].nota = nota;
			aluno->historico[i].status = (nota >= 50 && freq >= 70) ? 'A' : 'R';

			return true;
		}
	}
	
	return false;
}


/*
Funcao para atualizar o status do aluno em relacao a sua situacao geral no curso, isto e: Matriculado, Formado ou Jubilado. Caso o numero total de disciplinas nas quais o aluno foi aprovado seja maior ou igual a DISCIPLINAS_NECESSARIAS, entao o campo status deve ser atualizado para 'F'. Se, por outro lado, o numero maximo de turmas nas quais ele pode se matricular (MAX_TURMAS) menos o numero de disciplinas nas quais ele foi reprovado for menor do que o numero de disciplinas necessarias para se formar (DISCIPLINAS_NECESSARIAS) o campo status deve ser atualizado para 'J', pois nao sera mais possivel se formar. Por fim, caso nenhuma dessas situacoes ocorra, o status deve permanecer 'M' (matriculado).
*/
void atualizarStatusAluno(ALUNO* aluno) {

	// Verifica quantas disciplinas ele esta aprovado
	int numAprovado = 0;
	for(int i = 0; i < aluno->turmasNoHistorico; i++){
		if(aluno->historico[i].status == 'A'){
			numAprovado++;
		}
	}

	// Atualiza o status do aluno 
	if(numAprovado >= DISCIPLINAS_NECESSARIAS){
		aluno->status = 'F';
		return;
	}

	int numReprovado = numAprovado - aluno->turmasNoHistorico;
	if(MAX_TURMAS - numReprovado < DISCIPLINAS_NECESSARIAS){
		aluno->status = 'J';
		return;
	}

	aluno->status = 'M';

}


/*
Funcao para matricular um aluno em uma turma. A funcao devera retornar false caso o endereco aluno ou turma seja igual a NULL. Caso contrario, a funcao devera chamar a funcao atualizarStatusAluno, passando aluno como parametro, isto sera necessario para verificar o status atualizado do aluno.
A funcao tambem devera retornar false} se o numero de alunos na turma (numAlunos) referenciada por turma for igual ao numero total de vagas (totalVagas) dessa turma ou se o aluno atual tiver um status geral diferente de 'M' (ou seja, se ja tiver se formado ou jubilado) ou se o numero de turmas no historico do aluno (turmasNoHistorico) for igual a MAX_TURMAS. A funcao tambem devera retornar false caso o aluno ja estiver matriculado nessa turma (isto deve ser verificado na lista de numeros USP da respectiva turma) ou estiver matriculado em outra turma da mesma disciplina, ou matriculado em outra turma no mesmo dia da semana e periodo, ou ja tenha sido aprovado nessa disciplina (e necessario verificar se ele tem um DESEMPENHO em seu historico escolar nessa disciplina com status 'M' ou 'A', se isso ocorrer a funcao devera retornar false)\footnote{ Note que e possivel a um aluno se matricular em uma nova turma de uma disciplina na qual ele ja foi reprovado (desde que ja nao esteja matriculado ou ja tenha sido aprovado nessa disciplina). Caso contrario, um novo DESEMPENHO devera ser inserido (ja existe uma funcao implementada no codigo que cria e retorna um novo DESEMPENHO) no historico escolar do aluno (historico), na posicao turmasNoHistorico e o valor do campo turmasNoHistorico devera ser incrementado em um; o numero USP do aluno devera ser inserido no arranjo apontado por nusps da respectiva turma na posicao numAlunos e o campo numAlunos da turma deve ser incrementado em um; por fim, a funcao devera retornar true.
*/
bool matricularAlunoEmTurma(ALUNO* aluno, TURMA* turma){
	
	// Verifica se os parametros sao validos
	if(aluno == NULL || turma == NULL) return false;
	atualizarStatusAluno(aluno);

	// Verifica se o aluno esta devidamente cadastrado
	if(turma->numAlunos == turma->totalVagas) return false;
	if(aluno->status != 'M') return false;
	if(aluno->turmasNoHistorico >= MAX_TURMAS) return false;

	// Verificando a matricula do aluno
	for(int i = 0; i < turma->numAlunos; i++){
		if(aluno->nusp == turma->nusps[i]) return false;
	}
	
	for(int i = 0; i < aluno->turmasNoHistorico; i++){
		DESEMPENHO historico = aluno->historico[i];

		if(historico.turma->codigoDisciplina == turma->codigoDisciplina){
			if(historico.status == 'M' || historico.status == 'A') return false;
		}
		if(historico.status == 'M'){
			if(historico.turma->diaDaSemana == turma->diaDaSemana && historico.turma->periodo == turma->periodo) return false;
		}
	}

	// Matriculando o Aluno
	aluno->historico[aluno->turmasNoHistorico] = novoDesempenho(turma);
	aluno->turmasNoHistorico++;

	//Atualizando Turma
	turma->nusps[turma->numAlunos] = aluno->nusp;
	turma->numAlunos++;

	return true;
}



/*
Funcao para calcular a moda das notas de um aluno. A funcao deve retornar -1 caso o ponteiro para o aluno seja igual a NULL ou se o aluno ainda nao concluiu nenhuma turma de nenhuma disciplina. Caso contrario, a moda deve ser um valor inteiro de zero a 10 (ou seja, vocÃª deve considerar as notas atuais dos alunos [que valem de zero a cem] divididas por 10 (divisao inteira) para o calculo do valor mais frequente. Sempre que houver empate (duas ou mais notas ocorrendo o nÃºmero mÃ¡ximo de vezes) vocÃª deve considerar o valor mais alto como moda. A moda deve ser computada para todas as turmas que o aluno ja concluiu (isto eh, status igual a 'R' ou 'A').
*/
int retornarModaDasNotasDeAluno(ALUNO* aluno){

	// Verifica se o parametro e valido
	if(aluno == NULL) return -1;

	// Descobre a Moda
	bool concluiuUma = false;
	
	int cont[11] = {0};
	for(int i = 0; i < aluno->turmasNoHistorico; i++){
		char status = aluno->historico[i].status;
		if(status == 'A' || status == 'R'){
			int nota = aluno->historico[i].nota;
			cont[(int) (nota / 10)]++;
			concluiuUma = true;
		}
	}

	if(concluiuUma == false) return -1;

	int moda = -1;
	int maiorFreq = -1;
	for(int i = 0; i < 11; i++){
		if(cont[i] >= maiorFreq){
			maiorFreq = cont[i];
			moda = i;
		}
	}

	return moda;
}



/****** FUNCOES PARA EXIBIR DADOS DO CURSO, DAS TURMAS OU DOS ALUNOS ******/

/*
Funcao para imprimir informacoes detalhadas de um aluno.
*/

void imprimirDadosAluno(ALUNO* a1){
	if (!a1) return;
	printf("**************************************************************\n");
	printf("Imprimindo informacoes do aluno: %i - %s.\n", a1->nusp, a1->nome);
	printf("Status: %c\n", a1->status);
	int d;
	DESEMPENHO temp;
	printf("Turmas cursadas: %i\n", a1->turmasNoHistorico);
	for (d=0; d<a1->turmasNoHistorico; d++){
		temp = a1->historico[d];
		printf("\tDisciplina: %35s, Nota: %3i, Frequencia: %3i, Status: %c\n", temp.turma->nomeDisciplina, temp.nota, temp.frequencia, temp.status);
	}
	printf("Moda das notas (de zero a dez): %i\n", retornarModaDasNotasDeAluno(a1));
}


/*
Funcao para imprimir informacoes detalhadas de uma turma.
*/
void imprimirDadosTurma(TURMA* t1){
	if (!t1) return;
	printf("**************************************************************\n");
	printf("Imprimindo informacoes da turma: %i - %s.\n", t1->codigoDisciplina, t1->nomeDisciplina);
	int a;
	printf("A turma contem %i vagas e %i alunos (oferecimento - dia: %i, periodo: %i):\n", t1->totalVagas, t1->numAlunos, t1->diaDaSemana, t1->periodo);
	for (a=0; a < t1->numAlunos; a++){
		printf("\t%i\n",t1->nusps[a]);
	}
}


/*
Funcao para imprimir informacoes gerais sobre um curso.
*/
void imprimirDadosCurso(CURSO c1){
	printf("\n###################################################################################\n");
	printf("Imprimindo informacoes do curso.\n");
	printf("Ha %i alunos(s) neste curso.\n",c1.numAlunos);
	ALUNO* aluno;
	for (int a=0; a < c1.numAlunos; a++){
		aluno = c1.alunos[a];
		printf("Aluno: %s\tnusp: %i\n", aluno->nome, aluno->nusp);
	}
	printf("\n");
	TURMA* turma;
	printf("Ha %i turmas(s) neste curso.\n",c1.numTurmas);
	for (int t=0; t < c1.numTurmas; t++){
		turma = c1.turmas[t];
		printf("Turma: %35s, vagas: %i, matriculados: %i (oferecimento - dia: %i, periodo: %i)\n", turma->nomeDisciplina, turma->totalVagas, turma->numAlunos, turma->diaDaSemana, turma->periodo);
	//\n", turma->nomeDisciplina, turma->totalVagas, turma->numAlunos);
	}
	printf("###################################################################################\n");
}


/*
Funcao para imprimir informacoes detalhadas de todos os alunos de um curso.
*/
void imprimirDadosTodosAlunos(CURSO c1){
	printf("\n###################################################################################\n");
	printf("Imprimindo informacoes de todos os alunos do curso.\n");
	printf("Ha %i alunos(s) neste curso.\n",c1.numAlunos);
	for (int a=0; a < c1.numAlunos; a++){
		imprimirDadosAluno(c1.alunos[a]);
	}
	printf("###################################################################################\n");
}


/*
Funcao para imprimir informacoes detalhadas de todas as turmas de um curso.
*/
void imprimirDadosTodasTurmas(CURSO c1){
	printf("\n###################################################################################\n");
	printf("Imprimindo informacoes de todas as turmas do curso.\n");
	printf("Ha %i turma(s) neste curso.\n",c1.numTurmas);
	for (int t=0; t < c1.numTurmas; t++){
		imprimirDadosTurma(c1.turmas[t]);
	}
	printf("###################################################################################\n");
}



/*** FUNCAO MAIN QUE REALIZA ALGUNS TESTES SOBRE AS FUNCOES IMPLMENTADAS ***/

int main(){
	
	printf("ATENCAO: Nem todas as caracteristicas do enunciado sao testadas neste exemplo.\n");
	printf("         Cabe a cada aluno(a) testar cuidadosamente seu EP.\n\n");
	
	printf("*** Criando alunos *******************************************\n");
	ALUNO a1 = novoAluno("Aluno A\0", 22222);
	ALUNO a2 = novoAluno("Aluno B\0", 33333);
	ALUNO a3 = novoAluno("Aluno C\0", 44444);
	ALUNO a4 = novoAluno("Aluno D\0", 55555);
	ALUNO a5 = novoAluno("Aluno C\0", 44444);
	ALUNO a6 = novoAluno("Aluno E\0", 66666);

	printf("*** Criando turmas **************************************\n");
	TURMA t1 = novaTurma(2001, "Introducao a Programacao\0", 3, SEGUNDA, MANHA);
	TURMA t2 = novaTurma(2002, "Introducao a Analise de Algoritmos\0", 4, TERCA, NOITE);
	TURMA t3 = novaTurma(2023, "Algoritmos e Estruturas de Dados I\0", 5, SEXTA, NOITE);	
	TURMA t4 = novaTurma(2024, "Algoritmos e Estruturas de Dados II\0", 6, QUINTA, NOITE);
	TURMA t5 = novaTurma(2016, "Inteligencia Artificial\0", 7, TERCA, TARDE);
	TURMA t6 = novaTurma(2023, "Algoritmos e Estruturas de Dados I\0", 8, TERCA, NOITE);

	printf("*** Criando um curso *******************************************\n");
	CURSO meuCurso = novoCurso();

	
	imprimirDadosCurso(meuCurso);
	
	
	printf("*** Inserindo alunos no curso *******************************************\n");
	
	if (adicionarAlunoAoCurso(&a1, &meuCurso)) printf("1. OK\n");
	else printf("NOK\n");
	if (adicionarAlunoAoCurso(&a2, &meuCurso)) printf("2. OK\n");
	else printf("NOK\n");
	if (adicionarAlunoAoCurso(&a3, &meuCurso)) printf("3. OK\n");
	else printf("NOK\n");
	if (adicionarAlunoAoCurso(&a4, &meuCurso)) printf("4. OK\n");
	else printf("NOK\n");
	if (adicionarAlunoAoCurso(&a5, &meuCurso)) printf("NOK\n");
	else printf("5. OK\n");
	if (adicionarAlunoAoCurso(&a6, &meuCurso)) printf("6. OK\n");
	else printf("NOK\n");
	if (adicionarAlunoAoCurso(&a4, &meuCurso)) printf("NOK\n");
	else printf("7. OK\n");


	imprimirDadosCurso(meuCurso);
	
	printf("*** Inserindo turmas no curso *******************************************\n");
	

	
	if (adicionarTurmaAoCurso(&t1, &meuCurso)) printf("8. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t2, &meuCurso)) printf("9. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t3, &meuCurso)) printf("10. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t4, &meuCurso)) printf("11. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t5, &meuCurso)) printf("12. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t6, &meuCurso)) printf("13. OK\n");
	else printf("NOK\n");
	if (adicionarTurmaAoCurso(&t3, &meuCurso)) printf("NOK\n");
	else printf("14. OK\n");
	

	imprimirDadosCurso(meuCurso);
	imprimirDadosTodosAlunos(meuCurso);
	imprimirDadosTodasTurmas(meuCurso);

	printf("\n\n*** Matriculando alunos nas turmas **************************************\n");
	if (matricularAlunoEmTurma(&a1,&t1)) printf("15. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a1,&t2)) printf("16. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a1,&t6)) printf("NOK\n");
	else printf("17. OK\n");
	if (matricularAlunoEmTurma(&a1,&t2)) printf("NOK\n");
	else printf("18. OK\n");
	if (matricularAlunoEmTurma(&a2,&t1)) printf("19. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a2,&t2)) printf("20. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a3,&t1)) printf("21. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a1,&t3)) printf("22. OK\n");
	else printf("NOK\n");
	
	imprimirDadosCurso(meuCurso);
	imprimirDadosTodosAlunos(meuCurso);
	imprimirDadosTodasTurmas(meuCurso);
	

	printf("\n\n*** Cadastrando notas ***************************************************\n");
	
	
	if (cadastrarNota(&a1,t1.codigoDisciplina, 100, 90)) printf("23. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t2.codigoDisciplina, 70, 70)) printf("24. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t3.codigoDisciplina, 40, 75)) printf("25. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t2.codigoDisciplina, 80, 80)) printf("NOK\n");
	else printf("26. OK\n");
	if (cadastrarNota(&a1,t4.codigoDisciplina, 90, 90)) printf("NOK\n");
	else printf("27. OK\n");

	imprimirDadosAluno(&a1);

	printf("\n\n*** Matriculando alunos nas turmas (novamente) **************************\n");
	if (matricularAlunoEmTurma(&a1,&t3)) printf("NOK\n");
	else printf("28. OK\n");
	if (matricularAlunoEmTurma(&a1,&t4)) printf("29. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a1,&t5)) printf("30. OK\n");
	else printf("NOK\n");
	if (matricularAlunoEmTurma(&a1,&t6)) printf("31. OK\n");
	else printf("NOK\n");

	imprimirDadosAluno(&a1);

	printf("\n\n*** Cadastrando notas (novamente) ***************************************\n");
	if (cadastrarNota(&a1,t4.codigoDisciplina, 98, 90)) printf("32. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t5.codigoDisciplina, 75, 70)) printf("33. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t6.codigoDisciplina, 60, 100)) printf("34. OK\n");
	else printf("NOK\n");
	if (cadastrarNota(&a1,t3.codigoDisciplina, 80, 80)) printf("NOK\n");
	else printf("35. OK\n");
	if (cadastrarNota(&a1,t4.codigoDisciplina, 90, 90)) printf("NOK\n");
	else printf("36. OK\n");

	imprimirDadosAluno(&a1);

	imprimirDadosCurso(meuCurso);
	imprimirDadosTodosAlunos(meuCurso);
	imprimirDadosTodasTurmas(meuCurso);

	printf("\n\n*** Atualizando status **************************************************\n");
	atualizarStatusAluno(&a1);
	imprimirDadosAluno(&a1);
	imprimirDadosAluno(&a2);
	return 0;	
}
