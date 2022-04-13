/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao da funca CalcularMaximodivisorComum com recursividade.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/20 02:44:30 $
 * $Log: aula0301a.c,v $
 * Revision 1.1  2021/12/20 02:44:30  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull primeiroArgumento, ull segundoArgumento)
{
	int primeiroValor = primeiroArgumento;
	int segundoValor = segundoArgumento;

	if (primeiroValor == 0 && segundoValor == 0)
		return 0;

	if (segundoValor == 0)
		return primeiroValor;

	return CalcularMaximoDivisorComum (segundoValor, primeiroValor % segundoValor);
}

/* $RCSfile: aula0301a.c,v $ */
