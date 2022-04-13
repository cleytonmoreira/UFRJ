/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Tamanhos em bytes das combinacoes validas entre modificadores de sinal 
 * 		e modificadores de largura, entre tipos basicos e modificadores de sinal, 
 * 		entre tipos basicos e modificadores de largura e entre tipos basicos, 
 * 		modificadores de sinal e modificadores de largura.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/02 05:07:36 $
 * $Log: aula0103.c,v $
 * Revision 1.1  2021/12/02 05:07:36  cleyton.moreira
 * Initial revision
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>

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
	printf ("\n\n");
	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Modificadores de Sinal combinados com Modificadores de Largura\n\n");
	printf ("\n\n");
	printf ("signed short:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed short), 
			sizeof(signed short) == 1 ? "byte" : "bytes");
	printf ("signed long:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed long), 
			sizeof(signed long) == 1 ? "byte" : "bytes");
	printf ("signed long long:\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed long long), 
			sizeof(signed long long) == 1 ? "byte" : "bytes");
	printf ("unsigned short:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed short), 
			sizeof(signed short) == 1 ? "byte" : "bytes");
	printf ("unssigned long:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed long), 
			sizeof(signed long) == 1 ? "byte" : "bytes");
	printf ("unsigned short:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n\n\n", (long unsigned) sizeof(signed long long), 
			sizeof(signed long long) == 1 ? "byte" : "bytes");

	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal\n\n");
	printf ("Combinacoes Validas\n\n");
	printf ("signed char: \t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof (signed char), sizeof (signed char) > 1 ? "bytes" : "byte");
	printf ("unsigned char:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(unsigned char), sizeof (unsigned char) > 1 ? "bytes" : "byte");
	printf ("signed int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed int), sizeof (signed int) > 1 ? "bytes" : "byte");
	printf ("unsigned int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n\n\n", (long unsigned) sizeof(unsigned int), sizeof (unsigned int) > 1 ? "bytes" : "byte");
	printf ("Combinacoes invalidas\n\n\n");
	printf ("signed float\n");
	printf ("unsigned float\n");
	printf ("signed double\n");
	printf ("unsigned double\n");
	printf ("signed void\n");
	printf ("unsigned void\n\n");

	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Largura\n\n");
	printf ("Combinacoes Validas\n\n");
	printf ("short int:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (short int),sizeof (short int) > 1 ? "bytes" : "byte");
	printf ("long int:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (long int), 	sizeof (long int) > 1 ? "bytes" : "byte");
	printf ("long long int:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (long long int), sizeof (long long int) > 1 ? "bytes" : "byte");
	printf ("long double:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (short int), sizeof (short int) > 1 ? "bytes" : "byte");
	printf ("Combinacoes Invalidas\n\n");
	printf ("short char\n");
	printf ("long char\n");
	printf ("long long char\n");
	printf ("short float\n");
	printf ("long float\n");
	printf ("long long float\n");
	printf ("short double\n");
	printf ("long long double\n");
	printf ("short void\n");
	printf ("long void\n");
	printf ("long long void\n");

	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Basicos combinados com Modificadores de Sinal\n\n");
	printf ("Combinacoes Validas\n\n");
	printf ("signed char:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (signed char), sizeof (signed char) > 1 ? "bytes" : "byte");
	printf ("unsigned char:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (unsigned char),sizeof (unsigned char) > 1 ? "bytes" : "byte");
	printf ("signed int:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n", (long unsigned) sizeof (signed int), sizeof (signed int) > 1 ? "bytes" : "byte");
	printf ("unsigned int:\t\t\t\t\t\t\t\t\t\t\t %lu %s\n\n\n", (long unsigned) sizeof (unsigned int), sizeof (signed char) > 1 ? "bytes" : "byte");
	printf ("Combinacoes Invalidas\n\n");
	printf ("signed float\n");
	printf ("unsigned float\n");
	printf ("signed double\n");
	printf ("unsigned double\n");
	printf ("signed void\n");
	printf ("unsigned void\n");
	printf ("\n\n");

	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Básicos combinados com Modificadores de Sinal\n");
	printf ("signed char:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed char), sizeof(signed char) > 1 ? "bytes" : "byte");
	printf ("signed int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(signed int), sizeof(signed int) > 1 ? "bytes" : "byte");
	printf ("unsigned  char:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(unsigned char), sizeof(unsigned char) > 1 ? "bytes" : "byte");
	printf ("unsigned  int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n\n\n", (long unsigned) sizeof(unsigned int), sizeof(unsigned int) > 1 ? "bytes" : "byte");
	
	
	for (contador = 0; contador <= NUMERO_DE_HIFENS; contador++)
		printf ("-");
	printf ("\n\n");
	printf ("Tamanhos dos Tipos Básicos combinados com Modificadores e Largura\n");
	printf ("long int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(long int), sizeof(long int) > 1 ? "byte" : "bytes");
	printf ("long double:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(long double), sizeof(long double) > 1 ? "byte" : "bytes");
	printf ("short int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(short int), sizeof(short int) > 1 ? "byte" : "bytes");
	printf ("long long int:\t\t\t\t\t\t\t\t\t\t\t%lu %s\n", (long unsigned) sizeof(long long int), sizeof(long long int) > 1 ? "byte" : "bytes");
	printf ("\n\n\n");
	return OK;
}
/* $RCSfile: aula0103.c,v $ */
