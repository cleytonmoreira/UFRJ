/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa de testes para usar a funcao CalculcarComplementoAlgebrico.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/01 07:55:15 $
 * $Log: aula0606.c,v $
 * Revision 1.1  2022/02/01 07:55:15  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 	1999
#define __LONG_LONG_SUPPORTED
#endif


/* Inclusado dos arquivos de cabecalho para este programa. */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <limits.h>

/* Inclusao do arquiv cabecalho personalizado para este programa */
#include "aula0601.h"

/* Macros do programa */
#define NUMERO_MINIMO_DE_ARGUMENTOS 				3

int
main (int argc, char *argv[])
{	
	ush indice, contadorLinhas, contadorColunas, indicePosicao = 4;
	ush indiceLinhas, indiceColunas, indiceOrdem, indiceArgumentos;
	ush somaArgumentos;
	char *validacao;
	double matriz [100][100];
	double *complementoAlgebrico;
	double local;
	tipoErros resultado;
	
	/* Zerando a posicao que sera usado nas funcoes. */
	local = 0;
	complementoAlgebrico= &local;

	if (argc < NUMERO_MINIMO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado pela CLI invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	/* Verificacao dos argumentos passado pela CLI. */
	for (indice = 1; indice < argc; indice++)
	{
		indiceArgumentos = strtoul (argv[indice], &validacao, 10);
		if (errno == EINVAL)
		{
			printf ("\n\n\nErro #%i: Argumento contem digito invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		if (errno == ERANGE)
		{
			printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido.\n", ARGUMENTO_INVALIDO);
			printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
			printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: '%c'.\n", *validacao);
			printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		if (indiceArgumentos > USHRT_MAX)
		{
			printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido.\n", ARGUMENTO_INVALIDO);
			printf ("Entrada excede o valor maximo permitido para \"unsigned short\" (%hu)\n",(unsigned short) USHRT_MAX);
			printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}

		/* Valor da ordem da matriz */
		if (indice == 1)
			indiceOrdem = (ush) indiceArgumentos;

		/* Linha da posicao do elemento */
		if (indice == 2)
			indiceLinhas = (ush) indiceArgumentos;

		/* Colunas da posicao do elemento */
		if (indice == 3)
			indiceColunas = (ush) indiceArgumentos;			
	}
	
	/* Soma dos argumentos passados pelo programa */
	somaArgumentos = (indiceOrdem * indiceOrdem) + 4;

	/* Verificando a quantidade de argumentos passado pela CLI. */
	if (argc != somaArgumentos)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado pela CLI invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	/* Criando a matriz zerada */ 
	for (contadorLinhas = 0; contadorLinhas < indiceOrdem; contadorLinhas++)
		for (contadorLinhas = 0; contadorLinhas < indiceOrdem; contadorLinhas++)
			matriz[indiceLinhas][indiceColunas] = 0;		
	

	/* Verificando digito a digito passado para o programa */
	for (contadorLinhas = 0; contadorLinhas < indiceOrdem; contadorLinhas++)
	{
		for (contadorColunas = 0; contadorColunas < indiceOrdem; contadorColunas++)
		{
			matriz[contadorLinhas][contadorColunas] = strtod (argv[indicePosicao], &validacao);
			indicePosicao++;

			if (*validacao != EOS)
			{
				printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: '%c'.\n", *validacao);
				printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido.\n", ARGUMENTO_INVALIDO);
				printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
				printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
		}
	}

	if (indiceOrdem < 2)
	{
		printf ("\n\n\nErro #%i: Ordem da matriz Invalida.\n", ERRO_DE_MANIPULACAO_DE_MATRIZES);
		exit (ERRO_DE_MANIPULACAO_DE_MATRIZES);
	}

	if ((indiceLinhas > (indiceOrdem -1)) || (indiceColunas > (indiceOrdem - 1)))
	{
		printf ("\n\n\nErro #%i: Numero de linhas ou colunas invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}


	/* chamando a funcao CalcularComplementoAlgebrico */

	resultado = CalcularComplementoAlgebrico (indiceOrdem, indiceLinhas, indiceColunas, matriz, complementoAlgebrico);

	if (resultado == argumentoNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
		exit (ARGUMENTO_NULO);
	}

	if (resultado != ok)
	{
		printf ("\n\n\nErro #%i: Funcao retornou erro.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <ordem-da-matriz> <linha-do-elemento> <coluna-do-elemento> <a11> <a12> ... \n", argv[0]);
		exit (ERRO_DE_MANIPULACAO_DE_MATRIZES);
	}


	/* Exibir a Matriz */
	MostrarMatriz (indiceOrdem - 1, indiceOrdem - 1, matriz);

	printf ("\n\nComplementoAlgebrico: %.5f\n\n\n", *complementoAlgebrico);

	return OK;
}
/* $RCSfile: aula0606.c,v $ */
