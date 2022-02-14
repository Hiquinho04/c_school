#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[30];
    int tam;
    FILE *fp;
    printf("Insira a string: ");
    gets(s);
    tam=strlen(s);
    for(int i=0;i<tam;i++){
        printf("%c", s[i]);
        if(s[i]==' '){
            printf("\n");
        }

    }

    fp=fopen("arquivo2.txt", "wt");
    for(int i=0;i<tam;i++){
        putc(s[i], fp);
        if(s[i]==' '){
        fputs("\n", fp);
        }

    }fclose(fp);

    printf("\n\t\tHenrique Fleck Harff - 4324");
    return 0;

}
