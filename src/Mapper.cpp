#include "Mapper.hpp"

Mapper::Mapper() {
    create_scope();
}

Mapper& Mapper::instance() {
    static Mapper instance;
    return instance;
}

bool Mapper::insert_var(std::string id, Entry entry) {
    return m_scopes.back()->insert_var(id, entry);
}

bool Mapper::insert_fun(std::string id, Entry entry) {
    return m_scopes.back()->insert_fun(id, entry);
}

bool Mapper::lookup_var(std::string &id) const {
    return m_scopes.back()->lookup_var(id);
}

bool Mapper::lookup_fun(std::string &id) const {
    return m_scopes.back()->lookup_fun(id);
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