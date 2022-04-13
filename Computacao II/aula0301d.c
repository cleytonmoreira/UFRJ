/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa funcao CalcularMaximomum  atravésa ad repeticao While.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/20 02:44:30 $
 * $Log: aula0301d.c,v $
 * Revision 1.1  2021/12/20 02:44:30  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull primeiroValor, ull segundoValor)
{
	
	int indice = 0;
        int valorUm = primeiroValor;
        int valorDois = segundoValor;
        int resto;


        if(valorUm == 0 && valorDois == 0)
		return 0;
      

        if (valorUm == 0)
                return valorDois;
        

        if (valorDois == 0)
                return valorUm;

        while (valorDois != 0)
	{
		resto = valorUm % valorDois;
                valorUm = valorDois;
                valorDois = resto;

                indice++;

        }
	return  valorUm;
}


/* $RCSfile: aula0301d.c,v $ */
