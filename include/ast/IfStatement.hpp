#ifndef __AST_IF_STATEMENT_HPP__
#define __AST_IF_STATEMENT_HPP__

#include "AST.hpp"

class IfStatement : public AST {
public:
    IfStatement(node_ptr condition, node_ptrs&& ifStatements, node_ptrs&& elseIfStatements, node_ptrs&& elseStatements)
        : m_condition(std::move(condition)),
          m_ifStatements(std::forward<node_ptrs>(ifStatements)),
          m_elseIfStatements(std::forward<node_ptrs>(elseIfStatements)),
          m_elseStatements(std::forward<node_ptrs>(elseStatements)) {
    }
    ~IfStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "IfStatement" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "IF" << std::endl;
        std::cout << std::setw(width + 8) << "- " << "condition:" << std::endl;
        m_condition->print(width + 12);
        std::cout << std::setw(width + 8) << "- " << "body:" << std::endl;
        for (auto &child : m_ifStatements) {
            child->print(width + 12);
        }
        for (auto &child : m_elseIfStatements) {
            std::cout << std::setw(width + 4) << "- " << "ELSEIF" << std::endl;
            child->print(width + 8);
        }
        std::cout << std::setw(width + 4) << "- " << "ELSE" << std::endl;
        for (auto &child : m_elseStatements) {
            child->print(width + 8);
        }
    }

private:
    node_ptr m_condition;
    node_ptrs m_ifStatements;
    node_ptrs m_elseIfStatements;
    node_ptrs m_elseStatements;
};

#endif /* END __AST_IF_STATEMENT_HPP__ */