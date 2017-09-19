#ifndef __AST_SPECIFICATION_CONSTRUCT_HPP__
#define __AST_SPECIFICATION_CONSTRUCT_HPP__

#include "AST.hpp"

class SpecificationConstruct : public AST {
public:
    SpecificationConstruct(node_ptrs&& specifications)
        : m_specifications(std::forward<node_ptrs>(specifications)) {
    }
    ~SpecificationConstruct() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "SpecificationConstruct:" << std::endl;
        for (auto &child : m_specifications) {
            child->print(width + 4);
        }
    }

    void addChild(node_ptr child) {
        m_specifications.emplace_back(std::move(child));
    }

private:
    node_ptrs m_specifications;
};

#endif /* END __AST_SPECIFICATION_CONSTRUCT_HPP__ */