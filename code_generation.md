# Geração de Código da Linguagem F666


A geração de código é o processo pelo qual um compilador converte a *Representação Intermediária* (RI) de um código fonte em um formato executável por uma máquina. Neste projeto, utilizamos o LLVM (Low Level Virtual Machine) para a geração de código.

No compilador desenvolvido, a árvore de sintaxe abstrata (AST) gerada pelo *bison* é utilizada como entrada para o gerador de código. A árvore é convertida em uma seqüência de instruções segundo uma RI do LLVM. O LLVM suporta três formas isomórficas de RIs:

* Formato de objetos de C++
* Formato bitcode (para serialização)
* Formato *assembly* (`asm`)

O primeiro desses formatos foi parcialmente [implementado](https://github.com/makhles/f666/blob/master/src/codegen.cpp), porém não foi possível configurar a biblioteca do LLVM corretamente. Escolheu-se, então, utilizar o formato `asm`.






<!--- ####################################################################  -->
## Geração de Código Executável

Dado um arquivo de representação intermediária de um código fonte, `code.ll`, é possível obter-se um arquivo objeto utilizando-se o compilador estático do LLVM, [`llc`](https://llvm.org/docs/CommandGuide/llc.html):

```
    llc -filetype=obj code.ll
```

O arquivo objeto gerado, `code.o`, é um arquivo em `assembly` na arquitetura definida no arquivo de entrada. Este arquivo pode ser transformado em um arquivo executável com o auxílio do ligador do sistema. No caso do linux, utiliza-se o `g++`:

```
    g++ -o code.o
```

O compilador estático do LLVM, no entanto, não aceita qualquer arquivo de RI. Existem algumas regras para a nomeação de variáveis temporárias e *labels* que não estão explícitas no [manual de referência](https://releases.llvm.org/3.8.0/docs/LangRef.html). Embora algumas dessas regras tenham sido detectadas e aplicadas no arquivo de RI gerado pelo compilador Fortran 666, uma das regras implicaria na mudança de boa parte do código, pois se relaciona com a ordem de percorrimento da árvore AST e, portanto, não foi aplicada ao código.

Decidiu-se por utilizar a ferramenta de geração de código em RI do [ELLCC](http://ellcc.org/demo/index.cgi) e fazer a comparação dos códigos gerados. Dado um código em `C/C++`, a ferramenta utilizada gera o código `asm` do LLVM.





<!--- ####################################################################  -->
## Geração do Código Intermediário

Cada nó da árvore AST possui um método responsável pela geração de uma parte do código em `asm`:

```C++
    std::string generateCode(std::ofstream &ofs);
``` 

Alguns nós simplesmente imprimem o código gerado diretamente num arquivo chamado `code.ll` (através do objeto do tipo *stream* `ofs`); outros, além da impressão, retornam alguma variável temporária para seus nós antecessores. Citam-se como exemplos desse último caso os nós `Expression` e `Comparison`. Os métodos foram implementados no arquivo [`LLVM_AssemblyGenerator.cpp`](https://github.com/makhles/f666/blob/slave/src/LLVM_AssemblyGenerator.cpp).

A seguir são exemplificados trechos de código em `asm` do LLVM gerados pelo compilador Fortran 666 e pela ferramenta ELLCC.






<!--- ####################################################################  -->
### Declarações de Variáveis

Código em Fortran 666:

```Fortran
    INTEGER FUNCTION A()
    INTEGER A, I, J
    RETURN
    END
```

Código equivalente em C++:

```C++
    int main() {
        int i, j;
        return 0;
    }
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
    define i32 @A() #0 {
      %1 = alloca i32, align 4              ;  var A
      %2 = alloca i32, align 4              ;  var I
      %3 = alloca i32, align 4              ;  var J
      ret i32 %1
    }
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
    define i32 @main() #0 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      %3 = alloca i32, align 4
      store i32 0, i32* %1, align 4
      ret i32 0
    }
```

Percebe-se que em ambos os códigos gerados são alocadas as variáveis temporárias `%2` e `%3` para as variáveis `i` e `j`, respectivamente. No caso da linguagem Fortran 666, deve existir uma variável com o nome da própria função (`A`) que deve ser declarada em seu corpo e que será utilizada como retorno (`%1`). No caso do C++, o retorno é independente do nome da função, porém aloca-se uma variável temporária (`%1`) de qualquer maneira e armazena-se o valor `0`.



<!--- ####################################################################  -->
### Atribuições

Código em Fortran 666:
```Fortran
    PROGRAM A
    INTEGER I
    REAL J
    I = 10
    J = 2.0
    STOP
    END
```

Código equivalente em C++:

```C++
    int main() {
        int i;
        double j;
        i = 10;
        j = 2.0;
        return 0;
    }
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
    define i32 @A() #0 {
      %1 = alloca i32, align 4              ;  var A
      %2 = alloca i32, align 4              ;  var I
      %3 = alloca double, align 8           ;  var J
      store i32 10, i32* %2, align 4
      store double 2.000000, double* %3, align 8
      ret i32 %1
    }
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
    define i32 @main() #0 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      %3 = alloca double, align 8
      store i32 0, i32* %1, align 4
      store i32 10, i32* %2, align 4
      store double 2.000000e+00, double* %3, align 8
      ret i32 0
    }
```

Pode-se perceber que, exceto pela representação em formato científico de variáveis de ponto flutuante e do `store` de `0` na variável de retorno `%1`, os códigos gerados são equivalentes.



<!--- ####################################################################  -->
### Expressões Algébricas

Código em Fortran 666:
```Fortran
    INTEGER FUNCTION A()
    INTEGER A, I, J
    I = 5
    J = (3 + I) * 2 + 1
    RETURN
    END
```

Código equivalente em C++:
```C++
    int main() {
        int i, j;
        i = 5;
        j = (3 + i) * 2 + 1;
        return 0;
    }
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
    define i32 @A() #0 {
      %1 = alloca i32, align 4              ;  var A
      %2 = alloca i32, align 4              ;  var I
      %3 = alloca i32, align 4              ;  var J
      store i32 5, i32* %2, align 4
      %4 = load i32, i32* %2, align 4       ;  var I
      %5 = add i32 3, %4
      %6 = mul i32 %5, 2
      %7 = add i32 %6, 1
      store i32 %7, i32* %3, align 4
      ret i32 %1
    }
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
    define i32 @main() #0 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      %3 = alloca i32, align 4
      store i32 0, i32* %1, align 4
      store i32 5, i32* %2, align 4
      %4 = load i32, i32* %2, align 4
      %5 = add nsw i32 3, %4
      %6 = mul nsw i32 %5, 2
      %7 = add nsw i32 %6, 1
      store i32 %7, i32* %3, align 4
      ret i32 0
    }
```

Aqui novamente, com exceção do `store` de `0` na variável de retorno `%1`, os códigos gerados são equivalentes.



<!--- ####################################################################  -->
### Chamada de Funções

Código em Fortran 666:
```Fortran
INTEGER FUNCTION SUM(X,Y)
INTEGER SUM, X, Y
SUM = X + Y
RETURN
END

PROGRAM MAIN
INTEGER I, J, K
I = 5
J = 2
K = SUM(I, J)
STOP
END
```

Código equivalente em C++:
```C++
    int sum(int x, int y) {
        int sum;
        sum = x + y;
        return sum;
    }

    int main() {
        int i, j, k;
        i = 5;
        j = 2;
        k = sum(i,j);
        return 0;
    }
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
    define i32 @SUM(i32, i32) #0 {
      %3 = alloca i32, align 4              ;  var SUM
      %4 = alloca i32, align 4              ;  var X
      store i32 %0, i32* %4, align 4
      %5 = alloca i32, align 4              ;  var Y
      store i32 %1, i32* %5, align 4
      %6 = load i32, i32* %4, align 4       ;  var X
      %7 = load i32, i32* %5, align 4       ;  var Y
      %8 = add i32 %6, %7
      store i32 %8, i32* %3, align 4
      ret i32 %3
    }

    define @MAIN() #1 {
      %1 = alloca i32, align 4              ;  var I
      %2 = alloca i32, align 4              ;  var J
      %3 = alloca i32, align 4              ;  var K
      store i32 5, i32* %1, align 4
      store i32 2, i32* %2, align 4
      %4 = call i32 @SUM(i32 %1, i32 %3)
      store i32 %4, i32* %3, align 4
    }
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
    define i32 @_Z3sumii(i32, i32) #0 {
      %3 = alloca i32, align 4
      %4 = alloca i32, align 4
      %5 = alloca i32, align 4
      store i32 %0, i32* %3, align 4
      store i32 %1, i32* %4, align 4
      %6 = load i32, i32* %3, align 4
      %7 = load i32, i32* %4, align 4
      %8 = add nsw i32 %6, %7
      store i32 %8, i32* %5, align 4
      %9 = load i32, i32* %5, align 4
      ret i32 %9
    }

    ; Function Attrs: noinline norecurse nounwind optnone
    define i32 @main() #1 {
      %1 = alloca i32, align 4
      %2 = alloca i32, align 4
      %3 = alloca i32, align 4
      %4 = alloca i32, align 4
      store i32 0, i32* %1, align 4
      store i32 5, i32* %2, align 4
      store i32 2, i32* %3, align 4
      %5 = load i32, i32* %2, align 4
      %6 = load i32, i32* %3, align 4
      %7 = call i32 @_Z3sumii(i32 %5, i32 %6)
      store i32 %7, i32* %4, align 4
      ret i32 0
    }
```

Percebe-se que o código `asm` gerado pelo compilador Fortran 666 faz o `store` dos argumentos de funções tão logo quanto são alocadas variáveis temporárias para estes, enquanto que o compilador ELLCC primeiro faz a alocação e depois os `store`s. Ainda, pode-se perceber uma certa otimização no primeiro código gerado, visto que não são feitos `load`s desnecessários de variáveis temporárias antes da chamada de funções.



<!--- ####################################################################  -->
### Desvios

Código em Fortran 666:
```Fortran
```

Código equivalente em C++:
```C++
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
```





<!--- ####################################################################  -->
### Estrutura de Seleção `IF-THEN-ELSE`

Código em Fortran 666:
```Fortran
```

Código equivalente em C++:
```C++
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
```





<!--- ####################################################################  -->
### Estrutura de Repetição `DO`

Código em Fortran 666:
```Fortran
```

Código equivalente em C++:
```C++
```

Código `asm` gerado pelo compilador Fortran 666:
```LLVM
```

Código `asm` gerado pelo compilador ELLCC:
```LLVM
```