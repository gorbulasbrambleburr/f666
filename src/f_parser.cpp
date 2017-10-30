// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.
// //                    "%code top" blocks.
#line 32 "bison/f_parser.y" // lalr1.cc:397

    #include <iostream>
    #include "f_scanner.hpp"
    #include "f_parser.hpp"
    #include "f_driver.hpp"
    #include "location.hh"
    #include "../include/Mapper.hpp"

    // This function is called only inside Bison, so we make it static to limit
    // symbol visibility for the linker to avoid potential linking conflicts.
    static Fortran::Parser::symbol_type yylex(Fortran::Scanner &scanner) {
        return scanner.getNextToken();
    }

#line 49 "src/f_parser.cpp" // lalr1.cc:397


// First part of user declarations.

#line 54 "src/f_parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "f_parser.hpp"

// User implementation prologue.

#line 68 "src/f_parser.cpp" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 8 "bison/f_parser.y" // lalr1.cc:479
namespace  Fortran  {
#line 154 "src/f_parser.cpp" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
   Parser ::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
   Parser :: Parser  (Fortran::Scanner &scanner_yyarg, Fortran::Driver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

   Parser ::~ Parser  ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
   Parser ::by_state::by_state ()
    : state (empty_state)
  {}

  inline
   Parser ::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
   Parser ::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
   Parser ::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
   Parser ::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
   Parser ::symbol_number_type
   Parser ::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
   Parser ::stack_symbol_type::stack_symbol_type ()
  {}


  inline
   Parser ::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 44: // ExecutableProgram
      case 45: // Subprogram
      case 46: // MainProgram
      case 47: // Subroutine
      case 48: // Function
      case 49: // FunctionIdentifier
      case 50: // SubroutineIdentifier
      case 51: // ProgramIdentifier
      case 52: // Identifier
      case 54: // Argument
      case 55: // Type
      case 56: // Body
      case 57: // SpecificationConstruct
      case 59: // Specification
      case 60: // DeclarationStatement
      case 62: // IdentifierDeclaration
      case 63: // ParameterStatement
      case 65: // AssignmentStatement
      case 66: // Expression
      case 67: // FunctionCall
      case 68: // Literal
      case 69: // ExecutableConstruct
      case 71: // Statement
      case 72: // IfStatement
      case 74: // ElseIfStatement
      case 77: // ReadStatement
      case 78: // PrintStatement
      case 80: // DoStatement
      case 81: // WhileStatement
      case 82: // CallStatement
        value.move< AST::node_ptr > (that.value);
        break;

      case 53: // ArgumentList
      case 58: // SpecificationList
      case 61: // IdentifierDeclarationList
      case 64: // AssignmentStatementList
      case 70: // ExecutableList
      case 73: // ElseIfStatementList
      case 75: // ElseStatement
      case 76: // StatementList
      case 79: // PrintList
        value.move< AST::node_ptrs > (that.value);
        break;

      case 39: // "BOOLEAN value"
        value.move< Fortran::boolean > (that.value);
        break;

      case 37: // "INTEGER value"
        value.move< Fortran::integer > (that.value);
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        value.move< Fortran::op::arithmetic > (that.value);
        break;

      case 42: // "COMPARISON operator"
        value.move< Fortran::op::comp > (that.value);
        break;

      case 33: // "&&"
      case 34: // "||"
      case 35: // "!"
        value.move< Fortran::op::logic > (that.value);
        break;

      case 38: // "REAL value"
        value.move< Fortran::real > (that.value);
        break;

      case 40: // "STRING value"
      case 41: // "ID identifier"
        value.move< Fortran::string > (that.value);
        break;

      case 36: // "TYPE identifier"
        value.move< Fortran::type > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
   Parser ::stack_symbol_type&
   Parser ::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 44: // ExecutableProgram
      case 45: // Subprogram
      case 46: // MainProgram
      case 47: // Subroutine
      case 48: // Function
      case 49: // FunctionIdentifier
      case 50: // SubroutineIdentifier
      case 51: // ProgramIdentifier
      case 52: // Identifier
      case 54: // Argument
      case 55: // Type
      case 56: // Body
      case 57: // SpecificationConstruct
      case 59: // Specification
      case 60: // DeclarationStatement
      case 62: // IdentifierDeclaration
      case 63: // ParameterStatement
      case 65: // AssignmentStatement
      case 66: // Expression
      case 67: // FunctionCall
      case 68: // Literal
      case 69: // ExecutableConstruct
      case 71: // Statement
      case 72: // IfStatement
      case 74: // ElseIfStatement
      case 77: // ReadStatement
      case 78: // PrintStatement
      case 80: // DoStatement
      case 81: // WhileStatement
      case 82: // CallStatement
        value.copy< AST::node_ptr > (that.value);
        break;

      case 53: // ArgumentList
      case 58: // SpecificationList
      case 61: // IdentifierDeclarationList
      case 64: // AssignmentStatementList
      case 70: // ExecutableList
      case 73: // ElseIfStatementList
      case 75: // ElseStatement
      case 76: // StatementList
      case 79: // PrintList
        value.copy< AST::node_ptrs > (that.value);
        break;

      case 39: // "BOOLEAN value"
        value.copy< Fortran::boolean > (that.value);
        break;

      case 37: // "INTEGER value"
        value.copy< Fortran::integer > (that.value);
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        value.copy< Fortran::op::arithmetic > (that.value);
        break;

      case 42: // "COMPARISON operator"
        value.copy< Fortran::op::comp > (that.value);
        break;

      case 33: // "&&"
      case 34: // "||"
      case 35: // "!"
        value.copy< Fortran::op::logic > (that.value);
        break;

      case 38: // "REAL value"
        value.copy< Fortran::real > (that.value);
        break;

      case 40: // "STRING value"
      case 41: // "ID identifier"
        value.copy< Fortran::string > (that.value);
        break;

      case 36: // "TYPE identifier"
        value.copy< Fortran::type > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
   Parser ::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
   Parser ::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
   Parser ::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
   Parser ::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
   Parser ::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
   Parser ::debug_stream () const
  {
    return *yycdebug_;
  }

  void
   Parser ::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


   Parser ::debug_level_type
   Parser ::debug_level () const
  {
    return yydebug_;
  }

  void
   Parser ::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline  Parser ::state_type
   Parser ::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
   Parser ::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
   Parser ::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
   Parser ::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 44: // ExecutableProgram
      case 45: // Subprogram
      case 46: // MainProgram
      case 47: // Subroutine
      case 48: // Function
      case 49: // FunctionIdentifier
      case 50: // SubroutineIdentifier
      case 51: // ProgramIdentifier
      case 52: // Identifier
      case 54: // Argument
      case 55: // Type
      case 56: // Body
      case 57: // SpecificationConstruct
      case 59: // Specification
      case 60: // DeclarationStatement
      case 62: // IdentifierDeclaration
      case 63: // ParameterStatement
      case 65: // AssignmentStatement
      case 66: // Expression
      case 67: // FunctionCall
      case 68: // Literal
      case 69: // ExecutableConstruct
      case 71: // Statement
      case 72: // IfStatement
      case 74: // ElseIfStatement
      case 77: // ReadStatement
      case 78: // PrintStatement
      case 80: // DoStatement
      case 81: // WhileStatement
      case 82: // CallStatement
        yylhs.value.build< AST::node_ptr > ();
        break;

      case 53: // ArgumentList
      case 58: // SpecificationList
      case 61: // IdentifierDeclarationList
      case 64: // AssignmentStatementList
      case 70: // ExecutableList
      case 73: // ElseIfStatementList
      case 75: // ElseStatement
      case 76: // StatementList
      case 79: // PrintList
        yylhs.value.build< AST::node_ptrs > ();
        break;

      case 39: // "BOOLEAN value"
        yylhs.value.build< Fortran::boolean > ();
        break;

      case 37: // "INTEGER value"
        yylhs.value.build< Fortran::integer > ();
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        yylhs.value.build< Fortran::op::arithmetic > ();
        break;

      case 42: // "COMPARISON operator"
        yylhs.value.build< Fortran::op::comp > ();
        break;

      case 33: // "&&"
      case 34: // "||"
      case 35: // "!"
        yylhs.value.build< Fortran::op::logic > ();
        break;

      case 38: // "REAL value"
        yylhs.value.build< Fortran::real > ();
        break;

      case 40: // "STRING value"
      case 41: // "ID identifier"
        yylhs.value.build< Fortran::string > ();
        break;

      case 36: // "TYPE identifier"
        yylhs.value.build< Fortran::type > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 158 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 782 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 162 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 791 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 168 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 799 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 171 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 807 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 174 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 815 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 179 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 824 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 183 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 832 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 188 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 841 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 192 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 850 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 196 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 858 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 201 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 867 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 205 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 876 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 209 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 884 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 214 "bison/f_parser.y" // lalr1.cc:859
    {
        Entry entry(Fortran::symbol::type::FUNCTION);
        bool inserted = Mapper::instance().insert_fun(yystack_[0].value.as< Fortran::string > (), entry);
        Mapper::instance().create_scope();
        if (!inserted) {
            std::string error = "redefinition of function id '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::FUNCTION);
        }
    }
#line 901 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 228 "bison/f_parser.y" // lalr1.cc:859
    {
        Entry entry(Fortran::symbol::type::SUBROUTINE);
        bool inserted = Mapper::instance().insert_fun(yystack_[0].value.as< Fortran::string > (), entry);
        Mapper::instance().create_scope();
        if (!inserted) {
            std::string error = "redefinition of subroutine id '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::SUBROUTINE);
        }
    }
#line 918 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 242 "bison/f_parser.y" // lalr1.cc:859
    {
        Entry entry(Fortran::symbol::type::PROGRAM);
        bool inserted = Mapper::instance().insert_fun(yystack_[0].value.as< Fortran::string > (), entry);
        Mapper::instance().create_scope();
        if (!inserted) {
            std::string error = "redefinition of program id '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::PROGRAM);
        }
    }
#line 935 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 256 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 943 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 261 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 951 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 264 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 960 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 270 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 968 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 275 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 976 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 280 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 984 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 285 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 992 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 288 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 1000 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 293 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1008 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 296 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1017 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 302 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1025 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 305 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1033 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 310 "bison/f_parser.y" // lalr1.cc:859
    {
        bool any_error = false;
        for (auto& node : yystack_[0].value.as< AST::node_ptrs > ()) {
            Entry entry(yystack_[1].value.as< AST::node_ptr > ()->var_type(), node->struct_type(), Fortran::symbol::type::VARIABLE);
            bool inserted = Mapper::instance().insert_var(node->id(), entry);
            if (!inserted) {
                std::string error_msg = "redeclaration of variable id '" + node->id() + "'";
                driver.semantic_error(error_msg);
                any_error = true;
            }
        }
        if (any_error) {
            std::string error_msg = "redeclaration of variable(s)";
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
        }
    }
#line 1056 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 330 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1064 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 333 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1073 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 339 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1081 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 342 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 1089 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 345 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 1097 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 350 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1105 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 355 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1113 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 358 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1122 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 364 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;
        bool declared = Mapper::instance().lookup_var(yystack_[2].value.as< AST::node_ptr > ()->id());
        if (!declared) {
            error_msg += "variable id '" + yystack_[2].value.as< AST::node_ptr > ()->id() + "' not declared";
            any_error = true;
        } else {
            if (Mapper::instance().var_entry(yystack_[2].value.as< AST::node_ptr > ()->id()).type() == yystack_[0].value.as< AST::node_ptr > ()->var_type()) {
                yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
            } else {
                error_msg += "type mismatch";
                any_error = true;
            }
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }
    }
#line 1147 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 384 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1155 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 389 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1163 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 392 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1171 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 395 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1179 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 398 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1187 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 401 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1195 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 404 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1203 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 407 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1211 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 410 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1219 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 413 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
    }
