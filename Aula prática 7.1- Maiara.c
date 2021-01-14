#include <stdio.h>
#define tamanho 3

int main() {
  int matriz[tamanho][tamanho], i, j, somaDiagonal = 0, maiorValor = 0;
  
  printf("\nLetra A)\nDigite 9 números inteiros para compor uma matriz %dx%d!\n\n", tamanho, tamanho);

 for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      scanf("%d", &matriz[i][j]);
    }
 }

  printf("\n\n");

  for(i=0;i<tamanho;i++){
    for(j=0;j<tamanho;j++){
      
      printf("%6d", matriz[i][j]);
      if(i == j){
        somaDiagonal += matriz[i][j];
      }
      if(matriz[i][j]>maiorValor){
        maiorValor = matriz[i][j];
      }
    }
    printf("\n\n");
  }
  printf("\nLetra B)\nSoma da diagonal: %d\n\n", somaDiagonal);

  printf("\nLetra C)\nMaior valor da matriz: %d\n", maiorValor);

  return 0;
}