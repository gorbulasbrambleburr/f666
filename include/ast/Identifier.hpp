#ifndef __AST_IDENTIFIER_HPP__
#define __AST_IDENTIFIER_HPP__

#include <string>
#include "AST.hpp"

class Identifier : public AST {
public:
    Identifier(std::string id)
        : m_id(id) {
    }
    ~Identifier() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "id [" << m_id << "]" << std::endl;
    }

private:
    std::string m_id;
};

#endif /* END __AST_IDENTIFIER_HPP__ */