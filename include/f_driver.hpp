#ifndef __FDRIVER_HPP__
#define __FDRIVER_HPP__

#include <string>
#include <vector>
#include <memory>

#include "f_scanner.hpp"
#include "f_parser.hpp"
#include "ast/AST.hpp"
#include "ast/ExecutableProgram.hpp"
#include "ast/MainProgram.hpp"
#include "ast/Subroutine.hpp"
#include "ast/Function.hpp"
#include "ast/Identifier.hpp"
#include "ast/Type.hpp"
#include "ast/Body.hpp"
#include "ast/SpecificationConstruct.hpp"
#include "ast/DeclarationConstruct.hpp"
#include "ast/ExecutableConstruct.hpp"
#include "ast/DeclarationStatement.hpp"
#include "ast/ParameterStatement.hpp"
#include "ast/IdentifierDeclaration.hpp"

using node_ptr = std::shared_ptr<AST>;
using node_ptrs = std::vector<node_ptr>;

namespace Fortran {

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

        node_ptr createRoot();

        // Used by the Parser to create AST nodes
        template<typename NodeType, typename... Args>
        node_ptr createNode(Args&&... args) {
            return node_ptr(new NodeType(std::forward<Args>(args)...));
        }

        // Used by the Parser to create AST node lists
        template<typename... Args>
        node_ptrs createNodeList(Args&&... args) {
            return {args...};
        }

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