# Análise Semântica da Linguagem F666

Makhles Reuter Lange

Maurilio Atila Carvalho de Santana


## Verificações Semânticas

A análise semântica dirigida pela sintaxe considera que cada símbolo da gramática possui um conjunto de atributos associados a si, que subdividem-se em atributos _sintetizados_ e _herdados_. A análise presupõe a existência de uma _Abstract Syntax Tree_ (AST) representativa da gramática da linguagem. No entanto, a criação e decoração da árvore são feitas comitantemente, devido à estratégia _bottom-up_ inerente ao Bison.

A cada produção da gramática, pode-se associar um conjunto de regras semânticas responsáveis pela verificação semântica da linguagem. As seguintes verificações serão realizadas e são discriminadas a seguir:

    - Compatibilidade de tipos
    - Utilização de variáveis não declaradas;
    - Redeclaração de variáveis ou funções;
    - Chamadas de funções com número incorreto de parâmetros;

### Compatibilidade de tipos

A compatibilidade de tipos de atributos será imposta nos construtores de alguns nós. Cita-se como exemplo a expressão

```Fortran
X = Y + 5
```

e a sua redução para o nó `Expression`:

```c++
Expression
    : Expression PLUS Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Identifier {
        $$ = std::move($1);
    }
    | Literal {
        $$ = std::move($1);
    };

Identifier
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

Literal
    : INTEGER {
        $$ = driver.createNode<Literal>($1);
    }
    | REAL {
        $$ = driver.createNode<Literal>($1);
    }
    | BOOLEAN {
        $$ = driver.createNode<Literal>($1);
    }
    | STRING {
        $$ = driver.createNode<Literal>($1);
    };
```

Como o Bison é um parser LR, são feitas as seguintes operações:

1) Leitura de `Y` pelo _scanner_ e a criação de um nó do tipo `Identifier`;
2) Redução do símbolo `Identifier` pela regra `Expression ::= Identifier`;
3) Leitura de `+` pelo _scanner_ e identificação do token `PLUS`;
4) Leitura de `5` pelo _scanner_ e a criação de um nó do tipo `Literal` que possui o tipo `INTEGER`;
5) Redução do símbolo `Literal` pela regra `Expression ::= Literal`;
6) Redução dos símbolos `Expression PLUS Expression` para `Expression`.

Na última redução, cria-se um nó do tipo `Expression` cujo construtor será:

```c++
Expression(node_ptr left, node_ptr right, Fortran::op::arithmetic op)
        : m_left(std::move(left)), m_right(std::move(right)), m_operator(op) {
    assert(m_left.type() == m_right.type());
}
```

Aqui, `type()` é um método comum a todos os nós da árvore e que pode ser chamado recursivamente para os nós filhos. Para os nós envolvidos no exemplo acima, tem-se:

```c++
// Expression
// O tipo é obtido a partir do nó da esquerda (ou da direita, pois são compatíveis).
Fortran::type type() { return m_left.type(); }

// Identifier
// O tipo é obtido através de uma consulta à tabela de símbolos.
Fortran::type type() { return lookup(m_id); }

// Literal
// O tipo já é um atributo da classe.
Fortran::type type() { return m_type; }
```


### Utilização de variáveis não declaradas

A declaração de variáveis antes de sua utilização não é compulsória na linguagem Fortran. Neste caso, as variáveis e argumentos não declarados que começam com letras entre `I` e `N` são consideradas `INTEGER`, enquanto que todas as outras são `REAL`. Para forçar a utilização apenas de variáveis declaradas, inclui-se o _statement_ `IMPLICIT NONE` no início do programa. No entanto, visto que essa é considerada uma má prática, decidiu-se remover a utilização de variáveis implícitas. Para impor essa regra semântica, far-se-á o uso de uma tabela de símbolos. Para o trecho de código abaixo,

```Fortran
  PROGRAM TESTE
  REAL B
  X = B * 2.0
  STOP
  END
```

a seguinte árvore de sintaxe será criada pelo Bison:

```
  - ExecutableProgram:
      - MainProgram:
          - id: TESTE
          - Body:
              - SpecificationConstruct:
                  - DeclarationStatement:
                      - Type:INTEGER
                      - IdentifierDeclaration:
                          - id: B
                          - Structural type: SCALAR
              - ExecutableConstruct:
                  - AssignmentStatement:
                      - id: X
                      - Structural type: SCALAR
                      - Expression:
                          - MUL:
                              - id: B
                              - Literal: REAL [2.0]

```

A criação do nó `AssignmentStatement` tem como um dos parâmetros o nó `Identifier`, representado por `$1` na produção a seguir:

```c++
    AssignmentStatement
    : Identifier ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
    };
```
A verificação de variáveis declaradas pode ser feita diretamente no construtor de cada nó do tipo `Identifier` através de uma busca na tabela de símbolos:

```c++
    Identifier(std::string id) : m_id(id) {
        assert(lookup(m_id));
    }
  
```




### Redeclaração de variáveis ou funções

