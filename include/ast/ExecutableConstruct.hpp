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
        for (auto &child : m_statements) {
            child->print(width + 4);
        }
    }

    void addChild(node_ptr child) {
        m_statements.emplace_back(std::move(child));
    }

private:
    node_ptrs m_statements;
};

#endif /* END __AST_EXECUTABLE_CONSTRUCT_HPP__ */