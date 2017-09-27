#ifndef __AST_LOGICAL_EXPRESSION_HPP__
#define __AST_LOGICAL_EXPRESSION_HPP__

#include "AST.hpp"
#include "../Operators.hpp"

using comp_op = Fortran::op::comp;

class LogicalExpression : public AST {
public:
    LogicalExpression(node_ptr leftExpression, comp_op op, node_ptr rightExpression)
        : m_leftExpression(leftExpression), m_operator(op), m_rightExpression(rightExpression) {
    }
    LogicalExpression(bool logicalConstant) : m_logicalConstant(logicalConstant) {
    }
    ~LogicalExpression() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "LogicalExpression:" << std::endl;
        if (m_leftExpression != nullptr) {
            m_leftExpression->print(width + 4);
            std::cout << std::setw(width + 4) << "- ";
            printOp();
            m_rightExpression->print(width + 4);
        } else {
            std::cout << std::setw(width + 4) << "- " << "Constant value: "
                 << (m_logicalConstant == 1 ? "TRUE" : "FALSE") << std::endl;
        }
    }
    void printOp() const {
        switch (m_operator) {
            case (comp_op::EQ): std::cout << "EQ" << std::endl; break;
            case (comp_op::NE): std::cout << "NE" << std::endl; break;
            case (comp_op::LT): std::cout << "LT" << std::endl; break;
            case (comp_op::LE): std::cout << "LE" << std::endl; break;
            case (comp_op::GT): std::cout << "GT" << std::endl; break;
            case (comp_op::GE): std::cout << "GE" << std::endl; break;
        }
    }

private:
    node_ptr m_leftExpression = nullptr;
    comp_op m_operator;
    node_ptr m_rightExpression = nullptr;
    bool m_logicalConstant;
};

#endif /* END __AST_LOGICAL_EXPRESSION_HPP__ */