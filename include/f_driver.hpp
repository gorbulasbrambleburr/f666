#ifndef __FDRIVER_HPP__
#define __FDRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>

#include "f_scanner.hpp"
#include "../parser.tab.h"
#include "ast/AST.hpp"

namespace Fortran {

    class Driver {
    public:
        Driver() = default;

        virtual ~Driver();

        void parse(const char *filename);

        node_ptr root();
        node_ptr mainProgram(node_ptr id, node_ptr body);
        node_ptr subroutine(node_ptr id, node_ptrs params, node_ptr body);
        node_ptr function(node_ptr type, node_ptr id, node_ptrs params, node_ptr body);
        node_ptrs parameterList(node_ptr param);
        node_ptr identifier(std::string id);
        node_ptr createType(ast::type type);
        node_ptr body(node_ptr construct);

        std::ostream& print(std::ostream &stream);

    private:
        void parse_helper(std::istream &stream);

        Parser *parser = std::nullptr_t;
        Scanner *scanner = std::nullptr_t;

        /** define some pretty colors **/
        const std::string red  = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };
}
#endif /* END __FDRIVER_HPP__ */