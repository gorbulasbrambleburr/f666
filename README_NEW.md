# Análise Semântica F666

A análise semântica da linguagem F666 verificará se o programa escrito pelo desenvolvedor respeita a definição semântica por nós definida.

Nessa etapa do processo de compilação, o programa fonte não é mais utilizado pela ferramenta, e sim a árvore sintática gerada após passar pelos dois processos de análise anteriores (análise léxica e sintática). No entanto, gostariamos de propor uma abordagem um pouco diferente: a ideia é procurar por incoerências na árvore sintática. Alguns exemplos são:

	- Operandos incompatíveis com operadores;
	- Variáveis não declaradas;
	- Re-declaração de variáveis ou funções;
	- Chamadas de funções com número incorreto de parâmetros;
	- Comandos fora de contexto.

## Aspectos semânticos:
A linguagem Fortran 666 terá as regras semânticas bem semelhantes a linguagem Fortran, pois ela está baseada nas variáveis do Fortran 77, que serviu de inspiração para o nosso projeto.  

### Declaração de variáveis e funções

 Nossa linguagem aceita os seguintes tipos de variáveis:

```c
%token<Fortran::integer> INTEGER        "INTEGER value";
%token<Fortran::real>    REAL           "REAL value";
%token<Fortran::boolean> BOOLEAN        "BOOLEAN value";
%token<Fortran::string>  STRING         "STRING value";
```

## Gramática

Primeiro vamos apresentar a gramática atual da linguagem F666, ela esta contante modificação por conta da dinamica com o flex e bison que esta sendo a parte mais complexa do projeto, neste caso essa é a ultima versão das 9:40h do dia 29/09/2017 :) ...

```sh
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
    };

/*
ExpressionList
    : Expression
    | ExpressionList "," Expression
    ;
*/
ExecutableConstruct
    : ExecutableList {
        $$ = driver.createNode<ExecutableConstruct>(std::move($1));
    }
    | %empty {
        $$ = driver.createNode<ExecutableConstruct>(node_ptrs{});
    };;

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
    /*
    | DoConstruct {
        $$ = std::move($1);
    }
    | WhileConstruct {
        $$ = std::move($1);
    }
    | CallStatement {
        $$ = std::move($1);
    }
    | CycleStatement {
        $$ = std::move($1);
    }
    | ExitStatement {
        $$ = std::move($1);
    };
    | PrintStatement {
        $$ = std::move($1);
    }
    | ReadStatement {
        $$ = std::move($1);
    }*/;

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

/*
PrintStatement
    : "PRINT" PrintList
    ;

PrintList
    : PrintItem
    | PrintList "," PrintItem
    ;

PrintItem
    : STRING
    | Expression
    ;

ReadStatement
    : "READ" ArgumentList
    ;


DoConstruct
    : DoStatement DoLoopControl EndDoStatement
    ;

DoStatement
    : "DO"
    ;

DoLoopControl
    : ID "=" Expression "," Expression
    | ID "=" Expression "," Expression "," Expression
    ;

EndDoStatement
    : Statement "ENDDO"
    ;

WhileConstruct
    : WhileStatement EndWhileStatement
    ;

WhileStatement
    : "WHILE" LogicalExpression "DO"
    ;

EndWhileStatement
    : Statement "ENDDO"
    ;

CallStatement
    : "CALL" ID LP ArgumentList RP
    | "CALL" ID LP RP
    ;

CycleStatement
    : "CONTINUE"
    ;

ExitStatement
    : "EXIT"
    ;
*/
```


## Descrição do processo

Uma forma que pensamos em fazer o processo de analise semântica e geração de código é por meio de [Tradução dirigida pela Sintaxe](https://en.wikipedia.org/wiki/Syntax-directed_translation) - STD.  Pois em nosso projeto possuimos uma Abstract syntax tree, bem definida, e neste metodo usando essa arvore produzimos a análise semântica e a geração de código em cada passo. Então pretendemos análisar essa alternativa e se for o caso construir nossa solução usando ela. Em seguida apresentamos alguns dos pontos chave que pensamos ate o momento:

### Garantir que um tipo declarado seja apenas daquele tipo;

Nossa AST garante os tipos na sua análise inicial. Sendo assim basta que tenhamos um metodo lookup que olhe o tipo que foi declarado e o tipo que esta sendo devolvido.

```c

	// type declaration (example)

	Type: TYPE {$$ = driver.createNode<Type>($1);};

	DeclarationStatement
    : Type IdentifierDeclarationList {
        $$ = driver.createNode<DeclarationStatement>(std::move($1), std::move($2));
    };


	// type finding is intern method




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

### Garantir que não seja possivel acessar variável não declarada:

#### Exemplo:

```Fortran
  CHAR A[32] = B
```

#### Grámatica de atributos

```c

	// example

	exp : ( '(' exp ')' | BIN | HEX | ID | call_stat ) INTV?
	      { lookup(ID) != null }
      ;

  // our proposition

  Identifier: ID {drive.lookup($1) != null};

  // original grammar

  Identifier: ID {$$ = driver.createNode<Identifier>(std::move($1));};


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


