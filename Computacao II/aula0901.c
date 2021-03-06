/*
 * UNIVERSIDADE FEDERAL DO RIO DE JANEIRO
 * Escola politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/2
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Cleyton Marcos Siqueira Moreira
 * Descricao: ExibirConteudoArquivo.
 * 
 * $Author: cleyton.moreira $
 * $Date: 2022/03/09 01:47:16 $
 * $Log: aula0901.c,v $
 * Revision 1.3  2022/03/09 01:47:16  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.2  2022/02/25 13:32:17  cleyton.moreira
 * *** empty log message ***
 *
 * Revision 1.1  2022/02/23 06:16:48  cleyton.moreira
 * Initial revision
 *
 *
 */

/* Inclusao dos arquivos de cabecalho padrao para este programa */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include </usr/include/stdlib.h>
#include </usr/include/unistd.h>

/* Inclusao dos arquivos de cabecalho personalizado para este programa */
#include "aula0901.h"

/* funcao tipoErros ExibirConteudoArquivo */
tipoErros 
ExibirConteudoArquivo (char *nomeArquivo /* (E) */)
{
	int indiceDigito = 0, indiceAuxiliar = 0;
	long int tamanhoArquivo;
	unsigned char vetorBytes [17];
	char vetorCaracteres [3], contadorLinha, *dadosArquivos, *saidaBase16;
	FILE *ponteiroArquivo;
	
	ponteiroArquivo = fopen (nomeArquivo, "r");
	
	if (!ponteiroArquivo)
	{
		printf ("\n\n\nErro #%i: Solicitacao de abertura de arquivo inexistente.\n", ARQUIVO_INEXISTENTE);
		printf ("Erro abrindo o arquivo \"%s\"\n", nomeArquivo);
		printf ("Erro (#%i) | %s\n\n", errno, strerror(errno));
		return arquivoInexistente;
	}

	else
	{
		printf ("O arquivo foi aberto com sucesso!\n\n");
	}
	
	fseek (ponteiroArquivo, 0L, SEEK_END);

	tamanhoArquivo = ftell (ponteiroArquivo);
	
	if (tamanhoArquivo == 0)
	{
		printf ("\n\n\nErro #%i: Solicitacao de abertura de arquivo inexistente.\n", ARQUIVO_VAZIO);
		printf ("O arquivo \"%s\" esta vazio!\n", nomeArquivo);
		return arquivoVazio;
	}
	
	dadosArquivos = (char *) malloc (tamanhoArquivo * sizeof(char));

	if (!dadosArquivos)
	{
		printf ("\n\nErro #%i: Memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Erro abrindo o arquivo \"%s\"\n", nomeArquivo);
		printf ("Erro (#%i) | %s\n\n", errno, strerror(errno));
		return memoriaInsuficiente;
	}
	
	saidaBase16 = (char *) malloc ( (2 * (tamanhoArquivo * sizeof(char)) + 1 ) );
	
	if (!saidaBase16)
	{
		fclose(ponteiroArquivo);
		free (dadosArquivos);
		printf ("\n\nErro #%i: Memoria insuficiente para realizacao do processo.\n", MEMORIA_INSUFICIENTE);
		printf ("Erro abrindo o arquivo \"%s\"\n", nomeArquivo);
		printf ("Erro (#%i) | %s\n\n", errno, strerror(errno));
		return memoriaInsuficiente;
	}

	/* Realizando o inicio da leitura do arquivo desejado */

	fseek(ponteiroArquivo, 0, SEEK_SET);
	indiceDigito = 0;
	contadorLinha = fgetc(ponteiroArquivo);

	while (contadorLinha != EOF)
	{
		if (contadorLinha == '\n')
		{	
			dadosArquivos [indiceDigito] = '.';
		}
		else
		{
			dadosArquivos [indiceDigito] = contadorLinha;
		}
		contadorLinha = fgetc(ponteiroArquivo);
		indiceDigito += 1;
	}
	
	dadosArquivos [indiceDigito + 1] = EOS;

	/* Realizando a conversao dos digitos em hexadecimal */
	vetorCaracteres [2] = EOS;

	for (indiceDigito = 0; indiceDigito < (2*strlen(dadosArquivos)); indiceDigito++)
	{
		vetorCaracteres [0] = CONJUNTO_BASE16 [(dadosArquivos [indiceDigito] >> 4) & 0x0F];
		vetorCaracteres [1] = CONJUNTO_BASE16 [dadosArquivos [indiceDigito] & 0x0F];
		strcat (saidaBase16, vetorCaracteres);
	}
	
	for (indiceDigito = 0; indiceDigito < tamanhoArquivo; indiceDigito++)
	{
		if ((indiceDigito % 16) == 0)
		{
			if (indiceDigito != 0)
			{
			       	printf ("| %s\n", vetorBytes);
			}
			printf ("%08X | ", indiceDigito);
		}
		
		printf ("%c", saidaBase16 [indiceAuxiliar]);
		printf ("%c ", saidaBase16 [indiceAuxiliar + 1]);
		
		indiceAuxiliar += 2;
		if ((dadosArquivos [indiceDigito] < 0x20) || (dadosArquivos [indiceDigito] > 0x7F))
		        vetorBytes [indiceDigito % 16] = '.';
		else
			vetorBytes [indiceDigito % 16] = dadosArquivos [indiceDigito];

		vetorBytes [(indiceDigito % 16) + 1] = EOS;
	}
	
	indiceAuxiliar = 0;
	indiceAuxiliar = indiceDigito;

	while ((indiceDigito % 16) != 0)
	{
		printf ("    ");
		indiceDigito++;
	}

	printf ("| %s\n", vetorBytes);
	
	printf ("%08X\n", indiceAuxiliar);
	
	memset (saidaBase16, 0x00, (2 * tamanhoArquivo + 1));
	memset (dadosArquivos, 0x00, (tamanhoArquivo + 1));

	fclose (ponteiroArquivo);

	return ok;
}

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, char *convertido)
{
	FILE *arquivoOriginalUnix, *arquivoTipoDos;
	char indiceLinhas;
	unsigned numeroLinhas = 0;
	int arquivo, copia = 0;
	time_t hora;
	struct tm *dataHorario;
	char nomeArquivoBackup [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	char nomeArquivoTemporario [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	
	arquivoOriginalUnix = fopen (original, "r");
	
	if (!arquivoOriginalUnix)
	{
		printf ("\n\n\nErro #%i: Solicitacao de leitura de arquivo inexistente.\n", ARQUIVO_INEXISTENTE);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		return arquivoInexistente;
	}
	else
	{
		printf ("O arquivo foi aberto com sucesso.\n\n\n");
	}
	

	if (strlen (convertido) == 0)
	{
		strcpy (nomeArquivoTemporario, "temporario.XXXXXX");
	
		if ((arquivo = mkstemp (nomeArquivoTemporario)) == -1)
		{
			printf ("\n\n\nErro #%i: Solicitacao de nome do arquivo invalido.\n", NOME_ARQUIVO_INVALIDO);
			return arquivoInexistente;
		}
		copia += 1;
		
		arquivoTipoDos = fdopen (arquivo, "w");
	
		if (!arquivoTipoDos)
		{
		    printf ("\n\n\nErro #%i: Falha na escrita do arquivo temporario.\n", ESCRITA_ARQUIVO_INVALIDO);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			fclose (arquivoOriginalUnix);
			return arquivoInexistente;
		}
	}
	else
	{
		arquivoTipoDos = fopen (convertido, "w");
		
		if (!arquivoTipoDos)
		{
			printf ("\n\n\nErro #%i: Falha na escrita do arquivo temporario.\n", ESCRITA_ARQUIVO_INVALIDO);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			fclose (arquivoOriginalUnix);
			return arquivoInexistente;
		}
	}
	
	fseek (arquivoOriginalUnix, 0, SEEK_SET);

	while (!feof (arquivoOriginalUnix))
	{
		indiceLinhas = fgetc (arquivoOriginalUnix);

		if (indiceLinhas != EOF)
		{
			if (indiceLinhas == '\n')
			{
				fputc ('\r', arquivoTipoDos);
				fputc ('\n', arquivoTipoDos);
			}
			else
			{
				fputc (indiceLinhas, arquivoTipoDos);
				numeroLinhas++;
			}
		}
	}	
		
	fclose (arquivoOriginalUnix);
	fclose (arquivoTipoDos);
	
	hora = time (NULL);
  	dataHorario = localtime (&hora);
    	snprintf (nomeArquivoBackup,  COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1,
			"%s.backup-%04d%02d%02d_%02d%02d%02d.bck",
			original,
			dataHorario->tm_year + 1900,
			dataHorario->tm_mon + 1,
			dataHorario->tm_mday,
			dataHorario->tm_hour,
			dataHorario->tm_min,
			dataHorario->tm_sec);
	
	if (copia == 1)
	{
		strcpy (convertido, original);
		rename (original, nomeArquivoBackup);
		rename (nomeArquivoTemporario, convertido);
		printf ("Arquivo |'%s'| foi criado no formato DOS escrito com sucesso. Com  %u linhas escritas no arquivo.\n\n", convertido, numeroLinhas);
	}

	else
	{
		rename (original, nomeArquivoBackup);
	        rename (nomeArquivoTemporario, convertido);
		printf ("Arquivo |'%s'| foi criado no formato DOS escrito com sucesso. Com  %u linhas escritas no arquivo.\n\n", convertido, numeroLinhas);
	}

	return ok;
}

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, char *convertido)
{
	FILE *arquivoOriginalDos, *arquivoTipoUnix;
	char indiceLinha1, indiceLinha2;
	unsigned numeroLinhas = 0;
	int arquivo, copia = 0;
	time_t hora;
	struct tm *dataHorario;
	char nomeArquivoBackup [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	char nomeArquivoTemporario [COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1];
	
	arquivoOriginalDos = fopen (original, "r");
	
	if (!arquivoOriginalDos)
	{
		printf ("\n\n\nErro #%i: Solicitacao de leitura de arquivo inexistente.\n", ARQUIVO_INEXISTENTE);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		return arquivoInexistente;
	}
	else
	{
		printf ("O arquivo foi aberto com sucesso.\n\n\n");
	}
	
	if (strlen (convertido) == 0)
	{
		strcpy (nomeArquivoTemporario, "temporario.XXXXXX");
	
		if ((arquivo = mkstemp (nomeArquivoTemporario)) == -1)
		{
			printf ("\n\n\nErro #%i: Solicitacao de nome do arquivo invalido.\n", NOME_ARQUIVO_INVALIDO);
			return arquivoInexistente;
		}
		copia += 1;
		
		arquivoTipoUnix = fdopen (arquivo, "w");
	
		if (!arquivoTipoUnix)
		{
		    printf ("\n\n\nErro #%i: Falha na escrita do arquivo temporario.\n", ESCRITA_ARQUIVO_INVALIDO);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			fclose (arquivoOriginalDos);
			return arquivoInexistente;
		}
	}
	else
	{
		arquivoTipoUnix = fopen (convertido, "w");
		
		if (!arquivoTipoUnix)
		{
			printf ("\n\n\nErro #%i: Falha na escrita do arquivo temporario.\n", ESCRITA_ARQUIVO_INVALIDO);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			fclose (arquivoOriginalDos);
			return arquivoInexistente;
		}
	}

	fseek (arquivoOriginalDos, 0, SEEK_SET);

	while (!feof (arquivoOriginalDos))
	{
		indiceLinha1 = fgetc (arquivoOriginalDos);

		if (indiceLinha1 != EOF)
		{
			if (indiceLinha1 == '\r')
			{
				indiceLinha2 = fgetc (arquivoOriginalDos);
				
				if (indiceLinha2 != '\n')
				{
					putc (indiceLinha1, arquivoTipoUnix);
					putc ('\n', arquivoTipoUnix);
				}
				
				else
				{
					putc ('\n', arquivoTipoUnix);
				}
			}
			else
			{
				fputc (indiceLinha1, arquivoTipoUnix);
				numeroLinhas++;
			}
		}
	}
	
	fclose (arquivoOriginalDos);
	fclose (arquivoTipoUnix);
	
	hora = time (NULL);
  	dataHorario = localtime (&hora);
    	snprintf (nomeArquivoBackup,  COMPRIMENTO_MAXIMO_NOME_ARQUIVO + 1,
		"%s.backup-%04d%02d%02d_%02d%02d%02d.bck", original, dataHorario->tm_year + 1900, dataHorario->tm_mon + 1, 
		dataHorario->tm_mday, dataHorario->tm_hour, dataHorario->tm_min, dataHorario->tm_sec);
	
	if (copia == 1)
	{
		strcpy (convertido, original);
		rename (original, nomeArquivoBackup);
		rename (nomeArquivoTemporario, convertido);
		printf ("Arquivo |'%s'| foi criado no formato DOS escrito com sucesso. Com  %u linhas escritas no arquivo.\n\n", convertido, numeroLinhas);
	}
	else
	{
        	rename (original, nomeArquivoBackup);
        	rename (nomeArquivoTemporario, convertido);
		printf ("Arquivo |'%s'| foi criado no formato DOS escrito com sucesso. Com  %u linhas escritas no arquivo.\n\n", convertido, numeroLinhas);
	}
	
	return ok;
}

/*  $RCSfile: aula0901.c,v $ */
