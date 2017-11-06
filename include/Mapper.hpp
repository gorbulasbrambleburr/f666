#ifndef __MAPPER__
#define __MAPPER__

#include <list>
#include <map>
#include <memory>
#include "Entry.hpp"

// Mapper is a singleton symbol table implementation.
class Mapper {

  public:
    using scope = std::map<std::string,Entry>;

    // Returns a single instance of this class.
    static Mapper& instance();

    // Inserts an identifier into the table.
    // If it isn't already in it, the function
    // returns true, otherwise returns false.
    bool insert_var(const std::string& id, Entry entry);
    bool insert_fun(const std::string& id, Entry entry);

    // Checks if the specified id is in the table
    bool lookup_var(const std::string& id) const;
    bool lookup_fun(const std::string& id) const;

    const Entry& var_entry(const std::string& id) const; 
    const Entry& fun_entry(const std::string& id) const; 

    // Resets to the last scope used.
    void reset();

    // Creates and add a new scope to the list.
    void create_scope();

    // Copy constructor and assignment operator
    // should not be implemented to avoid copies.
    Mapper(Mapper const&) = delete;
    void operator=(Mapper const&) = delete;

  private:
    Mapper();

  private:
    std::list<scope> m_vars;  // For variables
    scope m_funs;             // For subprograms

};
    

#endif /* END __MAPPER__ */