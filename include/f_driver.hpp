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
#include "ast/ExecutableConstruct.hpp"
#include "ast/DeclarationStatement.hpp"
#include "ast/ParameterStatement.hpp"
#include "ast/IdentifierDeclaration.hpp"
#include "ast/AssignmentStatement.hpp"
#include "ast/Expression.hpp"
#include "ast/Comparison.hpp"
#include "ast/Literal.hpp"
#include "ast/IfStatement.hpp"
#include "ast/ElseIfStatement.hpp"
#include "ast/DoStatement.hpp"
#include "ast/WhileStatement.hpp"
#include "ast/ReadStatement.hpp"
#include "ast/PrintStatement.hpp"
#include "ast/CallStatement.hpp"
#include "ast/FunctionCall.hpp"
#include "ast/ErrorNode.hpp"

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
        double createReal(const std::string &);

        int parse(const char * const filename);
        void generateCode();

        node_ptr createRoot();
        node_ptr root() const {
            return m_root;
        }

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

        // Print error
        void printError(const std::string &message);
        void semantic_error(const std::string &message);

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

        // Update line number
        void newline();

        unsigned int line() const;

    private:
        node_ptr m_root;
        Scanner m_scanner;
        Parser m_parser;
        unsigned int m_location; // Used by scanner
        unsigned int m_line;
        unsigned int m_errors;
        const std::string m_red = "\033[1;31m";
        const std::string m_green = "\033[0m";
    };
}
#endif /* END __FDRIVER_HPP__ */