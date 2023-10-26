#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pratos.h"
#include "mesa.h"

Pilha *pilha_criar()
{
    return NULL;
}

bool vefica_pratos_limpos(Pilha *pratos);
// retirar um prato limpo da pilha, e coloca quatro pratos em uma mesa!!!
// sempre que uma mesa estiver vazia (ainda não ocupada ou recentemente liberada), um funcionário arruma a mesa (coloca pratos que são retirados da pilha).

// adiciona prato limpo

Pilha *pratos_arrumar_mesa(Pilha *pratos);
// Como as mesas possuem 4 lugares, sempre são colocados 4 pratos.

// Um funcionário repõe pratos na pilha de tempos (não sendo necessário que a pilha esteja vazia para que novos pratos sejam adicionados).
//  5) Repor pratos (adicionar pratos na pilha)
void repor_pratos();

Pilha *pilha_empilhar();

Pilha *pilha_desempilhar();

// Caso um grupo com menos de 4 pessoas ocupe uma certa mesa, os pratos excedentes são retirados da mesa e recolocados na pilha de pratos.
Pilha *empilhar_pratos_nao_ocupados();

Pilha* adicionar_prato_limpo(Pilha *pratos);
