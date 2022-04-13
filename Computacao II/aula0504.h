/* Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Aluno: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo de cabecalho para as funcao GerarDigitosVerificadoresRg e ValidarRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/24 03:56:58 $
 * $Log: aula0504.h,v $
 * Revision 1.2  2022/02/24 03:56:58  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/01 00:45:00  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifndef _AULA0504_
#define _AULA0504_	"@(#)aula0504.h $Revision: 1.2 $"

/* DEFINICOES DAS MACROS */
#define PESOS_RG 					8
#define RG_SEM_DIGITO_VERIFICADOR 			8
#define RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN		9
#define RG_COM_DIGITO_VERIFICADOR_COM_HIFEN 		10
#define RG_COMPLETO					12
#define EOS						'\0'

/* CODIGOS DE RETORNOS */
#define OK 						0
#define NUMERO_DE_ARGUMENTOS_INVALIDO 			1
#define ARGUMENTO_INVALIDO				2
#define DIGITO_INVALIDO					3
#define COMPRIMENTO_INVALIDO				4
#define AUSENCIA_DO_HIFEN				5
#define ARGUMENTO_NULO					6
#define ARGUMENTO_VAZIO					7

/* Definicao do tipo ush */
typedef unsigned short ush;

/* Definicao do tipo ull */
typedef unsigned long long ull;

typedef enum 
{
	invalido,
	valido,
	ok = 0,
	digitoInvalido = 3,
	digitoNulo = 6,
	argumentoInvalido,
	argumentoNulo,
	argumentoVazio
}tipoErros;

tipoErros
GerarDigitosVerificadoresRg (char * /* Entrada */, char * /* Saida - DV */);

tipoErros
ValidarRg (char *);


#endif
/* $Revision: 1.2 $ */
