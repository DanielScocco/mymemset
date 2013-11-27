/**************************************************************/
/*                MC504 - Projeto 2                           */
/*             Daniel Scocco - RA121937                       */
/*                                                            */
/*             Syscall que implementa um memset modificado,   */
/*             podendo ser usado para preencher um array de   */
/*             chars (option=1) ou de ints (option=2)         */
/*                                                            */
/**************************************************************/

#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/slab.h>

/********* Description of parameters *********************/
/* int option: 1 for array of chars, 2 for array of its  */
/* int value: value to fill array                        */
/* void* ptr: pointer to the array                       */
/* int size: number of elements in the array             */
/*********************************************************/

asmlinkage long mymemset(int option, int value, void* ptr, int size){
	char c = (char) value;
	char arr[4];
	int i,j;

	/*fill with chars*/
	if(option==1){
		memset(ptr,c,size);
	}
	/*fill with ints*/
	else if(option==2){
		for (i=0;i<4;i++){
			arr[i] = (char) value;
			value = value >> 8;
		}			
		for(i=0;i<size;i++){
			for(j=0;j<4;j++){
				memset(ptr+j+i*4,arr[j],1);
			}
		}
	}
	
	return 0;
}
