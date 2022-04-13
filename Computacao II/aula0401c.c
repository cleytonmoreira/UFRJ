/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa da Funcao CalcularExponencial com a estrutura de repeticao FOR.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/11 01:41:50 $
 * $Log: aula0401c.c,v $
 * Revision 1.2  2022/01/11 01:41:50  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 03:22:42  cleyton.moreira
 * Initial revision
 *
 *
 */

#include <math.h>

#if defined (__STRICT_ANSI__) && defined(__linux__)
#define INFINITO 1.0/0.0
#else
#define INFINITO INFINITY
#endif

#include "aula0401.h"

long double
CalcularExponencial (double base,int expoente)
{		
	
	long double resultado = 1;
	unsigned short indice;

	if ((base == 0) && (expoente == 0))
		return 1;

	if (expoente == 0)
		return 1;

	if ((base == 0) && (expoente < 0))
		return INFINITO;
	
	if (expoente < 0)
	{
		base = (1/base);
		expoente = (expoente*(-1));
	}

	for (indice = 0; (indice < expoente); indice++)
		resultado *= base;
	
	return resultado;
}
/* $RCSfile: aula0401c.c,v $ */
