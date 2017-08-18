PROGRAM RAIN
REAL R, T, SUM
INTEGER M

READ T
SUM = 0.0
DO 10 M = 1, 12
   SUM = SUM + R(M, T)
ENDDO
PRINT 'Annual rainfall is ', SUM, ' inches.'

STOP
END


// Compute the amount of rain R in the month M

REAL FUNCTION R(M,T)
INTEGER M
REAL T

R = 0.1*T * (M*(M+14) + 46)
IF (R .LT. 0) THEN
   R = 0.0
ENDIF

RETURN
END