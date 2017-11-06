PROGRAM A
INTEGER B
B = C(10)
STOP END

INTEGER FUNCTION C(A)
INTEGER A, C
C = A * 2
RETURN END

// Programa teste que faz referência a uma
// função que não foi declarada antes da chamada

// TODO:
// verificar se é feita alguma atribuição à variável que é a própria função
