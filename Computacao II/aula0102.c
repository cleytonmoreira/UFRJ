/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Um programa que exibe os tamanhos basicos dos 5 tipos basicos, 
 * 		dos 2 modificadores de sinal e dos 3 modificadores de largura
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/02 05:07:36 $
 * $Log: aula0102.c,v $
 * Revision 1.1  2021/12/02 05:07:36  cleyton.moreira
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK				0
#define NUMERO_DE_ARGUMENTOS		1
#define NUMERO_DE_HIFENS		100

int
main (int argc, char *argv[])
{
	int contador;
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("Uso: %s", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS);
	}
	
	printf ("\n");
	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Basicos\n\n");
	printf ("void:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(void), sizeof(void) == 1 ? "byte" : "bytes");
	printf ("char:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(char), sizeof(char) == 1 ? "byte": "bytes");
	printf ("int:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(int), sizeof(int) == 1 ? "byte" : "bytes");
	printf ("float:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(float), sizeof(float) == 1 ? "byte" : "bytes");
	printf ("double:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(double), sizeof(double) == 1 ? "byte" : "bytes");
	printf ("\n");
	
	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Modificadores de Sinal\n\n");
	printf ("signed:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(signed), sizeof(signed) == 1 ? "byte" : "bytes");
	printf ("unsigned:\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(unsigned), sizeof(unsigned) == 1 ? "byte" : "bytes");
	printf ("\n");

	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanho dos Modificadores de Largura\n\n");
	printf ("short:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(short), sizeof(short) == 1 ? "byte" : "bytes");
	printf ("long:\t\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(long), sizeof(long) == 1 ? "byte" : "bytes");
	printf ("long long:\t\t\t\t\t\t\t\t\t\t     %lu %s\n", (long unsigned) sizeof(long long), sizeof(long long) == 1 ? "byte" : "bytes");
	printf ("\n");
	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n\n");
	return OK;
}
/* $RCSfile: aula0102.c,v $ */
