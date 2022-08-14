#include <iostream>
#include <cstddef>
#include "arvoreAVL.h"

    
using namespace std;

    ArvoreAVL::ArvoreAVL()
    {
        raiz = NULL;
    }

    ArvoreAVL::~ArvoreAVL()
    {
        deletarArvore(raiz);
    }

    void ArvoreAVL::deletarArvore(No* noAtual)
    {
        if(noAtual != NULL){
            deletarArvore(noAtual->filhoesquerda);
            deletarArvore(noAtual->filhodireita);

            delete noAtual;
        }
    }

    No* ArvoreAVL::getRaiz()
    {
        return raiz;
    }

    bool ArvoreAVL::estaVazio()
    {
        return (raiz == NULL);
    }
    bool ArvoreAVL::estaCheio()
    {
        try
        {
            No* temp = new No;
            delete temp;
            return false;
        }
        catch(bad_alloc exception)
        {
            return true;
        }
        
    }

    void ArvoreAVL::inserir(Aluno aluno)
    {
        bool cresceu;
        insereRecursivo(raiz, aluno, cresceu);
    }

    void ArvoreAVL::insereRecursivo(No*& noAtual, Aluno aluno, bool& cresceu)
    {
        if(noAtual == NULL){
            noAtual = new No;
            noAtual->filhodireita = NULL;
            noAtual->filhoesquerda = NULL;
            noAtual->aluno = aluno;
            noAtual->fatorB = 0;
            cresceu = true;
            return;
        }
        if (aluno.getRa() < noAtual->aluno.getRa()) {
            insereRecursivo(noAtual->filhoesquerda, aluno, cresceu);
            if (cresceu) {
                noAtual->fatorB -= 1;
            }
        } else {
            insereRecursivo(noAtual->filhodireita, aluno, cresceu);
            if (cresceu) {
                noAtual->fatorB += 1;
            }
        }
        
        realizarRotacao(noAtual);

        if (cresceu && noAtual->fatorB == 0) {
            cresceu = false;
        }
    }

    void ArvoreAVL::remover(Aluno aluno)
    {
        bool diminuiu;
        removerBusca(aluno, raiz, diminuiu);
    }

    void ArvoreAVL::removerBusca(Aluno aluno, No*& noAtual, bool& diminuiu)
    {
        if (aluno.getRa() < noAtual->aluno.getRa()){
            removerBusca(aluno, noAtual->filhoesquerda, diminuiu);
            if (diminuiu) {
                noAtual->fatorB += 1;
            }
        } else if (aluno.getRa() > noAtual->aluno.getRa()){
            removerBusca(aluno, noAtual->filhodireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorB -= 1;
            }
        } else { 
            deletarNo(noAtual, diminuiu);
        }
        if (noAtual != NULL) {
            realizarRotacao(noAtual);
            if (diminuiu && noAtual->fatorB != 0) {
                diminuiu = false;
            }
        }
    }

    void ArvoreAVL::deletarNo(No*& noAtual, bool& diminuiu)
    {
        No* temp = noAtual;
        if (noAtual->filhoesquerda == NULL){
            noAtual = noAtual->filhodireita;
            diminuiu = true;
            delete temp;
        } else if (noAtual->filhodireita == NULL){
            noAtual = noAtual->filhoesquerda;
            diminuiu = true;
            delete temp;
        } else {
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor, noAtual);
            noAtual->aluno = AlunoSucessor;
            removerBusca(AlunoSucessor, noAtual->filhodireita, diminuiu);
            if (diminuiu) {
                noAtual->fatorB -= 1;
            }
        }
    }

    void ArvoreAVL::obterSucessor(Aluno& AlunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        AlunoSucessor = temp->aluno;
    }

    void ArvoreAVL::buscar(Aluno& aluno, bool& busca)
    {
        busca = false;
        No* noAtual = raiz;
        while(noAtual != NULL){
            if (aluno.getRa() < noAtual->aluno.getRa()){
                noAtual = noAtual->filhoesquerda;
            } else if(aluno.getRa() > noAtual->aluno.getRa()){
                noAtual = noAtual->filhodireita;
            } else{
                busca = true;
                aluno = noAtual->aluno;
                break;
            }
        }
    }

    void ArvoreAVL::imprimirPreOrdem(No* noAtual)
    {
        if(noAtual != NULL){
            cout << noAtual->aluno.getNome() << ": ";
            cout << noAtual->aluno.getRa() << '\n';

            imprimirPreOrdem(noAtual->filhoesquerda);
            imprimirPreOrdem(noAtual->filhodireita);
        }
    }

    void ArvoreAVL::imprimirEmOrdem(No* noAtual)
    {
        if(noAtual != NULL){
            imprimirEmOrdem(noAtual->filhoesquerda);

            cout << noAtual->aluno.getNome() << ": ";
            cout << noAtual->aluno.getRa() << '\n';
            
            imprimirEmOrdem(noAtual->filhodireita);
        }
    }

    void ArvoreAVL::imprimirPosOrdem(No* noAtual)
    {
        if(noAtual != NULL){
            imprimirPosOrdem(noAtual->filhoesquerda);
            imprimirPosOrdem(noAtual->filhodireita);

            cout << noAtual->aluno.getNome() << ": ";
            cout << noAtual->aluno.getRa() << '\n';
        }
    }

