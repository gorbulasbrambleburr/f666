#ifndef __FTYPES_HPP__
#define __FTYPES_HPP__

#include <string>

namespace Fortran {

    namespace vartype {
        enum class type {
            INTEGER,
            REAL,
            BOOLEAN,
        };
    }

    using type = vartype::type;
    using integer = int;
    using real = float;
    using boolean = bool;
    using string = std::string;
}

#endif /* __FTYPES_HPP__ */