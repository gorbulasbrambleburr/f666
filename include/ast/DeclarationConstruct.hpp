#ifndef __AST_DECLARATION_CONSTRUCT_HPP__
#define __AST_DECLARATION_CONSTRUCT_HPP__

#include "AST.hpp"

class DeclarationConstruct : public AST {
public:
    DeclarationConstruct(node_ptrs&& declarations)
        : m_declarations(std::forward<node_ptrs>(declarations)) {
    }
    ~DeclarationConstruct() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "DeclarationConstruct:" << std::endl;
        for (auto &child : m_declarations) {
            child->print(width + 4);
        }
    }

    void addChild(node_ptr child) {
        m_declarations.emplace_back(std::move(child));
    }

private:
    node_ptrs m_declarations;
};

#endif /* END __AST_DECLARATION_CONSTRUCT_HPP__ */