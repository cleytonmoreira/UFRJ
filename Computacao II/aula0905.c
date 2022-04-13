/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa contendo o código fonte de um programa de testes para as funções 
 * 				ConverterArquivoFormatoUnixParaFormatoDos e ConverterArquivoFormatoDosParaFormatoUnix.
 * 
 * $Author$
 * $Date$
 * $Log$
 *
 */
 
 
/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0901.h"

/* Macros de Retorno */
#define NUMERO_MINIMO_DE_ARGUMENTOS					2
#define NUMERO_MAXIMO_DE_ARGUMENTOS					4


int
main (int argc, char *argv[]) 
{
	int opcaaCurta;
	char *opcoesCurtas = "dDhHsSuU";
	char nomeArquivo [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	char nomeArquivoDesejado [COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO + 1];
	tipoErros resultado;
	
	if ((argc < NUMERO_MINIMO_DE_ARGUMENTOS) || (argc > NUMERO_MAXIMO_DE_ARGUMENTOS))
	{
		printf ("\n\n\nErro #%i: Numero de argumentos invalido.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
		printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
		exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
	}
	
	memset (nomeArquivo, 0x00, COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1);
	memset (nomeArquivoDesejado, 0x00, COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO + 1);
	
	opterr = 0;
	
	while ((opcaoCurta = getopt (argc, argv, opcoesCurtas)) != -1)
	{
		switch (opcaoCurta) 
		{
			case 'd':
      		case 'D':
        	printf ("Opcao selecionada: DOS \n");
        			
			if (argc > 2)
			{
				if ((strlen (argv [optind]) > 0) && (strlen(argv[optind]) < COMPRIMENTO_MAXIMO_NOME_ARQUIVO))
				{
					strcpy (nomeArquivo,argv[optind]);
					if (argc > 3)
					{
						if ((strlen (argv[optind + 1]) > 0) && (strlen(argv[optind + 1]) < COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO)
						{
							strcpy (nomeArquivoDesejado, argv[optind + 1]);
						}
						else 
						{
							strcpy(nomeArquivoDesejado,"");
						}
					}
				}
			}
			else
			{
				printf ("\n\n\nErro #%i: O usuario deve digitar o nome do primeiro arquivo.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
				printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
				exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
			}
			
			if (strlen (nomeArquivo) > 0)
			{
				resultado = ConverterArquivoFormatoUnixParaFormatoDos (nomeArquivo, nomeArquivoDesejado);
      			
				if (resultado != ok)
				{
					printf ("\n\nErro #%i: Funcao gerou erro inesperado.\n", ERRO_NA_FUNCAO);
					printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
					exit (ERRO_NA_FUNCAO);
      			}
			}
			break;
			
			case 'h':
			case 'H':
			
				printf ("Opcao AJUDA selecionada\n\n");	
				printf ("Comandos:\n\n");
				printf ("- Para converter um arquivo texto do formato Unix para o formato Microsoft (DOS):\n");
				printf ("./aula0905 -d | -D <nomeArquivo> <nomeArquivoDesejado(opcional)>\n\n");
				printf ("- Para exibir informações de como usar o programa:\n");
				printf ("./aula0905 -h | -H \n\n");	
				printf ("- Para exibir conteúdo do arquivo:\n");
				printf ("./aula0905 -s | -S <nomeArquivo>\n\n");
				printf ("- Para converter um arquivo texto do formato Microsoft para o formato Unix:\n");
				printf ("./aula0905 -u | -U <nomeArquivo> <nomeArquivoDesejado(opcional)>\n\n");

			break;

			case 's':
			case 'S':
				
				printf ("Opcao EXIBIR selecionada\n");
				
				if (argc > 2)
				{
					if (strlen(argv[optind]) > 0 && strlen(argv[optind]) < COMPRIMENTO_MAXIMO_NOME_ARQUIVO)
					{
						strcpy(nomeArquivo,argv[optind]);
					}
				}
				
				else
				{
					printf ("\n\n\nErro #%i: O usuario deve digitar o nome do primeiro arquivo.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
					printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
					exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
				}

				if (strlen(nomeArquivo) > 0)
				{
					resultado = ExibirConteudoArquivo (nomeArquivo);
      					if (resultado != ok)
						{
							printf ("\n\nErro #%i: Funcao gerou erro inesperado.\n", ERRO_NA_FUNCAO);
							printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
							exit (ERRO_NA_FUNCAO);
      					}
				}
			break;

			case 'u':
      		case 'U':
        		printf ("Opcao UNIX selecionada\n");
       				
				if (argc > 2)
				{	
					if (strlen(argv[optind]) > 0 && strlen(argv[optind]) < COMPRIMENTO_MAXIMO_NOME_ARQUIVO)
					{
						strcpy(nomeArquivo,argv[optind]);
						
						if (argc > 3)
						{
							if (strlen(argv[optind + 1]) > 0 && strlen(argv[optind + 1]) < COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO)
							{
								strcpy(nomeArquivoDesejado,argv[optind + 1]);
							}

							else
							{
								strcpy(nomeArquivoDesejado,"");
							}
						}
					}
				} 
			
				else
				{
					printf ("\n\n\nErro #%i: O usuario deve digitar o nome do primeiro arquivo.\n", NUMERO_DE_ARGUMENTOS_INVALIDO);
					printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
					exit (NUMERO_DE_ARGUMENTOS_INVALIDO);
				}
	
				if (strlen(nomeArquivo) > 0) 
				{
					resultado = ConverterArquivoFormatoDosParaFormatoUnix (nomeArquivo, nomeArquivoDesejado);
      					if (resultado != ok)
						{
							printf ("\n\nErro #%i: Funcao gerou erro inesperado.\n", ERRO_NA_FUNCAO);
							printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
							exit (ERRO_NA_FUNCAO);
      					}
				}

      			break;

      			default:
        			printf ("\n\n\nErro #%i: Opcao invalida foi escolhida.\n", ARGUMENTO_INVALIDO);
					printf ("Uso: %s <opcao-curta> <nome-do-arquivo> <nome-do-arquivo-desejado>\n", argv[0]);
					exit (ARGUMENTO_INVALIDO);
    
		}
	
	}
	
	return OK;
}
 /* $RCSfile$ */