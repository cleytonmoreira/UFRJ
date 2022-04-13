/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo da funcao calcular exponencial de forma recursiva.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/11 01:21:36 $
 * $Log: aula0401a.c,v $
 * Revision 1.2  2022/01/11 01:21:36  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 02:34:04  cleyton.moreira
 * Initial revision
 *
 *
 */

#include <math.h>

#if defined (__STRICT_ANSI__) && defined (__linux__)
#define INFINITO 1.0/0.0
#else
#define INFINITO INFINITY
#endif

#include "aula0401.h"

long double
CalcularExponencial (double base, int expoente)
{
	if ((base == 0) && (expoente < 0))
		return INFINITO;
	
	if (expoente == 0)
		return 1;

	if (expoente < 0)
		return ((1/base)*CalcularExponencial((1/base),(expoente*(-1) - 1)));
	else
		return (base*CalcularExponencial (base, (expoente - 1)));
}
/* $RCSfile: aula0401a.c,v $ */
