#include <string>
#include "f_driver.hpp"
#include "ast/AST.hpp"
#include "ast/MainProgram.hpp"
#include "ast/Subroutine.hpp"
#include "ast/Function.hpp"
#include "ast/Identifier.hpp"
#include "ast/DeclarationStatement.hpp"
#include "ast/ParameterStatement.hpp"
#include "ast/IdentifierDeclaration.hpp"
#include "ast/AssignmentStatement.hpp"
#include "ast/Expression.hpp"
#include "ast/Comparison.hpp"
#include "ast/Literal.hpp"
#include "ast/IfStatement.hpp"
#include "ast/ElseIfStatement.hpp"
#include "ast/DoStatement.hpp"
#include "ast/WhileStatement.hpp"
#include "ast/ReadStatement.hpp"
#include "ast/PrintStatement.hpp"
#include "ast/CallStatement.hpp"
#include "ast/FunctionCall.hpp"
#include "codegen.h"

using namespace std;

// Compile the AST into a module
void CodeGenContext::generateCode(node_ptr root) {
    std::cout << "Generating code..." << std::endl;
    
    // Create the top level interpreter function to call as entry
    FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), false);
    m_mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", m_module);
    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", m_mainFunction, 0);
    
    // Push a new variable/block context
    pushBlock(bblock);
    root.codeGen(*this); // Emit bytecode for the toplevel block
    ReturnInst::Create(getGlobalContext(), bblock);
    popBlock();
    
    // Print the bytecode in a human-readable format
    // to see if our program compiled properly
    std::cout << "Code is generated." << std::endl;
    
    // LLVM 3.7 compatibility
    PassManager<Module> pm;
    pm.addPass(createPrintModulePass(outs()));
    // PassManager pm;
    // pm.add(createPrintModulePass(&outs()));

    pm.run(*m_module);
}

// Executes the AST by running the main function
void CodeGenContext::runCode() {
    std::cout << "Running code..." << std::endl;
    
    // LLVM 3.7 compatibility
    ExecutionEngine *ee = EngineBuilder(unique_ptr<Module>(m_module)).create();
    ee->finalizeObject();
    // ExistingModuleProvider mp(m_module);
    // ExecutionEngine *ee = ExecutionEngine::create(&mp, false);
    
    ee->runFunction(m_mainFunction, std::vector<GenericValue>());
    std::cout << "Code was run." << std::endl;
}

// Returns an LLVM type
static const Type *typeOf(Fortran::type type) {
    switch (type) {
        case (Fortran::type::INTEGER):
            return Type::getInt64Ty(getGlobalContext());
            break; 
        case (Fortran::type::REAL):
            return Type::getDoubleTy(getGlobalContext());
            break; 
        case (Fortran::type::BOOLEAN):
            return Type::getInt1Ty(getGlobalContext());
            break; 
        default:
            Type::getVoidTy(getGlobalContext());
            break;
    }
}

/* -- Code Generation -- */

Value* Identifier::codeGen(CodeGenContext& context) {
    std::cout << "Creating identifier reference: " << m_id << std::endl;
    return new LoadInst(context.locals()[m_id], "", false, context.currentBlock());
}

Value* Function::codeGen(CodeGenContext& context) {
    Entry entry = Mapper::instance().fun_entry(m_id->id());

    vector<const Type*> argTypes;
    std::map<std::string, Fortran::vartype::type> types = Mapper::instance().fun_entry(m_id->id()).arg_types();
    for (auto& arg : m_args) {
        argTypes.push_back(typeOf(types.find(arg->id())->second));
    }
    FunctionType *ftype = FunctionType::get(typeOf(m_type), argTypes, false);
    Function *function = Function::Create(ftype, GlobalValue::InternalLinkage, m_id->id().c_str(), context.module);
    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", function, 0);

    context.pushBlock(bblock);

    for (auto& arg : m_args) {
        arg->codeGen(context);
    }
    
    m_body.codeGen(context);
    ReturnInst::Create(getGlobalContext(), bblock);

    context.popBlock();
    std::cout << "Creating function: " << id.name << std::endl;
    return function;
}

Value* Body::codeGen(CodeGenContext& context) {
    Value *last = NULL;
    last = m_specificationConstruct->codeGen(context);
    last = m_executionConstruct->codeGen(context);
    return last;
}

