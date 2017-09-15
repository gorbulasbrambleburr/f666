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

node_ptr Fortran::Driver::root() {
    node_ptr node(new ExecutableProgram);
    return node;
}

node_ptr Fortran::Driver::mainProgram(node_ptr id, node_ptr body) {
    node_ptr node(new MainProgram(std::move(id), std::move(body)));
    return node;
}

node_ptr Fortran::Driver::subroutine(node_ptr id, node_ptrs params, node_ptr body) {
    node_ptr node(new Subroutine(std::move(id), params, std::move(body)));
    return node;
}

node_ptr Fortran::Driver::function(node_ptr type, node_ptr id, node_ptrs params, node_ptr body) {
    node_ptr node(new Function(std::move(type), std::move(id), params, std::move(body)));
    return node;
}

node_ptrs Fortran::Driver::parameterList(node_ptr param) {
    node_ptrs params;
    params.emplace_back(param);
    return params;
}

node_ptr Fortran::Driver::identifier(std::string id) {
    node_ptr node(new Identifier(id));
    return node;
}

node_ptr Fortran::Driver::createType(ast::type type) {
    node_ptr node(new Type(type));
    return node;
}

node_ptr Fortran::Driver::body(node_ptr construct) {
    node_ptr node(new Body(construct));
    return node;
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