PROGRAM 
INTEGER B

IF (X .GT. 10) THEN
    Y = X * 2
ELSEIF (X .GT. 5) THEN
    Y = X * 3
ELSEIF (X .EQ. 5) THEN
    Y = X * 5
ELSE
    Y = X
ENDIF

STOP END

SUBROUTINE RETURN END
SUBROUTINE ( RETURN END
SUBROUTINE ) RETURN END

SUBROUTINE A RETURN END
SUBROUTINE A ( RETURN END
SUBROUTINE A ) RETURN END
SUBROUTINE A (B,) RETURN END


FUNCTION A(B,C) RETURN END