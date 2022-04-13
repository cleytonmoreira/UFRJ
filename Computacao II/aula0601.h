/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: arquivo de cabecalho da funcao Manipulacao de Matrizes
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/01 04:53:54 $
 * $Log: aula0601.h,v $
 * Revision 1.5  2022/02/01 04:53:54  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.4  2022/01/25 04:22:45  cleyton.moreira
 * *** empty log message ***
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

#ifndef _AULA06_
#define _AULA06_ "@(#)aula0601.h $Revision: 1.5 $"

/* DEFINICAO DAS MACROS */
#define NUMERO_DE_LINHAS_MAX 			100
#define NUMERO_DE_COLUNAS_MAX 			100
#define NUMERO_MAXIMO_DE_ARGUMENTOS		205
#define EOS 					'\0'

/* CODIGOS DE RETORNO */
#define OK 					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO 		1
#define ARGUMENTO_INVALIDO 			2
#define ARGUMENTO_NULO 				3
#define NUMERO_DE_LINHAS_INVALIDO		4
#define NUMERO_DE_COLUNAS_INVALIDO		5
#define ERRO_DE_MANIPULACAO_DE_MATRIZES 	6

typedef unsigned short ush;

typedef enum
{
	ok,
	argumentoNulo,
	argumentoInvalido = 1,
	argumentoFuncaoInvalido = -1,
	erroDeManipulacao
}tipoErros;

/* Prototipo da funcao MultiplicarMatrizes */
tipoErros
MultiplicarMatrizes (unsigned short, /* numero de linhas da matriz 1 (E) */
		     unsigned short, /*  numero de colunas da matriz 1 (E) */
	    	     unsigned short, /* numero de linhas da matriz 2 (E) */
	  	     unsigned short, /* numero de colunas da matriz 2 (E) */
		     double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz 1 (E) */ 
		     double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz 2 (E) */
		     double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX]); /* Matrizproduto (S) */


/* Prototipo da funcao ObterMatrizTransposta. */
tipoErros
ObterMatrizTransposta (unsigned short, /* numero de linhas (E) */
		       unsigned short, /* numero de colunas (E) */
		       double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz Original (E) */
		       double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX]); /* Matriz Transposta (S) */


/* Prototipo da funcao CalcularMenorComplementar. */
tipoErros
CalcularMenorComplementar (unsigned short, /* ordem da Matriz (E) */
			   unsigned short, /* linha do elemento (E) */
			   unsigned short, /* coluna do elemento (E) */
			   double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz (E) */
			   double *); /* menor complementar (S) */


/* Prototipo da funcao CalcularComplementoalgebrico. */
tipoErros
CalcularComplementoAlgebrico (unsigned short, /* Ordem da matriz (E) */
			      unsigned short, /* Linha do Elemento (E) */
			      unsigned short, /* Coluna do Elemento (E) */
			      double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz (E) */
			      double *); /* Complemento algebrico ou cofator */


/* Prototipo da funcao DeterminanteMatriz. */
tipoErros
CalcularDeterminanteMatriz (unsigned short, /* Ordem da Matriz (E) */
		    double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX], /* Matriz (E) */
	   	    double *); /* Determinante (S)*/


/* Prototipo da funcao */
void
MostrarMatriz (unsigned short, /* Numero de linhas */
	       unsigned short, /* numero de colunas */
	       double [NUMERO_DE_LINHAS_MAX][NUMERO_DE_COLUNAS_MAX]); /* Matriz */

#endif

/* $RCSfile: aula0601.h,v $ */
