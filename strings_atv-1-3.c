#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ativade 1\n");
    printf("Escrever um programa que le uma string e a escreve. Atraves de uma funcao, escrever a mesma string em ordem inversa\n\n");
    atividade_um();
    printf("\n\nAtividade 2\n");
    printf("Escrever um programa que le duas strings e informa o tamanho, a igualdade entre elas e no final escrever as strings concatenadas.\n\n");
    atividade_dois();
    printf("\n\nAtividade 3\n");
    printf("Escrever um programa que le uma string s[30]. Uma funcao deve escrever cada palavra desta string numa nova linha.\n\n");
    atividade_tres();
    return 0;
}

void atividade_um(){

    char string_user[40];
    printf("Insira uma string de ate 40 espacos: ");
    gets(string_user);
    printf("A string inserida foi: %s", &string_user);
    inverte_str(string_user);
}

int len_string(char str_1[])
{
  int tam = 0;
  for (int flag = 0; flag < 100; flag++)
  {
    if (str_1[flag] == '\0') {
      break;
      }
    tam++;
  }

  return tam;
}


void inverte_str(char str_2[]) {
    int tam_str = len_string(str_2);
    for (int flag_a = 0; flag_a < tam_str / 2; flag_a++){
        char inv = str_2[flag_a];
        str_2[flag_a] = str_2[tam_str - 1 - flag_a];
        str_2[tam_str - flag_a - 1] = inv;
    }

  printf("\nAo contrario, sua string eh: %s", str_2);
}


void atividade_dois(){
    char string_um[40], string_dois[40];
    printf("Insira uma string de ate 40 espacos:\n");
    gets(string_um);
    printf("\nInsira uma string de ate 40 espacos:\n");
    gets(string_dois);

    int string_um_len = len_string(string_um);
    int string_dois_len = len_string(string_dois);

    printf("\nPrimeira string: %i espacos; Segunda string: %i espacos", string_um_len, string_dois_len);
    concatena_string(string_um, string_dois, string_um_len, string_dois_len);
}



void concatena_string(char str_0[], char str_1[], int str_tam1, int str_tam2){

  char string_concatena[100];

  for (int c = 0; c < str_tam1; c++)
  {
    string_concatena[c] = str_0[c];
  }
  for (int h = 0; h < str_tam2; h++)
  {
    string_concatena[str_tam1 + h] = str_1[h];
  }

    string_concatena[str_tam1 + str_tam2] = '\0';

  printf("\nA concatenacao das strings eh: %s", string_concatena);
}

void atividade_tres() {
    char word[30];

    printf("Insira uma string de ate 30 espacos\n");
    gets(word);

    escreve_newline(word);
}

void escreve_newline(char str_line[]) {
    printf("\n");
    int tam_str = len_string(str_line);

    for (int flag_1 = 0; flag_1 < tam_str; flag_1++)
    {
        if (str_line[flag_1] == ' '){
            printf("\n");
        }
        else{
            printf("%c", str_line[flag_1]);
        }
    }
}
