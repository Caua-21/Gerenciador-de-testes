#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED
#include "interfaces.h"
#include "conteiners.h"
#include "dominios.h"
#include "entidades.h"
class CntrServicoDesenvolvedor:public IServicoDesenvolvedor{
public:
    bool cadastrarDesenvolvedor(Desenvolvedor);
    bool descadastrar(Matricula);
    bool editar(Desenvolvedor);
    bool visualizar(Matricula,Desenvolvedor *);

};

class CntrServicoAutenticacao:public IServicoAutenticacao{
public:
    bool autenticar(Matricula,Senha);
};

class CntrServicoTeste:public IServicoTeste{
public:
    bool cadastrarTeste(Matricula ,Teste);
    bool descadastrarTeste(Codigo);
    bool editar(Teste);
    bool visualizarTeste(Teste*);

    bool cadastrarCasoTeste(Codigo, Casodeteste);
    bool descadastrarCasoTeste(Codigo);
    bool editar(Casodeteste);
    bool visualizarCasoTeste(Casodeteste*);

};

#endif // CONTROLADORASSERVICO_H_INCLUDED
