#ifndef __AST_TERM_HPP__
#define __AST_TERM_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

using arithmetic_op = Fortran::op::arithmetic;

class Term : public AST {
public:
    Term(node_ptr expr)
        : m_expr(expr) {
    }
    Term(arithmetic_op op, node_ptr term)
        : m_sign(op), m_term(std::move(term)) {
    }
    ~Term() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Term:" << std::endl;
        if (m_expr != nullptr) {
            m_expr->print(width + 4);
        }
        if (m_term != nullptr) {
            std::cout << std::setw(width) << "- " << "Sign:";
            printOp();
            m_term->print(width + 4);
        }
    }
    void printOp() const {
        switch (m_sign) {
            case (arithmetic_op::ADD): std::cout << "+" << std::endl; break;
            case (arithmetic_op::SUB): std::cout << "-" << std::endl; break;
            case (arithmetic_op::DIV): std::cout << "DIV... something wrong!" << std::endl; break;
            case (arithmetic_op::MUL): std::cout << "MUL... something wrong!" << std::endl; break;
        }
    }

private:
    node_ptr m_expr = nullptr;
    arithmetic_op m_sign;
    node_ptr m_term = nullptr;
};

#endif /* END __AST_TERM_HPP__ */