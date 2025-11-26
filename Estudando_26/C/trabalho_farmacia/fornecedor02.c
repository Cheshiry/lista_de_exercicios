//
// Created by agnes on 25/11/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FORNECEDORES 100

//PARA LIMPAR A TELA
int clear_screen() {
    system("cls"); // Windows
}
void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
// =========================================================
// 1. DEFINIÇÃO DAS VARIÁVEIS GLOBAIS
// =========================================================
typedef struct {
    int id;
    char nome[100];
    char nomeContato[100];
    char numeroWhatsApp[50];
    int ativo;
} Fornecedor;


Fornecedor fornecedores[MAX_FORNECEDORES];

int num_fornecedores = 0;
// =========================================================
//ADMINISTRADOR TEMPORARIO
// =========================================================
int is_admin_user() {
    return 1;  // permite tudo por enquanto
}

// =========================================================
// 2. FUNÇÃO DE DADOS INICIAIS
// =========================================================

void carregar_dados_iniciais() {

    // Fornecedor 1: ID 101
    fornecedores[0].id = 101;
    strncpy(fornecedores[0].nome, "Biotech", sizeof(fornecedores[0].nome));
    strncpy(fornecedores[0].nomeContato, "jhonny souza", sizeof(fornecedores[0].nomeContato));
    strncpy(fornecedores[0].numeroWhatsApp, "(19)98766768", sizeof(fornecedores[0].numeroWhatsApp));
    fornecedores[0].ativo = 1;

    // Fornecedor 2: ID 102
    fornecedores[1].id = 102;
    strncpy(fornecedores[1].nome, "Landerlan Saúdes", sizeof(fornecedores[1].nome));
    strncpy(fornecedores[1].nomeContato, "Chris Bumstead", sizeof(fornecedores[1].nomeContato));
    strncpy(fornecedores[1].numeroWhatsApp, "(19)998765435", sizeof(fornecedores[1].numeroWhatsApp));
    fornecedores[1].ativo = 1;

    // Fornecedor 3: ID 103
    fornecedores[2].id = 103;
    strncpy(fornecedores[2].nome, "Gamma Labs", sizeof(fornecedores[2].nome));
    strncpy(fornecedores[2].nomeContato, "Ramon Dino", sizeof(fornecedores[2].nomeContato));
    strncpy(fornecedores[2].numeroWhatsApp, "(19)987654321", sizeof(fornecedores[2].numeroWhatsApp));
    fornecedores[2].ativo = 1;

    // Fornecedor 4: ID 104
    fornecedores[3].id = 104;
    strncpy(fornecedores[3].nome, "Olympia Medical Importadora", sizeof(fornecedores[3].nome));
    strncpy(fornecedores[3].nomeContato, "jorlan viera", sizeof(fornecedores[3].nomeContato));
    strncpy(fornecedores[3].numeroWhatsApp, "(19)998765432", sizeof(fornecedores[3].numeroWhatsApp));
    fornecedores[3].ativo = 1;

    // Fornecedor 5: ID 105
    fornecedores[4].id = 105;
    strncpy(fornecedores[4].nome, "integral Insumos Farmacêuticos", sizeof(fornecedores[4].nome));
    strncpy(fornecedores[4].nomeContato, "Paulo Muzy", sizeof(fornecedores[4].nomeContato));
    strncpy(fornecedores[4].numeroWhatsApp, "(19)987654321", sizeof(fornecedores[4].numeroWhatsApp));
    fornecedores[4].ativo = 1;

    num_fornecedores = 5;
}

// -----------------------------------
// 3. FUNÇÕES DE SUPORTE
// -----------------------------------

int gerar_novo_id_fornecedor() {
    if (num_fornecedores == 0) {
        return 101;
    }
    return fornecedores[num_fornecedores - 1].id + 1;
}

// -----------------------------------
// 4. INCLUIR FORNECEDOR
// -----------------------------------

