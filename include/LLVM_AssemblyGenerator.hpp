#ifndef __LLVM_ASSEMBLY_GENERATOR_HPP__
#define __LLVM_ASSEMBLY_GENERATOR_HPP__

#include "CodeGenerator.hpp"

class LLVM_AssemblyGenerator : public CodeGenerator {

public:
    void generateCode(ExecutableProgram &node) override;
    void generateCode(MainProgram &node) override;
    void generateCode(Function &node) override;
    void generateCode(Subroutine &node) override;
    void generateCode(Body &node) override;
    void generateCode(SpecificationConstruct &node) override;
    void generateCode(ExecutableConstruct &node) override;
    void generateCode(DeclarationStatement &node) override;
    void generateCode(ParameterStatement &node) override;
    void generateCode(IdentifierDeclaration &node) override;
    void generateCode(Type &node) override;
    void generateCode(Expression &node) override;
    void generateCode(Comparison &node) override;
    void generateCode(FunctionCall &node) override;
    void generateCode(Literal &node) override;
    void generateCode(Identifier &node) override;
    void generateCode(AssignmentStatement &node) override;
    void generateCode(IfStatement &node) override;
    void generateCode(ElseIfStatement &node) override;
    void generateCode(DoStatement &node) override;
    void generateCode(WhileStatement &node) override;
    void generateCode(PrintStatement &node) override;
    void generateCode(ReadStatement &node) override;
    void generateCode(CallStatement &node) override;
    void generateCode(ErrorNode &node) override;
};

#endif /* END __LLVM_ASSEMBLY_GENERATOR_HPP__ */