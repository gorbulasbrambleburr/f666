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
      case 56: // Parameter
      case 57: // Type
      case 58: // Body
      case 59: // SpecificationConstruct
      case 61: // Specification
      case 62: // DeclarationStatement
      case 64: // IdentifierDeclaration
      case 65: // ParameterStatement
      case 67: // AssignmentStatement
      case 68: // Expression
      case 69: // FunctionCall
      case 70: // Literal
      case 71: // ExecutableConstruct
      case 73: // Statement
      case 74: // IfStatement
      case 76: // ElseIfStatement
      case 79: // ReadStatement
      case 80: // PrintStatement
      case 82: // DoStatement
      case 83: // WhileStatement
      case 84: // CallStatement
        value.move< AST::node_ptr > (that.value);
        break;

      case 53: // ArgumentList
      case 55: // ParameterList
      case 60: // SpecificationList
      case 63: // IdentifierDeclarationList
      case 66: // AssignmentStatementList
      case 72: // ExecutableList
      case 75: // ElseIfStatementList
      case 77: // ElseStatement
      case 78: // StatementList
      case 81: // PrintList
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
      case 56: // Parameter
      case 57: // Type
      case 58: // Body
      case 59: // SpecificationConstruct
      case 61: // Specification
      case 62: // DeclarationStatement
      case 64: // IdentifierDeclaration
      case 65: // ParameterStatement
      case 67: // AssignmentStatement
      case 68: // Expression
      case 69: // FunctionCall
      case 70: // Literal
      case 71: // ExecutableConstruct
      case 73: // Statement
      case 74: // IfStatement
      case 76: // ElseIfStatement
      case 79: // ReadStatement
      case 80: // PrintStatement
      case 82: // DoStatement
      case 83: // WhileStatement
      case 84: // CallStatement
        value.copy< AST::node_ptr > (that.value);
        break;

      case 53: // ArgumentList
      case 55: // ParameterList
      case 60: // SpecificationList
      case 63: // IdentifierDeclarationList
      case 66: // AssignmentStatementList
      case 72: // ExecutableList
      case 75: // ElseIfStatementList
      case 77: // ElseStatement
      case 78: // StatementList
      case 81: // PrintList
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
      case 56: // Parameter
      case 57: // Type
      case 58: // Body
      case 59: // SpecificationConstruct
      case 61: // Specification
      case 62: // DeclarationStatement
      case 64: // IdentifierDeclaration
      case 65: // ParameterStatement
      case 67: // AssignmentStatement
      case 68: // Expression
      case 69: // FunctionCall
      case 70: // Literal
      case 71: // ExecutableConstruct
      case 73: // Statement
      case 74: // IfStatement
      case 76: // ElseIfStatement
      case 79: // ReadStatement
      case 80: // PrintStatement
      case 82: // DoStatement
      case 83: // WhileStatement
      case 84: // CallStatement
        yylhs.value.build< AST::node_ptr > ();
        break;

      case 53: // ArgumentList
      case 55: // ParameterList
      case 60: // SpecificationList
      case 63: // IdentifierDeclarationList
      case 66: // AssignmentStatementList
      case 72: // ExecutableList
      case 75: // ElseIfStatementList
      case 77: // ElseStatement
      case 78: // StatementList
      case 81: // PrintList
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
#line 160 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 788 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 164 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 797 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 170 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 805 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 173 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 813 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 176 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 821 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 181 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 830 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 185 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 838 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 190 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 847 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 194 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::instance().reset();
    }
#line 856 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 198 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 864 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 203 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        if (Mapper::instance().lookup_var(yystack_[6].value.as< AST::node_ptr > ()->id())) {
            Entry tmp = Mapper::instance().var_entry(yystack_[6].value.as< AST::node_ptr > ()->id());
            
            // Check function return type
            if (tmp.type() == yystack_[8].value.as< AST::node_ptr > ()->var_type()) {
                
                // Check arguments declarations
                std::string args = "";
                for (auto& arg : yystack_[4].value.as< AST::node_ptrs > ()) {
                    if (!Mapper::instance().lookup_var(arg->id())) {
                        args += arg->id() + ", ";
                        any_error = true;
                    }
                }
                if (any_error) {
                    error_msg += "argument ids [" + args + "] were not defined in function body";
                } else {
                    Entry entry(Fortran::symbol::type::FUNCTION, yystack_[8].value.as< AST::node_ptr > ()->var_type(), tmp.dimension(), yystack_[4].value.as< AST::node_ptrs > ());
                    bool inserted = Mapper::instance().insert_fun(yystack_[6].value.as< AST::node_ptr > ()->id(), entry);
                    if (inserted) {
                        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
                    } else {
                        error_msg += "redefinition of function id '" + yystack_[6].value.as< AST::node_ptr > ()->id() + "'";
                        any_error = true;
                    }
                }
            } else {
                error_msg += "type mismatch between var id '" + yystack_[6].value.as< AST::node_ptr > ()->id() + "' and function return type.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + yystack_[6].value.as< AST::node_ptr > ()->id() + "' was not defined in function body.";
            any_error = true;
        }

        // Create fake node
        if(any_error) {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::instance().reset();
    }
