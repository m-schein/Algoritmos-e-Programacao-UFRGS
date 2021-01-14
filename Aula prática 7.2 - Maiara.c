#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<math.h>
#define MIN 700
#define MAX 950
#define jogadores 6
#define lancamentos 3

int main() {

  srand(time(NULL));
  int matriz[lancamentos][jogadores], i, j, alvo, dif[lancamentos][jogadores], menor, maior = 0, posicaoVencedor, posicaoPerdedor;
  
  alvo = (MIN + (rand() % (MAX - MIN + 1)));
  printf("\n\nAlvo: %d\n\n", alvo);
  printf("\nLançamentos:\n\n\n");
  printf("Tentativa/\nJogador     ");

  for(j=0;j<jogadores;j++){
    printf("%5d",j+1);
  }
    printf("\n\n");
  

  for(i=0;i<lancamentos;i++){
    printf("Tentativa %d  ", i+1);
    for(j=0;j<jogadores;j++){
      matriz[i][j] = (MIN + (rand() % (MAX - MIN + 1)));
      printf("%5d", matriz[i][j]);
      dif[i][j] = abs(matriz[i][j] - alvo);
    
      if((dif[i][j] > maior)||(i == 0 && j == 0)){
        maior = dif[i][j];
        posicaoPerdedor = j+1;
      }
    }
    printf("\n\n");
  }

  for(j=0;j<jogadores;j++){
    for(i=0;i<lancamentos;i++){
      if((dif[i][j] < menor)||(i == 0 && j == 0)){
        menor = dif[i][j];
        posicaoVencedor = j+1;
      }
    }
  }
  

 printf("\n\nMatriz da diferença entre lançamentos e alvo\nApenas para conferir as respostas!\n\n");//para visualizar se o programa está imprimindo os valores certos
  for(i=0;i<lancamentos;i++){
    for(j=0;j<jogadores;j++){
       printf("%5d", dif[i][j]);
    } 
    printf("\n\n");
  }

  printf("\n\nRESULTADOS:\n");
  printf("\nO esportista %d foi quem ganhou o jogo: %d cm do alvo.", posicaoVencedor, menor);
  printf("\n\nO esportisa %d foi quem teve maior variação nos lancamentos: %d cm", posicaoPerdedor, maior);

  return (0);

}
