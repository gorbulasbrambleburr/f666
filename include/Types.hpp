#ifndef __FTYPES_HPP__
#define __FTYPES_HPP__

#include <type_traits>

namespace Fortran {

    namespace vartype {
        enum class type {
            INTEGER,
            REAL,
            BOOLEAN,
            STRING,
            UNDECLARED,
        };
    }

    namespace structural {
        enum class type {
            SCALAR,
            ARRAY,
        };
    }

    namespace symbol {
        enum class type {
            UNDECLARED,
            VARIABLE,
            FUNCTION,
            SUBROUTINE,
            PROGRAM,
        };
    }

    using type = vartype::type;
    using integer = int;
    using real = double;
    using boolean = bool;
    using string = std::string;
}

#endif /* __FTYPES_HPP__ */