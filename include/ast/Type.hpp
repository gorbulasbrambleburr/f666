#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__

#include "AST.hpp"
#include "../Types.hpp"

class Type : public AST {
public:
    Type(const Fortran::type &type)
        : m_type(type) {
    }
    ~Type() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Type:" << str() << std::endl;
    }
    std::string str() const {
        std::string s;
        switch (m_type) {
            case (Fortran::type::INTEGER): s = "INTEGER"; break; 
            case (Fortran::type::REAL): s = "REAL"; break; 
            case (Fortran::type::BOOLEAN): s = "BOOLEAN"; break; 
            case (Fortran::type::STRING): s = "STRING"; break; 
            case (Fortran::type::UNDECLARED): s = "UNDECLARED"; break;
        }
        return s;
    }
    Fortran::vartype::type var_type() const { return m_type; }

private:
    const Fortran::type m_type;
};

#endif /* END __AST_TYPE_HPP__ */