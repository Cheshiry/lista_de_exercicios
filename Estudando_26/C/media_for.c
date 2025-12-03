#include <stdio.h>
#include <locale.h>
int main() {

    char nomes[3][20];   // 3 alunos, até 19 letras por nome
    float notas[3][3];   // 3 alunos, 3 notas cada

    // Lendo os nomes
    for(int i = 0; i < 3; i++) {
        printf("Digite o nome do %d aluno: ", i + 1);
        scanf("%s", nomes[i]);

        // Lendo as notas do aluno
        for(int j = 0; j < 3; j++) {
            printf("Digite a %d nota de %s: ", j + 1, nomes[i]);
            scanf("%f", &notas[i][j]);
        }
        printf("\n");
    }

    // Mostrando os dados
    printf("\n----- RESULTADO -----\n");
    for(int i = 0; i < 3; i++) {
        float soma = 0;

        printf("Aluno: %s\nNotas: ", nomes[i]);
        for(int j = 0; j < 3; j++) {
            printf("%.1f ", notas[i][j]);
            soma += notas[i][j];
        }


        printf("\nMédia: %.1f\n\n", soma / 3);
    }

    return 0;
}
