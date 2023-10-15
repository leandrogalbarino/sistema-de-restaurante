
void menu_opcoes();

void menu(){
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
        menu_opcoes();

    } while (escolha != 7);
}
// 1) Chegar (grupo de) clientes ao restaurante (implica em ocupar mesa se há disponibilidade ou ir pra fila de espera)
// 2) Finalizar refeição/liberar mesa (liberar a mesa, chamar clientes da fila de espera (se houver), e arrumar mesa)
// 3) Desistir de esperar (sair da fila de espera)
// 4) Arrumar mesa (retirar pratos da pilha)
// 5) Repor pratos (adicionar pratos na pilha)
// 6) Imprimir pilha de pratos, fila de espera e ocupação das mesas, conforme descrito a seguir: 

    
}
