#include "stubs.h"

bool StubServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    if(matricula.getdado() == "1789817" &&
       senha.getdado() == "123456"){
           return true;
       }
       return false;
}

bool StubServicoDesenvolvedor::cadastrarDesenvolvedor(Desenvolvedor desenvolvedor){
    return true;
}

bool StubServicoDesenvolvedor::visualizar(Desenvolvedor *desenvolvedor){
    return true;
}

bool StubServicoDesenvolvedor::descadastrar(Matricula matricula){
    return true;
}

bool StubServicoDesenvolvedor::editar(Desenvolvedor desenvolvedor){
    return true;
}

bool StubServicoTeste::visualizarCasoTeste(Casodeteste *Casodeteste){
    return true;
}

bool StubServicoTeste::editar(Casodeteste casodeteste){
    return true;
}

bool StubServicoTeste::descadastrarCasoTeste(Codigo codigo){
    return true;
}

bool StubServicoTeste::cadastrarCasoTeste(Casodeteste casodeteste){
    return true;
}

bool StubServicoTeste::visualizarTeste(Teste *teste){
    return true;
}

bool StubServicoTeste::cadastrarTeste(Matricula matricula,Teste teste){
    return true;
}

bool StubServicoTeste::editar(Teste teste){
    return true;
}

bool StubServicoTeste::descadastrarTeste(Matricula matricula, Codigo codigo){
    return true;
}
