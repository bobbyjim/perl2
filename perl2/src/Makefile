# $Header: Makefile.SH,v 2.0 88/06/05 00:07:54 root Exp $
#
# $Log:	Makefile.SH,v $
# Revision 2.0  88/06/05  00:07:54  root
# Baseline version 2.0.
# 
# 

CC = cc
bin = /usr/local/bin
lib = /usr/local/lib/perl
mansrc = /usr/man/man1
manext = 1
CFLAGS =  -O
LDFLAGS = 
SMALL = 
LARGE =  
mallocsrc = 
mallocobj = 
SLN = ln -s

libs =  -lm

public = perl perldb

private = 

manpages = perl.man perldb.man

util =

sh = Makefile.SH makedepend.SH

h1 = EXTERN.h INTERN.h arg.h array.h cmd.h config.h form.h handy.h
h2 = hash.h perl.h regexp.h spat.h stab.h str.h util.h

h = $(h1) $(h2)

c1 = arg.c array.c cmd.c dump.c eval.c form.c hash.c $(mallocsrc)
c2 = perly.c regexp.c stab.c str.c toke.c util.c version.c

c = $(c1) $(c2)

obj1 = arg.o array.o cmd.o dump.o eval.o form.o hash.o $(mallocobj)
obj2 = perly.o regexp.o stab.o str.o toke.o util.o version.o

obj = $(obj1) $(obj2)

lintflags = -phbvxac

addedbyconf = Makefile.old bsd eunice filexp loc pdp11 usg v7

# grrr
SHELL = /bin/sh

.c.o:
	$(CC) -c $(CFLAGS) $(LARGE) $*.c

all: $(public) $(private) $(util)
	touch all

perl: $(obj) perl.o
	$(CC) $(LDFLAGS) $(LARGE) $(obj) perl.o $(libs) -o perl

perl.c perly.h: perl.y
	@ echo Expect 37 shift/reduce errors...
	yacc -d perl.y
	mv y.tab.c perl.c
	mv y.tab.h perly.h

perl.o: perl.c perly.h perl.h EXTERN.h regexp.h util.h INTERN.h handy.h config.h
	$(CC) -c $(CFLAGS) $(LARGE) perl.c

# if a .h file depends on another .h file...
$(h):
	touch $@

perl.man: perl.man.1 perl.man.2
	cat perl.man.1 perl.man.2 >perl.man

install: perl perl.man
# won't work with csh
	export PATH || exit 1
	- mv $(bin)/perl $(bin)/perl.old 2>/dev/null
	- if test `pwd` != $(bin); then cp $(public) $(bin); fi
	cd $(bin); \
for pub in $(public); do \
chmod +x `basename $$pub`; \
done
	- test $(bin) = /usr/bin || rm -f /usr/bin/perl
	- test $(bin) = /usr/bin || $(SLN) $(bin)/perl /usr/bin || cp $(bin)/perl /usr/bin
	chmod +x makedir
	- ./makedir $(lib)
	- \
if test `pwd` != $(lib); then \
cp $(private) lib/*.pl $(lib); \
fi
#	cd $(lib); \
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
	rm -f perl *.orig */*.orig *.o core $(addedbyconf)

# The following lint has practically everything turned on.  Unfortunately,
# you have to wade through a lot of mumbo jumbo that can't be suppressed.
# If the source file has a /*NOSTRICT*/ somewhere, ignore the lint message
# for that spot.

lint: perl.c $(c)
	lint $(lintflags) $(defs) perl.c $(c) > perl.fuzz

depend: makedepend
	- test -f perly.h || cp /dev/null perly.h
	./makedepend
	- test -s perly.h || /bin/rm -f perly.h

test: perl
	chmod +x t/TEST t/base.* t/comp.* t/cmd.* t/io.* t/op.*
	cd t && (rm -f perl; $(SLN) ../perl .) && ./perl TEST

clist:
	echo $(c) | tr ' ' '\012' >.clist

hlist:
	echo $(h) | tr ' ' '\012' >.hlist

shlist:
	echo $(sh) | tr ' ' '\012' >.shlist

