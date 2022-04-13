/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo Prototipo da Funcao GerarDigitosVerificadoresRg e ValidarRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/24 03:40:26 $
 * $Log: aula0501.h,v $
 * Revision 1.3  2022/02/24 03:40:26  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/01/21 00:40:06  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/01/12 04:52:23  cleyton.moreira
 * Initial revision
 *
 *
 */

#ifndef _AULA0501_
#define _AULA0501_	"@(#)aula0501.h $Revision: 1.3 $"


/* DEFINICOES DAS MACROS */
#define PESOS_RG				8
#define RG_SEM_DIGITO_VERIFICADOR		8
#define RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN	9
#define RG_COM_DIGITO_VERIFICADOR_COM_HIFEN	10
#define RG_COMPLETO				12
#define EOS					'\0'

/* CODIGOS DE RETORNO */
#define OK					0
#define NUMERO_DE_ARGUMENTOS_INVALIDO		1
#define ARGUMENTO_INVALIDO			2
#define DIGITO_INVALIDO				3
#define COMPRIMENTO_INVALIDO			4
#define AUSENCIA_DO_HIFEN			5
#define ARGUMENTO_NULO				6
#define ARGUMENTO_VAZIO				7

/* Definicao do tipo byte */
typedef unsigned char byte;

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

/* Prototipo da funcao GerarDigitosVerificadoresRg */
tipoErros
GerarDigitosVerificadoresRg (byte [] /*entrada/saida*/);


/* Prototipo da funcao ValidarRg */
tipoErros
ValidarRg (byte [] /* Entrada */);

#endif
/* $RCSfile: aula0501.h,v $ */
