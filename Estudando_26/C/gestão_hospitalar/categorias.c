// Arquivo: categorias.c
// =================================================================
// INCLUDES
// =================================================================
#include <stdio.h>    // Para funções de I/O: printf, scanf, FILE, fopen, fread, fwrite
#include <stdlib.h>   // Para gerenciamento de memória: malloc, realloc, free, NULL
#include <string.h>   // Para manipulação de strings: strcpy, strlen, strcspn
#include <time.h>     // Para manipulação de tempo: time()

// SEUS CABEÇALHOS DE PROJETO
#include "categorias.h" 
#include "utilidades.h" // Assumindo que clear_screen, flush_input, is_admin_user estão aqui
#include "dados.h"      // Define outras structs e constantes

// Constante para persistência de dados
#define NOME_ARQUIVO_CATEGORIAS "categorias.dat"


// =================================================================
// FUNÇÕES DE PERSISTÊNCIA (IMPLEMENTADAS)
// =================================================================

// Carrega todas as categorias salvas em arquivo binário
Categoria* carregar_categorias_do_arquivo(int *num_categorias) {
    FILE *arquivo = fopen(NOME_ARQUIVO_CATEGORIAS, "rb");
    Categoria *categorias = NULL;
    *num_categorias = 0;

    if (arquivo == NULL) {
        // Se o arquivo não existir (primeira execução), retorna NULL
        printf("Arquivo de categorias (%s) não encontrado. Iniciando vazio.\n", NOME_ARQUIVO_CATEGORIAS);
        return NULL; 
    }

    // Calcula o tamanho do arquivo e o número de registros
    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    *num_categorias = tamanho_arquivo / sizeof(Categoria);
    
    // Aloca memória e lê todos os registros
    categorias = (Categoria *) malloc(tamanho_arquivo);

    if (categorias == NULL) {
        printf("Erro na alocação de memória para carregar categorias.\n");
        fclose(arquivo);
        return NULL;
    }

    fseek(arquivo, 0, SEEK_SET);
    fread(categorias, sizeof(Categoria), *num_categorias, arquivo);
    
    fclose(arquivo);
    printf("Carregadas %d categorias do arquivo.\n", *num_categorias);
    return categorias;
}

// Salva o array de categorias no arquivo binário
int salvar_categorias_no_arquivo(Categoria *categorias, int num_categorias) {
    FILE *arquivo = fopen(NOME_ARQUIVO_CATEGORIAS, "wb");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar categorias.\n");
        return 0; // Falha
    }

    // Escreve todo o array de categorias de uma vez
    size_t elementos_escritos = fwrite(categorias, sizeof(Categoria), num_categorias, arquivo);
    
    fclose(arquivo);

    if (elementos_escritos == num_categorias) {
        return 1; // Sucesso
    } else {
        printf("Erro: Apenas %zu de %d categorias foram salvas.\n", elementos_escritos, num_categorias);
        return 0; // Falha
    }
}


// =================================================================
// FUNÇÃO DE INCLUSÃO (ADAPTADA COM PERSISTÊNCIA)
// =================================================================

void incluir_categoria() {
    clear_screen();
    printf("========================================================\n");
    printf("||               INCLUIR NOVA CATEGORIA               ||\n");
    printf("========================================================\n");
    
    // 1. CARREGAR DADOS EXISTENTES
    int num_categorias = 0;
    Categoria *categorias = carregar_categorias_do_arquivo(&num_categorias);
    
    // 2. REALOCAR MEMÓRIA PARA O NOVO REGISTRO
    categorias = (Categoria *) realloc(categorias, (num_categorias + 1) * sizeof(Categoria));

    if (categorias == NULL) {
        printf("Erro de memória ao incluir nova categoria.\n");
        return;
    }

    Categoria nova_categoria;
    
    // 3. GERAÇÃO DE ID E ENTRADA DE DADOS
    
    // Gera ID sequencial (ID da última categoria + 1, ou 1 se for a primeira)
    if (num_categorias > 0) {
        nova_categoria.id = categorias[num_categorias - 1].id + 1;
    } else {
        nova_categoria.id = 1;
    }
    
    flush_input(); // Limpa buffer antes do fgets

    printf(">> ID Gerado: %d\n", nova_categoria.id);

    // Nome da Categoria
    printf(">> Digite o Nome da Categoria (max 49): ");
    if (fgets(nova_categoria.nome, 50, stdin) == NULL || strlen(nova_categoria.nome) <= 1) {
        printf("Nome inválido. Cancelando operação.\n");
        free(categorias);
        return;
    }
    nova_categoria.nome[strcspn(nova_categoria.nome, "\n")] = 0; // Remove o '\n'

    // Descrição
    printf(">> Digite a Descrição (max 99): ");
    if (fgets(nova_categoria.descricao, 100, stdin) == NULL) {
        // Assume que descrição vazia é permitida
    }
    nova_categoria.descricao[strcspn(nova_categoria.descricao, "\n")] = 0; 

    // Tipo de Controle 
    printf(">> Digite o Tipo de Controle (Ex: ABC-A, REFRIGERADO, etc, max 19): ");
    if (fgets(nova_categoria.tipo_controle, 20, stdin) == NULL) {
        // Assume que tipo_controle vazio é permitido
    }
    nova_categoria.tipo_controle[strcspn(nova_categoria.tipo_controle, "\n")] = 0; 

    // 4. CONFIGURAÇÃO PADRÃO
    nova_categoria.ativo = 1; // Nova categoria é sempre ativa

    // 5. ADICIONA NOVO REGISTRO NO ARRAY
    categorias[num_categorias] = nova_categoria;
    num_categorias++;

    // 6. SALVAR DADOS ATUALIZADOS
    if (salvar_categorias_no_arquivo(categorias, num_categorias)) {
        printf("\n========================================================\n");
        printf(" ✅ CATEGORIA ID %d CADASTRADA e SALVA COM SUCESSO!\n", nova_categoria.id);
        printf("========================================================\n");
    } else {
        printf("\n ❌ Erro: Categoria cadastrada na memória, mas falha ao salvar no arquivo.\n");
    }

    free(categorias); // Liberar a memória alocada dinamicamente
}


