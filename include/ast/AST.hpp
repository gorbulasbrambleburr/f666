#pragma once

#include <string>
#include <vector>
#include "Types.hpp"

#define std::unique_ptr<AST> node_ptr
#define std::vector<node_ptr> node_ptrs

class AST {
public:
    AST();
    virtual ~AST();
    virtual std::string print() const;

protected:
    std::vector<std::unique_ptr<AST>> children;
};
