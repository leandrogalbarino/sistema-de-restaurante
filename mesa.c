#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"

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
                nova_mesa->comanda = i * colunas + j + 1; //uma comanda por mesa então é feito o mesmo calculo

                nova_mesa->prox = restaurante;
                restaurante = nova_mesa;
            }
        }
    }

    printf("Restaurante criado com tamanho %dx%d.\n", linhas,colunas);

    return restaurante;
}