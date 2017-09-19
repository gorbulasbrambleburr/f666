#ifndef __AST_BODY_HPP__
#define __AST_BODY_HPP__

#include "AST.hpp"

class Body : public AST {
public:
    Body(node_ptrs&& constructs)
        : m_constructs(constructs) {
    }
    ~Body() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Body:" << std::endl;
        for (auto& construct : m_constructs) {
            construct->print(width + 4);
        }
    }

private:
    node_ptrs m_constructs;
};

#endif /* END __AST_BODY_HPP__ */