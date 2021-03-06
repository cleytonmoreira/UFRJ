/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa contendo o codigo fonte para a funcao MostrarMonitor.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/24 04:28:34 $
 * $Log: aula0701.c,v $
 * Revision 1.2  2022/02/24 04:28:34  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/08 00:51:41  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivos de cabecalho padrao para este programa. */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0701.h"

/* Implementacao da funcao MostrarMonitor */
tipoErros
MostrarMonitor (useconds_t tempoEspera, tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		unsigned numeroMaximoLinhas, unsigned numeroMaximoColunas)
{
	unsigned indiceLinhas, indiceColunas;

	if (monitor == NULL)
		return monitorNulo;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS)
			return numeroLinhaInvalido;
	
	if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return numeroColunaInvalido;

	system("clear");
	
	for (indiceLinhas = 0; indiceLinhas < (numeroMaximoLinhas + 2); indiceLinhas++)
		printf ("-");
	printf ("\n");
	for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
	{
		printf ("|");
		for (indiceColunas = 0; indiceColunas < numeroMaximoLinhas; indiceColunas++)
		{
			printf (monitor[indiceLinhas][indiceColunas] == aceso ? "O" :\
				       	monitor[indiceLinhas][indiceColunas] == apagado ? " " : ".");
		}
		printf ("|\n");
	}
	for (indiceLinhas = 0; indiceLinhas < (numeroMaximoLinhas + 2); indiceLinhas++)
			printf ("-");
	printf ("\n");
	
	usleep(tempoEspera);

	printf ("\n");
	return ok;
}


tipoErros
GerarDistribuicaoInicial (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			  unsigned numeroMaximoLinhas, unsigned numeroMaximoColunas,
			  float percentualDefeituosos, float percentualApagados)
{
	unsigned contadorPixels, contadorDefeituosos, contadorApagados;
	unsigned indiceLinhas, indiceColunas, auxiliar;
	unsigned indiceLinhasAleatoria, indiceColunasAleatoria;

	if (!monitor)
		return monitorNulo;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS)
		return numeroLinhaInvalido;

	if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return numeroColunaInvalido;

	if ((percentualDefeituosos < 0.0) || (percentualDefeituosos > 100.0))
		return numeroDefeituososInvalido;

	if ((percentualApagados < 0.0) || (percentualApagados > 100.0))
		return numeroApagadosInvalido;

	if ((percentualApagados + percentualApagados) > 100.0)
		return numeroDefeituososInvalido;
	
	contadorPixels = numeroMaximoLinhas * numeroMaximoColunas;
	
	contadorDefeituosos = ((percentualDefeituosos/100) * contadorPixels);
	
	contadorApagados = ((percentualApagados/100) * contadorPixels);

	for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
	{
		for (indiceColunas = 0; indiceColunas < numeroMaximoColunas; indiceColunas++)
		{
			if (percentualApagados > 0)
			{
				monitor [indiceLinhas][indiceColunas] = apagado;
				contadorApagados--;
			}
			else if (percentualDefeituosos > 0)
			{
				monitor [indiceLinhas][indiceColunas] = defeituoso;
				contadorDefeituosos--;
			}
			else
				monitor [indiceLinhas][indiceColunas] = aceso;
		}
	}

	srand((unsigned) time(NULL));

	for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
	{
		for (indiceColunas = 0; indiceColunas < numeroMaximoColunas; indiceColunas++)
		{
			indiceLinhasAleatoria = rand() % numeroMaximoLinhas;
			indiceColunasAleatoria = rand() % numeroMaximoColunas;
			auxiliar = monitor [indiceLinhas][indiceColunas];
			monitor[indiceLinhas][indiceColunas] = monitor[indiceLinhasAleatoria][indiceColunasAleatoria];
			monitor[indiceLinhasAleatoria][indiceColunasAleatoria] = auxiliar;
		}
	}

	return ok;
}


