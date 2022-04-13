/*
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 * 
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo contendo a implementacao da Funcao GerarDigitosVerificadoresRg.
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/01/31 08:46:22 $
 * $Log: aula0501.c,v $
 * Revision 1.3  2022/01/31 08:46:22  cleyton.moreira
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

/* Inclusao dos arquivos de cabecalho da biblioteca padrao */
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <inttypes.h>

/* Inclusa do arquivo cabecalho personalizado para o programa */
#include "aula0501.h"

tipoErros
GerarDigitosVerificadoresRg (byte registroGeral[])
{
	unsigned pesosRG[PESOS_RG] = {2, 3, 4, 5, 6, 7, 8, 9};
	unsigned digitoVerificador, resto;
	ush indiceDigito;
	ull soma = 0;

	if (!registroGeral)
		return argumentoNulo;

	/* Verificacao da existencia de dois digitos ou mais */
	for (indiceDigito = 0; indiceDigito < RG_SEM_DIGITO_VERIFICADOR; indiceDigito++)
		if (registroGeral[indiceDigito] > 9)
			return digitoInvalido;
	
	/* Soma dos digitos multiplicados por seus respectivos pesos */
	for (indiceDigito = 0; indiceDigito < PESOS_RG; indiceDigito++)
		soma += (ull) registroGeral[indiceDigito] * pesosRG[indiceDigito];

	resto = (soma % 11);

	/* Atribuicao do valor do digito verificador a ultima posicao do vetor registroGeral */
	if (resto == 0)
		registroGeral[RG_SEM_DIGITO_VERIFICADOR] = 0;
	
	if (resto == 1)
		registroGeral[RG_SEM_DIGITO_VERIFICADOR] = 88;
	else
	{
		if (resto < 0)
		{
			digitoVerificador = -(resto + 11);
			registroGeral[RG_SEM_DIGITO_VERIFICADOR] = (byte) digitoVerificador;
		}
		else
		{
			digitoVerificador = (11 - resto);
			registroGeral[RG_SEM_DIGITO_VERIFICADOR] = (byte) digitoVerificador;
		}
	}
	return ok;
}

tipoErros
ValidarRg (byte registroGeral[])
{
	byte registroGeralSemDigito[RG_COM_DIGITO_VERIFICADOR_SEM_HIFEN];
	ush indiceDigito;
	/* Verificacao dos argumentos passado para a funcao. */
	if (!registroGeral)
		return argumentoNulo;
	/* Passando os digitos para uma outra variavel. */
	for (indiceDigito = 0; indiceDigito < RG_SEM_DIGITO_VERIFICADOR; indiceDigito++)
		registroGeralSemDigito[indiceDigito] = registroGeral[indiceDigito];
	
	/* Gerando o digito verificador da variavel neutra. */
	GerarDigitosVerificadoresRg (registroGeralSemDigito);

	if (registroGeralSemDigito[RG_SEM_DIGITO_VERIFICADOR] != registroGeral[RG_SEM_DIGITO_VERIFICADOR])
	{
		return digitoInvalido;
	}
	else
	{
		for (indiceDigito = 0; indiceDigito < RG_SEM_DIGITO_VERIFICADOR; indiceDigito++)
		{
			registroGeral[indiceDigito] = registroGeralSemDigito[indiceDigito];
		}
		return valido;
	}
	return ok;
}

/* $RCSfile: aula0501.c,v $ */
