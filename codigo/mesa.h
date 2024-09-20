#ifndef MESA_H
#define MESA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct mesa{
    int numero_da_mesa;
    bool livre;
    int pessoas_sentadas;    
    int pratos;   
    int comanda;
    struct mesa *prox;
}; typedef struct mesa Mesa; 

Mesa *inicializa_mesas();

Mesa *mesa_liberar(Mesa *restaurante);

int mesa_gerar_comanda();

void mesa_listar(Mesa *restaurante);

char *mesa_disponibidade(Mesa *mesa);

Mesa *mesa_a_arrumar(Mesa *mesa);

void mesa_pesquisar(Mesa *restaurante);

#endif