void incluir_fornecedor() {
    clear_screen();
    printf("========================================================\n");
    printf("||           INCLUIR NOVO FORNECEDOR                    ||\n");
    printf("========================================================\n");

    if (num_fornecedores >= MAX_FORNECEDORES) {
        printf("\nERRO: Limite máximo de fornecedores (%d) atingido.\n", MAX_FORNECEDORES);
        return;
    }

    int novo_indice = num_fornecedores;

    fornecedores[novo_indice].id = gerar_novo_id_fornecedor();
    printf(">> Novo ID gerado: %d\n\n", fornecedores[novo_indice].id);

    printf(">> Digite o Nome da Empresa Fornecedora (Max 99 chars): ");
    flush_input();
    if (fgets(fornecedores[novo_indice].nome, sizeof(fornecedores[0].nome), stdin) != NULL) {
        fornecedores[novo_indice].nome[strcspn(fornecedores[novo_indice].nome, "\n")] = 0;
    }

    printf(">> Digite o Nome de Contato (Max 99 chars): ");
    flush_input();
    if (fgets(fornecedores[novo_indice].nomeContato, sizeof(fornecedores[0].nomeContato), stdin) != NULL) {
        fornecedores[novo_indice].nomeContato[strcspn(fornecedores[novo_indice].nomeContato, "\n")] = 0;
    }

    printf(">> Digite o Número do WhatsApp (Max 49 chars): ");
    flush_input();
    if (fgets(fornecedores[novo_indice].numeroWhatsApp, sizeof(fornecedores[0].numeroWhatsApp), stdin) != NULL) {
        fornecedores[novo_indice].numeroWhatsApp[strcspn(fornecedores[novo_indice].numeroWhatsApp, "\n")] = 0;
    }

    fornecedores[novo_indice].ativo = 1;
    num_fornecedores++;

    printf("\n✅ FORNECEDOR CADASTRADO COM SUCESSO!\n");
    printf("Empresa: %s | ID: %d\n", fornecedores[novo_indice].nome, fornecedores[novo_indice].id);
}

// -----------------------------------
// LISTAR FORNECEDORES
// -----------------------------------

void listar_fornecedores() {
    clear_screen();
    printf("========================================================================================================================\n");
    printf("||                                         LISTAGEM DE FORNECEDORES                                                   ||\n");
    printf("========================================================================================================================\n");

    if (num_fornecedores == 0) {
        printf("Nenhum fornecedor cadastrado.\n");
        return;
    }

    printf("| %-4s | %-30s | %-25s | %-15s | %-6s |\n", "ID", "EMPRESA FORNECEDORA", "NOME DE CONTATO", "WHATSAPP", "ATIVO");
    printf("------------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_fornecedores; i++) {
        const char* status = (fornecedores[i].ativo == 1) ? "SIM" : "NÃO";

        printf("| %-4d | %-30s | %-25s | %-15s | %-6s |\n",
            fornecedores[i].id,
            fornecedores[i].nome,
            fornecedores[i].nomeContato,
            fornecedores[i].numeroWhatsApp,
            status);
    }
    printf("========================================================================================================================\n");
}

// -----------------------------------
// EDITAR FORNECEDOR
// -----------------------------------

void editar_fornecedor() {
    clear_screen();
    printf("========================================================\n");
    printf("||              EDITAR FORNECEDOR                       ||\n");
    printf("========================================================\n");

    if (num_fornecedores == 0) {
        printf("\nNenhum fornecedor cadastrado para edição.\n");
        return;
    }

    int id_editar;
    int encontrado = 0;

    printf(">> Digite o ID do fornecedor que deseja editar: ");
    if (scanf("%d", &id_editar) != 1) {
        printf("\nERRO: Entrada inválida.\n");
        flush_input();
        return;
    }
    flush_input();

    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id_editar) {
            encontrado = 1;

            printf("\n--- Editando: %s (ID %d) ---\n", fornecedores[i].nome, fornecedores[i].id);
            printf(">> NOVO Nome da Empresa (ENTER para manter '%s'): ", fornecedores[i].nome);
            char temp_nome[100];
            if (fgets(temp_nome, sizeof(temp_nome), stdin) != NULL) {
                temp_nome[strcspn(temp_nome, "\n")] = 0;
                if (strlen(temp_nome) > 0) {
                    strcpy(fornecedores[i].nome, temp_nome);
                }
            }

            // Edição do Nome de Contato
            printf(">> NOVO Nome de Contato (ENTER para manter '%s'): ", fornecedores[i].nomeContato);
            char temp_contato[100];
            if (fgets(temp_contato, sizeof(temp_contato), stdin) != NULL) {
                temp_contato[strcspn(temp_contato, "\n")] = 0;
                if (strlen(temp_contato) > 0) {
                    strcpy(fornecedores[i].nomeContato, temp_contato);
                }
            }

            // Edição do WhatsApp
            printf(">> NOVO WhatsApp (ENTER para manter '%s'): ", fornecedores[i].numeroWhatsApp);
            char temp_whatsapp[50];
            if (fgets(temp_whatsapp, sizeof(temp_whatsapp), stdin) != NULL) {
                temp_whatsapp[strcspn(temp_whatsapp, "\n")] = 0;
                if (strlen(temp_whatsapp) > 0) {
                    strcpy(fornecedores[i].numeroWhatsApp, temp_whatsapp);
                }
            }

            printf("\n✅ FORNECEDOR EDITADO COM SUCESSO!\n");
            return;
        }
    }

    if (!encontrado) {
        printf("\n❌ ERRO: Fornecedor com ID %d não encontrado.\n", id_editar);
    }
}

