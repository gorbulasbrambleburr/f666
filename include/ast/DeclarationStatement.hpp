#ifndef __AST_DECLARATION_STATEMENT_HPP__
#define __AST_DECLARATION_STATEMENT_HPP__

#include "AST.hpp"

class DeclarationStatement : public AST {
public:
    DeclarationStatement(node_ptr type, node_ptrs&& ids)
        : m_type(std::move(type)), m_ids(std::forward<node_ptrs>(ids)) {
    }
    ~DeclarationStatement() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "DeclarationStatement:" << std::endl;
        m_type->print(width + 4);
        for (auto &child : m_ids) {
            child->print(width + 4);
        }
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_type;
    node_ptrs m_ids;
};

#endif /* END __AST_DECLARATION_STATEMENT_HPP__ */