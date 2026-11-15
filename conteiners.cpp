#include"conteiners.h"

ConteinerDesenvolvedor * ConteinerDesenvolvedor::instancia=nullptr;
ConteinerDesenvolvedor*ConteinerDesenvolvedor::getinstancia(){
if(instancia==nullptr){
        instancia =new ConteinerDesenvolvedor();

}
return instancia;
}

bool ConteinerDesenvolvedor::incluir(Desenvolvedor desenvolvedor){
return container.insert(pair<string,Desenvolvedor>(desenvolvedor.getmatricula().getdado(),desenvolvedor)).second;
}

bool ConteinerDesenvolvedor::remover(Matricula matricula){
    return container.erase(matricula.getdado());
}

bool ConteinerDesenvolvedor::pesquisar(Matricula matricula,Desenvolvedor*desenvolvedor){
    map<string,Desenvolvedor>::iterator it=container.find(matricula.getdado());
    if (it == container.end()) return false;
    *desenvolvedor=it->second;
    return true;

}

bool ConteinerDesenvolvedor::atualizar(Desenvolvedor desenvolvedor){
    map<string,Desenvolvedor>::iterator it=container.find(desenvolvedor.getmatricula().getdado());
    if(it==container.end()) return false;
    it->second=desenvolvedor;
    return true;
}
ConteinerTeste * ConteinerTeste:: instancia=nullptr;
ConteinerTeste*ConteinerTeste::getinstancia(){
if(instancia==nullptr){
        instancia =new ConteinerTeste();

}
return instancia;
}

bool ConteinerTeste::incluir(Matricula matricula,Teste teste){
    TesteStruct testestruct;
    testestruct.matriculadev=matricula;
    testestruct.teste=teste;
return container.insert(pair<string,TesteStruct>(teste.getcodigo().getdado(),testestruct)).second;
}

bool ConteinerTeste::remover(Codigo codigo){
    return container.erase(codigo.getdado());
}

bool ConteinerTeste::pesquisar(Codigo codigoteste, Teste* teste) {
    map<string, TesteStruct>::iterator it = container.find(codigoteste.getdado());
    if (it == container.end()) return false;

    *teste = it->second.teste;
    return true;
}
bool ConteinerTeste::atualizar(Teste teste){
map<string,TesteStruct>::iterator it=container.find(teste.getcodigo().getdado());
if(it==container.end()) return false;
it->second.teste=teste;
return true;
}

bool ConteinerTeste::removerTeste(Matricula matriculadev){
    map<string,TesteStruct>::iterator it = container.begin();

    while( it != container.end()){
        if (it->second.matriculadev.getdado() == matriculadev.getdado()){
            it = container.erase(it);
        }else{
            it++;
        }
    }
    return true;
}

ConteinerCasoTeste * ConteinerCasoTeste:: instancia=nullptr;
ConteinerCasoTeste*ConteinerCasoTeste::getinstancia(){
if(instancia==nullptr){
        instancia =new ConteinerCasoTeste();

}
return instancia;
}

bool ConteinerCasoTeste::incluir(Codigo codigoteste,Casodeteste casoteste){
    CasoTesteStruct casotestestruct;
    casotestestruct.codigoteste=codigoteste;
    casotestestruct.casodeteste=casoteste;
return container.insert(pair<string,CasoTesteStruct>(casoteste.getcodigo().getdado(),casotestestruct)).second;
}

bool ConteinerCasoTeste::remover(Codigo codigo){
    return container.erase(codigo.getdado());
}

bool ConteinerCasoTeste::pesquisar(Codigo codigocasoteste, Casodeteste* casoteste) {
    map<string, CasoTesteStruct>::iterator it = container.find(codigocasoteste.getdado());
    if (it == container.end()) return false;

    *casoteste = it->second.casodeteste;
    return true;
}
bool ConteinerCasoTeste::atualizar(Casodeteste casoteste){
map<string,CasoTesteStruct>::iterator it=container.find(casoteste.getcodigo().getdado());
if(it==container.end()) return false;
it->second.casodeteste=casoteste;
return true;
}

bool ConteinerCasoTeste::removerCasosTeste(Codigo codigoteste){
    map<string, CasoTesteStruct>::iterator it = container.begin();

    while (it != container.end()){
        if (it->second.codigoteste.getdado() == codigoteste.getdado()){
            it = container.erase(it);
        }else{
            it++;
        }
    }
    return true;
}

