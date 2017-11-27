#include <string>   // For std::to_string()
#include <iomanip>  // For std::setw(int n)
#include "LLVM_AssemblyGenerator.hpp"
#include "ast/ExecutableProgram.hpp"
#include "ast/MainProgram.hpp"
#include "ast/Function.hpp"
#include "ast/Subroutine.hpp"
#include "ast/Body.hpp"
#include "ast/SpecificationConstruct.hpp"
#include "ast/ExecutableConstruct.hpp"
#include "ast/DeclarationStatement.hpp"
#include "ast/IdentifierDeclaration.hpp"
#include "ast/Type.hpp"
#include "ast/ParameterStatement.hpp"
#include "ast/AssignmentStatement.hpp"
#include "ast/Expression.hpp"
#include "ast/Comparison.hpp"
#include "ast/FunctionCall.hpp"
#include "ast/Literal.hpp"
#include "ast/Identifier.hpp"
#include "ast/IfStatement.hpp"
#include "ast/ElseIfStatement.hpp"
#include "ast/DoStatement.hpp"
#include "ast/WhileStatement.hpp"
#include "ast/PrintStatement.hpp"
#include "ast/ReadStatement.hpp"
#include "ast/CallStatement.hpp"
#include "ast/ErrorNode.hpp"
#include "Entry.hpp"
#include "Mapper.hpp"

static unsigned int addr;
static std::map<std::string, std::string> var_addr;

// Utilities ------------------------------------------------------------------

std::string next_addr() {
    return "%" + std::to_string(addr++);
}

void reset_addr() {
    addr = 0;
    var_addr.clear();
}

std::string typeOf(Fortran::type type) {
    std::string str;
    switch (type) {
        case (Fortran::type::INTEGER): str = "i32"; break; 
        case (Fortran::type::REAL): str = "double"; break; 
        case (Fortran::type::BOOLEAN): str = "i1"; break; 
        case (Fortran::type::STRING): str = ""; break; 
        case (Fortran::type::UNDECLARED): str = ""; break;
    }
    return str;
}

// Returns the alignment
// Doesn't work for strings and undeclared types
std::string align(Fortran::type type) {
    unsigned int align;
    switch (type) {
        case (Fortran::type::INTEGER): align = 4; break; 
        case (Fortran::type::REAL): align = 8; break; 
        case (Fortran::type::BOOLEAN): align = 1; break; 
        default: align = 1; break;
    }
    return std::to_string(align);
}

// Class methods --------------------------------------------------------------

LLVM_AssemblyGenerator::LLVM_AssemblyGenerator() {
    addr = 0;
}

void LLVM_AssemblyGenerator::generateCode(node_ptr &root) {
    std::ofstream ofs("./ir/code.txt", std::ofstream::out);
    root->generateCode(ofs);
    ofs.close();
}

// Node implementations -------------------------------------------------------

void ExecutableProgram::generateCode(std::ofstream &ofs) {
    ofs << "target datalayout = \"e-m:e-i64:64-f80:128-n8:16:32:64-S128\""
        << std::endl;
    ofs << "target triple = \"x86_64-samsung-linux\"" << std::endl;
    ofs << std::endl;
    for (auto& subprogram : m_subprograms) {
        subprogram->generateCode(ofs);
        ofs << std::endl;
        reset_addr();
    }
}

void MainProgram::generateCode(std::ofstream &ofs) {
    ofs << "define @";
    m_id->generateCode(ofs);
    ofs << "() #1 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << "}" << std::endl;
}

void Function::generateCode(std::ofstream &ofs) {
    ofs << "define ";
    m_type->generateCode(ofs);
    ofs << " @";
    m_id->generateCode(ofs);
    ofs << "(";
    
    Entry entry = Mapper::instance().fun_entry(m_id->id());
    std::vector<Parameter> params = entry.params();
    for (unsigned int i = 0; i < params.size(); i++) {
        ofs << typeOf(params[i].type());
        next_addr();
        if (i != params.size()-1) {
            ofs << ", ";
        }
    }
    ofs << ") #0 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << "}" << std::endl;
}

void Subroutine::generateCode(std::ofstream &ofs) {
    ofs << "define void @";
    m_id->generateCode(ofs);
    ofs << "(";
    
    Entry entry = Mapper::instance().fun_entry(m_id->id());
    std::vector<Parameter> params = entry.params();
    for (unsigned int i = 0; i < params.size(); i++) {
        ofs << typeOf(params[i].type());
        next_addr();
        if (i != params.size()-1) {
            ofs << ", ";
        }
    }
    ofs << ") #0 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << "}" << std::endl;
}

void Body::generateCode(std::ofstream &ofs) {
    m_specificationConstruct->generateCode(ofs);
    m_executionConstruct->generateCode(ofs);
}

// Contains a list of DeclarationStatement and/or ParameterStatement
void SpecificationConstruct::generateCode(std::ofstream &ofs) {
    for (auto& spec : m_specifications) {
        spec->generateCode(ofs);
    }
}

void ExecutableConstruct::generateCode(std::ofstream &ofs) {

}

// Contains a Type and a list of IdentifierDeclaration
// Only works for scalar variables
void DeclarationStatement::generateCode(std::ofstream &ofs) {
    for (auto& var : m_ids) {
        std::string addr = next_addr();
        var_addr.insert(std::pair<std::string, std::string>(var->id(), addr));
        ofs << std::setw(4) << addr << " = alloca " << typeOf(m_type->var_type())
            << ", align " << align(m_type->var_type())
            << " ; for var " << var->id() << std::endl;
    }
}

void ParameterStatement::generateCode(std::ofstream &ofs) {

}

void IdentifierDeclaration::generateCode(std::ofstream &ofs) {

}

void Type::generateCode(std::ofstream &ofs) {
    ofs << typeOf(m_type);
}

void Expression::generateCode(std::ofstream &ofs) {

}

void Comparison::generateCode(std::ofstream &ofs) {

}

void FunctionCall::generateCode(std::ofstream &ofs) {

}

void Literal::generateCode(std::ofstream &ofs) {

}

void Identifier::generateCode(std::ofstream &ofs) {
    ofs << m_id;
}

void AssignmentStatement::generateCode(std::ofstream &ofs) {

}

void IfStatement::generateCode(std::ofstream &ofs) {

}

void ElseIfStatement::generateCode(std::ofstream &ofs) {

}

void DoStatement::generateCode(std::ofstream &ofs) {

}

void WhileStatement::generateCode(std::ofstream &ofs) {

}

void PrintStatement::generateCode(std::ofstream &ofs) {

}

void ReadStatement::generateCode(std::ofstream &ofs) {

}

void CallStatement::generateCode(std::ofstream &ofs) {

}

void ErrorNode::generateCode(std::ofstream &ofs) {

}
