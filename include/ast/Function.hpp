#ifndef __AST_FUNCTION_HPP__
#define __AST_FUNCTION_HPP__

#include "AST.hpp"

class Function : public AST {
public:
    Function(node_ptr type, node_ptr id, node_ptrs args, node_ptr body)
        : m_type(std::move(type)), m_id(std::move(id)), m_args(std::forward<node_ptrs>(args)), m_body(std::move(body)) {
    }
    ~Function() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Function:" << std::endl;
        m_type->print(width + 4);
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "args:" << std::endl;
        for (auto& arg : m_args) {
            arg->print(width + 8);
        }
        m_body->print(width + 4);
    }
    void acceptCodeGenerator(CodeGenerator &generator) override {
        generator.generateCode(*this);
    }

private:
    node_ptr m_type;
    node_ptr m_id;
    node_ptrs m_args;
    node_ptr m_body;
};

#endif /* END __AST_FUNCTION_HPP__ */