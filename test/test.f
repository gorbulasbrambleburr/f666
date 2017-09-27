PROGRAM TESTE
PARAMETER (X = .FALSE.)
PARAMETER (X = W .GT. Z)
INTEGER X, Y
REAL W, Z

STOP
END

//------------------------------------------

SUBROUTINE B()
INTEGER X, Y
PARAMETER (X = 5 * 3 + 4)
RETURN
END

//------------------------------------------

INTEGER FUNCTION C()
REAL W, Z, X
PARAMETER (Z = W + 2)
RETURN
END