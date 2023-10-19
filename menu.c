#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void esperar_enter()
{
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar(); // Aguarda o Enter ser pressionado
}

void menu_opcoes(int escolha)
{

    switch(escolha)
    {
        case 1:
            //se há disponibilidade na mesa então adicionar grupo
            //senão ir para fila de espera
            break;
        case 2:
            //finalizar refeicao/liberar mesa(liberar a mesa, chamar clientes da fila de espera (se houver), e arrumar mesa)
            break;
        case 3:
            //Desistir de esperar (sair da fila de espera)
            break;
        case 4:
            //Arrumar mesa (retirar pratos da pilha)
            break;
        case 5:
            //Repor pratos (adicionar pratos na pilha)
            break;
        case 6:
            //Imprimir pilha de pratos, fila de espera e ocupação das mesas,
            break;
        default:
            break;
    }
    esperar_enter();
}

void menu()
{
    char sair;
    int escolha;
    do
    {
        printf("\tMENU\n");

        printf("1. Chegada de Cliente\n");
        printf("2. Liberar Mesa\n");
        printf("3. Desistir de Esperar\n");
        printf("4. Arrumar Mesa\n");
        printf("5. Repor pratos\n");
        printf("6. Imprimir Pilha, Fila de espera e Ocupacao de mesa\n");

        printf("7. Sair\n");

        do
        {
            printf("DIGITE O NUMERO DO QUE DESEJA REALIZAR:");
            scanf("%d", &escolha);
            if (escolha < 1 || escolha > 7)
            {
                printf("POR FAVOR DIGITE UM NUMERO VALIDO!\n");
            }
            printf("\n");
        } while (escolha < 1 || escolha > 7);

        menu_opcoes(escolha);

    } while (escolha != 7);
}

