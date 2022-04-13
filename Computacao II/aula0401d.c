/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa da funcao CalculcarExponencial com estrutura de repeticao While.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/11 01:50:24 $
 * $Log: aula0401d.c,v $
 * Revision 1.2  2022/01/11 01:50:24  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 03:29:40  cleyton.moreira
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

	if ((base == 0) && (expoente == 0))
		return 1;

	if (expoente == 0)
		return 1;

	if (base == 0)
	{
		if (expoente < 0)
			return INFINITO;
		else
			return 0;
	}
	
	if (expoente < 0)
	{
		base = (1/base);
		expoente = expoente*(-1);

	}
	while (expoente > 0)
	{
		resultado *= base;
		--expoente;
	}	
	return resultado;
}

/* $RCSfile: aula0401d.c,v $ */
