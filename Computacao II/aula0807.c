/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de teste da Funcao da DecodificarBase64.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/23 05:03:31 $
 * $Log: aula0807.c,v $
 * Revision 1.1  2022/02/23 05:03:31  cleyton.moreira
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
#include <malloc_np.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"

/* Definicoes das macros */
#define NUMERO_DE_ARGUMENTOS_INVALIDO			2

int 
main (int argc, char *argv[])
{
	
	byte *vetorBytes;
	char *entradaBase64;
	unsigned indiceDigito;
	ull *numeroBytes, tamanhoBytes = 0;
	tipoErros resultado;
	tipoFinalLinha finalLinha;
	
	numeroBytes = &tamanhoBytes;
	
	if (argc < NUMERO_DE_ARGUMENTOS_INVALIDO)
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <tipo-final-de-linha> <string-codificada-base64>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	for (indiceDigito = 1; indiceDigito < argc; indiceDigito++)
	{
		if(argv[indiceDigito][0] == '-')
		{
			printf ("\n\n\nErro #%i: Argumento contem caractere invalido.\n", ARGUMENTO_INVALIDO);
			printf ("Caractere Invalido: '-'\n\n");
			printf ("Uso: %s <tipo-final-de-linha> <string-codificada-base64>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
			exit (ARGUMENTO_INVALIDO);
		}
	}	
	
	tamanhoBytes = (strlen(argv[2]));
	
	numeroBytes[0] = (ull) (tamanhoBytes / 2);
	
	vetorBytes = (byte *)(malloc (sizeof(byte) * numeroBytes[0]));
	
	if(!vetorBytes)
	{
		free (vetorBytes);
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-final-de-linha> <string-codificada-base64>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	entradaBase64 = (char *) (malloc(6*(sizeof(char)*(numeroBytes[0]))));
	
	if(!entradaBase64)
	{
		printf ("\n\nErro #%i: memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("Atencao! Os argumentos devem estar no formato <decimal-nao-negativo>.\n\n");
		exit (MEMORIA_INSUFICIENTE);
	}
	
	if(argv[1][0] == '0')
	{
		finalLinha = desabilitado;
	}
	else if (argv[1][0] == '1')
	{
		finalLinha = habilitado;
	}
	else
	{
		printf ("\n\n\nErro #%i: Passagem de argumento invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <tipo-final-de-linha> <numero-de-byte> <primeiro-byte> ... <enesimo-byte>\n", argv[0]);
		printf ("desabilitado - 0 ou habilitado - 1\n");
		printf ("Atencao! Os argumentos devem estar no formato decimal nao negativo.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	strcpy(entradaBase64,argv[2]);
	
	resultado = DecodificarBase64 (entradaBase64, finalLinha, vetorBytes, numeroBytes);
	
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
	
	for (indiceDigito = 0; indiceDigito < numeroBytes[0] ; indiceDigito++)
		printf ("%d ", vetorBytes[indiceDigito]);
	
	printf ("\n");
	
	free(vetorBytes);
	free(entradaBase64);
	
	return OK;
}
/* $RCSfile */
