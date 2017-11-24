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

LLVM_AssemblyGenerator::LLVM_AssemblyGenerator() {

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

void LLVM_AssemblyGenerator::generateCode(node_ptr &root) {
    std::ofstream ofs("./ir/code.txt", std::ofstream::out);
    root->generateCode(ofs);
    ofs.close();
}

void ExecutableProgram::generateCode(std::ofstream &ofs) {
    for (node_ptr subprogram : m_subprograms) {
        subprogram->generateCode(ofs);
        ofs << std::endl;
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
    for (unsigned int i = 0; i < m_args.size(); i++) {
        ofs << typeOf(entry.arg_types().find(m_args[i]->id())->second);
        if (i != m_args.size()-1) {
            ofs << ", ";
        }
    }
    ofs << ") #0 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << "}" << std::endl;
}

void Subroutine::generateCode(std::ofstream &ofs) {

}

void Body::generateCode(std::ofstream &ofs) {

}

void SpecificationConstruct::generateCode(std::ofstream &ofs) {

}

void ExecutableConstruct::generateCode(std::ofstream &ofs) {

}

void DeclarationStatement::generateCode(std::ofstream &ofs) {

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
