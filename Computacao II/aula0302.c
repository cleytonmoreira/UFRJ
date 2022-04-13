/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implemetacao do programa de teste para a funcao CalcularMaximoDivisorComum.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/20 02:44:30 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2021/12/20 02:44:30  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE		2011
#define __LONG_LONG_SUPPORTED
#endif

/* Includes para este programa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include "aula0301.h"

/* Macros para este programa */

#define OK						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO			1
#define ARGUMENTO_NEGATIVO				2
#define BASE_INVALIDA					3
#define VALOR_MAXIMO_EXCEDIDO				4
#define ARGUMENTO_INVALIDO				5
#define VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO	6

#define NUMERO_DE_ARGUMENTOS				3
#define EOS						'\0'


int
main (int argc, char *argv[])
{
	ull primeiroArgumento, segundoArgumento, resultado;
	char *validacao;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\nErro #%i: Numero de Argumentos Invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <primeiro-argumento> <segundo-argumento> \n\n", argv [0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	if ((argv[1][0] == '-') || (argv[2][0] == '-'))
	{
		printf ("\nErro #%i: Entrada de Argumento Negativo.\n\n", ARGUMENTO_NEGATIVO);
		printf ("Uso: %s <primeiro-valor-nao-negativo> <segundo-valor-nao-negativo>\n\n", argv[0]);
		exit (ARGUMENTO_NEGATIVO);
	}

	primeiroArgumento = strtoull (argv[1], &validacao, 10);
	segundoArgumento = strtoull (argv[2], &validacao, 10);

	if (errno == EINVAL)
	{
		printf ("\nErro #%i: Base Invalida.\n\n", BASE_INVALIDA);
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("\nErro #%i: Valor maximo permitido (%lu) para o tipo LONG LONG UNSIGNED.\n\n", VALOR_MAXIMO_EXCEDIDO, ULONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}
	
	if (*validacao != EOS)
	{
		printf ("\nErro #%i: O argumento contem um ou mais caractere invalido.\n\n", ARGUMENTO_INVALIDO);
		printf ("Caractere Invalido: '%c'.\n\n", *validacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if ((primeiroArgumento > ULLONG_MAX) || (segundoArgumento > ULLONG_MAX))
	{
		printf ("\nErro #%i: Valor excede o limite permitido para o tipo Unsigned Long Long.\n\n", 
				VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
		exit (VALOR_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
	}

	resultado = CalcularMaximoDivisorComum (primeiroArgumento, segundoArgumento);

	if (resultado <= ULLONG_MAX)
	{
		printf ("\n\nMDC (%llu, %llu) = %llu \n\n", primeiroArgumento, segundoArgumento, 
				CalcularMaximoDivisorComum (primeiroArgumento, segundoArgumento));
	}
	else
	{
		printf ("\nNao eh possivel calculcaro valor de %llu pois excede o valor permitido para unsigned long long.\n", resultado);
	}
	
	return OK;
}

/* $RCSfile: aula0302.c,v $ */
