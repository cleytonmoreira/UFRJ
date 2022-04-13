/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Cabecalho da Funcao do Algoritmo Codificacao Base16, 32 e 64.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/24 03:56:58 $
 * $Log: aula0801.h,v $
 * Revision 1.3  2022/02/24 03:56:58  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/16 01:55:55  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/14 04:13:51  cleyton.moreira
 * Initial revision
 *
 *
 */
 
#ifdef _linux_
#define _XOPEN_SOURCE 600
#endif

#if defined (_FreeBSD) && defined (STRICT_ANSI_)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

/* definicao dos conjuntos base16 */
#define CONJUNTO_BASE_16			"0123456789ABCDEF"
#define BASE_16					16

#define CONJUNTO_BASE_32_BASICO			"ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
#define CONJUNTO_BASE_32_ESTENDIDO 		"0123456789ABCDEFGHIJKLMNOPQRSTUV"
#define BASE_32					32

#define CONJUNTO_BASE_64 			"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE_64					64

#ifndef _AULA0801_
#define _AULA0801_			"@(#)aula0801.h $Revision: 1.3 $"


/* definicao das Macros */
#define NUMERO_MAXIMO_DE_PADDINGS	 		2
#define NUMERO_MINIMO_DE_ARGUMENTOS			3
#define TAMANHO_DO_BLOCO_DE_CODIFICACAO			3
#define TAMANHO_DO_BLOCO_DE_DECODIFICACAO		4
#define NUMERO_MAXIMO_DE_BYTES_DE_CODIFICACAO		1024
#define NUMERO_MAXIMO_DE_ARGUMENTOS			1026
#define RLN						'\r'
#define NWL						'\n'
#define PAD	 					'='

/* Macros de retorno */
#define OK						0
#define BASE_INVALIDA					1
#define ARGUMENTO_INVALIDO				2
#define COMPRIMENTO_INVALIDO				3
#define ARGUMENTO_NULO					4
#define ARGUMENTO_VAZIO					5
#define CARACTERE_INVALIDO				6
#define MEMORIA_INSUFICIENTE 				7
#define EOS 						'\0'


/* definicao do tipo byte */
typedef unsigned char byte; 

/*definicao do tipo unsigned long long */
typedef unsigned long long ull;

/* Definicao do tipo tipoErros */
typedef enum
{
	ok,
	comprimentoInvalido = 3,
	argumentoNulo,
	argumentoVazio,
	argumentoInvalido,
	caractereInvalido
} tipoErros;

/* Definicao do tipo alfabeto base 32 */
typedef enum
{
	basico,
	estendido
} tipoAlfabetoBase32;

/* definicao di tipo final de linha */
typedef enum
{
	habilitado,
	desabilitado
} tipoFinalLinha;


tipoErros
CodificarBase2 (char * /* (E) */, ull * /* (E) */, byte * /* (S)*/);

tipoErros
DecToBin (byte * /* (E) */, ull /* (S) */, char * /* (S) */);

tipoErros
BinToDec (char * /* (E) */, byte * /* (S) */, ull * /* (S) */); 

tipoErros
CodificarBase16 (byte * /* (E) */, ull * /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase16 (char * /* (E) */, byte * /* (S) */, ull * /*(S) */);

tipoErros
CodificarBase32 (byte * /* (E) */, ull /* (E) */, tipoAlfabetoBase32 /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase32 (char * /* (E) */, tipoAlfabetoBase32 /* (E) */, byte * /* (S) */, ull * /* (S)*/);

tipoErros
CodificarBase64 (byte * /* (E) */, ull /* (E) */, tipoFinalLinha /* (E) */, char * /* (S) */);

tipoErros
DecodificarBase64 (char * /* (E) */, tipoFinalLinha /* (E) */, byte * /* (S) */, ull * /* (S) */);


#endif
/* $RCSfile: aula0801.h,v $ */
