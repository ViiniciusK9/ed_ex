# include "aluno.h"

using namespace std;


class Hash
{
private:
    int funcao_hash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Aluno* estrutura;

public:
    Hash(int tam_vetor, int max);
    Hash();
    ~Hash();
    bool esta_cheio();
    int obter_tamanho();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();
};