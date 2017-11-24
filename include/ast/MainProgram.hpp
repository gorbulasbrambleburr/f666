#ifndef __AST_MAIN_PROGRAM_HPP__
#define __AST_MAIN_PROGRAM_HPP__

#include "AST.hpp"

class MainProgram : public AST {
public:
    MainProgram(node_ptr id, node_ptr body)
        : m_id(std::move(id)), m_body(std::move(body)) {
    }
    ~MainProgram() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "MainProgram:"<< std::endl;
        m_id->print(width + 4);
        m_body->print(width + 4);
    }
    void acceptCodeGenerator(CodeGenerator &generator) override {
        generator.generateCode(*this);
    }

private:
    node_ptr m_id;
    node_ptr m_body;
};

#endif /* END __AST_MAIN_PROGRAM_HPP__ */