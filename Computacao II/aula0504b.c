/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 *  Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao do programa de testes para a Funcao GerarDigitosVerificadoresRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/17 04:42:03 $
 * $Log: aula0502b.c,v $
 * Revision 1.1  2022/01/17 04:42:03  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao do comando necassario para a funcao strtoull. */

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
#include <limits.h>
#include <errno.h>
#include <string.h>

/* Inclusao do arquivo de cabecalho personalizado */
#include "aula0501.h"

/* Definicoes das Macros */
#define NUMERO_DE_ARGUMENTOS		2
#define EOS				'\0'

int
main (int argc, char **argv)
{
	byte registroGeral[RG_SEM_DIGITO_VERIFICADOR];
	ush indiceDigito, indiceArgumento = 0;
	int valor;
	tipoErros resultado;

	/* Tratamento da quantidade de argumentos passado pela CLI */
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Quantidade de Argumentos Invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	/* Tratamento para entrada de valor negativo */
	if (argv[1][0] == '-')
	{
		printf ("\n\n\nErro #%i: Argumento contem caractere Invalid.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
		exit (ARGUMENTO_INVALIDO);
	}

	/* Tratamento do comprimento do argumento passado para o programa */
	if (strlen(argv[1]) != RG_COM_DIGITO_VERIFICADOR_COM_HIFEN)
	{
		printf ("\n\n\nErro #%i: Comprimento do argumento Invalido.\n", COMPRIMENTO_INVALIDO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
		exit (COMPRIMENTO_INVALIDO);
	}
	
	/* Verificacao dos pontos entre os numeros. */
	for (indiceDigito = 0; indiceDigito < RG_COM_DIGITO_VERIFICADOR_COM_HIFEN; indiceDigito++)
	{
		if ((indiceDigito == 2) || (indiceDigito == 6))
		{
			if ((argv[1][indiceDigito] != '.') && (argv[1][indiceDigito] != '.'))
			{
				printf ("\n\n\nErro #%i: Argumento nao contem os pontos nos devidos lugares.\n", ARGUMENTO_INVALIDO);
				printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
		}
		else
		{
			valor = argv[1][indiceDigito] - '0';

			if (errno == EINVAL)
			{
				printf ("\n\n\nErro #%i: Entrada de argumento invalida.\n", ARGUMENTO_INVALIDO);
				printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			if (errno == ERANGE)
			{
				printf ("\n\n\nErro #%i: Impossivel passar argumento.\n", DIGITO_INVALIDO);
				printf ("Primeira Ocorrencia: Argumento #%hhu (%u).\n", indiceDigito, valor);
				printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
				exit (DIGITO_INVALIDO);
			}
			if ((valor > 9)||(valor < 0))
			{
				printf ("\n\n\nErro #%i: Argumento contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Caractere invalido: '%c'.\n", argv[1][indiceDigito]);
				printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
				exit (ARGUMENTO_INVALIDO);
			}
			else
			{
				registroGeral[indiceArgumento] = valor;
				indiceArgumento++;
			}

		}
	}
	
	resultado = GerarDigitosVerificadoresRg (registroGeral);

	if (resultado == argumentoVazio)
	{
		printf ("\n\n\nErro #%i: Impossivel passar argumento vazio.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
		exit (ARGUMENTO_VAZIO);
	}

	if (resultado == argumentoNulo)
	{
		printf ("\n\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>\n\n\n", argv[0]);
		exit (ARGUMENTO_NULO);
	}

	indiceArgumento = 0;
	printf ("\n\n");
	for (indiceDigito = 0; indiceDigito < RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceDigito++)
	{
		if (indiceDigito == 0)
			printf ("RG: ");
		if ((indiceDigito == 2)||(indiceDigito == 5))
			printf (".");
		if (indiceDigito == 8)
			printf("-");
		if (registroGeral[indiceDigito] == 23)
			printf ("X");
		else
			printf ("%hhu", registroGeral[indiceDigito]);
	}

	printf ("\n\n\n");
	return OK;
}
/* $RCSfile: aula0502b.c,v $ */
