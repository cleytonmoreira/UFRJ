/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao do programa teste para a funcao CalcularExponecial.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/11 05:00:59 $
 * $Log: aula0402.c,v $
 * Revision 1.2  2022/01/11 05:00:59  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 02:34:04  cleyton.moreira
 * Initial revision
 *
 *
 */


#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (STRICT_ANSI__)
#define __ISO_C_VISIBLE		1999
#define __LONG_LONG_SUPPORTED
#endif

/* TODOS OS INCLUDES DO PROGRAMA */

/*#include <sys/limits.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>

#include "aula0401.h"

#include <math.h>

/* TODOS OS DEFINES DO PROGRAMA */

#define OK					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define BASE_INVALIDA				2
#define NUMERO_DE_ARGUMENTOS			3
#define VALOR_MAXIMO_EXCEDIDO			4
#define ARGUMENTO_INVALIDO			5
#define VALOR_INTEIRO_EXCEDIDO			6
#define EOS					'\0'


int
main (int argc, char *argv[])
{
	double base;
	char *verificacao;
	long expoenteLongo;
	long double resultado;
	int expoente;
	
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("Numero de Argumentos invalido.\n");
		printf ("Uso: %s <valor-termo-base> <valor-termo-expoente>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	base = strtod (argv[1], &verificacao);
	expoenteLongo = strtol (argv[2],&verificacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("\nArgumento de BASE invalida.\n");
		exit (BASE_INVALIDA);
	}

	if ((expoenteLongo > INT_MAX) || (expoenteLongo < INT_MIN))
	{
		printf ("\nValor maximo para o argumento base (inteiro).\n");
		exit (VALOR_INTEIRO_EXCEDIDO);
	}

	if (errno == ERANGE)
	{
		printf ("Valor do Argumento excedido para a funcao.\n");
		printf ("Valor maximo permitido: %lu.\n\n", ULONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("\nArgumento contem caractere invalido.\n\n");
		printf ("Caractere Invalido: %c \n\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	expoente = (int) expoenteLongo;
	resultado = CalcularExponencial (base, expoente);

	printf ("\n(%f)^(%i) = %.10Lf \n\n\n", base, expoente, resultado);

	return OK;
}

/* $RCSfile: aula0402.c,v $ */
