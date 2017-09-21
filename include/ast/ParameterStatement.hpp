#ifndef __AST_PARAMETER_STATEMENT_HPP__
#define __AST_PARAMETER_STATEMENT_HPP__

#include "AST.hpp"

class ParameterStatement : public AST {
public:
    ParameterStatement(node_ptrs&& constants)
        : m_constants(std::forward<node_ptrs>(constants)) {
    }
    ~ParameterStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "ParameterStatement:" << std::endl;
        if (m_constants.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_constants) {
                child->print(width + 4);
            }
        }
    }

private:
    node_ptrs m_constants;
};

#endif /* END __AST_PARAMETER_STATEMENT_HPP__ */