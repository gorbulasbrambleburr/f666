# Análise Semântica F666

A análise semântica da linguagem F666 verificará se o programa escrito pelo desenvolvedor respeita a definição semântica por nós definida.

Nessa etapa do processo de compilação, o programa fonte não é mais utilizado pela ferramenta, e sim a árvore sintática gerada após passar pelos dois processos de análise anteriores (análise léxica e sintática). No entanto, gostariamos de propor uma abordagem um pouco diferente: a ideia é procurar por incoerências na árvore sintática. Alguns exemplos são:


### Tipos

 Os seguintes tipos de variáveis são aceitos pela linguagem:

```c++
%token<Fortran::integer> INTEGER  "INTEGER value";
%token<Fortran::real>    REAL     "REAL value";
%token<Fortran::boolean> BOOLEAN  "BOOLEAN value";
%token<Fortran::string>  STRING   "STRING value";
```

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


## Verificações Semânticas

A análise semântica dirigida pela sintaxe considera que cada símbolo da gramática possui um conjunto de atributos associados a si, que subdividem-se em atributos _sintetizados_ e _herdados_. A análise presupõe a existência de uma _Abstract Syntax Tree_ (AST) representativa da gramática da linguagem descrita no item anterior. Essa árvore será decorada com atributos seguindo a estratégia _bottom-up_ inerente ao Bison.

A cada produção dessa gramática, pode-se associar um conjunto de regras semânticas responsáveis pela verificação semântica da linguagem. As seguintes verificações serão realizadas e são discriminadas a seguir:

    - Compatibilidade de tipos
    - Utilização de variáveis não declaradas;
    - Re-declaração de variáveis ou funções;
    - Chamadas de funções com número incorreto de parâmetros;
    - Comandos fora de contexto.

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

Embora as versões mais antigas do Fortran permitiam a utilização de variáveis implícitas, decidiu-se que todas as variáveis devem ser declaradas antes de serem utilizadas. Para o trecho de código abaixo,

```Fortran
  PROGRAM TESTE
  REAL B
  X = B * 2.0
  STOP
  END
```
a seguinte árvore de sintaxe será criada:

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

A criação do nó `AssignmentExpression` recebe como parâmetro um `Identifier`, como pode ser visto na produção a seguir:

```ebnf
    AssignmentStatement
    : Identifier ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
    };
```
A verificação de variáveis declaradas pode ser feito no construtor de cada nó do tipo `Identifier`:

```c++
    Identifier(std::string id)
            : m_id(id) {
        assert(lookup(m_id));
    }
  
```




### Garantir que a chamada de função respeita o número de argumentos especificado:

#### Exemplo:

```Fortran
	REAL FUNCTION R(M,T)
		INTEGER M
		REAL T

		R = 0.1*T * (M*(M+14) + 46)
		IF (R .LT. 0) THEN
		   R = 0.0
		ENDIF

		RETURN
	END

	R(A,B,C)
```

#### Grámatica de atributos

```c
	for_stat:  FOR ID 'IN' INTV 'BY' NUMBER ':' suite 
	           { ID[0].max_val = INTV[0].upperbound }
	           ;

	exp :      ( '(' exp ')' | BIN | HEX | ID | call_stat ) INTV? 
	           { INTV[0].upperbound <= ID[0].size }
	           ;

	INTV :     '<' NUMBEREXP ( ':' NUMBEREXP )? '>' 
	           { 
	          	 NUMBEREXP[0 ].max_val < NUMBEREXP[1].max_val & 
	           	 INTV.upperbound = NUMB EREXP[1].max_val 
	           }
	           ;
	SIZE :     '[' NUMBER ']' 
	           { SIZE.size = NUMBER[0].val }
	           ;

	func_stat: FUNC ID '(' ( param ( ',' param )* )? ')' SIZE ':' suite     
             { ID[0].nparams = count(param) }
             ;
	call_stat: ID '(' ( exp ( ',' exp )* )? ')' 
	           {
	           	  lookup(ID[0].type) == 'func' & 
	              count(exp) == lookup(ID[0].nparams) 
	           };

  // our proposition

  Function
    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7)); <-- we store the argument list
    }
    ...

  IdentifierDeclaration
      Identifier LP INTEGER RP {
        driver.lookupNumber($1) == 1;
    }
    | Identifier LP Identifier RP { <-- list of identifiers...
        driver.lookupNumber($1) == 1;
    };

  // original grammar

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
  ...
```

