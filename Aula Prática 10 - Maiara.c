#include <stdio.h>
#define TAM 5

struct jogador_st {
int totalpts;
int fase;
int vidas;
char nomejogador[9];
};

struct jogador_st leDadosJogador() {
  struct jogador_st jogadorQualquer;
  printf("\nIndique o total de pontos do jogador: ");
  scanf("%d", &jogadorQualquer.totalpts);
  printf("\nIndique a fase em que o jogador se encontra: ");
  scanf("%d", &jogadorQualquer.fase);
  printf("\nIndique a quantidade de vidas do jogador: ");
  scanf("%d", &jogadorQualquer.vidas);
  printf("\nIndique o nome do jogador: ");
  scanf(" %[^\n]", jogadorQualquer.nomejogador);
  return jogadorQualquer;
}

void imprimeDadosJogador(struct jogador_st jog){
  printf("\n\n========================\n");
  printf("    Dados do jogador\n");
  printf("========================\n");
  printf("\nJogador: %s", jog.nomejogador);
  printf("\nVidas: %d", jog.vidas);
  printf("\nTotal de pontos: %d", jog.totalpts);
  printf("\nFase: %d\n\n", jog.fase);
}

struct jogador_st maiorPontuacao(struct jogador_st jog[TAM]){
  int maior = 0, i;
  struct jogador_st jogVencedor;
  for(i=0;i<TAM;i++){
    if(i == 0 || jog[i].totalpts > maior){
      maior = jog[i].totalpts;
      jogVencedor = jog[i];
    }
  }
  return jogVencedor;
}

int main() {

  int i, maior;
  //PROBLEMA 1)
  printf("\n\n\nPROBLEMA 1)\n");
  struct jogador_st jogador;
  jogador = leDadosJogador();
  imprimeDadosJogador(jogador);

  //PROBLEMA 2)
  printf("\n\n\n\n\nPROBLEMA 2)\n");
  struct jogador_st vetorJog[TAM], jogVencedor;
  for(i=0;i<TAM;i++){
    vetorJog[i] = leDadosJogador();
    imprimeDadosJogador(vetorJog[i]);
  }

  jogVencedor = maiorPontuacao(vetorJog);
  printf("\n\n\n\n***********************");
  printf("\n\nJogador com maior pontuação: %s \nTotal de pontos: %d\nVidas: %d\nFase: %d", jogVencedor.nomejogador, jogVencedor.totalpts, jogVencedor.vidas, jogVencedor.fase);
  
  return 0;
}