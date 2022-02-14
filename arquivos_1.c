#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[50], new_string[50];
    int tam, end, flag;
    FILE *fp;

    printf("Insira a string que deseja inverter: ");
    //fgets(string, 50, stdin);
    gets(string);
    tam = strlen(string);
    end = tam - 1;
    for(flag=0; flag<tam; flag++){
        new_string[end] = string[flag];
        end--;
    }
    new_string[flag]='\0';
    printf("%s", new_string);

    fp=fopen("arquivos1.txt", "wt");
    fputs(new_string, fp);
    fclose(fp);


    printf("\n\t\tHenrique Fleck Harff - 4324");

    return 0;
}
