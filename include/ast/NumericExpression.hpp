#ifndef __AST_NUMERIC_EXPRESSION_HPP__
#define __AST_NUMERIC_EXPRESSION_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

class NumericExpression : public AST {
public:
    NumericExpression(node_ptr left, Fortran::op::arithmetic op, node_ptr right)
        : m_left(std::move(left)), m_operator(op), m_right(std::move(right)) {
    }
    ~NumericExpression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "NumericExpression:" << std::endl;
        std::cout << std::setw(width + 4) << "- ";
        printOp();
        m_left->print(width + 8);
        m_right->print(width + 8);
    }
    void printOp() const {
        switch (m_operator) {
            case (Fortran::op::arithmetic::ADD): std::cout << "ADD:" << std::endl; break;
            case (Fortran::op::arithmetic::SUB): std::cout << "SUB:" << std::endl; break;
            case (Fortran::op::arithmetic::DIV): std::cout << "DIV:" << std::endl; break;
            case (Fortran::op::arithmetic::MUL): std::cout << "MUL:" << std::endl; break;
        }
    }

private:
    node_ptr m_left = nullptr;
    Fortran::op::arithmetic m_operator;
    node_ptr m_right = nullptr;
};

#endif /* END __AST_NUMERIC_EXPRESSION_HPP__ */