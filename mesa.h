#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Sobre cada mesa, guardar o número da mesa e se está livre ou ocupada; se estiver ocupada, guardar a quantidade de
// pessoas sentadas e o número da comanda. Cada mesa possui uma comanda.
// Cada mesa possui uma comanda.
struct mesa{
    int numero_da_mesa;
    bool livre;
    int pessoas_sentadas;       
    int comanda;
    struct mesa *prox;
}; typedef struct mesa Mesa; 

Mesa* inicializa_mesas(int linhas, int colunas);


// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa) - o usuário pode pesquisar
// por número de mesa ou então consultar todas as mesas;

void listar_mesas(Mesa* restaurante);


void mesa_pesquisar();
// for (mesas)
// if numero_da_mesa == mesa_digitada
// Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa)







// verif_tamanho_do_grupo_na_mesa(Pilha* pratos, int pessoas); MESAS
// Caso um grupo com menos de 4 pessoas ocupe uma certa mesa os pratos excedentes são retirados da mesa e recolocados na pilha de pratos.
// Se as pessoas da mesa forem < 4, retirar os pratos da mesa PRATOS
// adicionar os pratos na pilha novamente

//  Pilha de pratos (quantos pratos existem na pilha de pratos). PRATOS/





    // DETALHES
// Caso não existam mesas suficientes, deve ser formada uma fila de espera.  
// Grupos diferentes não compartilham mesas, mesmo que haja lugar vago em certa mesa (ex: se houver 2 grupos de 1 pessoa cada, estes 2 grupos ocuparão 2 mesas, e não compartilharão uma única mesa de 4 lugares). 

bool verificar_mesas_livre(Mesa* restaurante);