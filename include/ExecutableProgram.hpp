#pragma once

#include <string>
#include <vector>

class ExecutableProgram : public AST {
public:
    ExecutableProgram();
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

};
