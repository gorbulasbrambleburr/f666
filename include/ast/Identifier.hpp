#ifndef __AST_IDENTIFIER_HPP__
#define __AST_IDENTIFIER_HPP__

#include <string>
#include "AST.hpp"

class Identifier : public AST {
public:
    Identifier(std::string &id)
        : m_id(id) {
    }
    ~Identifier() {}
    void print() const {
        std::cout << "ID (" << m_id << ")" << std::endl;
    }

private:
    std::string m_id;
};

#endif /* END __AST_IDENTIFIER_HPP__ */