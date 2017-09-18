#include "../include/ast/ExecutableProgram.hpp"

ExecutableProgram::ExecutableProgram(node_ptrs&& subprograms)
    : m_subprograms(std::forward<node_ptrs>(subprograms)) {
}

ExecutableProgram::~ExecutableProgram() {
}

void ExecutableProgram::print() const {
    std::cout << "ExecutableProgram" << std::endl;
    for (auto &child : m_subprograms) {
        child->print();
    }
}

void ExecutableProgram::addChild(node_ptr child) {
    m_subprograms.emplace_back(std::move(child));
}