/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa da Funcao CalcularSerieHarmonicaalternada com laco de repeticao While.
 *
 * $Autor$
 * $Date: 2022/03/29 22:42:02 $
 * $Log: aula0403e.c,v $
 * Revision 1.3  2022/03/29 22:42:02  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/11 05:00:39  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 05:08:24  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0401.h"

#include <string.h>
#include <math.h>

float
CalcularSerieHarmonicaAlternada (unsigned short int termo)
{
	float resultado = 0;
	int variavel = -1;
	int indice = 2;

	if (termo == 0)
		return 0;

	if (termo == 1)
		return 1;

	while (indice <= termo)
	{
		resultado = resultado + (variavel *(1/ pow (indice, indice)));
		variavel = variavel * variavel;
		indice++;
	}
	return resultado;
}
/* $RCSfile: aula0403e.c,v $ */
