/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao funcao teste para a funcao ObterMatrizTransposta.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/24 14:04:43 $
 * $Log: aula0603.c,v $
 * Revision 1.1  2022/01/24 14:04:43  cleyton.moreira
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
	ush contadorIndice, contadorLinhas, contadorColunas, numeroDeArgumentos, indice = 3;
	ush linhas_1, colunas_1, linhas_2, colunas_2;
	char *validacao;
	ush valorArgumento;
	double matrizOriginal [100][100];
	double matrizTransposta [100][100];
	tipoErros resultado;
	
	
	/* Verificacao dos argumentos referentes ao numero de linhas e colunas. */
	for (contadorIndice = 1; contadorIndice < indice; contadorIndice++)
	{
		/* Verificacao de argumento contendo hifen */
		if (argv[contadorIndice][0] == '-')
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: argumento #%hu (%s).\n",contadorIndice, argv[contadorIndice]);
			printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}

		valorArgumento = strtoul (argv[contadorIndice], &validacao, 10);
		
		/* Verificacao de caractere invalido */
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: Argumento #%hu (%s)\n", contadorIndice, argv[contadorIndice]);
			printf ("caractere invalido: '%c'\n", *validacao);
			printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal>  <a11> <a12> ...\n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		
		/* Verificacao do tamanho dos argumentos */
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
	}

	numeroDeArgumentos = indice + (linhas_1 * colunas_1);

	/* Verificando a quantidade de argumentos passado para o programa. */
	if (argc != numeroDeArgumentos)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <numero-de-linhas> <numero-de-colunas>  <a11> <a12> ... <a%i%i> <a%i%i> \n\n", argv[0], 
				linhas_1, (colunas_1 - 1), linhas_1, colunas_1);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	/* Verificando o numero de linha das matriz. */
	if (linhas_1 > NUMERO_DE_LINHAS_MAX)
	{
		printf ("\n\n\nErro #%i: Numero de linhas acima do permitido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Numero maximo de linhas permitido: %i\n", NUMERO_DE_LINHAS_MAX);
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
	
	/* Verificando o numero de colunas das matrizes. */
	if (colunas_1 > NUMERO_DE_COLUNAS_MAX)
	{
		printf ("\n\n\nErro #%i: Numero de colunas acima do permitido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Numero maximo de colunas permitido: %i\n", NUMERO_DE_COLUNAS_MAX);
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
	
	/* Criando a matrizOriginal zerada. */	
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_1; contadorColunas++)
			matrizOriginal [contadorLinhas][contadorColunas] = 0;
	
	/* Preencher a matrizOriginal com os argumentos passado pela CLI. */
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_1; contadorColunas++)
		{
			matrizOriginal [contadorLinhas][contadorColunas] = strtod (argv[indice++], &validacao);
			if (*validacao != EOS)
			{
				printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: <a%u%u> = %s\n", (contadorLinhas + 1), (contadorColunas + 1), argv[indice - 1]);
				printf ("caractere invalido: '%c'\n", *validacao);
				printf ("Uso: %s <numero-inteiro-sem-sinal> <numero-inteiro-sem-sinal> <a11> <a12> ...\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("Valor ultrapassa o limite inferior ou superior do tipo double.\n\n");
				printf ("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
				exit (ARGUMENTO_INVALIDO);
			}
		}
	
	linhas_2 = colunas_1;
	colunas_2 = linhas_1;
	
	/* Criando a matrizTransposta zerada 
	for (contadorLinhas = 0; contadorLinhas < colunas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < linhas_1; contadorColunas++)
			matrizOriginal [contadorLinhas][contadorColunas] = 0;
	*/

	/* Usando a funcao ObterMatrizTransposta */ 
	resultado = ObterMatrizTransposta (linhas_1, colunas_1, matrizOriginal, matrizTransposta);
	

	matrizTransposta [linhas_2][colunas_2] = resultado;
	
	printf ("\n\n");
	/* Mostrar matriz Original */
	printf ("--- Matriz Original ---\n");
	MostrarMatriz (linhas_1, colunas_1, matrizOriginal);

	/* Mostrar matriz Transposta */
	printf ("--- Matriz Transposta ---\n");
	MostrarMatriz (linhas_2, colunas_2, matrizTransposta);
	
	return OK;
}
/* $RCSfile: aula0603.c,v $ */
