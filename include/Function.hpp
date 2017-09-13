#pragma once

#include <string>
#include <vector>
#include "Types.hpp"

class Function : public AST {
public:
    Function(ast::type type, std::string name)
        : _type(type), _name(name) {
    }
    virtual ~Function();
    virtual std::string print() const {
        std::string code = "Function (name = " + _name + ", type = " + _type + ")\n";
        for (AST *child : children) {
            if (child != nullptr) {
                code += " " + child->print() + "\n";
            }
        }
        return code;
    }

private:
    std::string _name;
    ast::type _type;
};
