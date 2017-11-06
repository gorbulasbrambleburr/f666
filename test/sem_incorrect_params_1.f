INTEGER FUNCTION C(M,N)
INTEGER C, M, N
C = M * N

RETURN END

INTEGER FUNCTION D()
INTEGER D
D = 10
RETURN
END


PROGRAM A
INTEGER B, I, J
DO I = 1, 10
J = I + 1
B = C(I) + D(J)
ENDDO
STOP
END

// Programa teste que verifica a chamada de uma função
// com um número incorreto de parâmetros
