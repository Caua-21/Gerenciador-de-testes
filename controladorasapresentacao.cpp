#include "controladorasapresentacao.h"

void CntrApresentacaoInicializacao::executar(){
     char texto1[] = "Selecione um dos servicos: ";
     char texto2[] = "1 - Acessar sistema.";
     char texto3[] = "2 - Cadastrar desenvolvedor.";
     char texto4[] = "3 - Encerrar execucao do sistema.";

     char texto5[] = "Selecione um dos servicos: ";
     char texto6[] = "1 - Selecionar servicos de desenvolvedor.";
     char texto7[] = "2 - Selecionar servicos de teste.";
     char texto8[] = "3 - Voltar.";

     int campo;

     bool apresentar = true;

     while(apresentar){
        CLR_SCR;

        cout << texto1 << endl;
        cout << "" << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: if(cntrApresentacaoAutenticacao->autenticar(&matricula)){
                bool apresentar = true;
                while(apresentar){
                    CLR_SCR;

                    cout << texto5 << endl;
                    cout << "" << endl;
                    cout << texto6 << endl;
                    cout << texto7 << endl;
                    cout << texto8 << endl;

                    campo = getch() - 48;
                    bool autenticado;

                    switch(campo){
                        case 1: autenticado = cntrApresentacaoDesenvolvedor->executar(&matricula);
                                if (!autenticado){
                                    apresentar = false;
                                };
                                break;
                        case 2: cntrApresentacaoTeste->executar(&matricula);
                                break;
                        case 3: apresentar = false;
                                break;
                    }
                }
            }
            break;
    case 2: cntrApresentacaoDesenvolvedor->cadastrar();
            break;
    case 3: apresentar = false;
            break;
        }
     }
     return;
}


bool CntrApresentacaoAutenticacao::autenticar(Matricula *matricula){
    char texto1[] = "Digite a matricula: ";
    char texto2[] = "Digite a senha: ";
    char texto3[] = "Dado em formato incorreto. ";
    char texto4[] = "Pressione qualquer tecla para continuar ou esc para sair.";

    char campo1[80];
    char campo2[80];

    Senha senha;

    while(true){
        CLR_SCR;

        cout<< "Autenticacao de Desenvolvedor" << endl;
        cout << "" << endl;
        cout << texto1 << " ";
        cin.getline(campo1, 80);
        cout << texto2 << " ";
        cin.getline(campo2, 80);

        try{
            matricula->setdado(string(campo1));
            senha.setdado(string(campo2));
            break;
        }
        catch(invalid_argument &exp){
            cout << texto3 << endl;
            cout << "" << endl;
            cout << texto4 << endl;
            if (getch() == 27) return false;
        }
    }
    return (cntr->autenticar(*matricula, senha));
}

bool CntrApresentacaoDesenvolvedor::executar(Matricula* matricula){
    char texto1[] = "Selecione um dos servicos: ";
    char texto2[] = "1 - Visualizar.";
    char texto3[] = "2 - Descadastrar.";
    char texto4[] = "3 - Editar.";
    char texto5[] = "4 - Voltar.";

    int campo;

    bool apresentar = true;

    while(apresentar){
        CLR_SCR;

        cout << texto1 << endl;
        cout << "" << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getch() - 48;


        switch(campo){
            case 1: visualizar(*matricula);
                break;
            case 2: if (descadastrar(*matricula)) return false;
                break;
            case 3: editar(*matricula);
                break;
            case 4: apresentar = false;
                break;
        }
    }
    return true;
}

