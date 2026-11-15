#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <string>
#include <stdexcept>
#include <vector>
#pragma once

using namespace std;

///
///     Esta  é uma classe base abstrata para a criação de outras classes.
///     Sendo assim ela possui atributos e metodos que irá auxiliar a criação de outras classes.
///     A classe possui para o atributo um par de metodo set (atribui dado) e get (retorna dado) , e possui um metodo validar para
///     verificar se os dados fornecidos estão seguindos os padroes definidos.
///

class Dominios{
private:
    string dado="";
    virtual bool validar(string)=0;
public:
    void setdado(string dado);
    string getdado() const;
};

inline string Dominios::getdado() const {
    return dado;
}

///
/// Esta classe representa o formato ou descrição de um teste.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar a descrição do teste.
///

class Formato : public Dominios {
public:
    bool validar(string dado);
};

///
///Esta classe representa matricula de um desenvolvedor.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar a matricula do desenvolvedor.
///

class Matricula : public Dominios {
private:
    static const int TAMANHO = 7;

public:
    bool validar(string dado) override;
};

///
///Esta classe representa codigo de um teste.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar o codigo do teste.
///

class Codigo : public Dominios{
private:
    static const int TAMANHO = 6;

public:
    bool validar(string dado) override;
};

///
///Esta classe representa uma data.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar data.
///

class Data : public Dominios {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), ano(a) {}
    bool anobissexto() const;
    int diasnomes() const;
    bool validar(std::string dado);
};

///
///Esta classe representa senha.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar a senha.
///

class Senha : public Dominios {
private:
    static const int TAMANHO = 6;

public:
    bool validar(string dado) override;
};

///
///Esta classe representa telefone.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar o telefone.
///

class Telefone : public Dominios {
private:
    static const int TAMANHO_MAX = 15;
    static const int TAMANHO_MIN = 7;

public:
    bool validar(string dado) override;
};

///
///Esta classe representa texto que serve para descrever ou fornecer nome.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar o texto.
///


class Texto : public Dominios {
private:
    static const int TAMANHO = 20;

public:
    bool validar(string dado) override;
};

///
///Esta classe representa o resultado de um teste.
///Portanto ela possui atributo que, se fornecido dado valido, irá
///armazenar o resultado obtido no teste.
///


class Resultado : public Dominios {
private:
    const string str1 = "APROVADO";
    const string str2 = "REPROVADO";

public:
    Resultado() = default;
    Resultado(const Resultado& r);
    Resultado& operator=(const Resultado& r);
    bool validar(string dado) override;
};


#endif // DOMINIOS_H_INCLUDED
