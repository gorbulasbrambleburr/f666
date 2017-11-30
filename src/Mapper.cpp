#include <iostream>
#include "Mapper.hpp"

Mapper::Mapper()
  : m_scopes(std::map<std::string, scope_ptr>()),
    m_currentScope("@") {
}

Mapper& Mapper::get() {
    static Mapper instance;
    return instance;
}

bool Mapper::create_scope(const std::string &id) {
    // std::cout << "Creating scope '" << id << "'" << std::endl;
    auto pair = std::pair<std::string, scope_ptr>(id, std::make_shared<Scope>());
    auto ret = m_scopes.insert(pair);
    // std::cout << "Created? " << ret.second << std::endl;
    if (ret.second) {
        m_currentScope = id;
    }
    return ret.second;
}

void Mapper::reset_scope() {
    m_currentScope = "@";
}

void Mapper::set_scope(const std::string &fid) {
    m_currentScope = fid;
}

void Mapper::set_args(std::vector<std::string> args) {
    Mapper::set_args(args, m_currentScope);
}

void Mapper::set_args(std::vector<std::string> args, const std::string &fid) {
    // std::cout << "Setting args into Scope " << fid << std::endl;
    auto search = m_scopes.find(fid);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        scope->set_args(args);
    } else {
        std::cout << "Error (set_args): scope " << fid << " does not exist." << std::endl;
    }
}

const std::vector<std::string> Mapper::args() const {
    return Mapper::args(m_currentScope);
}

const std::vector<std::string> Mapper::args(const std::string &fid) const {
    auto search = m_scopes.find(fid);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        return scope->args();
    } else {
        std::cout << "Error (args): scope " << fid << " does not exist." << std::endl;
    }    
}

void Mapper::set_return_type(Fortran::type returnType) {
    Mapper::set_return_type(returnType, m_currentScope);
}

void Mapper::set_return_type(Fortran::type returnType, const std::string &fid) {
    // std::cout << "Setting return type into Scope " << fid << std::endl;
    auto search = m_scopes.find(fid);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        scope->set_return_type(returnType);
    } else {
        std::cout << "Error (set_return_type): scope " << fid << " does not exist." << std::endl;
    }
}

Fortran::type Mapper::return_type() const {
    return Mapper::return_type(m_currentScope);
}

Fortran::type Mapper::return_type(const std::string &fid) const {
    auto search = m_scopes.find(fid);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        return scope->return_type();
    } else {
        std::cout << "Error (return_type): scope " << fid << " does not exist." << std::endl;
    }
}

bool Mapper::insert(const std::string& id, entry_ptr entry) {
    // std::cout << "Inserting var '" << id << "' into Scope " << m_currentScope << std::endl;
    auto search = m_scopes.find(m_currentScope);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        return scope->insert(id, entry);
    } else {
        std::cout << "Error (insert): scope " << m_currentScope << " does not exist." << std::endl;
    }
}

entry_ptr Mapper::lookup_var(const std::string& id) const {
    return Mapper::lookup_var(id, m_currentScope);
}

entry_ptr Mapper::lookup_var(const std::string& id,
        const std::string &fid) const {
    // std::cout << "Looking up var '" << id << "' in Scope " << fid << std::endl;
    auto search = m_scopes.find(fid);
    if (search != m_scopes.end()) {
        auto scope = search->second;
        return scope->lookup(id);
    } else {
        std::cout << "Error (lookup_var): scope " << fid << " does not exist." << std::endl;
        return nullptr;
    }
}

bool Mapper::lookup_fun(const std::string &fid) const {
    return m_scopes.find(fid) != m_scopes.end();
}
