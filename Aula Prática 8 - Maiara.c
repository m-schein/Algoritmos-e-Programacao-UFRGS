#include <stdio.h>
#include <ctype.h>

//Questão A)
void imprimeMenu(){
  printf("\n\n(N) - Novo Jogo\n(C) - Carregar Jogo\n(M) - Mostrar Créditos\n(S) - Sair\n\n");
}

//Questão B)
char validaEntrada(){
 char qualquer;
   printf("Digite qual opção do menu você quer:\n");
  
  do{
    scanf(" %c", &qualquer);
    qualquer = toupper(qualquer);

    if((qualquer != 'N')&&(qualquer != 'C')&&(qualquer != 'M')&&(qualquer != 'S')){
      printf("Opção inválida! Digite novamente:\n");
      scanf("%c", &qualquer);
      qualquer = toupper(qualquer);
    }
  }while((qualquer != 'N')&&(qualquer != 'C')&&(qualquer != 'M')&&(qualquer != 'S'));

  return qualquer;
}

//Questão C)
void mensagem(char qualquer){

  char nomeJogador[10];

  if(qualquer == 'N'){
    printf("\n\nDigite o seu nome: ");
    scanf(" %[^\n]", nomeJogador);
    printf("\n\nJogador(a) %s: se prepare, jogo iniciando!\n", nomeJogador);
  }else if (qualquer == 'C'){
    printf("\n\nCarregando a lista de jogos salvos, aguarde um minuto.\n");
  }else if (qualquer == 'M'){
    printf("\n\nMaiara Schein\n275946\n");
  }else if(qualquer == 'S'){
    printf("\n\nEncerrando o jogo, ateh a proxima!\n");
  }
}

//Questão D)
int main() {

  char entrada;
  
  do{
    printf("\n\n==================\n");
    printf(" Lolo's Adventure\n");
    printf("==================");
    imprimeMenu();
    entrada = validaEntrada();
    mensagem(entrada);
    printf("\n");
  }while(entrada != 'S');

  return 0;
}