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
    void set_addr(unsigned int addr) { m_addr = addr; }
    unsigned int addr() const { return m_addr; }

    // static Entry empty() {
    //     return new Entry("$"); 
    // }

    // bool operator==(const Entry &rhs) {
    //     return m_id == rhs.m_id;
    // }

    // bool operator!=(const Entry &rhs) {
    //     return m_id != rhs.m_id;
    // }

  private:
    std::string m_id;
    Type m_type;
    Dimension m_dimension;
    unsigned int m_addr;
    //static Entry m_emptyEntry = Entry("$");
};

#endif /* END __ENTRY_HPP__ */