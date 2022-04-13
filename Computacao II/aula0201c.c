/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa CalcularTermoSerieFibonacci com repeticao For.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/10 01:56:59 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2021/12/10 01:56:59  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull
CalcularTermoSerieFibonacci (us indiceTermo)
{
 	int valor1 = 1;		
	int valor2 = 1;
	int resultado;

	if (indiceTermo <= 1)
		return indiceTermo;

	int indice;
	for(indice = 3; indice <= indiceTermo; indice++)
	{
		
		resultado =  valor1 + valor2;
		valor1 = valor2;
		valor2 = resultado;
		
	}
	return valor2; 
}
/* $RCSfile $ */
