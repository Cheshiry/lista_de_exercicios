// Arquivo: categorias.h

#ifndef CATEGORIAS_H
#define CATEGORIAS_H

#include <stdlib.h> // Necessário para size_t, usado na persistência

// Estrutura para representar uma categoria de medicamento/material
typedef struct {
    int id;
    char nome[50];
    char descricao[100];      // Descrição detalhada da categoria
    char tipo_controle[20];   // Ex: ABC-A, CONTROLADO, REFRIGERADO
    int ativo;                // Flag de exclusão lógica (1 = Ativo, 0 = Excluído)
} Categoria;

// ==========================================================
// PROTÓTIPOS DE PERSISTÊNCIA (NOVAS FUNÇÕES)
// ==========================================================

// Carrega todas as categorias salvas em arquivo binário
Categoria* carregar_categorias_do_arquivo(int *num_categorias);

// Salva o array de categorias no arquivo binário
int salvar_categorias_no_arquivo(Categoria *categorias, int num_categorias);


// ==========================================================
// PROTÓTIPOS DE CRUD E MENU (Já Existentes)
// ==========================================================
void incluir_categoria();
void listar_categorias();
void editar_categoria();
void excluir_categoria_logica();
void menu_categoria();

// Função auxiliar (Protótipo)
// Esta função será removida quando a persistência real for implementada
Categoria* carrega_categorias_ficticias(int *num_categorias); 

#endif // CATEGORIAS_H