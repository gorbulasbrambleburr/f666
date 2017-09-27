# Análise Semantica F666

A análise semântica da nossa linguagem F666, verificará se o programa escrito pelo desenvolvedor respeita a definição semântica definida pelos projetistas da linguagem.

Nessa etapa do processo de compilação, o programa fonte não é mais utilizado pela ferramenta, e sim a árvore sintática gerada após passar pelos 2 processos de análise anteriores (análise léxica, análise sintática).

Devendo procurar por incoerências na árvore sintática como:
		
		- Operandos incompatíveis com operadores;
		- Variáveis não declaradas;
		- Re-declaração de variáveis ou funções;
		- Chamadas de funções com número incorreto de parâmetros;
		- Comandos fora de contexto.

## Aspectos semânticos  

A linguagem Fortram 666 terá as regras semânticas bem semelhantes a linguagem Fortram, variaveis do Fortram 6 e 7, que serviu de inspiração para o desenvolvimento dela.  

### Declaração de variáveis e funções

 Nossa linguagem aceita os seguintes tipos de variáveis:

		- char: uma variável do tipo char pode ser atribuída por outra variável do tipo char, ou um  valor de tamanho 1 entre aspas simples;  
		-  int: variável que representa um número inteiro, onde pode ser atribuída por uma operação  matemática de outros valores inteiros;  
		- float: variável que representa um número fracionário, onde pode ser atribuída por uma  operação matemática de outros valores inteiros ou fracionários;  
		- string: variável que representa uma cadeia de caracteres entre aspas duplas e pode ser  atribuída por outra variável do mesmo tipo ou a operação + (representa uma  concatenação) entre strings;  
		- boolean: variável que assume dois valores, verdadeiro ou falso, podendo ser atribuída  através de uma operação booleana. 

As variáveis podem ser atribuídas através de resultados de funções onde o retorno dela é do mesmo tipo ou aplicadas a fórmulas matemáticas respeitando as regras anteriores.


## Gramática

Primeiro vamos apresentar a gramática da linguagem F666:

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
    : LogicalExpression {
        $$ = std::move($1);
    }
    /*| NumericExpression {
        $$ = std::move($1);
    }*/;

LogicalExpression
    : Expression COMPARISON Expression {
        $$ = driver.createNode<LogicalExpression>(std::move($1), std::move($2), std::move($3));
    }
    | BOOLEAN {
        $$ = driver.createNode<LogicalExpression>($1);
    };

NumericExpression
    : %empty {
        $$ = driver.createNode<NumericExpression>();
    }

    : Factor
    | NumericExpression "+" Factor
    | NumericExpression "-" Factor
    ;

ExpressionList
    : Expression
    | ExpressionList "," Expression
    ;

Number
    : INT {
        $$ = driver.intNumeber($1);
    }
    | FLOAT {
        $$ = driver.floatNumber($1);
    };

ExecutableConstruct
    : %empty {
        $$ = driver.createNode<ExecutableConstruct>(node_ptrs{});
    };

    : Statement
    | ExecutableConstruct Statement
    ;

Statement
    : AssignmentStatement
    | PrintStatement
    | ReadStatement
    | IfConstruct
    | DoConstruct
    | WhileConstruct
    | CallStatement
    | CycleStatement
    | ExitStatement
    ;

Factor
    : Term
    | Factor "*" Term
    | Factor "/" Term
    ;

Term
    : LP NumericExpression RP
    | ID LP ExpressionList RP
    | ID LP RP
    | ID
    | Number
    | "-" Term
    ;

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

IfConstruct
    : IfThenStatement ThenConstruct
    ;

IfThenStatement
    : "IF" LogicalExpression "THEN"
    ;

ThenConstruct
    : Statement EndIfStatement
    | Statement ElseIfConstruct
    | Statement ElseConstruct
    ;

EndIfStatement
    : "ENDIF"
    ;

ElseIfConstruct
    : ElseIfStatement ThenConstruct
    ;

ElseIfStatement
    : "ELSEIF" Expression "THEN"
    ;

ElseConstruct
    : "ELSE" Expression "END"
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
```


## Descrição do processo


Micro texto instrodutorio para esta parte.


### Garantir que um tipo declarado seja apenas daquele tipo;

T➡char.      T.type = char
T ➡ boolean  T.type = boolean
T➡int        T.type = int
T➡id         T.type = id

### Garantir que o retorno de uma função possui o mesmo tipo do que foi declarado;

### Garantir que o tipo da variável é igual ao da expressão de atribuição;



### Garantir que não seja possivel acessar índice maior do que o declarado: (ok)

#### Exemplo

```Fortram
  INTEGER A[32] 
  A = 0xFFFFFFF
	PRINT A[100]
