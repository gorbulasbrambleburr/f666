#ifndef __AST_ELSEIF_STATEMENT_HPP__
#define __AST_ELSEIF_STATEMENT_HPP__

#include "AST.hpp"

class ElseIfStatement : public AST {
public:
    ElseIfStatement(node_ptr condition, node_ptrs&& statements)
        : m_condition(std::move(condition)),
          m_statements(std::forward<node_ptrs>(statements)) {
    }
    ~ElseIfStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Condition:" << std::endl;
        m_condition->print(width + 4);
        std::cout << std::setw(width) << "- " << "Body:" << std::endl;
        if (m_statements.empty()) {
            std::cout << std::setw(width + 4) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_statements) {
                child->print(width + 4);
            }
        }
    }
    void acceptCodeGenerator(CodeGenerator &generator) override {
        generator.generateCode(*this);
    }

private:
    node_ptr m_condition;
    node_ptrs m_statements;
};

#endif /* END __AST_ELSEIF_STATEMENT_HPP__ */