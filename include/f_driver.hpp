#ifndef __FDRIVER_HPP__
#define __FDRIVER_HPP__

#include <string>
#include <vector>
#include <memory>
//#include <cstddef>
//#include <istream>

#include "f_scanner.hpp"
#include "../parser.tab.h"
//#include "ast/AST.hpp"

using node_ptr = std::unique_ptr<AST>;
using node_ptrs = std::vector<node_ptr>;

namespace Fortran {

    // Forward declare the AST node class so we
    // can declare container for it without the header
    class AST;

    /**
     * This class is the interface for our scanner/lexer. The end user
     * is expected to use this. It drives scanner/lexer, keeps
     * parsed AST and generally is a good place to store additional
     * context data. Both parser and lexer have access to it via internal 
     * references.
     */ 
    class Driver {
    public:
        Driver();

        bool createBoolean(const std::string &);
        bool createInteger(const std::string &);
        bool createReal(const std::string &);

        void parse(const char *filename);


        // Print AST
        std::string print() const;

        /**
         * This is needed so that Scanner and Parser can call some
         * methods that we want to keep hidden from the end user.
         */
        friend class Parser;
        friend class Scanner;

    private:

        // Used by the Parser to create AST nodes
        template<typename NodeType, typename... Args>
        node_ptr Fortran::Driver::createNode(Args&&... args);

        // Used by the Parser to create AST node lists
        template<typename... Args>
        node_ptrs Fortran::Driver::createNodeList(Args&&... args);

        void parse_helper(std::istream &stream);

        // Used internally by Scanner YY_USER_ACTION to update location indicator
        void increaseLocation(unsigned int loc);

        // Used to get last Scanner location. Used in error messages.
        unsigned int location() const;

    private:
        Parser m_parser;
        Scanner m_scanner;
        node_ptrs m_nodes;
        unsigned int m_location; // Used by scanner
    };
}
#endif /* END __FDRIVER_HPP__ */