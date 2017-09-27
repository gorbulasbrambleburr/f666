#ifndef __AST_LITERAL_HPP__
#define __AST_LITERAL_HPP__

#include "AST.hpp"
#include "../Types.hpp"

class Literal : public AST {
public:
    Literal(int value, Fortran::type type = Fortran::type::INTEGER)
        : m_iValue(value), m_type(type) {
    }
    Literal(float value, Fortran::type type = Fortran::type::REAL)
        : m_fValue(value), m_type(type) {
    }
    Literal(bool value, Fortran::type type = Fortran::type::BOOLEAN)
        : m_bValue(value), m_type(type) {
    }
    ~Literal() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Literal: ";
        switch (m_type) {
            case (Fortran::type::INTEGER): std::cout << "INTEGER [" << m_iValue << "]" << std::endl; break;
            case (Fortran::type::REAL): std::cout << "REAL [" << m_fValue << "]" << std::endl; break;
            case (Fortran::type::BOOLEAN): std::cout << "BOOLEAN [" << m_bValue << "]" << std::endl; break;
        }
    }

private:
    int m_iValue;
    float m_fValue;
    bool m_bValue;
    Fortran::type m_type;
};

#endif /* END __AST_LITERAL_HPP__ */