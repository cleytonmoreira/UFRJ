/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Codifo fonte para o programa de teste da aula02.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/10 01:55:56 $
 * $Log: aula0202.c,v $
 * Revision 1.2  2021/12/10 01:55:56  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2021/12/08 01:59:18  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE		1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <errno.h>
#include "aula0201.h"


#define OK					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define NUMERO_DE_ARGUMENTOS			2
#define ARGUMENTO_NEGATIVO			3
#define ARGUMENTO_INVALIDO			4
#define BASE_INVALIDA				5
#define VALOR_MAXIMO_EXCEDIDO			6
#define VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO	7
#define EOS					'\0'

int
main (int argc, char *argv[])
{
	us contador, indice;
	unsigned long indiceTermo;
	ull resultado;
	char *validacao;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("Execucao Incorreta.\n\n");
		printf ("Uso: %s <valor-termo-SerieFibonacci>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	if (argv[1][0] == '-')
	{
		printf ("Argumento Negatido.\n\n");
		printf ("Uso: %s <numero_inteiro-nao-negativo>\n\n", argv[0]);
		exit (ARGUMENTO_NEGATIVO);
	}

	indiceTermo = strtoul (argv [1], &validacao, 10);

	if (errno == EINVAL)
	{
		printf ("Base Invalida!\n");
		exit (BASE_INVALIDA);
	}

	if (errno == ERANGE)
	{
		printf ("Valor Maximo Permitido (%lu) pela funcao foi excedido!\n", ULONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	if (*validacao != EOS)
	{
		printf ("\nArgumento Contem Caractere invalido!\n");
		printf ("Caractere Invalido: %c \n\n", *validacao);
		exit (ARGUMENTO_INVALIDO);
	}

	if (indiceTermo > USHRT_MAX)
	{
		printf ("Valor Excede o Limite para UNSIGNED SHORT.\n");
		exit (VALOR_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}
	
	printf ("\n\n");
	
	indice = (unsigned short) indiceTermo;

	for (contador = 0; contador  <= indice; contador++)
	{
		resultado  = CalcularTermoSerieFibonacci (contador);
		if (resultado <= ULLONG_MAX)
		{
			printf ("F(%i) = %llu \n", contador, CalcularTermoSerieFibonacci (contador));
		}
		else
			printf ("Impossivel calcular o Fibonacci de %hu, pois excedeu o valor permitido.", contador);
	}
	printf ("\n\n");

	return OK;	
}

/* $RCSfile: aula0202.c,v $ */
