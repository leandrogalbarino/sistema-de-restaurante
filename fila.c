#include "filas.h"
#include <stdio.h>
#include <stdlib.h>

struct fila {
  int senha_grupo;
  int pessoas;
  struct fila *prox;
};
typedef struct fila Fila;

// senha unica
// O grupo que aguarda na fila recebe uma senha
int fila_gerar_senha();

int fila_atualiza_pessoas_grupo() {}
// Pode haver grupos grandes, e neste caso, assim que liberar uma mesa, alguns
// membros do grupo podem conseguir a mesa e outros ainda ficarem na fila (em
// razão do tamanho da mesa).

// IMPORTANTEEEE!!!!!
//  senha é útilizada para colocar membros de um determinado grupo em uma mesa;

Fila *fila_criar() { return NULL; }

Fila *fila_inserir(Fila *l, int senha) {
  Fila *novo = (Fila *)malloc(sizeof(Fila));
  novo->prox = NULL;
  novo->senha_grupo = senha;
  if (l == NULL)
    return novo;
  Fila *p;
  while (p->prox != NULL) {
    p = p->prox;
  }
  p->prox = novo;
  return l;
}

Fila *fila_adicionar_grupo(Fila *l, int tamanho) {
  Fila *f = l;
  int senha;
  senha = fila_gerar_senha();
  for (int i = 0; i < tamanho; i++) {
    f = fila_inserir(l, senha)
  }
  return f;
}

Fila *fila_abandonar(Fila *l, Fila *grupo, int senha) {
  Fila *ant = l;
  Fila *novo;

  while (ant->prox != grupo) {
    ant = ant->prox;
  }
  if (ant == NULL) {
    novo = l->prox;
    free(l);
    return novo;
  }
  Fila *p;

  for (p = grupo; p != NULL; p = p->prox) {
    if (p->senha != grupo->senha) {
      ant->prox = p;
      break;
    } else {
      ant->prox = p->prox;
      free(p);
    }
  }
  return l;
}

Fila *fila_procurar(Fila *l, int senha) {
  Fila *p;
  for (p = l; p != NULL; p = p->prox) {
    if (p->senha == senha) {
      return p;
    }
  }
  return NULL;
}

void fila_sair(Fila *l) {
  if (l == NULL) {
    printf("Nao existem grupos na fila!!\n") return;
  }
  int senha;
  fila *grupo;
  printf("Por favor! Digite a senha do grupo:");
  scanf("%d", &senha) grupo = fila_procurar(l, senha);

  if (grupo != NULL) {
    printf("Seu grupo foi retirado da fila!!\n Nosso restaurante sempre te "
           "espera.\n") l = fila_abandonar(l, grupo, senha);
  } else {
    printf("Seu grupo nao foi encontrado na fila!!\n")
  }
  return l;
}
// Grupos podem desistir de esperar por uma mesa e com isso liberar suas senhas
// de espera (sair da fila de espera).
