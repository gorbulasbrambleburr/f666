#include <iostream>
#include "Scope.hpp"

Scope::Scope() {

}

bool Scope::insert_var(std::string id, Entry entry) {
    std::cout << "Inserting variable id " << id << std::endl;
    std::cout << "Scope size: " << m_vars.size() << std::endl;
    auto ret = m_vars.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << ret.second << std::endl;
    return ret.second;
}

bool Scope::insert_fun(std::string id, Entry entry) {
    std::cout << "Inserting subprogram id " << id << std::endl;
    std::cout << "Scope size: " << m_funs.size() << std::endl;
    auto ret = m_funs.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << ret.second << std::endl;
    return ret.second;
}

bool Scope::lookup_var(std::string &id) const {
    return m_vars.count(id) == 1;
}

bool Scope::lookup_fun(std::string &id) const {
    return m_funs.count(id) == 1;
}