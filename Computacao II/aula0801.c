/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: Arquivo da Funcao da aula Algoritmos de Codificação Base16, Base32 e Base64
 *
 * $Author: cleyton.moreira $
 * $Date: 2022/02/23 05:03:31 $
 * $Log: aula0801.c,v $
 * Revision 1.3  2022/02/23 05:03:31  cleyton.moreira
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


#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (STRICT_ANSI__)
#define __ISO_C_VISIBLE 	1999
#define __LONG_LOONG_SUPPORTED
#endif

/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0801.h"

tipoErros
CodificarBase16 (byte *entrada, ull *numeroBytes, char *saida)
{
	unsigned indiceDigito;
	char argumentoEntrada [3];
	
	if ((!entrada) || (!saida))
		return argumentoNulo;
	
	argumentoEntrada [2] = EOS;
	
	for (indiceDigito = 0; indiceDigito < *numeroBytes; indiceDigito++)
	{
		argumentoEntrada [0] = CONJUNTO_BASE_16 [ (entrada[indiceDigito] >> 4) & 0x0F ];
		
		argumentoEntrada [1] = CONJUNTO_BASE_16 [ entrada[indiceDigito] & 0x0F ];
		
		strcat (saida, argumentoEntrada);
	}
	
	return ok;
}

tipoErros
DecodificarBase16 (char *entrada, byte *saida, ull *numeroBytes)
{
	unsigned indiceDigito, indiceBase16, argumentoByte;
	unsigned primeiroTermo, segundoTermo;

	if ((!entrada) || (!saida))
		return argumentoVazio;
	
	for (indiceDigito = 0; indiceDigito < strlen(entrada); indiceDigito += 2)
	{
		for (indiceBase16 = 0; indiceBase16 < 16; indiceBase16++)
		{
			if (CONJUNTO_BASE_16 [indiceBase16] == entrada [indiceDigito])
				primeiroTermo = indiceBase16;
			
			if (CONJUNTO_BASE_16 [indiceBase16] == entrada [indiceDigito + 1])
				segundoTermo = indiceBase16;
			
			argumentoByte = ((primeiroTermo * 16) + segundoTermo);

			saida [indiceDigito] = argumentoByte;
		}
	}
	return ok;
}

tipoErros
CodificarBase32 (byte *entrada, ull numeroBytes, tipoAlfabetoBase32 tipoAlfabeto, char *saida)
{
	ull indiceContador, indiceContador1 = 0, indiceContador2;
	unsigned indiceContador3 = 0, saidaAuxiliar = 0;
	char vetorAuxiliar [numeroBytes * 8];
	size_t comprimentoSaida;
	
	DecToBin (entrada, numeroBytes, vetorAuxiliar);
	
	for (indiceContador = 0; indiceContador < (8 * numeroBytes); indiceContador += 5)
	{
		for (indiceContador2 = 4; indiceContador2 >= 0;indiceContador2--)
		{
			saidaAuxiliar += pow(2,indiceContador2) * (vetorAuxiliar[indiceContador + indiceContador3]);
			indiceContador3++;
		}
		indiceContador3 = 0;
		if (tipoAlfabeto == basico)
		{
			saida[indiceContador1] = CONJUNTO_BASE_32_BASICO [saidaAuxiliar];
			indiceContador1++;
		}
		if (tipoAlfabeto == estendido)
		{
			saida[indiceContador1] = CONJUNTO_BASE_32_ESTENDIDO[saidaAuxiliar];
			indiceContador1++;
		}		
		saidaAuxiliar = 0;
	}
	
	if (strlen(saida) % 8 != 0)
	{
		
		comprimentoSaida = strlen(saida) % 8;
		for (indiceContador = 0; indiceContador < (8 - comprimentoSaida); indiceContador++)
		{
			saida[indiceContador + indiceContador1] = PAD;
		}
	}
	saida[indiceContador + indiceContador1] = EOS;
	
	return ok;
}

