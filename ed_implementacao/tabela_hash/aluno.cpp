# include "aluno.h"



    Aluno::Aluno()
    {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int r, string n)
    {
        ra = r;
        nome = n;
    }

    int Aluno::obter_ra()
    {
        return ra;
    }

    string Aluno::obter_nome()
    {
        return nome;
    }
