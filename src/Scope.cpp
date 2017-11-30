#include <iostream>
#include <string>
#include "Scope.hpp"

bool Scope::insert(const std::string& id, entry_ptr entry) {
    auto ret = m_vars.insert(std::pair<std::string, entry_ptr>(id,entry));
    return ret.second;
}

entry_ptr Scope::lookup(const std::string& id) const {
    auto ret = m_vars.find(id);
    if (ret == m_vars.end()) {
        return nullptr;
    }
    return ret->second;
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