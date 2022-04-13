/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: CleytonMarcos Siqueira Moreira
 * Descricao: Programa da funcao CalcularMaximodivisorComum atraves da repeticao FOR.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/24 00:15:03 $
 * $Log: aula0301c.c,v $
 * Revision 1.2  2022/02/24 00:15:03  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2021/12/20 02:44:30  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull primeiroValor, ull segundoValor)
{
	int indice;
	int valorUm = primeiroValor;
	int valorDois = segundoValor;	
	int restoUm = 1,restoDois = 1;
	
	if(valorUm == 0 && valorDois == 0)
		return 0;

	if (valorUm == 0)
		return valorDois;

	if (valorDois == 0)
		return valorUm;
	
	if(valorUm >= valorDois)
	{

		for (indice = valorDois; (restoUm != 0 || restoDois != 0); indice--)
		{ 
			restoDois = valorDois % indice;
			restoUm = valorUm % indice;
		}
	}
	else{
		
		for (indice = valorUm; (restoUm != 0 || restoDois != 0); indice--)
		{
			restoUm = valorUm % indice;
			restoDois = valorDois % indice;
		}
	}
		
	return indice + 1;		

	}


/* $RCSfile: aula0301c.c,v $ */
