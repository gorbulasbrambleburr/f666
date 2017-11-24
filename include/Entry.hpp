#ifndef __ENTRY__
#define __ENTRY__

#include "Types.hpp"
#include "ast/AST.hpp"

class Entry {

public:

    using node_ptr = std::shared_ptr<AST>;
    using node_ptrs = std::vector<node_ptr>;

    // Constructor used for variables
    Entry(Fortran::vartype::type type = Fortran::vartype::type::INTEGER,
          Fortran::structural::type dimension = Fortran::structural::type::SCALAR,
          Fortran::symbol::type symbol = Fortran::symbol::type::VARIABLE)
            : m_type(type), m_dimension(dimension), m_symbol(symbol) {
    }

    // Constructor used for Subprograms
    Entry(Fortran::symbol::type symbol = Fortran::symbol::type::UNDECLARED,
          Fortran::vartype::type type = Fortran::vartype::type::INTEGER,
          Fortran::structural::type dimension = Fortran::structural::type::SCALAR,
          std::map<std::string, Fortran::vartype::type> argTypes = {},
          node_ptrs args = {})
            : m_type(type), m_dimension(dimension), m_symbol(symbol),
              m_argTypes(argTypes), m_args(args) {
    }

    virtual ~Entry() {}
    Fortran::vartype::type type() const { return m_type; }
    Fortran::structural::type dimension() const { return m_dimension; }
    Fortran::symbol::type symbol() const { return m_symbol; }
    std::map<std::string, Fortran::vartype::type> arg_types() const { return m_argTypes; }
    node_ptrs args() const { return m_args; }

private:
    Fortran::vartype::type m_type;
    Fortran::structural::type m_dimension;
    Fortran::symbol::type m_symbol;
    std::map<std::string, Fortran::vartype::type> m_argTypes;
    node_ptrs m_args;
};

#endif /* END __ENTRY__ */