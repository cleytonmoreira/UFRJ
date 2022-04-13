/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa de testes para usar a funcao CalcularMenorComplementar.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/01 07:57:01 $
 * $Log: aula0605.c,v $
 * Revision 1.2  2022/02/01 07:57:01  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/01 07:20:34  cleyton.moreira
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
	ush indiceLinhas, indiceColunas, indiceOrdem, indiceArgumentos, indicePosicao = 4;
	ush indice, contadorLinhas, contadorColunas;
	ush somaArgumentos;
	char *validacao;
	double matriz [100][100];
	double *menorComplementar, *determinante;
	double local;
	tipoErros resultado;
	
	/* Zerando a posicao que sera usado nas funcoes. */
	local = 0;
	determinante = &local;
	menorComplementar = &local;

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

	/* chamando a funcao CalcularMenorComplementar */

	resultado = CalcularMenorComplementar (indiceOrdem, indiceLinhas, indiceColunas, matriz, menorComplementar);

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


	/* Exibir o resultado do Menor Complementar */
	MostrarMatriz (indiceOrdem - 1, indiceOrdem - 1, matriz);
	
	resultado = CalcularDeterminanteMatriz (indiceOrdem - 1, matriz, determinante);

	printf ("Menor Complementar: %.5f\n\n\n", *determinante);

	return OK;
}
/* $RCSfile: aula0605.c,v $ */
