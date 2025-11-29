#ifndef AUTENTICACAO_H
#define AUTENTICACAO_H

#include "dados.h"

// Autenticação
int logar();
void deslogar();

// Gestão de Usuários
void incluir_usuario();
void editar_usuario();
void listar_usuarios();
void alterar_senha();
void excluir_usuario_logica();
void menu_usuario();

#endif