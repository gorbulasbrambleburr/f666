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
        std::cout << std::setw(width) << "- " << "Type:" << str(m_type) << std::endl;
    }
    std::string str(Fortran::type type) const {
        std::string s;
        switch (type) {
            case (Fortran::type::INTEGER): s = "INTEGER"; break; 
            case (Fortran::type::REAL): s = "REAL"; break; 
            case (Fortran::type::BOOLEAN): s = "BOOLEAN"; break; 
        }
        return s;
    }

private:
    const Fortran::type m_type;
};

#endif /* END __AST_TYPE_HPP__ */