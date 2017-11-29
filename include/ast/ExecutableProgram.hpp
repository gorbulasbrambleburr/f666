#ifndef __AST_EXECUTABLE_PROGRAM_HPP__
#define __AST_EXECUTABLE_PROGRAM_HPP__

#include "AST.hpp"

class ExecutableProgram : public AST {
public:
    ExecutableProgram(node_ptrs&& subprograms);
    ~ExecutableProgram();
    void print(int width) const;
    void addChild(node_ptr child);
    virtual std::string generateCode(std::ofstream &ofs);

private:
    node_ptrs m_subprograms;
};

#endif /* END __AST_EXECUTABLE_PROGRAM_HPP__ */