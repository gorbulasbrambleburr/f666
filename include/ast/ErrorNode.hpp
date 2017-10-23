#ifndef __AST_ERROR_NODE_HPP__
#define __AST_ERROR_NODE_HPP__

#include "AST.hpp"

class ErrorNode : public AST {
public:
    ErrorNode(std::string &message)
        : m_message(message) {
    }
    ~ErrorNode() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "id: " << m_message << std::endl;
    }

private:
    std::string m_message;

};

#endif /* END __AST_ERROR_NODE_HPP__ */