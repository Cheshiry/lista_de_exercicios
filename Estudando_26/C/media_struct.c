//
// Created by agnes on 30/11/2025.
//
#include <stdio.h>

#define QTD_ALUNOS 3
#define QTD_NOTAS  3

// Estrutura do aluno
typedef struct {
    char nome[30];
    float notas[QTD_NOTAS];
    float media;
} Aluno;

int main() {
    Aluno alunos[QTD_ALUNOS];

    // Cadastro dos alunos
    for(int i = 0; i < QTD_ALUNOS; i++) {
        printf("Digite o nome do %dº aluno: ", i + 1);
        scanf("%s", alunos[i].nome);

        float soma = 0.0;

        for(int j = 0; j < QTD_NOTAS; j++) {
            printf("Digite a %dª nota de %s: ", j + 1, alunos[i].nome);
            scanf("%f", &alunos[i].notas[j]);
            soma += alunos[i].notas[j];
        }

        alunos[i].media = soma / QTD_NOTAS;
        printf("\n");
    }

    // Exibição dos resultados
    printf("\n------ RESULTADO FINAL ------\n");
    for(int i = 0; i < QTD_ALUNOS; i++) {
        printf("\nAluno: %s\n", alunos[i].nome);
        printf("Notas: ");

        for(int j = 0; j < QTD_NOTAS; j++) {
            printf("%.1f ", alunos[i].notas[j]);
        }

        printf("\nMédia: %.1f\n", alunos[i].media);
    }

    return 0;
}
