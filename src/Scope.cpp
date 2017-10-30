#include <iostream>
#include "Scope.hpp"

Scope::Scope() {

}

bool Scope::insert_var(const std::string& id, Entry entry) {
    std::cout << "Inserting variable id " << id << std::endl;
    std::cout << "Scope size: " << m_vars.size() << std::endl;
    auto ret = m_vars.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << ret.second << std::endl;
    return ret.second;
}

bool Scope::insert_fun(const std::string& id, Entry entry) {
    std::cout << "Inserting subprogram id " << id << std::endl;
    std::cout << "Scope size: " << m_funs.size() << std::endl;
    auto ret = m_funs.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << ret.second << std::endl;
    return ret.second;
}

const Entry& Scope::var_entry(const std::string& id) const {
    return m_vars.find(id)->second;
}

const Entry& Scope::fun_entry(const std::string& id) const {
    return m_funs.find(id)->second;
}

bool Scope::lookup_var(const std::string& id) const {
    return m_vars.count(id) == 1;
}

bool Scope::lookup_fun(const std::string& id) const {
    return m_funs.count(id) == 1;
}