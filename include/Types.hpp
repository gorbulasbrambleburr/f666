namespace ast {

    using type = vartype::type;

    enum {
        PROGRAM,
        SUBROUTINE,
        FUNCTION,
        STOP,
        RETURN,
        END,
        PARAMETER,
        CYCLE,
        EXIT,
        IF,
        ELSE,
        ELSEIF,
        ENDIF,
        WHILE,
        DO,
        ENDDO,
        PRINT,
        READ,
        CALL
    };

    namespace vartype {
        enum class type {
            INTEGER,
            REAL
        };
    }

    enum {
        SIGN_SUM,
        SIGN_SUB,
        SIGN_TIMES,
        SIGN_DIV
    };

    enum {
        REL_EQ,
        REL_NE,
        REL_GT,
        REL_GE,
        REL_LT,
        REL_LE
    };

    enum {
        BOOL_TRUE,
        BOOL_FALSE
    };

    enum {
        ASSIGN,
        COMMA,
        LP,
        RP
    }
};