// =================================================================
// FUNÇÕES DE CRUD (Esqueletos originais - A SEREM ADAPTADAS)
// =================================================================

void listar_categorias() {
    clear_screen();
    printf("========================================================\n");
    printf("||             LISTAGEM DE CATEGORIAS SALVAS          ||\n");
    printf("========================================================\n");

    int num_categorias = 0;
    // 1. Carrega dados do arquivo (substituindo o fictício)
    Categoria *categorias = carregar_categorias_do_arquivo(&num_categorias);

    if (categorias == NULL || num_categorias == 0) {
        printf("Nenhuma categoria encontrada no arquivo.\n");
        return;
    }

    // Tabela de listagem
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-30s | %-55s | %-15s | %-6s |\n", 
           "ID", "NOME", "DESCRIÇÃO", "TIPO CONTROLE", "STATUS");
    printf("---------------------------------------------------------------------------------------------------------------------\n");

    int categorias_ativas = 0;
    for (int i = 0; i < num_categorias; i++) {
        // Exibe categorias ATIVAS e INATIVAS
        printf("| %-5d | %-30s | %-55s | %-15s | %-6s |\n",
               categorias[i].id, 
               categorias[i].nome, 
               categorias[i].descricao,
               categorias[i].tipo_controle,
               (categorias[i].ativo == 1 ? "ATIVO" : "INATIVO"));
        
        if (categorias[i].ativo == 1) {
            categorias_ativas++;
        }
    }

    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("Total de Categorias Ativas: %d (Total de Registros: %d)\n", categorias_ativas, num_categorias);
    
    // Liberar a memória
    free(categorias);
}

void editar_categoria() {
    clear_screen();
    printf("========================================================\n");
    printf("||                 EDITAR CATEGORIA                   ||\n");
    printf("========================================================\n");

    printf("\n>>> Funcionalidade de Edição deve ser adaptada para ler e escrever no arquivo. <<<\n");
}

void excluir_categoria_logica() {
    clear_screen();
    printf("========================================================\n");
    printf("||         EXCLUIR CATEGORIA (EXCLUSÃO LÓGICA)        ||\n");
    printf("========================================================\n");

    printf("\n>>> Funcionalidade de Exclusão Lógica deve ser adaptada para ler e escrever no arquivo. <<<\n");
}

// A função menu_categoria() permanece como esqueleto
void menu_categoria() {
    int opcao;
    int is_admin = is_admin_user(); // Assumindo is_admin_user está em utilidades.h

    do {
        clear_screen();
		// ... (código do menu) ...
		printf("========================================================\n");
		printf("||             GERENCIAR CATEGORIAS                     ||\n");		
		printf("|| %-50s ||\n", is_admin ? "ADMINISTRADOR (Acesso Total)" : "SIMPLES (Apenas Leitura)");		
		printf("========================================================\n");		
		
		printf("|| [1] %-46s ||\n", is_admin ? "INCLUIR CATEGORIA" : "INCLUIR CATEGORIA (APENAS ADMIN)");
		printf("|| [2] %-46s ||\n", "LISTAR CATEGORIAS");
		printf("|| [3] %-46s ||\n", is_admin ? "EDITAR CATEGORIA" : "EDITAR CATEGORIA (APENAS ADMIN)");
		printf("|| [4] %-46s ||\n", is_admin ? "EXCLUIR CATEGORIA" : "EXCLUIR CATEGORIA (APENAS ADMIN)");
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
                    if (opcao == 1) incluir_categoria();
                    // As funções 3 e 4 ainda precisam ser totalmente adaptadas
                    else if (opcao == 3) editar_categoria();
                    else excluir_categoria_logica();
                } else {
                    printf("Acesso negado. Apenas Administradores podem realizar operações de escrita.\n");
                }
                break;
            case 2: 
                listar_categorias();
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

// Nota: A função carrega_categorias_ficticias não é mais necessária e foi removida.