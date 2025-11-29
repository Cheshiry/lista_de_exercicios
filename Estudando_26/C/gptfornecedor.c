#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FORNECEDORES 100

// Estrutura simples do fornecedor
typedef struct {
    int id;
    char nome[100];
    char contato[100];
    char whatsapp[50];
    int ativo;
} Fornecedor;

Fornecedor fornecedores[MAX_FORNECEDORES];
int num_fornecedores = 0;

// ------------------------------------------------------
// FUNÇÕES AUXILIARES
// ------------------------------------------------------
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int gerar_id() {
    return num_fornecedores + 1;
}

// Converte string para minúsculas
void str_minusculo(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

// ------------------------------------------------------
// INCLUIR FORNECEDOR
// ------------------------------------------------------
void incluir_fornecedor() {
    if (num_fornecedores >= MAX_FORNECEDORES) {
        printf("\nLimite máximo atingido!\n");
        return;
    }

    int i = num_fornecedores;

    fornecedores[i].id = gerar_id();
    fornecedores[i].ativo = 1;

    printf("\nID gerado: %d\n", fornecedores[i].id);

    printf("Nome da Empresa: ");
    fgets(fornecedores[i].nome, 100, stdin);
    fornecedores[i].nome[strcspn(fornecedores[i].nome, "\n")] = 0;

    printf("Nome de Contato: ");
    fgets(fornecedores[i].contato, 100, stdin);
    fornecedores[i].contato[strcspn(fornecedores[i].contato, "\n")] = 0;

    printf("WhatsApp: ");
    fgets(fornecedores[i].whatsapp, 50, stdin);
    fornecedores[i].whatsapp[strcspn(fornecedores[i].whatsapp, "\n")] = 0;

    num_fornecedores++;

    printf("\nFornecedor cadastrado com sucesso!\n");
}

// ------------------------------------------------------
// LISTAR
// ------------------------------------------------------
void listar_fornecedores() {
    if (num_fornecedores == 0) {
        printf("\nNenhum fornecedor cadastrado.\n");
        return;
    }

    printf("\n--- LISTA DE FORNECEDORES ---\n");

    for (int i = 0; i < num_fornecedores; i++) {
        printf("\nID: %d\n", fornecedores[i].id);
        printf("Empresa: %s\n", fornecedores[i].nome);
        printf("Contato: %s\n", fornecedores[i].contato);
        printf("WhatsApp: %s\n", fornecedores[i].whatsapp);
        printf("Ativo: %s\n", fornecedores[i].ativo ? "Sim" : "Não");
    }
}

// ------------------------------------------------------
// EDITAR
// ------------------------------------------------------
void editar_fornecedor() {
    int id;
    printf("\nID do fornecedor para editar: ");
    scanf("%d", &id);
    limpar_buffer();

    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id) {

            printf("\nEditando fornecedor %s\n", fornecedores[i].nome);

            char temp[100];

            printf("Novo nome (ENTER mantém): ");
            fgets(temp, 100, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = 0;
                strcpy(fornecedores[i].nome, temp);
            }

            printf("Novo contato (ENTER mantém): ");
            fgets(temp, 100, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = 0;
                strcpy(fornecedores[i].contato, temp);
            }

            printf("Novo WhatsApp (ENTER mantém): ");
            fgets(temp, 100, stdin);
            if (temp[0] != '\n') {
                temp[strcspn(temp, "\n")] = 0;
                strcpy(fornecedores[i].whatsapp, temp);
            }

            printf("\nFornecedor atualizado!\n");
            return;
        }
    }

    printf("\nFornecedor não encontrado!\n");
}

// ------------------------------------------------------
// EXCLUSÃO LÓGICA
// ------------------------------------------------------
void excluir_fornecedor() {
    int id;
    printf("\nID do fornecedor para inativar: ");
    scanf("%d", &id);
    limpar_buffer();

    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id) {
            fornecedores[i].ativo = 0;
            printf("\nFornecedor inativado!\n");
            return;
        }
    }

    printf("\nFornecedor não encontrado!\n");
}

// ------------------------------------------------------
// BUSCAR POR ID
// ------------------------------------------------------
void buscar_por_id() {
    int id;
    printf("\nDigite o ID: ");
    scanf("%d", &id);
    limpar_buffer();

    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id) {
            printf("\n--- Fornecedor Encontrado ---\n");
            printf("ID: %d\n", fornecedores[i].id);
            printf("Empresa: %s\n", fornecedores[i].nome);
            printf("Contato: %s\n", fornecedores[i].contato);
            printf("WhatsApp: %s\n", fornecedores[i].whatsapp);
            printf("Ativo: %s\n", fornecedores[i].ativo ? "Sim" : "Não");
            return;
        }
    }

    printf("\nNenhum fornecedor com esse ID foi encontrado.\n");
}

// ------------------------------------------------------
// BUSCAR POR NOME (CORRIGIDO)
// ------------------------------------------------------
void buscar_por_nome() {
    char nome_busca[100];

    printf("\nDigite parte ou o nome completo da empresa: ");
    fgets(nome_busca, 100, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = 0;

    str_minusculo(nome_busca);

    int encontrados = 0;

    printf("\n--- Resultados da Busca ---\n");

    for (int i = 0; i < num_fornecedores; i++) {
        char temp[100];
        strcpy(temp, fornecedores[i].nome);
        str_minusculo(temp);

        if (strstr(temp, nome_busca) != NULL) {
            printf("\nID: %d\n", fornecedores[i].id);
            printf("Empresa: %s\n", fornecedores[i].nome);
            printf("Contato: %s\n", fornecedores[i].contato);
            printf("WhatsApp: %s\n", fornecedores[i].whatsapp);
            printf("Ativo: %s\n", fornecedores[i].ativo ? "Sim" : "Não");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("\nNenhum fornecedor encontrado com esse nome.\n");
    }
}

// ------------------------------------------------------
// MENU
// ------------------------------------------------------
void menu() {
    int op;

    do {
        printf("\n=============================\n");
        printf("  MENU DE FORNECEDORES\n");
        printf("=============================\n");
        printf("[1] Incluir fornecedor\n");
        printf("[2] Listar fornecedores\n");
        printf("[3] Editar fornecedor\n");
        printf("[4] Excluir fornecedor\n");
        printf("[5] Buscar fornecedor\n");
        printf("[0] Sair\n");
        printf("Escolha: ");
        
        scanf("%d", &op);
        limpar_buffer();

        switch (op) {
            case 1: incluir_fornecedor(); break;
            case 2: listar_fornecedores(); break;
            case 3: editar_fornecedor(); break;
            case 4: excluir_fornecedor(); break;

            case 5: {
                int sub;
                printf("\n[1] Buscar por ID\n");
                printf("[2] Buscar por nome\n");
                printf("Escolha: ");
                scanf("%d", &sub);
                limpar_buffer();

                if (sub == 1) buscar_por_id();
                else if (sub == 2) buscar_por_nome();
                else printf("\nOpcao inválida!\n");
                break;
            }

            case 0: printf("\nSaindo...\n"); break;

            default: printf("\nOpcao inválida!\n");
        }

    } while (op != 0);
}

// ------------------------------------------------------
// MAIN
// ------------------------------------------------------
int main() {
    menu();
    return 0;
}
