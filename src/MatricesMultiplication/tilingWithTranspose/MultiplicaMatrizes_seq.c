
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

#define HIDE_TIMER 0

int min(int, int);

void transposeInplace(double **, int);

void printerOfMatrix(double **, int);

int main(int argc, char *argv[]) 
{
	/*Inicializacao de variaveis*/
	int size=10,block;
	double **A, **B, **R;

	if (argc > 1){
	  size = atoi(argv[1]);
	}

	/*Define aqui de acordo com tua máquina, 16, 32, 64 por ai, pra mim ficou massa com 64 pra 1000 elementos*/
	block= 16;

	/*Inicialização das matrizes*/
	A = cmp134_create_matrix (size);
	B = cmp134_create_matrix (size);
	R = cmp134_create_matrix (size);

	CMP134_DECLARE_TIMER;
	CMP134_START_TIMER;

	int i,j,jj,k,kk;
	double tmp;

	transposeInplace(B, size);
	
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
						tmp = tmp + A[i][k] * B[j][k];
					}
					R[i][j] = tmp;
				}
			}
		}
	}

	CMP134_END_TIMER;

	if(HIDE_TIMER!=1)
	{
		CMP134_REPORT_TIMER;
		/*Temos que imprimir isso se não o compilador 
		não faz a multiplicação por não se justificar essa operação*/
		//printf("The last element is %.2f\n", R[size*size-1]);
	}else
	{
		printerOfMatrix(R,size);
	}

	cmp134_free_matrix(A,size);
	cmp134_free_matrix(B,size);
	cmp134_free_matrix(R,size);
	
	return 0;

}

void transposeInplace(double **B, int size)
{
	int i,j;
	double tmp=0;
	for(i = 0; i < size; i++)
	{
		for(j=i+1; j < size; j++)
		{
			tmp = B[i][j];
			B[i][j] = B[j][i];
			B[j][i] = tmp;
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

void printerOfMatrix(double **R, int size)
{
	int i,j;

	for(i=0; i < size; i++)
	{
		for(j=0; j < size; j++)
			 printf("%f\t", R[i][j]);
	    printf("\n");
	}
}
