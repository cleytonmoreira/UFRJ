/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa da funcao CalcularSerieHarmonicaAlternada com laco de repeticao While.
 *
 * $Autor$
 * $Date: 2022/01/10 05:08:24 $
 * $Log: aula0403d.c,v $
 * Revision 1.1  2022/01/10 05:08:24  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int valor)
{	
	float resultado = 1;
	int variavel = -1;
	int indice = 2;

	if (valor == 0)
		return 0;

	if (valor == 1)
		return 1;

	while(indice <= valor)
	{	
		resultado = resultado + (variavel *(1/CalcularExponencial(indice,indice)));
		variavel = variavel*variavel;
		indice++;		
	}
	
	return resultado;
}
/* $RCSfile: aula0403d.c,v $ */
