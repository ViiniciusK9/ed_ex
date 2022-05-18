// Fila encadeada

typedef int TipoItem;


struct No
{
    TipoItem valor;
    No* proximo;
};



class fila_encadeada
{
private:
    No* primeiro;
    No* ultimo;
public:
    fila_encadeada(); // construtor
    ~fila_encadeada(); // destrutor
    bool esta_cheio(); // verifica se a fila esta cheia
    bool esta_vazio(); // verifica se a fila esta vazia
    void inserir(TipoItem item); // insere um novo elemento na fila
    TipoItem remover(); // remove o primeiro elemento da fila
    void imprimir(); // imprime os elementos da fila
};

