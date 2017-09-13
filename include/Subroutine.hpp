#pragma once

#include <string>
#include <vector>

class Subroutine : public AST {
public:
    Subroutine(std::string name)
        : _name(name) {
    }
    virtual ~Subroutine();
    virtual std::string print() const {
        std::string code = "Subroutine (" + _name + ")\n";
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
