/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da DecodificarBase16.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/16 01:55:55 $
 * $Log: aula0803.c,v $
 * Revision 1.1  2022/02/16 01:55:55  cleyton.moreira
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


/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"


/* Definicoes das macros */
#define NUMERO_DE_ARGUMENTOS			2

int
main (int argc, char *argv[]) 
{
	unsigned indiceDigito;
	char * entradaBase16;
	byte *vetorArgumentos;
	tipoErros resultado;
	ull *numeroBytes, tamanhoBytes = 0;
	
	numeroBytes = &tamanhoBytes;
	
		if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS);
		printf ("Uso: %s <string-codificada-base16>\n\n\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS);
	}
	for (indiceDigito = 1; indiceDigito < argc; indiceDigito++)
	{
		if (argv[indiceDigito][0] == '-')
		{
			printf ("\n\n\nErro #%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Caractere Invalido: '-'\n\n");
			printf ("Uso: %s <string-codificada-base16>\n\n\n", argv[0]);
			exit (ARGUMENTO_INVALIDO);
		}
	}
	
	tamanhoBytes = strlen(argv[1]);
	
	numeroBytes [0] = (ull) (tamanhoBytes/2);
	
	vetorArgumentos = (byte *)  malloc (sizeof(byte) * numeroBytes[0]);
	
	if (vetorArgumentos == NULL)
	{
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <string-codificada-base16>\n\n\n", argv[0]);
		exit (MEMORIA_INSUFICIENTE);
	}
	
	entradaBase16 = (char *) malloc (sizeof(char) * (numeroBytes[0] * 2 + 1));
	
	if (entradaBase16 == NULL)
	{
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <string-codificada-base16>\n\n\n", argv[0]);
		exit (MEMORIA_INSUFICIENTE);
	}
	
	strcpy (entradaBase16, argv[1]);
	
	resultado = DecodificarBase16 (entradaBase16, vetorArgumentos, numeroBytes);
	
	
	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar Argumento Nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <numero-de-bytes> <primeiro-byte> <segundo-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (ARGUMENTO_NULO);
	}
	
	printf ("\n\n");
	
	for (indiceDigito = 0; indiceDigito < strlen(entradaBase16); indiceDigito+=2)
		printf ("%d ",vetorArgumentos [indiceDigito]);
			
	printf ("\n\n");
	
	free(vetorArgumentos);
	free(entradaBase16);
	
	return OK;

}
/* $RCSfile */
