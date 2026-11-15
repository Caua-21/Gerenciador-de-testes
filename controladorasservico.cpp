#include "controladorasservico.h"
using namespace std;

bool CntrServicoDesenvolvedor::cadastrarDesenvolvedor(Desenvolvedor desenvolvedor){
    ConteinerDesenvolvedor * conteinerdesenvolvedor;
    conteinerdesenvolvedor=ConteinerDesenvolvedor::getinstancia();
    Desenvolvedor desenvolvedorcadastrar;
    if(conteinerdesenvolvedor->pesquisar(desenvolvedor.getmatricula(),&desenvolvedorcadastrar)){
        return false;
    }
    return conteinerdesenvolvedor->incluir(desenvolvedor);
}

bool CntrServicoDesenvolvedor::descadastrar(Matricula matricula){
    ConteinerDesenvolvedor *conteinerdesenvolvedor;
    conteinerdesenvolvedor=ConteinerDesenvolvedor::getinstancia();
    Desenvolvedor desenvolvedorx;
    if(!conteinerdesenvolvedor->pesquisar(matricula,&desenvolvedorx)){
        return false;
    }

    ConteinerTeste *conteinerteste;
    conteinerteste=ConteinerTeste::getinstancia();

    conteinerteste->removerTeste(matricula);

    return conteinerdesenvolvedor->remover(matricula);
}

bool CntrServicoDesenvolvedor::editar(Desenvolvedor desenvolvedor){
    ConteinerDesenvolvedor *conteinerdesenvolvedor;
    conteinerdesenvolvedor=ConteinerDesenvolvedor::getinstancia();
    Desenvolvedor desenvolvedorcadastrar;
    if(!conteinerdesenvolvedor->pesquisar(desenvolvedor.getmatricula(),&desenvolvedorcadastrar)){
        return false;
    }
    return conteinerdesenvolvedor->atualizar(desenvolvedor);
}

bool CntrServicoDesenvolvedor::visualizar(Matricula matricula,Desenvolvedor* desenvolvedor){
    ConteinerDesenvolvedor *conteinerdesenvolvedor;
    conteinerdesenvolvedor=ConteinerDesenvolvedor::getinstancia();

    return conteinerdesenvolvedor->pesquisar(matricula,desenvolvedor);
}



bool CntrServicoAutenticacao::autenticar(Matricula matricula, Senha senha){
    ConteinerDesenvolvedor *conteinerdesenvolvedor;
    conteinerdesenvolvedor=ConteinerDesenvolvedor::getinstancia();
    Desenvolvedor desenvolvedorAutenticar;

    if(conteinerdesenvolvedor->pesquisar(matricula, &desenvolvedorAutenticar)){
        return desenvolvedorAutenticar.getsenha().getdado()==senha.getdado();
    }

return false;

}

bool CntrServicoTeste::cadastrarTeste(Matricula matricula,Teste teste){
    ConteinerTeste *conteinerteste;
    conteinerteste=ConteinerTeste::getinstancia();
    Teste cadastrarteste;
    if(conteinerteste->pesquisar(teste.getcodigo(),&cadastrarteste)){
        return false;
    }
    return conteinerteste->incluir(matricula,teste);
}

bool CntrServicoTeste::descadastrarTeste(Codigo codigo){
    ConteinerTeste *conteinerteste;
    conteinerteste=ConteinerTeste::getinstancia();

    Teste teste;

    if (!conteinerteste->pesquisar(codigo, &teste)){
            return false;
    }

    ConteinerCasoTeste *conteinerCasoTeste;
    conteinerCasoTeste = ConteinerCasoTeste::getinstancia();

    conteinerCasoTeste->removerCasosTeste(codigo);

    return conteinerteste->remover(codigo);
}

bool CntrServicoTeste::visualizarTeste(Teste *teste){
    ConteinerTeste *conteinerteste;
    conteinerteste=ConteinerTeste::getinstancia();

    return conteinerteste->pesquisar(teste->getcodigo(), teste);
}

bool CntrServicoTeste::editar(Teste teste){
    ConteinerTeste *conteinerteste;
    conteinerteste=ConteinerTeste::getinstancia();

    Teste testeCadastrado;

    if (!conteinerteste->pesquisar(teste.getcodigo(), &testeCadastrado)){
        return false;
    }
    return conteinerteste->atualizar(teste);
}

bool CntrServicoTeste::cadastrarCasoTeste(Codigo codigo, Casodeteste casodeteste){
    ConteinerCasoTeste *conteinerCasoTeste;
    conteinerCasoTeste = ConteinerCasoTeste::getinstancia();

    Casodeteste casodetesteCadastrado;

    if (conteinerCasoTeste->pesquisar(casodeteste.getcodigo(), &casodetesteCadastrado)){
        return false;
    }
    return conteinerCasoTeste->incluir(codigo, casodeteste);
}

bool CntrServicoTeste::descadastrarCasoTeste(Codigo codigo){
    ConteinerCasoTeste *conteinerCasoTeste;
    conteinerCasoTeste = ConteinerCasoTeste::getinstancia();

    Casodeteste casoteste;

    if (!conteinerCasoTeste->pesquisar(codigo, &casoteste)){
        return false;
    }
    return conteinerCasoTeste->remover(codigo);
}

bool CntrServicoTeste::visualizarCasoTeste(Casodeteste *casodeteste){
    ConteinerCasoTeste *conteinerCasoTeste;
    conteinerCasoTeste = ConteinerCasoTeste::getinstancia();

    return conteinerCasoTeste->pesquisar(casodeteste->getcodigo(), casodeteste);
}

bool CntrServicoTeste::editar(Casodeteste casodeteste){
    ConteinerCasoTeste *conteinerCasoTeste;
    conteinerCasoTeste = ConteinerCasoTeste::getinstancia();

    Casodeteste casotesteCadastrado;

    if (!conteinerCasoTeste->pesquisar(casodeteste.getcodigo(), &casotesteCadastrado)){
        return false;
    }
    return conteinerCasoTeste->atualizar(casodeteste);
}
