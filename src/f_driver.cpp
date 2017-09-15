#include <cctype>
#include <fstream>
#include <cassert>

#include "../include/f_driver.hpp"

Fortran::Driver::Driver() :
    m_nodes(),
    m_scanner(*this),
    m_parser(_scanner, *this),
    m_location(0) {
}

template<typename NodeType, typename ...Args>
node_ptr Fortran::Driver::createNode(Args&&... args) {
    return node_ptr(new NodeType(std::forward<Args>(args)...));
}

template<typename ...Args>
node_ptrs Fortran::Driver::crateNodeList(Args&&... args) {
    return node_ptrs(args...);
}

bool Fortran::Driver::createBoolean(const std::string &text) {
    if (text == "TRUE") {
        return true;
    }
    return false;
}

int Fortran::Driver::createInteger(const std::string &text) {
    return std::atoi(text.c_str());
}

float Fortran::Driver::createReal(const std::string &text) {
    return std::atof(text.c_str());
}

void Fortran::Driver::parse(const char * const filename) {
    assert(filename != std::nullptr_t);
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        exit(EXIT_FAILURE);
    }
    m_location = 0;
    parse_helper(in_file);
    return;
}

void Fortran::Driver::parse_helper(std::istream &stream) {
    delete(scanner);
    try {
        scanner = new Fortran::Scanner(&stream);
    } catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate scanner: (" <<
        ba.what() << "), exiting!\n";
        exit(EXIT_FAILURE);
    }

    delete(parser);
    try {
        parser = new Fortran::Parser((*scanner), (*this));
    } catch (std::bad_alloc &ba) {
        std::cerr << "Failed to allocate parser: (" <<
        ba.what() << "), exiting!\n";
        exit(EXIT_FAILURE);
    }

    const int accept(0);
    if (parser->parse() != accept) {
        std::cerr << "Parse failed!\n";
    }
    return;
}

std::string Fortran::Driver::print() const {
    std::stringstream s;
    s << "Results:\n";
    for (node_ptr child : node_ptrs) {
        s << child->print() << std::endl;
    }
    return s.str();
}

void Fortran::Driver::increaseLocation(unsigned int loc) {
    m_location += loc;
    cout << "increaseLocation(): " << loc << ", total = " << m_location << endl;
}

unsigned int Fortran::Driver::location() const {
    return m_location;
}