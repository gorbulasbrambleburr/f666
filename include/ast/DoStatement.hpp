#ifndef __AST_DO_STATEMENT_HPP__
#define __AST_DO_STATEMENT_HPP__

#include "AST.hpp"

class DoStatement : public AST {
public:
    DoStatement(node_ptr id, node_ptr varExpr, node_ptr boundExpr, node_ptr incExpr, node_ptrs&& statements)
        : m_id(std::move(id)),
          m_varExpr(std::move(varExpr)),
          m_boundExpr(std::move(boundExpr)),
          m_incExpr(std::move(incExpr)),
          m_statements(std::forward<node_ptrs>(statements)) {
    }
    ~DoStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "DoStatement:" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "var: " << std::endl;
        m_id->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "var_expr: " << std::endl;
        m_varExpr->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "var_bound: " << std::endl;
        m_boundExpr->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "var_incr: " << std::endl;
        m_incExpr->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "body: " << std::endl;
        for (auto &child : m_statements) {
            child->print(width + 4);
        }
    }
    virtual std::string generateCode(std::ofstream &ofs);

private:
    node_ptr m_id;
    node_ptr m_varExpr;
    node_ptr m_boundExpr;
    node_ptr m_incExpr;
    node_ptrs m_statements;
};

#endif /* END __AST_DO_STATEMENT_HPP__ */