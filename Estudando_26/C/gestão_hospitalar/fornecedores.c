#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"        
#include "fornecedores.h" 
#include "utilidades.h"   

// =========================================================
// 1. DEFINIÃ‡ÃƒO DAS VARIÃVEIS GLOBAIS
// =========================================================
Fornecedor fornecedores[MAX_FORNECEDORES];
int num_fornecedores = 0;

// =========================================================
// 2. FUNÃ‡ÃƒO DE DADOS INICIAIS 
// =========================================================

void carregar_dados_iniciais() {
    
    // Fornecedor 1: ID 101 
    fornecedores[0].id = 101;
    strcpy(fornecedores[0].nome, "Biotech"); 
    strcpy(fornecedores[0].nomeContato, "jhonny souza"); 
    strcpy(fornecedores[0].numeroWhatsApp, "(19)98766768");
    fornecedores[0].ativo = 1;

    // Fornecedor 2: ID 102
    fornecedores[1].id = 102;
    strcpy(fornecedores[1].nome, "Landerlan SaÃºdes"); 
    strcpy(fornecedores[1].nomeContato, "Chris Bumstead"); 
    strcpy(fornecedores[1].numeroWhatsApp, "(19)998765435"); 
    fornecedores[1].ativo = 1;

    // Fornecedor 3: ID 103
    fornecedores[2].id = 103;
    strcpy(fornecedores[2].nome, "Gamma Labs");
    strcpy(fornecedores[2].nomeContato, "Ramon Dino");
    strcpy(fornecedores[2].numeroWhatsApp, "(19)987654321");
    fornecedores[2].ativo = 1;

    // Fornecedor 4: ID 104
    fornecedores[3].id = 104;
    strcpy(fornecedores[3].nome, "Olympia Medical Importadora");
    strcpy(fornecedores[3].nomeContato, "jorlan viera");
    strcpy(fornecedores[3].numeroWhatsApp, "(19)998765432");
    fornecedores[3].ativo = 1;

    // Fornecedor 5: ID 105
    fornecedores[4].id = 105;
    strcpy(fornecedores[4].nome, "integral Insumos FarmacÃªuticos");
    strcpy(fornecedores[4].nomeContato, "Paulo Muzy");
    strcpy(fornecedores[4].numeroWhatsApp, "(19)987654321");
    fornecedores[4].ativo = 1;
    
    num_fornecedores = 5; 
}

// -----------------------------------
// 3. FUNÃ‡Ã•ES DE SUPORTE
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
        printf("\nERRO: Limite mÃ¡ximo de fornecedores (%d) atingido.\n", MAX_FORNECEDORES);
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

    printf(">> Digite o NÃºmero do WhatsApp (Max 49 chars): ");
    flush_input(); 
    if (fgets(fornecedores[novo_indice].numeroWhatsApp, sizeof(fornecedores[0].numeroWhatsApp), stdin) != NULL) {
        fornecedores[novo_indice].numeroWhatsApp[strcspn(fornecedores[novo_indice].numeroWhatsApp, "\n")] = 0;
    }

    fornecedores[novo_indice].ativo = 1; 
    num_fornecedores++;

    printf("\nâœ… FORNECEDOR CADASTRADO COM SUCESSO!\n");
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
        const char* status = (fornecedores[i].ativo == 1) ? "SIM" : "NÃƒO";
        
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
        printf("\nNenhum fornecedor cadastrado para ediÃ§Ã£o.\n");
        return;
    }

    int id_editar;
    int encontrado = 0;

    printf(">> Digite o ID do fornecedor que deseja editar: ");
    if (scanf("%d", &id_editar) != 1) {
        printf("\nERRO: Entrada invÃ¡lida.\n");
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

            // EdiÃ§Ã£o do Nome de Contato
            printf(">> NOVO Nome de Contato (ENTER para manter '%s'): ", fornecedores[i].nomeContato);
            char temp_contato[100];
            if (fgets(temp_contato, sizeof(temp_contato), stdin) != NULL) {
                temp_contato[strcspn(temp_contato, "\n")] = 0;
                if (strlen(temp_contato) > 0) {
                    strcpy(fornecedores[i].nomeContato, temp_contato);
                }
            }

            // EdiÃ§Ã£o do WhatsApp
            printf(">> NOVO WhatsApp (ENTER para manter '%s'): ", fornecedores[i].numeroWhatsApp);
            char temp_whatsapp[50];
            if (fgets(temp_whatsapp, sizeof(temp_whatsapp), stdin) != NULL) {
                temp_whatsapp[strcspn(temp_whatsapp, "\n")] = 0;
                if (strlen(temp_whatsapp) > 0) {
                    strcpy(fornecedores[i].numeroWhatsApp, temp_whatsapp);
                }
            }
            
            printf("\nâœ… FORNECEDOR EDITADO COM SUCESSO!\n");
            return;
        }
    }

    if (!encontrado) {
        printf("\nâŒ ERRO: Fornecedor com ID %d nÃ£o encontrado.\n", id_editar);
    }
}

