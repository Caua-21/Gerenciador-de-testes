#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//camada de apresentacao

class IServicoAutenticacao;
class IServicoDesenvolvedor;
class IServicoTeste;

class IApresentacaoAutenticacao{
public:
    virtual bool autenticar(Matricula*)=0;
    virtual void setcontroleservicoautenticacao(IServicoAutenticacao*)=0;
    virtual ~IApresentacaoAutenticacao(){}

};

class IApresentacaoDesenvolvedor{
public:
    virtual void cadastrar()=0;
    virtual bool executar(Matricula*)=0;
    virtual void setcontroleservicodesenvolvedor(IServicoDesenvolvedor*)=0;
    virtual void setcontroleservicoteste(IServicoTeste*)=0;
    virtual ~IApresentacaoDesenvolvedor(){}

};

class IApresentacaoTeste{
public:
    virtual void executar(Matricula*) = 0;
    virtual void setcontroleservicoteste(IServicoTeste*) = 0;
    virtual ~IApresentacaoTeste(){}

};

//camada de servicos

class IServicoTeste{
public:
    virtual bool cadastrarTeste(Matricula,Teste)=0;
    virtual bool descadastrarTeste(Codigo)=0;
    virtual bool editar(Teste)=0;
    virtual bool visualizarTeste(Teste*)=0;

    virtual bool cadastrarCasoTeste(Codigo, Casodeteste)=0;
    virtual bool descadastrarCasoTeste(Codigo)=0;
    virtual bool editar(Casodeteste)=0;
    virtual bool visualizarCasoTeste(Casodeteste*)=0;

    virtual ~IServicoTeste(){}

};

class IServicoDesenvolvedor{
public:
    virtual bool cadastrarDesenvolvedor(Desenvolvedor)=0;
    virtual bool visualizar(Matricula,Desenvolvedor*)=0;
    virtual bool descadastrar(Matricula)=0;
    virtual bool editar(Desenvolvedor)=0;
    virtual ~IServicoDesenvolvedor(){}

};

class IServicoAutenticacao{
public:
    virtual bool autenticar(Matricula, Senha)=0;
    virtual ~IServicoAutenticacao(){}

};

#endif // INTERFACES_H_INCLUDED
