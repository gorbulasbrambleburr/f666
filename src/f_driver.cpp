#include <cctype>
#include <fstream>
#include <cassert>
#include <istream>

#include "../include/f_driver.hpp"
#include "LLVM_AssemblyGenerator.hpp"

Fortran::Driver::Driver() :
    m_root(nullptr),
    m_scanner(*this),
    m_parser(m_scanner, *this),
    m_location(0),
    m_line(1),
    m_errors(0) {
}

node_ptr Fortran::Driver::createRoot() {
    m_root = std::move(createNode<ExecutableProgram>(node_ptrs{}));
    return m_root;
}

bool Fortran::Driver::createBoolean(const std::string &text) {
    return text == "TRUE";
}

int Fortran::Driver::createInteger(const std::string &text) {
    return std::stoi(text);
}

double Fortran::Driver::createReal(const std::string &text) {
    return std::stod(text);
}

void Fortran::Driver::generateCode() {
    LLVM_AssemblyGenerator generator;
    generator.generateCode(m_root);
}

int Fortran::Driver::parse(const char * const filename) {
    assert(filename != nullptr);
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        return EXIT_FAILURE;
    }
    m_location = 0;
    switchInputStream(&in_file);
    int res = m_parser.parse();
    return res || m_errors;
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
    std::cout << "AST:" << std::endl;
    m_root->print(4);
}

void Fortran::Driver::printError(const std::string &message) {
    std::cout << "Error (" << m_red << m_line << m_green << "): " << message << std::endl;
    m_errors++;
}

void Fortran::Driver::semantic_error(const std::string &message) {
    std::cout << "Error (" << m_red << m_line << m_green << "): " << message << std::endl; 
    m_errors++;
}

void Fortran::Driver::increaseLocation(unsigned int loc) {
    m_location += loc;
}

unsigned int Fortran::Driver::location() const {
    return m_location;
}

void Fortran::Driver::newline() {
    m_line++;
}

unsigned int Fortran::Driver::line() const {
    return m_line;
}