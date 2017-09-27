#ifndef __AST_NUMBER_HPP__
#define __AST_NUMBER_HPP__

#include "AST.hpp"
#include "../Types.hpp"

class Number : public AST {
public:
    Number(int value, Fortran::type type = Fortran::type::INTEGER)
        : m_iValue(value), m_type(type) {
    }
    Number(float value, Fortran::type type = Fortran::type::REAL)
        : m_fValue(value), m_type(type) {
    }
    ~Number() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Number:" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "Value: ";
        switch (m_type) {
            case (Fortran::type::INTEGER): std::cout << m_iValue << std::endl; break;
            case (Fortran::type::REAL): std::cout << m_fValue << std::endl; break;
            case (Fortran::type::BOOLEAN): std::cout << "Boolean value... something wrong!" << std::endl; break;
        }
    }

private:
    int m_iValue;
    float m_fValue;
    Fortran::type m_type;
};

#endif /* END __AST_NUMBER_HPP__ */