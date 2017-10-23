#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>  // For std::setw(int n)
#include "../Types.hpp"

class AST {

public:
    using node_ptr = std::shared_ptr<AST>;
    using node_ptrs = std::vector<node_ptr>;

    AST() {}
    virtual ~AST() {}
    virtual void print(int width) const {}
    virtual void addChild(node_ptr child) {}
};

#endif /* END __AST_HPP__ */