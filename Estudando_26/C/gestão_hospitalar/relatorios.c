#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorios.h"
#include "utilidades.h"
#include "dados.h"
#include "estoque.h"

void relatorio_consumo_matriz() {
    //clear_screen();
    printf("======================================================================================================================================================\n");
    printf("||                                      RELATÓRIO AGREGADO DE CONSUMO POR LOTE E CUSTO                                                              ||\n");
    printf("======================================================================================================================================================\n");
    
    printf("=====================NÃO IMPLEMENTADO===================\n");
}

void popular_sistema() {
    //clear_screen();
    printf("========================================================\n");
    printf("|| INICIAR/REINICIAR DADOS DE TESTE (FICTÍCIOS)       ||\n");
    printf("========================================================\n");

    g_idUsuarioLogado = 0;
    g_nomeUsuarioLogado[0] = '\0';
    
    char senha_padrao[] = "102030";
    char hash_padrao[65];
    calcular_sha256(senha_padrao, hash_padrao);
    time_t now = time(NULL);
    int admin_id = 1;

    FILE *f_user = fopen("usuarios.dat", "wb");
    if (!f_user) { 
        printf("ERRO: Não foi possível criar o arquivo de usuários.\n"); 
        return; 
    }
    Usuario adm = { .id = admin_id, .ativo = 1, .data_criacao = now, .data_ultima_atualizacao = now, .id_usuario_ultima_atualizacao = admin_id };
    strcpy(adm.nome, "Admin Master"); 
    strcpy(adm.email, "admin@usf.com"); 
    strcpy(adm.senha_hash, hash_padrao);
    fwrite(&adm, sizeof(Usuario), 1, f_user);
    
    Usuario simples = { .id = 11, .ativo = 1, .data_criacao = now, .data_ultima_atualizacao = now, .id_usuario_ultima_atualizacao = admin_id };
    strcpy(simples.nome, "Usuario Simples"); 
    strcpy(simples.email, "user@usf.com"); 
    strcpy(simples.senha_hash, hash_padrao);
    fwrite(&simples, sizeof(Usuario), 1, f_user);
    fclose(f_user);
    printf("-> Dados de Usuários criados.\n");

    FILE *f_cat = fopen("categorias.dat", "wb");
    if (!f_cat) { 
        printf("ERRO: Não foi possível criar o arquivo de categorias.\n"); 
        return; 
    }
    Categoria c1 = {1, "Antibióticos", 1, admin_id, now}; 
    fwrite(&c1, sizeof(Categoria), 1, f_cat);
    Categoria c2 = {2, "Analgésicos", 1, admin_id, now}; 
    fwrite(&c2, sizeof(Categoria), 1, f_cat);
    Categoria c3 = {3, "Anti-inflamatórios", 1, admin_id, now}; 
    fwrite(&c3, sizeof(Categoria), 1, f_cat);
    Categoria c4 = {4, "Vacinas", 0, admin_id, now}; 
    fwrite(&c4, sizeof(Categoria), 1, f_cat);
    fclose(f_cat);
    printf("-> Dados de Categorias criados.\n");

    FILE *f_forn = fopen("fornecedores.dat", "wb");
    if (!f_forn) { 
        printf("ERRO: Não foi possível criar o arquivo de fornecedores.\n"); 
        return; 
    }
    Fornecedor f1 = {1, "Eurofarma", "João Silva", "5511987654321", 1, admin_id, now}; 
    fwrite(&f1, sizeof(Fornecedor), 1, f_forn);
    Fornecedor f2 = {2, "EMS", "Maria Oliveira", "5511987654322", 1, admin_id, now}; 
    fwrite(&f2, sizeof(Fornecedor), 1, f_forn);
    Fornecedor f3 = {3, "AstraZeneca", "Carlos Pereira", "5511987654323", 1, admin_id, now}; 
    fwrite(&f3, sizeof(Fornecedor), 1, f_forn);
    fclose(f_forn);
    printf("-> Dados de Fornecedores criados.\n");

    FILE *f_prod = fopen("produtos.dat", "wb");
    if (!f_prod) { 
        printf("ERRO: Não foi possível criar o arquivo de produtos.\n"); 
        return; 
    }
    Produto p1 = { .id = 1, .idCategoria = 1, .idFornecedor = 1, .ativo = 1, .data_ultima_atualizacao = now, .id_usuario_ultima_atualizacao = admin_id };
    strcpy(p1.nome, "Amoxicilina 500mg"); 
    strcpy(p1.principioAtivo, "Amoxicilina"); 
    strcpy(p1.indicacao, "Infecções bacterianas");
    fwrite(&p1, sizeof(Produto), 1, f_prod);
    
    Produto p2 = { .id = 2, .idCategoria = 2, .idFornecedor = 2, .ativo = 1, .data_ultima_atualizacao = now, .id_usuario_ultima_atualizacao = admin_id };
    strcpy(p2.nome, "Dipirona 1g injetável"); 
    strcpy(p2.principioAtivo, "Dipirona Monoidratada"); 
    strcpy(p2.indicacao, "Dor e febre");
    fwrite(&p2, sizeof(Produto), 1, f_prod);
    
    Produto p3 = { .id = 3, .idCategoria = 3, .idFornecedor = 3, .ativo = 0, .data_ultima_atualizacao = now, .id_usuario_ultima_atualizacao = admin_id };
    strcpy(p3.nome, "Ibuprofeno 600mg"); 
    strcpy(p3.principioAtivo, "Ibuprofeno"); 
    strcpy(p3.indicacao, "Inflamação e dor");
    fwrite(&p3, sizeof(Produto), 1, f_prod);
    fclose(f_prod);
    printf("-> Dados de Produtos criados.\n");
    
    FILE *f_estoque = fopen("estoque.dat", "wb");
    if (!f_estoque) { 
        printf("ERRO: Não foi possível criar o arquivo de estoque.\n"); 
        return; 
    }
    
    Estoque e1 = {1, 1, 100, 5.50, "31/12/2026", admin_id, now}; 
    fwrite(&e1, sizeof(Estoque), 1, f_estoque);

    Estoque e2 = {2, 1, 50, 6.00, "15/05/2026", admin_id, now};
    fwrite(&e2, sizeof(Estoque), 1, f_estoque);

    Estoque e3 = {3, 2, 200, 2.15, "01/01/2027", admin_id, now};
    fwrite(&e3, sizeof(Estoque), 1, f_estoque);
    
    fclose(f_estoque);
    printf("-> Dados de Estoque (Lotes) criados.\n");

    FILE *f_consumo = fopen("consumo.dat", "wb");
    if (!f_consumo) { 
        printf("ERRO: Não foi possível criar o arquivo de consumo.\n"); 
        return; 
    }

    Consumo con1 = {
        .id = 1, 
        .idEstoque = 1, 
        .quantidade = 10, 
        .data_hora_consumo = now,
        .id_usuario_ultima_atualizacao = admin_id,
        .data_ultima_atualizacao = now
    }; 
    strcpy(con1.nome_pessoa_consumo, "João Paciente");
    strcpy(con1.observacoes, "Teste inicial de consumo");
    fwrite(&con1, sizeof(Consumo), 1, f_consumo);

    Consumo con2 = {
        .id = 2, 
        .idEstoque = 3, 
        .quantidade = 5, 
        .data_hora_consumo = now,
        .id_usuario_ultima_atualizacao = admin_id,
        .data_ultima_atualizacao = now
    };
    strcpy(con2.nome_pessoa_consumo, "Maria Paciente");
    strcpy(con2.observacoes, "Dor de cabeça, saída emergencial");
    fwrite(&con2, sizeof(Consumo), 1, f_consumo);

    fclose(f_consumo);
    printf("-> Dados de Consumo de teste criados.\n");
    
    printf("\nSistema populado com dados de teste. Por favor, faça login com:\n");
    printf("   ADMIN: E-mail: admin@usf.com | Senha: 102030\n");
    printf("   USER:  E-mail: user@usf.com  | Senha: 102030\n");
}