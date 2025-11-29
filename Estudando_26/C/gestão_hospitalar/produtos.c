#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "produtos.h"
#include "utilidades.h"
#include "dados.h"

void incluir_produto() {
    clear_screen();
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores podem incluir produtos.\n");
        return;
    }

    printf("========================================================\n");
    printf("||                INCLUIR NOVO PRODUTO                ||\n");
    printf("========================================================\n");
    
    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void listar_produtos() {
    clear_screen();
    printf("==================================================================================================================================================================================================================================\n");
    printf("||                                                   LISTAGEM DE PRODUTOS E INVENTÁRIO                                                                                                                                          ||\n");
    printf("==================================================================================================================================================================================================================================\n");

    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void editar_produto() {
    clear_screen();
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores podem editar produtos.\n");
        return;
    }

    printf("========================================================\n");
    printf("||                 EDITAR PRODUTO                     ||\n");
    printf("========================================================\n");

    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void excluir_produto_logica() {
    clear_screen();
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores podem excluir produtos.\n");
        return;
    }

    printf("========================================================\n");
    printf("||         EXCLUIR PRODUTO (EXCLUSÃO LÓGICA)          ||\n");
    printf("========================================================\n");

    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void buscar_por_codigo() {
    clear_screen();
    printf("========================================================\n");
    printf("||           BUSCA DE PRODUTO POR CÓDIGO (ID)         ||\n");
    printf("========================================================\n");

    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void buscar_por_principio_ativo() {
    clear_screen();
    printf("========================================================\n");
    printf("||       BUSCA DE PRODUTO POR PRINCÍPIO ATIVO         ||\n");
    printf("========================================================\n");

	printf("=====================NÃO IMPLEMENTADO===================\n");
}

void buscar_por_indicacao() {
    clear_screen();
    printf("========================================================\n");
    printf("||          BUSCA DE PRODUTO POR INDICAÇÃO            ||\n");
    printf("========================================================\n");

	printf("=====================NÃO IMPLEMENTADO===================\n");
}