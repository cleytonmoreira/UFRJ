/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de cabecalho da funcao Algoritmo de preenchimento.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/13 23:37:46 $
 * $Log: aula0701.h,v $
 * Revision 1.2  2022/02/13 23:37:46  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/08 00:51:41  cleyton.moreira
 * Initial revision
 *
 *
 */


#ifdef __linux__
#define _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED;
#endif


#include <sys/types.h>
#include <unistd.h>

#ifdef __linux__
typedef __useconds_t useconds_t;
#endif


#ifndef _AULA0701_
#define _AULA0701_ 	"@(#)aula0701.h $Revision: 1.2 $"

/* DEFINICOES DAS MACROS */
#define NUMERO_MAXIMO_LINHAS			250
#define NUMERO_MAXIMO_COLUNAS			800
#define APAGADO					' '
#define ACESO					'O'
#define DEFEITUOSO				'.'
#define TEMPO_MAXIMO_DE_ATRASO 			1000
#define CONSTANTE_DE_ATRASO 			1000
#define EOS 					'\0'

/* DEFINICAO DAS MACROS DE RETORNO */
#define OK 					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO			2
#define COMPRIMENTO_INVALIDO			3
#define BASE_INVALIDA				4
#define ERRO_NA_FUNCAO				5
#define NUMERO_DE_LINHAS_INVALIDO		6
#define NUMERO_DE_COLUNAS_INVALIDO		7
#define MONITOR_NULO				8
#define PERCENTUAL_DEFEITUOSOS_INVALIDO		9
#define PERCENTUAL_APAGADOS_INVALIDO		10
#define NUMERO_DE_VERTICES_INVALIDO		11



typedef unsigned short ush;

typedef unsigned int useconds_t;

typedef enum
{
	ok,
	numeroLinhaInvalido,
	numeroColunaInvalido,
	numeroDefeituososInvalido,
	numeroApagadosInvalido,
	numeroPercentualInvalido,
	digitoInvalido,
	monitorNulo,
	pixelDefeituoso
} tipoErros;

typedef enum
{
	apagado,
	aceso,
	defeituoso = -1
} tipoPixel;

/* Prototipo da funcao MostrarMonitor */
tipoErros
MostrarMonitor (useconds_t tempoEspera, /* (E) */
		tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* (E) */
		unsigned numeroMaximoLinhas, /* (E) */
		unsigned numeroMaximoColunas); /* (E) */

/* Prototipo da funcao DistriuicaoInicial */
tipoErros
GerarDistribuicaoInicial (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
				unsigned numeroMaximoLinhas, /* E */
				unsigned numeroMaximoColunas, /* E */
				float percentualDefeituoso, /* E */
				float percentualApagado/* E */);


/* Prototipo da funcao LimparMonitor */
tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
		unsigned numeroMaximoLinhas, /* E*/
		unsigned numeroMaximoColunas); /* E */


/* Prototipo da funcao DesenharReta */
tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS] /* E/S */,
		unsigned numeroMaximoLinhas /* E */,
		unsigned numeroMaximoColunas /* E */,
		unsigned linhaA, /* E */
		unsigned colunaA, /* E */
		unsigned linhaB, /* E */
		unsigned colunaB);/* E */


/* Prototipo da funcao DesenharPoligono */
tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS] /* E */,
			unsigned numeroMaximoLinhas /* E */,
			unsigned numeroMaximoColunas /* E */,
			unsigned numeroVertice /* E */,
			unsigned linhasVertices [NUMERO_MAXIMO_LINHAS], /* E */
			unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS] /* E */);



/* Prototipo da funcao PreencherPoligono */
tipoErros
PreencherPoligono (useconds_t tempoEspera, /* E */
			tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
			unsigned numeroMaximoLinhas, /* E */
			unsigned numeroMaximoColunas, /* E */
			unsigned linha, /* E */
			unsigned coluna /* E */);


#endif

/* $RCSfile: aula0701.h,v $ */
