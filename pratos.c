#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pratos.h"
#include "mesa.h"

Pilha *pilha_criar()
{
    return NULL;
}

Pilha *pilha_empilhar(Pilha *p)
{
    Pilha *novo;
    novo->prox = p;
    return novo;
}

Pilha *pilha_desempilhar(Pilha *p)
{
    Pilha *novo;
    novo = p->prox;
    free(p);
    return novo;
}

int verif_pratos_limpos(Pilha *pratos)
{
    int pratos_limpos = 0;

    Pilha *p = pratos;
    while (p != NULL)
    {
        pratos_limpos++;
        p = p->prox;
    }
    return pratos_limpos;
}
// retirar um prato limpo da pilha, e coloca quatro pratos em uma mesa!!!
// sempre que uma mesa estiver vazia (ainda não ocupada ou recentemente liberada), um funcionário arruma a mesa (coloca pratos que são retirados da pilha).

// adiciona prato limpo

// Um funcionário repõe pratos na pilha de tempos (não sendo necessário que a pilha esteja vazia para que novos pratos sejam adicionados).
//  5) Repor pratos (adicionar pratos na pilha)
Pilha *repor_pratos(Pilha *pratos)
{
    int quant_pratos;
    Pilha *novo = pratos;
    printf("Quantos pratos deseja empilhar?");
    scanf("%d", &quant_pratos);
    for (int i = 0; i < quant_pratos; i++)
    {
        novo = pilha_empilhar(pratos);
    }
    printf("Foram empilhados %d pratos\n", quant_pratos);
    return novo;
};

// Como as mesas possuem 4 lugares, sempre são colocados 4 pratos.
Pilha *pratos_arrumar_mesa(Pilha *pratos, Mesa *mesa)
{
    Pilha *nova;
    int quant_pratos = verif_pratos_limpos(pratos);
    if (quant_pratos >= 4)
    {
        for (int i = 0; i < 4; i++)
        {
            mesa->pratos++;
            nova = pilha_desempilhar(pratos);
        }
    }
    else
    {
        printf("Nao existem pratos suficientes para a mesa!!\n");
        printf("Quantidade de pratos limpos:%d", quant_pratos);
        return pratos;
    }
    return nova;
}

// Caso um grupo com menos de 4 pessoas ocupe uma certa mesa, os pratos excedentes são retirados da mesa e recolocados na pilha de pratos.
Pilha *empilhar_pratos_nao_ocupados(Pilha *pratos, Mesa *mesa)
{
    Pilha *nova = pratos;
    if (mesa->pratos > mesa->pessoas_sentadas)
    {
        while (mesa->pratos > mesa->pessoas_sentadas)
        {
            mesa->pratos--;
            nova = pilha_empilhar(pratos);
        }
    }
    return nova;
}
