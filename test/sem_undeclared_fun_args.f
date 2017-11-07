INTEGER FUNCTION C(I,J,K,M)
INTEGER C, I, L
L = 5
C = I * L
RETURN
END

PROGRAM A
INTEGER B, I, J
DO I = 1, 10
J = I + 1
B = C(I,J,3,5)
ENDDO
STOP
END

// Programa teste que não declara os argumentos
// recebidos na função C