Value* SpecificationConstruct::codeGen(CodeGenContext& context) {
    Value *last = NULL;
    for (auto& spec : m_specifications) {
        last = spec->codeGen(context);
    }
    std::cout << "Creating specification construct" << std::endl;
    return last;
}

Value* ExecutionConstruct::codeGen(CodeGenContext& context) {
    Value *last = NULL;
    for (auto& statement : m_statements) {
        last = statement->codeGen(context);
    }
    std::cout << "Creating execution construct" << std::endl;
    return last;
}

Value* DeclarationStatement::codeGen(CodeGenContext& context) {
    std::cout << "Creating declaration statement:" << std::endl;
    AllocaInst *alloc = NULL;
    for (auto& id : m_ids) {
        std::cout << id->id() << ":" << m_type->str() << std::endl;
        alloc = new AllocaInst(typeOf(m_type), id->id().c_str(), context.currentBlock());
        context.locals()[id->id()] = alloc;
    }
    return alloc;
}

Value* ParameterStatement::codeGen(CodeGenContext& context) {}

Value* AssignmentStatement::codeGen(CodeGenContext& context) {
    std::cout << "Creating assignment for " << m_id->id() << std::endl;
    return new StoreInst(m_expression.codeGen(context), context.locals()[m_id->id()], false, context.currentBlock());
}

Value* Expression::codeGen(CodeGenContext& context) {
    std::cout << "Creating binary operation " << m_operator << std::endl;
    Instruction::BinaryOps instr;
    switch (m_operator) {
        case (Fortran::op::arithmetic::ADD): 
            std::cout << "Creating binary operation: add" << std::endl;
            instr = Instruction::Add;
            goto math;
            break;
        case (Fortran::op::arithmetic::SUB): 
            std::cout << "Creating binary operation: sub" << std::endl;
            instr = Instruction::Sub;
            goto math;
            break;
        case (Fortran::op::arithmetic::DIV): 
            std::cout << "Creating binary operation: div" << std::endl;
            instr = Instruction::SDiv;
            goto math;
            break;
        case (Fortran::op::arithmetic::MUL): 
            std::cout << "Creating binary operation: mul" << std::endl;
            instr = Instruction::Mul;
            goto math;
            break;
        default: break;
    }
    return NULL;
math:
    return BinaryOperator::Create(instr, m_left.codeGen(context), 
            m_right.codeGen(context), "", context.currentBlock());
}

Value* FunctionCall::codeGen(CodeGenContext& context) {
    Function *function = context.module->getFunction(m_id->id().c_str());
    if (function == NULL) {
        std::cerr << "no such function " << m_id->id() << std::endl;
    }
    std::vector<Value*> args;
    for (auto& arg : m_args) {
        args.push_back(arg->codeGen(context));
    }
    CallInst *call = CallInst::Create(function, args.begin(), args.end(), "", context.currentBlock());
    std::cout << "Creating function call: " << m_id->id() << std::endl;
    return call;
}

Value* Literal::codeGen(CodeGenContext& context) {
    std::cout << "Creating integer: " << value << std::endl;
    switch (m_type) {
        case (Fortran::type::INTEGER):
            std::cout << "Creating integer: " << m_iValue << std::endl;
            return ConstantInt::get(Type::getInt64Ty(context), m_iValue, true);
            break;
        case (Fortran::type::REAL):
            std::cout << "Creating real: " << m_fValue << std::endl;
            return ConstantFP::get(Type::getDoubleTy(context), m_fValue);
            break;
        case (Fortran::type::BOOLEAN):
            std::cout << "Creating boolean: " << m_bValue << std::endl;
            return ConstantInt::get(Type::getInt1Ty(context), m_bValue);
            break;
        default:
            std::cout << "Creating something unsupported." << std::endl;
            break;
    }
}

Value* IfStatement::codeGen(CodeGenContext& context) {
    //std::cout << "Creating if condition " << std::endl;
    // return new StoreInst(m_expression.codeGen(context), context.locals()[m_id->id()], false, context.currentBlock());
}

Value* DoStatement::codeGen(CodeGenContext& context) {}
Value* WhileStatement::codeGen(CodeGenContext& context) {}
Value* PrintStatement::codeGen(CodeGenContext& context) {}
Value* ReadStatement::codeGen(CodeGenContext& context) {}
