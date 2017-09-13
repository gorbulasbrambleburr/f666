#pragma once

#include <string>
#include "AST.hpp"

class Function : public AST {
public:
    Function(node_ptr type, node_ptr id, node_ptr params, node_ptr body)
        : _type(type), _id(id), _params(params), _body(body) {
    }
    virtual ~Function();
    virtual std::string print() const {
        std::string code = "- Function\n";
        for (AST *child : children) {
            if (child != nullptr) {
                code += " " + child->print() + "\n";
            }
        }
        return code;
    }

private:
    node_ptr _type;
    node_ptr _id;
    node_ptr _params;
    node_ptr _body;
};
