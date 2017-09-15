namespace ast {

    using type = vartype::type;
    using integer = int;
    using real = float;

    namespace vartype {
        enum class type {
            INTEGER,
            REAL,
            BOOLEAN
        };
    }
};