#include <stdio.h>
#include <string.h>

void escreveEstatisticas(char *filename, int totalEntrevistados, int totalFumantes, int homemAbaixo40NaoFumante, int homens, int mulherAbaixo40NaoFumante, int mulheres){
  FILE * estatisticas;
  if(!(estatisticas = fopen("estatisticas.txt","a"))){
    printf("Erro na abertura\n"); 
  }else{
  fprintf(estatisticas,"Numero total de entrevistados: %d\n", totalEntrevistados);
  fprintf(estatisticas,"Percentual de fumantes em relacao ao numero total de entrevistados: %.2f%%\n",((float)totalFumantes/(float)totalEntrevistados)*100);
  fprintf(estatisticas,"Percentual de homens não fumantes abaixo de 40 anos em relação ao número total de homens entrevistados: %.2f%%\n", ((float)homemAbaixo40NaoFumante/(float)homens)*100);
  fprintf(estatisticas,"Percentual de mulheres não fumantes abaixo de 40 anos em relação ao número total de mulheres entrevistadas: %.2f%%\n", ((float)mulherAbaixo40NaoFumante/(float)mulheres)*100);
  }
  fclose(estatisticas);
}

int main() {

  int idade, totalEntrevistados = 0, totalFumantes = 0, homemAbaixo40NaoFumante = 0, mulherAbaixo40NaoFumante = 0, mulheres = 0, homens = 0;

  char sexo[2], fumante[2], f[2] = {'S'}, n[2] = {'N'}, mulher[2] = {'F'}, homem[2] = {'M'};

  FILE *arquivoprincipal, *fumantes, *naofumantes;

  if ( !(arquivoprincipal=fopen("dados.txt", "r")) )
   printf("Erro ao abrir arquivo!\n");
  else {
    while(!(feof(arquivoprincipal))){ //enquanto nao chegar ao final do arquivo de dados, faça:
      fscanf(arquivoprincipal, "%s %d %s", sexo, &idade, fumante);
      if(strcmp(fumante,f) == 0){ //adiciona fumantes à um outro arquivo
        if(!(fumantes = fopen("fumantes.txt","a")))
          printf("Erro na abertura\n");
        else{
          fprintf(fumantes, "%s %d %s\n", sexo, idade, fumante);
        }
          fclose(fumantes);
          totalFumantes++;
      }else if (strcmp(fumante,n) == 0){ //adiciona não fumantes à um outro arquivo
        if(!(naofumantes = fopen("naofumantes.txt","a")))
          printf("Erro na abertura\n"); 
        else{
          fprintf(naofumantes, "%s %d %s\n", sexo, idade, fumante);
          if((idade < 40) && (strcmp (sexo, homem))){
            homemAbaixo40NaoFumante++;
          }else if((idade < 40) && (strcmp (sexo, mulher))){
            mulherAbaixo40NaoFumante++;
          }
        }
        fclose(naofumantes);
      }
      if(strcmp(sexo, mulher)){//contagem do total de mulheres
        mulheres++;
      }else if (strcmp(sexo, homem)){//contagem do total de homens
        homens++;
      }
      totalEntrevistados++;
    }
  }
  fclose(arquivoprincipal);

  escreveEstatisticas("estatisticas.txt", totalEntrevistados, totalFumantes, homemAbaixo40NaoFumante, homens, mulherAbaixo40NaoFumante, mulheres);

  return 0;
}