# include <iostream>
# include "hash.h"


using namespace std;


int main(){
    int max, tam_vetor, ra, opcao;
    string nome;
    bool busca;

    cout << "Programa gerador de Hash!\n";
    cout << "Digite o tamanho da Hash: ";
    cin >> tam_vetor;
    cout << "Digite o numero maximo de elementos: ";
    cin >> max;
    cout << "O fator de carga é: " << ((float)max / (float)tam_vetor) << '\n';

    Hash alunohash(tam_vetor, max);

    do
    {
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para buscar um elemento!\n";
        cout << "Digite 4 para imprimir a Hash!\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 0:
            /* code */
            break;
        case 1:
        {
            cout << "Digite o RA do aluno: ";
            cin >> ra;
            cout << "Digite o nome do aluno: ";
            cin >> nome;
            Aluno alunoAux(ra, nome);
            alunohash.inserir(alunoAux);
            break;
        }
        case 2:
        {
            cout << "Digite o RA do aluno a ser removido: ";
            cin >> ra;
            Aluno alunoAux(ra, " ");
            alunohash.remover(alunoAux);
            break;
        }
        case 3:
        {
            cout << "Digite o RA do aluno a ser buscado: ";
            cin >> ra;
            Aluno alunoAux(ra, " ");
            alunohash.buscar(alunoAux, busca);

            if (busca){
                cout << "Aluno encontrado!\n";
                cout << "Ra: " << alunoAux.obter_ra() << "\nNome: " << alunoAux.obter_nome() << '\n';
            } else {
                cout << "Aluno nao encontrado!\n";
            }

            break;
        }
        case 4:
            alunohash.imprimir();
            break;
        
        default:
        cout << "Opção invalida!\n";
            break;
        }


    } while (opcao != 0);
    
}