/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao funcao teste para a funcao MultiplicarMatrizes.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/24 11:43:03 $
 * $Log: aula0602.c,v $
 * Revision 1.2  2022/01/24 11:43:03  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/23 07:54:58  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivo de cabecalho para este problema. */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <limits.h>

/* Inclusao do arquivo de cabecalho personalizado. */
#include "aula0601.h"

int
main (int argc, char *argv[])
{
	ush contadorIndice, contadorLinhas, contadorColunas, numeroDeArgumentos, indice = 5;
	ush linhas_1, linhas_2, colunas_1, colunas_2;
	char *validacao;
	ush valorArgumento;
	double matriz1 [100][100];
	double matriz2 [100][100];
	double matrizProduto [100][100];
	tipoErros resultado;

	for (contadorIndice = 1; contadorIndice < indice; contadorIndice++)
	{
		/*
		if (argv[contadorIndice][0] != '-')
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: argumento #%hu (%s).\n",contadorIndice, argv[contadorIndice]);
			printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ... <b11> <b12>...\n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}*/

		valorArgumento = strtoul (argv[contadorIndice], &validacao, 10);

		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: Argumento #%hu (%s)\n", contadorIndice, argv[contadorIndice]);
			printf ("caractere invalido: '%c'\n", *validacao);
			printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ... <b11> <b12>...\n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		
		if (valorArgumento > 100)
		{
			printf ("\n\n\nErro #%i: Valor ultrapassa o limite para o nomero de linhas ou colunas\n", ARGUMENTO_INVALIDO);
			printf ("Valor para o numero de linhas e colunas abaixo de 100.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		if (contadorIndice == 1)
			linhas_1 = (unsigned short) valorArgumento;
		if (contadorIndice == 2)
			colunas_1 = (unsigned short) valorArgumento;
		if (contadorIndice == 3)
			linhas_2 = (unsigned short) valorArgumento;
		if (contadorIndice == 4)
			colunas_2 = (unsigned short) valorArgumento;
	}

	numeroDeArgumentos = indice + (linhas_1 * colunas_1) + (linhas_2 * colunas_2);

	/* Verificando a quantidade de argumentos passado para o programa. */
	if (argc != numeroDeArgumentos)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <linha1> <coluna1> <linha2> <coluna2> <a11> <a12> ... <a%i%i> <a%i%i> <b11> <b12> ... <b%i%i> <b%i%i>\n\n", argv[0], linhas_1, (colunas_1 - 1), linhas_1, colunas_1, linhas_2, (colunas_2 - 1), linhas_2, colunas_2);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	/* Comparacao do numero de colunas da matriz1 com o numero de linhas da matriz2. */
	if (colunas_1 != linhas_2)
	{
		printf ("\n\n\nErro #%i: Multiplicacao de matrizes errado.\n", ERRO_DE_MANIPULACAO_DE_MATRIZES);
		printf ("Valor para o numero de colunas da matriz1 tem que ser igual ao numero de linhas da matriz2.\n\n");
		printf ("Numero de Colunas da matriz1 = %i != Numero de Linhas da matriz2 = %i.\n\n", colunas_1, linhas_2);
		exit (ERRO_DE_MANIPULACAO_DE_MATRIZES);
	}
	/* Verificando o numero de linhas das matrizes. */
	if ((linhas_1 > NUMERO_DE_LINHAS_MAX) || (linhas_2 > NUMERO_DE_LINHAS_MAX))
	{
		printf ("\n\n\nErro #%i: Numero de linhas acima do permitido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Numero maximo de linhas permitido: %i\n", NUMERO_DE_LINHAS_MAX);
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
	
	/* Verificando o numero de colunas das matrizes. */
	if ((colunas_1 > NUMERO_DE_COLUNAS_MAX) || (colunas_2 > NUMERO_DE_COLUNAS_MAX))
	{
		printf ("\n\n\nErro #%i: Numero de colunas acima do permitido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Numero maximo de colunas permitido: %i\n", NUMERO_DE_COLUNAS_MAX);
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
	
	/* Criando a matriz1 zerada. */	
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_1; contadorColunas++)
			matriz1 [contadorLinhas][contadorColunas] = 0;
	
	/* Preencher a matriz1 com os argumentos passado pela CLI. */
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_1; contadorColunas++)
		{
			matriz1 [contadorLinhas][contadorColunas] = strtod (argv[indice++], &validacao);
			if (*validacao != EOS)
			{
				printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: <a%u%u> = %s\n", (contadorLinhas + 1), (contadorColunas + 1), argv[indice - 1]);
				printf ("caractere invalido: '%c'\n", *validacao);
				printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ... <b11> <b12>...\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("Valor ultrapassa o limite inferior ou superior do tipo double.\n\n");
				printf ("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
				exit (ARGUMENTO_INVALIDO);
			}
		}

	
	/* Criando a matriz2 zerada. */	
	for (contadorLinhas = 0; contadorLinhas < linhas_2; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_2; contadorColunas++)
			matriz2 [contadorLinhas][contadorColunas] = 0;
	
	/* Preencher a matriz2 com os argumentos passado pela CLI. */
	for (contadorLinhas = 0; contadorLinhas < linhas_2; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_2; contadorColunas++)
		{
			matriz2 [contadorLinhas][contadorColunas] = strtod (argv[indice++], &validacao);
			if (*validacao != EOS)
			{
				printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: <a%u%u> = %s\n", (contadorLinhas + 1), (contadorColunas + 1), argv[indice - 1]);
				printf ("caractere invalido: '%c'\n", *validacao);
				printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ... <b11> <b12>...\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("Valor ultrapassa o limite inferior ou superior do tipo double.\n\n");
				printf ("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
				exit (ARGUMENTO_INVALIDO);
			}
		}

	/* Criando a matrizProduto zerada. */	
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_2; contadorColunas++)
			matrizProduto [contadorLinhas][contadorColunas] = 0;
	

	resultado = MultiplicarMatrizes(linhas_1, colunas_1, linhas_2, colunas_2, matriz1, matriz2, matrizProduto);

	matrizProduto [linhas_1][colunas_2] = resultado;

	/* Mostrar matriz 1 */
	printf ("--- Matriz 1 ---\n");
	MostrarMatriz (linhas_1, colunas_1, matriz1);

	/* Mostrar matriz 2 */
	printf ("--- Matriz 2 ---\n");
	MostrarMatriz (linhas_2, colunas_2, matriz2);
	
	/* Mostrar matriz Produto */
	printf ("--- Matriz Produto ---\n");
	MostrarMatriz (linhas_1, colunas_2, matrizProduto);

	return OK;
}
/* $RCSfile: aula0602.c,v $ */