tipoErros LimparMonitor (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],\
	unsigned numeroMaximoLinhas, unsigned numeroMaximoColunas)
{
	  
	unsigned indiceLinhas, indiceColunas;
	
	if (monitor == NULL)
		return monitorNulo;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS)
		return numeroLinhaInvalido;
	
	if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return numeroColunaInvalido;
		
	system("clear");
		
	
	for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
	{
		for (indiceColunas = 0; indiceColunas < numeroMaximoColunas; indiceColunas++)
		{
			if(monitor[indiceLinhas][indiceColunas] != defeituoso)
			{
				monitor[indiceLinhas][indiceColunas] = apagado;
			}
		}		          	
	}	

	return ok;
}



tipoErros DesenharReta (tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
			unsigned numeroMaximoLinhas, unsigned numeroMaximoColunas, unsigned linhaA, 
			unsigned colunaA, unsigned linhaB, unsigned colunaB)
{
	  
	signed deltaLinha, deltaColuna, direcaoY, direcaoX;
	float coeficienteAngularX, coeficienteAngularY;
	unsigned indiceLinhas, indiceColunas, indice, indiceLinhaA, indiceColunaA, indiceLinhaB, indiceColunaB;
	
	indiceLinhaA = linhaA - 1;
	indiceColunaA = colunaA - 1;
	indiceLinhaB = linhaB - 1;
	indiceColunaB = colunaB - 1;

	if (monitor == NULL)
		return monitorNulo;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS)
		return numeroLinhaInvalido;
	
	if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return numeroColunaInvalido;

	if(indiceLinhaA == indiceLinhaB)
	{	
		for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
		{	
			for (indiceColunas = 0; indiceColunas < numeroMaximoColunas; indiceColunas++)
			{	
				if(indiceColunaA <= indiceColunaB)
				{
					monitor[indiceLinhaA][indiceColunaA] = aceso;
					indiceLinhaA =  indiceLinhaA;	
					indiceColunaA++;
				}
				
				if(indiceColunaA >= indiceColunaB)
				{
					monitor[indiceLinhaA][indiceColunaA] = aceso;
					indiceLinhaA = indiceLinhaA;
					indiceColunaA--;
				}

				if(monitor[indiceLinhaA][indiceColunaA] == defeituoso)
				{
					return pixelDefeituoso;
				}
			}
		}
	}
	else if (indiceColunaA == indiceColunaB)
	{
		for (indiceLinhas = 0; indiceLinhas < numeroMaximoLinhas; indiceLinhas++)
		{
			for (indiceColunas = 0; indiceColunas < numeroMaximoColunas; indiceColunas++)
			{
				if(indiceLinhaA <= indiceLinhaB)
				{	
					monitor[indiceLinhaA][indiceColunaA] = aceso;
					indiceColunaA = indiceColunaA;
					indiceLinhaA++;
				}
				
				if(indiceLinhaA >= indiceLinhaB)
				{
					monitor[indiceLinhaA][indiceColunaA] = aceso;
					indiceColunaA = indiceColunaA;	
					indiceLinhaA--;
				}

				if(monitor[indiceLinhaA][indiceColunaA] == defeituoso)
				{
					return pixelDefeituoso;
				}
			}
		}
	}	
	else 
	{  

		deltaLinha = indiceLinhaA - indiceLinhaB;
		deltaColuna = indiceColunaA - indiceColunaB;

		if (deltaLinha > 0)
		{
			direcaoY = -1;
		}
		else
		{
			deltaLinha = deltaLinha*(-1);
			direcaoY = 1;
		}
	
		if (deltaColuna > 0)
		{
			direcaoX = -1;
		}
		else
		{
			deltaColuna = deltaColuna*(-1);
			direcaoX = 1;
		}

		coeficienteAngularY = (float) deltaColuna/deltaLinha;

		for ( indice = 0; indice < deltaLinha; indice++)
		{
			int inteiroCoeficiente = (int) (coeficienteAngularY *  indice);		
			
			if (monitor[indiceLinhaA + (indice * direcaoY)][indiceColunaA + ( inteiroCoeficiente * direcaoX )] != defeituoso)
			{
				monitor[indiceLinhaA + (indice * direcaoY)][indiceColunaA + ( inteiroCoeficiente * direcaoX )] = aceso;
			}
			else 
			{
				return pixelDefeituoso;
			}
			
		}
	
		coeficienteAngularX = (float) deltaLinha/deltaColuna;
		

		for ( indice = 0; indice < deltaColuna ; indice++)
		{
			int inteiroCoeficiente = (int) (coeficienteAngularX *  indice);
			
			if (monitor[indiceLinhaA + ( inteiroCoeficiente * direcaoY )][indiceColunaA + (indice * direcaoX)] != defeituoso)
			{
				monitor[indiceLinhaA + ( inteiroCoeficiente * direcaoY )][indiceColunaA + (indice * direcaoX)] = aceso;
			}

			else 
			{
				return pixelDefeituoso;
			}
		}			
	}
	return ok;
}


tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], unsigned numeroMaximoLinhas, 
		  unsigned numeroMaximoColunas, unsigned numeroVertices, unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],
		  unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS])
{
	
	unsigned indice;
	unsigned linhaA, colunaA, linhaB, colunaB;
	tipoErros condicao;	
	
	for (indice = 0; indice < numeroVertices; indice++)
	{
		linhaA = linhasVertices[indice];
		colunaA = colunasVertices[indice];	
		
		if (indice + 1 == numeroVertices)
		{
			linhaB = linhasVertices[0];
			colunaB = colunasVertices[0];
		}
		else
		{
			linhaB = linhasVertices[indice + 1];
            colunaB = colunasVertices[indice + 1];
		}	
		
		condicao = DesenharReta (monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaA, colunaA, linhaB, colunaB);
		
		if (condicao != ok)
		{
			return pixelDefeituoso;
		}
	}	
	return ok;
}


tipoErros
PreencherPoligono (useconds_t tempoEspera, tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
		   unsigned numeroMaximoLinhas, unsigned numeroMaximoColunas, unsigned linha, unsigned coluna)
{
	signed indiceLinhas, indiceColunas;
	tipoErros condicao;
	
	indiceLinhas = linha - 1;
	indiceColunas = coluna - 1;
	
	if (monitor == NULL)
		return monitorNulo;

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS)
			return numeroLinhaInvalido;
	
	if (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return numeroColunaInvalido;
	
	if (monitor[indiceLinhas][indiceColunas] == defeituoso)
		return pixelDefeituoso;
		
	if (monitor[indiceLinhas][indiceColunas] == apagado)
	{
		monitor[indiceLinhas][indiceColunas] = aceso;	
		condicao = MostrarMonitor(tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);	
	}
	
	if (monitor[indiceLinhas + 1][indiceColunas] != aceso)
	{	
		condicao = PreencherPoligono (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha + 1, coluna);
		if (condicao == pixelDefeituoso)
			return pixelDefeituoso;
	}	
	
	if (monitor[indiceLinhas - 1][indiceColunas] != aceso)
	{	
		condicao = PreencherPoligono (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha - 1, coluna);
		if (condicao == pixelDefeituoso)
			return pixelDefeituoso;
	}

	if (monitor[indiceLinhas][indiceColunas + 1] != aceso)
	{	
		condicao = PreencherPoligono (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna + 1);
		if (condicao == pixelDefeituoso)
			return pixelDefeituoso;
	}

	if (monitor[indiceLinhas][indiceColunas - 1] != aceso)
	{	
		condicao = PreencherPoligono (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna - 1);	
		if (condicao == pixelDefeituoso)
			return pixelDefeituoso;
	}
	return ok;
}

/* $RCSfile: aula0701.c,v $ */
