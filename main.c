#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void capacitor_e12(double cap_10, int resistor){


    double cap_e12;
    double fc_c;
    int test = 0;


    float e12[14];
    e12[0] = 1;
    e12[1] = 1.2;
    e12[2] = 1.5;
    e12[3] = 1.8;
    e12[4] = 2.2;
    e12[5] = 2.7;
    e12[6] = 3.3;
    e12[7] = 3.9;
    e12[8] = 4.7;
    e12[9] = 5.6;
    e12[10] = 6.8;
    e12[11] = 8.2;

    while(test < 12){
        if(cap_10 < e12[test]){
            cap_e12 = e12[test];
            test = 12;
        }
        test++;
    }
   printf("\nCapacitor na E12: %lf\n", cap_e12);

    cap_e12 = cap_e12 * 0.000000001;
    fc_c = 1/(2*PI*resistor*cap_e12);
    printf("Frequencia de corte, comercial: %lfHz\n", fc_c);
}

void Xc(double capacitor, int resistor){

    double xc[20], frequencia[16];
    printf("\nInsira a frequencia de corte, 7 frequencias abaixo e 7 acima: ");
    for(int test = 0; test<15; test++){
        printf("\nFrequencia %i: ", test + 1);
        scanf("%lf", &frequencia[test]);
    }
    printf("\n\tValores de Xc: ");
    for(int test = 0; test<15; test++){
        xc[test] = 1/(2*PI*frequencia[test]*capacitor);
        printf("\nXc: %lf ", xc[test]);
    }

    Vo_FPB_FPA(xc, resistor);
}

void Vo_FPB_FPA(double xc[20], int resistor){
    double vi = 5;
    double quadrado_a[20], quadrado_b;
    quadrado_b = resistor * resistor;

    double z[20], angulo[20], soma_q[20], mult;
    double Vo_B[20], Vo_A[20], VoVi_B[20], VoVi_A[20], Vo_ViBlog[20], Vo_ViAlog[20];
    float Vo;

    for(int test = 0; test<15; test++){
        quadrado_a[test] = xc[test] * xc[test];
        soma_q[test] = quadrado_a[test] + quadrado_b;
        z[test] = sqrt(soma_q[test]);

    }
    printf("\n\tVo - FPB\n");
    for(int test = 0; test<15; test++){
        mult = atan2(xc[test], resistor);
        angulo[test] = mult * (-1);
        angulo[test] = angulo[test] * (180/PI);

        Vo_B[test] = xc[test]/z[test];
        Vo_B[test] = Vo_B[test] * 5;
        printf("%lf <%lf>\n", Vo_B[test], angulo[test]);

    }
    printf("\n\tVo/Vi\n");
    for (int test = 0; test<15; test++){
        VoVi_B[test] = Vo_B[test]/5;

        printf("%lf\n", VoVi_B[test]);
    }

    printf("\n\tVo/Vi(dB)\n");
    for(int test = 0; test<15; test++){
        Vo_ViBlog[test] = log10(VoVi_B[test]);
        Vo_ViBlog[test] = -20 * Vo_ViBlog[test];
        printf("%lf\n", Vo_ViBlog[test]);

    }



    printf("\n\tVo - FPA\n");
    for(int test = 0; test<15; test++){
        mult = atan2(xc[test], resistor);
        angulo[test] = mult * (1);
        angulo[test] = angulo[test] * (180/PI);

        Vo_A[test] = resistor/z[test];
        Vo_A[test] = Vo_A[test] * 5;
        printf("%lf <%lf>\n", Vo_A[test], angulo[test]);
    }


    printf("\n\tVo/Vi\n");
    for(int test = 0; test<15; test++){
        VoVi_A[test] = Vo_A[test]/5;
        printf("%lf\n", VoVi_A[test]);
    }

    printf("\n\tVo/Vi(dB)\n");
    for(int test = 0; test<15; test++){
        Vo_ViAlog[test] = log10(VoVi_A[test]);
        Vo_ViAlog[test] = -20 * Vo_ViAlog[test];
        printf("%lf\n", Vo_ViAlog[test]);
    }

}


int main()
{
    //int fc, resistor;

    float  resistor, fc;

    double capacitor, capacitor_nF;
    printf("Insira a frequência de corte(N° da chamada x1000): ");
    scanf("%f", &fc);
    printf("Frequencia de corte: %f\n", fc);
    printf("Escolha um resistor R>1k(E12): ");
    scanf("%f", &resistor);
    printf("Resistor: %f\n", resistor);

    capacitor = (2*PI*resistor*fc);

    capacitor = 1/capacitor;
    capacitor_nF = capacitor * 1000000000;

    printf("Capacitor: %lf nF", capacitor_nF);
    capacitor_e12(capacitor_nF, resistor);
    Xc(capacitor, resistor);

    printf("\n\tMade by Hiquinho");

    return 0;
}