// -----------------------------------
// EXCLUIR FORNECEDOR LÓGICA
// -----------------------------------

void excluir_fornecedor_logica() {
    clear_screen();
    printf("========================================================\n");
    printf("||     EXCLUIR FORNECEDOR (EXCLUSÃO LÓGICA)             ||\n");
    printf("========================================================\n");

    if (num_fornecedores == 0) {
        printf("\nNenhum fornecedor cadastrado para exclusão.\n");
        return;
    }

    int id_excluir;
    int encontrado = 0;

    printf(">> Digite o ID do fornecedor que deseja excluir (inativar): ");

    if (scanf("%d", &id_excluir) != 1) {
        printf("\nERRO: Entrada inválida.\n");
        flush_input();
        return;
    }
    flush_input();

    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id_excluir) {
            encontrado = 1;

            if (fornecedores[i].ativo == 0) {
                printf("\n⚠️ ATENÇÃO: O fornecedor '%s' (ID %d) já está INATIVO.\n", fornecedores[i].nome, id_excluir); // Corrigido
                return;
            }

            fornecedores[i].ativo = 0;

            printf("\n✅ Exclusão Lógica Realizada com Sucesso!\n");
            printf("O fornecedor '%s' (ID %d) foi INATIVADO.\n", fornecedores[i].nome, id_excluir); // Corrigido
            return;
        }
    }

    if (!encontrado) {
        printf("\n❌ ERRO: Fornecedor com ID %d não encontrado.\n", id_excluir);
    }
}

// -----------------------------------
// MENU FORNECEDOR
// -----------------------------------

void menu_fornecedor() {
    int opcao;
    const int is_admin = is_admin_user();

    do {
        clear_screen();
        printf("========================================================\n");
        printf("||          GERENCIAR FORNECEDORES                      ||\n");
        printf("|| %-50s ||\n", is_admin ? "ADMINISTRADOR (Acesso Total)" : "SIMPLES (Acesso Restrito)");
		printf("========================================================\n");

        printf("|| [1] %-46s ||\n", is_admin ? "INCLUIR FORNECEDOR" : "INCLUIR FORNECEDOR (APENAS ADMIN)");
		printf("|| [2] %-46s ||\n", "LISTAR FORNECEDORES");
		printf("|| [3] %-46s ||\n", is_admin ? "EDITAR FORNECEDOR" : "EDITAR FORNECEDOR (APENAS ADMIN)");
		printf("|| [4] %-46s ||\n", is_admin ? "EXCLUIR FORNECEDOR" : "EXCLUIR FORNECEDOR (APENAS ADMIN)");
		printf("|| [0] %-46s ||\n", "VOLTAR AO MENU ANTERIOR");

		printf("========================================================\n");
		printf(">> Escolha uma opcao: ");

		if (scanf("%d", &opcao) != 1) {
            opcao = -1;
		    printf("\nEntrada inválida. Pressione ENTER para continuar...");
		    getchar();
            flush_input();
		}
    } while (opcao != 0);
}

int clear_screen();
