/*
    This file is part of libcmp134

    libcmp134 is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libcmp134 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with libcmp134. If not, see <http://www.gnu.org/licenses/>.
*/
#include "cmp134.h"

//next function has been found here:
//http://stackoverflow.com/questions/26237419/faster-than-rand
//all credits to the authors there
static unsigned int g_seed;
inline int fastrand()
{
  g_seed = (214013*g_seed+2531011);
  return (g_seed>>16)&0x7FFF;
}

double cmp134_gettime (void)
{
  struct timeval tr;
  gettimeofday(&tr, NULL);
  return (double)tr.tv_sec+(double)tr.tv_usec/1000000;
}

double *cmp134_create_matrix (int size)
{
  double *matrix = calloc(size*size,sizeof(double));
  /* Error checking */
  int i;
  for (i=0; i < size*size; i++){
    matrix[i] = (double) fastrand();
  }
  return matrix;
}

void cmp134_free_matrix (double *matrix)
{
  free(matrix);
}

