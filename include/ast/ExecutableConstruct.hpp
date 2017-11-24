#ifndef __AST_EXECUTABLE_CONSTRUCT_HPP__
#define __AST_EXECUTABLE_CONSTRUCT_HPP__

#include "AST.hpp"

class ExecutableConstruct : public AST {
public:
    ExecutableConstruct(node_ptrs&& statements)
        : m_statements(std::forward<node_ptrs>(statements)) {
    }
    ~ExecutableConstruct() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "ExecutableConstruct:" << std::endl;
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
    node_ptrs m_statements;
};

#endif /* END __AST_EXECUTABLE_CONSTRUCT_HPP__ */