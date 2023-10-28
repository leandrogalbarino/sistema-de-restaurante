#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"
#include "fila.h"
#include "pratos.h"

Mesa *inicializa_mesas()
{
    Mesa *restaurante = NULL;
    int i, j, linhas, colunas;

    printf("Informe a dimensao das linhas da mesa: ");
    scanf("%d", &linhas);
    printf("Informe a dimensao das colunas da mesa: ");
    scanf("%d", &colunas);

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            Mesa *nova_mesa = (Mesa *)malloc(sizeof(Mesa));

            if (nova_mesa != NULL)
            {
                nova_mesa->numero_da_mesa = i * colunas + j + 1; // calcula número único para cada mesa criada
                nova_mesa->livre = true;
                nova_mesa->pessoas_sentadas = 0;
                nova_mesa->comanda = 0;
                
                nova_mesa->pratos = 4;

                nova_mesa->prox = restaurante;
                restaurante = nova_mesa;
            }
        }
    }

    printf("Restaurante criado com tamanho %dx%d.\n", linhas, colunas);

    return restaurante;
}

// Clientes podem finalizar a refeição e sair do restaurante, liberando as mesas; com isso, os clientes que por ventura
// aguardam na fila podem sentar-se (saindo da fila de espera).
Mesa *mesa_liberar(Mesa *restaurante)
{
    int mesa;
    Mesa *mesa_atual = restaurante;

    printf("Digite o numero da sua mesa para liberar: ");
    scanf("%d", &mesa);

    while (mesa_atual != NULL)
    {
        // Assim funciona, antes, podia mesa_atual fica == NULL e te achado a mesa, porque o ultimo no ia pro proximo;
        if (mesa_atual->numero_da_mesa == mesa)
        {
            break;
        }
        mesa_atual = mesa_atual->prox;
    }

    if (mesa_atual == NULL)
    {
        printf("Não foi encontrado a sua mesa para liberar.\n");
    }
    // PODE TIRAR O ELSE IF, EU ACHO! ass leandro
    else if (mesa_atual->numero_da_mesa == mesa)
    {
        mesa_atual->livre = true;
        mesa_atual->pessoas_sentadas = 0;
        mesa_atual->pratos = 0;

        return mesa_atual;
    }

    // se não achar volta a mesa sem alteração
    return restaurante;
}

int mesa_gerar_comanda(){
    static int comanda = 1;

    return comanda++;
}

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

// lista todas as mesas

// PODE COLOCAR QUE NAO EXISTEM MESA, SE O RESTAURANTE NAO POSSUIR MESAS
void mesa_listar(Mesa *restaurante)
{
    Mesa *mesas = restaurante;

    printf("\tMesas:\n");
    if (restaurante == NULL)
    {
        printf("Nao existem mesas no restaurante!\n");
        return;
    }

    while (mesas != NULL)
    { // percore todas as mesas do restaurante e imprime elas
        printf("Número da Mesa: %d\n", mesas->numero_da_mesa);
        printf("Pessoas sentadas: %d\n", mesas->pessoas_sentadas);
        printf("\n");
        mesas = mesas->prox;
    }
}

//  ADICIONEI ESSA FUNCAO PARA PRINTAR: DISPONIVEL OU INDISPONIVEL
char *mesa_disponibidade(Mesa *mesa)
{
    if (mesa->livre)
    {
        return "Disponivel";
    }
    return "Indisponivel";
}

Mesa *mesa_a_arrumar(Mesa *mesa)
{
    int numero_mesa;
    printf("Digite o numero da mesa que deseja arrumar!!\n");
    if (mesa == NULL)
    {
        printf("Nao existem mesas no restaurante!!\n");
        return NULL;
    }
    Mesa *m;
    for (m = mesa; m != NULL; m = m->prox)
    {
        if (numero_mesa == m->numero_da_mesa)
        {
            if (m->livre)
            {
                if (m->pratos == 4)
                {
                    printf("A mesa ja esta arrumada!!\n");
                    return NULL;
                }
                break;
            }
            else
            {
                printf("A mesa esta sendo ocupada no momento!!\n");
                printf("Nao foi possivel arruma-la!\n");
                return NULL;
            }
        }
    }
    if (m == NULL)
    {
        printf("Nao foi encontrada a mesa com numero %d!!\n", numero_mesa);
    }
    return m;
}

void mesa_pesquisar(Mesa *restaurante)
{
    int pesquisa;
    char tecla;
    if (restaurante == NULL)
    {
        printf("Nao existem mesas no restaurante!!\n");
        return;
    }
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

            printf("Disponibilidade:%s", mesa_disponibidade(mesa_atual));
        }
        else
        {
            printf("Não foi encontrado a mesa pesquisada.\n");
        }

        printf("Deseja consultar novamente? (s/n): ");
        scanf(" %c", &tecla);

    } while (tecla == 's');
}


Mesa* chegar_grupo(Mesa* restaurante, Fila* fila){
    int tamanho;
    int senha = fila_gerar_senha(fila);
    Mesa* mesa_atual = restaurante;
    bool mesa_livre = verificar_mesas_livre(restaurante);

    printf("Quantas pessoas estao no grupo? ");
    scanf("%d", &tamanho);

    Fila* grupo = (Fila*)malloc(sizeof(Fila));
    grupo->pessoas = tamanho;
    grupo->senha = senha;

    while(grupo->pessoas > 0 && mesa_atual != NULL){
        if(mesa_atual->livre){
            if(grupo->pessoas <= 4){
                mesa_atual->livre = false;
                mesa_atual->pessoas_sentadas = grupo->pessoas;
                mesa_atual->comanda = mesa_gerar_comanda();
                grupo->pessoas = 0;
            } else {
                mesa_atual->livre = false;
                mesa_atual->pessoas_sentadas = 4;
                mesa_atual->comanda = mesa_gerar_comanda();
                grupo->pessoas -= 4;
            }
        }
        mesa_atual = mesa_atual->prox;
    }

    if(grupo->pessoas > 0){
        fila = fila_inserir(fila, senha);
        printf("Seu grupo foi adicionado a fila de espera com a senha %d.\n", senha);
    }

    return restaurante;
}
