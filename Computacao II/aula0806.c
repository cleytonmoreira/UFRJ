/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da CodificarBase64.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/23 05:03:31 $
 * $Log: aula0806.c,v $
 * Revision 1.1  2022/02/23 05:03:31  cleyton.moreira
 * Initial revision
 *
 *
 */
 
/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <malloc_np.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"

/* Definicoes das macros */
#define NUMERO_DE_ARGUMENTOS_INVALIDO			3

int 
main (int argc, char *argv[])
{
	byte *vetorBytes;
	char *saidaBase64;
	unsigned indiceDigito, indiceArgumentos;
	ull argumento, numeroBytes;
	char *validacao;	
	tipoFinalLinha finalLinha;
	tipoErros resultado;
	
	if (argc < NUMERO_DE_ARGUMENTOS_INVALIDO)
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	for (indiceArgumentos = 1; indiceArgumentos < NUMERO_DE_ARGUMENTOS_INVALIDO; indiceArgumentos++)
	{
		argumento = (ull) strtoul (argv[indiceArgumentos], &validacao, 10);
		
		if (errno == EINVAL)
		{
			printf ("\n\nErro #%i: Argumento na base invalida.\n", BASE_INVALIDA);
			printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
			exit (BASE_INVALIDA);
		}

		if (errno == ERANGE)
		{
			printf ("\n\nErro #%i: Argumento excedeu o valor permitido para o tipo ull.\n", ARGUMENTO_INVALIDO);
			printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}

		if (*validacao != EOS)
		{
			printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
			printf ("Primeira ocorrencia: argumento #1 (%s).\n", argv[2]);
			printf ("Caractere invalido: '%c'.\n", *validacao);
			printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
			printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
		
		if (indiceArgumentos == 1)
		{
			if ((argumento == 0) || (argumento == 1))
			{
				if (argumento == 0)
					finalLinha = desabilitado;
				if (argumento == 1)
					finalLinha = habilitado;
			}
			else
			{
				printf ("\n\nErro #%i: Argumento para o tipo final de linha invalido.\n", ARGUMENTO_INVALIDO);
				printf ("Tipo final de linha: Desabilitado - 0 ou Habilitado - 1.\n");
				printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
				printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
				exit (ARGUMENTO_INVALIDO);
			}
		}
		
		if (indiceArgumentos == 2)
		{
			if (argumento != (argc - NUMERO_DE_ARGUMENTOS_INVALIDO))
			{
				printf ("\n\n\nErro #%i: Quantidade de argumentos passado pela CLI para conversao invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
				printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
				printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
				exit (NUMERO_DE_ARGUMENTOS_INVALIDO);

			}
			else
				numeroBytes = argumento;
		}

	}		
	vetorBytes = (byte *) (malloc (sizeof(byte)*numeroBytes));
	
	if(vetorBytes == NULL)
	{
		free (vetorBytes);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	saidaBase64 = (char *) malloc (6*(sizeof(char)*(numeroBytes)));
	
	if(saidaBase64 == NULL)
	{
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	for (indiceDigito = 0 ; indiceDigito < numeroBytes; indiceDigito++)
	{
		vetorBytes[indiceDigito] = (byte) strtoul (argv[indiceDigito + 3], &validacao, 16);
	}
	
	resultado = CodificarBase64 (vetorBytes, numeroBytes, finalLinha, saidaBase64);
	
	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar Argumento vazio.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_VAZIO);
	}
	
	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar Argumento Nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_NULO);
	}
	
	for (indiceDigito = 0; indiceDigito < (numeroBytes * 3); indiceDigito++)
		printf ("%c",saidaBase64[indiceDigito]);	
	
	printf ("\n\n\n\n");
	
	free(vetorBytes);
	free(saidaBase64);
	
	return OK;
}
/* $RCSfile */
