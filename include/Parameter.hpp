#ifndef __PARAMETER__
#define __PARAMETER__

#include "Types.hpp"

class Parameter {
  public:
    Parameter(const std::string &name, Fortran::type type)
      : m_name(name), m_type(type) {}
    virtual ~Parameter() {}
    const std::string& name() const { return m_name; }
    Fortran::type type() const { return m_type; }
    unsigned int addr() const { return m_addr; }
    void set_addr(unsigned int addr) { m_addr = addr; }

  private:
    std::string m_name;
    Fortran::type m_type;
    unsigned int m_addr;  // The address in IR
};

#endif /* END __PARAMETER__ */