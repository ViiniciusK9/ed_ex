// Pilha dinamica utilizando encadeamento

typedef int TipoItem;


struct No
{
    TipoItem valor;
    No* proximo;
};


class pilha_encadeada
{
private:
    No* NoTopo;
public:
    pilha_encadeada(); // construtor
    ~pilha_encadeada(); // destrutor
    bool esta_cheio(); // verificar se a pilha esta cheia
    bool esta_vazio(); // verificar se a pilha esta vazia
    void inserir(TipoItem item); // inserir um novo elemento no topo da pilha
    TipoItem remover(); // remover um elemento do topo da pilha
    void imprimir(); // imprimir na tela todos os elementos que estao na pilha
    int qual_tamanho(); // retorna o tamanho da pilha
};
