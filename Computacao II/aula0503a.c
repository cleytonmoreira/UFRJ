/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao do programa teste para a funcao ValidarRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/31 03:37:31 $
 * $Log: aula0503a.c,v $
 * Revision 1.2  2022/01/31 03:37:31  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/21 00:39:44  cleyton.moreira
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 	1999
#define __LONG_LONG_SUPPORTED
#endif

/* Inclusao dos arquivos de cabecalho da biblioteca padrao */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Inclusao do arquivo de cabecalho personalizado para o programa */
#include "aula0501.h"

/* Definicao de macro */
#define NUMERO_DE_ARGUMENTOS			10

/* Implementacao do programa de testes da funcao GerarDigitosVerificadoresRg */

int
main (int argc, char *argv[])
{
	byte registroGeral [NUMERO_DE_ARGUMENTOS];
	ush indiceArgumento;
	tipoErros resultado;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\nErro #%i: Quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <DV>\n\n\n", argv[0]);
		printf ("Sabendo: digito Verificador variando entre 0 a 9 ou 'X'\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	for (indiceArgumento = 1; indiceArgumento <= RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceArgumento++)
	{
			if (argv[indiceArgumento][0] == '-')
			{
				printf ("\n\nErro #%i: Os argumentos contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Primeira Ocorrencia: argumento #%hu (%s).\n", indiceArgumento, argv[indiceArgumento]);
				printf ("Caractere Invalido: '-'.\n");
				printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8> <DV>\n\n\n", argv [0]);
				printf ("Sabendo: digito Verificador variando entre 0 a 9 ou 'X'\n");
				exit (ARGUMENTO_INVALIDO);
			}
			if (indiceArgumento != (NUMERO_DE_ARGUMENTOS - 1))
			{
				if ((argv[indiceArgumento][0] > '9') || (argv[indiceArgumento][0] < '0'))
				{
					printf ("\n\nErro #%i: Impossivel passar argumentos com dois ou mais algarismos.\n", DIGITO_INVALIDO);
					printf ("Primeira ocorrencia: Argumento #%hu (%s).\n", indiceArgumento, argv[indiceArgumento]);
					printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8> <DV>\n\n\n", argv [0]);
					printf ("Sabendo: digito Verificador variando entre 0 a 9 ou 'X'\n");
					exit (DIGITO_INVALIDO);
				}
				registroGeral [indiceArgumento - 1] = (byte) (argv[indiceArgumento][0] - '0');
			}
			else
			{
				if (argv[indiceArgumento][0] != 'X')
					registroGeral [indiceArgumento - 1] = (byte)(argv[indiceArgumento][0] - '0');
				else
					registroGeral [indiceArgumento - 1] = (byte) ('X');
			}
	}
	registroGeral[indiceArgumento] = EOS;

	resultado = ValidarRg (registroGeral);

	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
		printf ("Sabendo: digito Verificador variando entre 0 a 9 ou 'X'\n");
		exit (ARGUMENTO_NULO);
	}
	
	if (resultado == argumentoVazio)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento vazio.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
		printf ("Sabendo: digito Verificador variando entre 0 a 9 ou 'X'\n");
		exit (ARGUMENTO_VAZIO);
	}

	/* Exibicao do resultado na tela. */
	printf ("\n\n\n");
	printf ("RG: ");
	printf ("%hhu", registroGeral[0]);
	printf ("%hhu", registroGeral[1]);
	printf (".");
	printf ("%hhu", registroGeral[2]);
	printf ("%hhu", registroGeral[3]);
	printf ("%hhu", registroGeral[4]);
	printf (".");
	printf ("%hhu", registroGeral[5]);
	printf ("%hhu", registroGeral[6]);
	printf ("%hhu", registroGeral[7]);
	printf ("-");
	if (registroGeral[8] == 88)
	{
		if (resultado == valido)
			printf ("X - valido");
		else
			printf ("X - invalido");
	}
	else
	{
		if (resultado == valido)
			printf ("%hhu - valido", registroGeral[8]);
		else
			printf ("%hhu - invalido", registroGeral[8]);
	}
	printf ("\n\n\n");
	return OK;
}
/* $RCSfile $ */
