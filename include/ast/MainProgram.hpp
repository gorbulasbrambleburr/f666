#pragma once

#include <string>
#include "AST.hpp"

class MainProgram : public AST {
public:
    MainProgram(std::string name)
        : _name(name) {
    }
    virtual ~MainProgram();
    virtual std::string print() const {
        std::string code = "MainProgram (" + _name + ")\n";
        for (AST *child : children) {
            if (child != nullptr) {
                code += " " + child->print() + "\n";
            }
        }
        return code;
    }

private:
    std::string _name;
};
