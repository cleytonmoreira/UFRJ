/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa de testes para a funcao ConverterArquivoFormatoDosParaFormatoUnix.
 * 
 * $Author: cleyton.moreira $
 * $Date: 2022/02/25 13:32:17 $
 * $Log: aula0903.c,v $
 * Revision 1.1  2022/02/25 13:32:17  cleyton.moreira
 * Initial revision
 *
 *
 *
 */

/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0901.h"

/* Macros de Retorno */
#define NUMERO_DE_ARGUMENTOS					2

int
main (int argc, char *argv[]) 
{
	unsigned indiceDados, tamanhoString;
	char local = 0;
	char *nomeArquivo = &local, *arquivoConvertido = &local;
	tipoErros resultado;
	
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	for (indiceDados = 1; indiceDados < argc; indiceDados++)
	{
		if(argv[indiceDados][0] == '/' || argv[indiceDados][0] == ':'|| argv[indiceDados][0] == '*'\
		|| argv[indiceDados][0] == '"' || argv[indiceDados][0] == '<' || argv[indiceDados][0] == '>')
		{
			printf ("\n\n\nErro #%i: Nome do arquivo contem caractere invalido.\n", CARACTERE_INVALIDO);
			printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
			exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
		}
	}
	
	tamanhoString = strlen (argv[1]);

	nomeArquivo = (char *) malloc (sizeof (char) * tamanhoString);
	
	arquivoConvertido = (char *) malloc ((sizeof (char) * tamanhoString));

	if (!nomeArquivo)
	{
		printf ("\n\nErro #%i: Memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (MEMORIA_INSUFICIENTE);
	}
	
	strcpy (nomeArquivo,argv[1]);
	
	if (!argv[2])
	{	
		strcpy (arquivoConvertido, argv[2]);	
	}
	
	else
	{
		strcpy (arquivoConvertido, "");
	}

	resultado = ConverterArquivoFormatoUnixParaFormatoDos (nomeArquivo, arquivoConvertido);
	
	if (resultado == arquivoInexistente)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento inexistente.\n", ARQUIVO_INEXISTENTE);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (ARQUIVO_INEXISTENTE);
	}
	if (resultado == arquivoVazio)
	{
		printf ("\n\nErro #%i: O arquivo esta vazio.\n", ARQUIVO_VAZIO);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (ARQUIVO_VAZIO);
	}
	if (resultado == memoriaInsuficiente)
	{
		printf ("\n\nErro #%i: Memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (ARQUIVO_VAZIO);
	}
	if (resultado != ok)
	{
		printf ("\n\nErro #%i: Funcao gerou erro inesperado.\n", ERRO_NA_FUNCAO);
		printf ("Uso: %s <o-nome-do-arquivo-desejado>\n", argv[0]);
		exit (ERRO_NA_FUNCAO);
	}

	free (nomeArquivo);
	
	return OK;
}
