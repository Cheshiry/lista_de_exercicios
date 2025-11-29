#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "dados.h"

#define MAX_LOTES 100

// Funções de estoque
void incluir_lancamento_estoque();
void registrar_consumo();

// Funções auxiliares FEFO
int get_lotes_fefo(int idProd, LoteFefo lotes[], int max_lotes);
int get_estoque_by_id(int idEstoque, Estoque *est_out);
int get_produto_by_id(int idProduto, Produto *prod_out);

#endif