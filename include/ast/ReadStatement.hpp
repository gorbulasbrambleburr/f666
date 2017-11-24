#ifndef __AST_READ_STATEMENT_HPP__
#define __AST_READ_STATEMENT_HPP__

#include "AST.hpp"

class ReadStatement : public AST {
public:
    ReadStatement(node_ptrs&& arguments)
        : m_arguments(std::forward<node_ptrs>(arguments)) {
    }
    ~ReadStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "ReadStatement:" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "arguments: " << std::endl;
        for (auto &child : m_arguments) {
            child->print(width + 8);
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptrs m_arguments;
};

#endif /* END __AST_READ_STATEMENT_HPP__ */