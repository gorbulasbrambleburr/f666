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
        std::cout << std::setw(width) << "- " << "IF" << std::endl;
        std::cout << std::setw(width + 4) << "- " << "Condition:" << std::endl;
        m_condition->print(width + 8);
        std::cout << std::setw(width + 4) << "- " << "Body:" << std::endl;
        if (m_ifStatements.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_ifStatements) {
                child->print(width + 4);
            }
        }
        if (m_elseIfStatements.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_elseIfStatements) {
                std::cout << std::setw(width) << "- " << "ELSEIF" << std::endl;
                child->print(width + 4);
            }
        }
        std::cout << std::setw(width) << "- " << "ELSE" << std::endl;
        if (m_elseStatements.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_elseStatements) {
                child->print(width + 4);
            }
        }
    }

private:
    node_ptr m_condition;
    node_ptrs m_ifStatements;
    node_ptrs m_elseIfStatements;
    node_ptrs m_elseStatements;
};

#endif /* END __AST_IF_STATEMENT_HPP__ */