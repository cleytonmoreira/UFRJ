/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de cabecalho para exibicao de conteudo de arquivos, conversao de \
 * arquivos texto entre os formatos DOS e Unix, funcoes  getopt, getopt_long e getsubopt.
 * 
 * $Author: cleyton.moreira $
 * $Date: 2022/02/25 13:32:17 $
 * $Log: aula0901.h,v $
 * Revision 1.3  2022/02/25 13:32:17  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/25 11:22:09  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/23 06:16:48  cleyton.moreira
 * Initial revision
 *
 *
 */
 
#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE 	2011
#define __LONG_LONG_SUPPORTED
#endif


/* definicao das Macros */
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO 		255
#define TAMANHO_MAXIMO_NOME 				30
#define CONJUNTO_BASE16 				"0123456789ABCDEF"

/* Macros de retorno */
#define OK 						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO 			1
#define ARQUIVO_INEXISTENTE				2
#define VALOR_ARGUMENTO_INEXISTENTE                     			3
#define ARQUIVO_VAZIO 					4
#define NOME_ARQUIVO_INVALIDO 				5
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO_EXCEDIDO        			6
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO_EXCEDIDO  			7
#define MEMORIA_INSUFICIENTE 				8
#define ERRO_NA_FUNCAO					9
#define CARACTERE_INVALIDO 				10
#define ESCRITA_ARQUIVO_INVALIDO 			11
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO		        			255
#define COMPRIMENTO_MAXIMO_NOME_ARQUIVO_DESEJADO        			255
#define EOS 						'\0'


#ifndef _AULA0901_
#define _AULA0901_			"@(#)aula0901.h $Revision: 1.3 $"

typedef enum 
{
	ok,
	arquivoInexistente,
	arquivoVazio,
	memoriaInsuficiente
} tipoErros;

/* Prototipo da funcao ExibirConteudoArquivo */
tipoErros 
ExibirConteudoArquivo (char * /* (E) */);

/* Prototipo da funcao ConverterArquivoFormatoUnixParaFormatoDos */
tipoErros 
ConverterArquivoFormatoUnixParaFormatoDos (char *original /* (E) */, char *convertido /* (S) */);

/* Prototipo da funcao ConverterArquivoFormatoDosParaFormatoUnix */
tipoErros 
ConverterArquivoFormatoDosParaFormatoUnix (char *original /* (E)*/, char *convertido /* (S) */);

#endif
/* $RCSfile: aula0901.h,v $ */
