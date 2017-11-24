#ifndef __AST_BODY_HPP__
#define __AST_BODY_HPP__

#include "AST.hpp"

class Body : public AST {
public:
    Body(node_ptr specificationConstruct, node_ptr executionConstruct)
        : m_specificationConstruct(specificationConstruct),
          m_executionConstruct(executionConstruct) {
    }
    ~Body() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "Body:" << std::endl;
        m_specificationConstruct->print(width + 4);
        m_executionConstruct->print(width + 4);
    }
    virtual void generateCode(std::ofstream &ofs);

private:
    node_ptr m_specificationConstruct;
    node_ptr m_executionConstruct;
};

#endif /* END __AST_BODY_HPP__ */