void CntrApresentacaoDesenvolvedor::cadastrar(){
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome:";
    char texto3[] = "Matricula:";
    char texto4[] = "Telefone:";
    char texto5[] = "Senha:";
    char texto6[] = "Dados em formato incorreto. Pressione qualquer tecla para continuar.";
    char texto7[] = "Sucesso no cadastramento. Pressione qualquer tecla para continuar.";
    char texto8[] = "Falha no cadastramento. Pressione qualquer tecla para continuar.";

    char campo1[80], campo2[80], campo3[80], campo4[80];

    Texto nome;
    Matricula matricula;
    Telefone telefone;
    Senha senha;

    CLR_SCR;

    cout << texto1 << endl;
    cout << "" << endl;
    cout << texto2 << "  ";
    cin.getline(campo1, 80);
    cout << texto3 << " ";
    cin.getline(campo2, 80);
    cout << texto4 << " ";
    cin.getline(campo3, 80);
    cout << texto5 << " ";
    cin.getline(campo4, 80);

    try{
        nome.setdado(string(campo1));
        matricula.setdado(string(campo2));
        telefone.setdado(string(campo3));
        senha.setdado(string(campo4));
    }
    catch(invalid_argument &exp){
        cout << texto6 << endl;
        getch();
        return;
    }

    Desenvolvedor desenvolvedor;

    desenvolvedor.setnome(nome);
    desenvolvedor.setmatricula(matricula);
    desenvolvedor.settelefone(telefone);
    desenvolvedor.setsenha(senha);

    if(cntrServicoDesenvolvedor-> cadastrarDesenvolvedor(desenvolvedor)){
        cout << texto7 << endl;
        getch();
        return;
    } else{
        cout << texto8 << endl;
        getch();
        return;
    }
}

void CntrApresentacaoDesenvolvedor::visualizar(Matricula matricula){
    Desenvolvedor desenvolvedor;


    char texto1[] = "Dados do desenvolvedor.";
    char texto2[] = "Nome: ";
    char texto3[] = "Matricula: ";
    char texto4[] = "Telefone: ";
    char texto5[] = "Senha: ";
    char texto6[] = "Dados do desenvolvedor nao encontrados. Pressione qualquer tecla para continuar.";

    CLR_SCR;

    if (cntrServicoDesenvolvedor->visualizar(matricula,&desenvolvedor)){

         cout << texto1 << endl;
         cout << "" << endl;
         cout << texto2 << desenvolvedor.getnome().getdado() <<endl;
         cout << texto3 << desenvolvedor.getmatricula().getdado() <<endl;
         cout << texto4 << desenvolvedor.gettelefone().getdado() <<endl;
         cout << texto5 << desenvolvedor.getsenha().getdado() <<endl;
         getch();
    }else{
        cout << texto6 << endl;
        getch();
    }
}

bool CntrApresentacaoDesenvolvedor::descadastrar(Matricula matricula){
    char resposta;
    CLR_SCR;

    cout << "Tem certeza que deseja descadastrar o desenvolvedor? (s/n)" << endl;
    resposta = getch();
    Matricula matriculaDescadatrar;

    if (resposta == 's' || resposta == 'S'){
        if (cntrServicoDesenvolvedor->descadastrar(matricula)){
            cout << "Desenvolvedor descadastrado com sucesso." << endl;
            getch();
            return true;
        }else{
            cout << "Erro ao descadastrar desenvolvedor. Pressione qualquer tecla para continuar." << endl;
            getch();
        }
    }
    return false;
}

