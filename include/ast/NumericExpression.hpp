#ifndef __AST_NUMERIC_EXPRESSION_HPP__
#define __AST_NUMERIC_EXPRESSION_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

using arithmetic_op = Fortran::op::arithmetic;

class NumericExpression : public AST {
public:
    NumericExpression(node_ptr expr, arithmetic_op op, node_ptr factor)
        : m_expr(std::move(expr)), m_operator(op), m_factor(std::move(factor)) {
    }
    NumericExpression(node_ptr factor)
        : m_factor(std::move(factor)) {
    }
    ~NumericExpression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "NumericExpression:" << std::endl;
        if (m_expr != nullptr) {
            m_expr->print(width + 4);
            std::cout << std::setw(width) << "- ";
            printOp();
        }
        m_factor->print(width + 4);
    }
    void printOp() const {
        switch (m_operator) {
            case (arithmetic_op::ADD): std::cout << "ADD" << std::endl; break;
            case (arithmetic_op::SUB): std::cout << "SUB" << std::endl; break;
            case (arithmetic_op::DIV): std::cout << "DIV... something wrong!" << std::endl; break;
            case (arithmetic_op::MUL): std::cout << "MUL... something wrong!" << std::endl; break;
        }
    }

private:
    node_ptr m_expr = nullptr;
    arithmetic_op m_operator;
    node_ptr m_factor = nullptr;
};

#endif /* END __AST_NUMERIC_EXPRESSION_HPP__ */