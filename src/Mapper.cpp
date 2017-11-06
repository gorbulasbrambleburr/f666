#include <iostream>
#include "Mapper.hpp"

Mapper::Mapper() {
    create_scope();
}

void Mapper::create_scope() {
    m_vars.push_back(scope());
}

Mapper& Mapper::instance() {
    static Mapper instance;
    return instance;
}

bool Mapper::insert_var(const std::string& id, Entry entry) {
    std::cout << "Inserting variable id '" << id << "'..." << std::endl;
    auto ret = m_vars.back().insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << (ret.second ? " yes." : "no.") << std::endl;
    std::cout << "Variables in scope: " << m_vars.back().size() << std::endl;
    return ret.second;
}

bool Mapper::insert_fun(const std::string& id, Entry entry) {
    std::cout << "Inserting function id '" << id << "'..." << std::endl;
    auto ret = m_funs.insert(std::pair<std::string,Entry>(id,entry));
    std::cout << "Inserted? " << (ret.second ? " yes." : "no.") << std::endl;
    std::cout << "Variables in scope: " << m_funs.size() << std::endl;
    return ret.second;
}

bool Mapper::lookup_var(const std::string& id) const {
    bool id_found = false;
    std::cout << "Looking up variable id '" << id << "'..." << std::endl;
    for (auto rit = m_vars.rbegin(); rit != m_vars.rend(); ++rit) {
        if ((*rit).count(id) == 1) {
            std::cout << "Found it." << std::endl;
            id_found = true;
            break;
        }
    }
    return id_found;
}

bool Mapper::lookup_fun(const std::string& id) const {
    std::cout << "Looking up function id '" << id << "'..." << std::endl;
    bool id_found = m_funs.count(id) == 1;
    if (id_found) {
        std::cout << "Found it." << std::endl;
    }
    return id_found;
}

const Entry& Mapper::var_entry(const std::string& id) const {
    std::cout << "Searching entry '" << id << "'..." << std::endl;
    for (auto rit = m_vars.rbegin(); rit != m_vars.rend(); ++rit) {
        if ((*rit).count(id) == 1) {
            std::cout << "Found it." << std::endl;
            return (*rit).find(id)->second;
        }
    }
}

// This method should only be called after lookup_fun returns true
const Entry& Mapper::fun_entry(const std::string& id) const {
    auto search = m_funs.find(id);
    if (search != m_funs.end()) {
        return search->second;
    }
}

void Mapper::reset() {
    if (!m_vars.empty()) {
        m_vars.pop_back();
    }
}
