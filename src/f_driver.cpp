#include <cctype>
#include <fstream>
#include <cassert>

#include "../include/f_driver.hpp"

Fortran::Driver::~Driver() {
    delete(scanner);
    scanner = nullptr;
    delete(parser);
    parser = nullptr;
}

void
Fortran::Driver::parse(const char * const filename) {
    assert(filename != nullptr);
    std::ifstream in_file(filename);
    if (!in_file.good()) {
        exit(EXIT_FAILURE);
    }
    parse_helper(in_file);
    return;
}

void
Fortran::Driver::parse_helper(std::istream &stream) {
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

std::ostream&
Fortran::Driver::print(std::ostream &stream) {
    stream << blue << "Results:\n";
    return(stream);
}