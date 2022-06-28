#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define NUM 2
#define MX_TYPE long double // tipo dos elementos da matriz
#define ID_TYPE long int // tipo dos índices da matriz

int main(int argc, char **argv)
{
  
  // criando e inicializando as matrizes 1, 2 e 3 (a matriz 3 inicializada com zeros):
  printf("\n*versão serial*\n\n");
  printf("criando as matrizes 1, 2 e 3...");

  MX_TYPE   *m1_1d,
            *m2_1d,
            *m3_1d;

  ID_TYPE i, j, k;

  m1_1d= malloc(NUM * NUM * sizeof(MX_TYPE));
  m2_1d= malloc(NUM * NUM * sizeof(MX_TYPE));
  m3_1d= calloc(NUM * NUM, sizeof(MX_TYPE));
  printf("OK\n");

  // inicializando os valores da matriz 1 e 2 (utilizando os valores dos índices)
  printf("inicializando matrizes 1 e 2...");

  for(i = 0; i<NUM; i++){
    for(j = 0; j<NUM; j++){
      m1_1d[NUM*i+j] = i;
      m2_1d[NUM*i+j] = j;
    }
  }
  printf("OK\n");
  
  //iniciar mpi codigo dividido em processos a partir daqui
  MX_TYPE accum = 0;
  long start, end;
  
  MPI_Status status;  
  MPI_Init(NULL, NULL);
  // Find out rank, size
  int world_rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  int world_size;
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  
  start = NUM * world_rank / world_size + 1;
  end = NUM * (world_rank + 1) / world_size;
  
  printf("multiplicando matrizes 1 e 2..."); 
  for(i=start;i<end;i++){
    for(j=0;j<NUM;j++){
      for(k=0;k<NUM;k++){
        m3_1d[NUM*i+j] += m1_1d[NUM*i+k] * m2_1d[NUM*k+j];
      }
    }
  }
  // slaves
  if (world_rank != 0) {
    // If we are rank 0, set the number to -1 a  nd send it to process 1
    // multiplicando matrizes 1 e 2, salvando resultado na matriz 3
    MPI_Send(m3_1d, 1, MPI_LONG_DOUBLE, 0, 1, MPI_COMM_WORLD);
   
  } 
  
  else  { // master
    for(i=1;i<world_size;i++){
      for(j=0;j<NUM;j++){
        for(k=0;k<NUM;k++){
          MPI_Recv(&accum, 1, MPI_LONG_DOUBLE, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
          m3_1d[NUM*i+j] = 
        }  
      }
      
    }
  }
  
  printf("OK\n");
  for(i = 0; i<NUM; i++){
    for(j = 0; j<NUM; j++){
      printf("%Lf ", m3_1d[NUM*i+j]);
    }
  }
  
  MPI_Finalize();


  
  // salvando a matriz 3 em um arquivo para conferência no código paralelo
  printf("salvando matriz resultado no arquivo 'mx.data'...");

  int written = 0;
  FILE *f = fopen("mx.data", "wb");
  written = fwrite(m3_1d, sizeof(MX_TYPE), NUM*NUM, f);
  if (written == 0){
    printf("erro durante escrita para o arquivo !\nabortando...\n");
    return -1;
  }
  else printf("OK\n");
  fclose(f);

  // desalocando memória das matrizes:
  printf("\ndesalocando memória...");
  free(m1_1d);
  free(m2_1d);
  free(m3_1d);
  printf("OK\n");

  return 0;
}
