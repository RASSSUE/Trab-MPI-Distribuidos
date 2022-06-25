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

/*
    int equalmxs(MX_TYPE **mx, MX_TYPE *mx_1d)

    descrição:  essa função verifica se as matrizes são iguais,
                e pode ser utilizada para checar o resultado sem a
                necessidade de exibir a matriz

    **mx        ponteiro para a matriz 2D
    *mx_1d      ponteiro para a matriz 1D

    retorno:    retorna 1 para matrizes iguais, 0 caso contrário

*/
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
    /*
        mx1         matriz convencional (2D)
        mx1_1d      matriz 1D
    */
    
    // criando as matrizes

    MX_TYPE **mx1 = malloc(NUM * sizeof(MX_TYPE *));
    ID_TYPE i,j;
    for(i=0;i<NUM;i++){
        mx1[i] = malloc(NUM * sizeof(MX_TYPE));
    }

    MX_TYPE *mx1_1d = malloc(NUM * NUM * sizeof(MX_TYPE));

    // inicializando matriz 1D

    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            mx1_1d[3*i+j]=3*i+j;
        }
    }

    // copiando matriz 1D para matriz 2D e exibindo
    // o resultado

    for(i=0;i<NUM;i++){
        for(j=0;j<NUM;j++){
            mx1[i][j]=mx1_1d[3*i+j];
            printf("%Lf ",mx1[i][j]);
        }
        printf("\n");
    }

    // liberando memória
    
    for(i=0;i<NUM;i++){
        free(mx1[i]);
    }
    free(mx1);
    free(mx1_1d);

    return 0;
}