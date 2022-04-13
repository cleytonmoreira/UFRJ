/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Funcao CalcularTermoSerieFibonacci com recursividade.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/08 01:59:18 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2021/12/08 01:59:18  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us indiceTermo)
{

	if (indiceTermo <= 1)
		return indiceTermo;

	return CalcularTermoSerieFibonacci (indiceTermo - 2) 
			+ CalcularTermoSerieFibonacci (indiceTermo - 1);
}
/* $RCSfile: aula0201a.c,v $ */
