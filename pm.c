#include <stdio.h>
#include <stdlib.h>
#define NUM 2000

int main()
{
  
  // criando e inicializando as matrizes 1, 2 e 3 (a matriz 3 inicializada com zeros):

  long double **m1,**m2,**m3;
  int i, j, k;
  m1= malloc(NUM * sizeof(long double *));
  m2= malloc(NUM * sizeof(long double *));
  m3= malloc(NUM * sizeof(long double *));

  for(i=0;i<NUM;i++){
    m1[i] = malloc(NUM * sizeof(long double));
  }
  for(i=0;i<NUM;i++){
    m2[i] = malloc(NUM * sizeof(long double));
  }
  for(i=0;i<NUM;i++){
    m3[i] = calloc(NUM,sizeof(long double));
  }

  // inicializando os valores da matriz 1 e 2 (utilizando os valores dos índices)

  for(i = 0; i<NUM; i++){
    for(j = 0; j<NUM; j++){
      m1[i][j]=i;
      m2[i][j]=j;
    }
  }

  // multiplicando matrizes 1 e 2, salvando resultado na matriz 3

  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      for(k=0;k<NUM;k++){
        m3[i][j] += m1[i][k] * m1[k][j];
       }
    }
  }

  // desalocando memória das matrizes:

  for(i=0; i<NUM; i++){
    free(m1[i]);
  }
  for(i=0; i<NUM; i++){
    free(m2[i]);
  }
  for(i=0; i<NUM; i++){
    free(m3[i]);
  }
  free(m1);
  free(m2);
  free(m3);

  return 0;
}
