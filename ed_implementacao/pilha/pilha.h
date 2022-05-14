
typedef int TipoItem;
const int max_itens = 100;

class pilha
{
private:
    int tamanho;
    TipoItem* estrutura;

public:
    pilha(); // contrutora
    ~pilha(); // destrutora
    bool estacheia(); // verifica se a pilha esta cheia
    bool estavazia(); // verifica se a pilha esta vazia
    void inserir(TipoItem item); // inserir um elemento
    TipoItem remover(); // remover um elemento
    void imprimir(); // imprimir os elementos da estrutura
    int qualtamanho(); // retorna o a quantidade de elementos da estrutura
    

};


