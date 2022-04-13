/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da CodificarBase16.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/21 05:18:06 $
 * $Log: aula0802.c,v $
 * Revision 1.3  2022/02/21 05:18:06  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/14 05:40:04  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/14 04:13:51  cleyton.moreira
 * Initial revision
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
#include <math.h>


/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"

/* Definicoes das macros */
#define NUMERO_DE_ARGUMENTOS_INVALIDO			3

int 
main (int argc, char *argv[])
{
	unsigned indiceArgumento;
	ull argumento, numeroBytes;
	byte *entrada;
	unsigned valorMaximoByte = 256;
	char *saida;
	char *validacao;
	tipoErros resultado;
	
	
	if ((argc < NUMERO_DE_ARGUMENTOS_INVALIDO) || (argc > NUMERO_MAXIMO_DE_ARGUMENTOS))
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	if (argv [1][0] == '-')
	{
		printf ("\n\nErro #%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Caractere Invalido: '-'\n\n");
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	numeroBytes = (ull) strtoul (argv[1], &validacao, 10);
	
	if (errno == EINVAL)
	{
		printf ("\n\nErro #%i: Argumento esta na base invalida.\n", BASE_INVALIDA);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)
	{
		printf ("\n\nErro #%i: Argumento excedeu o valor permitido para o tipo ull.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*validacao != EOS)
	{
		printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
		printf ("Primeira ocorrencia: argumento #1 (%s).\n", argv[1]);
		printf ("Caractere invalido: '%c'.\n", *validacao);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if ((numeroBytes != (argc - 2)) || (numeroBytes == 0))
	{
		printf ("\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	entrada = (byte *)  malloc (sizeof(byte) * numeroBytes);
	
	if(entrada == NULL)
	{
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	saida = (char *) malloc (sizeof(char) * (numeroBytes * 2 + 1));
	
	if(saida == NULL)
	{
		free (entrada);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	
	/* Verificacao dos argumentos passado pela CLI */
	for (indiceArgumento = 2; indiceArgumento < argc; indiceArgumento++)
	{
		if (argv[indiceArgumento][0] == '-')
		{
			printf ("\n\nErro #%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Caractere Invalido: '-'\n\n");
			printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
		
		argumento = strtoul (argv[indiceArgumento], &validacao, 10);
		
		if ((argumento < 0) || (argumento > valorMaximoByte))
		{
			printf ("\n\nErro #%i: Argumento excedeu o valor permitido para o tipo byte .\n", ARGUMENTO_INVALIDO);
			printf ("Argumento: 0 <= valor <= 255.\n\n");
			printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
			exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
		}
		entrada [indiceArgumento - 2] = (byte) argumento;
	}
	
	resultado = CodificarBase16 (entrada, numeroBytes, saida);
	
	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar Argumento Nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_NULO);
	}
	printf ("\n\n");
	for (indiceArgumento = 0; indiceArgumento < numeroBytes*2; indiceArgumento++)
	{
		printf ("%c", saida[indiceArgumento]);
	}
	printf ("\n\n");
	free (saida);
	free (entrada);	
	
	return OK;
}

/* $RCSfile */
