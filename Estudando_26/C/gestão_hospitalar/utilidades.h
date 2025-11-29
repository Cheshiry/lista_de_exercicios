#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <stdio.h>
#include "dados.h"

// Códigos de cores ANSI (funcionam em Linux/Mac/Windows 10+)
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"

// Declarar variáveis globais como extern
extern int g_idUsuarioLogado;
extern char g_nomeUsuarioLogado[100];

// Funções utilitárias básicas
void flush_input();
void clear_screen();
void limpar_buffer();

// Funções de arquivo e ID
int obter_proximo_id(const char *nomeArquivo);

// Funções de segurança
void calcular_sha256(const char *input, char *output);

// Funções de data
long data_para_int(const char *data_str);
int validar_data_validade(const char *data_str);

// Funções de busca por ID
void buscar_nome_usuario_por_id(int id, char *nome_output);
void buscar_nome_categoria_por_id(int id, char *nome_output);
void buscar_nome_fornecedor_por_id(int id, char *nome_output);

// Funções de estoque
int calcular_estoque_restante(int idEstoque, int qtd_original);

// Funções de validação
int is_admin_user();
int validar_fk_produto(int idCat, int idForn);
int validar_fk_estoque(int idProd);

// Funções de entrada de dados
void ler_string(char *destino, int tamanho, const char *prompt);

// Função de busca de produto por estoque
int get_produto_id_by_estoque_id(int idEstoque);

// Novas funções de interface
void print_centered(const char *text, int width);
void print_line(int length);
void print_middle_line(int length);
void print_bottom_line(int length);
void print_header(const char *title);
void print_menu_option(int number, const char *text, int is_available);
void print_subheader(const char *text);

#endif