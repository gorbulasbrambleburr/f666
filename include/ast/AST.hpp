#pragma once

#include <string>
#include <vector>
#include "Types.hpp"

using node_ptr = std::unique_ptr<AST>;
using node_ptrs = std::vector<node_ptr>;

class AST {
public:
    AST();
    virtual ~AST();
    virtual std::string print() const;

protected:
    std::vector<std::unique_ptr<AST>> children;
};
