#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include <string>
#include "dominios.h"
#include "interfaces.h"

using namespace std;

class StubServicoAutenticacao:public IServicoAutenticacao {
    public:
        bool autenticar(Matricula, Senha);
};


class StubServicoDesenvolvedor:public IServicoDesenvolvedor {
    public:
        bool cadastrarDesenvolvedor(Desenvolvedor);
        bool visualizar(Desenvolvedor*);
        bool descadastrar(Matricula);
        bool editar(Desenvolvedor);
};

class StubServicoTeste:public IServicoTeste{
public:
    bool cadastrarTeste(Matricula,Teste);
    bool descadastrarTeste(Matricula, Codigo);
    bool editar(Teste);
    bool visualizarTeste(Teste*);

    bool cadastrarCasoTeste(Casodeteste);
    bool descadastrarCasoTeste(Codigo);
    bool editar(Casodeteste);
    bool visualizarCasoTeste(Casodeteste*);
};

#endif // STUBS_H_INCLUDED
