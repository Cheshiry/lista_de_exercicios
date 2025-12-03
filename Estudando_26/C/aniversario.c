//
// Created by agnes on 29/11/2025.
//

#include <stdio.h>

void main(){
    char nome[50];
    int idade;
    printf("-----------------------\n");
    printf("Digite o seu nome:");
    scanf("%s", &nome);
    printf("-----------------------\n");
    printf("Digite a sua idade:");
    scanf("%i",&idade);
    printf("-----------------------\n");
    printf("No ano que vem a(o) %s vai fazer idade %d\n",nome, idade+1);
    printf("-----------------------");
}