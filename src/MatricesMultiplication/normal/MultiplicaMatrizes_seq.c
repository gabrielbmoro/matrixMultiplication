
/*###########################
 *Autor: Gabriel B Moro
 *---------------------------
 *Programa sequencial: 
 *Multiplicação de Matrizes
 *###########################
 */

#include <stdio.h>
#include "cmp134.h"

int main(int argc, char *argv[]) 
{
	/*Inicializacao de variaveis*/
	int size=10;

	double **A, **B, **R;

	if (argc > 1){
	  size = atoi(argv[1]);
	}

	/*Inicialização das matrizes*/
	A = cmp134_create_matrix (size);
	B = cmp134_create_matrix (size);
	R = cmp134_create_matrix (size);

	CMP134_DECLARE_TIMER;
	CMP134_START_TIMER;

	/*Multiplicacao das matrizes matA e matB*/
	int i,j,k;
	double tmp=0.0;
	
	for(i=0;i < size; i++)
	{
		for(j=0;j < size; j++)
		{
			tmp=0;
			for(k=0; k < size; k++)
				tmp = tmp + A[i][k] * B[k][j];
			R[i][j] = tmp;
		}
	}

	CMP134_END_TIMER;
	CMP134_REPORT_TIMER;

	/*Temos que imprimir isso se não o compilador 
	não faz a multiplicação por não se justificar essa operação*/
	
	printf("The last element is %.2f\n", R[size-1][size-1]);

	cmp134_free_matrix(A,size);
	cmp134_free_matrix(B,size);
	cmp134_free_matrix(R,size);
	
	return 0;
}