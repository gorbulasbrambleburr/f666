#ifndef __CODE_GENERATOR_HPP__
#define __CODE_GENERATOR_HPP__

// Forward declaration
class ExecutableProgram;
class MainProgram;
class Function;
class Subroutine;
class Body;
class SpecificationConstruct;
class ExecutableConstruct;
class DeclarationStatement;
class ParameterStatement;
class IdentifierDeclaration;
class Type;
class AssignmentStatement;
class Expression;
class Comparison;
class FunctionCall;
class Literal;
class Identifier;
class IfStatement;
class ElseIfStatement;
class DoStatement;
class WhileStatement;
class PrintStatement;
class ReadStatement;
class CallStatement;
class ErrorNode;

// Visitor class that implements intermediate code generation
class CodeGenerator {

public:
    virtual void generateCode(ExecutableProgram &node) = 0;
    virtual void generateCode(MainProgram &node) = 0;
    virtual void generateCode(Function &node) = 0;
    virtual void generateCode(Subroutine &node) = 0;
    virtual void generateCode(Body &node) = 0;
    virtual void generateCode(SpecificationConstruct &node) = 0;
    virtual void generateCode(ExecutableConstruct &node) = 0;
    virtual void generateCode(DeclarationStatement &node) = 0;
    virtual void generateCode(ParameterStatement &node) = 0;
    virtual void generateCode(IdentifierDeclaration &node) = 0;
    virtual void generateCode(Type &node) = 0;
    virtual void generateCode(Expression &node) = 0;
    virtual void generateCode(Comparison &node) = 0;
    virtual void generateCode(FunctionCall &node) = 0;
    virtual void generateCode(Literal &node) = 0;
    virtual void generateCode(Identifier &node) = 0;
    virtual void generateCode(AssignmentStatement &node) = 0;
    virtual void generateCode(IfStatement &node) = 0;
    virtual void generateCode(ElseIfStatement &node) = 0;
    virtual void generateCode(DoStatement &node) = 0;
    virtual void generateCode(WhileStatement &node) = 0;
    virtual void generateCode(PrintStatement &node) = 0;
    virtual void generateCode(ReadStatement &node) = 0;
    virtual void generateCode(CallStatement &node) = 0;
    virtual void generateCode(ErrorNode &node) = 0;
};

#endif /* END __CODE_GENERATOR_HPP__ */