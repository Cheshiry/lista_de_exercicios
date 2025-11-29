#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "autenticacao.h"
#include "utilidades.h"
#include "dados.h"

int logar() {
    clear_screen();
    int width = 60;
    
    // CORRIGIDO: sem parâmetro de caractere
    print_line(width);
    print_centered("LOGIN NO SISTEMA", width - 2);
    print_middle_line(width);
    print_centered("Entre com suas credenciais", width - 2);
    print_middle_line(width);
    
    char email[100], senha_clara[100], senha_hash_digitada[65];
    
    printf("| %sE-mail:%s ", COLOR_BOLD, COLOR_RESET);
    flush_input();
    fgets(email, 100, stdin);
    email[strcspn(email, "\n")] = 0;

    printf("| %sSenha:%s  ", COLOR_BOLD, COLOR_RESET);
    fgets(senha_clara, 100, stdin);
    senha_clara[strcspn(senha_clara, "\n")] = 0;
    
    print_bottom_line(width);

    // 1. Calcular o hash da senha digitada
    calcular_sha256(senha_clara, senha_hash_digitada);

    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) {
        printf("\n%sERRO: Arquivo de usuarios nao encontrado. Crie dados de teste.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }

    Usuario usuario;
    int login_sucesso = 0;

    // 2. Iterar sobre os usuários para encontrar a correspondência
    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        
        // Deve ser um usuário ATIVO
        if (!usuario.ativo) continue; 

        // 3. Comparar E-mail
        if (strcmp(usuario.email, email) == 0) {
            
            // 4. Comparar HASH da senha
            if (strcmp(usuario.senha_hash, senha_hash_digitada) == 0) {
                
                // Login bem-sucedido: define estado global
                g_idUsuarioLogado = usuario.id;
                strcpy(g_nomeUsuarioLogado, usuario.nome);
                login_sucesso = 1;
                break;
            }
        }
    }
    
    fclose(file);

    if (login_sucesso) {
        printf("\n%sLogin efetuado com sucesso. Bem-vindo(a), %s!%s\n", COLOR_GREEN, g_nomeUsuarioLogado, COLOR_RESET);
        return 1;
    } else {
        printf("\n%sE-mail, senha invalida ou usuario inativo.%s\n", COLOR_RED, COLOR_RESET);
        return 0;
    }
}

void deslogar() {
    g_idUsuarioLogado = 0;
    g_nomeUsuarioLogado[0] = '\0';
    clear_screen();
    printf("Deslogado com sucesso.\n");
}

void incluir_usuario() {
    clear_screen();
    printf("========================================================\n");
    printf("||              INCLUIR NOVO USUÁRIO                  ||\n");
    printf("========================================================\n");
    
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores (IDs 1-10) podem incluir novos usuários.\n");
        return;
    }

    Usuario novo;
    novo.id = obter_proximo_id("usuarios.dat");
    
    ler_string(novo.nome, 100, "Nome do novo usuário: ");
    ler_string(novo.email, 100, "E-mail: ");

    char senha_clara[100];
    ler_string(senha_clara, 100, "Senha Inicial: ");

    calcular_sha256(senha_clara, novo.senha_hash);

    novo.ativo = 1;
    novo.data_criacao = time(NULL);
    novo.data_ultima_atualizacao = novo.data_criacao;
    novo.id_usuario_ultima_atualizacao = g_idUsuarioLogado;

    FILE *file = fopen("usuarios.dat", "ab");
    if (file) {
        fwrite(&novo, sizeof(Usuario), 1, file);
        fclose(file);
        printf("\nUsuário %s (ID %d) incluído com sucesso!\n", novo.nome, novo.id);
        printf("Tipo: %s\n", (novo.id >= 1 && novo.id <= 10) ? "ADMINISTRADOR" : "SIMPLES");
    } else {
        printf("ERRO: Não foi possível abrir o arquivo para escrita.\n");
    }
}

