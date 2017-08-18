PROGRAM MATRIX_MULTIPLICATION

INTEGER I, M, N
LOGICAL ORDER_OK

PARAMETER (M = 10)
ORDER_OK = .FALSE.

INTEGER A(M,M), B(M,M), C(M,M)

WHILE (ORDER_OK .EQ. .FALSE.) DO
    PRINT 'Enter the order of the matrices (n <= ', M, ')'
    READ N
    IF (N .LE. 10) THEN
        ORDER_OK = .TRUE.
    ENDIF
ENDDO

CALL MATMUL(N,A,B,C)

PRINT 'Result:'
DO I = 1, N
    DO J = 1, N
        PRINT C(I, J)
    ENDDO
ENDDO

STOP
END


// Matrix multiplication

FUNCTION MATMUL(N, A, B, C)
INTEGER N
INTEGER A(N,N), B(N,N), C(N,N)

// Local variables

INTEGER I, J, K, TEMP

DO I = 1, N
    DO J = 1, N
        TEMP = 0
        DO K = 1, N
            TEMP = TEMP + A(I,K) * B(K,J)
        ENDDO
        C(I,J) = TEMP
    ENDDO
ENDDO

RETURN
END