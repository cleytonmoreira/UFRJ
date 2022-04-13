/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao do programa teste para a Funcao CalculcarSerieHarmonicaAlternada.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/11 05:00:47 $
 * $Log: aula0404.c,v $
 * Revision 1.2  2022/01/11 05:00:47  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 05:09:55  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

/* TODOS OS INCLUDES DO PROGRAMA */

/*#include <sys/limits.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <limits.h>
#include <errno.h>

#include "aula0401.h"

#include <math.h>

/* TODOS OS DEFINE PARA O PROGRAMA */

#define OK					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define NUMERO_DE_ARGUMENTOS			2
#define ARGUMENTO_NEGATIVO			3
#define ARGUMENTO_INVALIDO			4
#define VALOR_INTEIRO_EXCEDIDO			5
#define VALOR_MAXIMO_EXCEDIDO			6
#define BASE_INVALIDA				7
#define EOS					'\0'

int
main (int argc, char *argv[])
{
	char *verificacao;
	float valorIndice;
	int indice;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\nNumero de Argumentos Invalidos.\n");
		printf ("Uso: %s <valor-termo-nao-negatico>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf ("\nValor Negativo do Argumento,\n");
		printf ("Uso: %s <valor-inteiro-nao-negativo>\n\n", argv[0]);
		exit (ARGUMENTO_NEGATIVO);
	}

	valorIndice = strtof (argv[1], &verificacao);

	if (errno == EINVAL)
	{
		printf ("\nValor para Base Invalida.\n\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("\nValor maximo excedido.");
		printf ("Valor Maximo: %lu\n\n", ULONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	if (*verificacao != EOS)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		printf ("Caractere Invalido: %c\n\n", *verificacao);
		exit (ARGUMENTO_INVALIDO);
	}

	float numero = (float) valorIndice;

	if ((numero > 1) || (numero < 0))
	{
		printf ("O Valor deve esta entre 0 < valor < 1.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	printf ("\n\n");
	for (indice = 1; (1/CalcularExponencial( indice, 2)) > numero; indice++)
	{
		printf ("1/(%i^(2)) = %Lf > %f*S(%i) = %.10f\t|\tS(%i) = %.10f\n", indice, 1/CalcularExponencial(indice, 2), numero, 
				(indice-1), numero*CalcularSerieHarmonicaAlternada (indice-1), 
				indice, CalcularSerieHarmonicaAlternada(indice));
	}
	printf ("1/(%i^(2)) = %Lf < %f*S(%i) = %.10f\t|\tS(%i) = %.10f\n", indice, 1/CalcularExponencial(indice, 2), numero, 
				(indice-1), numero*CalcularSerieHarmonicaAlternada (indice-1), 
				(indice-1), CalcularSerieHarmonicaAlternada(indice -1));
	printf("\n\n");
	return OK;
}
/* $RCSfile: aula0404.c,v $ */
