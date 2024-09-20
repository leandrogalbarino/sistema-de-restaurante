#ifndef PRATOS_H
#define PRATOS_H
#include "mesa.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pilha{ 
    struct pilha *prox;
}; typedef struct pilha Pilha;

Pilha *pilha_criar();

Pilha *pilha_empilhar(Pilha *p);

Pilha *pilha_desempilhar(Pilha *p);

int verif_pratos_limpos(Pilha *pratos);

Pilha *repor_pratos(Pilha *pratos);

Pilha *pratos_arrumar_mesa(Pilha *pratos, Mesa *mesa);

Pilha *empilhar_pratos_nao_ocupados(Pilha *pratos, Mesa *mesa);

void pratos_imprimir(Pilha *pratos);

#endif