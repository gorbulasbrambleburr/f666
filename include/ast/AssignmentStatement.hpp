#ifndef __AST_ASSIGNMENT_STATEMENT_HPP__
#define __AST_ASSIGNMENT_STATEMENT_HPP__

#include "AST.hpp"
#include "../Types.hpp"

using stype = Fortran::structural::type;

class AssignmentStatement : public AST {
public:
    AssignmentStatement(node_ptr id, node_ptr expression, stype type = stype::SCALAR)
        : m_id(std::move(id)), m_expression(std::move(expression)), m_type(type) {
    }
    AssignmentStatement(node_ptr id, node_ptr elementExpression, node_ptr expression, stype type = stype::ARRAY)
        : m_id(std::move(id)), m_elementExpression(std::move(elementExpression)), m_expression(std::move(expression)), m_type(type) {
    }
    ~AssignmentStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "AssignmentStatement:" << std::endl;
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "Structural type: ";
        switch (m_type) {
            case (stype::SCALAR): {
                std::cout << "SCALAR" << std::endl;
                break;
            }
            case (stype::ARRAY): {
                std::cout << "ARRAY" << std::endl;
                m_elementExpression->print(width + 4);
                break;
            }
        }
        m_expression->print(width + 4);
    }
    void acceptCodeGenerator(CodeGenerator &generator) override {
        generator.generateCode(*this);
    }

private:
    node_ptr m_id;
    node_ptr m_elementExpression;
    node_ptr m_expression;
    stype m_type;

};

#endif /* END __AST_ASSIGNMENT_STATEMENT_HPP__ */