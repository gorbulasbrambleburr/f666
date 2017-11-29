#include <iostream>
#include <string>
#include "Scope.hpp"

bool Scope::insert(const std::string& id, Entry entry) {
    auto ret = m_vars.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Number of vars: " << std::to_string(m_vars.size()) << std::endl;
    return ret.second;
}

std::shared_ptr<Entry> Scope::lookup(const std::string& id) const {
    std::cout << "Scope: looking up var '" << id << "'" << std::endl;
    auto ret = m_vars.find(id);
    if (ret == m_vars.end()) {
        std::cout << "Not found." << std::endl;
        return nullptr;
    }
    std::cout << "Found." << std::endl;
    return std::make_shared<Entry>(ret->second);
}

Fortran::type Scope::return_type() const {
    return m_returnType;
}

void Scope::set_return_type(Fortran::type returnType) {
    m_returnType = returnType;
}

// Returns the function arguments
const std::vector<std::string> Scope::args() const {
    return m_args;
}

// Set the function arguments
void Scope::set_args(std::vector<std::string> args) {
    m_args = args;
}