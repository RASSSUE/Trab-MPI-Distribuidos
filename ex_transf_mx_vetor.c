// exemplo de transformação de matriz em vetor

/*
  lógica utilizada:

  0 1 2   0   1   2   0   1   2   0   1   2
  0 1 2   0+0 0+1 0+2 3+0 3+1 3+2 6+0 6+1 6+2
  0 1 2   0   1   2   3   4   5   6   7   8

  m[i][j] = m1_1d[3*i+j]

*/

#include <stdio.h>
#include <stdlib.h>

#define NUM 3 // comprimento/largura da matriz
#define MX_TYPE long double // tipo dos elementos da matriz
#define ID_TYPE long int // tipo dos índices da matriz

int equalmxs(MX_TYPE **mx, MX_TYPE *mx_1d){
    ID_TYPE i,j;
    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            if(mx[i][j]!=mx_1d[3*i+j]) return 0;
        }
    }
    return 1;
}
int main(void){
    // mx1 matriz convencional,     mx1_1d matriz de 1 Dim.
    MX_TYPE **mx1 = malloc(NUM * sizeof(MX_TYPE *));
    ID_TYPE i,j;
    for(i=0;i<NUM;i++){
        mx1[i] = malloc(NUM * sizeof(MX_TYPE));
    }

    MX_TYPE *mx1_1d = malloc(NUM * NUM * sizeof(MX_TYPE));
    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            mx1_1d[3*i+j]=3*i+j;
        }
    }
    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            mx1[i][j]=mx1_1d[3*i+j];
            printf("%Lf ",mx1[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<NUM;i++){
        free(mx1[i]);
    }
    free(mx1);
    free(mx1_1d);

    return 0;
}