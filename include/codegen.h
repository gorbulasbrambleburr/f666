#include <stack>
#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/ModuleProvider.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Support/raw_ostream.h>
// #include <llvm/Bitcode/BitstreamWriter.h> // LLVM 4.0
// #include <llvm/Bitcode/BitstreamReader.h> // LLVM 4.0
#include <llvm/Bitcode/ReaderWriter.h>

// LLVM 3.7 compatibility
#include <llvm/IR/PassManager.h>
// #include <llvm/PassManager.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
// #include <llvm/ExecutionEngine/JIT.h>
#include <llvm/ExecutionEngine/GenericValue.h>


using namespace llvm;

class Driver;

class CodeGenBlock {
  public:
    BasicBlock *block;
    std::map<std::string, Value*> locals;
};

class CodeGenContext {

  public:
    CodeGenContext() {
        m_module = new Module("main", getGlobalContext());
    }
    
    void generateCode(node_ptr root);

    void runCode();
    
    std::map<std::string, Value*>& locals() {
        return m_blocks.top()->locals;
    }
    
    BasicBlock *currentBlock() {
        return m_blocks.top()->block;
    
}
    void pushBlock(BasicBlock *block) {
        m_blocks.push(new CodeGenBlock());
        m_blocks.top()->block = block;
    }
    
    void popBlock() {
        CodeGenBlock *top = m_blocks.top();
        m_blocks.pop(); delete top;
    }

  public:
    Module *m_module;

  private:
    std::stack<CodeGenBlock *> m_blocks;
    Function *m_mainFunction;
};