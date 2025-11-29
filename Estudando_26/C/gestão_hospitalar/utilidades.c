#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utilidades.h"
#include "dados.h"

// DEFINIR as variáveis globais APENAS AQUI
int g_idUsuarioLogado = 0;
char g_nomeUsuarioLogado[100] = "";

void flush_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\033[H\033[J");
    #endif
}

void limpar_buffer() {
    flush_input();
}

void calcular_sha256(const char *input, char *output) {
    if (input == NULL || output == NULL) {
        output[0] = '\0';
        return;
    }
    unsigned int hash_val = 0;
    size_t i;
    for (i = 0; i < strlen(input); i++) {
        hash_val = (hash_val << 5) - hash_val + input[i];
        hash_val = hash_val ^ (hash_val >> 16);
    }
    snprintf(output, 65, 
             "%08x%08x%08x%08x%08x%08x%08x%08x", 
             hash_val, hash_val * 2, hash_val * 3, hash_val * 4, 
             hash_val * 5, hash_val * 6, hash_val * 7, hash_val * 8);
    output[64] = '\0';
}

long data_para_int(const char *data_str) {
    int dia, mes, ano;
    if (sscanf(data_str, "%d/%d/%d", &dia, &mes, &ano) == 3) {
        return ano * 10000 + mes * 100 + dia;
    }
    return 0;
}

int obter_proximo_id(const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "rb");
    if (!file) { return 1; }
    
    int current_id = 0;
    
    if (strcmp(nomeArquivo, "usuarios.dat") == 0) { 
        Usuario reg; 
        while (fread(&reg, sizeof(Usuario), 1, file)) { 
            current_id = reg.id; 
        } 
    } 
    else if (strcmp(nomeArquivo, "categorias.dat") == 0) { 
        Categoria reg; 
        while (fread(&reg, sizeof(Categoria), 1, file)) { 
            current_id = reg.id; 
        } 
    } 
    else if (strcmp(nomeArquivo, "fornecedores.dat") == 0) { 
        Fornecedor reg; 
        while (fread(&reg, sizeof(Fornecedor), 1, file)) { 
            current_id = reg.id; 
        } 
    } 
    else if (strcmp(nomeArquivo, "produtos.dat") == 0) { 
        Produto reg; 
        while (fread(&reg, sizeof(Produto), 1, file)) { 
            current_id = reg.id; 
        } 
    } 
    else if (strcmp(nomeArquivo, "estoque.dat") == 0) { 
        Estoque reg; 
        while (fread(&reg, sizeof(Estoque), 1, file)) { 
            current_id = reg.id; 
        } 
    } 
    else if (strcmp(nomeArquivo, "consumo.dat") == 0) { 
        Consumo reg; 
        while (fread(&reg, sizeof(Consumo), 1, file)) { 
            current_id = reg.id; 
        }
    }

    fclose(file);
    return current_id + 1;
}

void buscar_nome_usuario_por_id(int id, char *nome_output) {
    if (id <= 0) {
        strcpy(nome_output, "Sistema/Invalido");
        return;
    }

    FILE *file = fopen("usuarios.dat", "rb");
    if (!file) {
        strcpy(nome_output, "ARQUIVO INDISPONÍVEL");
        return;
    }

    Usuario usuario;
    int encontrado = 0;

    while (fread(&usuario, sizeof(Usuario), 1, file)) {
        if (usuario.id == id) {
            strcpy(nome_output, usuario.nome);
            encontrado = 1;
            break;
        }
    }

    fclose(file);

    if (!encontrado) {
        strcpy(nome_output, "ID NÃO CADASTRADO");
    }
}

void buscar_nome_categoria_por_id(int id, char *nome_output) {
    FILE *file = fopen("categorias.dat", "rb");
    if (!file) { 
        strcpy(nome_output, "ERRO ARQUIVO"); 
        return; 
    }

    Categoria cat;
    int encontrado = 0;
    while (fread(&cat, sizeof(Categoria), 1, file)) {
        if (cat.id == id) {
            strcpy(nome_output, cat.nome);
            encontrado = 1;
            break;
        }
    }
    fclose(file);
    if (!encontrado) {
        strcpy(nome_output, "CATEGORIA NAO ENCONTRADA");
    }
}

