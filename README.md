# Sistema de Gestão de Restaurante

Este programa simula a gestão de um restaurante, com funcionalidades para gerenciar mesas, filas de espera e pilha de pratos. O objetivo é auxiliar na organização de grupos de clientes, mesas disponíveis e pratos prontos para serem usados.

## Funcionalidades

O sistema oferece as seguintes funcionalidades principais:

1. **Chegada de Cliente**: Adiciona um novo grupo de clientes à fila de espera.
2. **Liberar Mesa**: Libera uma mesa que estava ocupada, tornando-a disponível para novos clientes.
3. **Desistir de Esperar**: Remove um grupo de clientes da fila de espera.
4. **Arrumar Mesa**: Organiza uma mesa para um grupo de clientes na fila de espera e atualiza o status da mesa e dos pratos.
5. **Repor Pratos**: Reabastece a pilha de pratos.
6. **Imprimir Relatórios**: Exibe informações sobre mesas, fila de espera e pilha de pratos.

## Estruturas de Dados Utilizadas

O programa utiliza três principais estruturas de dados:

- **Mesas (`Mesa`)**: Representa as mesas do restaurante, cada uma com um estado de ocupação e quantidade de pratos.
- **Fila (`Fila`)**: Gerencia os grupos de clientes que estão esperando para serem atendidos.
- **Pilha (`Pilha`)**: Representa os pratos disponíveis no restaurante.

## Menu Principal

No menu principal, o usuário pode escolher entre as seguintes opções:

1. Chegada de Cliente
2. Liberar Mesa
3. Desistir de Esperar
4. Arrumar Mesa
5. Repor Pratos
6. Imprimir Relatórios
7. Sair

### Submenu de Relatórios

O submenu de relatórios permite ao usuário visualizar detalhes sobre o estado atual do restaurante, com as seguintes opções:

1. Pesquisar mesa.
2. Listar todas as mesas.
3. Listar número de grupos na fila.
4. Listar quantidade de pessoas na fila.
5. Listar quantidade de pratos.
6. Voltar ao menu principal.

## Fluxo do Programa

1. **Inicialização**: As mesas, fila de espera e pilha de pratos são inicializadas.
2. **Menu Principal**: O usuário escolhe uma das opções disponíveis para gerenciar o restaurante.
3. **Operações**: Dependendo da escolha, o sistema executa uma operação, como adicionar um grupo à fila, liberar uma mesa ou repor pratos.
4. **Relatórios**: Se escolhido, o programa exibe relatórios sobre o estado atual das mesas, fila e pratos.
5. **Sair**: O programa encerra quando o usuário escolhe a opção "Sair".

## Como Executar

1. Compile o programa utilizando um compilador C. Exemplo: `gcc -o restaurante main.c mesa.c fila.c pratos.c -I.`
2. Execute o programa gerado: `./restaurante`

## Dependências

- `mesa.h` e `mesa.c`: Gerenciamento das mesas do restaurante.
- `fila.h` e `fila.c`: Manipulação da fila de espera dos clientes.
- `pratos.h` e `pratos.c`: Controle da pilha de pratos disponíveis.

## Nota

Este código é uma simulação simples para fins educacionais e demonstra o uso de diferentes estruturas de dados (fila, pilha, lista encadeada) e suas operações em C.

