// fila
typedef int TipoItem;
const int max_itens = 100;

class fila
{
private:
    int primeiro, ultimo;
    TipoItem* estrutura;

public:
    fila(); // construtor
    ~fila(); // destrutor
    bool estavazio(); // verifica se a estrutura esta vazia
    bool estacheio(); // verifica se a estrutura esta cheia
    void inserir(TipoItem item); // insere um elemento na estrutura
    TipoItem remover(); // remove um elemento da estrutura
    void imprimir(); // imprime todos os elementos da estrutura
};