Essa regra é semelhante à anterior para o caso das variáveis. Contudo, faz-se a verificação no nó `DeclarationStatement`. Neste caso, espera-se que a pesquisa na tabela de símbolos não retorne nenhum resultado:

```c++
    DeclarationStatement(node_ptr type, node_ptrs&& ids)
            : m_type(std::move(type)), m_ids(std::forward<node_ptrs>(ids)) {
        for (auto id : m_ids) {
            assert(lookup(id) == 0);
        }
    }
```

Semelhantemente para as funções, a verificação pode ser feita no construtor do nó `Function`:

```c++
    Function(node_ptr type, node_ptr id, node_ptrs params, node_ptr body)
            : m_type(std::move(type)),
              m_id(std::move(id)),
              m_params(std::forward<node_ptrs>(params)),
              m_body(std::move(body)) {
        
        // Verifica se a função não existe
        assert(lookup(m_id) == 0);
    }
```


### Chamadas de funções com número incorreto de parâmetros


As regras gramaticais responsáveis por criar nós do tipo `Function` e `FunctionCall` podem ser vistos abaixo. O último é passado como parâmetro na criação de um nó do tipo `Expression`, o qual será, por sua vez, atribuído a um nó do tipo `AssignmentStatement` (vide gramática completa para mais detalhes):

```c++
    Function
    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
    }

    Expression
    : FunctionCall {
        $$ = std::move($1);
    };

    FunctionCall
    : Identifier LP ArgumentList RP {
        $$ = driver.createNode<FunctionCall>(std::move($1), std::move($3));
    };

```

Aqui, também, uma tabela de símbolos será utilizada para armazenar o identificador de cada função e seus argumentos. A implementação poderia ser feita diretamente no construtor do nó `FunctionCall`:

```c++
    FunctionCall(node_ptr id, node_ptrs&& args)
            : m_id(std::move(id)), m_args(std::forward<node_ptrs>(args)) {
        
        // Verifica a declaração
        assert(lookup(m_id));

        // Verifica a igualdade entre número de parâmetros e argumentos
        assert(lookup(m_id, args.size()));
    }
```

Assim, na última chamada do método `lookup` da tabela de símbolos, pode-se comparar o número de argumentos que está declarado para o símbolo `m_id` com o número de argumentos passado com `args.size()`. Alternativamente, pode-se pedir o número de argumentos para a tabela de símbolos e fazer a comparação no próprio construtor.

## Gramática

A gramática apresentada a seguir segue a notação utilizada pelo Bison 3.0.4. Para mais informações sobre os símbolos utilizados, verificar o arquivo `f_parser.y`.