// -----------------------------------
// EXCLUIR FORNECEDOR LÃ“GICA
// -----------------------------------

void excluir_fornecedor_logica() {
    clear_screen();
    printf("========================================================\n");
    printf("||     EXCLUIR FORNECEDOR (EXCLUSÃƒO LÃ“GICA)             ||\n");
    printf("========================================================\n");

    if (num_fornecedores == 0) {
        printf("\nNenhum fornecedor cadastrado para exclusÃ£o.\n");
        return;
    }

    int id_excluir;
    int encontrado = 0;

    printf(">> Digite o ID do fornecedor que deseja excluir (inativar): ");
    
    if (scanf("%d", &id_excluir) != 1) {
        printf("\nERRO: Entrada invÃ¡lida.\n");
        flush_input(); 
        return;
    }
    flush_input(); 
    
    for (int i = 0; i < num_fornecedores; i++) {
        if (fornecedores[i].id == id_excluir) {
            encontrado = 1;
            
            if (fornecedores[i].ativo == 0) {
                printf("\nâš ï¸ ATENÃ‡ÃƒO: O fornecedor '%s' (ID %d) jÃ¡ estÃ¡ INATIVO.\n", fornecedores[i].nome, id_excluir); // Corrigido
                return;
            }

            fornecedores[i].ativo = 0;
            
            printf("\nâœ… ExclusÃ£o LÃ³gica Realizada com Sucesso!\n");
            printf("O fornecedor '%s' (ID %d) foi INATIVADO.\n", fornecedores[i].nome, id_excluir); // Corrigido
            return; 
        }
    }

    if (!encontrado) {
        printf("\nâŒ ERRO: Fornecedor com ID %d nÃ£o encontrado.\n", id_excluir);
    }
}

// -----------------------------------
// MENU FORNECEDOR
// -----------------------------------

void menu_fornecedor() {
    int opcao;
    int is_admin = is_admin_user();

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
            flush_input();	
		}
		clear_screen();

		switch (opcao) {
			case 1:	
			case 3:	
			case 4:	
				if (is_admin) {
					if (opcao == 1) incluir_fornecedor();
					else if (opcao == 3) editar_fornecedor();
					else excluir_fornecedor_logica();
				} else {
					printf("Acesso negado. Apenas Administradores podem realizar operaÃ§Ãµes de escrita.\n");
				}
				break;
			case 2:	
				listar_fornecedores();
				break;
			case 0:	
				printf("Voltando ao Menu Cadastros Base...\n");	
				break;
			default:	
				printf("OpÃ§Ã£o invÃ¡lida.\n");
		}

		if (opcao != 0) {
			printf("\nPressione ENTER para continuar...");
			flush_input();
			getchar();
		}
	} while (opcao != 0);
}