```

#### Grámatica de atributos

```c
  var_stat: VAR ID SIZE (ASSIGN exp)? { ID[0].size = SIZE[0].size} ;
	param: ID SIZE { ID[0].size = SIZE[0].size } ;
  assign_stat: ID INTV? ASSIGN exp { INTV[0].upperbound <= ID[0].size };
```


OBS: NUMBER.val e NUMBEREXP.max_val como esta no exemplo passado em aula pelo professor


### Garantir que a chamada de função respeita o número de argumentos especificado:

#### Exemplo:

```Fortram
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
```

### Garantir que não seja possivel acessar variável não declarada:

#### Exemplo:

```Fortram
  CHAR A[32] = B
```

#### Grámatica de atributos

```c
	exp : ( '(' exp ')' | BIN | HEX | ID | call_stat ) INTV?
	      { lookup(ID) != null }
;
```


### Garantir que não seja possivel acessar variável não iniciada:

#### Exemplo:
```Fortram
	INTEGER A, B
	A = B
```

#### Grámatica de atributos

```c
	exp : ( '(' exp ')' | BIN | HEX | ID | call_stat ) INTV? 
	      { lookup(ID.val) != null }
;
```

### Garantir que não seja possivel chamar função não declarada:

#### Exemplo

```Fortram
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
	call_stat: ID '(' ( exp ( ',' exp )* )? ')' 
	           { lookup(ID) != null } ;
```

### Garantir que seja imposivel atribuir valores de tamanho maior para variáveis:

#### Exemplo

```Fortram
	CHAR A[32] <- 0xFFFFFFF
	CHAR B <- A
```

#### Gramática de atributos

```c
  var_stat:     VAR ID SIZE (ASSIGN exp)? 
                { SIZE.size >= exp.size } 
                ;
	assign_stat:  ID INTV? ASSIGN exp 
	              { ID[0].size >= exp[0].size } 
	              ;
	exp:          'NOT' exp 
	              { exp.size = exp[0].size }
                | exp '^' NUMBER 
                  { exp.size = exp[0].size * NUMBER.val } 
                | exp '<<' NUMBER 
                  { exp.size = exp[0].size }
                | exp '>>' NUMBER 
                  { exp.size = exp[0].size }
								| exp '.' exp 
								  { exp.size = exp[0].size + exp[1].size }
								| exp 'XOR' exp 
								  { exp.size = max(exp[0].size, exp[1].size) }

							  | exp 'AND' exp 
							    { exp.size = max(exp[0].size, exp[1].siz e) }
								| exp 'OR' exp 
								  { exp.size = max(exp[0].size, exp[1].size )}
								|(
								|'(' exp ')' 
								  { exp.size = exp[0].size }
								| BIN 
								  { exp.size = BIN[0].size }
								| HEX 
								  { exp.size = HEX[0].size }
								| ID 
								  { exp.size = ID[0].size }
								| call_stat 
								  { exp.size = call_stat[0].return_size }
								) INTV? 
								  { exp.size <= INTV[0].upperbound & exp.size = IN
								TV[0].upperbound }
								;
								call_stat: ID '(' ( exp ( ',' exp )* )? ')' 
								           { 
								           	 lookup(ID[0].type) == 'func' & call_stat.return_size = lookup(ID[0].return_s ize) 
								           	}
								;
``` 

### Garantir que não seja possivel declarar duas variáveis com o mesmo nome:


#### Exemplo

```Fortram
	INTEGER A
	CHAR A
```

#### Gramática de atributos

```c
  var_stat: VAR ID SIZE (ASSIGN exp)? 
            { lookup(ID[0]) == null } ;
```

### Garantir que não seja possivel declarar duas funções com o mesmo nome:

#### Exemplo

```Fortram
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
func_stat
: FUNC ID '(' ( param ( ',' param )* )? ')' SIZE ':' sui
te { lookup(ID[0]) == null } ;
```




Declarar variavel com nome de função
Foi comtemplado nos dois aspectos anteriores
Váraveis do for são apenas usadas dentro do intervalo




