# Geração de Código da Linguagem F666


A geração de código é o processo pelo qual um compilador converte a *Representação Intermediária* (RI) de um código fonte em um formato executável por uma máquina. Neste projeto, utilizamos o LLVM (Low Level Virtual Machine) para a geração de código.

No compilador desenvolvido, a árvore de sintaxe abstrata (AST) gerada pelo *bison* é utilizada como entrada para o gerador de código. A árvore é convertida em uma seqüência de instruções segundo uma RI do LLVM. O LLVM suporta três formas isomórficas de RIs:

* Formato de objetos de C++
* Formato bitcode (para serialização)
* Formato *assembly* (`asm`)

O primeiro desses formatos foi parcialmente [implementado](https://github.com/makhles/f666/blob/master/src/codegen.cpp), porém não foi possível configurar a biblioteca do LLVM corretamente. Escolheu-se, então, utilizar o formato `asm`.


## Geração do Código Intermediário

Cada nó da árvore AST possui um método responsável pela geração de uma parte do código em `asm`:

```C++
    std::string generateCode(std::ofstream &ofs);
``` 

Alguns nós simplesmente imprimem o código gerado diretamente num arquivo chamado `code.ll` (através do objeto do tipo *stream* `ofs`); outros, além da impressão, retornam alguma variável temporária para seus nós antecessores. Citam-se como exemplos desse último caso os nós `Expression` e `Comparison`. Os métodos foram implementados no arquivo [`LLVM_AssemblyGenerator.cpp`](https://github.com/makhles/f666/blob/slave/src/LLVM_AssemblyGenerator.cpp).

A seguir são exemplificados trechos de código gerados segundo o `asm` do LLVM.




## Declarações de Variáveis
## Atribuições
## Expressões Algébricas
## Chamada de Funções




## Desvios

### Código em `Fortran 666`

```Fortran
INTEGER FUNCTION B(A,C)
INTEGER A, B, C, D
B = A + C * 2
IF (B .EQ. A) THEN
  D = A / C
ENDIF
RETURN
END
```

### Código em `C++` usado no site `ellcc.org`

```C++
int b(int a, int c)
{
  int b, d;
  b = a + c * 2;
  if (b == a) {
    d = a/c;
  }
  return b;
}
```



### Código gerado em _assembly_ do LLVM

```
define i32 @B(i32, i32) #0 {
  %3 = alloca i32, align 4              ;  var A
  store i32 %0, i32* %3, align 4
  %4 = alloca i32, align 4              ;  var B
  %5 = alloca i32, align 4              ;  var C
  store i32 %1, i32* %5, align 4
  %6 = alloca i32, align 4              ;  var D
  %7 = load i32, i32* %3, align 4       ;  var A
  %8 = load i32, i32* %5, align 4       ;  var C
  %9 = mul i32 %8, 2
  %10 = add i32 %7, %9
  store i32 %10, i32* %4, align 4
  %11 = load i32, i32* %4, align 4      ;  var B
  %12 = load i32, i32* %3, align 4      ;  var A
  %13 = icmp eq i32 %11, %12
  br i1 %13, label %14, label %15

; <label>:14:
  %16 = load i32, i32* %3, align 4      ;  var A
  %17 = load i32, i32* %5, align 4      ;  var C
  %18 = sdiv i32 %16, %17
  store i32 %18, i32* %6, align 4
  br label %15

; <label>:15:
  ret i32 %4
}
```

### Código gerado no site `ellcc.org`

```
define i32 @_Z1bii(i32, i32) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %7 = load i32, i32* %3, align 4
  %8 = load i32, i32* %4, align 4
  %9 = mul nsw i32 %8, 2
  %10 = add nsw i32 %7, %9
  store i32 %10, i32* %5, align 4
  %11 = load i32, i32* %5, align 4
  %12 = load i32, i32* %3, align 4
  %13 = icmp eq i32 %11, %12
  br i1 %13, label %14, label %18

; <label>:14:                                     ; preds = %2
  %15 = load i32, i32* %3, align 4
  %16 = load i32, i32* %4, align 4
  %17 = sdiv i32 %15, %16
  store i32 %17, i32* %6, align 4
  br label %18

; <label>:18:                                     ; preds = %14, %2
  %19 = load i32, i32* %5, align 4
  ret i32 %19
}
```


## Estrutura de Seleção `IF-THEN-ELSE`
## Estrutura de Repetição `DO`