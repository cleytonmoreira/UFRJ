/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa CalcularTermoSerieFibonacci com repeticao DO-WHILE.
 *  
 * $Author: cleyton.moreira $
 * $Date: 2021/12/10 01:55:56 $
 * $Log: aula0201b.c,v $
 * Revision 1.1  2021/12/10 01:55:56  cleyton.moreira
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
	int indice = 3; 
	int resultado;

	if (indiceTermo <= 1)
		return indiceTermo;
	
	do {		
		resultado = valor1 + valor2;
		valor1 = valor2;
	        valor2 = resultado;
		indice += 1;
	}	
	while (indice <= indiceTermo);
	
	return valor2;
}
/* $RCSfile: aula0201b.c,v $ */
