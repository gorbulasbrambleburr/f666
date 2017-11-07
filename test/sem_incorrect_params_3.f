INTEGER FUNCTION C(M,N)
INTEGER C, M, N
C = M * N
RETURN
END


PROGRAM A
INTEGER B, I
REAL J
DO I = 1, 10, 1
J = 3.5
B = C(I,L)
ENDDO
STOP
END

// Programa teste que verifica a chamada de uma função
// com um parâmetro não declarado.
