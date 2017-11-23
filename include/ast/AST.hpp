#ifndef __AST_HPP__
#define __AST_HPP__

#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>  // For std::setw(int n)
#include <llvm/IR/Value.h>
#include "../Types.hpp"

class AST {

public:
    using node_ptr = std::shared_ptr<AST>;
    using node_ptrs = std::vector<node_ptr>;

    AST() {}
    virtual ~AST() {}
    virtual void print(int width) const {}
    virtual void addChild(node_ptr child) {}
    virtual const std::string& id() const { return m_bleh; }
    virtual Fortran::vartype::type var_type() const {
        return Fortran::vartype::type::INTEGER;
    }
    virtual Fortran::structural::type struct_type() const {
        return Fortran::structural::type::SCALAR;
    }
    virtual Fortran::symbol::type symbol_type() const {
        return Fortran::symbol::type::UNDECLARED;
    }
    virtual llvm::Value* codeGen(CodeGenContext& context) {}

private:
    std::string m_bleh;
};

#endif /* END __AST_HPP__ */