#ifndef __ENTRY__
#define __ENTRY__

#include "Types.hpp"
#include "ast/AST.hpp"
#include "Parameter.hpp"

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
          std::vector<Parameter> params = {})
        : m_type(type), m_dimension(dimension), m_symbol(symbol), m_params(params) {
    }

    virtual ~Entry() {}
    Fortran::vartype::type type() const { return m_type; }
    Fortran::structural::type dimension() const { return m_dimension; }
    Fortran::symbol::type symbol() const { return m_symbol; }
    std::vector<Parameter> params() const { return m_params; }

private:
    Fortran::vartype::type m_type;
    Fortran::structural::type m_dimension;
    Fortran::symbol::type m_symbol;
    std::vector<Parameter> m_params;
};

#endif /* END __ENTRY__ */