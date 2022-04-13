/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Programa de teste para a funcao VerificarRg.
 *
 * $author$
 * $Date: 2022/01/31 08:59:24 $
 * $Log: aula0503b.c,v $
 * Revision 1.2  2022/01/31 08:59:24  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/31 08:45:04  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivos de cabecalho da biblioteca padrao. */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <string.h>

/* Inclusao dos arquivos de cabecalho personalizado. */
#include "aula0501.h"

/* Definicao das Macros.*/
#define NUMERO_DE_ARGUMENTOS 				2

/* Implementacao do programa de teste da funcao ValidarRg.*/
int
main (int argc, char *argv[])
{
	byte registroGeral [RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN];
	ush indiceArgumento = 0, indiceDigito;
	ull valor;
	tipoErros resultado;

	printf ("\n");
	/* Verificacao dos argumentos passado pela CLI. */
	if (argc != NUMERO_DE_ARGUMENTOS)
	{
		printf ("\n\nErro #%i: Quantidade de argumntos passado pela CLI invalido.\n", ARGUMENTO_INVALIDO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
		printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
		exit (ARGUMENTO_INVALIDO);
	}

	/* Tratamento do comprimento do argumento passado para o programa. */
	if (strlen(argv[1]) != RG_COMPLETO)
	{
		printf ("\n\n\nErro #%i: Comprimento do argumento invalido.\n", COMPRIMENTO_INVALIDO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
		printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
		exit (COMPRIMENTO_INVALIDO);
	}
	
	/* Analisando os digitos passados para o programa. */
	for (indiceDigito = 0; indiceDigito < RG_COMPLETO; indiceDigito++)
	{
		if ((indiceDigito == 2) || (indiceDigito == 6) || (indiceDigito == 10))
		{
			if ((indiceDigito == 2) || (indiceDigito == 6))
			{
				if (argv[1][indiceDigito] != '.')
				{
					printf ("\n\nErro #%i: Argumento nao contem os pontos nos devidos lugares.\n", DIGITO_INVALIDO);
					printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
					printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
					exit (DIGITO_INVALIDO);
				}
			}
			if (indiceDigito == 10)
			{
				if (argv[1][indiceDigito] != '-')
				{
					printf ("\n\nErro #%i: Argumento nao contem o hifen no devido lugar.\n", AUSENCIA_DO_HIFEN);
					printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
					printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
					exit (AUSENCIA_DO_HIFEN);
				}
			}
		}
		else
		{
			if (indiceDigito != (RG_COMPLETO - 1))
			{
				valor = argv[1][indiceDigito] - '0';
				if (errno == EINVAL)
				{
					printf ("\n\nErro #%i: Entrada de argumento invalido.\n", ARGUMENTO_INVALIDO);
					printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
					printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
					exit (ARGUMENTO_INVALIDO);
				}
	
				if (errno == ERANGE)
				{
					printf ("\n\nErro #%i: Impossovel passagem de argumento invalido.\n", DIGITO_INVALIDO);
					printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
					printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
					exit (DIGITO_INVALIDO);
				}
			
				if ((valor > 9) || (valor < 0))
				{
					printf ("\n\nErro #%i: Argumento contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
					printf ("Caractere Invalido: '%c'.\n", argv[1][indiceDigito]);
					printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
					printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
					exit (ARGUMENTO_INVALIDO);
				}
				else
				{
					registroGeral [indiceArgumento] = valor;
					indiceArgumento++;
				}
			}
			else
			{
				if (argv[1][indiceDigito] != 'X')
				{
					valor = argv[1][indiceDigito] - '0';
					if (errno == EINVAL)
					{
						printf ("\n\nErro #%i: Entrada de argumento invalido.\n", ARGUMENTO_INVALIDO);
						printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
						printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
						exit (ARGUMENTO_INVALIDO);
					}
					if (errno == ERANGE)
					{
						printf ("\n\nErro #%i: Impossovel passagem de argumento invalido.\n", DIGITO_INVALIDO);
						printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
						printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
						exit (DIGITO_INVALIDO);
					}
					if ((valor > 9) || (valor < 0))
					{
						printf ("\n\nErro #%i: Argumento contem um ou mais caracteres invalido.\n", ARGUMENTO_INVALIDO);
						printf ("Caractere Invalido: '%c'.\n", argv[1][indiceDigito]);
						printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
						printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
						exit (ARGUMENTO_INVALIDO);
					}
					else
					{
						registroGeral [indiceArgumento] = valor;
					}
				}
				else
				{
					registroGeral[indiceArgumento] = (byte)('X');
				}
			}
		}
	}			
	/* Verificando o digito verificador.*/
	resultado = ValidarRg (registroGeral);

	if (resultado == argumentoNulo)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_NULO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
		printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
		exit (DIGITO_INVALIDO);
	}
	
	if (resultado == argumentoVazio)
	{
		printf ("\n\nErro #%i: Impossivel passar argumento nulo.\n", ARGUMENTO_VAZIO);
		printf ("Uso: %s <d1><d2>.<d3><d4><d5>.<d6><d7><d8>-<DV>\n", argv[0]);
		printf ("Sabendo: DV variando de 0 a 9 ou == 'X'.\n\n");
		exit (ARGUMENTO_VAZIO);
	}

	/* Exibicao do Resultado na tela. */
	indiceArgumento = 0;
	printf ("\n\n");
	for (indiceDigito = 0; indiceDigito < RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN; indiceDigito++)
	{
		if (indiceDigito == 0)
			printf ("RG: ");
		if ((indiceDigito == 2) || (indiceDigito == 5))
			printf(".");
		if (indiceDigito == 8)
			printf ("-");
		if (indiceDigito == (RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN - 1))
		{
			if (registroGeral[indiceDigito] == 88)
			{
				if (resultado == valido)
					printf ("X - valido");
				else
					printf ("X - invalido");
			}
			else
			{
				if (resultado == valido)
					printf ("%hhu - valido", registroGeral[indiceDigito]);
				else
					printf ("%hhu - invalido", registroGeral[indiceDigito]);
			}
		}
		else
		{
			printf ("%hhu", registroGeral[indiceDigito]);
		}
	}
	printf ("\n\n\n");
	
	return OK;
}
/* $RCSfile: aula0503b.c,v $ */