```c++
ExecutableProgram
    : ExecutableProgram Subprogram {
        $$ = std::move($1);
        $$->addChild(std::move($2));
    }
    | Subprogram {
        $$ = driver.createRoot();
        $$->addChild(std::move($1));
    };

Subprogram
    : MainProgram {
        $$ = std::move($1);
    }
    | Subroutine {
        $$ = std::move($1);
    }
    | Function {
        $$ = std::move($1);
    };

MainProgram
    : PROGRAM Identifier Body STOP END {
        $$ = driver.createNode<MainProgram>(std::move($2), std::move($3));
    };

Subroutine
    : SUBROUTINE Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), std::move($4), std::move($6));
    }
    | SUBROUTINE Identifier LP RP Body RETURN END {
        $$ = driver.createNode<Subroutine>(std::move($2), node_ptrs{}, std::move($5));
    };

Function
    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
    }
    | Type FUNCTION Identifier LP RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), node_ptrs{}, std::move($6));
    };

Identifier
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

ArgumentList
    : Argument {
        $$ = driver.createNodeList(std::move($1));
    }
    | ArgumentList COMMA Argument {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

Argument
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

Type
    : TYPE {
        $$ = driver.createNode<Type>($1);
    };

Body
    : SpecificationConstruct ExecutableConstruct {
        $$ = driver.createNode<Body>(std::move($1), std::move($2));
    };

SpecificationConstruct
    : SpecificationList {
        $$ = driver.createNode<SpecificationConstruct>(std::move($1));
    }
    | %empty {
        $$ = driver.createNode<SpecificationConstruct>(node_ptrs{});
    };

SpecificationList
    : Specification {
        $$ = driver.createNodeList(std::move($1));
    }
    | SpecificationList Specification {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

Specification
    : DeclarationStatement {
        $$ = std::move($1);
    }
    | ParameterStatement {
        $$ = std::move($1);
    };

DeclarationStatement
    : Type IdentifierDeclarationList {
        $$ = driver.createNode<DeclarationStatement>(std::move($1), std::move($2));
    };

IdentifierDeclarationList
    : IdentifierDeclaration {
        $$ = driver.createNodeList(std::move($1));
    }
    | IdentifierDeclarationList COMMA IdentifierDeclaration {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

IdentifierDeclaration
    : Identifier {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1));
    }
    | Identifier LP INTEGER RP {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1), $3);
    }
    | Identifier LP Identifier RP {
        $$ = driver.createNode<IdentifierDeclaration>(std::move($1), std::move($3));
    };

ParameterStatement
    : PARAMETER LP AssignmentStatementList RP {
        $$ = driver.createNode<ParameterStatement>(std::move($3));
    };

AssignmentStatementList
    : AssignmentStatement {
        $$ = driver.createNodeList(std::move($1));
    }
    | AssignmentStatementList COMMA AssignmentStatement {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

AssignmentStatement
    : Identifier ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
    }
    | Identifier LP Expression RP ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3), std::move($6));
    };

Expression
    : Expression COMPARISON Expression {
        $$ = driver.createNode<Comparison>(std::move($1), std::move($3), $2);
    }
    | Expression PLUS Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression MINUS Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression TIMES Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression DIVIDE Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression AND Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | Expression OR Expression {
        $$ = driver.createNode<Expression>(std::move($1), std::move($3), $2);
    }
    | NOT Expression {
        $$ = driver.createNode<Expression>(std::move($2), $1);
    }
    | LP Expression RP {
        $$ = std::move($2);
    }
    | Identifier {
        $$ = std::move($1);
    }
    | Literal {
        $$ = std::move($1);
    };

Literal
    : INTEGER {
        $$ = driver.createNode<Literal>($1);
    }
    | REAL {
        $$ = driver.createNode<Literal>($1);
    }
    | BOOLEAN {
        $$ = driver.createNode<Literal>($1);
    }
    | STRING {
        $$ = driver.createNode<Literal>($1);
    };

ExecutableConstruct
    : ExecutableList {
        $$ = driver.createNode<ExecutableConstruct>(std::move($1));
    }
    | %empty {
        $$ = driver.createNode<ExecutableConstruct>(node_ptrs{});
    };

ExecutableList
    : Statement {
        $$ = driver.createNodeList(std::move($1));
    }
    | ExecutableList Statement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

Statement
    : AssignmentStatement {
        $$ = std::move($1);
    }
    | IfStatement {
        $$ = std::move($1);
    }
    | DoStatement {
        $$ = std::move($1);
    }
    | WhileStatement {
        $$ = std::move($1);
    }
    | ReadStatement {
        $$ = std::move($1);
    }
    | PrintStatement {
        $$ = std::move($1);
    }
    | CallStatement {
        $$ = std::move($1);
    };

IfStatement
    : IF LP Expression RP THEN StatementList ENDIF {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), node_ptrs{}, node_ptrs{});
    }
    | IF LP Expression RP THEN StatementList ElseIfStatementList ElseStatement {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), std::move($7), std::move($8));
    }
    | IF LP Expression RP THEN StatementList ElseStatement {
        $$ = driver.createNode<IfStatement>(std::move($3), std::move($6), node_ptrs{}, std::move($7));
    };

ElseIfStatementList
    : ElseIfStatement {
        $$ = driver.createNodeList(std::move($1));
    }
    | ElseIfStatementList ElseIfStatement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

ElseIfStatement
    : ELSEIF LP Expression RP THEN StatementList {
        $$ = driver.createNode<ElseIfStatement>(std::move($3), std::move($6));
    };

ElseStatement
    : ELSE StatementList ENDIF {
        $$ = std::move($2);
    };

StatementList
    : Statement {
        $$ = driver.createNodeList(std::move($1));
    }
    | StatementList Statement {
        $$ = std::move($1);
        $$.emplace_back(std::move($2));
    };

ReadStatement
    : READ ArgumentList {
        $$ = driver.createNode<ReadStatement>(std::move($2));
    };

PrintStatement
    : PRINT PrintList {
        $$ = driver.createNode<PrintStatement>(std::move($2));
    };

PrintList
    : Expression {
        $$ = driver.createNodeList(std::move($1));
    }
    | PrintList COMMA Expression {
        $$ = std::move($1);
        $$.emplace_back(std::move($3));
    };

DoStatement
    : DO Identifier ASSIGN Expression COMMA Expression StatementList ENDDO {
        node_ptr unitary = driver.createNode<Literal>(1);
        $$ = driver.createNode<DoStatement>(std::move($2),
            std::move($4), std::move($6), std::move(unitary), std::move($7));
    }
    | DO Identifier ASSIGN Expression COMMA Expression COMMA Expression StatementList ENDDO {
        $$ = driver.createNode<DoStatement>(std::move($2),
            std::move($4), std::move($6), std::move($8), std::move($9));
    };

WhileStatement
    : WHILE LP Expression RP DO StatementList ENDDO {
        $$ = driver.createNode<WhileStatement>(std::move($3), std::move($6));
    };

CallStatement
    : CALL Identifier LP ArgumentList RP {
        $$ = driver.createNode<CallStatement>(std::move($2), std::move($4));
    }
    | CALL Identifier LP RP {
        $$ = driver.createNode<CallStatement>(std::move($2), std::move(node_ptrs{}));
    };
```

