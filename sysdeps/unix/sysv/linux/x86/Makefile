# We don't need any header files.
abi-includes :=

abi-variants := 32 64 x32

abi-32-options := -D__i386__ -U__x86_64__
abi-32-condition := !defined __x86_64__
abi-64-options := -U__i386__ -D__x86_64__ -U__ILP32__ -D__LP64__
abi-64-condition := defined __x86_64__ && defined __LP64__
abi-x32-options := -U__i386__ -D__x86_64__ -D__ILP32__ -U__LP64__
abi-x32-condition := defined __x86_64__ && defined __ILP32__

ifeq ($(subdir),misc)
sysdep_headers += sys/elf.h sys/perm.h sys/reg.h sys/vm86.h sys/debugreg.h sys/io.h
endif

ifeq ($(subdir),nptl)
libpthread-sysdep_routines += elision-lock elision-unlock elision-timed \
			      elision-trylock
endif

ifeq ($(subdir),elf)
sysdep_routines += dl-vdso
endif

# Always build relocatable objects with <sys/cet.h> which is unused if
# IBT and SHSTCK are disabled.
CPPFLAGS-.o += -include $(..)sysdeps/unix/sysv/linux/x86/sys/cet.h
CPPFLAGS-.os += -include $(..)sysdeps/unix/sysv/linux/x86/sys/cet.h
CPPFLAGS-.op += -include $(..)sysdeps/unix/sysv/linux/x86/sys/cet.h
