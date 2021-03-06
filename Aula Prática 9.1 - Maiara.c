#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 150

void conta_vogais_consoantes(char* string, int len, int* vogais, int*
consoantes){
  int conta_vog = 0, conta_cons = 0, i;
  for(i=0; i<len; i++){
    *(string+i) = toupper(*(string+i));
    if((*(string+i)>=65) && (*(string+i)<=90)){
      if((*(string+i) == 65)||(*(string+i) == 69)||(*(string+i) == 73)||(*(string+i) == 79)||(*(string+i) == 85)){
        conta_vog++;

      }else{
        conta_cons++;
      }
    }  
  }
  *vogais = conta_vog;
  *consoantes = conta_cons;
}

int main() {
  int vogais, consoantes,numCaracteres;
  char string[MAX];
  printf("\n\nDigite uma frase com até 150 caracteres:\n");
  scanf(" %[^\n]", string);

  numCaracteres = strlen (string);
  
  conta_vogais_consoantes(string, numCaracteres, &vogais, &consoantes);

  printf("\n\nVogais: %d \nConsoantes: %d",vogais, consoantes);

 return 0;
}