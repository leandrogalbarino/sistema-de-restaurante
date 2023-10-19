#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Sobre cada mesa, guardar o número da mesa e se está livre ou ocupada; se estiver ocupada, guardar a quantidade de
// pessoas sentadas e o número da comanda. Cada mesa possui uma comanda.
struct mesa{
    int numero_da_mesa;
    bool livre;
    int comanda;
    struct mesa *prox;
}; typedef struct mesa *Mesa; 
// Cada mesa possui uma comanda.

// Crie um sistema para gerenciamento de um restaurante que satisfaça aos seguintes requisitos:
// 1. O restaurante possui n mesas de 4 lugares. Estas mesas são organizadas seguindo uma forma de matriz (linhas e colunas),
// e o usuário informa como é esta distribuição (por exemplo, observe a figura abaixo: há 15 mesas, e elas estão distribuídas
// em uma matriz de tamanho 3x5). 

// 1. Implemente as mesas como uma matriz de structs. Usuário informa número de linhas e de
// colunas, e consequentemente já se sabe quantas mesas o restaurante possui.
// Exemplo de distribuição de mesas:

// quantas_meses_o_restaurante_possui();
// linhas * colunas;
Mesa inicializa_mesas(int linhas, int colunas){
    Mesa restaurante = NULL;
    int i,j;

    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            Mesa nova_mesa = (Mesa*)malloc(sizeof(Mesa));

            if(nova_mesa != NULL){
                nova_mesa->numero_da_mesa = i * colunas + j + 1; //calcula número único para cada mesa criada
                nova_mesa->livre = true;
                nova_mesa->comanda = 0;

                nova_mesa->prox = restaurante;
                restaurante = nova_mesa;
            }
        }
    }

    return restaurante;
}

// Quando chega um grupo de pessoas ao restaurante, é informado o número de pessoas e é atribuída uma mesa para tal
// grupo. Caso o grupo seja formado por mais de 4 pessoas, então eles são divididos em diversos subgrupos, mas não há
// garantia de que sentarão em mesas adjacentes.



// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa) - o usuário pode pesquisar
// por número de mesa ou então consultar todas as mesas;

// for (mesas)
// if numero_da_mesa == mesa_digitada
// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa)



struct pilha{ 
    struct pilha *prox;
}; typedef struct pilha Pilha;
// implementar funcoes de pilha;

struct fila{
    int senha_grupo;
    struct fila *ant;
    struct fila *prox;
}; typedef struct fila Fila;
// PESSOA 1 - CRIA UM NO - SENHA DO GRUPO
// PESSOA 2 - CRIA UM NO - SENHA DO GRUPO
// PESSOA 3 - CRIA UM NO - SENHA DO GRUPO
// PESSOA 4 - CRIA UM NO - SENHA DO GRUPO
// PESSOA 5 - CRIA UM NO - SENHA DO GRUPO


// senha unica
// O grupo que aguarda na fila recebe uma senha
// Pode haver grupos grandes, e neste caso, assim que liberar uma mesa, alguns membros do grupo podem conseguir a
// mesa e outros ainda ficarem na fila (em razão do tamanho da mesa). 
//  senha é útilizada para colocar membros de um determinado grupo em uma mesa;
 
    // DETALHES
// Caso não existam mesas suficientes, deve ser formada uma fila de espera.  
// Grupos diferentes não compartilham mesas, mesmo que haja lugar vago em certa mesa (ex: se houver 2 grupos de 1 pessoa cada, estes 2 grupos ocuparão 2 mesas, e não compartilharão uma única mesa de 4 lugares). 

// pratos. Um funcionário repõe pratos na pilha de tempos
// em tempos (não sendo necessário que a pilha esteja vazia para que novos pratos sejam adicionados).


// Caso um grupo com menos de 4 pessoas ocupe uma certa mesa, os pratos excedentes são retirados da mesa e recolocados na pilha de pratos. Um funcionário repõe pratos na pilha de tempos em tempos (não sendo necessário que a pilha esteja vazia para que novos pratos sejam adicionados).

// pratos limpos do restaurante
// PILHA DE PRATOS,

bool vefica_pratos_limpos(Pilha* pratos);
// retirar um prato limpo da pilha, e coloca quatro pratos em uma mesa!!!
// sempre que uma mesa estiver vazia (ainda não ocupada ou recentemente liberada), um funcionário arruma a mesa (coloca pratos que são retirados da pilha).


adicionar_prato_limpo(Pilha* pratos);
// adiciona prato limpo

Mesa* mesa_liberar();
// Clientes podem finalizar a refeição e sair do restaurante, liberando as mesas; com isso, os clientes que por ventura
// aguardam na fila podem sentar-se (saindo da fila de espera).


bool verificar_mesas_livre();
// Se houver mesas livres retorna TRUE, assim o proximo da fila entra, se não tiver fila, o proximo que entrar já é colocado em uma mesa;

Pilha* arruma_mesa(Pilha* pratos);
// Como as mesas possuem 4 lugares, sempre são colocados 4 pratos.

// verif_tamanho_do_grupo_na_mesa(Pilha* pratos, int pessoas);
// Caso um grupo com menos de 4 pessoas ocupe uma certa mesa os pratos excedentes são retirados da mesa e recolocados na pilha de pratos.
// Se as pessoas da mesa forem < 4, retirar os pratos da mesa
// adicionar os pratos na pilha novamente

//  Pilha de pratos (quantos pratos existem na pilha de pratos).

// Fila* sair_da_fila();
// Grupos podem desistir de esperar por uma mesa e com isso liberar suas senhas de espera (sair da fila de espera).