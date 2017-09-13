#pragma once

#include <string>
#include <vector>

class AST {
public:
    AST();
    virtual ~AST();
    virtual std::string print() const;

protected:
    std::vector<std::unique_ptr<AST>> children;
};
