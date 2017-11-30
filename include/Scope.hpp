#ifndef __SCOPE__
#define __SCOPE__

#include <map>
#include <vector>
#include <memory>
#include "Entry.hpp"

using entry_ptr = std::shared_ptr<Entry>;

class Scope {

  public:
    Scope() {}
    virtual ~Scope() {}

    // Inserts a variable in this scope. 
    // Returns true if it isn't already in it, otherwise returns false.
    bool insert(const std::string& id, entry_ptr entry);

    entry_ptr lookup(const std::string& id) const;

    Fortran::type return_type() const;

    void set_return_type(Fortran::type returnType);

    // Returns the function arguments
    const std::vector<std::string> args() const;

    // Set the function arguments
    void set_args(std::vector<std::string> args);

  private:
    Fortran::type m_returnType;
    std::map<std::string, entry_ptr> m_vars;
    std::vector<std::string> m_args;
};

#endif /* END __SCOPE__ */