void buscar_nome_fornecedor_por_id(int id, char *nome_output) {
    FILE *file = fopen("fornecedores.dat", "rb");
    if (!file) { 
        strcpy(nome_output, "ERRO ARQUIVO"); 
        return; 
    }

    Fornecedor forn;
    int encontrado = 0;
    while (fread(&forn, sizeof(Fornecedor), 1, file)) {
        if (forn.id == id) {
            strcpy(nome_output, forn.nome);
            encontrado = 1;
            break;
        }
    }
    fclose(file);
    if (!encontrado) {
        strcpy(nome_output, "FORNECEDOR NAO ENCONTRADO");
    }
}

int calcular_estoque_restante(int idEstoque, int qtd_original) {
    int consumido = 0;
    FILE *f_consumo = fopen("consumo.dat", "rb");

    if (f_consumo) {
        Consumo cons;
        while (fread(&cons, sizeof(Consumo), 1, f_consumo)) {
            if (cons.idEstoque == idEstoque) {
                consumido += cons.quantidade;
            }
        }
        fclose(f_consumo);
    }
    
    return qtd_original - consumido;
}

int validar_data_validade(const char *data_str) {
    int dia, mes, ano;

    if (sscanf(data_str, "%2d/%2d/%4d", &dia, &mes, &ano) != 3) {
        printf("ERRO: Formato de data inválido. Use DD/MM/AAAA.\n");
        return 0;
    }

    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("ERRO: Mês ou Dia fora do intervalo normal (1-12 e 1-31).\n");
        return 0;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("ERRO: Dia inválido para o mês.\n");
        return 0;
    }
    
    if (mes == 2) {
        int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
        if (dia > 29 || (dia == 29 && !bissexto)) {
            printf("ERRO: Dia inválido para Fevereiro.\n");
            return 0;
        }
    }
    
    struct tm validade_tm = {0};
    validade_tm.tm_year = ano - 1900;
    validade_tm.tm_mon = mes - 1;
    validade_tm.tm_mday = dia;
    
    time_t validade_time = mktime(&validade_tm);

    time_t now_time;
    time(&now_time);
    struct tm *now_tm = localtime(&now_time);
    now_tm->tm_hour = 0;
    now_tm->tm_min = 0;
    now_tm->tm_sec = 0;
    time_t hoje_sem_hora = mktime(now_tm);

    if (validade_time <= hoje_sem_hora) {
        printf("ERRO: Data de Validade deve ser estritamente futura.\n");
        return 0;
    }

    return 1;
}

int is_admin_user() {
    return (g_idUsuarioLogado >= 1 && g_idUsuarioLogado <= 10);
}

void ler_string(char *string, int tamanho, const char *prompt) {
    printf("%s", prompt);
    if (fgets(string, tamanho, stdin)) {
        // 1. Tentar encontrar e remover o '\n'
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0';
        } else {
            // 2. Se o '\n' não foi encontrado, a linha era maior que o buffer. 
            //    Limpar o restante da entrada (o que seria o flush_input())
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    }
}

// FUNÇÕES DE INTERFACE - USANDO CARACTERES DIRETAMENTE

void print_centered(const char *text, int width) {
    int len = strlen(text);
    int padding = (width - len) / 2;
    printf("|");
    for (int i = 0; i < padding; i++) printf(" ");
    printf("%s%s%s", COLOR_BOLD, text, COLOR_RESET);
    for (int i = 0; i < width - len - padding; i++) printf(" ");
    printf("|\n");
}

void print_line(int length) {
    printf("+");
    for (int i = 0; i < length - 2; i++) printf("-");
    printf("+\n");
}

void print_middle_line(int length) {
    printf("+");
    for (int i = 0; i < length - 2; i++) printf("-");
    printf("+\n");
}

void print_bottom_line(int length) {
    printf("+");
    for (int i = 0; i < length - 2; i++) printf("-");
    printf("+\n");
}

void print_header(const char *title) {
    int width = 60;
    print_line(width);
    print_centered(title, width - 2);
    print_middle_line(width);
}

void print_menu_option(int number, const char *text, int is_available) {
    if (is_available) {
        printf("| %s[%2d]%s %-61s |\n", COLOR_GREEN, number, COLOR_RESET, text);
    } else {
        printf("| %s[%2d]%s %-61s |\n", COLOR_RED, number, COLOR_RESET, text);
    }
}

void print_subheader(const char *text) {
    printf("| %s%-66s%s |\n", COLOR_CYAN, text, COLOR_RESET);
}

int get_produto_id_by_estoque_id(int idEstoque) {
    FILE *f = fopen("estoque.dat", "rb");
    if (!f) return 0;
    Estoque est;
    while (fread(&est, sizeof(Estoque), 1, f)) {
        if (est.id == idEstoque) {
            fclose(f);
            return est.idProduto;
        }
    }
    fclose(f);
    return 0;
}