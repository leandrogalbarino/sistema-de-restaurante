#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pratos.h"
#include "mesa.h"

// CRIA PIHLA VAZIA
Pilha *pilha_criar()
{
    return NULL;
}

// CRIA UM NOVO NO NO TOPO DA PILHA
Pilha *pilha_empilhar(Pilha *p)
{
    // SE p == NULL, então : novo->prox == NULL | se p != NULL novo->prox = p
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    novo->prox = p;
    return novo;
}

// DESEMPILHA, REMOVENDO O NO DO TOPO DA PILHA
Pilha *pilha_desempilhar(Pilha *p)
{
    Pilha *novo;
    novo = p->prox;
    free(p);
    return novo;
}
// VERIFICA A QUANTIDADE DE PRATOS LIMPOS;
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

//  REPOE PRATOS
Pilha *repor_pratos(Pilha *pratos)
{
    int quant_pratos;
    Pilha *novo = pratos;
    printf("Quantos pratos deseja empilhar?");
    scanf("%d", &quant_pratos);
    for (int i = 0; i < quant_pratos; i++)
    {
        novo = pilha_empilhar(novo);
    }
    printf("Foram empilhados %d pratos\n", quant_pratos);
    return novo;
}

// COMO AS MESAS POSSUEM 4 LUGARES, SEMPRE SAO COLOCADOS 4 PRATOS
Pilha *pratos_arrumar_mesa(Pilha *pratos, Mesa *mesa)
{
    Pilha *novo = pratos;
    int quant_pratos = verif_pratos_limpos(pratos);
    if (quant_pratos >= 4)
    {
        if (mesa->pratos == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                mesa->pratos++;
                novo = pilha_desempilhar(novo);
            }
            printf("Mesa arrumada com sucesso!!\n");
        }
        else{
            printf("Mesa ja esta arrumada!!\n");
            return pratos;
        }
    }
    else
    {
        printf("Nao existem pratos suficientes para a mesa!!\n");
        printf("Quantidade de pratos limpos:%d\n", quant_pratos);
        return pratos;
    }
    return novo;
}

// CASO UM GRUPO COM MENOS DE 4 PESSOAS OCUPE UMA MESA, RETIRA OS PRATOS QUE SOBRARAM
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

// IMPRIME A QUANTIDADE DE PRATOS
void pratos_imprimir(Pilha *pratos)
{
    int contador = verif_pratos_limpos(pratos);
    printf("Existem %d pratos na pilha\n", contador);
}
