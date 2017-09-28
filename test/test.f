PROGRAM TESTE
PARAMETER (X = .FALSE.)
PARAMETER (X = W .GT. Z)
INTEGER X, Y, E, F
REAL W, Z

E = 10
F = E + W

IF (X .GT. 10) THEN
    Y = X * 2
ELSEIF (X .GT. 5) THEN
    Y = X * 3
ELSEIF (X .EQ. 5) THEN
    Y = X * 5
ELSE
    Y = X
ENDIF


STOP
END

//------------------------------------------

SUBROUTINE B()
INTEGER X, Y
PARAMETER (X = 5 * 3 + 4)
PARAMETER (Y = 666)
RETURN
END

//------------------------------------------

INTEGER FUNCTION C()
REAL W, Z, X
BOOLEAN B
PARAMETER (Z = W + 2)

IF (B) THEN
    X = Z
ELSE
    X = W
ENDIF

RETURN
END