namespace Fortran {
    struct op {
        enum class arithmetic {
            ADD,
            SUB,
            DIV,
            MULT
        };

        enum class comparison {
            LT,
            GT,
            LE,
            GE,
            EQ,
            NE,
        };

        enum class logic {
            AND,
            OR,
            NOT
        };

        enum class assignment {
            DIRECT,
            ADD,
            SUB,
            DIV,
            MULT
        };
    };
};