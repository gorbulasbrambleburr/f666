#ifndef __AST_CALL_STATEMENT_HPP__
#define __AST_CALL_STATEMENT_HPP__

#include "AST.hpp"

class CallStatement : public AST {
public:
    CallStatement(node_ptr id, node_ptrs&& params)
        : m_id(std::move(id)),
          m_params(std::forward<node_ptrs>(params)) {
    }
    ~CallStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "CallStatement" << std::endl;
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "params:" << std::endl;
        if (m_params.empty()) {
            std::cout << std::setw(width + 8) << "- " << "EMPTY" << std::endl;
        } else {
            for (auto &child : m_params) {
                child->print(width + 8);
            }
        }
    }
private:
    node_ptr m_id;
    node_ptrs m_params;
};

#endif /* END __AST_CALL_STATEMENT_HPP__ */