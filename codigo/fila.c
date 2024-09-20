#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesa.h"
// CRIA FILA!!!
Fila *fila_criar()
{
    return NULL;
}

Fila *fila_ultimo_no(Fila *f)
{
    Fila *p = f;
    if (f == NULL)
    {
        return f;
    }
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    return p;
}

// GERA UMA SENHA UNICA
int fila_gerar_senha(Fila *l)
{
    int nova_senha;

    if (l == NULL)
    {
        nova_senha = 1;
        return nova_senha;
    }
    Fila *p = fila_ultimo_no(l);

    nova_senha = p->senha + 1;

    return nova_senha;
}

// REMOVE UM NO DA FILA!!
Fila *fila_remover(Fila *l)
{
    Fila *nova;
    if (l == NULL)
    {
        printf("Fila Vazia!!\n");
        return l;
    }
    nova = l->prox;
    free(l);
    return nova;
}

// QUANDO FOR ENCONTRADO UMA MESA VAZIA, CHAMAR ESSA FUNÇÃO PARA TIRAR 4 PESSOAS DA FILA!!
Fila *fila_mesa_encontrada(Fila *l)
{
    if (l == NULL)
    {
        printf("Fila Vazia!!\n");
        return NULL; // Retorna NULL para indicar que a fila está vazia.
    }

    Fila *nova = l;
    if (l->pessoas > 4)
    {
        l->pessoas = l->pessoas - 4;
    }
    else
    {
        nova = fila_remover(l);
        return nova;
    }
    return l;
}

// INSERE O GRUPO NA FILA!!
Fila *fila_inserir(Fila *l, int senha, int tamanho)
{
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    novo->prox = NULL;
    novo->pessoas = tamanho;
    novo->senha = senha;

    if (l == NULL)
        return novo;

    Fila *p = fila_ultimo_no(l);
    p->prox = novo;
    return l;
}

// ADICIONA UM GRUPO E CRIA UMA SENHA
Fila *fila_adicionar_grupo(Fila *l, int tamanho)
{
    Fila *f = l;
    int senha;
    senha = fila_gerar_senha(l);
    f = fila_inserir(l, senha, tamanho);
    return f;
}

// CRIA GRUPO
Fila *cria_grupo(Fila *l)
{
    int tamanho;
    Fila *novo;
    do
    {
        printf("Insira a quantidade de pessoas do seu grupo: ");
        scanf("%d", &tamanho);
        if (tamanho <= 0)
            printf("Digite um numero valido!!\n");
    } while (tamanho <= 0);

    novo = fila_adicionar_grupo(l, tamanho);

    return novo;
}

// UM GRUPO ABANDONA A FILA
Fila *fila_abandonar(Fila *l, Fila *grupo, int senha)
{
    Fila *ant = l;
    Fila *p;
    if (l == grupo)
    {
        p = l->prox;
        free(l);
        return p;
    }

    while (ant->prox != grupo)
    {
        ant = ant->prox;
    }

    p = grupo->prox;
    ant->prox = p;
    free(grupo);
    return l;
}

// PROCURA O GRUPO NA FILA
Fila *fila_procurar(Fila *l, int senha)
{
    Fila *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (p->senha == senha)
        {
            return p;
        }
    }
    return NULL;
}

// CHAMA AS FUNCOES PARA REMOVER UM GRUPO DA FILA
Fila *fila_sair(Fila *l)
{
    if (l == NULL)
    {
        printf("Nao existem grupos na fila!!\n");
        return l;
    }
    int senha;
    Fila *grupo;
    printf("Por favor! Digite a senha do grupo:");
    scanf("%d", &senha);
    grupo = fila_procurar(l, senha);

    if (grupo != NULL)
    {
        printf("Seu grupo foi retirado da fila!!\n Voce eh sempre bem-vindo novamente.\n");
        l = fila_abandonar(l, grupo, senha);
    }
    else
    {
        printf("Seu grupo nao foi encontrado na fila!!\n");
    }
    return l;
}

// LISTAR QUANTIDADE DE PESSOAS NA FILA.
void fila_quant_pessoas(Fila *l)
{
    int quant_pessoas = 0;
    Fila *p;
    for (p = l; p != NULL; p = p->prox)
    {
        quant_pessoas += p->pessoas;
    }
    printf("Quantidade de pessoas na fila:%d\n", quant_pessoas);
}

// LISTAR NUMERO DE GRUPOS NA FILA
void fila_numero_de_grupo(Fila *l)
{
    int contador = 0;
    Fila *p;
    for (p = l; p != NULL; p = p->prox)
    {
        contador++;
    }
    printf("Grupos na fila:%d\n", contador);
}

void printa_situacao(Fila *f, int pessoas_inicio, int pessoas_fim, int mesas_disponiveis)
{
    if (pessoas_inicio != pessoas_fim)
    {
        if (pessoas_fim != 0)
        {
            if (mesas_disponiveis == 1)
                printf("Foi encontrado 1 mesa para %d membros do primeiro grupo da fila!!\n", pessoas_inicio - pessoas_fim);
            else
            {
                printf("Foi encontrado %d mesas para ser ocupada por %d membros do primeiro grupo da fila!!\n", mesas_disponiveis, pessoas_inicio - pessoas_fim);
            }
            printf("Ainda ficaram %d na Fila de Espera!!\n", pessoas_fim);
            printf("SENHA:%d\n\n", f->senha);
        }
        else
        {
            printf("Foi encontrado %d mesa(s) para ocupar todos membros do grupo!!\n", mesas_disponiveis);
        }
    }
    else
    {
        Fila *p = fila_ultimo_no(f);
        printf("Seu grupo foi adicionado a fila!!\n");
        printf("SENHA:%d\n\n", p->senha);
    }
}

Fila *chegar_grupo(Mesa *restaurante, Fila *fila)
{
    Mesa *mesa_atual = restaurante;
    int mesas_disponiveis = 0;

    if (restaurante == NULL)
    {
        printf("Restaurante nao possui mesas!\n");
        return NULL;
    }
    Fila *f = cria_grupo(fila);

    int pessoas_inicio = f->pessoas;
    int pessoas_fim = pessoas_inicio;

    while (mesa_atual != NULL && f != NULL)
    {
        if (mesa_atual->livre)
        {
            mesa_atual->livre = false;
            mesa_atual->comanda = mesa_gerar_comanda();

            if (f->pessoas <= 4)
            {
                mesa_atual->pessoas_sentadas = f->pessoas;
            }
            else
            {
                mesa_atual->pessoas_sentadas = 4;
            }
            f = fila_mesa_encontrada(f);

            if (f == NULL)
                pessoas_fim = 0;
            else
                pessoas_fim = f->pessoas;

            mesas_disponiveis++;
        }

        mesa_atual = mesa_atual->prox;
    }

    printa_situacao(f, pessoas_inicio, pessoas_fim, mesas_disponiveis);

    return f;
}