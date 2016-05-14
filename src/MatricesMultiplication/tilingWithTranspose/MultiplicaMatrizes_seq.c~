
/*###########################
 *Autor: Gabriel B Moro
 *---------------------------
 *Programa sequencial: 
 *Multiplicação de Matrizes
 *###########################
 */

#include <stdlib.h>
#include <stdio.h>
#include "cmp134.h"

void transpose(double **B, int size)
{
	int i,j;

	for(i=0; i < size; i++)
	{
		for(j=0; j < size; j++)
		{
			B[i][j] = B[j][i];
		}
	}
}

int min(int x, int y)
{
	if(x<y)
		return x;
	else
		return y;
}

int main(int argc, char *argv[]) 
{
	/*Inicializacao de variaveis*/
	int size=10,block=2;
	double **A, **B, **R;

	if (argc > 1){
	  size = atoi(argv[1]);
	}

	/*Define aqui de acordo com tua máquina, 16, 32, 64 por ai, pra mim ficou massa com 64 pra 1000 elementos*/
	block= 64;

	/*Inicialização das matrizes*/
	A = cmp134_create_matrix (size);
	B = cmp134_create_matrix (size);
	R = cmp134_create_matrix (size);

	CMP134_DECLARE_TIMER;
	CMP134_START_TIMER;

	int i,j,jj,k,kk;
	double tmp;

	transpose(B, size);

	for(jj=0;jj < size; jj=jj+block)
	{
		for(kk=0; kk < size; kk=kk+block)
		{
			for(i=0; i < size; i++)
			{
				for(j=jj; j < min(jj+block, size); j++)
				{
					tmp=0;
					for(k=kk; k < min(kk+block,size); k++)
					{
						tmp =+ A[i][k] * B[i][k];
					}
					R[i][j] = tmp;
				}
			}
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