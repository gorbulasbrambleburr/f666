#ifndef __AST_COMPARISON_HPP__
#define __AST_COMPARISON_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

class Comparison : public AST {
public:
    Comparison(node_ptr left, node_ptr right, Fortran::op::comp op)
        : m_left(std::move(left)), m_right(std::move(right)), m_operator(op) {
    }
    ~Comparison() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Comparison: " << std::endl;
        std::cout << std::setw(width + 4) << "- ";
        printOp();
        m_left->print(width + 8);
        m_right->print(width + 8);
    }
    void printOp() const {
        switch (m_operator) {
            case (Fortran::op::comp::EQ): std::cout << ".EQ." << std::endl; break;
            case (Fortran::op::comp::NE): std::cout << ".NE." << std::endl; break;
            case (Fortran::op::comp::LT): std::cout << ".LT." << std::endl; break;
            case (Fortran::op::comp::LE): std::cout << ".LE." << std::endl; break;
            case (Fortran::op::comp::GT): std::cout << ".GT." << std::endl; break;
            case (Fortran::op::comp::GE): std::cout << ".GE." << std::endl; break;
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_left = nullptr;
    node_ptr m_right = nullptr;
    Fortran::op::comp m_operator;
};

#endif /* END __AST_COMPARISON_HPP__ */