void listar_usuarios() {
    clear_screen();
    printf("========================================================================\n");
    printf("||                      LISTAGEM DE USUÁRIOS                          ||\n");
    printf("========================================================================\n");

    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) { 
        printf("Nenhum usuário cadastrado.\n"); 
        return; 
    }

    Usuario user;
    char buffer_data[20];
    char nome_usuario_auditoria[100];
    
    printf("| ID | Tipo        | Status  | Nome                  | Última Atualização (ID/Nome/Data)\n");
    printf("|----|-------------|---------|-----------------------|---------------------------------------------------\n");

    while (fread(&user, sizeof(Usuario), 1, file)) {
        strftime(buffer_data, 20, "%d/%m/%Y %H:%M", localtime(&user.data_ultima_atualizacao));
        buscar_nome_usuario_por_id(user.id_usuario_ultima_atualizacao, nome_usuario_auditoria);

        printf("| %-2d | %-11s | %-7s | %-21s | ID %-3d / %-15s em %s\n", 
               user.id, 
               (user.id >= 1 && user.id <= 10) ? "ADMIN" : "SIMPLES",
               user.ativo ? "ATIVO" : "INATIVO", 
               user.nome, 
               user.id_usuario_ultima_atualizacao, 
               nome_usuario_auditoria, 
               buffer_data);
    }
    fclose(file);
}

void editar_usuario() {
    clear_screen();
    printf("========================================================\n");
    printf("||               EDITAR USUÁRIO                       ||\n");
    printf("========================================================\n");

    int id_busca;
    printf("Digite o ID do Usuário a ser editado: ");
    if (scanf("%d", &id_busca) != 1) { 
        flush_input(); 
        printf("ID inválido.\n"); 
        return; 
    }
    flush_input();

    FILE *file = fopen("usuarios.dat", "rb+");
    if (!file) { 
        printf("Arquivo de usuários não encontrado.\n"); 
        return; 
    }

    Usuario user;
    long pos = 0;
    int encontrada = 0;

    while (fread(&user, sizeof(Usuario), 1, file)) {
        if (user.id == id_busca) {
            encontrada = 1;
            break;
        }
        pos = ftell(file);
    }

    if (encontrada) {
        printf("\nUsuário encontrado: %s (Status: %s)\n", user.nome, user.ativo ? "ATIVO" : "INATIVO");
        printf(">> ATENÇÃO: A senha é alterada apenas na opção [5] Alterar Senha.\n");

        char novo_nome[100];
        ler_string(novo_nome, 100, "\nNovo Nome (deixe em branco para manter atual): ");
        if (strlen(novo_nome) > 0) {
            strcpy(user.nome, novo_nome);
        }

        char novo_email[100];
        ler_string(novo_email, 100, "\nNovo E-mail (deixe em branco para manter atual): ");
        if (strlen(novo_email) > 0) {
            strcpy(user.email, novo_email);
        }
        
        printf("\nNovo Status (1 para Ativo, 0 para Inativo, qualquer outro para manter atual): ");
        int novo_status;
        if (scanf("%d", &novo_status) == 1 && (novo_status == 0 || novo_status == 1)) {
            user.ativo = novo_status;
        }

        user.id_usuario_ultima_atualizacao = g_idUsuarioLogado;
        user.data_ultima_atualizacao = time(NULL);

        fseek(file, pos, SEEK_SET);
        fwrite(&user, sizeof(Usuario), 1, file);
        printf("\nUsuário ID %d atualizado com sucesso.\n", user.id);

    } else {
        printf("\nUsuário ID %d não encontrado.\n", id_busca);
    }

    fclose(file);
}

void excluir_usuario_logica() {
    clear_screen();
    printf("========================================================\n");
    printf("||         EXCLUIR USUÁRIO (EXCLUSÃO LÓGICA)          ||\n");
    printf("========================================================\n");

    int id_busca;
    printf("Digite o ID do Usuário a ser desativado: ");
    if (scanf("%d", &id_busca) != 1) { 
        flush_input(); 
        printf("ID inválido.\n"); 
        return; 
    }

    if (id_busca == g_idUsuarioLogado) {
        printf("ERRO: Você não pode desativar sua própria conta.\n");
        return;
    }

    FILE *file = fopen("usuarios.dat", "rb+");
    if (!file) { 
        printf("Arquivo de usuários não encontrado.\n"); 
        return; 
    }

    Usuario user;
    long pos = 0;
    int encontrada = 0;

    while (fread(&user, sizeof(Usuario), 1, file)) {
        if (user.id == id_busca && user.ativo == 1) {
            encontrada = 1;
            break;
        }
        pos = ftell(file);
    }

    if (encontrada) {
        user.ativo = 0;
        user.id_usuario_ultima_atualizacao = g_idUsuarioLogado;
        user.data_ultima_atualizacao = time(NULL);

        fseek(file, pos, SEEK_SET);
        fwrite(&user, sizeof(Usuario), 1, file);
        printf("\nUsuário '%s' (ID %d) desativado com sucesso.\n", user.nome, user.id);
    } else {
        printf("\nUsuário ID %d não encontrado ou já está inativo.\n", id_busca);
    }

    fclose(file);
}

