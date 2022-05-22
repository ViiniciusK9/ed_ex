#include <iostream>
#include <cstddef>
#include "arvore_binaria.h"

    
using namespace std;

    ArvoreBinaria::ArvoreBinaria()
    {
        raiz = NULL;
    }

    ArvoreBinaria::~ArvoreBinaria()
    {

    }

    void ArvoreBinaria::deletarArvore(No* Noatual)
    {

    }

    No* ArvoreBinaria::obterRaiz()
    {
        return raiz;
    }

    bool ArvoreBinaria::estavazio()
    {
        return (raiz == NULL);
    }
    bool ArvoreBinaria::estacheio()
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

    void ArvoreBinaria::inserir(Aluno aluno)
    {
        if(estacheio()){
            cout << "A arvore esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NovoNo = new No;
            NovoNo->aluno = aluno;
            NovoNo->filhodireita = NULL;
            NovoNo->filhoesquerda = NULL;
            if (raiz == NULL){
                raiz = NovoNo;
            } else{
                No* temp = raiz;
                while (temp != NULL){
                    if (aluno.obterRa() < temp->aluno.obterRa()){
                        if (temp->filhoesquerda == NULL){
                            temp->filhoesquerda = NovoNo;
                            break;
                        } else{
                            temp = temp->filhoesquerda;
                        }
                    } else{
                        if (temp->filhodireita == NULL){
                            temp->filhodireita = NovoNo;
                            break;
                        } else{
                            temp = temp->filhodireita;
                        }
                    }
                }
            }
        }
    }

    void ArvoreBinaria::remover(Aluno aluno)
    {
        removerbusca(aluno, raiz);
    }

    void ArvoreBinaria::removerbusca(Aluno aluno, No*& noatual)
    {
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhoesquerda);
        } else if (aluno.obterRa() > noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhodireita);
        } else {
            deletarNo(noatual);
        }
    }

    void ArvoreBinaria::deletarNo(No*& noatual)
    {
        No* temp = noatual;
        if (noatual->filhoesquerda == NULL){
            noatual = noatual->filhodireita;
            delete temp;
        } else if (noatual->filhodireita == NULL){
            noatual = noatual->filhoesquerda;
            delete temp;
        } else {
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor, noatual);
            noatual->aluno = AlunoSucessor;
            removerbusca(AlunoSucessor, noatual->filhodireita);
        }
    }

    void ArvoreBinaria::obterSucessor(Aluno& AlunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        AlunoSucessor = temp->aluno;
    }

    void ArvoreBinaria::buscar(Aluno& aluno, bool& busca)
    {
        busca = false;
        No* noatual = raiz;
        while(noatual != NULL){
            if (aluno.obterRa() < noatual->aluno.obterRa()){
                noatual = noatual->filhoesquerda;
            } else if(aluno.obterRa() > noatual->aluno.obterRa()){
                noatual = noatual->filhodireita;
            } else{
                busca = true;
                aluno = noatual->aluno;
                break;
            }
        }
    }

    void ArvoreBinaria::imprimirpreordem(No* Noatual)
    {

    }

    void ArvoreBinaria::imprimiremordem(No* Noatual)
    {

    }

    void ArvoreBinaria::imprimirposordem(No* Noatual)
    {

    }
