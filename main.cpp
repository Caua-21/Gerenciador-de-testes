#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"
#include "controladorasservico.h"
using namespace std;

int main()
{
    CntrApresentacaoInicializacao cntrApresentacaoInicializacao;

    // Apresentacao
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoDesenvolvedor *cntrApresentacaoDesenvolvedor;
    IApresentacaoTeste *cntrApresentacaoTeste;

    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoDesenvolvedor = new CntrApresentacaoDesenvolvedor();
    cntrApresentacaoTeste = new CntrApresentacaoTeste();

    cntrApresentacaoInicializacao.setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoInicializacao.setCntrApresentacaoDesenvolvedor(cntrApresentacaoDesenvolvedor);
    cntrApresentacaoInicializacao.setCntrApresentacaoTeste(cntrApresentacaoTeste);

    // Servico

    IServicoAutenticacao * cntrServicoAutenticacao;
    IServicoTeste * cntrServicoTeste;
    IServicoDesenvolvedor *cntrServicoDesenvolvedor;

    cntrServicoAutenticacao = new CntrServicoAutenticacao();
    cntrServicoTeste = new CntrServicoTeste();
    cntrServicoDesenvolvedor = new CntrServicoDesenvolvedor();


    cntrApresentacaoAutenticacao->setcontroleservicoautenticacao(cntrServicoAutenticacao);
    cntrApresentacaoTeste->setcontroleservicoteste(cntrServicoTeste);
    cntrApresentacaoDesenvolvedor->setcontroleservicodesenvolvedor(cntrServicoDesenvolvedor);

    cntrApresentacaoInicializacao.executar();

    delete cntrApresentacaoAutenticacao;
    delete cntrApresentacaoDesenvolvedor;
    delete cntrApresentacaoTeste;
    delete cntrServicoAutenticacao;
    delete cntrServicoTeste;
    delete cntrServicoDesenvolvedor;

    return 0;
}
