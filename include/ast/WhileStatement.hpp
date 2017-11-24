#ifndef __AST_WHILE_STATEMENT_HPP__
#define __AST_WHILE_STATEMENT_HPP__

#include "AST.hpp"

class WhileStatement : public AST {
public:
    WhileStatement(node_ptr expr, node_ptrs&& statements)
        : m_expr(std::move(expr)),
          m_statements(std::forward<node_ptrs>(statements)) {
    }
    ~WhileStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "WhileStatement:" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "expr: " << std::endl;
        m_expr->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "body: " << std::endl;
        for (auto &child : m_statements) {
            child->print(width + 8);
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_expr;
    node_ptrs m_statements;
};

#endif /* END __AST_WHILE_STATEMENT_HPP__ */