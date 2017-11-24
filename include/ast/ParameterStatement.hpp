#ifndef __AST_PARAMETER_STATEMENT_HPP__
#define __AST_PARAMETER_STATEMENT_HPP__

#include "AST.hpp"

class ParameterStatement : public AST {
public:
    ParameterStatement(node_ptrs&& assignments)
        : m_assignments(std::forward<node_ptrs>(assignments)) {
    }
    ~ParameterStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "ParameterStatement:" << std::endl;
        if (m_assignments.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_assignments) {
                child->print(width + 4);
            }
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptrs m_assignments;
};

#endif /* END __AST_PARAMETER_STATEMENT_HPP__ */