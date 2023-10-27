#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct fila
{
    int senha;
    int pessoas;
    struct fila *prox;
};
typedef struct fila Fila;

Fila *fila_criar();

Fila *fila_remover(Fila *l);

Fila *fila_mesa_encontrada(Fila *l);

int fila_gerar_senha(Fila *l);

Fila *fila_inserir(Fila *l, int senha);

Fila *fila_adicionar_grupo(Fila *l, int tamanho);

Fila *fila_abandonar(Fila *l, Fila *grupo, int senha);

Fila *fila_procurar(Fila *l, int senha);

Fila *fila_sair(Fila *l);

void fila_quant_pessoas(Fila *l);

void fila_numero_de_grupo(Fila *l);

Fila* cria_grupo(Fila* l);

#endif


