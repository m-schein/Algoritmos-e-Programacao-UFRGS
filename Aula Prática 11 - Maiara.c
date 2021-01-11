#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct {
char nome[80];
char telefone[15];
char vinculo[30];
int sala;
int predio;
} funcionario_st;

void addFuncionario(char * filename){
  funcionario_st funcionarioAdd;
  FILE *arquivo;
  arquivo = fopen(filename,"ab");
  if(!(arquivo = fopen(filename, "ab"))){
    printf("Erro na abertura do arquivo");
  } else {
    
    printf("\n\nDigite o nome do funcionário: ");
    scanf(" %[^\n]", funcionarioAdd.nome);
    printf("\nDigite o telefone do funcionário: ");
    scanf(" %[^\n]", funcionarioAdd.telefone);
    printf("\nDigite o status do vínculo do funcionário: ");
    scanf(" %[^\n]",funcionarioAdd.vinculo);
    printf("\nDigite a sala do funcionario: ");
    scanf("%d", &funcionarioAdd.sala);
    printf("\nDigite o número do prédio do funcionário: ");
    scanf("%d", &funcionarioAdd.predio);
    fwrite(&funcionarioAdd, sizeof(funcionario_st), 1, arquivo);
  }
  fclose(arquivo);
}

void le_funcionario(char * filename){
  funcionario_st funcionario;
  FILE *arquivo;
  arquivo = fopen(filename,"rb");
  if(arquivo == NULL){
    printf("Erro na abertura do arquivo");
  }
 
  while(fread(&funcionario, sizeof(funcionario_st), 1, arquivo)){
    printf("%s\n", funcionario.nome);
    printf("%s\n", funcionario.telefone);
    printf("%s\n", funcionario.vinculo);
    printf("%d\n", funcionario.sala);
    printf("%d\n\n", funcionario.predio);
  }
  fclose(arquivo);
}

void atualiza_sala_predio(char* filename){
  int sucesso = 0;
  FILE *arquivo;
  funcionario_st funcionario;
  char funcionarioProcurado[80];
  
  if(!(arquivo = fopen(filename,"r+b"))){
      printf("\nErro na abertura do arquivo");
  }else{
    fflush(stdin);
    rewind(arquivo);
    printf("\nDigite o nome completo do funcionario cuja sala e predio devem ser atualizadas: ");
    scanf(" %[^\n]", funcionarioProcurado);
    while(!feof(arquivo)){
      if(fread(&funcionario,sizeof(funcionario_st),1,arquivo) == 1){
        if(strncmp(funcionario.nome, funcionarioProcurado, 80) == 0){
          printf("\nDigite a nova sala: ");
          scanf("%d",&funcionario.sala);
          printf("\nDigite o novo predio: ");
          scanf("%d",&funcionario.predio);
          fseek(arquivo, -sizeof(funcionario_st),SEEK_CUR);

          if(fwrite(&funcionario,sizeof(funcionario_st),1,arquivo) != 1){
            printf("\nErro na gravação\n");
          }
          sucesso = 1;
          printf("\nAtualização bem sucedida\n");
        }
      }
    }
    if (!sucesso){
        printf("\nNenhum funcionário encontrado\n\n\n");
    }
  }
 fclose(arquivo);
}

int main() {
  printf("\n\nQUESTÃO A)\n\n");
  le_funcionario("inf.bin");
  printf("\n\nQUESTÃO B)\n\n");
  addFuncionario("inf.bin");
  printf("\n\nQUESTÃO C)\n\n");
  atualiza_sala_predio("inf.bin");
  printf("ARQUIVO ATUALIZADO:\n\n");
  le_funcionario("inf.bin");
 return 0;
} 