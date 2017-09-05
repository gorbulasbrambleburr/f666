#ifndef __FSCANNER_HPP__
#define __FSCANNER_HPP__

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "f_parser.tab.hh"
#include "location.hh"

namespace Fortran {

    class Scanner : public yyFlexLexer {
    public:
        Scanner(std::istream *in) : yyFlexLexer(in) {
            loc = new Fortran::Parser::location_type();
        }

        using FlexLexer::yylex;

        virtual int yylex(Fortran::Parser::semantinc_type * const lval,
                          Fortran::Parser::location_type *location);
        // YY_DECL defined in scanner.l
        // Method body created by flex in scanner.yy.cc

    private:
        Fortran::Parser::semantinc_type *yylval = nullptr;
        Fortran::Parser::location_type *loc = nullptr;
    };
}

#endif /* END __FSCANNER_HPP__ */