#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estoque.h"
#include "utilidades.h"
#include "dados.h"

void incluir_lancamento_estoque() {
    clear_screen();
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores podem incluir lançamentos de estoque.\n");
        return;
    }
    
    printf("========================================================\n");
    printf("||           INCLUIR NOVO LOTE (ESTOQUE)              ||\n");
    printf("========================================================\n");
    
    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void registrar_consumo() {
    clear_screen();
    if (!is_admin_user()) {
        printf("Acesso negado. Apenas Administradores podem registrar consumo.\n");
        return;
    }
    
    printf("========================================================\n");
    printf("||              REGISTRAR CONSUMO (SAÍDA)             ||\n");
    printf("========================================================\n");
    
    printf("=====================NÃO IMPLEMENTADO===================\n");
}