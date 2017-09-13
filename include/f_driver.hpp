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

        node_ptr type(ast::type type);
        node_ptr identifier(std::string id);

        std::ostream& print(std::ostream &stream);

    private:
        void parse_helper(std::istream &stream);

        Parser *parser = nullptr;
        Scanner *scanner = nullptr;

        /** define some pretty colors **/
        const std::string red  = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };
}
#endif /* END __FDRIVER_HPP__ */