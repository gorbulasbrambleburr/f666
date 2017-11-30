#ifndef __MAPPER__
#define __MAPPER__

#include <vector>
#include <map>
#include <memory>
#include "Entry.hpp"
#include "Scope.hpp"

using scope_ptr = std::shared_ptr<Scope>;

// Mapper is a singleton symbol table implementation.
class Mapper {

  public:

    // Returns a single instance of this class
    static Mapper& get();

    // Creates a new scope
    bool create_scope(const std::string& id);

    // Resets to the last scope used.
    void reset_scope();
    
    // Sets the current scope
    void set_scope(const std::string &fid);

    // Set the arguments to the function id
    void set_args(std::vector<std::string> args);
    void set_args(std::vector<std::string> args, const std::string &fid);

    // Get the arguments of the function id
    const std::vector<std::string> args() const;
    const std::vector<std::string> args(const std::string &fid) const;

    // Set the return type of the function id
    void set_return_type(Fortran::type returnType);
    void set_return_type(Fortran::type returnType, const std::string &fid);
    
    // Get the return type of the function id
    Fortran::type return_type() const;
    Fortran::type return_type(const std::string &fid) const;

    // Inserts a variable into the current function scope
    bool insert(const std::string& id, entry_ptr entry);

    // Get a pointer to the variable entry in the function id scope
    entry_ptr lookup_var(const std::string& id) const;
    entry_ptr lookup_var(const std::string& id, const std::string &fid) const;
    
    // Checks if the specified function has been declared
    bool lookup_fun(const std::string& fid) const;

    // Copy constructor and assignment operator
    // should not be implemented to avoid copies.
    Mapper(Mapper const&) = delete;
    void operator=(Mapper const&) = delete;

  private:
    Mapper();

  private:
    std::map<std::string,scope_ptr> m_scopes;
    std::string m_currentScope;

};

#endif /* END __MAPPER__ */