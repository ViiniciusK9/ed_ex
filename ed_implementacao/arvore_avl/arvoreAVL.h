#include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;

    int fatorB; 
};

class ArvoreAVL{
    private:
    No* raiz;

    public:
    ArvoreAVL();
    ~ArvoreAVL();
    void deletarArvore(No* noAtual);
    No* getRaiz();
    bool estaVazio();
    bool estaCheio();
    void inserir(Aluno aluno);
    void remover(Aluno aluno);
    void removerBusca(Aluno aluno, No*& noAtual, bool& diminuiu);
    void deletarNo(No*& noAtual, bool& busca);
    void obterSucessor(Aluno& alunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca);
    void imprimirPreOrdem(No* noAtual);
    void imprimirEmOrdem(No* noAtual);
    void imprimirPosOrdem(No* noAtual);

    void rotacaoDireita(No*& tree);
    void rotacaoEsquerda(No*& tree);
    void rotacaoEsquerdaDireita(No*& tree);
    void rotacaoDireitaEsquerda(No*& tree);
    void realizarRotacao(No*& tree);
    void insereRecursivo(No*& noAtual, Aluno aluno, bool& cresceu);
};