/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa da funcao CalcularSerieHarmonicaAlternada com recursividade.
 *
 * $Autor$
 * $Date: 2022/01/11 04:35:30 $
 * $Log: aula0403a.c,v $
 * Revision 1.2  2022/01/11 04:35:30  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/10 05:08:24  cleyton.moreira
 * Initial revision
 *
 *
 */

#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int termo)
{		
	if (termo == 0)
		return 0;

	if ((termo % 2) == 0)
		return (float)(CalcularSerieHarmonicaAlternada(termo - 1) - (1/CalcularExponencial(termo, termo)));

	return (float)((1/CalcularExponencial(termo, termo)) + CalcularSerieHarmonicaAlternada (termo - 1));
}
/* $RCSfile: aula0403a.c,v $ */
