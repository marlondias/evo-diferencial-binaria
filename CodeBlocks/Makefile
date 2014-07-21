sources = av.c deb.c doio.c doop.c dump.c globals.c gv.c hv.c locale.c mg.c numeric.c op.c pad.c perl.c perlapi.c perlio.c perlmain.c perly.c pp.c pp_ctl.c pp_hot.c pp_pack.c pp_sort.c pp_sys.c regcomp.c regexec.c run.c scope.c sv.c taint.c toke.c universal.c utf8.c util.c xsutils.c Base64.c Cwd.c Dumper.c HiRes.c IO.c Peek.c attrs.c poll.c stdio.c DynaLoader.c MD5.c Storable.c Parser.c specrand.c Hostname.c Opcode.c
 cc_opts = -c -I. -DSPEC_CPU -DNDEBUG -DPERL_CORE -DSPEC_CPU_LP64 -DSPEC_CPU_LINUX_X64
exec = /home/anderson/Projetos/MSOF/resultados/ordering.lkh/execs/400.perlbench.n.15.0
libs = -lm 

OPT_OPTS = 
SOURCES = $(sources)
EXE = $(exec)
CC_OPTS = $(cc_opts)
LD_OPTS = $(ld_opts)
CC_OBJS = $(sources:.c=.o)
LIBS_A = $(libs_a)
LIB_OBJS = $(lib_objs)
LIBS = $(libs)
INCLUDES = $(includes)
CC = clang
AS = as
LD = ld
OPT = opt
LLC = llc
$(EXE): $(CC_OBJS)
	$(CC) -w $(CC_OBJS) $(LIBS_A) $(LD_OPTS) -o $(EXE) $(LIBS)
	rm -f $(CC_OBJS)
%.o: %.c $(INCLUDES)
	$(CC) -w $(CC_OPTS) -emit-llvm -O0 -c $< -o $@.bc
	$(OPT) $(OPT_OPTS) -stats -instcount $@.bc -o $@.opt.bc 2> $@.opt.stats
	rm -f $@.bc
	$(LLC) -O2 -stats -mcpu=x86-64 $@.opt.bc -o $@.s 2> $@.llc.stats
	rm -f $@.opt.bc
	$(AS) $@.s -o $@
	rm -f $@.s
clean:
	rm -f $(EXE)
	rm -f $(CC_OBJS)
	rm -f *.stats










































































