#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#define MIN 0
#define MAX 100
#define NCOL 6
#define NLIN 3

int omaior(int matriz[][NCOL], int num_lin, int num_col, int *pos_lin, int *pos_col){
  int i, j, maior = 0;
  for(i=0;i<num_lin;i++){
    for(j=0;j<num_col;j++){
       if((matriz[i][j] > maior)||(i == 0 && j == 0)){
        maior = matriz[i][j];
        *pos_lin = i+1;
        *pos_col = j+1;
      }
    }
  }
  return maior;
}



int main() {

  srand(time(NULL));
  int matriz[NLIN][NCOL], i, j, pos_lin, pos_col, maior;
  printf("\n\n");
  for(i=0;i<NLIN;i++){
    for(j=0;j<NCOL;j++){
      matriz[i][j] = (MIN + (rand() % (MAX - MIN + 1)));
      printf("%5d", matriz[i][j]);
    }
    printf("\n\n");
  }

  maior = omaior(matriz, NLIN, NCOL, &pos_lin, &pos_col);
  printf("\nMaior número da matriz: %d \nPosição da linha: %d\nPosição da coluna: %d", maior, pos_lin, pos_col);

  return (0);
}