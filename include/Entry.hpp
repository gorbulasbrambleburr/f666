#ifndef __ENTRY__
#define __ENTRY__

#include "Types.hpp"

class Entry {

public:
    //using node_ptrs = std::list<node_ptr>;

    Entry(Fortran::vartype::type type,
          Fortran::structural::type dimension = Fortran::structural::type::SCALAR,
          Fortran::symbol::type symbol = Fortran::symbol::type::VARIABLE)
            : m_type(type), m_dimension(dimension), m_symbol(symbol) {}
    virtual ~Entry() {}
    Fortran::vartype::type type() const { return m_type; }
    Fortran::structural::type dimension() const { return m_dimension; }
    Fortran::symbol::type symbol() const { return m_symbol; }

private:
    Fortran::vartype::type m_type;
    Fortran::structural::type m_dimension;
    Fortran::symbol::type m_symbol;
};
    

#endif /* END __ENTRY__ */