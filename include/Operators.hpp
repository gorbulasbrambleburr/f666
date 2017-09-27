#ifndef __FOPERATORS_HPP__
#define __FOPERATORS_HPP__

namespace Fortran {
    namespace op {
        enum class arithmetic {
            ADD,
            SUB,
            DIV,
            MUL,
        };

        enum class comp {
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
            NOT,
        };

        enum class assignment {
            DIRECT,
            ADD,
            SUB,
            DIV,
            MULT,
        };
    }
}

#endif /* __FOPERATORS_HPP__ */