#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 80
#define MAX_OPTIONS 256

FILE *fp;

int string_invert(char s[TAM]){
    int tam=strlen(s);

    for(int i=tam-1;i>=0;i--){
        putc(s[i],fp);
    }
    fputs("\n\n", fp);
}

int just_one_word(char s[TAM]){
    int tam=strlen(s);
    for(int flag=0;flag<tam;flag++){
        putc(s[flag], fp);
        if(s[flag]==' '){
            fputs("\n", fp);
        }
    }
    fputs("\n\n", fp);
}

int just_one_letter(char s[TAM]){
    int tam=strlen(s);
    for(int i=0; i<tam;i++){
        putc(s[i], fp);
        fputs("\n", fp);
    }
    fputs("\n", fp);
}


 int how_much_a(char s[TAM]){

    int size=strlen(s);
    int counter[MAX_OPTIONS];
    char string_flag[TAM];
    strcpy(string_flag, s);
    //limpando lixo da lista
    for(int i=0; i<TAM;i++){
        counter[i]=0;
    }


    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(s[i]==s[j+i+1]){
                s[j+1+i]= '0'; //elimina caracteres iguais na mesma string
            }
        }
    }
    //verifica caracteres iguais na string
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(s[i]==string_flag[j]){
                counter[i]++;
            }
    }
 }
    for(int i=0;i<size;i++){
        if(counter[i]>=1){
        putc(string_flag[i],fp);
        fputs(" = ", fp);
        fprintf(fp,"%i" "%s",counter[i],"\n");

        }
    }

 }

int main()
{
    char string[80];
    int tam;

    printf("Insira a string: ");
    gets(string);

    tam=strlen(string);
    fp=fopen("string.txt", "wt");
    fputs(string, fp);
    fputs("\n\n", fp);

    string_invert(string);
    just_one_word(string);
    just_one_letter(string);
    how_much_a(string);
    fclose(fp);

    printf("\n\n\tHenrique Fleck Harff - 4324");

    return 0;

}
