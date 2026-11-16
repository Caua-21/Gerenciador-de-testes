#include "dominios.h"
#include <string>
#include <cctype>
#include<iostream>
#include<unordered_set>
using namespace std;

///este metodo verifica se o dado fornecido � v�lida.
///Se o dado for v�lido inicializa o objeto.
///Se o dado for inv�lido lan�a exe��o.
///
///@param dado
///
///@throw invalid_argument


void Dominios::setdado(string dado) {
    if (validar(dado)) {
        this->dado = dado;
    } else {
        throw invalid_argument("Valor inv�lido para o dom�nio");
    }
}

bool Data::anobissexto() const {
    return ((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0);
}

int Data::diasnomes() const {
    int dias[12] = {31, anobissexto() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dias[mes - 1];
}

///este metodo verifica se a data fornecido � v�lido.
///Se a data for v�lida retorna verdadeiro.
///Se a data for inv�lida retorna falso.
///
///@return true.
///
///@return false.


bool Data::validar(string dado) {
    if (dado.size() < 8 || dado.size() > 11) {
        return false;
    }

    int dia, mes, ano;
    int pos1 = dado.find('/');
    int pos2 = dado.rfind('/');

    if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2) {
        return false;
    }

    dia = std::stoi(dado.substr(0, pos1));

    string mes_str = dado.substr(pos1 + 1, pos2 - pos1 - 1);
    if (mes_str == "JAN" || mes_str == "jan") {
        mes = 1;
    } else if (mes_str == "FEV" || mes_str == "fev") {
        mes = 2;
    } else if (mes_str == "MAR" || mes_str == "mar") {
        mes = 3;
    } else if (mes_str == "ABR" || mes_str == "abr") {
        mes = 4;
    } else if (mes_str == "MAI" || mes_str == "mai") {
        mes = 5;
    } else if (mes_str == "JUN" || mes_str == "jun") {
        mes = 6;
    } else if (mes_str == "JUL" || mes_str == "jul") {
        mes = 7;
    } else if (mes_str == "AGO" || mes_str == "ago") {
        mes = 8;
    } else if (mes_str == "SET" || mes_str == "set") {
        mes = 9;
    } else if (mes_str == "OUT" || mes_str == "out") {
        mes = 10;
    } else if (mes_str == "NOV" || mes_str == "nov") {
        mes = 11;
    } else if (mes_str == "DEZ" || mes_str == "dez") {
        mes = 12;
    } else {
        return false;
    }

    ano = std::stoi(dado.substr(pos2 + 1));

    if (ano < 2000 || ano > 2999) {
        return false;
    }

    this->mes = mes;
    this->ano = ano;
    int dias_no_mes = diasnomes();

    if (dia < 1 || dia > dias_no_mes) {
        return false;
    }

    return true;
}

///este metodo verifica se o resultado fornecido � v�lido.
///Se o resultado for v�lido retorna verdadeiro.
///Se o resultado for inv�lido retorna falso.
///
///@return true.
///
///@return false.

bool Resultado::validar(string dado){
    if(dado != str1 && dado != str2){
        return false;
    }
    return true;
}

Resultado& Resultado::operator=(const Resultado& r) {
    if (this != &r) {
        Dominios::operator=(r);
    }
    return *this;
}

Resultado::Resultado(const Resultado& r) : Dominios(r), str1(r.str1), str2(r.str2) {}


///este metodo verifica se o formato fornecido � v�lido.
///Se o formato for v�lido retorna verdadeiro.
///Se o formato for inv�lido retorna falso.
///
///@return true.
///
///@return false.

bool Formato::validar(string dado) {
    if ((dado == "FUMACA" || dado == "UNIDADE" || dado == "INTEGRACAO" || dado == "SISTEMA" || dado == "REGRESSAO" || dado == "ACEITACAO")){
        return true;
    }else{
        return false;
    }
}

///este metodo verifica se a matricula fornecido � v�lid.
///Se a matricula for v�lida retorna verdadeiro.
///Se a matricula for inv�lida retorna falso.
///
///@return true.
///
///@return false.


bool Matricula::validar(string dado) {
        //1234567
        int vect[6]={1,2,1,2,1,2};
        if(dado.size()!= TAMANHO){
            throw invalid_argument("Tamanho da matricula invalido");
        }
        int soma = 0;
        for (int i = 5; i >=0 ;--i ) {
        int mult;
        if (isdigit(dado[i])){
        mult=(dado[i]-'0')*vect[i];
        if(mult > 9){
            string convert=to_string(mult);
            mult=(convert[0]-'0')+(convert[1]-'0');
        }
        soma=soma+mult;
        }
        else{
            throw invalid_argument("Digite apenas digitos numericos");
        }
        }
        int digito = (10 - (soma % 10)) % 10;

        if(digito == dado.back()-'0'){
            return true;
        }
        else{
            return false;
        }
}

///este metodo verifica se o codigo fornecido � v�lido.
///Se o codigo for v�lido retorna verdadeiro.
///Se o codigo for inv�lido retorna falso.
///
///@return true.
///
///@return false.

bool Codigo::validar(string dado){
    int contador_letras = 0;
    int contador_digitos = 0;

    if(dado.size() != TAMANHO){
        return false;
    }

    for(int i = 0; i < TAMANHO-3; i++){
        if(isalpha(dado[i])){
            contador_letras++;
        } else {
            return false;
        }
    }

    if (contador_letras != 3){
        return false;
    }

    for(int i = TAMANHO-3; i < TAMANHO; i++){
        if(isdigit(dado[i])){
            contador_digitos++;
        } else {
            return false;
        }
    }

    if(contador_digitos != 3){
        return false;
    }

    return true;
}

///este metodo verifica se a senha fornecida � v�lido.
///Se a senha for v�lida retorna verdadeiro.
///Se a senha for inv�lida retorna falso.
///
///@return true.
///
///@return false.

bool Senha::validar(string dado) {
    if (dado.size() != TAMANHO) {
        return false;
    }

    unordered_set<char> caracteresunicos;
    for (char c : dado) {
        if (!isalnum(c) && !isalpha(c) && c != '@' && c != '$' && c != '#' && c != '&' && c != '%') {
            return false;
        }
        if (caracteresunicos.count(c) != 0) {
            return false;
        }
        caracteresunicos.insert(c);
    }
    return true;
}

///este metodo verifica se o telefone fornecido � v�lido.
///Se o telefone for v�lido retorna verdadeiro.
///Se o telefone for inv�lido retorna falso.
///
///@return true.
///
///@return false.

bool Telefone::validar(string dado){
    string subs_str;
    if(dado[0] == '+'){
        subs_str = dado.substr(1, dado.size());
    } else {
        subs_str = dado;
    }
    if(subs_str.size() >= TAMANHO_MIN && subs_str.size() <= TAMANHO_MAX){
        for(int i = 0; i < subs_str.size(); ++i){
            if(isdigit(subs_str[i])){
                if(subs_str[i] >= '0' && subs_str[i] <= '9'){
                    continue;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

///este metodo verifica se o data fornecido � v�lido.
///Se o texto for v�lido retorna verdadeiro.
///Se o texto for inv�lido retorna falso.
///
///@return true.
///
///@return false.


bool Texto::validar(string dado){

    if(dado.size()<= TAMANHO){
        for(int i=0;i<dado.size();++i){
            if (dado[i] == ' '){
                if(dado[i+1] == ' '){
                    return false;
                }
                else{
                    continue;
                }
            }
            else{
                if(isdigit(dado[i])){
                    if(dado[i]>='0'&&dado[i]<='9'){
                        continue;
                    }
                    return false;
                }
                if(dado[i]>= 'A' && dado[i] <= 'Z' || dado[i] >= 'a' && dado[i]<='z'){
                    continue;
                }
               else{
                  if(((dado[i]!='(') && (dado[i]!=')') && (dado[i]!='!') && (dado[i]!='?') && (dado[i]!=',') && (dado[i]!=':') && (dado[i]!=';') && (dado[i]!='!') &&
                    (dado[i]!='.')&& (dado[i]!='$') && (dado[i]!='-') && (dado[i]!='@')&& (dado[i]!='%') && (dado[i]!= '&'))) {
                       return false;}
                       continue;}}}
                  return true;}
    return false;}
