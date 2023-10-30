#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include "mesa.h"
// CRIA FILA!!!
Fila *fila_criar()
{
    return NULL;
}

// GERA UMA SENHA UNICA
int fila_gerar_senha(Fila *l)
{
    int nova_senha;
    Fila *p = l;

    if (l == NULL)
    {
        nova_senha = 1;
        return nova_senha;
    }
    for(p = l; p != NULL; p = p->prox)
    {
        if(p->prox == NULL){
            break;
        }
    }
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
    if (l == NULL) {
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
    Fila *p = l; // Correção: inicializa p com l
    while (p->prox != NULL)
    {
        p = p->prox;
    }
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
    printf("Insira a quantidade de pessoas do seu grupo: ");
    scanf("%d", &tamanho);

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
        // returno o proximo ou NULL, se for o primeiro elemento!!
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


Fila *chegar_grupo(Mesa *restaurante, Fila *fila)
{
    Mesa *mesa_atual = restaurante;
    if (restaurante == NULL)
    {
        printf("Restaurante nao possui mesas!\n");
        return NULL;
    }
    Fila *f = cria_grupo(fila);
    int pessoas_inicio = f->pessoas;
    int pessoas_fim = f->pessoas;
    bool mesa_livre = verificar_mesas_livre(restaurante);

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
            // OK
            f = fila_mesa_encontrada(f);

            if (f == NULL)
                pessoas_fim = 0;
            else
                pessoas_fim = f->pessoas;
        }

        mesa_atual = mesa_atual->prox;
    }
    
    if (pessoas_inicio != pessoas_fim)
    {
        if (pessoas_fim != 0)
        {
            printf("Foi encontrado uma mesa para %d membros do seu grupo!!\n", pessoas_inicio - pessoas_fim);
            printf("Ainda ficaram %d na Fila de Espera!!\n", pessoas_fim);
            printf("SENHA:%d\n\n", f->senha);
        }
        else
        {
            printf("Foi encontrado uma(ou mais) mesa(s) para o seu grupo!!\n");
        }
    }
    if (mesa_livre == true && (pessoas_inicio == pessoas_fim))
    {
        printf("Foi encontrado uma(ou mais) mesa(s) para o seu grupo!!\n");
    }
    if (!mesa_livre)
    {
        Fila *p = f;
        while (p->prox != NULL)
        {
            p = p->prox;
            break;
        }
        printf("Seu grupo foi adicionado a fila!!\n");
        printf("SENHA:%d\n\n", p->senha);
    }

    return f;
}