#line 1227 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 416 "bison/f_parser.y" // lalr1.cc:859
    {
        std::cout << "Creating a function call." << std::endl;
        if (!Mapper::instance().lookup_fun(yystack_[0].value.as< AST::node_ptr > ()->id())) {
            std::string error_msg = "function id '" + yystack_[0].value.as< AST::node_ptr > ()->id() + "' not declared";
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        } else {
            yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
        }
    }
#line 1242 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 426 "bison/f_parser.y" // lalr1.cc:859
    {
        if (!Mapper::instance().lookup_var(yystack_[0].value.as< AST::node_ptr > ()->id())) {
            std::string error_msg = "variable id '" + yystack_[0].value.as< AST::node_ptr > ()->id() + "' not declared";
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        } else {
            yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
        }
    }
#line 1256 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 435 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1264 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 440 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1272 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 445 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1280 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 448 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1288 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 451 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1296 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 454 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::string > ());
    }
#line 1304 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 465 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1312 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 468 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1320 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 473 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1328 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 476 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1337 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 482 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1345 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 485 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1353 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 488 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1361 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 491 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1369 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 494 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1377 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 497 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1385 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 500 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1393 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 514 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1401 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 517 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1409 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 520 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1417 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 525 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1425 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 528 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1434 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 534 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1442 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 539 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1450 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 544 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1458 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 547 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1467 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 553 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ReadStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1475 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 558 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<PrintStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1483 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 563 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1491 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 566 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1500 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 572 "bison/f_parser.y" // lalr1.cc:859
    {
        node_ptr unitary = driver.createNode<Literal>(1);
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[6].value.as< AST::node_ptr > ()),
            std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(unitary), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1510 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 577 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[8].value.as< AST::node_ptr > ()),
            std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1519 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 583 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<WhileStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1527 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 588 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1535 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 591 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(node_ptrs{}));
    }
