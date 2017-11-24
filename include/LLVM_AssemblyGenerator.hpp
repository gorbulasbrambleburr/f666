#ifndef __LLVM_ASSEMBLY_GENERATOR_HPP__
#define __LLVM_ASSEMBLY_GENERATOR_HPP__

#include "ast/AST.hpp"

using node_ptr = std::shared_ptr<AST>;
using node_ptrs = std::vector<node_ptr>;
    
class LLVM_AssemblyGenerator {
public:
    LLVM_AssemblyGenerator();
    ~LLVM_AssemblyGenerator() {}
    void generateCode(node_ptr &root);
};

#endif /* END __LLVM_ASSEMBLY_GENERATOR_HPP__ */