#line 916 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 250 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        if (Mapper::instance().lookup_var(yystack_[5].value.as< AST::node_ptr > ()->id())) {
            Entry tmp = Mapper::instance().var_entry(yystack_[5].value.as< AST::node_ptr > ()->id());
            
            // Check function return type
            if (tmp.type() == yystack_[7].value.as< AST::node_ptr > ()->var_type()) {

                Entry entry(Fortran::symbol::type::FUNCTION, yystack_[7].value.as< AST::node_ptr > ()->var_type(), tmp.dimension(), node_ptrs{});
                bool inserted = Mapper::instance().insert_fun(yystack_[5].value.as< AST::node_ptr > ()->id(), entry);
                if (inserted) {
                    yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
                } else {
                    error_msg += "redefinition of function id '" + yystack_[5].value.as< AST::node_ptr > ()->id() + "'";
                    any_error = true;
                }
            } else {
                error_msg += "type mismatch between var id '" + yystack_[5].value.as< AST::node_ptr > ()->id() + "' and function return type.";
                any_error = true;
            }
        } else {
            error_msg += "function id '" + yystack_[5].value.as< AST::node_ptr > ()->id() + "' was not defined in function body.";
            any_error = true;
        }

        // Create fake node
        if(any_error) {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::instance().reset();
    }
#line 956 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 285 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
        std::string error_msg = "syntax error";
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
    }
#line 966 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 292 "bison/f_parser.y" // lalr1.cc:859
    {
        Mapper::instance().create_scope();
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::FUNCTION);
    }
#line 975 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 298 "bison/f_parser.y" // lalr1.cc:859
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
#line 992 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 312 "bison/f_parser.y" // lalr1.cc:859
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
#line 1009 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 326 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 1017 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 331 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1025 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 334 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1034 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 340 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 1042 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 345 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1050 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 348 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1059 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 354 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1067 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 357 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1075 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 362 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 1083 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 367 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1091 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 372 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1099 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 375 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 1107 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 380 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1115 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 383 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1124 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 389 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1132 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 392 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1140 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 397 "bison/f_parser.y" // lalr1.cc:859
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
        if(any_error) {
            std::string error_msg = "redeclaration of variable(s)";
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
        }
    }
#line 1163 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 417 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1171 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 420 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1180 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 426 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1188 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 429 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 1196 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 432 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 1204 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 437 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1212 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 442 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1220 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 445 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1229 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 451 "bison/f_parser.y" // lalr1.cc:859
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
#line 1254 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 471 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1262 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 476 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1270 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 479 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1278 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 482 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1286 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 485 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1294 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 488 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1302 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 491 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1310 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 494 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1318 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 497 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1326 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 500 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
    }
#line 1334 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 503 "bison/f_parser.y" // lalr1.cc:859
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
#line 1349 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 513 "bison/f_parser.y" // lalr1.cc:859
    {
        if (!Mapper::instance().lookup_var(yystack_[0].value.as< AST::node_ptr > ()->id())) {
            std::string error_msg = "variable id '" + yystack_[0].value.as< AST::node_ptr > ()->id() + "' not declared";
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        } else {
            yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
        }
    }
#line 1363 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 522 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1371 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 527 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1379 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 530 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[2].value.as< AST::node_ptr > ()), node_ptrs{});
    }
#line 1387 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 535 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1395 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 538 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1403 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 541 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1411 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 544 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::string > ());
    }
