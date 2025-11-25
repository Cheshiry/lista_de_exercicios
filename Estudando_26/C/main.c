#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilidades.h"
#include "autenticacao.h"
#include "categorias.h"
#include "fornecedores.h"
#include "produtos.h"
#include "estoque.h"
#include "relatorios.h"

extern void carregar_dados_iniciais();

void mostrar_menu_login() {
    clear_screen();
    int width = 60;
    
    print_line(width);
    print_centered("SISTEMA DE GESTAO DE FARMACIA HOSPITALAR", width - 2);
    print_middle_line(width);
    print_centered("Sistema Integrado de Controle de Medicamentos", width - 2);
    print_middle_line(width);
    
    printf("| %s[ 1 ]%s %-50s |\n", COLOR_GREEN, COLOR_RESET, "Fazer Login");
    printf("| %s[ 2 ]%s %-50s |\n", COLOR_GREEN, COLOR_RESET, "Iniciar/Reiniciar Dados de Teste");
    printf("| %s[ 0 ]%s %-50s |\n", COLOR_RED, COLOR_RESET, "Sair do Sistema");
    
    print_bottom_line(width);
    printf("%s>> Escolha uma opcao:%s ", COLOR_BOLD, COLOR_RESET);
}

void mostrar_menu_principal() {
    clear_screen();
    int width = 70;
    
    print_line(width);
    print_centered("MENU PRINCIPAL - FARMACIA HOSPITALAR", width - 2);
    print_middle_line(width);
    
    // Informações do usuário
    char user_info[100];
    snprintf(user_info, sizeof(user_info), "Usuário: %s (ID: %d) - %s", 
             g_nomeUsuarioLogado, g_idUsuarioLogado, 
             is_admin_user() ? "ADMINISTRADOR" : "USUARIO SIMPLES");
    printf("| %s%-67s%s |\n", COLOR_YELLOW, user_info, COLOR_RESET);
    print_middle_line(width);
    
    // CADASTROS BASE
    print_subheader("CADASTROS BASE");
    print_menu_option(1, "Gerenciar Categorias, Fornecedores e Usuarios", 1);
    print_middle_line(width);
    
    // PRODUTOS
    print_subheader("GERENCIAR PRODUTOS");
    print_menu_option(21, "Incluir Novo Produto", is_admin_user());
    print_menu_option(22, "Listar Todos os Produtos", 1);
    print_menu_option(23, "Editar Produto", is_admin_user());
    print_menu_option(24, "Excluir Produto", is_admin_user());
    print_middle_line(width);
    
    // ESTOQUE
    print_subheader("CONTROLE DE ESTOQUE");
    print_menu_option(31, "Incluir Lancamento de Estoque (Lote)", is_admin_user());
    print_menu_option(32, "Registrar Consumo (Saida - FEFO)", is_admin_user());
    print_middle_line(width);
    
    // LOCALIZAR
    print_subheader("LOCALIZAR PRODUTOS");
    print_menu_option(41, "Buscar por Codigo (ID)", 1);
    print_menu_option(42, "Buscar por Principio Ativo", 1);
    print_menu_option(43, "Buscar por Indicacao", 1);
    print_middle_line(width);
    
    // RELATÓRIOS
    print_subheader("RELATORIOS");
    print_menu_option(51, "Relatorio: Consumo por Lote e Custo (Agregado)", 1);
    print_middle_line(width);
    
    // SAIR
    print_menu_option(0, "Fazer Logout e Sair do Sistema", 1);
    
    print_bottom_line(width);
    printf("%s>> Escolha uma opcao:%s ", COLOR_BOLD, COLOR_RESET);
}

