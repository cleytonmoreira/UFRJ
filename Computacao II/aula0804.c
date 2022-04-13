/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da CodificarBase32.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/23 05:03:31 $
 * $Log: aula0804.c,v $
 * Revision 1.1  2022/02/23 05:03:31  cleyton.moreira
 * Initial revision
 *
 *
 *
 */
 
/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>


/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"


/* Definicoes das macros */
#define NUMERO_DE_ARGUMENTOS_INVALIDO			3


int 
main (int argc, char *argv[])
{
	
	ull numeroBytes, indiceDigito, indiceAuxiliar;
	char *vetorBytes;
	char *saida32;
	byte *entrada;
	char *validacao;
	tipoAlfabetoBase32 alfabetoDesejado;
	
	if ((argc < NUMERO_DE_ARGUMENTOS_INVALIDO) || (argc > NUMERO_MAXIMO_DE_ARGUMENTOS))
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	numeroBytes = (ull) strtoul (argv[2], &validacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("\n\nErro #%i: Argumento esta na base invalida.\n", BASE_INVALIDA);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)
	{
		printf ("\n\nErro #%i: Argumento excedeu o valor permitido para o tipo ull.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*validacao != EOS)
	{
		printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
		printf ("Primeira ocorrencia: argumento #1 (%s).\n", argv[2]);
		printf ("Caractere invalido: '%c'.\n", *validacao);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (numeroBytes != (argc - 3))
	{
		printf ("\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	entrada = (byte *) (malloc (sizeof(byte[numeroBytes + 1])));
	
	if(entrada == NULL)
	{
		free (entrada);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	for (indiceDigito = 3; indiceDigito < argc; indiceDigito++)
	{
		if (argv[indiceDigito][0] == '-')
		{
			printf ("\n\nErro #%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Caractere Invalido: '-'\n\n");
			printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		vetorBytes = strtol(argv[indiceDigito], &validacao, 16);

		if (errno == EINVAL)
		{
			printf ("\n\nErro #%i: Argumento esta na base invalida.\n", BASE_INVALIDA);
			printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
			
		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira ocorrencia: argumento #1 (%s).\n", argv[1]);
			printf ("Caractere invalido: '%c'.\n", *validacao);
			printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
		entrada [indiceDigito - 3] = vetorBytes;
	}
	
	saida32 = (char *) malloc (sizeof(char[2 * numeroBytes + 8]));
	
	if (saida32 == NULL)
	{
		free (entrada);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-alfabeto-desejado> <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	CodificarBase32 (entrada, numeroBytes, alfabetoDesejado, saida32);
	
	printf ("Base: %s\n\n", saida32);
	free(saida32);
	
	return OK;
}
/* $RCSfile */