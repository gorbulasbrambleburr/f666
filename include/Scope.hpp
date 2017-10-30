#ifndef __SCOPE__
#define __SCOPE__

#include <map>
#include "Entry.hpp"

class Scope {

public:
    using var = std::map<std::string,Entry>;
    using fun = std::map<std::string,Entry>;

    Scope();
    virtual ~Scope() {}

    // Inserts an identifier into the table
    // if it doesn't already is in it and
    // returns true, otherwise returns false.
    bool insert_var(const std::string& id, Entry entry);
    bool insert_fun(const std::string& id, Entry entry);

    // Checks if the specified id is in the table
    bool lookup_var(const std::string& id) const;
    bool lookup_fun(const std::string& id) const;

    const Entry& var_entry(const std::string& id) const;
    const Entry& fun_entry(const std::string& id) const;

private:
    std::map<std::string,Entry> m_vars;  // For variables
    std::map<std::string,Entry> m_funs;  // For subprograms

};

#endif /* END __SCOPE__ */