//
// Created by agnes on 29/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#define PI 3.14159265

void main() {
//*************************************************************
//EXEMPLO 1
//*************************************************************
/*
    printf("Hello World");
*/
//*************************************************************
//EXEMPLO 2
//*************************************************************
    /*
    char var_c;
    int var_i;
    float var_f;
    double var_d;

    scanf("%c",&var_c);
    scanf("%d",&var_i);
    scanf("%f",&var_f);
    scanf("%lf",&var_d);


    printf("%i\n",var_i);
    printf("%f\n",var_f);
    printf("%lf\n",var_d);
    printf("%c\n",var_c);
    printf("%f\n", PI);
*/
//*************************************************************
//EXEMPLO 3
//*************************************************************

int a,b,c;
    printf("Digite um numero: \n");
    scanf("%d",&a);

    if (a>=0 && a<=10) {
        printf("Numero Valido\n");
    }else {
        printf("Numero Valido\n");
    }

    printf("Digite outro numero: \n");
    scanf("%d", &b);

    if (b>=0 && b<=10) {
        printf("Numero Valido\n");
    }else {
        printf("Numero Valido\n");
    }

    printf("Digite outro numero: \n");
    scanf("%d", &c);

    if (c>=0 && c<=10) {
        printf("Numero Valido\n");
    } else {
        printf("Numero Valido\n");
    }



    printf("Os numeros digitados foram: %d, %d, %d", a, b, c);


}

