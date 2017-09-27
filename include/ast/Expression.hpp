#ifndef __AST_EXPRESSION_HPP__
#define __AST_EXPRESSION_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

class Expression : public AST {
public:
    Expression(node_ptr left, node_ptr right, Fortran::op::arithmetic op)
        : m_left(std::move(left)), m_right(std::move(right)), m_operator(op) {
    }
    ~Expression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Expression:" << std::endl;
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
            default: break;
        }
    }

private:
    node_ptr m_left = nullptr;
    node_ptr m_right = nullptr;
    Fortran::op::arithmetic m_operator;
};

#endif /* END __AST_EXPRESSION_HPP__ */