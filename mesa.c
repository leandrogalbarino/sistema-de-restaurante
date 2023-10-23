#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"
#include "pratos.h"

// Crie um sistema para gerenciamento de um restaurante que satisfaça aos seguintes requisitos:
// 1. O restaurante possui n mesas de 4 lugares. Estas mesas são organizadas seguindo uma forma de matriz (linhas e colunas),
// e o usuário informa como é esta distribuição (por exemplo, observe a figura abaixo: há 15 mesas, e elas estão distribuídas
// em uma matriz de tamanho 3x5).

// 1. Implemente as mesas como uma matriz de structs. Usuário informa número de linhas e de
// colunas, e consequentemente já se sabe quantas mesas o restaurante possui.
// Exemplo de distribuição de mesas:

// quantas_meses_o_restaurante_possui();
// linhas * colunas;
Mesa *inicializa_mesas(int linhas, int colunas)
{
    Mesa *restaurante = NULL;
    int i, j;

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            Mesa *nova_mesa = (Mesa *)malloc(sizeof(Mesa));

            if (nova_mesa != NULL)
            {
                nova_mesa->numero_da_mesa = i * colunas + j + 1; // calcula número único para cada mesa criada
                nova_mesa->livre = true;
                nova_mesa->comanda = i * colunas + j + 1; // uma comanda por mesa então é feito o mesmo calculo

                nova_mesa->prox = restaurante;
                restaurante = nova_mesa;
            }
        }
    }

    printf("Restaurante criado com tamanho %dx%d.\n", linhas, colunas);

    return restaurante;
}

Mesa *mesa_liberar()
{
}

// Clientes podem finalizar a refeição e sair do restaurante, liberando as mesas; com isso, os clientes que por ventura
// aguardam na fila podem sentar-se (saindo da fila de espera).

bool verificar_mesas_livre(Mesa *restaurante)
{
    Mesa *mesa_atual = restaurante;

    while (mesa_atual != NULL)
    { // percore todas as mesas do restaurante
        if (mesa_atual->livre == true)
        {
            return true;
        }
        mesa_atual = mesa_atual->prox;
    }

    return false;
}
// Se houver mesas livres retorna TRUE, assim o proximo da fila entra, se não tiver fila, o proximo que entrar já é colocado em uma mesa;

// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa) - o usuário pode pesquisar
// por número de mesa ou então consultar todas as mesas;
// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa)

// lista todas as mesas
void listar_mesas(Mesa *restaurante)
{
    Mesa *mesas = restaurante;

    printf("\tMesas:\n");

    while (mesas != NULL)
    { // percore todas as mesas do restaurante e imprime elas
        printf("Número da Mesa: %d\n", mesas->numero_da_mesa);
        printf("Pessoas sentadas: %d\n", mesas->pessoas_sentadas);
        printf("\n");
        mesas = mesas->prox;
    }
}

void mesa_pesquisar(Mesa *restaurante)
{
    int pesquisa;
    char tecla;
    Mesa *mesa_atual = restaurante;

    do
    {
        printf("Digite o numero da mesa para consulta: ");
        scanf("%d", &pesquisa);

        if (mesa_atual->numero_da_mesa == pesquisa)
        {
            printf("Mesa encontrada.\n", mesa_atual->numero_da_mesa);
            printf("Numero da mesa: %d.\n", mesa_atual->numero_da_mesa);
            printf("Pessoas sentadas: %d.\n", mesa_atual->pessoas_sentadas);
        }
        else
        {
            printf("Não foi encontrado a mesa pesquisada.\n");
        }

        printf("Deseja consultar novamente? (s/n): ");
        scanf(" %c", &tecla);

    } while (mesa_atual != NULL && tecla == 's');
}
