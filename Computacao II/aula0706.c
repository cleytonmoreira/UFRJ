/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - ComputacaoII - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa para realizacao de testes da funcao PreencherPoligono.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 *
 */
 
/* Inclusao dos arquivos de cabecalho padrao para esse programa. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>

/* Inclusao dos arquivos de cabecalho personalizado para esse programa. */
#include "aula0701.h"

/* definicao das macros */
#define NUMERO_DE_ARGUMENTOS 		14		

int main (int argc, char *argv[]) 
{
	ush indiceArgumento;
	unsigned numeroLinhas, numeroColunas, indiceLinhas, indiceColunas;
	unsigned percentualDefeituosos, percentualApagados, numeroVertices;
	unsigned linhaPonto, colunaPonto, numeroVertices;
	unsigned int tempoEspera;
	unsigned int argumento1;
	unsigned long argumento2;
	unsigned linhasVertices [numeroVertices], colunasVertices [numeroVertices];
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	char *validacao;
	tipoErros resultado;
	
	if (argc < NUMERO_DE_ARGUMENTOS)
	{	
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
				<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
				<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	for (indiceArgumento = 1; indiceArgumento < NUMERO_DE_ARGUMENTOS + 1; indiceArgumento++)
	{
		argumento1 = strtod (argv[indiceArgumento], &validacao);
		if (errno == EINVAL)
		{
			printf ("\n\n\nErro #%i: Argumento passado com base invalida.\n", BASE_INVALIDA);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
			exit (BASE_INVALIDA);
		}
		if (errno == ERANGE)
		{
			printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido pela baseo.\n", BASE_INVALIDA);
			printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		 	exit (BASE_INVALIDA);
		}
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("caractere invalido: '%c'\n", *validacao);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
		if (indiceArgumento == 1)
		{
			tempoEspera = (unsigned int) argumento1;
			if ((tempoEspera < 0) || (tempoEspera > TEMPO_MAXIMO_DE_ATRASO))
			{
				printf ("\n\n\nErro #%i: Tempo de espera do programa indiferente do tempo esperado.\n", ARGUMENTO_INVALIDO);
				printf ("Tempo de espera permitido: 0 a 1000 us\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
			       	exit (ARGUMENTO_INVALIDO);
			}
		}
		if (indiceArgumento == 2)
		{
			numeroLinhas = (unsigned) argumento1;
			if ((numeroLinhas < 0) || (numeroLinhas > NUMERO_MAXIMO_LINHAS))
			{
				printf ("\n\n\nErro #%i: Numero de linhas do programa indiferente da quantidade esperada.\n", NUMERO_DE_LINHAS_INVALIDO);
				printf ("Numero de linhas permitido: 0 a 250\n");
				pprintf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		       	exit (NUMERO_DE_LINHAS_INVALIDO);
			}
		}
		if (indiceArgumento == 3)
		{
			numeroColunas = (unsigned) argumento1;
			if ((numeroColunas < 0) || (numeroColunas > NUMERO_MAXIMO_COLUNAS))
			{
				printf ("\n\n\nErro #%i: Numero de colunas do programa indiferente da quantidade esperada.\n", NUMERO_DE_COLUNAS_INVALIDO);
				printf ("Numero de colunas permitido: 0 a 800\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
	        		exit (NUMERO_DE_COLUNAS_INVALIDO);
			}
		}
		if (indiceArgumento == 4)
		{
			percentualDefeituosos = (unsigned) argumento1;
			if ((percentualDefeituosos < 0) || (percentualDefeituosos > (numeroMaximoLinhas*numeroMaximoColunas)))
			{
				printf ("\n\n\nErro #%i: Quantidade de percentual de defeituosos invalido.\n", PERCENTUAL_DEFEITUOSOS_INVALIDO);
				printf ("Percentual valido: 0 <= Percentual Defeituoso <= 100.\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		        	exit (PERCENTUAL_DEFEITUOSOS_INVALIDO);
			}
		}
		if (indiceArgumento == 5)
		{
			percentualApagados = (unsigned) argumento1;
			if ((percentualApagados < 0) || (percentualApagados > (numeroMaximoLinhas*numeroMaximoColunas)))
			{
				printf ("\n\n\nErro #%i: Percentual de defeituosos invalido.\n", PERCENTUAL_APAGADOS_INVALIDO);
				printf ("Percentual valido: 0 <= Percentual Apagados <= 100.\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		        	exit (PERCENTUAL_APAGADOS_INVALIDO);
			}
		}
		if (indiceArgumento == 6)
		{
			linhaPonto = (unsigned) argumento1;
			if (linhaPonto < 0)
			{
				printf ("\n\n\nErro #%i: Numero da linha ponto invalido.\n", NUMERO_DE_VERTICES_INVALIDO);
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
	        	exit (NUMERO_DE_VERTICES_INVALIDO);
			}
		}
		if (indiceArgumento == 7)
		{
			colunaPonto = (unsigned) argumento1;
			if (colunaPonto < 0)
			{
				printf ("\n\n\nErro #%i: Numero da coluna ponto invalido.\n", NUMERO_DE_VERTICES_INVALIDO);
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
	        	exit (NUMERO_DE_VERTICES_INVALIDO);
			}
		}
		if (indiceArgumento == 8)
		{
			numeroVertices = (unsigned) argumento1;
			if (numeroVertices < 0)
			{
				printf ("\n\n\nErro #%i: Numero de vertices invalido.\n", NUMERO_DE_VERTICES_INVALIDO);
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
	        	exit (NUMERO_DE_VERTICES_INVALIDO);
			}
		}
		if (indiceArgumento >= 9)
		{
			if ((argumento1 < 0) || (argumento1 > numeroLinhas) || (argumento1 > numeroColunas))
			{
				printf ("\n\n\nErro #%i: Numero de vertices invalido.\n", NUMERO_DE_VERTICES_INVALIDO);
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
						 <numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
						 <linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
	        	exit (NUMERO_DE_VERTICES_INVALIDO);
			}				
			else
			{
				for (indiceDigito = 0; indiceDigito < (numeroVertices*2); indiceDigito++)
				{
					if ((indiceArgumento % 2) == 1)
					{
						linhasVertices [indiceDigito] = argumento;
					}
					else
					{
						colunasVertices [indiceDigito] = argumento;
					}
				}					
			}
		}
	}
	
	
	resultado = GerarDistribuicaoInicial (monitor, numeroMaximoLinhas, numeroMaximoColunas, percentualDefeituosos, percentualApagados);
		
	resultado = MostrarMonitor (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
	
	if (resultado == numeroLinhaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de linhas passado pelo programa invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-linhas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
 
	if (resultado == numeroColunaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de colunas passado pelo programa invalido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-colunas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

 	if (resultado == monitorNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar monitor nulo.\n", MONITOR_NULO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		exit (MONITOR_NULO);
	}
	
	/*DESENHANDO O POLIGONO NO  MONITOR*/ 
	resultado = DesenharPoligono (tempoEspera, numeroLinhas, numeroColunas, numeroVertices, linhasVertices, colunasVertices);
	
	if (resultado == numeroLinhaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de linhas passado pelo programa invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-linhas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
 
	if (resultado == numeroColunaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de colunas passado pelo programa invalido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-colunas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

 	if (resultado == monitorNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar monitor nulo.\n", MONITOR_NULO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		exit (MONITOR_NULO);
	}
	
	
	/*EXECUCAO COM POLIGONO NO MONITOR*/
	printf ("Monitor com reta: \n");
	resultado = MostrarMonitor (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
	
	resultado = PreencherPoligono (tempoEspera, numeroLinhas, numeroColunas, percentualDefeituosos, percentualApagados linhaPonto, colunaPonto, numeroVertices, linhasVertices, colunasVertices);
	
	
	
	if (resultado == numeroLinhaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de linhas passado pelo programa invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-linhas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
 
	if (resultado == numeroColunaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de colunas passado pelo programa invalido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		printf ("Uso: <numero-de-colunas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

 	if (resultado == monitorNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar monitor nulo.\n", MONITOR_NULO);
		printf ("Uso: %s  <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\
					<numero-vertices> <linha-vertice-1> <coluna-vertice-1> <linha-vertice-2> <coluna-vertice-2> . . . \
					<linha-vertice-N> <coluna-vertice-N>\n\n", argv[0]);
		exit (MONITOR_NULO);
	}
	
	return OK;
}

/* $RCSfile: aula0705.c,v $ */
