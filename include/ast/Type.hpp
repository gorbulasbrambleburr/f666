#ifndef __AST_TYPE_HPP__
#define __AST_TYPE_HPP__

#include <string>
#include "AST.hpp"

class Type : public AST {
public:
    Type(std::string &id)
        : m_id(id) {
    }
    ~Type() {}
    void print() const {
        std::cout << "ID (" << m_id << ")" << std::endl;
    }

private:
    std::string m_id;
};

#endif /* END __AST_TYPE_HPP__ */