tipoErros
DecodificarBase32 (char *entrada, tipoAlfabetoBase32 tipoAlfabeto, byte *saida, ull *numeroBytes)
{
	unsigned int indiceContador2, indiceSaidaBin, saidaAuxiliar, validar = 0, indicePAD = 0;
	ull indiceContador;
	signed int indiceContador3;
	size_t comprimentoEntrada;
	char *saidaBinaria;
	char vetorAlfabetoBase32 [33];
	
	comprimentoEntrada = strlen(entrada);
	
	strcpy(vetorAlfabetoBase32, CONJUNTO_BASE_32_BASICO);

	if (tipoAlfabeto == estendido)
		strcpy(vetorAlfabetoBase32, CONJUNTO_BASE_32_ESTENDIDO);
	
	saidaBinaria = (char *) malloc (sizeof(char[comprimentoEntrada + 1]));
	
	if (tipoAlfabeto != basico &&  tipoAlfabeto != estendido)
		return argumentoInvalido;

	for (indiceContador = 0; indiceContador < comprimentoEntrada; indiceContador++)
	{
		if (entrada[indiceContador] == PAD)
		{
			while (entrada[indiceContador + indicePAD] == PAD)
				indicePAD++;
			indicePAD++;
			break;
		}
		
		for (indiceContador2 = 0; indiceContador2 < 33; indiceContador2++)
		{
			if (entrada[indiceContador] == vetorAlfabetoBase32[indiceContador2])
			{
				indiceSaidaBin = indiceContador2;
				validar++;
			}
		}
		saidaAuxiliar = indiceSaidaBin;
		
		for (indiceContador3 = 4; indiceContador3 >= 0; indiceContador3--)
		{
			saidaBinaria[5 * indiceContador + indiceContador3] = (saidaAuxiliar % 2) + '0';
			saidaAuxiliar = (saidaAuxiliar - (saidaAuxiliar % 2)) / 2;
		}
		if (validar == 0)
			return (argumentoInvalido);
		validar = 0;		
	}
	saidaBinaria [strlen(saidaBinaria) + indicePAD] = EOS;
	
	BinToDec (saidaBinaria, saida, numeroBytes);
	
	return ok;
}



tipoErros
CodificarBase64 (byte *vetorBytes, ull numeroBytes, tipoFinalLinha finalLinha, char *saidaBase64)
{
	unsigned divisao = 0, indice = 0, indiceSaida = 0;
	byte posicaoBytes;
	
	if ((!vetorBytes) || (!saidaBase64))
		return argumentoVazio;

	divisao = (numeroBytes/3);

	if ((numeroBytes % 3) != 0)
		divisao += 1;

	for (posicaoBytes = 0; posicaoBytes < divisao; posicaoBytes++)
	{
		saidaBase64 [indiceSaida] = CONJUNTO_BASE_64 [((vetorBytes[indice] & 0xfc) >> 2)];
		saidaBase64 [indiceSaida + 1] = CONJUNTO_BASE_64[((vetorBytes[indice] & 0x03) << 4)| ((vetorBytes [indice + 1] & 0xf0) >> 4)];

		saidaBase64 [indice + 2] = CONJUNTO_BASE_64[((vetorBytes[indice + 1] & 0x0f) << 2) | ((vetorBytes[indice + 2] & 0xc0) >> 6)];

		saidaBase64 [indice + 3] = CONJUNTO_BASE_64[(vetorBytes[indice + 2] & 0x3f)];
		if (posicaoBytes == (divisao) - 1)
		{
			if ((numeroBytes % 3) == 1)
			{
				saidaBase64 [indiceSaida + 2] = PAD;
				saidaBase64 [indiceSaida + 3] = PAD;
			}
		}
		if (((posicaoBytes == (divisao - 1)) && (numeroBytes % 3) != 1) || (posicaoBytes != (divisao - 1)))
		{
			if ((numeroBytes % 3) == 2)
			{
				saidaBase64[indiceSaida + 3] = PAD;
			}
		}

		indiceSaida += 4;
		indice += 3;
	}

	saidaBase64 [indiceSaida + 3] = EOS;

	return ok;
}