void menu_cadastros_base() {
    int opcao;
    do {
        clear_screen();
        int width = 70;
        
        print_line(width);
        print_centered("MENU CADASTROS BASE", width - 2);
        print_middle_line(width);
        
        char user_info[100];
        snprintf(user_info, sizeof(user_info), "Usuário: %s (ID: %d)", 
                 g_nomeUsuarioLogado, g_idUsuarioLogado);
        printf("| %s%-67s%s |\n", COLOR_YELLOW, user_info, COLOR_RESET);
        print_middle_line(width);
        
        print_subheader("Selecione o Modulo:");
        print_menu_option(1, "Gerenciar Categorias", 1);
        print_menu_option(2, "Gerenciar Fornecedores", 1);
        print_menu_option(3, "Gerenciar Usuarios", is_admin_user());
        print_menu_option(0, "Voltar ao Menu Principal", 1);
        
        print_bottom_line(width);
        printf("%s>> Escolha uma opcao:%s ", COLOR_BOLD, COLOR_RESET);

        if (scanf("%d", &opcao) != 1) { 
            opcao = -1; 
            flush_input(); 
        }
        clear_screen();

        switch (opcao) {
            case 1: menu_categoria(); break;
            case 2: menu_fornecedor(); break;
            case 3: 
                if (is_admin_user()) {
                    menu_usuario(); 
                } else {
                    printf("\n%sERRO: Acesso negado. Apenas administradores podem gerenciar usuarios.%s\n", COLOR_RED, COLOR_RESET);
                }
                break;
            case 0: 
                printf("\n%sVoltando ao Menu Principal...%s\n", COLOR_BLUE, COLOR_RESET); 
                break;
            default: 
                printf("\n%sERRO: Opcao invalida.%s\n", COLOR_RED, COLOR_RESET);
        }

        if (opcao != 0) {
            printf("\n%sPressione ENTER para continuar...%s", COLOR_CYAN, COLOR_RESET);
            flush_input();
            getchar();
        }
    } while (opcao != 0);
}

int main() {
    int opcao_login;
    int logado = 0;
    
    carregar_dados_iniciais();
    
    

    while (logado == 0) {
        mostrar_menu_login();

        if (scanf("%d", &opcao_login) != 1) { 
            opcao_login = -1; 
            flush_input(); 
        }
        clear_screen();

        switch (opcao_login) {
            case 1: 
                logado = logar(); 
                break;
            case 2: 
                popular_sistema(); 
                break;
            case 0: 
                printf("\n%sObrigado por usar o sistema!%s\n", COLOR_GREEN, COLOR_RESET); 
                return 0;
            default: 
                printf("\n%sERRO: Opcao invalida. Tente novamente.%s\n", COLOR_RED, COLOR_RESET);
        }

        if (logado == 0 && opcao_login != 0) {
            printf("\n%sPressione ENTER para continuar...%s", COLOR_CYAN, COLOR_RESET);
            flush_input();
            getchar();
        }
    }
    
    int opcao;
    do {
        mostrar_menu_principal();

        if (scanf("%d", &opcao) != 1) { 
            opcao = -1; 
            flush_input(); 
        }
        clear_screen();

        switch (opcao) {
            case 1: menu_cadastros_base(); break;
            case 21: incluir_produto(); break;
            case 22: listar_produtos(); break;
            case 23: editar_produto(); break;
            case 24: excluir_produto_logica(); break;
            case 31: incluir_lancamento_estoque(); break;
            case 32: registrar_consumo(); break;
            case 41: buscar_por_codigo(); break;
            case 42: buscar_por_principio_ativo(); break;
            case 43: buscar_por_indicacao(); break;
            case 51: relatorio_consumo_matriz(); break;
            case 0: 
                deslogar(); 
                logado = 0; 
                printf("\n%sLogout realizado com sucesso!%s\n", COLOR_GREEN, COLOR_RESET); 
                break;
            default: 
                printf("\n%sERRO: Opcao invalida.%s\n", COLOR_RED, COLOR_RESET);
        }

        if (opcao != 0) {
            printf("\n%sPressione ENTER para continuar...%s", COLOR_CYAN, COLOR_RESET);
            flush_input();
            getchar();
        }

    } while (opcao != 0 && logado == 1);

    if (logado == 0) {
        main();
    }
    
    return 0;
}