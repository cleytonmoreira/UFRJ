/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao funcao teste para a funcao CalcularDeterminanteMatriz.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/01 07:58:18 $
 * $Log: aula0604.c,v $
 * Revision 1.4  2022/02/01 07:58:18  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.3  2022/02/01 04:53:54  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/01 00:45:00  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/25 04:21:42  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivo de cabecalho para este problema. */
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <limits.h>

/* Inclusao do arquivo de cabecalho personalizado. */
#include "aula0601.h"

/* Macros do programa. */
#define NUMERO_MINIMO_DE_ARGUMENTOS 				3


int
main (int argc, char *argv[])
{
	ush contadorLinhas, contadorColunas, indice = 2;
	ush somaProdutos, indiceOrdem;
	unsigned long indiceArgumento;
	char *validacao;
	double matriz[100][100], *determinante;
	tipoErros resultado;
	double local;
	local = 0;
	determinante = &local;
		
	/* Verificando a quantidade minima de argumentos passado pela CLI. */
	if (argc < NUMERO_MINIMO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <ordem-da-matriz> <a11> <a12> ...\n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	/* Verificacao do valor contem hifen. */
	if (argv[1][0] == '-')
	{
			printf ("\n\n\nErro #%i: Impossivel a passagem de argumento negativo, para o valor da Ordem.\n", ARGUMENTO_INVALIDO);
			printf ("Uso: %s <numero-inteiro-sem-sinal>  <a11> <a12> ... \n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
	}
	
	indiceArgumento = (unsigned short) strtod (argv[1], &validacao);
	
	/* Verificacao do tamanho do argumento */
	if (errno == EINVAL)
	{
		printf ("\n\n\nErro #%i: Argumento do numero de Ordem invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)
	{
		printf ("\n\n\nErro #%i: Argumento do numero de Ordem excedeu o valor permitido.\n", ARGUMENTO_INVALIDO);
		printf ("Valor maximo permitido (%lu) pela funcao foi excedido.\n", ULONG_MAX);
		printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	/* Verificacao do numero de argumentos */
	if (*validacao != EOS)
	{
		printf ("\n\n\nErro #%i: Argumento contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Primeiro Caractere: '%c'.\n", *validacao);
		printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (indiceArgumento > USHRT_MAX)
	{
		printf ("\n\n\nErro #%i: Argumento excede o valor permitido.\n", ARGUMENTO_INVALIDO);
		printf ("Entrada excede o valor permitido para o tipo \"unsigned short\" (%hu).\n", (unsigned short) USHRT_MAX);
		printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}

	indiceOrdem = (ush) indiceArgumento;
	
	somaProdutos = ((indiceOrdem * indiceOrdem) + 2);

	/* Verificacao do argumento da ordem da matriz. */
	if ((indiceOrdem <= 0) || (indiceOrdem > 100))
	{
		printf ("\n\n\nErro #%i: Impossivel passar Ordem da Matriz igual a zero ou maior que cem.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}
	
	/* Verificando a quantidade de argumentos passado para o programa. */
	if (argc != somaProdutos)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado para o programa invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <numero-da-ordem> <a11> <a12> ...\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	
	/* Preencher a matriz com os argumentos passado pela CLI. */
	for (contadorLinhas = 0; contadorLinhas < indiceOrdem; contadorLinhas++)
		for (contadorColunas = 0; contadorColunas < indiceOrdem; contadorColunas++)
		{
			matriz [contadorLinhas][contadorColunas] = strtod (argv[indice, &validacao);
			if (*validacao != EOS)
			{
				printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: <a%u%u> = %s\n", (contadorLinhas + 1), (contadorColunas + 1), argv[indice - 1]);
				printf ("caractere invalido: '%c'\n", *validacao);
				printf ("Uso: %s <numero-inteiro-sem-sinal> <a11> <a12> ... \n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == EINVAL)
			{
				printf ("Argumento esta na base invalida.\n\n");
				printf ("Uso: <numero-inteiro-sem-sinal(tipo-double)> <a11> <a12>...\n\n");
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("Valor ultrapassa o limite inferior ou superior do tipo double.\n\n");
				printf ("Valor maximo permitido (%lf) pela funcao foi excedido.\n", DBL_MAX);
				exit (ARGUMENTO_INVALIDO);
			}
			indice++;
		}
	
	
	/* Calculando o determinante */
	resultado = CalcularDeterminanteMatriz (indiceOrdem, matriz, determinante);

	if (resultado == argumentoNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: <indice-ordem> <a11> <a12>...<%i%i>\n\n", indiceOrdem, indiceOrdem);
		exit (ARGUMENTO_NULO);
	}
	if (resultado == argumentoInvalido)
	{
		printf ("\n\n\nErro #%i: Impossivel passar argumento invalido.\n", ARGUMENTO_NULO);
		printf ("Uso: <indice-ordem> <a11> <a12>...<%i%i> \n\n", indiceOrdem, indiceOrdem);
		exit (ARGUMENTO_NULO);
	}
	if (resultado != ok)
	{
		printf ("\n\n\nErro #%i: Funcao retornou erro.\n", ERRO_DE_MANIPULACAO_DE_MATRIZES);
		printf ("Uso: <indice-ordem> <a11> <a12>...<%i%i> \n\n", indiceOrdem, indiceOrdem);
		exit (ERRO_DE_MANIPULACAO_DE_MATRIZES);
	}
	
	/* Mostrar a matriz */	
	printf ("\nMatriz:\n");
	MostrarMatriz (indiceOrdem, indiceOrdem, matriz);

	printf ("\nDeterminante: %.5f\n\n\n", *determinante);

	return OK;
}
/* $RCSfile: aula0604.c,v $ */
