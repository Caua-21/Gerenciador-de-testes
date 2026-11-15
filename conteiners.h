#ifndef CONTEINERS_H_INCLUDED
#define CONTEINERS_H_INCLUDED
#include <map>
#include "dominios.h"
#include"entidades.h"
#include"string.h"
using namespace std;
class ConteinerDesenvolvedor{
private:
map<string,Desenvolvedor>container;
static ConteinerDesenvolvedor*instancia;
ConteinerDesenvolvedor(){}
public:
static ConteinerDesenvolvedor* getinstancia();
bool incluir(Desenvolvedor);
bool remover(Matricula);
bool pesquisar(Matricula,Desenvolvedor *);
bool atualizar(Desenvolvedor);
};

struct TesteStruct{
Matricula matriculadev;
Teste teste;
};

struct CasoTesteStruct{
Codigo codigoteste;
Casodeteste casodeteste;

};

class ConteinerTeste{
private:
map<string,TesteStruct>container;
static ConteinerTeste*instancia;
ConteinerTeste(){};
public:
static ConteinerTeste*getinstancia();
bool incluir(Matricula,Teste);
bool remover(Codigo);
bool pesquisar(Codigo,Teste*);
bool atualizar(Teste);
bool removerTeste(Matricula);
};

class ConteinerCasoTeste{
private:
map<string,CasoTesteStruct>container;
static ConteinerCasoTeste*instancia;
ConteinerCasoTeste(){};
public:
static ConteinerCasoTeste*getinstancia();
bool incluir(Codigo,Casodeteste);
bool remover(Codigo);
bool pesquisar(Codigo,Casodeteste*);
bool atualizar(Casodeteste);
bool removerCasosTeste(Codigo);
};


#endif // CONTEINERS_H_INCLUDED
