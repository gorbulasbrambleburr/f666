#ifndef __AST_FUNCTION_CALL_HPP__
#define __AST_FUNCTION_CALL_HPP__

#include "AST.hpp"
#include "../Mapper.hpp"

class FunctionCall : public AST {
public:
    FunctionCall(node_ptr id, node_ptrs&& args)
        : m_id(std::move(id)), m_args(std::forward<node_ptrs>(args)) {
    }
    ~FunctionCall() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "FunctionCall:" << std::endl;
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "args:" << std::endl;
        for (auto &child : m_args) {
            child->print(width + 8);
        }
    }
    const std::string& id() const {
        return m_id->id();
    }
    Fortran::vartype::type var_type() const {
        return Mapper::instance().fun_entry(m_id->id()).type();
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_id;
    node_ptrs m_args;
};

#endif /* END __AST_FUNCTION_CALL_HPP__ */