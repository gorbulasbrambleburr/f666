#pragma once

#include <string>
#include "AST.hpp"

class MainProgram : public AST {
public:
    MainProgram(node_ptr id, node_ptr body)
        : _id(id), _body(body) {
    }
    ~MainProgram();
    std::string print() const {
        std::string code = "MainProgram (" + _name + ")\n";
        for (AST *child : children) {
            if (child != nullptr) {
                code += " " + child->print() + "\n";
            }
        }
        return code;
    }

private:
    ode_ptr _id;
    node_ptr _body;
};
