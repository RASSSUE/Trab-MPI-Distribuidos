#include <stdio.h>
#include <stdlib.h>
#define NUM 1000

int main()
{

  int **m1,**m2,**m3, i, j, k;
  m1= calloc(NUM, sizeof(int *));
  m2= calloc(NUM, sizeof(int *));
  m3= calloc(NUM, sizeof(int *));

  for(i=0; i<NUM; i++){
    m1[i] = calloc(NUM, sizeof(int));
  }
  for(i=0; i<NUM; i++){
    m2[i] = calloc(NUM, sizeof(int));
  }
  for(i=0; i<NUM; i++){
    m3[i] = calloc(NUM, sizeof(int));
  }

  printf("Digite os valores da matriz\n");

  for(i = 0; i<NUM; i++){
    for(j=0; j<NUM; j++){
      m1[i][j]=1;
      m2[i][j]=1;
      m3[i][j]=0;
    }
  }
  printf("Matriz 1\n");

  for(i = 0; i<NUM; i++){
    for(j=0; j<NUM; j++){
      printf("%d, ", m1[i][j]);
    }
    printf("\n");
  }
  printf("Matriz 2\n");

  for(i = 0; i<NUM; i++){
    for(j=0; j<NUM; j++){
      printf("%d, ", m2[i][j]);
    }
    printf("\n");
  }

  //desalocando mem ́oria usada
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      for(k=0;k<NUM;k++){
        m3[i][j] += m1[i][k] * m1[k][j];
       }
    }
  }
  printf("Matriz 3\n");

  for(i = 0; i<NUM; i++){
    for(j=0; j<NUM; j++){
      printf("%d, ", m3[i][j]);
    }
    printf("\n");
  }

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

}
