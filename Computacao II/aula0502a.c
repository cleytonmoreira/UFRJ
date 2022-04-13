/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Implementacao do programa teste para a funcao GerarDigitosVerificadoresRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/17 02:52:35 $
 * $Log: aula0502a.c,v $
 * Revision 1.2  2022/01/17 02:52:35  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/12 04:52:23  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivos de cabecalho da biblioteca padrao */
#include <stdio.h>
#include <stdlib.h>

/* Inclusao do arquivo de cabecalho personalizado para o programa */
#include "aula0501.h"

/* Definicao de macro */
#define NUMERO_DE_ARGUMENTOS			9

/* Implementacao do programa de testes da funcao GerarDigitosVerificadoresRg */

int
main (int argc, char *argv[])
{
	byte registroGeral [RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN];
	char *validacao;
	ush indiceArgumento;
	tipoErros resultado;
	ull valor;

	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\nErro #%i: Quantidade de argumentos invalida.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8>\n\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}

	for (indiceArgumento = 1; indiceArgumento <= RG_SEM_DIGITO_VERIFICADOR; indiceArgumento++)
	{
		if (argv[indiceArgumento][0] == '-')
		{
			printf ("\n\nErro #%i: Os argumentos contem um ou mais caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira Ocorrencia: argumento #%hu (%s).\n", indiceArgumento, argv[indiceArgumento]);
			printf ("Caractere Invalido: '-'.\n");
			printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d7> <d8>\n\n\n", argv [0]);
			exit (ARGUMENTO_INVALIDO);
		}

		valor = strtol(argv[indiceArgumento], &validacao, 10);
	
		if (*validacao != EOS)
		{
			printf ("\n\nErro #%i: Os argumentos contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira ocorrencia: Argumento #%hu (%s).\n", indiceArgumento, argv[indiceArgumento]);
			printf ("Caractere Invalido: '%c'.\n", *validacao);
			printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
			exit (ARGUMENTO_INVALIDO);
		}

		if (valor > 255)
		{
			printf ("\n\nErro #%i: Impossivel passar argumentos com dois ou mais algarismos.\n", DIGITO_INVALIDO);
			printf ("Primeira ocorrencia: Argumento #%hu (%llu).\n", indiceArgumento, valor);
			printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
			exit (DIGITO_INVALIDO);
		}

		registroGeral [indiceArgumento - 1] = (byte) valor;
	}
	registroGeral [indiceArgumento] = EOS;
	
	resultado = GerarDigitosVerificadoresRg (registroGeral);

	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
		exit (ARGUMENTO_NULO);
	}
	
	if (resultado == argumentoVazio)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento vazio.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
		exit (ARGUMENTO_VAZIO);
	}

	if (resultado == digitoInvalido)
		for (indiceArgumento = 1; indiceArgumento <= RG_SEM_DIGITO_VERIFICADOR; indiceArgumento++)
		{
			valor = strtol (argv[indiceArgumento], &validacao, 10);

			if (valor > 9)
			{
				printf ("\n\nErro #%i: Impossivel passar argumentos com dois ou mais digitos.\n", DIGITO_INVALIDO);
				printf ("Primeira Ocorrencia: argumento #%hu (%llu).\n", indiceArgumento, valor);
				printf ("Uso: %s <d1> <d2> <d3> <d4> <d5> <d6> <d6> <d7> <d8>\n\n\n", argv [0]);
				exit (DIGITO_INVALIDO);
			}
		}
	printf ("\n\n\n");
	
	for (indiceArgumento = 0; indiceArgumento < RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceArgumento++)
	{
		if (indiceArgumento == 0)
			printf ("RG: ");
		if ((indiceArgumento == 2)||(indiceArgumento == 5))
			printf (".");
		if (indiceArgumento == 8)
			printf ("-");
		if (registroGeral[indiceArgumento] == 23)
			printf ("X");
		else
			printf ("%hhu", registroGeral[indiceArgumento]);
	}
	printf ("\n\n\n");

	return OK;
}

/* $RCSfile: aula0502a.c,v $ */
