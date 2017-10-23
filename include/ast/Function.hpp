#ifndef __AST_FUNCTION_HPP__
#define __AST_FUNCTION_HPP__

#include "AST.hpp"

class Function : public AST {
public:
    Function(node_ptr type, node_ptr id, node_ptrs params, node_ptr body)
        : m_type(std::move(type)), m_id(std::move(id)), m_params(std::forward<node_ptrs>(params)), m_body(std::move(body)) {
    }
    ~Function() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Function:" << std::endl;
        m_type->print(width + 4);
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "params:" << std::endl;
        for (auto& param : m_params) {
            param->print(width + 8);
        }
        m_body->print(width + 4);
    }

private:
    node_ptr m_type;
    node_ptr m_id;
    node_ptrs m_params;
    node_ptr m_body;
};

#endif /* END __AST_FUNCTION_HPP__ */