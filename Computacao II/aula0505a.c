/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao:
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/01 00:45:00 $
 * $Log: aula0505a.c,v $
 * Revision 1.1  2022/02/01 00:45:00  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao de cabecalho da biblioteca padrao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <float.h>
#include <limits.h>


/* inclusao de cabecalho personalizado para este funcao */
#include "aula0504.h"

/* Definicao das macros */
#define NUMERO_DE_ARGUMENTOS 			2

/* Implementacao da funcao teste para a funcao GerarDigitosVerificadoresRg (char *) */
int
main (int argc, char *argv[])
{
	char registroGeral [10];
	char digitoVerificador;
	ush indiceDigito, posicaoArgumento = 0,  indiceArgumento = 0;
	tipoErros resultado;
	
	/* Verificacao dos argumentos passados pela CLI */
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado pela CLI invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	/* Tratamento do comprimento do argumento passado para o programa */
	if (strlen(argv[1]) != 10)
	{
		printf ("\n\n\nErro #%i: Quantidade de argumentos passado pela CLI invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	/* Verificando o modelo de formatcao da entrada dos argumentos. */
	for (indiceDigito = 0; indiceDigito < RG_COM_DIGITO_VERIFICADOR_COM_HIFEN; indiceDigito++)
	{
		if ((argv[1][indiceDigito] > '9') || (argv[1][indiceDigito] < '0'))
		{
			if ((argv[1][indiceDigito] != '.') || (argv[1][indiceDigito] != '-'))
			{
				printf ("\n\n\nErro #%i: Os argumentos nao contem os pontos nos devidos lugares.\n", ARGUMENTO_INVALIDO);
				printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			else
			{
				indiceDigito++;
				indiceArgumento = (argv[1][indiceDigito] - '0');
			}
		}
		else
		{
			indiceArgumento = (argv[1][indiceDigito] - '0');

			if (indiceArgumento > 255)
			{
				printf ("\n\n\nErro #%i: Argumento excede a capacidade maxima.\n", COMPRIMENTO_INVALIDO);
				printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n", argv[0]);
				exit (COMPRIMENTO_INVALIDO);
			}
		}
		registroGeral [posicaoArgumento] = indiceArgumento;
		posicaoArgumento++;
	}
	registroGeral [posicaoArgumento + 1] = EOS;

	resultado = GerarDigitosVerificadoresRg (registroGeral, &digitoVerificador);

	if (resultado == argumentoNulo)
	{
		printf ("\n\n\nErro #%i: impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n\n", argv[0]);
		exit (ARGUMENTO_NULO);
	}
	
	if (resultado == argumentoVazio)
	{
		printf ("\n\n\nErro #%i: impossivel passar argumento vazio.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <d1d2.d3d4d5.d6d7d8>\n\n", argv[0]);
		exit (ARGUMENTO_VAZIO);
	}
	
	
	printf ("\n\nRG: %s%c\n", registroGeral, digitoVerificador); 

	return OK;
}
/* $RCSfile: aula0505a.c,v $ */
