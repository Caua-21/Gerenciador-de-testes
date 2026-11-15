#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED
#include "dominios.h"


///
///Esta classe representa um desenvolvedor.
///Sendo assim ela possui atributos que caracterizam um desenvovedor
///como nome, matricula, senha e telefone.
/// Esta classe possui, para cada atributo, um para de metodo set e get.
///
///@param matricula.
///@param nome.
///@param senha.
///@param telefone.

class Desenvolvedor{
    private:
        Matricula matricula;
        Texto nome;
        Senha senha;
        Telefone telefone;
    public:
        void setmatricula(const Matricula & matricula);
        void setnome(const Texto & texto);
        void setsenha(const Senha & senha);
        void settelefone(const Telefone & telefone);
        Matricula getmatricula()const;
        Texto getnome()const;
        Senha getsenha()const;
        Telefone gettelefone()const;};

    inline void Desenvolvedor::setmatricula(const Matricula & matricula){
        this->matricula=matricula;}
    inline void Desenvolvedor::setnome(const Texto & nome){
        this->nome=nome;}
    inline void Desenvolvedor::setsenha(const Senha & senha){
        this->senha=senha;}
    inline void Desenvolvedor::settelefone(const Telefone & telefone){
        this->telefone=telefone;}

    inline Matricula Desenvolvedor::getmatricula()const{
          return matricula;}
    inline Texto Desenvolvedor::getnome()const{
          return nome;}
    inline Telefone Desenvolvedor::gettelefone()const{
         return telefone;}
    inline Senha Desenvolvedor::getsenha()const{
         return senha;}

///
///Esta classe representa um teste.
///Sendo assim ela possui atributos que caracterizam um teste
///como codigo, nome do desenvolvedor e a classe(tipo) do teste.
///Esta classe possui, para cada atributo, um para de metodo set e get.
///
///
///@param codigo.
///@param nome.
///@param formato.

class Teste{
    private:
        Codigo codigo;
        Texto nome;
        Formato formato;
    public:
        void setcodigo(const Codigo& codigo);
        void setnome(const Texto& nome);
        void setformato(const Formato& formato);
        Codigo getcodigo() const;
        Texto getnome() const;
        Formato getformato() const;
};

inline void Teste::setcodigo(const Codigo& codigo){
     this->codigo = codigo;
}

inline void Teste::setnome(const Texto& nome){
     this->nome = nome;
}

inline void Teste::setformato(const Formato& formato) {
    this->formato = formato;
}

inline Codigo Teste::getcodigo() const {
      return codigo;
}

inline Texto Teste::getnome() const {
      return nome;
}

inline Formato Teste::getformato() const {
      return formato;
}

///
///     Esta classe representa um a simulacao de um teste.
///     Sendo assim ela possui atributos que caracterizam essa simulacao
///     como codigo, nome do desenvolvedor, classe(tipo) do teste, data de realizacao,
///     a acao realizada, uma resposta para acao e por fim fornece um resultado.
///     Esta classe possui, para cada atributo, um para de metodo set e get.
///
///@param nome.
///@param data.
///@param acao.
///@param resposta.
///@param resultado.


class Casodeteste{
    private:
    Codigo codigo;
    Texto nome;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;
    public:
        void setcodigo(const Codigo & codigo);
        void setnome(const Texto & nome);
        void setdata(const Data & data);
        void setacao(const Texto & acao);
        void setresposta(const Texto & resposta);
        void setresultado(const Resultado & resultado);
        inline Codigo getcodigo()const;
        inline Texto getnome()const;
        inline Data getdata()const;
        inline Texto getresposta()const;
        inline Resultado getresultado()const;
        inline Texto getacao()const;

};
inline void Casodeteste::setcodigo(const Codigo &codigo){
    this->codigo=codigo;}
inline void Casodeteste::setnome(const Texto & nome){
    this->nome=nome;}
inline void Casodeteste::setdata(const Data & data){
    this->data=data;}
inline void Casodeteste::setacao(const Texto & acao){
    this->acao=acao;}
inline void Casodeteste::setresposta(const Texto & resposta){
    this->resposta=resposta;}
inline void Casodeteste::setresultado(const Resultado & resultado){
    this->resultado=resultado;}
inline Codigo Casodeteste::getcodigo()const{
    return codigo;}
inline Texto Casodeteste::getnome()const{
      return nome;}
inline Data Casodeteste::getdata()const{
      return data;}
inline Texto Casodeteste::getresposta()const{
      return resposta;}
inline Resultado Casodeteste::getresultado()const{
      return resultado;}
inline Texto Casodeteste::getacao()const{
      return acao;}
#endif // ENTIDADES_H_INCLUDED
