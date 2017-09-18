#include <cctype>
#include <fstream>
#include <cassert>
#include <istream>

#include "../include/f_driver.hpp"

Fortran::Driver::Driver() :
    m_root(nullptr),
    m_scanner(*this),
    m_parser(m_scanner, *this),
    m_location(0) {
}

node_ptr Fortran::Driver::createRoot() {
    m_root = std::move(createNode<ExecutableProgram>(node_ptrs{}));
    return m_root;
}

template<typename NodeType, typename ...Args>
node_ptr Fortran::Driver::createNode(Args&&... args) {
    return node_ptr(new NodeType(std::forward<Args>(args)...));
}

template<typename ...Args>
node_ptrs Fortran::Driver::createNodeList(Args&&... args) {
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

int Fortran::Driver::parse(const char * const filename) {
    assert(filename != nullptr);
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        return EXIT_FAILURE;
    }
    m_location = 0;
    switchInputStream(&in_file);
    return m_parser.parse();
}

void Fortran::Driver::switchInputStream(std::istream *is) {
    m_scanner.switch_streams(is, NULL);
    m_root = nullptr;
}

void Fortran::Driver::clear() {
    m_location = 0;
    m_root = nullptr;
}

void Fortran::Driver::print() const {
    std::cout << "Results:" << std::endl;
    m_root->print();
}

void Fortran::Driver::increaseLocation(unsigned int loc) {
    m_location += loc;
    std::cout << "increaseLocation(): " << loc << ", total = " << m_location << std::endl;
}

unsigned int Fortran::Driver::location() const {
    return m_location;
}