#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "dados.h"

void incluir_produto();
void editar_produto();
void listar_produtos();
void excluir_produto_logica();
void imprimir_detalhes_produto_completo(const Produto *prod);
void buscar_por_codigo();
void buscar_por_principio_ativo();
void buscar_por_indicacao();

#endif