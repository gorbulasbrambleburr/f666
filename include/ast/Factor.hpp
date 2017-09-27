#ifndef __AST_FACTOR_HPP__
#define __AST_FACTOR_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

using arithmetic_op = Fortran::op::arithmetic;

class Factor : public AST {
public:
    Factor(node_ptr factor, arithmetic_op op, node_ptr term)
        : m_factor(std::move(factor)), m_operator(op), m_term(std::move(term)) {
    }
    Factor(node_ptr term)
        : m_term(std::move(term)) {
    }
    ~Factor() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Factor:" << std::endl;
        if (m_factor != nullptr) {
            m_factor->print(width + 4);
            std::cout << std::setw(width) << "- ";
            printOp();
        }
        m_term->print(width + 4);
    }
    void printOp() const {
        switch (m_operator) {
            case (arithmetic_op::DIV): std::cout << "DIV" << std::endl; break;
            case (arithmetic_op::MUL): std::cout << "MUL" << std::endl; break;
            case (arithmetic_op::ADD): std::cout << "ADD... something wrong!" << std::endl; break;
            case (arithmetic_op::SUB): std::cout << "SUB... something wrong!" << std::endl; break;
        }
    }

private:
    node_ptr m_factor = nullptr;
    arithmetic_op m_operator;
    node_ptr m_term = nullptr;
};

#endif /* END __AST_FACTOR_HPP__ */