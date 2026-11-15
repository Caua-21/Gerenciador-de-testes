#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include <conio.h>
#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

#define CLR_SCR system("cls");

class CntrApresentacaoInicializacao{
private:
    Matricula matricula;
    IApresentacaoAutenticacao * cntrApresentacaoAutenticacao;
    IApresentacaoDesenvolvedor *cntrApresentacaoDesenvolvedor;
    IApresentacaoTeste *cntrApresentacaoTeste;
public:
    void executar();
    void setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao*);
    void setCntrApresentacaoDesenvolvedor(IApresentacaoDesenvolvedor*);
    void setCntrApresentacaoTeste(IApresentacaoTeste*);
};

inline  void CntrApresentacaoInicializacao::setCntrApresentacaoAutenticacao(IApresentacaoAutenticacao *cntr){
    cntrApresentacaoAutenticacao = cntr;
}

inline void CntrApresentacaoInicializacao::setCntrApresentacaoDesenvolvedor(IApresentacaoDesenvolvedor *cntr){
    cntrApresentacaoDesenvolvedor = cntr;
}

inline void CntrApresentacaoInicializacao::setCntrApresentacaoTeste(IApresentacaoTeste*cntr){
    cntrApresentacaoTeste = cntr;
}

class CntrApresentacaoAutenticacao:public IApresentacaoAutenticacao{
private:
    IServicoAutenticacao *cntr;
public:
    bool autenticar(Matricula*);
    void setcontroleservicoautenticacao(IServicoAutenticacao*);
};

inline void CntrApresentacaoAutenticacao::setcontroleservicoautenticacao(IServicoAutenticacao *cntr){
    this->cntr = cntr;
}

class CntrApresentacaoDesenvolvedor:public IApresentacaoDesenvolvedor{
private:
    IServicoDesenvolvedor *cntrServicoDesenvolvedor;
    IServicoTeste * cntrServicoTeste;
    void visualizar(Matricula);
    bool descadastrar(Matricula);
    void editar(Matricula);
public:
    bool executar(Matricula*);
    void cadastrar();
    void setcontroleservicodesenvolvedor(IServicoDesenvolvedor*);
    void setcontroleservicoteste(IServicoTeste*);
};

inline void CntrApresentacaoDesenvolvedor::setcontroleservicodesenvolvedor(IServicoDesenvolvedor*cntr){
    cntrServicoDesenvolvedor = cntr;
}

inline void CntrApresentacaoDesenvolvedor::setcontroleservicoteste(IServicoTeste*cntr){
    cntrServicoTeste = cntr;
}

class CntrApresentacaoTeste:public IApresentacaoTeste{
private:
    IServicoTeste *cntrServicoTeste;
    void cadastrarTeste(Matricula);
    void descadastrarTeste();
    void visualizarTeste();
    void editarTeste();
    void cadastrarCasoTeste();
    void descadastrarCasoTeste();
    void visualizarCasoTeste();
    void editarCasoTeste();
public:
    void executar(Matricula*);
    void setcontroleservicoteste(IServicoTeste*);
};

inline void CntrApresentacaoTeste::setcontroleservicoteste(IServicoTeste*cntr){
     this ->cntrServicoTeste= cntr;
}

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
