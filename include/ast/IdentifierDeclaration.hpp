#ifndef __AST_IDENTIFIER_DECLARATION_HPP__
#define __AST_IDENTIFIER_DECLARATION_HPP__

#include "AST.hpp"
#include "../Types.hpp"

using stype = Fortran::structural::type;

class IdentifierDeclaration : public AST {
public:
    IdentifierDeclaration(node_ptr id, stype type = stype::SCALAR)
        : m_id(std::move(id)), m_type(type) {
    }
    IdentifierDeclaration(node_ptr id, int arraySize, stype type = stype::ARRAY)
        : m_id(std::move(id)), m_type(type), m_arraySize(arraySize) {
    }
    IdentifierDeclaration(node_ptr id,  node_ptr intId, stype type = stype::ARRAY)
        : m_id(std::move(id)), m_type(type), m_intId(std::move(intId)) {
    }
    ~IdentifierDeclaration() {}
    void print(int width) const {
        std::cout << std::setw(width) << "- " << "IdentifierDeclaration:" << std::endl;
        m_id->print(width + 4);
        std::cout << std::setw(width + 4) << "- " << "Structural type: ";
        switch (m_type) {
            case (stype::SCALAR): {
                std::cout << "SCALAR" << std::endl;
                break;
            }
            case (stype::ARRAY): {
                std::cout << "ARRAY" << std::endl;
                if (m_intId == nullptr) {
                    std::cout << std::setw(width + 4) << "- " << "Size: " << m_arraySize << std::endl;
                } else {
                    m_intId->print(width + 4);
                }
                break;
            }
        }
    }
    const std::string& id() const { return m_id->id(); }
    Fortran::structural::type struct_type() const { return m_type; }
    virtual std::string generateCode(std::ofstream &ofs);

private:
    node_ptr m_id;
    stype m_type;
    int m_arraySize;
    node_ptr m_intId = nullptr;

};

#endif /* END __AST_IDENTIFIER_DECLARATION_HPP__ */