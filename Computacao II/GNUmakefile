# 
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - 2021/2
# Prof. Marcelo Luiz Drumond Lanza
#
# Autor: Cleyton Marcos Siqueira Moreira
# Descricao:
# 
# $Author: cleyton.moreira $
# $Date: 2022/02/23 05:03:31 $
# $Log: GNUmakefile,v $
# Revision 1.15  2022/02/23 05:03:31  cleyton.moreira
# *** empty log message ***
#
# Revision 1.14  2022/02/16 01:55:55  cleyton.moreira
# *** empty log message ***
#
# Revision 1.13  2022/02/14 04:14:29  cleyton.moreira
# *** empty log message ***
#
# Revision 1.12  2022/02/01 07:20:34  cleyton.moreira
# *** empty log message ***
#
# Revision 1.11  2022/02/01 00:49:24  cleyton.moreira
# *** empty log message ***
#
# Revision 1.10  2022/01/25 04:21:42  cleyton.moreira
# ls
#
# Revision 1.9  2022/01/24 14:04:43  cleyton.moreira
# *** empty log message ***
#
# Revision 1.8  2022/01/12 04:52:23  cleyton.moreira
# *** empty log message ***
#
# Revision 1.7  2022/01/11 05:01:15  cleyton.moreira
# *** empty log message ***
#
# Revision 1.6  2022/01/10 02:34:04  cleyton.moreira
# *** empty log message ***
#
# Revision 1.5  2021/12/10 02:19:01  cleyton.moreira
# *** empty log message ***
#
# Revision 1.4  2021/12/10 01:55:56  cleyton.moreira
# *** empty log message ***
#
# Revision 1.3  2021/12/08 01:59:18  cleyton.moreira
# *** empty log message ***
#
# Revision 1.2  2021/12/02 05:07:36  cleyton.moreira
# *** empty log message ***
#
# Revision 1.1  2021/12/01 02:22:07  cleyton.moreira
# Initial revision
#

OS = $(shell uname -s)

CC = gcc

ifeq ($(cc), CLANG)
CC = clang
endif

LD = $(CC)

DIALECT = ansi
STANDARD = -ansi

ifeq ($(dialeto), C99)
DIALECT = c99
STANDARD = -std=c99
endif

ifeq ($(dialeto), C90)
DIALECT = c90
STANDARD = -std=c90
endif

ifeq ($(dialeto), C89)
DIALECT = c89
STANDARD = -std=c89
endif

ifeq ($(dialeto), C11)
DIALECT = c11
STANDARD = -std=c11
endif

DEBUG = 

ifeq ($(debug), DEPURACAO)
DEBUG = -DDEPURACAO
endif

CFLAGS = -Wall $(STANDARD) $(DEBUG)

LFLAGS = -Wall

# MACROS REFERENTES AOS CODIGOS-OBJETOS
# AULA 01
AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o

# AULA 02
AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o

# AULA 03
AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o

# AULA 04
AULA0402AOBJS = aula0401a.o aula0402.o
AULA0402BOBJS = aula0401b.o aula0402.o
AULA0402COBJS = aula0401c.o aula0402.o
AULA0402DOBJS = aula0401d.o aula0402.o
AULA0404AOBJS = aula0401a.o aula0403a.o aula0404.o
AULA0404BOBJS = aula0401b.o aula0403b.o aula0404.o
AULA0404COBJS = aula0401c.o aula0403c.o aula0404.o
AULA0404DOBJS = aula0401d.o aula0403d.o aula0404.o

# AULA 05
AULA0502AOBJS = aula0501.o aula0502a.o
AULA0502BOBJS = aula0501.o aula0502b.o
AULA0503AOBJS = aula0501.o aula0503a.o
AULA0503BOBJS = aula0501.o aula0503b.o
AULA0505AOBJS = aula0504.o aula0505a.o

# AULA 06
AULA0602OBJS = aula0601.o aula0602.o
AULA0603OBJS = aula0601.o aula0603.o
AULA0604OBJS = aula0601.o aula0604.o
AULA0605OBJS = aula0601.o aula0605.o
AULA0606OBJS = aula0601.o aula0606.o