#line 1543 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1547 "src/f_parser.cpp" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
   Parser ::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
   Parser ::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char  Parser ::yypact_ninf_ = -80;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short int
   Parser ::yypact_[] =
  {
       3,     4,     8,   -80,    27,   -80,   -80,   -80,   -80,     7,
      45,   -80,     5,    36,   -80,    34,   -80,   -80,     9,    64,
      57,    35,    85,   208,     5,   -80,   -80,   -80,    86,   -16,
      91,   -80,    74,   -80,    35,   -80,    79,    90,   -80,   108,
     100,   101,    35,   289,    87,    35,    16,   -80,   -80,   208,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     5,
     -80,    10,   -80,   121,   -12,    50,   -80,   -19,    35,   -80,
     289,   289,   104,   289,   289,   -80,   -80,   -80,   -80,   107,
     302,   -80,   -80,   113,   126,   124,   289,   289,   -80,   145,
      87,     5,   -80,     5,    55,    35,   -80,   129,   131,   -80,
     224,   238,   289,   252,   302,    87,   289,   289,   289,   289,
     289,   289,   289,   289,    -1,   266,   302,   151,   -80,   155,
     161,     5,   -80,   -80,   -80,   162,   147,   210,   -80,    65,
      37,    37,    70,    70,   302,   302,   158,   302,   -80,    72,
     143,   -80,   168,   170,   172,   208,   208,   289,   -80,   -80,
     289,   -80,   -80,   188,   -80,   183,    67,   152,   302,   -80,
     208,   154,   -80,   -80,    98,   -80,   -80,   -80,   289,   125,
     190,   289,   -80,   -80,    89,   -80,   -80,   280,   197,   200,
     -80,   208,   208
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    22,     0,     3,     4,     5,     6,     0,
       0,    17,    25,     0,    16,     0,     1,     2,     0,     0,
       0,     0,     0,    59,    24,    26,    28,    29,     0,     0,
       0,    15,     0,     8,     0,    18,    33,    30,    31,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    23,    58,
      60,    63,    66,    67,    64,    65,    68,    27,    11,    25,
      21,     0,    19,     0,     0,     0,    37,     0,     0,     7,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    51,
      80,    50,    52,    79,    78,     0,     0,     0,    61,     0,
       0,    25,    14,    25,     0,     0,    36,     0,     0,    32,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    20,     0,
       0,    25,    38,    34,    35,     0,     0,     0,    49,     0,
      42,    43,    44,    45,    46,    47,    41,    81,    86,     0,
       0,    10,     0,     0,     0,     0,     0,     0,    53,    85,
       0,     9,    13,     0,    76,     0,     0,     0,    40,    12,
       0,     0,    69,    77,     0,    72,    71,    84,     0,     0,
       0,     0,    73,    70,     0,    82,    75,     0,     0,     0,
      83,     0,    74
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -80,   -80,   217,   -80,   -80,   -80,   -80,   -80,   -80,   -21,
     -41,   132,    61,   -55,   -80,   -80,   199,   -80,   -80,   159,
     -80,   -80,   -33,   -54,   -80,   -80,   -80,   -80,   -15,   -80,
     -80,    68,    69,   -79,   -80,   -80,   -80,   -80,   -80,   -80
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    32,    15,    12,    79,
      61,    62,    21,    22,    23,    24,    25,    26,    37,    38,
      27,    65,    47,    80,    81,    82,    48,    49,   154,    51,
     164,   165,   166,   155,    52,    53,    83,    54,    55,    56
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      36,    66,    46,    84,    89,    10,     1,     2,    50,    13,
      30,    59,    18,    46,    20,    93,   100,   101,    97,   103,
     104,    72,    35,    94,    85,    60,   138,    16,    46,    60,
       1,     2,   115,   116,    88,    90,   119,    91,   120,     3,
      60,     3,    86,    28,    87,    11,    98,    36,   127,    14,
      31,    19,   130,   131,   132,   133,   134,   135,   136,   137,
      29,     9,   122,     3,   129,     9,   144,   156,   108,   109,
     110,   111,    33,   139,    46,    95,    35,    96,   169,    40,
      90,   170,   121,    34,    41,    42,   167,    43,    44,    45,
      90,    39,   148,   157,    58,   178,   158,    90,    63,   149,
      64,    40,   182,   110,   111,    67,    41,    42,    35,    43,
      44,    45,   160,   161,   174,    68,    69,   177,   106,   107,
     108,   109,   110,   111,    46,    46,    70,    71,    60,    92,
      35,   112,   102,   105,    46,    46,    46,    40,   113,    46,
     163,   163,    41,    42,   175,    43,    44,    45,    46,    46,
     114,    90,   117,    46,   163,   163,   123,    46,   124,   141,
      46,    46,   142,   163,    40,   146,    35,   163,   143,    41,
      42,   150,    43,    44,    45,   145,   151,   168,   152,   153,
     171,   106,   107,   108,   109,   110,   111,   106,   107,   108,
     109,   110,   111,    35,   112,    40,   159,   160,   161,   162,
      41,    42,    40,    43,    44,    45,   176,    41,    42,    40,
      43,    44,    45,   181,    41,    42,   180,    43,    44,    45,
      40,    17,   118,    57,    35,    41,    42,    99,    43,    44,
      45,    35,   172,   173,     0,   147,     0,     0,    35,   106,
     107,   108,   109,   110,   111,     0,     0,     0,     0,    35,
       0,   125,   112,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     0,     0,     0,   126,   112,   106,   107,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,   128,
     112,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,   140,   112,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,   179,   112,   106,
     107,   108,   109,   110,   111,    73,     0,     0,     0,     0,
       0,     0,   112,     0,    74,     0,    75,    76,    77,    78,
      35,   106,   107,   108,   109,   110,   111,     0,     0,     0,
       0,     0,     0,     0,   112
  };

  const short int
   Parser ::yycheck_[] =
  {
      21,    34,    23,    44,    59,     1,     3,     4,    23,     1,
       1,    27,     5,    34,     9,    27,    70,    71,    37,    73,
      74,    42,    41,    64,    45,    41,    27,     0,    49,    41,
       3,     4,    86,    87,    49,    25,    91,    27,    93,    36,
      41,    36,    26,     7,    28,    41,    67,    68,   102,    41,
      41,     6,   106,   107,   108,   109,   110,   111,   112,   113,
      26,     0,    95,    36,   105,     4,   121,   146,    31,    32,
      33,    34,     8,   114,    95,    25,    41,    27,   157,    12,
      25,   160,    27,    26,    17,    18,    19,    20,    21,    22,
      25,     6,    27,   147,     8,   174,   150,    25,     7,    27,
      26,    12,   181,    33,    34,    26,    17,    18,    41,    20,
      21,    22,    14,    15,   168,    25,     8,   171,    29,    30,
      31,    32,    33,    34,   145,   146,    26,    26,    41,     8,
      41,    42,    28,    26,   155,   156,   157,    12,    25,   160,
     155,   156,    17,    18,    19,    20,    21,    22,   169,   170,
      26,    25,     7,   174,   169,   170,    27,   178,    27,     8,
     181,   182,     7,   178,    12,    18,    41,   182,     7,    17,
      18,    28,    20,    21,    22,    13,     8,    25,     8,     7,
      26,    29,    30,    31,    32,    33,    34,    29,    30,    31,
      32,    33,    34,    41,    42,    12,     8,    14,    15,    16,
      17,    18,    12,    20,    21,    22,    16,    17,    18,    12,
      20,    21,    22,    13,    17,    18,    19,    20,    21,    22,
      12,     4,    90,    24,    41,    17,    18,    68,    20,    21,
      22,    41,   164,   164,    -1,    25,    -1,    -1,    41,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    41,
      -1,    27,    42,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    42,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      42,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    42,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    27,    42,    29,
      30,    31,    32,    33,    34,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    35,    -1,    37,    38,    39,    40,
      41,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    36,    44,    45,    46,    47,    48,    55,
       1,    41,    51,     1,    41,    50,     0,    45,     5,     6,
       9,    55,    56,    57,    58,    59,    60,    63,     7,    26,
       1,    41,    49,     8,    26,    41,    52,    61,    62,     6,
      12,    17,    18,    20,    21,    22,    52,    65,    69,    70,
      71,    72,    77,    78,    80,    81,    82,    59,     8,    27,
      41,    53,    54,     7,    26,    64,    65,    26,    25,     8,
      26,    26,    52,    26,    35,    37,    38,    39,    40,    52,
      66,    67,    68,    79,    53,    52,    26,    28,    71,    56,
      25,    27,     8,    27,    53,    25,    27,    37,    52,    62,
      66,    66,    28,    66,    66,    26,    29,    30,    31,    32,
      33,    34,    42,    25,    26,    66,    66,     7,    54,    56,
      56,    27,    65,    27,    27,    27,    27,    66,    27,    53,
      66,    66,    66,    66,    66,    66,    66,    66,    27,    53,
      27,     8,     7,     7,    56,    13,    18,    25,    27,    27,
      28,     8,     8,     7,    71,    76,    76,    66,    66,     8,
      14,    15,    16,    71,    73,    74,    75,    19,    25,    76,
      76,    26,    74,    75,    66,    19,    16,    66,    76,    27,
      19,    13,    76
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    48,    49,    50,    51,    52,    53,
      53,    54,    55,    56,    57,    57,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    62,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    68,    68,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    75,    76,    76,    77,    78,
      79,    79,    80,    80,    81,    82,    82
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     4,     8,
       7,     4,     9,     8,     5,     1,     1,     1,     1,     1,
       3,     1,     1,     2,     1,     0,     1,     2,     1,     1,
       2,     1,     3,     1,     4,     4,     4,     1,     3,     3,
       6,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     7,
       8,     7,     1,     2,     6,     3,     1,     2,     2,     2,
       1,     3,     8,    10,     7,     5,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"PROGRAM keyword\"",
  "\"SUBROUTINE keyword\"", "\"FUNCTION keyword\"", "\"STOP keyword\"",
  "\"RETURN keyword\"", "\"END keyword\"", "\"PARAMETER keyword\"",
  "\"CYCLE keyword\"", "\"EXIT keyword\"", "\"IF keyword\"",
  "\"THEN keyword\"", "\"ELSE keyword\"", "\"ELSEIF keyword\"",
  "\"ENDIF keyword\"", "\"WHILE keyword\"", "\"DO keyword\"",
  "\"ENDDO keyword\"", "\"PRINT keyword\"", "\"READ keyword\"",
  "\"CALL keyword\"", "\"ERR keyword\"", "\"new line\"", "\"comma\"",
  "\"left parenthesis\"", "\"right parenthesis\"", "\"=\"", "\"+\"",
  "\"-\"", "\"*\"", "\"/\"", "\"&&\"", "\"||\"", "\"!\"",
  "\"TYPE identifier\"", "\"INTEGER value\"", "\"REAL value\"",
  "\"BOOLEAN value\"", "\"STRING value\"", "\"ID identifier\"",
  "\"COMPARISON operator\"", "$accept", "ExecutableProgram", "Subprogram",
  "MainProgram", "Subroutine", "Function", "FunctionIdentifier",
  "SubroutineIdentifier", "ProgramIdentifier", "Identifier",
  "ArgumentList", "Argument", "Type", "Body", "SpecificationConstruct",
  "SpecificationList", "Specification", "DeclarationStatement",
  "IdentifierDeclarationList", "IdentifierDeclaration",
  "ParameterStatement", "AssignmentStatementList", "AssignmentStatement",
  "Expression", "FunctionCall", "Literal", "ExecutableConstruct",
  "ExecutableList", "Statement", "IfStatement", "ElseIfStatementList",
  "ElseIfStatement", "ElseStatement", "StatementList", "ReadStatement",
  "PrintStatement", "PrintList", "DoStatement", "WhileStatement",
  "CallStatement", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   158,   158,   162,   168,   171,   174,   179,   183,   188,
     192,   196,   201,   205,   209,   214,   228,   242,   256,   261,
     264,   270,   275,   280,   285,   288,   293,   296,   302,   305,
     310,   330,   333,   339,   342,   345,   350,   355,   358,   364,
     384,   389,   392,   395,   398,   401,   404,   407,   410,   413,
     416,   426,   435,   440,   445,   448,   451,   454,   465,   468,
     473,   476,   482,   485,   488,   491,   494,   497,   500,   514,
     517,   520,   525,   528,   534,   539,   544,   547,   553,   558,
     563,   566,   572,   577,   583,   588,   591
  };

  // Print the state stack on the debug stream.
  void
   Parser ::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
   Parser ::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


#line 8 "bison/f_parser.y" // lalr1.cc:1167
} //  Fortran 
#line 2084 "src/f_parser.cpp" // lalr1.cc:1167
#line 604 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   //std::cerr << "Error: " << message << " at " << driver.location() << "\n";
   driver.printError(message);
}
