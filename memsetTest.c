/**************************************************************/
/*                MC504 - Projeto 2                           */
/*             Daniel Scocco - RA121937                       */
/*                                                            */
/*             Funcao para testar a syscall myMemset()        */
/*                                                            */
/**************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	char v[10];
	int v2[10];
	int i;
	
	for(i=0;i<10;i++){
		v[i] = 'a';
		v2[i] = 22;
	}

	syscall(351,1,'z',v,10);
	syscall(351,2,1098,v2,10);

	for(i=0;i<10;i++){
		printf("%c\n",v[i]);
	}
	for(i=0;i<10;i++){
		printf("%d\n",v2[i]);
	}

	return 0;

}
