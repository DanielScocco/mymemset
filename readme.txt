MC504 - Projeto 2
Daniel Scocco - RA 121937

DESCRICAO
mymemset.c e uma chamada de sistema que preenche um vetor de chars ou de ints
com o valor passado como parametro. Ela e uma modificacao da funcao memset
tradicional, que funciona somente com chars. 

IMPLEMENTACAO
1. Alterar linux-3.12/arch/x86/syscalls/syscall_32.tlb, adicionando:
	351     i386    mymemset                  sys_mymemset

2. Copiar mymemset.c para linux-3.12/arch/x86/kernel/

3. Incluir uma declaração da função sys_memset em linux-3.12/include/linux/syscalls.h
	asmlinkage long sys_memset(int, int, void*, int);

4. Alterar o Makefile do diretório linux-3.12/arch/x86/kernel/, incluindo uma linha:
	obj-y                                   += mymemset.o

Feito isso basta re-compilar o kernel e testar a syscall com memsetTest.c
