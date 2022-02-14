#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[6][6];
    int change, each_oter;

    for(int column=0;column<6;column++){
        for(int line=0;line<6;line++){
            printf("[%i][%i]: ", column, line);
            scanf("%i", &matrix[column][line]);
        }

    }
    //printa matriz inserido
    for(int column=0;column<6;column++){
        for(int line=0;line<6;line++){
            printf("%i ", matrix[column][line]);

        }
        printf("\n");
    }


    change = 1;
    while(change == 1){
        change = 0;
        for(int column = 0; column<=5; column++){
            for(int line=0; line<=5;line++){
                if(matrix[column][line]>matrix[column][line+1]){
                    change = 1;
                    each_oter = matrix[column][line];
                    matrix[column][line] = matrix[column][line+1];
                    matrix[column][line+1] = each_oter;
                }
            }
        }
    }

    printf("\n\n\tMatriz ordenada\n");
    for(int column=0;column<6;column++){
        for(int line=0;line<6;line++){
            printf(" %i ", matrix[column][line]);

        }
        printf("\n");
    }
    return 0;
}