### Garantir que não seja possivel acessar variável não iniciada:

#### Exemplo:
```Fortran
	INTEGER A, B
	A = B
```

#### Grámatica de atributos

```c

  // example

	exp : ( '(' exp ')' | BIN | HEX | ID | call_stat ) INTV? 
	      { lookup(ID.val) != null }

	// our proposition

	AssignmentStatement
    : Identifier ASSIGN Expression {
        driver.lookup($1, $3) != null;
    }
    | Identifier LP Expression RP ASSIGN Expression {
        driver.lookup($1, $6) != null;
    };


	// original grammar

	AssignmentStatement
    : Identifier ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3));
    }
    | Identifier LP Expression RP ASSIGN Expression {
        $$ = driver.createNode<AssignmentStatement>(std::move($1), std::move($3), std::move($6));
    };

```

### Garantir que não seja possivel chamar função não declarada:

#### Exemplo

```Fortran
	INTEGER A, B
	A = 1
	B = 2

	R(A,B) <-- not declared function

	REAL FUNCTION R(M,T)
		INTEGER M
		REAL T

		R = 0.1*T * (M*(M+14) + 46)
		IF (R .LT. 0) THEN
		   R = 0.0
		ENDIF

		RETURN
	END
```

#### Gramática de atributos

```c

  // example

	call_stat: ID '(' ( exp ( ',' exp )* )? ')' 
	           { lookup(ID) != null } ;

  // our proposition (how we know if this is a function?)

	Identifier
    : ID {driver.lookup($1) != null};

  // original grammar

  Identifier
    : ID {
        $$ = driver.createNode<Identifier>(std::move($1));
    };

  // another proposition (is posible?)

  	Function: Type FUNCTION Identifier LP ArgumentList RP Body RETURN END 
	            { driver.lookup($3) != null; }
	            | Type FUNCTION Identifier LP RP Body RETURN END 
		          { driver.lookup($3) != null };

  // original grammar

	Function
	    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
	        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
	    }
	    | Type FUNCTION Identifier LP RP Body RETURN END {
	        $$ = driver.createNode<Function>(std::move($1), std::move($3), node_ptrs{}, std::move($6));
	    };

```

### Garantir que não seja possivel declarar duas variáveis com o mesmo nome:

#### Exemplo

```Fortran
	INTEGER A
	CHAR A
```

#### Gramática de atributos

```c

  // example
  var_stat: VAR ID SIZE (ASSIGN exp)?
            { lookup(ID[0]) == null } ;

  // our proposition (if this is not a var id but a function id?)

	Identifier: ID {driver.lookup($1) == null};

  // original grammar

  Identifier: ID {$$ = driver.createNode<Identifier>(std::move($1));};
```

### Garantir que não seja possivel declarar duas funções com o mesmo nome:

#### Exemplo

```Fortran
	REAL FUNCTION R(M,T)
		
		R = M + T

		RETURN
	END

	REAL FUNCTION R(M,T)
		INTEGER M
		REAL T

		R = 0.1*T * (M*(M+14) + 46)
		IF (R .LT. 0) THEN
		   R = 0.0
		ENDIF

		RETURN
	END
```

#### Grámatica de atributos

```sh

  // example
	func_stat:  FUNC ID '(' ( param ( ',' param )* )? ')' SIZE ':' suite 
  	          { lookup(ID[0]) == null } ;

  // our proposition

	Function:   Type FUNCTION Identifier LP ArgumentList RP Body RETURN END 
	            { driver.lookup($3) == null; }
	          | Type FUNCTION Identifier LP RP Body RETURN END 
		          { driver.lookup($3) == null };

  // original grammar

	Function
	    : Type FUNCTION Identifier LP ArgumentList RP Body RETURN END {
	        $$ = driver.createNode<Function>(std::move($1), std::move($3), std::move($5), std::move($7));
	    }
	    | Type FUNCTION Identifier LP RP Body RETURN END {
	        $$ = driver.createNode<Function>(std::move($1), std::move($3), node_ptrs{}, std::move($6));
	    };
```


