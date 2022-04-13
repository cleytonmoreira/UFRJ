/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - ComputacaoII - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa para realizacao de testes da funcao LimparMonitor e MostrarMonitor.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/08 02:38:08 $
 * $Log: aula0703.c,v $
 * Revision 1.1  2022/02/08 02:38:08  cleyton.moreira
 * Initial revision
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
#define NUMERO_DE_ARGUMENTOS 				6

int 
main (int argc, char *argv[]) 
{

	ush indiceArgumento;
	unsigned numeroMaximoLinhas, numeroMaximoColunas;
	unsigned int tempoEspera;
	unsigned int argumento1;
	float argumento2;
	float percentualApagados, percentualDefeituosos;
	tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	char *validacao;
	tipoErros resultado;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{	
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
 
	for (indiceArgumento = 1; indiceArgumento < NUMERO_DE_ARGUMENTOS; indiceArgumento++)
	{
		argumento1 = strtod (argv[indiceArgumento], &validacao);
		if (errno == EINVAL)
		{
			printf ("\n\n\nErro #%i: Argumento passado com base invalida.\n", BASE_INVALIDA);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		       exit (BASE_INVALIDA);
		}
		if (errno == ERANGE)
		{
			printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido pela baseo.\n", BASE_INVALIDA);
		      	printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		 	exit (BASE_INVALIDA);
		}
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("caractere invalido: '%c'\n", *validacao);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		       exit (ARGUMENTO_INVALIDO);
		}
		if (indiceArgumento == 1)
		{
			tempoEspera = (unsigned int) argumento1;
			if ((tempoEspera < 0) || (tempoEspera > TEMPO_MAXIMO_DE_ATRASO))
			{
				printf ("\n\n\nErro #%i: Tempo de espera do programa indiferente do tempo esperado.\n", ARGUMENTO_INVALIDO);
				printf ("Tempo de espera permitido: 0 a 1000 us\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
			       	exit (ARGUMENTO_INVALIDO);
			}
		}
		if (indiceArgumento == 2)
		{
			numeroMaximoLinhas = (unsigned) argumento1;
			if ((numeroMaximoLinhas < 0) || (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS))
			{
				printf ("\n\n\nErro #%i: Numero de linhas do programa indiferente da quantidade esperada.\n", ARGUMENTO_INVALIDO);
				printf ("Numero de linhas permitido: 0 a 250 us\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		       	exit (ARGUMENTO_INVALIDO);
			}
		}
		if (indiceArgumento == 3)
		{
			numeroMaximoColunas = (unsigned) argumento1;
			if ((numeroMaximoColunas < 0) || (numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS))
			{
				printf ("\n\n\nErro #%i: Numero de colunas do programa indiferente da quantidade esperada.\n", ARGUMENTO_INVALIDO);
				printf ("Numero de colunas permitido: 0 a 250 us\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
	        	exit (ARGUMENTO_INVALIDO);
			}
		}
	}
	
	for (indiceArgumento = 4; indiceArgumento < NUMERO_DE_ARGUMENTOS; indiceArgumento++)
	{
		argumento2 = strtof (argv[indiceArgumento], &validacao);
		if (errno == EINVAL)
		{
			printf ("\n\n\nErro #%i: Argumento passado com base invalida.\n", BASE_INVALIDA);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
	        exit (BASE_INVALIDA);
		}
	        if (errno == ERANGE)
		{
			printf ("\n\n\nErro #%i: Argumento excedeu o valor permitido pela baseo.\n", BASE_INVALIDA);
		       	printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
	        exit (BASE_INVALIDA);
		}
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("caractere invalido: '%c'\n", *validacao);
			printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		        exit (ARGUMENTO_INVALIDO);
		}
		if (indiceArgumento == 4)
		{
			percentualDefeituosos = (float) argumento2;
			if ((percentualDefeituosos < 0) || (percentualDefeituosos > 100))
			{
				printf ("\n\n\nErro #%i: Quantidade de percentual de defeituosos invalido.\n", PERCENTUAL_DEFEITUOSOS_INVALIDO);
				printf ("Percentual valido: 0 <= pD <= 100.\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
	        	exit (ARGUMENTO_INVALIDO);
			}
		}
		if (indiceArgumento == 5)
		{
			percentualApagados = (float) argumento2;
			if ((percentualApagados < 0) || (percentualApagados > 100))
			{
				printf ("\n\n\nErro #%i: Quantidade de percentual de apagados invalido.\n", PERCENTUAL_APAGADOS_INVALIDO);
				printf ("Percentual valido: 0 <= pD <= 100.\n");
				printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
	        	exit (ARGUMENTO_INVALIDO);
			}
		}
	}
	resultado = GerarDistribuicaoInicial (monitor, numeroMaximoLinhas, numeroMaximoColunas, percentualDefeituosos, percentualApagados);

 	if(resultado == numeroLinhaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de linhas passado pelo programa invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		printf ("Uso: <numero-de-linhas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
 
	if(resultado == numeroColunaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de colunas passado pelo programa invalido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		printf ("Uso: <numero-de-colunas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

 	if(resultado == monitorNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar monitor nulo.\n", MONITOR_NULO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		exit (MONITOR_NULO);
	}

	resultado = MostrarMonitor (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
	
 	if(resultado == numeroLinhaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de linhas passado pelo programa invalido.\n", NUMERO_DE_LINHAS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		printf ("Uso: <numero-de-linhas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_LINHAS_INVALIDO);
	}
 
	if(resultado == numeroColunaInvalido)
	{
		printf ("\n\n\nErro #%i: Numero de colunas passado pelo programa invalido.\n", NUMERO_DE_COLUNAS_INVALIDO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		printf ("Uso: <numero-de-colunas-(inteiro-sem-sinal)\n\n");
		exit (NUMERO_DE_COLUNAS_INVALIDO);
	}

 	if(resultado == monitorNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar monitor nulo.\n", MONITOR_NULO);
		printf ("Uso: %s <tempo-congelamento> <numero-linhas> <numero-colunas> <percentual-defeituosos> <percentual-apagados>\n\n", argv[0]);
		exit (MONITOR_NULO);
	}

	resultado = LimparMonitor (monitor, numeroMaximoLinhas, numeroMaximoColunas);
	
	resultado = MostrarMonitor (tempoEspera, monitor, numeroMaximoLinhas, numeroMaximoColunas);
	
	return OK;
}
 /* $RCSfile $ */
