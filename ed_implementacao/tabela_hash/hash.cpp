# include <iostream>
# include "hash.h"


using namespace std;

    int Hash::funcao_hash(Aluno aluno)
    {
        return (aluno.obter_ra() % max_posicoes);
    }

    Hash::Hash(int tam_vetor, int max)
    {
        quant_itens = 0;
        max_posicoes = tam_vetor;
        max_itens = max;
        estrutura = new Aluno[tam_vetor];
    }

    Hash::~Hash()
    {
        delete [] estrutura;
    }

    bool Hash::esta_cheio()
    {
        return (quant_itens == max_itens);
    }

    int Hash::obter_tamanho()
    {
        return quant_itens;
    }

    void Hash::inserir(Aluno aluno)
    {
        int local = funcao_hash(aluno);
        estrutura[local] = aluno;
        quant_itens++;
    }

    void Hash::remover(Aluno aluno)
    {
        int local = funcao_hash(aluno);
        if(estrutura[local].obter_ra() != -1){
            estrutura[local] = Aluno(-1, " ");
            quant_itens--;
        }
    }

    void Hash::buscar(Aluno& aluno, bool& busca)
    {
        int local = funcao_hash(aluno);
        Aluno aux = estrutura[local];
        if(aluno.obter_ra() != aux.obter_ra()){
            busca = false;
        } else{
            busca = true;
            aluno = aux;
        }
    }

    void Hash::imprimir()
    {
        cout << "Tabela hash:\n";
        int i;
        for(i = 0; i < max_posicoes; i++){
            if(estrutura[i].obter_ra() != -1){
                cout << i << " : " << estrutura[i].obter_ra() << " " << estrutura->obter_nome() << '\n';
            }
        }
    }