void CntrApresentacaoDesenvolvedor::editar(Matricula matricula){
    CLR_SCR;

    char campo1[80], campo2[80], campo3[80];

    cout << "Digite os novos dados de desenvolvedor:" << endl;
    cout << "Nome:" << " ";
    cin.getline(campo1, 80);
    cout << "Telefone:" << " ";
    cin.getline(campo2, 80);
    cout << "Senha:" << " ";
    cin.getline(campo3, 80);

    Texto nome;
    Telefone telefone;
    Senha senha;

    try{
        nome.setdado(string(campo1));
        telefone.setdado(string(campo2));
        senha.setdado(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Pressione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    Desenvolvedor desenvolvedor;

    desenvolvedor.setnome(nome);
    desenvolvedor.setmatricula(matricula);
    desenvolvedor.settelefone(telefone);
    desenvolvedor.setsenha(senha);

    CLR_SCR;

    if(cntrServicoDesenvolvedor->editar(desenvolvedor)){
        cout << "Dados alterados com sucesso. Pressione qualquer tecla para continuar." << endl;
        getch();
        return;
    }else{
        cout << "Erro ao alterar dados. Pressione qualquer tecla para continuar" << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::executar(Matricula* matricula){
    char texto1[] = "Selecione um dos servicos de teste:";
    // servicos de Teste.
    char texto2[] = "1 - Cadastrar Teste.";
    char texto3[] = "2 - Descadastrar Teste.";
    char texto4[] = "3 - Visualizar Teste.";
    char texto5[] = "4 - Editar teste.";
    // sevicos de Caso de Teste.
    char texto6[] = "5 - Cadastrar Caso de Teste.";
    char texto7[] = "6 - Descadastrar Caso de Teste.";
    char texto8[] = "7 - Visualizar Caso de Teste.";
    char texto9[] = "8 - Editar Caso de Teste.";

    char texto0[] = "9 - Voltar.";

    int campo;

    bool apresentar = true;

    while(apresentar){
        CLR_SCR;

        cout << texto1 << endl;
        cout << "" << endl;
        cout << "Teste:" << endl;

        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        cout << "" << endl;
        cout << "Caso de Teste:" << endl;

        cout << texto6 << endl;
        cout << texto7 << endl;
        cout << texto8 << endl;
        cout << texto9 << endl;
        cout << texto0 << endl;

        campo = getch() - 48;

        switch(campo){
            case 1: cadastrarTeste(*matricula);
                    break;
            case 2: descadastrarTeste();
                    break;
            case 3 : visualizarTeste();
                    break;
            case 4 : editarTeste();
                    break;
            case 5 : cadastrarCasoTeste();
                    break;
            case 6 : descadastrarCasoTeste();
                    break;
            case 7 : visualizarCasoTeste();
                    break;
            case 8 : editarCasoTeste();
                    break;
            case 9 : apresentar = false;
                    break;
        }
    }
}

void CntrApresentacaoTeste::cadastrarTeste(Matricula matricula){
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome:";
    char texto3[] = "Codigo:";
    char texto4[] = "Formato:";
    char texto5[] = "Dados em formato incorreto. Presione qualquer tecla para continuar.";
    char texto6[] = "Sucesso no cadastramento. Presione qualquer tecla para continuar.";
    char texto7[] = "Falha no cadastramento. Presione qualquer tecla para continuar.";

    char campo1[80], campo2[80], campo3[80];

    Texto nome;
    Codigo codigo;
    Formato formato;

    CLR_SCR;

    cout << texto1 << endl;
    cout<< "" << endl;
    cout << texto2 << " ";
    cin.getline(campo1, 80);
    cout << texto3 << " ";
    cin.getline(campo2, 80);
    cout << texto4 << " ";
    cin.getline(campo3, 80);

    try{
        nome.setdado(string(campo1));
        codigo.setdado(string(campo2));
        formato.setdado(string(campo3));
    }
    catch(invalid_argument &exp){
        cout << texto5 << endl;
        getch();
        return;
    }

    Teste teste;
    teste.setnome(nome);
    teste.setcodigo(codigo);
    teste.setformato(formato);

    if (cntrServicoTeste->cadastrarTeste(matricula,teste)){
        cout << texto6 << endl;
        getch();
        return;
    }else{
        cout << texto7 << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::descadastrarTeste(){
    char resposta[80];

    CLR_SCR;

    cout << "Qual o codigo do Teste que deseja descadastrar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(resposta, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(resposta));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    CLR_SCR;

    if(cntrServicoTeste->descadastrarTeste(codigo)){
        cout << "Teste descadastrado com sucesso. Pressione qualquer tecla para continuar" << endl;
        getch();
        return;
    }else{
        cout << "Erro ao descadastar Teste. Pressione qualquer tecla para continuar" << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::visualizarTeste(){
     char resposta[80];

    CLR_SCR;

    cout << "Qual o codigo do Teste que deseja visualizar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(resposta, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(resposta));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    Teste teste;
    teste.setcodigo(codigo);

    char texto1[] = "Dados do Teste.";
    char texto2[] = "Nome: ";
    char texto3[] = "Codigo: ";
    char texto4[] = "Formato: ";
    char texto5[] = "Dados do Teste nao encontrados. Pressione qualquer tecla para continuar.";

    CLR_SCR;

    if(cntrServicoTeste->visualizarTeste(&teste)){
        cout << texto1 << endl;
        cout << "" << endl;
        cout << texto2 << teste.getnome().getdado() << endl;
        cout << texto3 << teste.getcodigo().getdado() << endl;
        cout << texto4 << teste.getformato().getdado() << endl;
        getch();
    }else{
        cout << texto5 << endl;
        getch();
    }
}

void CntrApresentacaoTeste::editarTeste(){
    char resposta[80];

    CLR_SCR;

    cout << "Qual o codigo do Teste que deseja editar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(resposta, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(resposta));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    CLR_SCR;

    char campo1[80], campo2[80];

    cout << "Digite os novos dados de Teste" << endl;
    cout << "Nome:" << " ";
    cin.getline(campo1, 80);
    cout << "Formato:" << " ";
    cin.getline(campo2, 80);

    Texto nome;
    Formato formato;

    try{
        nome.setdado(string(campo1));
        formato.setdado(string(campo2));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    Teste teste;

    teste.setnome(nome);
    teste.setcodigo(codigo);
    teste.setformato(formato);

    if(cntrServicoTeste->editar(teste)){
        cout << "Dados alterados com sucesso. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }else{
        cout << "Erro ao alterar dados. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::cadastrarCasoTeste(){
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome:";
    char texto3[] = "Codigo:";
    char texto4[] = "Data:";
    char texto5[] = "Acao:";
    char texto6[] = "Resposta:";
    char texto7[] = "Resultado:";
    char texto8[] = "Dados em formato incorreto. Pressione qualquer tecla para continuar.";
    char texto9[] = "Sucesso no cadastramento. Pressione qualquer tecla para continuar.";
    char texto0[] = "Falha no cadastramento. Pressione qualquer tecla para continuar.";

    char campo1[80], campo2[80], campo3[80];
    char campo4[80], campo5[80], campo6[80];

    char res[80];

    CLR_SCR;

    cout << "Digite o codigo do teste para o qual deseja cadastrar um Caso de teste:" << endl;
    cout << "Codigo:" << " ";
    cin.getline(res, 80);

    Codigo codigoTeste;

    try{
        codigoTeste.setdado(string(res));
    }
    catch(invalid_argument &exp){
        cout << "Dado em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }


    Texto nome;
    Codigo codigo;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;

    CLR_SCR;

    cout << texto1 << endl;
    cout << "" << endl;
    cout << texto2 << "  ";
    cin.getline(campo1, 80);
    cout << texto3 << " ";
    cin.getline(campo2, 80);
    cout << texto4 << " ";
    cin.getline(campo3, 80);
    cout << texto5 << " ";
    cin.getline(campo4, 80);
    cout << texto6 << " ";
    cin.getline(campo5, 80);
    cout << texto7 << " ";
    cin.getline(campo6, 80);

    try{
        nome.setdado(string(campo1));
        codigo.setdado(string(campo2));
        data.setdado(string(campo3));
        acao.setdado(string(campo4));
        resposta.setdado(string(campo5));
        resultado.setdado(string(campo6));
    }
    catch(invalid_argument &exp){
        cout << texto8 << endl;
        getch();
        return;
    }

    Casodeteste casodeteste;

    casodeteste.setnome(nome);
    casodeteste.setcodigo(codigo);
    casodeteste.setdata(data);
    casodeteste.setacao(acao);
    casodeteste.setresposta(resposta);
    casodeteste.setresultado(resultado);

    if(cntrServicoTeste-> cadastrarCasoTeste(codigoTeste, casodeteste)){
        cout << texto9 << endl;
        getch();
        return;
    }else{
        cout << texto0 << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::descadastrarCasoTeste(){
    char resposta[80];

    CLR_SCR;

    cout << "Qual o codigo do Caso de Teste que deseja descadastrar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(resposta, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(resposta));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    CLR_SCR;

    if(cntrServicoTeste->descadastrarCasoTeste(codigo)){
        cout << "Caso de Teste descadastrado com sucesso. Pressione qualquer tecla para continuar." << endl;
        getch();
        return;
    }else{
        cout << "Erro ao descadastrar Caso de Teste. Pressione qualquer tecla para continuar" << endl;
        getch();
        return;
    }
}

void CntrApresentacaoTeste::visualizarCasoTeste(){
    char resposta[80];

    CLR_SCR;

    cout << "Qual o codigo do Caso de Teste que deseja visualizar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(resposta, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(resposta));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    Casodeteste casodeteste;
    casodeteste.setcodigo(codigo);

    char texto1[] = "Dados do Caso de Teste.";
    char texto2[] = "Nome: ";
    char texto3[] = "Codigo: ";
    char texto4[] = "Data: ";
    char texto5[] = "Acao: ";
    char texto6[] = "Resposta: ";
    char texto7[] = "Resultado: ";
    char texto8[] = "Dados do Caso de Teste nao encontrados. Pressione qualquer tecla para continuar.";

    CLR_SCR;

    if(cntrServicoTeste->visualizarCasoTeste(&casodeteste)){
        cout << texto1 << endl;
        cout << " " << endl;
        cout << texto2 << casodeteste.getnome().getdado() << endl;
        cout << texto3 << casodeteste.getcodigo().getdado()  << endl;
        cout << texto4 << casodeteste.getdata().getdado()  << endl;
        cout << texto5 << casodeteste.getacao().getdado()  << endl;
        cout << texto6 << casodeteste.getresposta().getdado()  << endl;
        cout << texto7 << casodeteste.getresultado().getdado()  << endl;
        getch();
    }else{
        cout << texto8 << endl;
        getch();
    }
}

void CntrApresentacaoTeste::editarCasoTeste(){
     char res[80];

    CLR_SCR;

    cout << "Qual o codigo do Caso de Teste que deseja editar?" << endl;
    cout << "Codigo:" << " ";
    cin.getline(res, 80);

    Codigo codigo;

    try{
        codigo.setdado(string(res));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }

    CLR_SCR;

    char campo1[80], campo2[80], campo3[80];
    char campo4[80], campo5[80];

    cout << "Digite os novos dados de Caso de Teste" << endl;
    cout << "Nome:" << " ";
    cin.getline(campo1,80);
    cout << "Data:" << " ";
    cin.getline(campo2, 80);
    cout << "Acao: " << " ";
    cin.getline(campo3, 80);
    cout << "Resposta:" << " ";
    cin.getline(campo4, 80);
    cout << "Resultado:" << " ";
    cin.getline(campo5, 80);

    Texto nome;
    Data data;
    Texto acao;
    Texto resposta;
    Resultado resultado;

    try{
        nome.setdado(string(campo1));
        data.setdado(string(campo2));
        acao.setdado(string(campo3));
        resposta.setdado(string(campo4));
        resultado.setdado(string(campo5));
    }
    catch(invalid_argument &exp){
        cout << "Dados em formato incorreto. Pressione qualquer tecla para continuar.";
        getch();
        return;
    }

    Casodeteste casodeteste;

    casodeteste.setnome(nome);
    casodeteste.setcodigo(codigo);
    casodeteste.setdata(data);
    casodeteste.setacao(acao);
    casodeteste.setresposta(resposta);
    casodeteste.setresultado(resultado);

    if(cntrServicoTeste->editar(casodeteste)){
        cout << "Dados alterados com sucesso. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }else{
        cout << "Erro ao alterar dados. Presione qualquer tecla para continuar." << endl;
        getch();
        return;
    }
}
