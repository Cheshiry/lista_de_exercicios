#ifndef DADOS_H
#define DADOS_H

#include <time.h>
#include "categorias.h" // Incluído para definir a estrutura Categoria
#define MAX_FORNECEDORES 50

// Estruturas de dados do sistema

typedef struct {
    int id;
    char nome[100];
    char email[100];
    char senha_hash[65];
    int ativo;
    time_t data_criacao;
    int id_usuario_ultima_atualizacao;
    time_t data_ultima_atualizacao;
} Usuario;

// Nota: A estrutura Categoria foi removida daqui e está em categorias.h

typedef struct {
    int id;
    char nome[100];
    char nomeContato[100];
    char numeroWhatsApp[50];
    int ativo;
    int id_usuario_ultima_atualizacao;
    time_t data_ultima_atualizacao;
} Fornecedor;

typedef struct {
    int id;
    int idCategoria; // Agora Categoria está definido via include
    int idFornecedor;
    char nome[300];
    char principioAtivo[300];
    char indicacao[1000];
    int ativo;
    int id_usuario_ultima_atualizacao;
    time_t data_ultima_atualizacao;
} Produto;

typedef struct {
    int id;
    int idProduto;
    int quantidade;
    float valor;
    char dataValidade[11];
    int id_usuario_ultima_atualizacao;
    time_t data_ultima_atualizacao;
} Estoque;

typedef struct {
    int id;
    int idEstoque;
    int quantidade;
    time_t data_hora_consumo;
    char nome_pessoa_consumo[300];
    char observacoes[1000];
    int id_usuario_ultima_atualizacao;
    time_t data_ultima_atualizacao;
} Consumo;

// Estruturas auxiliares
typedef struct {
    Estoque lote;
    long data_int;
} LoteFefo;

typedef struct {
    int idProduto;
    int idLote;
    char nomeProduto[300];
    char principioAtivo[300];
    char dataValidade[11];
    int quantidadeConsumida;
    float valorUnitario;
} RelatorioConsumoAgregado;

#endif