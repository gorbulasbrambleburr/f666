#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__

#include <string>
#include "AST.hpp"

class Type : public AST {
public:
    Type(int type)
        : m_type("int") {
    }
    Type(float type)
        : m_type("float") {
    }
    Type(bool type)
        : m_type("bool") {
    }
    ~Type() {}
    void print() const {
        std::cout << "Type (" << m_type << ")" << std::endl;
    }

private:
    std::string m_type;
};

#endif /* END __AST_TYPE_HPP__ */