#include "Scope.hpp"

Scope::Scope() {

}

bool Scope::insert_var(std::string &id, Entry entry) {
    auto ret = m_vars.insert(std::pair<std::string,Entry>(id,entry));
    return ret.second;
}

bool Scope::insert_fun(std::string &id, Entry entry) {
    auto ret = m_funs.insert(std::pair<std::string,Entry>(id,entry));
    return ret.second;
}

bool Scope::lookup_var(std::string &id) const {
    return m_vars.count(id) == 1;
}

bool Scope::lookup_fun(std::string &id) const {
    return m_funs.count(id) == 1;
}
