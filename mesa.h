// Sobre cada mesa, guardar o número da mesa e se está livre ou ocupada; se estiver ocupada, guardar a quantidade de
// pessoas sentadas e o número da comanda. Cada mesa possui uma comanda.
struct mesa{
    int numero_da_mesa;
    bool livre;
    int comanda;
    struct mesa *prox;
}; typedef struct mesa *Mesa; 
// Cada mesa possui uma comanda.

Mesa inicializa_mesas(int linhas, int colunas);