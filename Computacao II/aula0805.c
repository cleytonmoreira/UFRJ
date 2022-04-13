/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da DecodificarBase32.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/23 05:03:31 $
 * $Log: aula0805.c,v $
 * Revision 1.1  2022/02/23 05:03:31  cleyton.moreira
 * Initial revision
 *
 *
 */
 
#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

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
#define NUMERO_DE_ARGUMENTOS_INVALIDO			2

int 
main (int argc, char *argv[])
{
	ull numeroBytes[1];
	int tamanhoBytes;
	char *validacao;
	char *entradaBase32, *saidaHexadecimal;
	byte *saidaByte;
	tipoErros saida;
	ull indiceDigito, tipoAlfabeto, tipoAlfabeto32;
	
	if (argc != NUMERO_DE_ARGUMENTOS_INVALIDO)
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	tipoAlfabeto = (ull) strtoul (argv[1], &validacao, 10);

	if (errno == EINVAL)
	{
		printf ("\n\nErro #%i: Argumento esta na base invalida.\n", BASE_INVALIDA);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (errno == ERANGE)
	{
		printf ("\n\nErro #%i: Argumento excedeu o valor permitido para o tipo ull.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*validacao != EOS)
	{
		printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
		printf ("Primeira ocorrencia: argumento #1 (%s).\n", argv[2]);
		printf ("Caractere invalido: '%c'.\n", *validacao);
		pprintf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if ((tipoAlfabeto != '0') || (tipoAlfabeto != '1'))
	{
		printf ("\n\n\nErro #%i: Os argumentos contem um ou mais caracteres invalidos.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! Tipo do alfabeto <0 ou 1>\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	else
	{
		if (tipoAlfabeto == '0')
			tipoAlfabeto32 = basico;
		if (tipoAlfabeto == '1')
			tipoAlfabeto32 = estendido;
	}
	
	tamanhoBytes = strlen(argv[2]);
	
	entradaBase32 = (char *) malloc (sizeof(char[tamanhoBytes + 1]));
	
	if (entradaBase32 == NULL)
	{
		free (entrada);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	entradaBase32 = argv[2];
	
	saidaHexadecimal = (char *) malloc (sizeof(char[tamanhoBytes]));
	
	if (saidaHexadecimal == NULL)
	{
		free (saidaHexadecimal);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	saidaByte = (byte *) malloc (sizeof(char[tamanhoBytes]));
	
	if (saidaByte == NULL)
	{
		free (saidaByte);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <alfabeto-desejado> <string-codificada-base32>\n", argv[0]);
		printf ("Atencao! <0 ou 1> <sequencia-hexadecimal>\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	saida = DecodificarBase32 (entradaBase32, tipoAlfabeto32, saidaByte, numeroBytes);
	
	if (saida == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar Argumento Nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_NULO);
	}
	
	CodificarBase16 (saidaByte, numeroBytes [0], saidaHexadecimal);

	for (indiceDigito = 0; indiceDigito < (2 * (*numeroBytes)); indiceDigito+=2)
	{	
		printf ("%c%c ", saidaHexadecimal [indiceDigito], saidaHexadecimal [indiceDigito + 1]);
	}
	printf ("\n\n\n");
	
	free(saida);
	free(entradaBase32);
	
	return OK;

}

/* RCSfile$ */

 
