# PKL - Gerenciador de Testes de Software

Sistema de console em **C++** para cadastrar desenvolvedores e gerenciar os **testes** e **casos de teste** de cada um. O projeto foi organizado em **três camadas** (apresentação, serviço e armazenamento) e usa **tipos de domínio** que validam o formato dos dados antes de aceitá-los.

> Os dados ficam apenas em memória: ao fechar o programa, tudo é perdido.

## Sumário

- [Funcionalidades](#funcionalidades)
- [Tecnologias](#tecnologias)
- [Requisitos](#requisitos)
- [Como compilar e executar](#como-compilar-e-executar)
- [Como usar](#como-usar)
- [Regras de validação dos dados](#regras-de-validação-dos-dados)
- [Arquitetura](#arquitetura)
- [Estrutura dos arquivos](#estrutura-dos-arquivos)
- [Limitações conhecidas](#limitações-conhecidas)
- [Autor](#autor)

## Funcionalidades

**Desenvolvedor**
- Cadastrar, visualizar, editar e descadastrar (a matrícula é a chave única)
- Autenticação por matrícula e senha

**Teste** (pertence a um desenvolvedor)
- Cadastrar, visualizar, editar e descadastrar
- Formatos: `FUMACA`, `UNIDADE`, `INTEGRACAO`, `SISTEMA`, `REGRESSAO`, `ACEITACAO`

**Caso de teste** (pertence a um teste)
- Cadastrar, visualizar, editar e descadastrar
- Campos: nome, código, data, ação, resposta e resultado (`APROVADO` ou `REPROVADO`)

**Remoção em cascata:** descadastrar um desenvolvedor remove os testes dele, e descadastrar um teste remove os casos de teste dele.

## Tecnologias

| Item | Uso |
|---|---|
| C++ (biblioteca padrão: `string`, `map`, `unordered_set`, `stdexcept`) | Todo o código |
| `<conio.h>` (`getch`) e `system("cls")` | Leitura de teclas e limpeza de tela (**somente Windows**) |
| GCC / MinGW | Compilação |
| Code::Blocks (`pkl.cbp`) ou VS Code | Ambientes de desenvolvimento suportados |

Não há bibliotecas externas.

## Requisitos

- **Windows** (por causa do `conio.h`)
- **g++** (MinGW-w64). Para conferir: `g++ --version`

Para instalar o compilador pelo PowerShell:

```powershell
winget install BrechtSanders.WinLibs.POSIX.UCRT
```

Depois feche e reabra o terminal.

## Como compilar e executar

### Pelo terminal (PowerShell), na pasta do projeto

```powershell
mkdir bin\Debug -Force
g++ -static -g -Wall -fexceptions conteiners.cpp controladorasapresentacao.cpp controladorasservico.cpp dominios.cpp main.cpp stubs.cpp -o bin/Debug/pkl.exe
.\bin\Debug\pkl.exe
```

A opção `-static` embute as bibliotecas do MinGW no executável e evita erros de DLL quando há mais de um MinGW instalado no computador.

### Pelo VS Code

Abra a pasta do projeto e pressione **Ctrl+Shift+B**. A tarefa `Compilar pkl` (em `.vscode/tasks.json`) cria `bin/Debug` e compila. Depois execute `.\bin\Debug\pkl.exe`.

> O programa usa `getch()` e limpa a tela a cada menu. Se o terminal integrado do VS Code se comportar de forma estranha, execute numa janela do Prompt de Comando:
> ```powershell
> Start-Process cmd -ArgumentList '/k', '.\bin\Debug\pkl.exe'
> ```

### Pelo Code::Blocks

Abra o arquivo `pkl.cbp` e use **Build and run** (F9).

## Como usar

Como os dados não são salvos, a cada execução é preciso **cadastrar um desenvolvedor antes de entrar**.

1. No menu principal, escolha **2** (cadastrar desenvolvedor) e preencha os campos.
2. Escolha **1** (acessar o sistema) e faça login com matrícula e senha.
3. No submenu, escolha **1** para serviços de desenvolvedor ou **2** para serviços de teste.
4. Em serviços de teste: cadastrar, descadastrar, visualizar e editar teste (opções 1 a 4) e as mesmas operações para caso de teste (opções 5 a 8).

As opções dos menus são lidas **sem apertar Enter**.

### Valores de exemplo válidos

| Campo | Exemplo |
|---|---|
| Nome | `Joao Silva` |
| Matrícula | `1234566` |
| Telefone | `11999999999` |
| Senha | `abc123` |
| Código de teste / caso | `ABC123` |
| Formato | `UNIDADE` |
| Data | `15/MAR/2024` |
| Resultado | `APROVADO` |

## Regras de validação dos dados

Cada campo é um **tipo de domínio** (`dominios.h`). Um valor inválido lança `invalid_argument` e a tela mostra "Dados em formato incorreto".

| Domínio | Regra |
|---|---|
| `Matricula` | 7 dígitos numéricos; o último é dígito verificador calculado sobre os 6 primeiros |
| `Senha` | 6 caracteres, sem repetição, letras, números ou `@ $ # & %` |
| `Telefone` | 7 a 15 dígitos, com `+` opcional no início |
| `Codigo` | 3 letras seguidas de 3 dígitos |
| `Texto` | Até 20 caracteres, sem dois espaços seguidos |
| `Formato` | Uma das seis palavras da lista de formatos |
| `Resultado` | `APROVADO` ou `REPROVADO` |
| `Data` | `DD/MMM/AAAA`, com mês abreviado (`JAN`, `FEV`, `MAR`, ...) |

## Arquitetura

O projeto segue uma **arquitetura em três camadas**. A camada de apresentação conhece apenas **interfaces** de serviço, e a ligação entre as classes concretas é feita no `main.cpp` (injeção de dependência).

```
Usuário (teclado)
      │
      ▼
Apresentação  (controladorasapresentacao)   menus, leitura e mensagens
      │  usa apenas as interfaces IServico*
      ▼
Serviço       (controladorasservico)        regras de negócio
      │
      ▼
Contêineres   (conteiners)                  std::map em memória (Singleton)

dominios.h  ◄──  entidades.h     (usados por todas as camadas)
```

**Recursos de C++ e padrões usados:** classe abstrata (`Dominios`) com método virtual puro, herança e polimorfismo, encapsulamento, composição (entidades formadas por tipos de domínio), interfaces, exceções, Singleton, injeção de dependência e Template Method (`Dominios::setdado` chama o `validar` de cada filho).

## Estrutura dos arquivos

| Arquivo | Responsabilidade |
|---|---|
| `main.cpp` | Cria os objetos e liga as camadas |
| `dominios.h/.cpp` | Tipos de domínio com validação |
| `entidades.h` | `Desenvolvedor`, `Teste` e `Casodeteste` |
| `interfaces.h` | Interfaces (classes abstratas) de apresentação e serviço |
| `controladorasapresentacao.h/.cpp` | Menus e telas |
| `controladorasservico.h/.cpp` | Regras de negócio |
| `conteiners.h/.cpp` | Armazenamento em memória |
| `stubs.h/.cpp` | Implementações de teste dos serviços (não usadas no `main`) |
| `pkl.cbp` | Projeto do Code::Blocks |

## Limitações conhecidas

- Os dados não são persistidos.
- Só funciona no Windows (`conio.h` e `cls`).
- A senha é guardada e comparada em texto puro.
- A validação de `Data` usa sempre o mês e o ano padrão no cálculo de dias, então datas como `30/FEV/2024` são aceitas; o mês `ABRIL` nunca é aceito por causa do limite de tamanho.
- O validador de `Texto` rejeita qualquer dígito diferente de `9`.
- Cerca de 10% das combinações de matrícula não têm dígito verificador possível.
- Apagar um desenvolvedor remove os testes dele, mas deixa os casos de teste órfãos.
- Não há verificação de que o teste existe ao cadastrar um caso de teste, nem de que o teste pertence ao usuário logado ao editá-lo ou removê-lo.
- As classes em `stubs.cpp` não implementam corretamente as interfaces e não são usadas.

## Autor

Cauã Lima - [Caua-21](https://github.com/Caua-21)