tipoErros
DecodificarBase64 (char *entradaBase64, tipoFinalLinha finalLinha, byte *vetorBytes, ull *numeroBytes)
{

	unsigned indice = 0, indiceSaida = 0;
	byte posicaoBytes;

	if ((!vetorBytes) || (!entradaBase64))
		return argumentoVazio;

	for (posicaoBytes = 0; posicaoBytes < strlen (entradaBase64); posicaoBytes++)
	{
		vetorBytes[indiceSaida] = (entradaBase64[indice] << 2) | (entradaBase64[indice + 1] >> 4);
		vetorBytes[indiceSaida + 1] = (entradaBase64[indice + 1] << 4) | (entradaBase64[indice + 2] >> 2);
		vetorBytes[indiceSaida + 2] = (entradaBase64[indice + 2] << 6) | (entradaBase64[indice + 3] >> 0);

		indiceSaida += 3;
		indice += 4;
	}

	return ok;
}

tipoErros
CodificarBase2 (char *entrada, ull *numeroBytes, byte *saida)
{
	int indiceContador, indiceContador2, indiceBase, indiceBase2, validar = 0;
	
	*numeroBytes = strlen(entrada);
	
	for (indiceContador = 0; indiceContador < *numeroBytes; indiceContador++)
	{
		for (indiceBase = 0; indiceBase < BASE_16; indiceBase++)
		{
			if (entrada[indiceContador] == CONJUNTO_BASE_16[indiceBase])
			{
				indiceBase2 = indiceBase;
				validar++;
				break;
			}
		}
	
		if (validar != 1)
			return argumentoInvalido;

		validar = 0;

		for (indiceContador2 = 3; indiceContador2 >= 0; indiceContador2--)
		{
			saida[4 * indiceContador + indiceContador2] = (indiceBase2 % 2);
			indiceBase2 = (indiceBase2 - indiceBase2 % 2) / 2;
		}
	}
	
	*numeroBytes *= 4;
	return ok;
}


/* DecToBin */
tipoErros
DecToBin (byte *entrada, ull numeroBytes, char *saida)
{
	ull indiceContador;
	byte saidaAuxiliar;
	signed short indiceContador2;

	for (indiceContador = 0; indiceContador < numeroBytes; indiceContador++)
	{
		if (entrada[indiceContador] > 255)
			return argumentoInvalido;

		saidaAuxiliar = entrada [indiceContador];
		
		for (indiceContador2 = 7; indiceContador2 >= 0; indiceContador2--)
		{
			saida [8*indiceContador + indiceContador2] = ((saidaAuxiliar % 2) + '0');
			saidaAuxiliar = (saidaAuxiliar - (saidaAuxiliar % 2))/2;
		}
	}
	saida [8*indiceContador] = EOS;
	return ok;
}

/* binToDec */
tipoErros
BinToDec (char * entrada, byte *saida, ull *numeroBytes)
{
	ull indiceContador;
	int indiceContador2, indiceContador3 = 0;
	size_t comprimentoEntrada;
	
	numeroBytes[0] = 0;
	comprimentoEntrada = strlen(entrada);
	if (comprimentoEntrada % 8 != 0)
	{
		for (indiceContador = 0; indiceContador < (8 - comprimentoEntrada % 8); indiceContador++)
			strcat (entrada,"0\0");
	}
	
	for (indiceContador = 0; indiceContador < comprimentoEntrada; indiceContador++)
	{
		saida[indiceContador3] = 0;
		for (indiceContador2 = 7; indiceContador2 >= 0; indiceContador2--)
		{
			saida [indiceContador3] += (entrada[indiceContador] - '0') * (pow(2,indiceContador2));
			indiceContador++;
		}
		indiceContador3++;
		numeroBytes[0]++;
	}
	saida[indiceContador3] = 0;
	
	return ok;
}

/* $RCSfile: aula0801.c,v $ */