# AULA 07
AULA0702OBJS = aula0701.o aula0702.o
AULA0703OBJS = aula0701.o aula0703.o
AULA0704OBJS = aula0701.o aula0704.o
AULA0705OBJS = aula0701.o aula0705.o
AULA0706OBJS = aula0701.o aula0706.o

# AULA 08
AULA0802OBJS = aula0801.o aula0802.o
AULA0803OBJS = aula0801.o aula0803.o
AULA0804OBJS = aula0801.o aula0804.o
AULA0805OBJS = aula0801.o aula0805.o
AULA0806OBJS = aula0801.o aula0806.o
AULA0807OBJS = aula0801.o aula0807.o

# AULA 09
AULA0902OBJS = aula0901.o aula0902.o

# MACROS REFERENTE AOS EXECUTAVEIS

AULA01 = aula0101\
	 aula0102\
	 aula0103

AULA02 = aula0202a\
	 aula0202b\
	 aula0202c\
	 aula0202d

AULA03 = aula0302a\
	 aula0302b\
	 aula0302c\
	 aula0302d


AULA04 = aula0402a\
	 aula0402b\
	 aula0402c\
	 aula0202d\
	 aula0404a\
	 aula0404b\
	 aula0404c\
	 aula0404d\
	 aula0404e

AULA05 = aula0502a\
	 aula0502b\
	 aula0503a\
	 aula0503b\
	 aula0505a

AULA06 = aula0602\
	 aula0603\
	 aula0604\
	 aula0605\
	 aula0606

AULA07 = aula0702\
	 aula0703\
	 aula0704\
	 aula0705\
	 aula0706

AULA08 = aula0802\
	 aula0803\
	 aula0804\
	 aula0805\
	 aula0806\
	 aula0807

AULA09 = aula0902


LIBMATEMATICARECURSAOOBJS = aula0201a.o aula0301a.o aula0401a.o aula0403a.o
LIBMATEMATICADOWHILEOBJS = aula0201b.o aula0301b.o aula0401b.o aula0403b.o
LIBMATEMATICAFOROBJS = aula0201c.o aula0301c.o aula0401c.o aula0403c.o
LIBMATEMATICAWHILEOBJS = aula0201d.o aula0301d.o aula0401d.o aula0403d.o
LIBMATEMATICAOBJS = aula0601.o
LIBMONITOROBJS = aula0701.o
LIBBASEOBJS = aula0801.o
LIBARQUIVOS = aula0901.o

LIBMATEMATICARECURSAO = libmatematicarecursao.a
LIBMATEMATICADOWHILE = libmatematicadowhile.a
LIBMATEMATICAFOR = libmatematicafor.a
LIBMATEMATICAWHILE = libmatematicawhile.a
LIBMATEMATICA = libmatematica.a
LIBMONITOR = libmonitor.a
LIBBASE = libbase.a
LIBARQUIVOS = libarquivos.a


EXECS = $(AULA01) $(AULA02) $(AULA03) $(AULA04) $(AULA05) $(AULA06) \
	$(AULA07) $(AULA08) $(AULA09)

LIBS = $(LIBMATEMATICARECURSAO) $(LIBMATEMATICADOWHILE) $(LIBMATEMATICAFOR) \
       $(LIBMATEMATICAWHILE) $(LIBMATEMATICA) $(LIBMONITOR) $(LIBBASE) $(LIBARQUIVOS)

ALL = $(EXECS) $(LIBS)


# REGRA IMPLICITA
.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)

# AULA 01
aula01: $(AULA01)

aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 02
aula02: $(AULA02)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp -f  $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 03
aula03: $(AULA03)

aula0302a: $(AULA0302AOBJS) $(LIBMATEMATICARECURSAO)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS) -L. -lmatematicarecursao
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302b: $(AULA0302BOBJS) $(LIBMATEMATICADOWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS) -L. -lmatematicadowhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302c: $(AULA0302COBJS) $(LIBMATEMATICAFOR)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS) -L. -lmatematicafor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0302d: $(AULA0302DOBJS) $(LIBMATEMATICAWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS) -L. -lmatematicawhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 04
aula04: $(AULA04)

