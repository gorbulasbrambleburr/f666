#ifndef __AST_IDENTIFIER_HPP__
#define __AST_IDENTIFIER_HPP__

#include <string>
#include "AST.hpp"
#include "../Types.hpp"

class Identifier : public AST {
public:
    Identifier(const std::string& id, Fortran::symbol::type symbol = Fortran::symbol::type::VARIABLE)
        : m_id(id), m_symbol(symbol) {
    }
    ~Identifier() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "id: " << m_id << std::endl;
        std::cout << std::setw(width) << "- " << "type: " << str(m_symbol) << std::endl;
    }
    std::string str(Fortran::symbol::type type) const {
        std::string s;
        switch (type) {
            case (Fortran::symbol::type::UNDECLARED): s = "UNDECLARED"; break; 
            case (Fortran::symbol::type::VARIABLE): s = "VARIABLE"; break; 
            case (Fortran::symbol::type::FUNCTION): s = "FUNCTION"; break; 
            case (Fortran::symbol::type::SUBROUTINE): s = "SUBROUTINE"; break; 
            case (Fortran::symbol::type::PROGRAM): s = "PROGRAM"; break; 
        }
        return s;
    }
    const std::string& id() const { 
        return m_id;
    }
    Fortran::symbol::type symbol_type() const { return m_symbol; }
    virtual llvm::Value* codeGen(CodeGenContext& context);

private:
    std::string m_id;
    Fortran::symbol::type m_symbol;
};

#endif /* END __AST_IDENTIFIER_HPP__ */