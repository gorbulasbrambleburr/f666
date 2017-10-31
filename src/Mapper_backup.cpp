#include <iostream>
#include "Mapper_backup.hpp"

Mapper::Mapper() {
    create_scope();
}

Mapper& Mapper::instance() {
    static Mapper instance;
    return instance;
}

bool Mapper::insert_var(const std::string& id, Entry entry) {
    return m_scopes.back()->insert_var(id, entry);
}

bool Mapper::insert_fun(const std::string& id, Entry entry) {
    return m_scopes.back()->insert_fun(id, entry);
}

bool Mapper::lookup_var(const std::string& id) const {
    bool id_found = false;
    std::cout << "Looking up variable id '" << id << "'..." << std::endl;
    for (auto rit = m_scopes.rbegin(); rit != m_scopes.rend(); ++rit) {
        if ((*rit)->lookup_var(id)) {
            std::cout << "Found it." << std::endl;
            id_found = true;
            break;
        }
    }
    return id_found;
}

bool Mapper::lookup_fun(const std::string& id) const {
    bool id_found = false;
    std::cout << "Looking up function id '" << id << "'..." << std::endl;
    for (auto rit = m_scopes.rbegin(); rit != m_scopes.rend(); ++rit) {
        if ((*rit)->lookup_fun(id)) {
            std::cout << "Found it." << std::endl;
            id_found = true;
            break;
        }
    }
    return id_found;
}

const Entry& Mapper::var_entry(const std::string& id) const {
    std::cout << "Searching entry '" << id << "'..." << std::endl;
    for (auto rit = m_scopes.rbegin(); rit != m_scopes.rend(); ++rit) {
        if ((*rit)->lookup_var(id)) {
            std::cout << "Found it." << std::endl;
            return (*rit)->var_entry(id);
        }
    }
}

// This method should only be called after lookup_fun returns true
const Entry& Mapper::fun_entry(const std::string& id) const {
    std::cout << "Searching entry '" << id << "'..." << std::endl;
    for (auto rit = m_scopes.rbegin(); rit != m_scopes.rend(); ++rit) {
        if ((*rit)->lookup_fun(id)) {
            std::cout << "Found it." << std::endl;
            return (*rit)->fun_entry(id);
        }
    }
}

void Mapper::reset() {
    if (!m_scopes.empty()) {
        m_scopes.pop_back();
    }
}

void Mapper::create_scope() {
    m_scopes.push_back(scope_factory());
}

std::unique_ptr<Scope> Mapper::scope_factory() const {
    return std::make_unique<Scope>();
}