aula0402a: $(AULA0402AOBJS) $(LIBMATEMATICARECURSAO)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS) -L. -lmatematicarecursao
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402b: $(AULA0402BOBJS) $(LIBMATEMATICADOWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0402BOBJS) -L. -lmatematicadowhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402c: $(AULA0402COBJS) $(LIBMATEMATICAFOR)
	$(LD) $(LFLAGS) -o $@ $(AULA0402AOBJS) -L. -lmatematicafor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0402d: $(AULA0402DOBJS) $(LIBMATEMATICAWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0402DOBJS) -L. -lmatematicawhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404a: $(AULA0404AOBJS) $(LIBMATEMATICARECURSAO)
	$(LD) $(LFLAGS) -o $@ $(AULA0404AOBJS) -L. -lmatematicarecursao
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404b: $(AULA0404BOBJS) $(LIBMATEMATICADOWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0404BOBJS) -L. -lmatematicadowhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404c: $(AULA0404COBJS) $(LIBMATEMATICAFOR)
	$(LD) $(LFLAGS) -o $@ $(AULA0404COBJS) -L. -lmatematicafor
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404d: $(AULA0404DOBJS) $(LIBMATEMATICAWHILE)
	$(LD) $(LFLAGS) -o $@ $(AULA0404DOBJS) -L. -lmatematicawhile
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0404e: $(AULA0404EOBJS) $(LIBMATEMATICARECURSAO)
	$(LD) $(LFLAGS) -o $@ $(AULA0404DOBJS) -L. -lmatematicarecursao
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 05
aula05: $(AULA05)

aula0502a: $(AULA0502AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0502b: $(AULA0502BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0502BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0503a: $(AULA0503AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0503b: $(AULA0503BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0503BOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0505a: $(AULA0505AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0505AOBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 06
aula06: $(AULA06)

aula0602: $(AULA0602OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0602OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0603: $(AULA0603OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0603OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0604: $(AULA0604OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0604OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0605: $(AULA0605OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0605OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0606: $(AULA0606OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0606OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 07
aula07: $(AULA07)

aula0702: $(AULA0702OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0702OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0703: $(AULA0703OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0703OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0704: $(AULA0704OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0704OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0705: $(AULA0705OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0705OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0706: $(AULA0706OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0706OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 08
aula08: $(AULA08)

aula0802: $(AULA0802OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0802OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0803: $(AULA0803OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0803OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0804: $(AULA0804OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0804OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0805: $(AULA0805OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0805OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)


aula0806: $(AULA0806OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0806OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

aula0807: $(AULA0807OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0807OBJS) -lm
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

# AULA 09
aula09: $(AULA09)

aula0902: $(AULA0902OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0902OBJS)
	cp -f $@ $@-$(OS)-$(CC)-$(DIALECT)

.PHONY: clean-all clean clean-objs clean-bsd clean-linux clean-gcc clean-clang clean-ansi clean-c99 clean-c90 clean-c89 clean-c11

clean-all:
	rm -f *.o $(ALL) *-FreeBSD-* *-Linux-* *.core *.a

clean:
	rm -f *.o $(ALL) *.core

clean-objs:
	rm -f *.o *.core

clean-bsd:
	rm -f *.o $(ALL) *-FreeBSD-* *.core

clean-linux:
	rm -f *.o $(ALL) *-Linux-* *.core

clean-gcc:
	rm -f *.o $(ALL) *-gcc-* *.core

clean-clang:
	rm -f *.o $(ALL) *-clang-* *.core

clean-ansi:
	rm -f *.o $(ALL) *-ansi * *.core

clean-c99:
	rm -f *.o $(ALL) *-c99 * *.core

clean-c90:
	rm -f *.o $(ALL) *-c90-* *.core

clean-c89:
	rm -f *.o $(ALL) *-c89 * *.core

clean-c11:
	rm -f *.o $(ALL) *-c11 * *.core

# $RCSfile: GNUmakefile,v $
