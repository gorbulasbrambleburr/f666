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

// Holds the last attributed variable address
static unsigned int addr;

// Utilities ------------------------------------------------------------------

unsigned int next_addr() {
    return addr++;
}

void reset_addr() {
    addr = 0;
    // var_addr.clear();
}

std::string typeOf(Fortran::type type) {
    std::string str;
    switch (type) {
        case (Fortran::type::INTEGER): str = "i32"; break; 
        case (Fortran::type::REAL): str = "double"; break; 
        case (Fortran::type::BOOLEAN): str = "i8"; break; 
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


// Returns the comparison type for signed integer comparison
std::string icmp_type(Fortran::op::comp op) {
    switch (op) {
        case (Fortran::op::comp::EQ): return "icmp eq"; break;
        case (Fortran::op::comp::NE): return "icmp ne"; break;
        case (Fortran::op::comp::LT): return "icmp slt"; break;
        case (Fortran::op::comp::LE): return "icmp sle"; break;
        case (Fortran::op::comp::GT): return "icmp sgt"; break;
        case (Fortran::op::comp::GE): return "icmp sge"; break;
        default: return ""; break;
    }
}

// Returns the comparison type for ordered float comparison
std::string fcmp_type(Fortran::op::comp op) {
    switch (op) {
        case (Fortran::op::comp::EQ): return "fcmp oeq"; break;
        case (Fortran::op::comp::NE): return "fcmp one"; break;
        case (Fortran::op::comp::LT): return "fcmp olt"; break;
        case (Fortran::op::comp::LE): return "fcmp ole"; break;
        case (Fortran::op::comp::GT): return "fcmp ogt"; break;
        case (Fortran::op::comp::GE): return "fcmp oge"; break;
        default: return ""; break;
    }
}

// Generates a ALLOCA operation
void op_alloca(std::ofstream &ofs, Fortran::type type,
        const std::string &what, const std::string &where) {

    ofs << std::setw(where.size() + 2)
        << where << " = alloca "
        << typeOf(type) << ", align " << align(type)
        << "\t\t\t\t;  var " << what << std::endl;
}

// Generates a STORE operation
void op_store(std::ofstream &ofs, Fortran::type type,
        const std::string &what, const std::string &where) {

    ofs << std::setw(8)
        << "store " << typeOf(type) << " " << what
        << ", " << typeOf(type) << "* " << where
        << ", align " << align(type) << std::endl;
}

// Generates a LOAD operation
void op_load(std::ofstream &ofs, Fortran::type type,
        const std::string &what, const std::string &from, const std::string &to) {

    ofs << std::setw(to.size() + 2)
        << to << " = load " << typeOf(type)
        << ", " << typeOf(type) << "* " << from
        << ", align " << align(type) 
        << "\t\t;  var " << what << std::endl;
}

// Generates a  TRUNC operation from 8 bits to 1 bit
void op_trunc_boolean(std::ofstream &ofs, const std::string &from,
        const std::string &to) {

    ofs << std::setw(to.size() + 2)
        << to << " = trunc i8 "
        << from << " to i1"
        << std::endl;
}

// Generates a CONDITIONAL BRANCH
void op_cond_branch(std::ofstream &ofs, const std::string &cond,
        const std::string &label_true, const std::string &label_false) {

    ofs << std::setw(8) << "br i1 " << cond
        << ", label " << label_true
        << ", label " << label_false
        << std::endl << std::endl;
}

void op_branch(std::ofstream &ofs, const std::string &label) {
    ofs << std::setw(11) << "br label "
        << label << std::endl << std::endl;
}

// Class methods --------------------------------------------------------------

LLVM_AssemblyGenerator::LLVM_AssemblyGenerator() {
    addr = 0;
}

void LLVM_AssemblyGenerator::generateCode(node_ptr &root) {
    std::ofstream ofs("./ir/code.ll", std::ofstream::out);
    root->generateCode(ofs);
    ofs.close();
}

// Node implementations -------------------------------------------------------

std::string ExecutableProgram::generateCode(std::ofstream &ofs) {
    ofs << "target datalayout = \"e-m:e-i64:64-f80:128-n8:16:32:64-S128\""
        << std::endl;
    ofs << "target triple = \"x86_64-samsung-linux\"" << std::endl;
    ofs << std::endl;
    for (auto& subprogram : m_subprograms) {
        subprogram->generateCode(ofs);
        ofs << std::endl;
        reset_addr();
    }
    return "";
}

std::string MainProgram::generateCode(std::ofstream &ofs) {
    Mapper::get().set_scope(m_id->id());
    ofs << "define @" << m_id->id() << "() #1 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << "}" << std::endl;
    Mapper::get().reset_scope();
    return "";
}

std::string Function::generateCode(std::ofstream &ofs) {
    
    // Enter the function scope
    Mapper::get().set_scope(m_id->id());

    ofs << "define " << m_type->generateCode(ofs)
        << " @" << m_id->id() << "(";

    // Get the function arguments
    auto args = Mapper::get().args(m_id->id());

    for (unsigned int i = 0; i < args.size(); i++) {
        ofs << typeOf(Mapper::get().lookup_var(args[i])->type());
        next_addr();
        if (i != args.size()-1) {
            ofs << ", ";
        }
    }

    ofs << ") #0 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << std::setw(6) << "ret " << m_type->generateCode(ofs);
    auto entry = Mapper::get().lookup_var(m_id->id());
    ofs << " %" + std::to_string(entry->addr()) << std::endl;;
    ofs << "}" << std::endl;
    Mapper::get().reset_scope();
    return "";
}

std::string Subroutine::generateCode(std::ofstream &ofs) {
    
    // Enter the subroutine scope
    Mapper::get().set_scope(m_id->id());

    ofs << "define void @" << m_id->id() << "(";

    // Get the subroutine arguments
    auto args = Mapper::get().args(m_id->id());

    for (unsigned int i = 0; i < args.size(); i++) {
        ofs << typeOf(Mapper::get().lookup_var(args[i])->type());
        next_addr();
        if (i != args.size()-1) {
            ofs << ", ";
        }
    }

    ofs << ") #0 {" << std::endl;
    m_body->generateCode(ofs);
    ofs << std::setw(10) << "ret void" << std::endl;
    ofs << "}" << std::endl;
    Mapper::get().reset_scope();
    return "";
}

std::string Body::generateCode(std::ofstream &ofs) {
    m_specificationConstruct->generateCode(ofs);
    m_executionConstruct->generateCode(ofs);
    return "";
}

// Contains a list of DeclarationStatement and/or ParameterStatement
std::string SpecificationConstruct::generateCode(std::ofstream &ofs) {
    
    // For some shady reason, it has to skip a number
    next_addr();

    for (auto& spec : m_specifications) {
        spec->generateCode(ofs);
    }
    return "";
}

std::string ExecutableConstruct::generateCode(std::ofstream &ofs) {
    for (auto& statement : m_statements) {
        statement->generateCode(ofs);
    }
    return "";
}

// Contains a Type and a list of IdentifierDeclaration
// Only works for scalar variables
std::string DeclarationStatement::generateCode(std::ofstream &ofs) {

    // For each declared variable
    for (auto& var : m_ids) {
        auto entry = Mapper::get().lookup_var(var->id());
        unsigned int addr = next_addr();
        entry->set_addr(addr);
        
        std::string what = var->id();
        std::string where = "%" + std::to_string(addr);
        op_alloca(ofs, entry->type(), what, where);

        // If the variable is in the function arguments, 
        // store its value in its address
        auto args = Mapper::get().args();
        for (unsigned int i = 0; i < args.size(); i++) {
            if (args[i] == var->id()) {
                what = "%" + std::to_string(i);
                op_store(ofs, entry->type(), what, where);
                break;
            }
        }

        auto entry2 = Mapper::get().lookup_var(var->id());
    }
    return "";
}

// Will no be implemented
std::string ParameterStatement::generateCode(std::ofstream &ofs) {
    return "";
}

// Only works for scalar variables
std::string IdentifierDeclaration::generateCode(std::ofstream &ofs) {
    return m_id->generateCode(ofs);
}

std::string Type::generateCode(std::ofstream &ofs) {
    return typeOf(m_type);
}

std::string Expression::generateCode(std::ofstream &ofs) {

    // Get the variable from the children nodes
    std::string ret_left = m_left->generateCode(ofs);
    std::string ret_right =  m_right->generateCode(ofs);

    // Print this node code    
    unsigned int addr = next_addr();
    std::string ret = "%" + std::to_string(addr);
    ofs << std::setw(ret.size() + 2) << ret << " = ";

    if (m_logic) {
        switch (m_logicOp) {
            case (Fortran::op::logic::AND):
                break;
            case (Fortran::op::logic::OR) :
                break;
            case (Fortran::op::logic::NOT):
                break;
            default: break;
        }
    } else {
        switch (m_operator) {
            case (Fortran::op::arithmetic::ADD):
                switch (this->var_type()) {
                    case (Fortran::type::INTEGER): ofs << "add i32 "; break;
                    case (Fortran::type::REAL): ofs << "fadd double "; break;
                    default: ofs << ""; break;
                }
                break;
            case (Fortran::op::arithmetic::SUB):
                switch (this->var_type()) {
                    case (Fortran::type::INTEGER): ofs << "sub i32 "; break;
                    case (Fortran::type::REAL): ofs << "fsub double "; break;
                    default: ofs << ""; break;
                }
                break;
            case (Fortran::op::arithmetic::DIV):
                switch (this->var_type()) {
                    case (Fortran::type::INTEGER): ofs << "sdiv i32 "; break;
                    case (Fortran::type::REAL): ofs << "fdiv double "; break;
                    default: ofs << ""; break;
                }
                break;
            case (Fortran::op::arithmetic::MUL):
                switch (this->var_type()) {
                    case (Fortran::type::INTEGER): ofs << "mul i32 "; break;
                    case (Fortran::type::REAL): ofs << "fmul double "; break;
                    default: ofs << ""; break;
                }
                break;
            default: break;
        }
        ofs << ret_left << ", " << ret_right << std::endl;
    }
    return ret;
}

std::string Comparison::generateCode(std::ofstream &ofs) {
    
    // First compute the expressions in the subtrees
    std::string res_left = m_left->generateCode(ofs);
    std::string res_right = m_right->generateCode(ofs);

    std::string result = "%" + std::to_string(next_addr());
    ofs << std::setw(result.size() + 2) << result << " = ";
    
    switch (m_left->var_type()) {
        case (Fortran::type::INTEGER):
            ofs << icmp_type(m_operator) << " ";
            break;
        case (Fortran::type::REAL):
            ofs << fcmp_type(m_operator) << " ";
            break;
        default: break;
    }

    ofs << typeOf(m_left->var_type()) << " "
        << res_left << ", "
        << res_right << std::endl;
    return result;
}

std::string FunctionCall::generateCode(std::ofstream &ofs) {

    auto ret_type = Mapper::get().return_type();

    std::string call_ret = "%" + std::to_string(next_addr());
    ofs << std::setw(call_ret.size() + 2)
        << call_ret << " = call " << typeOf(ret_type)
        << " @" << m_id->id() << "(";

    for (unsigned int i = 0; i < m_args.size(); i++) {
        auto entry = Mapper::get().lookup_var(m_args[i]->id());
        std::string addr = "%" + std::to_string(entry->addr());
        ofs << typeOf(entry->type()) << " " << addr;
        if (i < m_args.size() - 1) {
            ofs << ", ";
        }
    }
    ofs << ")" << std::endl;

    return call_ret;
}

std::string Literal::generateCode(std::ofstream &ofs) {
    switch (m_type) {
        case (Fortran::type::INTEGER): return std::to_string(m_iValue); break;
        case (Fortran::type::REAL): return std::to_string(m_dValue); break;
        case (Fortran::type::BOOLEAN): return std::to_string(m_bValue); break;
        case (Fortran::type::STRING): return m_sValue; break;
        default: return ""; break;
    }
}

std::string Identifier::generateCode(std::ofstream &ofs) {
    auto entry = Mapper::get().lookup_var(m_id);
    std::string from = "%" + std::to_string(entry->addr());
    std::string to = "%" + std::to_string(next_addr());

    // Loads the variable into a new temporary
    op_load(ofs, entry->type(), m_id, from, to);

    if (entry->type() == Fortran::type::BOOLEAN) {
        std::string from_addr = to;
        std::string to_addr = "%" + std::to_string(next_addr());
        op_trunc_boolean(ofs, from_addr, to_addr);
    }
    return to;
}

// Only works for scalar variables
std::string AssignmentStatement::generateCode(std::ofstream &ofs) {
    std::string res = m_expression->generateCode(ofs);
    auto entry = Mapper::get().lookup_var(m_id->id());
    std::string to = "%" + std::to_string(entry->addr());
    op_store(ofs, entry->type(), res, to);
    return "";
}

// Not working for ELSE IF
std::string IfStatement::generateCode(std::ofstream &ofs) {
    std::string cond = m_condition->generateCode(ofs);
    std::string label_true = "%" + std::to_string(next_addr());
    std::string label_false, label_end;

    // Check if there is an ELSE block
    if (m_elseStatements.empty()) {
        label_end = "%" + std::to_string(next_addr());
        op_cond_branch(ofs, cond, label_true, label_end);
    } else {
        label_false = "%" + std::to_string(next_addr());
        label_end = "%" + std::to_string(next_addr());
        op_cond_branch(ofs, cond, label_true, label_false);
    }

    // Label true branch
    ofs << "; <label>:" << label_true.substr(1,std::string::npos) << ":" << std::endl;
    for (auto& statement : m_ifStatements) {
        statement->generateCode(ofs);
    }

    op_branch(ofs, label_end);

    // Label false branch
    if (!m_elseStatements.empty()) {
        ofs << "; <label>:" << label_false.substr(1,std::string::npos) << ":" << std::endl;
        for (auto& statement : m_elseStatements) {
            statement->generateCode(ofs);
        }
        op_branch(ofs, label_end);
    }

    ofs << "; <label>:" << label_end.substr(1,std::string::npos) << ":" << std::endl;
    return "";
}

std::string ElseIfStatement::generateCode(std::ofstream &ofs) {
    return "";
}

std::string DoStatement::generateCode(std::ofstream &ofs) {

    // The loop var
    auto entry = Mapper::get().lookup_var(m_id->id());

    // Loop var initial value comes from an expression
    std::string what = m_varExpr->generateCode(ofs);

    // Loop var allocated memory address
    std::string where = "%" + std::to_string(entry->addr());

    // Store initial value for loop var
    op_store(ofs, entry->type(), what, where);

    // Label branches
    std::string label_decl = "%" + std::to_string(next_addr());
    std::string label_true = "%" + std::to_string(next_addr());
    std::string label_incr = "%" + std::to_string(next_addr());
    std::string label_end = "%" + std::to_string(next_addr());

    // Create loop declaration branch and branch to it
    op_branch(ofs, label_decl);

    // Start of loop declaration branch
    ofs << "; <label>:" << label_decl.substr(1,std::string::npos) << ":" << std::endl;

    // Load loop var
    std::string loop_var = m_id->generateCode(ofs);

    // Get bound expression
    std::string loop_bound = m_boundExpr->generateCode(ofs);

    // Make LE comparison between integers
    std::string cond = "%" + std::to_string(next_addr());
    ofs << std::setw(cond.size() + 2) << cond << " = ";
    ofs << icmp_type(Fortran::op::comp::LE) << " ";
    ofs << typeOf(Fortran::type::INTEGER) << " "
        << loop_var << ", "
        << loop_bound << std::endl;
    
    // Comparison of loop declaration branch
    op_cond_branch(ofs, cond, label_true, label_end);

    // Start of true branch
    ofs << "; <label>:" << label_true.substr(1,std::string::npos) << ":" << std::endl;

    // Loop body
    for (auto& statement : m_statements) {
        statement->generateCode(ofs);
    }

    // Branch to loop increment branch
    op_branch(ofs, label_incr);

    // Start of loop increment branch
    ofs << "; <label>:" << label_incr.substr(1,std::string::npos) << ":" << std::endl;

    // Load loop var and increment it
    loop_var = m_id->generateCode(ofs);
    std::string loop_incr = m_incExpr->generateCode(ofs);
    std::string tmp = "%" + std::to_string(next_addr());
    ofs << std::setw(tmp.size() + 2)
        << tmp << " = add i32 " << loop_var
        << ", " << loop_incr
        << std::endl;
    op_store(ofs, entry->type(), tmp, where); 

    // Branch to loop declaration branch
    op_branch(ofs, label_decl);

    // Start of loop end branch
    ofs << "; <label>:" << label_end.substr(1,std::string::npos) << ":" << std::endl;    

    return "";
}

std::string WhileStatement::generateCode(std::ofstream &ofs) {
    return "";
}

std::string PrintStatement::generateCode(std::ofstream &ofs) {
    return "";
}

std::string ReadStatement::generateCode(std::ofstream &ofs) {
    return "";
}

std::string CallStatement::generateCode(std::ofstream &ofs) {
    ofs << std::setw(13)
        << "call void @" << m_id->id() << "(";

    for (unsigned int i = 0; i < m_params.size(); i++) {
        auto entry = Mapper::get().lookup_var(m_params[i]->id());
        std::string addr = "%" + std::to_string(entry->addr());
        ofs << typeOf(entry->type()) << " " << addr;
        if (i < m_params.size() - 1) {
            ofs << ", ";
        }
    }
    ofs << ")" << std::endl;
    return "";
}

std::string ErrorNode::generateCode(std::ofstream &ofs) {
    return "";
}
