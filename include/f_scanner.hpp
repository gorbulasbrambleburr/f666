#ifndef __FSCANNER_HPP__
#define __FSCANNER_HPP__

/**
 * Generated Flex class name is yyFlexLexer by default. If we want to use more flex-generated
 * classes we should name them differently. See scanner.l prefix option.
 * 
 * Unfortunately the implementation relies on this trick with redefining class name
 * with a preprocessor macro. See GNU Flex manual, "Generating C++ Scanners" section
 */
#if ! defined(yyFlexLexerOnce)
#undef yyFlexLexer
#define yyFlexLexer Fortran_FlexLexer // the trick with prefix; no namespace here :(
#include <FlexLexer.h>
#endif

// Scanner method signature is defined by this macro. Original yylex() returns int.
// Since Bison 3 uses symbol_type, we must change returned type. We also rename it
// to something sane, since you cannot overload return type.
#undef YY_DECL
#define YY_DECL Fortran::Parser::symbol_type Fortran::Scanner::getNextToken()

#include "f_parser.hpp" // this is needed for symbol_type

namespace Fortran {

    class Driver;

    class Scanner : public yyFlexLexer {
    public:
        Scanner(Fortran::Driver &driver) : m_driver(driver) {}
        virtual ~Scanner() {}
        virtual Fortran::Parser::symbol_type getNextToken();

    private:
        Fortran::Driver &m_driver;
    };
}

#endif /* END __FSCANNER_HPP__ */