// Novos metodos 

    void ArvoreAVL::rotacaoDireita(No*& pai)
    {
        No* novopai = pai->filhoesquerda;
        pai->filhoesquerda = novopai->filhodireita;
        novopai->filhodireita = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoEsquerda(No*& pai)
    {
        No* novopai = pai->filhodireita;
        pai->filhodireita = novopai->filhoesquerda;
        novopai->filhoesquerda = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoEsquerdaDireita(No*& pai)
    {
        No* filho = pai->filhoesquerda;
        rotacaoEsquerda(filho);
        pai->filhoesquerda = filho;
        rotacaoDireita(pai);
    }

    void ArvoreAVL::rotacaoDireitaEsquerda(No*& pai)
    {
        No* filho = pai->filhodireita;
        rotacaoDireita(filho);
        pai->filhodireita = filho;
        rotacaoEsquerda(pai);
    }

    void ArvoreAVL::realizarRotacao(No*& pai)
    {
        No* filho;
        No* neto;

        if (pai->fatorB == -2) { // rotaciona para a direita

            filho = pai->filhoesquerda;

            if (filho->fatorB == -1) { // simples para a direita
                pai->fatorB = 0;
                filho->fatorB = 0;
                rotacaoDireita(pai);
            } else if (filho->fatorB == 0) { // simples para a direita
                pai->fatorB = -1;
                filho->fatorB = 1;
                rotacaoDireita(pai);
            } else if (filho->fatorB == 1) { // rotacao dupla
                neto = filho->filhodireita;
                if (neto->fatorB == -1) {
                    pai->fatorB = 1;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 0) {
                    pai->fatorB = 0;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 1) {
                    pai->fatorB = 0;
                    filho->fatorB = -1;
                }
                neto->fatorB = 0;
                rotacaoEsquerdaDireita(pai);
            }
        } else if (pai->fatorB == 2) { // rotaciona para a esquerda

            filho = pai->filhoesquerda;

            if (filho->fatorB == -1) { // simples para a esquerda
                pai->fatorB = 0;
                filho->fatorB = 0;
                rotacaoEsquerda(pai);
            } else if (filho->fatorB == 0) { // simples para a esquerda
                pai->fatorB = 1;
                filho->fatorB = -1;
                rotacaoEsquerda(pai);
            } else if (filho->fatorB == -1) { // rotacao dupla
                neto = filho->filhodireita;
                if (neto->fatorB == -1) {
                    pai->fatorB = 0;
                    filho->fatorB = 1;
                } else if (filho->fatorB == 0) {
                    pai->fatorB = 0;
                    filho->fatorB = 0;
                } else if (filho->fatorB == 1) {
                    pai->fatorB = 1;
                    filho->fatorB = 0;
                }
                neto->fatorB = 0;
                rotacaoDireitaEsquerda(pai);
            }
        }
    }