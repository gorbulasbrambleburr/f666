#pragma once

#include <string>
#include "AST.hpp"

class ExecutableProgram : public AST {
public:
    ExecutableProgram(node_ptrs subprograms)
        : _subprograms(subprograms) {
    }
    virtual ~ExecutableProgram();
    virtual std::string print() const {
        std::string code = "ExecutableProgram\n";
        for (AST *child : children) {
            if (child != nullptr) {
                code += " " + child.print() + "\n";
            }
        }
        return code;
    }

private:
    node_ptrs _subprograms;
};
