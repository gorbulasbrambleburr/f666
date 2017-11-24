#ifndef __AST_EXPRESSION_HPP__
#define __AST_EXPRESSION_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

class Expression : public AST {
public:
    Expression(node_ptr left, node_ptr right, Fortran::op::arithmetic op)
            : m_left(std::move(left)), m_right(std::move(right)), m_operator(op) {
        m_logic = false;
    }
    Expression(node_ptr left, node_ptr right, Fortran::op::logic op)
            : m_left(std::move(left)), m_right(std::move(right)), m_logicOp(op) {
        m_logic = true;
    }
    Expression(node_ptr right, Fortran::op::logic op)
            : m_left(nullptr), m_right(std::move(right)), m_logicOp(op) {
        m_logic = true;
    }
    ~Expression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Expression:" << std::endl;
        std::cout << std::setw(width + 4) << "- ";
        printOp();
        if (m_left != nullptr) {
            m_left->print(width + 8);
        }
        m_right->print(width + 8);
    }
    void printOp() const {
        if (m_logic) {
            switch (m_logicOp) {
                case (Fortran::op::logic::AND): std::cout << "AND:" << std::endl; break;
                case (Fortran::op::logic::OR) : std::cout << "OR:"  << std::endl; break;
                case (Fortran::op::logic::NOT): std::cout << "NOT:" << std::endl; break;
                default: break;
            }
        } else {
            switch (m_operator) {
                case (Fortran::op::arithmetic::ADD): std::cout << "ADD:" << std::endl; break;
                case (Fortran::op::arithmetic::SUB): std::cout << "SUB:" << std::endl; break;
                case (Fortran::op::arithmetic::DIV): std::cout << "DIV:" << std::endl; break;
                case (Fortran::op::arithmetic::MUL): std::cout << "MUL:" << std::endl; break;
                default: break;
            }
        }
    }
    Fortran::vartype::type var_type() const {
        if (m_logic) {
            return Fortran::vartype::type::BOOLEAN;
        } else {
            return m_right->var_type();
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_left = nullptr;
    node_ptr m_right = nullptr;
    Fortran::op::arithmetic m_operator;
    Fortran::op::logic m_logicOp;
    bool m_logic;
};

#endif /* END __AST_EXPRESSION_HPP__ */