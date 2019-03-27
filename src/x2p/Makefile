# $Header: Makefile.SH,v 2.0 88/06/05 00:15:31 root Exp $
#
# $Log:	Makefile.SH,v $
# Revision 2.0  88/06/05  00:15:31  root
# Baseline version 2.0.
# 
# 

CC = cc
bin = /usr/local/bin
lib = 
mansrc = /usr/man/man1
manext = 1
CFLAGS =  -O
LDFLAGS = 
SMALL = 
LARGE =  
mallocsrc = 
mallocobj = 

libs =  -lm

public = a2p s2p

private = 

manpages = a2p.man s2p.man

util =

sh = Makefile.SH makedepend.SH

h = EXTERN.h INTERN.h config.h handy.h hash.h a2p.h str.h util.h

c = hash.c $(mallocsrc) str.c util.c walk.c

obj = hash.o $(mallocobj) str.o util.o walk.o

lintflags = -phbvxac

addedbyconf = Makefile.old bsd eunice filexp loc pdp11 usg v7

# grrr
SHELL = /bin/sh

.c.o:
	$(CC) -c $(CFLAGS) $(LARGE) $*.c

all: $(public) $(private) $(util)
	touch all

a2p: $(obj) a2p.o
	$(CC) $(LDFLAGS) $(LARGE) $(obj) a2p.o $(libs) -o a2p

a2p.c: a2p.y
	@ echo Expect 103 shift/reduce errors...
	yacc a2p.y
	mv y.tab.c a2p.c

a2p.o: a2p.c a2py.c a2p.h EXTERN.h util.h INTERN.h handy.h ../config.h
	$(CC) -c $(CFLAGS) $(LARGE) a2p.c

# if a .h file depends on another .h file...
$(h):
	touch $@
install: a2p s2p
# won't work with csh
	export PATH || exit 1
	- mv $(bin)/a2p $(bin)/a2p.old 2>/dev/null
	- mv $(bin)/s2p $(bin)/s2p.old
	- if test `pwd` != $(bin); then cp $(public) $(bin); fi
	cd $(bin); \
for pub in $(public); do \
chmod +x `basename $$pub`; \
done
#	chmod +x makedir
#	- ./makedir `filexp $(lib)`
#	- \
#if test `pwd` != `filexp $(lib)`; then \
#cp $(private) `filexp $(lib)`; \
#fi
#	cd `filexp $(lib)`; \
#for priv in $(private); do \
#chmod +x `basename $$priv`; \
#done
	- if test `pwd` != $(mansrc); then \
for page in $(manpages); do \
cp $$page $(mansrc)/`basename $$page .man`.$(manext); \
done; \
fi

clean:
	rm -f *.o

realclean:
	rm -f a2p *.orig */*.orig *.o core $(addedbyconf)

# The following lint has practically everything turned on.  Unfortunately,
# you have to wade through a lot of mumbo jumbo that can't be suppressed.
# If the source file has a /*NOSTRICT*/ somewhere, ignore the lint message
# for that spot.

lint:
	lint $(lintflags) $(defs) $(c) > a2p.fuzz

depend: ../makedepend
	../makedepend

clist:
	echo $(c) | tr ' ' '\012' >.clist

hlist:
	echo $(h) | tr ' ' '\012' >.hlist

shlist:
	echo $(sh) | tr ' ' '\012' >.shlist

# AUTOMATICALLY GENERATED MAKE DEPENDENCIES--PUT NOTHING BELOW THIS LINE
$(obj):
	@ echo "You haven't done a "'"make depend" yet!'; exit 1
makedepend: makedepend.SH
	/bin/sh makedepend.SH
