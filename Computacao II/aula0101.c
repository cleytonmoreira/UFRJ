/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Codigo-Fonte de um programa que recebe um nome\
 * 	que possa conter caracteres de espaco e o maximo de 50 caracteres.
 *
 * $Author: cleyton.moreira $
 * $Date: 2021/12/01 02:22:07 $
 * $Log: aula0101.c,v $
 * Revision 1.1  2021/12/01 02:22:07  cleyton.moreira
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define NUMERO_DE_ARGUMENTOS			2
#define COMPRIMENTO_MAXIMO_DO_NOME		50
#define NUMERO_DE_COLUNAS			80


int 
main (int argc, char *argv [])
{
	int comparador = 0;
	int contador = 0;
	int espacamento = 0;
	int comprimento = 0;

	printf ("\n");	
	if (argc != 2)
	{
		printf ("Uso: %s <nome>\n\n", argv [0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	comprimento = strlen (argv[1]);
	
	if (comprimento == 0 || comprimento > COMPRIMENTO_MAXIMO_DO_NOME)
	{
		printf ("Comprimento excede o valor maximo permitido.\n\n");
		exit (COMPRIMENTO_MAXIMO_DO_NOME);
	}

	espacamento = (NUMERO_DE_COLUNAS - comprimento);

	while (comparador != 8)
	{
		for (contador = 0; contador < 10; contador++)
			printf ("%u", comparador);
		comparador++;
	}
	printf ("\n");
	
	comparador = 0;

	while (comparador != 8)
	{
		for (contador = 0; contador < 10; contador++)
			printf ("%u", contador);
		comparador++;
	}
	printf ("\n\n");
	
	for (contador = 0; contador < espacamento/2; contador++)
		printf (" ");

	printf ("\"%s\"", argv[1]);

	printf ("\n\n");
	for (contador = 0; contador <= NUMERO_DE_COLUNAS; contador++)
		printf ("-");
	
	printf ("\n\n");
	return OK;
}
/* $RCSfile: aula0101.c,v $ */
