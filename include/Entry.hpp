#ifndef __ENTRY_HPP__
#define __ENTRY_HPP__

#include "Types.hpp"

class Entry {
  
  using Dimension = Fortran::structural::type;
  using Type = Fortran::vartype::type;

  public:
    Entry(const std::string &id, Type type = Type::INTEGER,
        Dimension dimension = Dimension::SCALAR)
      : m_id(id), m_type(type), m_dimension(dimension) {}
    virtual ~Entry() {}
    Type type() const { return m_type; }
    Dimension dimension() const {return m_dimension; }
    
    void set_addr(unsigned int addr) {
        std::cout << "Setting addr of " << m_id << ": %"
                  << std::to_string(addr) << std::endl;
        m_addr = addr;
    }

    unsigned int addr() const { return m_addr; }

  private:
    std::string m_id;
    Type m_type;
    Dimension m_dimension;
    unsigned int m_addr;
};

#endif /* END __ENTRY_HPP__ */