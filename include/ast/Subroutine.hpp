#ifndef __AST_SUBROUTINE_HPP__
#define __AST_SUBROUTINE_HPP__

#include "AST.hpp"

class Subroutine : public AST {
public:
    Subroutine(node_ptr id, node_ptrs&& params, node_ptr body)
        : m_id(std::move(id)), m_params(std::forward<node_ptrs>(params)), m_body(std::move(body)) {
    }
    ~Subroutine() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Subroutine:" << std::endl;
        m_id->print(width + 4);
        for (auto& param : m_params) {
            param->print(width + 4);
        }
        m_body->print(width + 4);
    }
    virtual llvm::Value* codeGen(CodeGenContext& context);

private:
    node_ptr m_id;
    node_ptrs m_params;
    node_ptr m_body;
};

#endif /* END __AST_SUBROUTINE_HPP__ */