# AUTOMATICALLY GENERATED MAKE DEPENDENCIES--PUT NOTHING BELOW THIS LINE
# If this runs make out of memory, delete /usr/include lines.
arg.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
arg.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
arg.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
arg.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
arg.o: /usr/include/_ansi.h
arg.o: /usr/include/_newlib_version.h
arg.o: /usr/include/bits/byteswap.h
arg.o: /usr/include/bits/endian.h
arg.o: /usr/include/bits/wordsize.h
arg.o: /usr/include/ctype.h
arg.o: /usr/include/cygwin/config.h
arg.o: /usr/include/cygwin/signal.h
arg.o: /usr/include/cygwin/stat.h
arg.o: /usr/include/cygwin/time.h
arg.o: /usr/include/endian.h
arg.o: /usr/include/errno.h
arg.o: /usr/include/features.h
arg.o: /usr/include/limits.h
arg.o: /usr/include/machine/_default_types.h
arg.o: /usr/include/machine/_endian.h
arg.o: /usr/include/machine/_types.h
arg.o: /usr/include/machine/endian.h
arg.o: /usr/include/machine/ieeefp.h
arg.o: /usr/include/machine/setjmp.h
arg.o: /usr/include/machine/time.h
arg.o: /usr/include/machine/types.h
arg.o: /usr/include/newlib.h
arg.o: /usr/include/setjmp.h
arg.o: /usr/include/signal.h
arg.o: /usr/include/stdio.h
arg.o: /usr/include/sys/_pthreadtypes.h
arg.o: /usr/include/sys/_sigset.h
arg.o: /usr/include/sys/_stdint.h
arg.o: /usr/include/sys/_timespec.h
arg.o: /usr/include/sys/_timeval.h
arg.o: /usr/include/sys/_types.h
arg.o: /usr/include/sys/cdefs.h
arg.o: /usr/include/sys/config.h
arg.o: /usr/include/sys/errno.h
arg.o: /usr/include/sys/features.h
arg.o: /usr/include/sys/lock.h
arg.o: /usr/include/sys/param.h
arg.o: /usr/include/sys/reent.h
arg.o: /usr/include/sys/select.h
arg.o: /usr/include/sys/signal.h
arg.o: /usr/include/sys/stat.h
arg.o: /usr/include/sys/stdio.h
arg.o: /usr/include/sys/sysmacros.h
arg.o: /usr/include/sys/times.h
arg.o: /usr/include/sys/timespec.h
arg.o: /usr/include/sys/types.h
arg.o: /usr/include/sys/ucontext.h
arg.o: /usr/include/time.h
arg.o: /usr/include/xlocale.h
arg.o: arg.c
arg.o: arg.h
arg.o: array.h
arg.o: cmd.h
arg.o: config.h
arg.o: EXTERN.h
arg.o: form.h
arg.o: handy.h
arg.o: hash.h
arg.o: perl.h
arg.o: regexp.h
arg.o: spat.h
arg.o: stab.h
arg.o: str.h
arg.o: util.h
array.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
array.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
array.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
array.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
array.o: /usr/include/_ansi.h
array.o: /usr/include/_newlib_version.h
array.o: /usr/include/bits/byteswap.h
array.o: /usr/include/bits/endian.h
array.o: /usr/include/bits/wordsize.h
array.o: /usr/include/ctype.h
array.o: /usr/include/cygwin/config.h
array.o: /usr/include/cygwin/signal.h
array.o: /usr/include/cygwin/stat.h
array.o: /usr/include/cygwin/time.h
array.o: /usr/include/endian.h
array.o: /usr/include/features.h
array.o: /usr/include/limits.h
array.o: /usr/include/machine/_default_types.h
array.o: /usr/include/machine/_endian.h
array.o: /usr/include/machine/_types.h
array.o: /usr/include/machine/endian.h
array.o: /usr/include/machine/ieeefp.h
array.o: /usr/include/machine/setjmp.h
array.o: /usr/include/machine/time.h
array.o: /usr/include/machine/types.h
array.o: /usr/include/newlib.h
array.o: /usr/include/setjmp.h
array.o: /usr/include/signal.h
array.o: /usr/include/stdio.h
array.o: /usr/include/sys/_pthreadtypes.h
array.o: /usr/include/sys/_sigset.h
array.o: /usr/include/sys/_stdint.h
array.o: /usr/include/sys/_timespec.h
array.o: /usr/include/sys/_timeval.h
array.o: /usr/include/sys/_types.h
array.o: /usr/include/sys/cdefs.h
array.o: /usr/include/sys/config.h
array.o: /usr/include/sys/features.h
array.o: /usr/include/sys/lock.h
array.o: /usr/include/sys/param.h
array.o: /usr/include/sys/reent.h
array.o: /usr/include/sys/select.h
array.o: /usr/include/sys/signal.h
array.o: /usr/include/sys/stat.h
array.o: /usr/include/sys/stdio.h
array.o: /usr/include/sys/sysmacros.h
array.o: /usr/include/sys/times.h
array.o: /usr/include/sys/timespec.h
array.o: /usr/include/sys/types.h
array.o: /usr/include/sys/ucontext.h
array.o: /usr/include/time.h
array.o: /usr/include/xlocale.h
array.o: arg.h
array.o: array.c
array.o: array.h
array.o: cmd.h
array.o: config.h
array.o: EXTERN.h
array.o: form.h
array.o: handy.h
array.o: hash.h
array.o: perl.h
array.o: regexp.h
array.o: spat.h
array.o: stab.h
array.o: str.h
array.o: util.h
cmd.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
cmd.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
cmd.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
cmd.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
cmd.o: /usr/include/_ansi.h
cmd.o: /usr/include/_newlib_version.h
cmd.o: /usr/include/bits/byteswap.h
cmd.o: /usr/include/bits/endian.h
cmd.o: /usr/include/bits/wordsize.h
cmd.o: /usr/include/ctype.h
cmd.o: /usr/include/cygwin/config.h
cmd.o: /usr/include/cygwin/signal.h
cmd.o: /usr/include/cygwin/stat.h
cmd.o: /usr/include/cygwin/time.h
cmd.o: /usr/include/endian.h
cmd.o: /usr/include/features.h
cmd.o: /usr/include/limits.h
cmd.o: /usr/include/machine/_default_types.h
cmd.o: /usr/include/machine/_endian.h
cmd.o: /usr/include/machine/_types.h
cmd.o: /usr/include/machine/endian.h
cmd.o: /usr/include/machine/ieeefp.h
cmd.o: /usr/include/machine/setjmp.h
cmd.o: /usr/include/machine/time.h
cmd.o: /usr/include/machine/types.h
cmd.o: /usr/include/newlib.h
cmd.o: /usr/include/setjmp.h
cmd.o: /usr/include/signal.h
cmd.o: /usr/include/stdio.h
cmd.o: /usr/include/sys/_pthreadtypes.h
cmd.o: /usr/include/sys/_sigset.h
cmd.o: /usr/include/sys/_stdint.h
cmd.o: /usr/include/sys/_timespec.h
cmd.o: /usr/include/sys/_timeval.h
cmd.o: /usr/include/sys/_types.h
cmd.o: /usr/include/sys/cdefs.h
cmd.o: /usr/include/sys/config.h
cmd.o: /usr/include/sys/features.h
cmd.o: /usr/include/sys/lock.h
cmd.o: /usr/include/sys/param.h
cmd.o: /usr/include/sys/reent.h
cmd.o: /usr/include/sys/select.h
cmd.o: /usr/include/sys/signal.h
cmd.o: /usr/include/sys/stat.h
cmd.o: /usr/include/sys/stdio.h
cmd.o: /usr/include/sys/sysmacros.h
cmd.o: /usr/include/sys/times.h
cmd.o: /usr/include/sys/timespec.h
cmd.o: /usr/include/sys/types.h
cmd.o: /usr/include/sys/ucontext.h
cmd.o: /usr/include/time.h
cmd.o: /usr/include/xlocale.h
cmd.o: arg.h
cmd.o: array.h
cmd.o: cmd.c
cmd.o: cmd.h
cmd.o: config.h
cmd.o: EXTERN.h
cmd.o: form.h
cmd.o: handy.h
cmd.o: hash.h
cmd.o: perl.h
cmd.o: regexp.h
cmd.o: spat.h
cmd.o: stab.h
cmd.o: str.h
cmd.o: util.h
dump.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
dump.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
dump.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
dump.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
dump.o: /usr/include/_ansi.h
dump.o: /usr/include/_newlib_version.h
dump.o: /usr/include/bits/byteswap.h
dump.o: /usr/include/bits/endian.h
dump.o: /usr/include/bits/wordsize.h
dump.o: /usr/include/ctype.h
dump.o: /usr/include/cygwin/config.h
dump.o: /usr/include/cygwin/signal.h
dump.o: /usr/include/cygwin/stat.h
dump.o: /usr/include/cygwin/time.h
dump.o: /usr/include/endian.h
dump.o: /usr/include/features.h
dump.o: /usr/include/limits.h
dump.o: /usr/include/machine/_default_types.h
dump.o: /usr/include/machine/_endian.h
dump.o: /usr/include/machine/_types.h
dump.o: /usr/include/machine/endian.h
dump.o: /usr/include/machine/ieeefp.h
dump.o: /usr/include/machine/setjmp.h
dump.o: /usr/include/machine/time.h
dump.o: /usr/include/machine/types.h
dump.o: /usr/include/newlib.h
dump.o: /usr/include/setjmp.h
dump.o: /usr/include/signal.h
dump.o: /usr/include/stdio.h
dump.o: /usr/include/sys/_pthreadtypes.h
dump.o: /usr/include/sys/_sigset.h
dump.o: /usr/include/sys/_stdint.h
dump.o: /usr/include/sys/_timespec.h
dump.o: /usr/include/sys/_timeval.h
dump.o: /usr/include/sys/_types.h
dump.o: /usr/include/sys/cdefs.h
dump.o: /usr/include/sys/config.h
dump.o: /usr/include/sys/features.h
dump.o: /usr/include/sys/lock.h
dump.o: /usr/include/sys/param.h
dump.o: /usr/include/sys/reent.h
dump.o: /usr/include/sys/select.h
dump.o: /usr/include/sys/signal.h
dump.o: /usr/include/sys/stat.h
dump.o: /usr/include/sys/stdio.h
dump.o: /usr/include/sys/sysmacros.h
dump.o: /usr/include/sys/times.h
dump.o: /usr/include/sys/timespec.h
dump.o: /usr/include/sys/types.h
dump.o: /usr/include/sys/ucontext.h
dump.o: /usr/include/time.h
dump.o: /usr/include/xlocale.h
dump.o: arg.h
dump.o: array.h
dump.o: cmd.h
dump.o: config.h
dump.o: dump.c
dump.o: EXTERN.h
dump.o: form.h
dump.o: handy.h
dump.o: hash.h
dump.o: perl.h
dump.o: regexp.h
dump.o: spat.h
dump.o: stab.h
dump.o: str.h
dump.o: util.h
eval.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
eval.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
eval.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
eval.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
eval.o: /usr/include/_ansi.h
eval.o: /usr/include/_newlib_version.h
eval.o: /usr/include/bits/byteswap.h
eval.o: /usr/include/bits/endian.h
eval.o: /usr/include/bits/wordsize.h
eval.o: /usr/include/ctype.h
eval.o: /usr/include/cygwin/config.h
eval.o: /usr/include/cygwin/signal.h
eval.o: /usr/include/cygwin/stat.h
eval.o: /usr/include/cygwin/time.h
eval.o: /usr/include/endian.h
eval.o: /usr/include/errno.h
eval.o: /usr/include/features.h
eval.o: /usr/include/limits.h
eval.o: /usr/include/machine/_default_types.h
eval.o: /usr/include/machine/_endian.h
eval.o: /usr/include/machine/_types.h
eval.o: /usr/include/machine/endian.h
eval.o: /usr/include/machine/ieeefp.h
eval.o: /usr/include/machine/setjmp.h
eval.o: /usr/include/machine/time.h
eval.o: /usr/include/machine/types.h
eval.o: /usr/include/newlib.h
eval.o: /usr/include/setjmp.h
eval.o: /usr/include/signal.h
eval.o: /usr/include/stdio.h
eval.o: /usr/include/sys/_pthreadtypes.h
eval.o: /usr/include/sys/_sigset.h
eval.o: /usr/include/sys/_stdint.h
eval.o: /usr/include/sys/_timespec.h
eval.o: /usr/include/sys/_timeval.h
eval.o: /usr/include/sys/_types.h
eval.o: /usr/include/sys/cdefs.h
eval.o: /usr/include/sys/config.h
eval.o: /usr/include/sys/errno.h
eval.o: /usr/include/sys/features.h
eval.o: /usr/include/sys/lock.h
eval.o: /usr/include/sys/param.h
eval.o: /usr/include/sys/reent.h
eval.o: /usr/include/sys/select.h
eval.o: /usr/include/sys/signal.h
eval.o: /usr/include/sys/stat.h
eval.o: /usr/include/sys/stdio.h
eval.o: /usr/include/sys/sysmacros.h
eval.o: /usr/include/sys/times.h
eval.o: /usr/include/sys/timespec.h
eval.o: /usr/include/sys/types.h
eval.o: /usr/include/sys/ucontext.h
eval.o: /usr/include/time.h
eval.o: /usr/include/xlocale.h
eval.o: arg.h
eval.o: array.h
eval.o: cmd.h
eval.o: config.h
eval.o: eval.c
eval.o: EXTERN.h
eval.o: form.h
eval.o: handy.h
eval.o: hash.h
eval.o: perl.h
eval.o: regexp.h
eval.o: spat.h
eval.o: stab.h
eval.o: str.h
eval.o: util.h
form.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
form.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
form.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
form.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
form.o: /usr/include/_ansi.h
form.o: /usr/include/_newlib_version.h
form.o: /usr/include/bits/byteswap.h
form.o: /usr/include/bits/endian.h
form.o: /usr/include/bits/wordsize.h
form.o: /usr/include/ctype.h
form.o: /usr/include/cygwin/config.h
form.o: /usr/include/cygwin/signal.h
form.o: /usr/include/cygwin/stat.h
form.o: /usr/include/cygwin/time.h
form.o: /usr/include/endian.h
form.o: /usr/include/features.h
form.o: /usr/include/limits.h
form.o: /usr/include/machine/_default_types.h
form.o: /usr/include/machine/_endian.h
form.o: /usr/include/machine/_types.h
form.o: /usr/include/machine/endian.h
form.o: /usr/include/machine/ieeefp.h
form.o: /usr/include/machine/setjmp.h
form.o: /usr/include/machine/time.h
form.o: /usr/include/machine/types.h
form.o: /usr/include/newlib.h
form.o: /usr/include/setjmp.h
form.o: /usr/include/signal.h
form.o: /usr/include/stdio.h
form.o: /usr/include/sys/_pthreadtypes.h
form.o: /usr/include/sys/_sigset.h
form.o: /usr/include/sys/_stdint.h
form.o: /usr/include/sys/_timespec.h
form.o: /usr/include/sys/_timeval.h
form.o: /usr/include/sys/_types.h
form.o: /usr/include/sys/cdefs.h
form.o: /usr/include/sys/config.h
form.o: /usr/include/sys/features.h
form.o: /usr/include/sys/lock.h
form.o: /usr/include/sys/param.h
form.o: /usr/include/sys/reent.h
form.o: /usr/include/sys/select.h
form.o: /usr/include/sys/signal.h
form.o: /usr/include/sys/stat.h
form.o: /usr/include/sys/stdio.h
form.o: /usr/include/sys/sysmacros.h
form.o: /usr/include/sys/times.h
form.o: /usr/include/sys/timespec.h
form.o: /usr/include/sys/types.h
form.o: /usr/include/sys/ucontext.h
form.o: /usr/include/time.h
form.o: /usr/include/xlocale.h
form.o: arg.h
form.o: array.h
form.o: cmd.h
form.o: config.h
form.o: EXTERN.h
form.o: form.c
form.o: form.h
form.o: handy.h
form.o: hash.h
form.o: perl.h
form.o: regexp.h
form.o: spat.h
form.o: stab.h
form.o: str.h
form.o: util.h
hash.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
hash.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
hash.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
hash.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
hash.o: /usr/include/_ansi.h
hash.o: /usr/include/_newlib_version.h
hash.o: /usr/include/bits/byteswap.h
hash.o: /usr/include/bits/endian.h
hash.o: /usr/include/bits/wordsize.h
hash.o: /usr/include/ctype.h
hash.o: /usr/include/cygwin/config.h
hash.o: /usr/include/cygwin/signal.h
hash.o: /usr/include/cygwin/stat.h
hash.o: /usr/include/cygwin/time.h
hash.o: /usr/include/endian.h
hash.o: /usr/include/features.h
hash.o: /usr/include/limits.h
hash.o: /usr/include/machine/_default_types.h
hash.o: /usr/include/machine/_endian.h
hash.o: /usr/include/machine/_types.h
hash.o: /usr/include/machine/endian.h
hash.o: /usr/include/machine/ieeefp.h
hash.o: /usr/include/machine/setjmp.h
hash.o: /usr/include/machine/time.h
hash.o: /usr/include/machine/types.h
hash.o: /usr/include/newlib.h
hash.o: /usr/include/setjmp.h
hash.o: /usr/include/signal.h
hash.o: /usr/include/stdio.h
hash.o: /usr/include/sys/_pthreadtypes.h
hash.o: /usr/include/sys/_sigset.h
hash.o: /usr/include/sys/_stdint.h
hash.o: /usr/include/sys/_timespec.h
hash.o: /usr/include/sys/_timeval.h
hash.o: /usr/include/sys/_types.h
hash.o: /usr/include/sys/cdefs.h
hash.o: /usr/include/sys/config.h
hash.o: /usr/include/sys/features.h
hash.o: /usr/include/sys/lock.h
hash.o: /usr/include/sys/param.h
hash.o: /usr/include/sys/reent.h
hash.o: /usr/include/sys/select.h
hash.o: /usr/include/sys/signal.h
hash.o: /usr/include/sys/stat.h
hash.o: /usr/include/sys/stdio.h
hash.o: /usr/include/sys/sysmacros.h
hash.o: /usr/include/sys/times.h
hash.o: /usr/include/sys/timespec.h
hash.o: /usr/include/sys/types.h
hash.o: /usr/include/sys/ucontext.h
hash.o: /usr/include/time.h
hash.o: /usr/include/xlocale.h
hash.o: arg.h
hash.o: array.h
hash.o: cmd.h
hash.o: config.h
hash.o: EXTERN.h
hash.o: form.h
hash.o: handy.h
hash.o: hash.c
hash.o: hash.h
hash.o: perl.h
hash.o: regexp.h
hash.o: spat.h
hash.o: stab.h
hash.o: str.h
hash.o: util.h
perly.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
perly.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
perly.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
perly.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
perly.o: /usr/include/_ansi.h
perly.o: /usr/include/_newlib_version.h
perly.o: /usr/include/bits/byteswap.h
perly.o: /usr/include/bits/endian.h
perly.o: /usr/include/bits/wordsize.h
perly.o: /usr/include/ctype.h
perly.o: /usr/include/cygwin/config.h
perly.o: /usr/include/cygwin/signal.h
perly.o: /usr/include/cygwin/stat.h
perly.o: /usr/include/cygwin/time.h
perly.o: /usr/include/endian.h
perly.o: /usr/include/features.h
perly.o: /usr/include/limits.h
perly.o: /usr/include/machine/_default_types.h
perly.o: /usr/include/machine/_endian.h
perly.o: /usr/include/machine/_types.h
perly.o: /usr/include/machine/endian.h
perly.o: /usr/include/machine/ieeefp.h
perly.o: /usr/include/machine/setjmp.h
perly.o: /usr/include/machine/time.h
perly.o: /usr/include/machine/types.h
perly.o: /usr/include/newlib.h
perly.o: /usr/include/setjmp.h
perly.o: /usr/include/signal.h
perly.o: /usr/include/stdio.h
perly.o: /usr/include/sys/_pthreadtypes.h
perly.o: /usr/include/sys/_sigset.h
perly.o: /usr/include/sys/_stdint.h
perly.o: /usr/include/sys/_timespec.h
perly.o: /usr/include/sys/_timeval.h
perly.o: /usr/include/sys/_types.h
perly.o: /usr/include/sys/cdefs.h
perly.o: /usr/include/sys/config.h
perly.o: /usr/include/sys/features.h
perly.o: /usr/include/sys/lock.h
perly.o: /usr/include/sys/param.h
perly.o: /usr/include/sys/reent.h
perly.o: /usr/include/sys/select.h
perly.o: /usr/include/sys/signal.h
perly.o: /usr/include/sys/stat.h
perly.o: /usr/include/sys/stdio.h
perly.o: /usr/include/sys/sysmacros.h
perly.o: /usr/include/sys/times.h
perly.o: /usr/include/sys/timespec.h
perly.o: /usr/include/sys/types.h
perly.o: /usr/include/sys/ucontext.h
perly.o: /usr/include/time.h
perly.o: /usr/include/xlocale.h
perly.o: arg.h
perly.o: array.h
perly.o: cmd.h
perly.o: config.h
perly.o: EXTERN.h
perly.o: form.h
perly.o: handy.h
perly.o: hash.h
perly.o: perl.h
perly.o: perly.c
perly.o: perly.h
perly.o: regexp.h
perly.o: spat.h
perly.o: stab.h
perly.o: str.h
perly.o: util.h
regexp.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
regexp.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
regexp.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
regexp.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
regexp.o: /usr/include/_ansi.h
regexp.o: /usr/include/_newlib_version.h
regexp.o: /usr/include/bits/byteswap.h
regexp.o: /usr/include/bits/endian.h
regexp.o: /usr/include/bits/wordsize.h
regexp.o: /usr/include/ctype.h
regexp.o: /usr/include/cygwin/config.h
regexp.o: /usr/include/cygwin/signal.h
regexp.o: /usr/include/cygwin/stat.h
regexp.o: /usr/include/cygwin/time.h
regexp.o: /usr/include/endian.h
regexp.o: /usr/include/features.h
regexp.o: /usr/include/limits.h
regexp.o: /usr/include/machine/_default_types.h
regexp.o: /usr/include/machine/_endian.h
regexp.o: /usr/include/machine/_types.h
regexp.o: /usr/include/machine/endian.h
regexp.o: /usr/include/machine/ieeefp.h
regexp.o: /usr/include/machine/setjmp.h
regexp.o: /usr/include/machine/time.h
regexp.o: /usr/include/machine/types.h
regexp.o: /usr/include/newlib.h
regexp.o: /usr/include/setjmp.h
regexp.o: /usr/include/signal.h
regexp.o: /usr/include/stdio.h
regexp.o: /usr/include/sys/_pthreadtypes.h
regexp.o: /usr/include/sys/_sigset.h
regexp.o: /usr/include/sys/_stdint.h
regexp.o: /usr/include/sys/_timespec.h
regexp.o: /usr/include/sys/_timeval.h
regexp.o: /usr/include/sys/_types.h
regexp.o: /usr/include/sys/cdefs.h
regexp.o: /usr/include/sys/config.h
regexp.o: /usr/include/sys/features.h
regexp.o: /usr/include/sys/lock.h
regexp.o: /usr/include/sys/param.h
regexp.o: /usr/include/sys/reent.h
regexp.o: /usr/include/sys/select.h
regexp.o: /usr/include/sys/signal.h
regexp.o: /usr/include/sys/stat.h
regexp.o: /usr/include/sys/stdio.h
regexp.o: /usr/include/sys/sysmacros.h
regexp.o: /usr/include/sys/times.h
regexp.o: /usr/include/sys/timespec.h
regexp.o: /usr/include/sys/types.h
regexp.o: /usr/include/sys/ucontext.h
regexp.o: /usr/include/time.h
regexp.o: /usr/include/xlocale.h
regexp.o: arg.h
regexp.o: array.h
regexp.o: cmd.h
regexp.o: config.h
regexp.o: EXTERN.h
regexp.o: form.h
regexp.o: handy.h
regexp.o: hash.h
regexp.o: perl.h
regexp.o: regexp.c
regexp.o: regexp.h
regexp.o: spat.h
regexp.o: stab.h
regexp.o: str.h
regexp.o: util.h
stab.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
stab.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
stab.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
stab.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
stab.o: /usr/include/_ansi.h
stab.o: /usr/include/_newlib_version.h
stab.o: /usr/include/bits/byteswap.h
stab.o: /usr/include/bits/endian.h
stab.o: /usr/include/bits/wordsize.h
stab.o: /usr/include/ctype.h
stab.o: /usr/include/cygwin/config.h
stab.o: /usr/include/cygwin/signal.h
stab.o: /usr/include/cygwin/stat.h
stab.o: /usr/include/cygwin/time.h
stab.o: /usr/include/endian.h
stab.o: /usr/include/features.h
stab.o: /usr/include/limits.h
stab.o: /usr/include/machine/_default_types.h
stab.o: /usr/include/machine/_endian.h
stab.o: /usr/include/machine/_types.h
stab.o: /usr/include/machine/endian.h
stab.o: /usr/include/machine/ieeefp.h
stab.o: /usr/include/machine/setjmp.h
stab.o: /usr/include/machine/time.h
stab.o: /usr/include/machine/types.h
stab.o: /usr/include/newlib.h
stab.o: /usr/include/setjmp.h
stab.o: /usr/include/signal.h
stab.o: /usr/include/stdio.h
stab.o: /usr/include/sys/_pthreadtypes.h
stab.o: /usr/include/sys/_sigset.h
stab.o: /usr/include/sys/_stdint.h
stab.o: /usr/include/sys/_timespec.h
stab.o: /usr/include/sys/_timeval.h
stab.o: /usr/include/sys/_types.h
stab.o: /usr/include/sys/cdefs.h
stab.o: /usr/include/sys/config.h
stab.o: /usr/include/sys/features.h
stab.o: /usr/include/sys/lock.h
stab.o: /usr/include/sys/param.h
stab.o: /usr/include/sys/reent.h
stab.o: /usr/include/sys/select.h
stab.o: /usr/include/sys/signal.h
stab.o: /usr/include/sys/stat.h
stab.o: /usr/include/sys/stdio.h
stab.o: /usr/include/sys/sysmacros.h
stab.o: /usr/include/sys/times.h
stab.o: /usr/include/sys/timespec.h
stab.o: /usr/include/sys/types.h
stab.o: /usr/include/sys/ucontext.h
stab.o: /usr/include/time.h
stab.o: /usr/include/xlocale.h
stab.o: arg.h
stab.o: array.h
stab.o: cmd.h
stab.o: config.h
stab.o: EXTERN.h
stab.o: form.h
stab.o: handy.h
stab.o: hash.h
stab.o: perl.h
stab.o: regexp.h
stab.o: spat.h
stab.o: stab.c
stab.o: stab.h
stab.o: str.h
stab.o: util.h
str.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
str.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
str.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
str.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
str.o: /usr/include/_ansi.h
str.o: /usr/include/_newlib_version.h
str.o: /usr/include/bits/byteswap.h
str.o: /usr/include/bits/endian.h
str.o: /usr/include/bits/wordsize.h
str.o: /usr/include/ctype.h
str.o: /usr/include/cygwin/config.h
str.o: /usr/include/cygwin/signal.h
str.o: /usr/include/cygwin/stat.h
str.o: /usr/include/cygwin/time.h
str.o: /usr/include/endian.h
str.o: /usr/include/features.h
str.o: /usr/include/limits.h
str.o: /usr/include/machine/_default_types.h
str.o: /usr/include/machine/_endian.h
str.o: /usr/include/machine/_types.h
str.o: /usr/include/machine/endian.h
str.o: /usr/include/machine/ieeefp.h
str.o: /usr/include/machine/setjmp.h
str.o: /usr/include/machine/time.h
str.o: /usr/include/machine/types.h
str.o: /usr/include/newlib.h
str.o: /usr/include/setjmp.h
str.o: /usr/include/signal.h
str.o: /usr/include/stdio.h
str.o: /usr/include/sys/_pthreadtypes.h
str.o: /usr/include/sys/_sigset.h
str.o: /usr/include/sys/_stdint.h
str.o: /usr/include/sys/_timespec.h
str.o: /usr/include/sys/_timeval.h
str.o: /usr/include/sys/_types.h
str.o: /usr/include/sys/cdefs.h
str.o: /usr/include/sys/config.h
str.o: /usr/include/sys/features.h
str.o: /usr/include/sys/lock.h
str.o: /usr/include/sys/param.h
str.o: /usr/include/sys/reent.h
str.o: /usr/include/sys/select.h
str.o: /usr/include/sys/signal.h
str.o: /usr/include/sys/stat.h
str.o: /usr/include/sys/stdio.h
str.o: /usr/include/sys/sysmacros.h
str.o: /usr/include/sys/times.h
str.o: /usr/include/sys/timespec.h
str.o: /usr/include/sys/types.h
str.o: /usr/include/sys/ucontext.h
str.o: /usr/include/time.h
str.o: /usr/include/xlocale.h
str.o: arg.h
str.o: array.h
str.o: cmd.h
str.o: config.h
str.o: EXTERN.h
str.o: form.h
str.o: handy.h
str.o: hash.h
str.o: perl.h
str.o: regexp.h
str.o: spat.h
str.o: stab.h
str.o: str.c
str.o: str.h
str.o: util.h
toke.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
toke.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
toke.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
toke.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
toke.o: /usr/include/_ansi.h
toke.o: /usr/include/_newlib_version.h
toke.o: /usr/include/bits/byteswap.h
toke.o: /usr/include/bits/endian.h
toke.o: /usr/include/bits/wordsize.h
toke.o: /usr/include/ctype.h
toke.o: /usr/include/cygwin/config.h
toke.o: /usr/include/cygwin/signal.h
toke.o: /usr/include/cygwin/stat.h
toke.o: /usr/include/cygwin/time.h
toke.o: /usr/include/endian.h
toke.o: /usr/include/features.h
toke.o: /usr/include/limits.h
toke.o: /usr/include/machine/_default_types.h
toke.o: /usr/include/machine/_endian.h
toke.o: /usr/include/machine/_types.h
toke.o: /usr/include/machine/endian.h
toke.o: /usr/include/machine/ieeefp.h
toke.o: /usr/include/machine/setjmp.h
toke.o: /usr/include/machine/time.h
toke.o: /usr/include/machine/types.h
toke.o: /usr/include/newlib.h
toke.o: /usr/include/setjmp.h
toke.o: /usr/include/signal.h
toke.o: /usr/include/stdio.h
toke.o: /usr/include/sys/_pthreadtypes.h
toke.o: /usr/include/sys/_sigset.h
toke.o: /usr/include/sys/_stdint.h
toke.o: /usr/include/sys/_timespec.h
toke.o: /usr/include/sys/_timeval.h
toke.o: /usr/include/sys/_types.h
toke.o: /usr/include/sys/cdefs.h
toke.o: /usr/include/sys/config.h
toke.o: /usr/include/sys/features.h
toke.o: /usr/include/sys/lock.h
toke.o: /usr/include/sys/param.h
toke.o: /usr/include/sys/reent.h
toke.o: /usr/include/sys/select.h
toke.o: /usr/include/sys/signal.h
toke.o: /usr/include/sys/stat.h
toke.o: /usr/include/sys/stdio.h
toke.o: /usr/include/sys/sysmacros.h
toke.o: /usr/include/sys/times.h
toke.o: /usr/include/sys/timespec.h
toke.o: /usr/include/sys/types.h
toke.o: /usr/include/sys/ucontext.h
toke.o: /usr/include/time.h
toke.o: /usr/include/xlocale.h
toke.o: arg.h
toke.o: array.h
toke.o: cmd.h
toke.o: config.h
toke.o: EXTERN.h
toke.o: form.h
toke.o: handy.h
toke.o: hash.h
toke.o: perl.h
toke.o: perly.h
toke.o: regexp.h
toke.o: spat.h
toke.o: stab.h
toke.o: str.h
toke.o: toke.c
toke.o: util.h
util.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/limits.h
util.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stdarg.h
util.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/stddef.h
util.o: /lib/gcc/x86_64-pc-cygwin/7.4.0/include/syslimits.h
util.o: /usr/include/_ansi.h
util.o: /usr/include/_newlib_version.h
util.o: /usr/include/bits/byteswap.h
util.o: /usr/include/bits/endian.h
util.o: /usr/include/bits/wordsize.h
util.o: /usr/include/ctype.h
util.o: /usr/include/cygwin/config.h
util.o: /usr/include/cygwin/signal.h
util.o: /usr/include/cygwin/stat.h
util.o: /usr/include/cygwin/time.h
util.o: /usr/include/endian.h
util.o: /usr/include/features.h
util.o: /usr/include/limits.h
util.o: /usr/include/machine/_default_types.h
util.o: /usr/include/machine/_endian.h
util.o: /usr/include/machine/_types.h
util.o: /usr/include/machine/endian.h
util.o: /usr/include/machine/ieeefp.h
util.o: /usr/include/machine/setjmp.h
util.o: /usr/include/machine/time.h
util.o: /usr/include/machine/types.h
util.o: /usr/include/newlib.h
util.o: /usr/include/setjmp.h
util.o: /usr/include/signal.h
util.o: /usr/include/stdio.h
util.o: /usr/include/sys/_pthreadtypes.h
util.o: /usr/include/sys/_sigset.h
util.o: /usr/include/sys/_stdint.h
util.o: /usr/include/sys/_timespec.h
util.o: /usr/include/sys/_timeval.h
util.o: /usr/include/sys/_types.h
util.o: /usr/include/sys/cdefs.h
util.o: /usr/include/sys/config.h
util.o: /usr/include/sys/features.h
util.o: /usr/include/sys/lock.h
util.o: /usr/include/sys/param.h
util.o: /usr/include/sys/reent.h
util.o: /usr/include/sys/select.h
util.o: /usr/include/sys/signal.h
util.o: /usr/include/sys/stat.h
util.o: /usr/include/sys/stdio.h
util.o: /usr/include/sys/sysmacros.h
util.o: /usr/include/sys/times.h
util.o: /usr/include/sys/timespec.h
util.o: /usr/include/sys/types.h
util.o: /usr/include/sys/ucontext.h
util.o: /usr/include/time.h
util.o: /usr/include/xlocale.h
util.o: arg.h
util.o: array.h
util.o: cmd.h
util.o: config.h
util.o: EXTERN.h
util.o: form.h
util.o: handy.h
util.o: hash.h
util.o: perl.h
util.o: regexp.h
util.o: spat.h
util.o: stab.h
util.o: str.h
util.o: util.c
util.o: util.h
version.o: patchlevel.h
version.o: version.c
: Makefile.SH config.sh ; /bin/sh Makefile.SH
: makedepend.SH config.sh ; /bin/sh makedepend.SH
# WARNING: Put nothing here or make depend will gobble it up!
