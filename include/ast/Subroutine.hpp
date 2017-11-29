#ifndef __AST_SUBROUTINE_HPP__
#define __AST_SUBROUTINE_HPP__

#include "AST.hpp"

class Subroutine : public AST {
public:
    Subroutine(node_ptr id, node_ptrs&& args, node_ptr body)
        : m_id(std::move(id)), m_args(std::forward<node_ptrs>(args)), m_body(std::move(body)) {
    }
    ~Subroutine() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Subroutine:" << std::endl;
        m_id->print(width + 4);
        for (auto& param : m_args) {
            param->print(width + 4);
        }
        m_body->print(width + 4);
    }
    virtual std::string generateCode(std::ofstream &ofs);

private:
    node_ptr m_id;
    node_ptrs m_args;
    node_ptr m_body;
};

#endif /* END __AST_SUBROUTINE_HPP__ */