#ifndef __FDRIVER_HPP__
#define __FDRIVER_HPP__

#include <string>
#include <vector>
#include <memory>

#include "f_scanner.hpp"
#include "ast/AST.hpp"
#include "../include/ast/ExecutableProgram.hpp"
#include "../include/ast/MainProgram.hpp"
#include "../include/ast/Subroutine.hpp"
#include "../include/ast/Function.hpp"

using node_ptr = std::unique_ptr<AST>;
using node_ptrs = std::vector<node_ptr>;

namespace Fortran {

    // Forward declare the AST node class so we
    // can declare container for it without the header
    //class AST;

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
        int createInteger(const std::string &);
        float createReal(const std::string &);

        int parse(const char * const filename);

        AST* createRoot();

        // Used by the Parser to create AST nodes
        template<typename NodeType, typename... Args>
        node_ptr createNode(Args&&... args);

        // Used by the Parser to create AST node lists
        template<typename... Args>
        node_ptrs createNodeList(Args&&... args);

        void switchInputStream(std::istream *is);

        // Print AST
        void print() const;

        /**
         * This is needed so that Scanner and Parser can call some
         * methods that we want to keep hidden from the end user.
         */
        friend class Parser;
        friend class Scanner;

    private:
        void clear();

        // Used internally by Scanner YY_USER_ACTION to update location indicator
        void increaseLocation(unsigned int loc);

        // Used to get last Scanner location. Used in error messages.
        unsigned int location() const;

    private:
        node_ptr m_root;
        Scanner m_scanner;
        Parser m_parser;
        unsigned int m_location; // Used by scanner
    };
}
#endif /* END __FDRIVER_HPP__ */