void alterar_senha() {
    clear_screen();
    printf("========================================================\n");
    printf("||           ALTERAR SENHA DE OUTRO USUÁRIO           ||\n");
    printf("========================================================\n");

    int id_busca;
    printf("Digite o ID do Usuário para alterar a senha: ");
    if (scanf("%d", &id_busca) != 1) { 
        flush_input(); 
        printf("ID inválido.\n"); 
        return; 
    }
    flush_input();

    FILE *file = fopen("usuarios.dat", "rb+");
    if (!file) { 
        printf("Arquivo de usuários não encontrado.\n"); 
        return; 
    }

    Usuario user;
    long pos = 0;
    int encontrada = 0;

    while (fread(&user, sizeof(Usuario), 1, file)) {
        if (user.id == id_busca) {
            encontrada = 1;
            break;
        }
        pos = ftell(file);
    }

    if (encontrada) {
        printf("\nAlterando senha para: %s (ID %d)\n", user.nome, user.id);

        char nova_senha_clara[100];
        ler_string(nova_senha_clara, 100, "Digite a NOVA SENHA: ");

        calcular_sha256(nova_senha_clara, user.senha_hash);
        user.id_usuario_ultima_atualizacao = g_idUsuarioLogado;
        user.data_ultima_atualizacao = time(NULL);

        fseek(file, pos, SEEK_SET);
        fwrite(&user, sizeof(Usuario), 1, file);
        printf("\nSenha do usuário %s (ID %d) alterada com sucesso.\n", user.nome, user.id);

    } else {
        printf("\nUsuário ID %d não encontrado.\n", id_busca);
    }

    fclose(file);
}

void menu_usuario() {
    int opcao;
    int is_admin = is_admin_user();

    do {
        clear_screen();
        printf("========================================================\n");
        printf("||          GERENCIAR USUÁRIOS                        ||\n");
        printf("|| %-50s ||\n", is_admin ? "ADMINISTRADOR (Acesso Total)" : "SIMPLES (Apenas Leitura)");		
		printf("========================================================\n");
		
        printf("|| [1] %-46s  ||\n", is_admin ? "INCLUIR USUÁRIO" : "INCLUIR USUÁRIO (APENAS ADMIN)");
		printf("|| [2] %-46s  ||\n", "LISTAR USUÁRIOS");
		printf("|| [3] %-46s  ||\n", is_admin ? "EDITAR USUÁRIO" : "EDITAR USUÁRIO (APENAS ADMIN)");
		printf("|| [4] %-46s  ||\n", is_admin ? "EXCLUIR USUÁRIO" : "EXCLUIR USUÁRIO (APENAS ADMIN)");
		printf("|| [5] %-46s  ||\n", is_admin ? "ALTERAR SENHA DE USUÁRIO" : "ALTERAR SENHA DE USUÁRIO (APENAS ADMIN)");		
   
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
            case 5:
                if (is_admin) {
                    if (opcao == 1) incluir_usuario();
                    else if (opcao == 3) editar_usuario();
                    else if (opcao == 4) excluir_usuario_logica();
                    else alterar_senha();
                } else {
                    printf("Acesso negado. Apenas Administradores podem gerenciar usuários.\n");
                }
                break;
            case 2: 
                listar_usuarios();
                break;
            case 0: 
                printf("Voltando ao Menu Cadastros Base...\n"); 
                break;
            default: 
                printf("Opção inválida.\n");
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            flush_input();
            getchar();
        }
    } while (opcao != 0);
}