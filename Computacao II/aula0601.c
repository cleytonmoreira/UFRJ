/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao da funcao MultiplicarMatrizes.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/04/06 04:51:12 $
 * $Log: aula0601.c,v $
 * Revision 1.7  2022/04/06 04:51:12  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.6  2022/02/01 08:00:04  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.5  2022/02/01 04:53:54  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.4  2022/01/25 04:21:42  cleyton.moreira
 * ls
 *
 * Revision 1.3  2022/01/24 14:04:43  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/24 11:43:03  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/23 07:54:58  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivos cabecalho da biblioteca padrao. */
#include <stdlib.h>
#include <stdio.h>

/* Inclusao do arquivo de cabecalho personalizado para o programa. */
#include "aula0601.h"


/* Implementacao da funcao MultiplicarMatrizes */
tipoErros
MultiplicarMatrizes (unsigned short LINHA_1, unsigned short COLUNA_1, unsigned short LINHA_2, unsigned short COLUNA_2, 
			double matriz1 [100][100], double matriz2 [100][100], double matrizResultado [100][100])
{
	ush contadorLinhas, contadorColunas, contadorAuxiliar = 0;

	if (matriz1 == NULL)
		return argumentoNulo;
	
	if (matriz2 == NULL)
		return argumentoNulo;
	
	if ((!LINHA_1) || (!COLUNA_1) || (!LINHA_2) || (!COLUNA_2))
		return argumentoNulo;
	
	if ((LINHA_1 > 100) || (LINHA_2 > 100) || (COLUNA_1 > 100) || (COLUNA_2 > 100))
		return argumentoInvalido;

	if (COLUNA_1 == LINHA_2)
	{
		for (contadorLinhas = 0; contadorLinhas < LINHA_1; contadorLinhas++)
		{
			for (contadorColunas = 0; contadorColunas < COLUNA_2; contadorColunas++)
			{
				matrizResultado [contadorLinhas][contadorColunas] = 0;
				
				for (contadorAuxiliar = 0; contadorAuxiliar < COLUNA_1; contadorAuxiliar++)
				{
					matrizResultado [contadorLinhas][contadorColunas] = 
						matrizResultado [contadorLinhas][contadorColunas] + 
						matriz1 [contadorLinhas][contadorAuxiliar] * 
						matriz2 [contadorAuxiliar][contadorColunas];
				}
			}
		}

	}
	else
	{
		return argumentoInvalido;
	}

	return ok;
}

/* Implementacao  da funcao ObterMatrizTransposta */

tipoErros
ObterMatrizTransposta (unsigned short linhas_1, unsigned short colunas_1,
			double matrizOriginal [100][100], double matrizTransposta [100][100])
{
	ush contadorLinhas, contadorColunas;
	for (contadorLinhas = 0; contadorLinhas < linhas_1; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < colunas_1; contadorColunas++)
			matrizTransposta [contadorColunas][contadorLinhas] = matrizOriginal [contadorLinhas][contadorColunas];
	return ok;
}

/* Implementacao CalcularDeterminanteMatriz. */

tipoErros
CalcularDeterminanteMatriz (unsigned short indiceOrdem, double matriz [100][100], double *determinante)
{
	double *complementoAlgebrico, local;
	local = 0;
	complementoAlgebrico = &local;
	ush contadorLinhas, contadorColunas;
	
	if(indiceOrdem == 1)
		determinante[0] = matriz[0][0];
	
	if(indiceOrdem == 2)
		determinante[0] = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);

	if(indiceOrdem == 3)
	{
		determinante[0] = ((matriz[0][0]*matriz[1][1]*matriz[2][2] + 
							matriz[0][1]*matriz[1][2]*matriz[2][0] +
							matriz[0][2]*matriz[1][0]*matriz[2][1]) -
							(matriz[0][1]*matriz[1][0]*matriz[2][2] +
							matriz[0][0]*matriz[1][2]*matriz[2][1] +
							matriz[0][2]*matriz[1][1]*matriz[2][0]));

	}

	if(indiceOrdem > 3)
	{
		double somatorio = 0;
		contadorLinhas = indiceOrdem - 1;
		contadorColunas = 0;
		
		for (contadorColunas = 0; contadorColunas < indiceOrdem; contadorColunas++)
		{
			CalcularComplementoAlgebrico (indiceOrdem , contadorLinhas, contadorColunas, matriz, complementoAlgebrico);
			somatorio +=  complementoAlgebrico[0] * matriz[contadorLinhas][contadorColunas];
		}
		
		determinante[0] = somatorio;		
	}

	return ok;
}

/* Implementacao da funcao CalcularMenorComplementar. */
tipoErros CalcularMenorComplementar (unsigned short ordemMatriz, unsigned short linha1,\
	       			    unsigned short coluna1, double matriz[LIMITE_LINHAS][LIMITE_COLUNAS],\
				    double *menorComplementar){
	
	int c=0,i=0,j=0,linha=0,coluna=0;
	double vetorAux[LIMITE_LINHAS];

	if (ordemMatriz < 2){
		printf ("Ordem da matriz invalida!\n");
		return argumentoInvalido;
	}

	if (linha1 > (ordemMatriz -1) || coluna1 > (ordemMatriz -1)){
		printf ("Linha ou coluna inexistente!\n");
		return argumentoInvalido;
	}

	
	linha = linha1;
	coluna = coluna1;
	
	for (i=0; i < ordemMatriz; i++){
		for (j =0; j < ordemMatriz; j++){
			if(i != linha && j != coluna){
				vetorAux[c] = matriz[i][j];
				c++;
			}
		}
	}

	c =0;
	
	for (i =0; i < ordemMatriz - 1;i++){
		for (j =0; j < ordemMatriz - 1;j++){
			matriz[i][j] = vetorAux[c];
			c++;
			
		}
	}
		
	return ok;

}

/* Implementacao da funcao CalcularComplementoAlgebrico. */
tipoErros CalcularComplementoAlgebrico (unsigned short ordemMatriz, unsigned short linha1,\
	       			        unsigned short coluna1, double matriz[LIMITE_LINHAS][LIMITE_COLUNAS],\
				        double *complementoAlgebrico){
	
	double *determinante,*menorComplementar;
	double local;
	local = 0;
	determinante = &local;
	menorComplementar = &local;
	
	CalcularMenorComplementar (ordemMatriz,linha1,coluna1,matriz,menorComplementar);	

        CalcularDeterminanteMatriz (ordemMatriz - 1, matriz, determinante);	
	
	
	if ((linha1 + coluna1) % 2 == 0){
		complementoAlgebrico[0] = 1 * determinante[0];
	}

	else{
		complementoAlgebrico[0] = ((1 * determinante[0]) * -1);
	}

	return ok;

}


/* $RCSfile: aula0601.c,v $ */