#line 1419 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 555 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1427 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 558 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1435 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 563 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1443 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 566 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1452 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 572 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1460 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 575 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1468 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 578 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1476 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 581 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1484 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 584 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1492 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 587 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1500 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 590 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1508 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 604 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1516 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 607 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1524 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 610 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1532 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 615 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1540 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 618 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1549 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 624 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1557 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 629 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1565 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 634 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1573 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 637 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1582 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 643 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ReadStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1590 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 648 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<PrintStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1598 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 653 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1606 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 656 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1615 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 662 "bison/f_parser.y" // lalr1.cc:859
    {
        node_ptr unitary = driver.createNode<Literal>(1);
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[6].value.as< AST::node_ptr > ()),
            std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(unitary), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1625 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 667 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[8].value.as< AST::node_ptr > ()),
            std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1634 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 673 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<WhileStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1642 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 678 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1650 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 91:
#line 681 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(node_ptrs{}));
    }
#line 1658 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1662 "src/f_parser.cpp" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -92;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short int
   Parser ::yypact_[] =
  {
       3,     4,     9,   -92,    40,   -92,   -92,   -92,   -92,    13,
      25,   -92,     6,    42,   -92,    11,   -92,   -92,    10,    52,
      59,    23,    76,   215,     6,   -92,   -92,   -92,    90,   -19,
      95,   -92,   104,   -92,    23,   -92,   112,    93,   -92,   113,
     142,   143,    23,   268,    84,    23,    55,   -92,   -92,   215,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     6,
     -92,    92,   -92,   149,   -15,    99,   -92,   -12,    23,   -92,
     268,   268,   166,   268,   268,   -92,   -92,   -92,   -92,   170,
      80,   -92,   -92,   172,   173,   177,   268,   268,   -92,   192,
      84,     6,   -92,     6,   117,    23,   -92,   193,   201,   -92,
      38,   217,   268,   231,    80,   202,   268,   268,   268,   268,
     268,   268,   268,   268,     0,   245,    80,   222,   -92,   227,
     246,     6,   -92,   -92,   -92,   239,   236,   153,   -92,   -92,
     -92,   133,   -92,   -92,    56,    56,    44,    44,    80,    80,
     237,    80,   -92,   148,   229,   -92,   247,   277,   288,   215,
     215,   268,   243,   -92,   -92,   268,   -92,   -92,   289,   -92,
     190,   115,    74,   -92,    80,   -92,   215,   270,   -92,   -92,
     150,   -92,   -92,   -92,   268,   131,   197,   268,   -92,   -92,
     159,   -92,   -92,   259,   204,   285,   -92,   215,   215
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    26,     0,     3,     4,     5,     6,     0,
       0,    17,    29,     0,    16,     0,     1,     2,     0,     0,
       0,     0,     0,    64,    28,    30,    32,    33,     0,     0,
       0,    15,     0,     8,     0,    18,    37,    34,    35,     0,
       0,     0,     0,     0,     0,     0,     0,    67,    27,    63,
      65,    68,    71,    72,    69,    70,    73,    31,    11,    29,
      21,     0,    19,     0,     0,     0,    41,     0,     0,     7,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    55,
      85,    54,    56,    84,    83,     0,     0,     0,    66,     0,
       0,    29,    14,    29,     0,     0,    40,     0,     0,    36,
       0,     0,     0,     0,    52,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,    20,     0,
       0,    29,    42,    38,    39,     0,     0,     0,    53,    58,
      24,     0,    22,    25,    46,    47,    48,    49,    50,    51,
      45,    86,    91,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    57,    90,     0,     9,    13,     0,    81,
       0,     0,     0,    23,    44,    12,     0,     0,    74,    82,
       0,    77,    76,    89,     0,     0,     0,     0,    78,    75,
       0,    87,    80,     0,     0,     0,    88,     0,    79
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -92,   -92,   295,   -92,   -92,   -92,   -92,   -92,   -92,   -21,
     -41,   210,   -92,   152,    30,   -55,   -92,   -92,   278,   -92,
     -92,   242,   -92,   -92,   -33,   -54,   -92,   -91,   -92,   -92,
     -14,   -92,   -92,   141,   144,   -87,   -92,   -92,   -92,   -92,
     -92,   -92
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    32,    15,    12,    79,
      61,    62,   131,   132,    21,    22,    23,    24,    25,    26,
      37,    38,    27,    65,    47,    80,    81,    82,    48,    49,
     159,    51,   170,   171,   172,   160,    52,    53,    83,    54,
      55,    56
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      36,    66,    46,    84,    89,    10,     1,     2,    59,    50,
      13,    30,    93,    46,   133,    20,   100,   101,    18,   103,
     104,    72,    60,    94,    85,    97,    60,   142,    46,    35,
       9,    19,   115,   116,     9,    88,   119,    29,   120,     3,
      16,    60,     3,     1,     2,    11,    98,    36,   127,    28,
      14,    31,   134,   135,   136,   137,   138,   139,   140,   141,
      33,   133,   122,   161,    35,   125,   148,   106,   107,   108,
     109,   110,   111,   143,    46,   175,     3,   110,   111,   176,
     112,    86,    39,    87,   130,    34,    40,   108,   109,   110,
     111,    41,    42,   184,    43,    44,    45,   162,    58,   174,
     188,   164,    63,   106,   107,   108,   109,   110,   111,   106,
     107,   108,   109,   110,   111,    35,   112,    90,    68,    91,
     180,    69,   112,   183,    95,    60,    96,    40,    46,    46,
      64,   130,    41,    42,   173,    43,    44,    45,    67,    46,
      46,    46,    90,    40,   121,    46,   169,   169,    41,    42,
     181,    43,    44,    45,    46,    46,    35,    92,   152,    46,
     153,   169,   169,    46,   166,   167,    46,    46,    70,    71,
     169,    40,    35,    90,   169,   154,    41,    42,   151,    43,
      44,    45,   106,   107,   108,   109,   110,   111,   106,   107,
     108,   109,   110,   111,   102,   112,   105,   113,    90,   117,
      35,   112,    40,   114,   166,   167,   168,    41,    42,    40,
      43,    44,    45,   182,    41,    42,    40,    43,    44,    45,
     123,    41,    42,   186,    43,    44,    45,    40,   124,   129,
     145,    35,    41,    42,   146,    43,    44,    45,    35,    75,
      76,    77,    78,    35,   126,    35,   106,   107,   108,   109,
     110,   111,   149,   147,   150,   156,    35,   155,   128,   112,
     106,   107,   108,   109,   110,   111,   106,   107,   108,   109,
     110,   111,   144,   112,   106,   107,   108,   109,   110,   111,
      75,    76,    77,    78,    35,   157,   185,   112,   106,   107,
     108,   109,   110,   111,    73,   158,   177,   165,   187,    17,
     118,   112,    57,    74,   163,    75,    76,    77,    78,    35,
      99,   178,     0,     0,   179
  };

  const short int
   Parser ::yycheck_[] =
  {
      21,    34,    23,    44,    59,     1,     3,     4,    27,    23,
       1,     1,    27,    34,   105,     9,    70,    71,     5,    73,
      74,    42,    41,    64,    45,    37,    41,    27,    49,    41,
       0,     6,    86,    87,     4,    49,    91,    26,    93,    36,
       0,    41,    36,     3,     4,    41,    67,    68,   102,     7,
      41,    41,   106,   107,   108,   109,   110,   111,   112,   113,
       8,   152,    95,   150,    41,    27,   121,    29,    30,    31,
      32,    33,    34,   114,    95,   162,    36,    33,    34,   166,
      42,    26,     6,    28,   105,    26,    12,    31,    32,    33,
      34,    17,    18,   180,    20,    21,    22,   151,     8,    25,
     187,   155,     7,    29,    30,    31,    32,    33,    34,    29,
      30,    31,    32,    33,    34,    41,    42,    25,    25,    27,
     174,     8,    42,   177,    25,    41,    27,    12,   149,   150,
      26,   152,    17,    18,    19,    20,    21,    22,    26,   160,
     161,   162,    25,    12,    27,   166,   160,   161,    17,    18,
      19,    20,    21,    22,   175,   176,    41,     8,    25,   180,
      27,   175,   176,   184,    14,    15,   187,   188,    26,    26,
     184,    12,    41,    25,   188,    27,    17,    18,    25,    20,
      21,    22,    29,    30,    31,    32,    33,    34,    29,    30,
      31,    32,    33,    34,    28,    42,    26,    25,    25,     7,
      41,    42,    12,    26,    14,    15,    16,    17,    18,    12,
      20,    21,    22,    16,    17,    18,    12,    20,    21,    22,
      27,    17,    18,    19,    20,    21,    22,    12,    27,    27,
       8,    41,    17,    18,     7,    20,    21,    22,    41,    37,
      38,    39,    40,    41,    27,    41,    29,    30,    31,    32,
      33,    34,    13,     7,    18,     8,    41,    28,    27,    42,
      29,    30,    31,    32,    33,    34,    29,    30,    31,    32,
      33,    34,    27,    42,    29,    30,    31,    32,    33,    34,
      37,    38,    39,    40,    41,     8,    27,    42,    29,    30,
      31,    32,    33,    34,    26,     7,    26,     8,    13,     4,
      90,    42,    24,    35,   152,    37,    38,    39,    40,    41,
      68,   170,    -1,    -1,   170
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    36,    44,    45,    46,    47,    48,    57,
       1,    41,    51,     1,    41,    50,     0,    45,     5,     6,
       9,    57,    58,    59,    60,    61,    62,    65,     7,    26,
       1,    41,    49,     8,    26,    41,    52,    63,    64,     6,
      12,    17,    18,    20,    21,    22,    52,    67,    71,    72,
      73,    74,    79,    80,    82,    83,    84,    61,     8,    27,
      41,    53,    54,     7,    26,    66,    67,    26,    25,     8,
      26,    26,    52,    26,    35,    37,    38,    39,    40,    52,
      68,    69,    70,    81,    53,    52,    26,    28,    73,    58,
      25,    27,     8,    27,    53,    25,    27,    37,    52,    64,
      68,    68,    28,    68,    68,    26,    29,    30,    31,    32,
      33,    34,    42,    25,    26,    68,    68,     7,    54,    58,
      58,    27,    67,    27,    27,    27,    27,    68,    27,    27,
      52,    55,    56,    70,    68,    68,    68,    68,    68,    68,
      68,    68,    27,    53,    27,     8,     7,     7,    58,    13,
      18,    25,    25,    27,    27,    28,     8,     8,     7,    73,
      78,    78,    68,    56,    68,     8,    14,    15,    16,    73,
      75,    76,    77,    19,    25,    78,    78,    26,    76,    77,
      68,    19,    16,    68,    78,    27,    19,    13,    78
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    48,    49,    50,    51,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    64,    64,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    76,
      77,    78,    78,    79,    80,    81,    81,    82,    82,    83,
      84,    84
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     4,     8,
       7,     4,     9,     8,     5,     1,     1,     1,     1,     1,
       3,     1,     1,     3,     1,     1,     1,     2,     1,     0,
       1,     2,     1,     1,     2,     1,     3,     1,     4,     4,
       4,     1,     3,     3,     6,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     0,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     7,     8,     7,     1,     2,     6,
       3,     1,     2,     2,     2,     1,     3,     8,    10,     7,
       5,     4
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
  "ArgumentList", "Argument", "ParameterList", "Parameter", "Type", "Body",
  "SpecificationConstruct", "SpecificationList", "Specification",
  "DeclarationStatement", "IdentifierDeclarationList",
  "IdentifierDeclaration", "ParameterStatement", "AssignmentStatementList",
  "AssignmentStatement", "Expression", "FunctionCall", "Literal",
  "ExecutableConstruct", "ExecutableList", "Statement", "IfStatement",
  "ElseIfStatementList", "ElseIfStatement", "ElseStatement",
  "StatementList", "ReadStatement", "PrintStatement", "PrintList",
  "DoStatement", "WhileStatement", "CallStatement", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   160,   160,   164,   170,   173,   176,   181,   185,   190,
     194,   198,   203,   250,   285,   292,   298,   312,   326,   331,
     334,   340,   345,   348,   354,   357,   362,   367,   372,   375,
     380,   383,   389,   392,   397,   417,   420,   426,   429,   432,
     437,   442,   445,   451,   471,   476,   479,   482,   485,   488,
     491,   494,   497,   500,   503,   513,   522,   527,   530,   535,
     538,   541,   544,   555,   558,   563,   566,   572,   575,   578,
     581,   584,   587,   590,   604,   607,   610,   615,   618,   624,
     629,   634,   637,   643,   648,   653,   656,   662,   667,   673,
     678,   681
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
#line 2198 "src/f_parser.cpp" // lalr1.cc:1167
#line 694 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   //std::cerr << "Error: " << message << " at " << driver.location() << "\n";
   driver.printError(message);
}
