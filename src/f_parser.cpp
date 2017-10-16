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
#line 31 "bison/f_parser.y" // lalr1.cc:397

    #include <iostream>
    #include "f_scanner.hpp"
    #include "f_parser.hpp"
    #include "f_driver.hpp"
    #include "location.hh"

    // This function is called only inside Bison, so we make it static to limit
    // symbol visibility for the linker to avoid potential linking conflicts.
    static Fortran::Parser::symbol_type yylex(Fortran::Scanner &scanner) {
        return scanner.getNextToken();
    }

#line 48 "src/f_parser.cpp" // lalr1.cc:397


// First part of user declarations.

#line 53 "src/f_parser.cpp" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "f_parser.hpp"

// User implementation prologue.

#line 67 "src/f_parser.cpp" // lalr1.cc:412


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
#line 153 "src/f_parser.cpp" // lalr1.cc:479

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
      case 49: // Identifier
      case 51: // Argument
      case 52: // Type
      case 53: // Body
      case 54: // SpecificationConstruct
      case 56: // Specification
      case 57: // DeclarationStatement
      case 59: // IdentifierDeclaration
      case 60: // ParameterStatement
      case 62: // AssignmentStatement
      case 63: // Expression
      case 64: // FunctionCall
      case 65: // Literal
      case 66: // ExecutableConstruct
      case 68: // Statement
      case 69: // IfStatement
      case 71: // ElseIfStatement
      case 74: // ReadStatement
      case 75: // PrintStatement
      case 77: // DoStatement
      case 78: // WhileStatement
      case 79: // CallStatement
        value.move< AST::node_ptr > (that.value);
        break;

      case 50: // ArgumentList
      case 55: // SpecificationList
      case 58: // IdentifierDeclarationList
      case 61: // AssignmentStatementList
      case 67: // ExecutableList
      case 70: // ElseIfStatementList
      case 72: // ElseStatement
      case 73: // StatementList
      case 76: // PrintList
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
      case 49: // Identifier
      case 51: // Argument
      case 52: // Type
      case 53: // Body
      case 54: // SpecificationConstruct
      case 56: // Specification
      case 57: // DeclarationStatement
      case 59: // IdentifierDeclaration
      case 60: // ParameterStatement
      case 62: // AssignmentStatement
      case 63: // Expression
      case 64: // FunctionCall
      case 65: // Literal
      case 66: // ExecutableConstruct
      case 68: // Statement
      case 69: // IfStatement
      case 71: // ElseIfStatement
      case 74: // ReadStatement
      case 75: // PrintStatement
      case 77: // DoStatement
      case 78: // WhileStatement
      case 79: // CallStatement
        value.copy< AST::node_ptr > (that.value);
        break;

      case 50: // ArgumentList
      case 55: // SpecificationList
      case 58: // IdentifierDeclarationList
      case 61: // AssignmentStatementList
      case 67: // ExecutableList
      case 70: // ElseIfStatementList
      case 72: // ElseStatement
      case 73: // StatementList
      case 76: // PrintList
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
      case 49: // Identifier
      case 51: // Argument
      case 52: // Type
      case 53: // Body
      case 54: // SpecificationConstruct
      case 56: // Specification
      case 57: // DeclarationStatement
      case 59: // IdentifierDeclaration
      case 60: // ParameterStatement
      case 62: // AssignmentStatement
      case 63: // Expression
      case 64: // FunctionCall
      case 65: // Literal
      case 66: // ExecutableConstruct
      case 68: // Statement
      case 69: // IfStatement
      case 71: // ElseIfStatement
      case 74: // ReadStatement
      case 75: // PrintStatement
      case 77: // DoStatement
      case 78: // WhileStatement
      case 79: // CallStatement
        yylhs.value.build< AST::node_ptr > ();
        break;

      case 50: // ArgumentList
      case 55: // SpecificationList
      case 58: // IdentifierDeclarationList
      case 61: // AssignmentStatementList
      case 67: // ExecutableList
      case 70: // ElseIfStatementList
      case 72: // ElseStatement
      case 73: // StatementList
      case 76: // PrintList
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
#line 153 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 772 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 157 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 781 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 163 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 789 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 166 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 797 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 169 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 805 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 174 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 813 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 177 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 821 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 182 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 829 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 185 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 837 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 188 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 845 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 193 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 853 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 196 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 861 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 199 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
    }
#line 869 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 204 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 877 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 209 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 885 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 212 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 894 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 218 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 902 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 223 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 910 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 228 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 918 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 233 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 926 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 236 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 934 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 241 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 942 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 244 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 951 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 250 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 959 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 253 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 967 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 258 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 975 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 263 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 983 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 266 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 992 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 272 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1000 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 275 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 1008 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 278 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 1016 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 283 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1024 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 288 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1032 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 291 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1041 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 297 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1049 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 300 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1057 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 305 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1065 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 308 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1073 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 311 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1081 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 314 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1089 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 317 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1097 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 320 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1105 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 323 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1113 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 326 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1121 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 329 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
    }
#line 1129 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 332 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1137 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 335 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1145 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 338 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1153 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 343 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1161 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 348 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1169 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 351 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1177 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 354 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1185 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 357 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::string > ());
    }
#line 1193 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 368 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1201 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 371 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1209 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 376 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1217 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 379 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1226 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 385 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1234 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 388 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1242 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 391 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1250 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 394 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1258 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 397 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1266 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 400 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1274 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 403 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1282 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 417 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1290 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 420 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1298 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 423 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1306 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 428 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1314 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 431 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1323 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 437 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1331 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 442 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1339 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 447 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1347 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 450 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1356 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 456 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ReadStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1364 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 461 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<PrintStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1372 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 466 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1380 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 469 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1389 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 475 "bison/f_parser.y" // lalr1.cc:859
    {
        node_ptr unitary = driver.createNode<Literal>(1);
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[6].value.as< AST::node_ptr > ()),
            std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(unitary), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1399 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 480 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[8].value.as< AST::node_ptr > ()),
            std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1408 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 486 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<WhileStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1416 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 491 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1424 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 494 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(node_ptrs{}));
    }
#line 1432 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1436 "src/f_parser.cpp" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -76;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short int
   Parser ::yypact_[] =
  {
      24,     2,     3,   -76,    10,   -76,   -76,   -76,   -76,     4,
      11,   -76,    -4,     5,    -8,   -76,   -76,     6,    16,    32,
     -11,    36,   237,    -4,   -76,   -76,   -76,    54,   -19,    60,
      51,   -76,   -11,    74,    76,   -76,    94,    80,    85,   -11,
     318,    73,   -11,    25,   -76,   -76,   237,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,    -4,   -76,    29,   -76,
     107,   -16,    34,   -76,    -2,   -11,   -76,   318,   318,   102,
     318,   318,   -76,   -76,   -76,   -76,   110,    93,   -76,   -76,
     112,   113,   114,   318,   318,   -76,   132,    73,    -4,   -76,
      -4,    53,   -11,   -76,   116,   117,   -76,   253,   267,   318,
     281,    93,    73,   318,   318,   318,   318,   318,   318,   318,
     318,   -12,   295,    93,   137,   -76,   141,   142,    -4,   -76,
     -76,   -76,   144,   136,   239,   -76,    67,    55,    55,    50,
      50,    93,    93,   157,    93,   -76,    68,   122,   -76,   150,
     152,   154,   237,   237,   318,   -76,   -76,   318,   -76,   -76,
     156,   -76,   182,   189,    87,    93,   -76,   237,   149,   -76,
     -76,    83,   -76,   -76,   -76,   318,   200,   215,   318,   -76,
     -76,   151,   -76,   -76,   309,   226,   163,   -76,   237,   237
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    19,     0,     3,     4,     5,     6,     0,
       0,    15,    22,     0,     0,     1,     2,     0,     0,     0,
       0,     0,    56,    21,    23,    25,    26,     0,     0,     0,
       0,     8,     0,    30,    27,    28,     0,     0,     0,     0,
       0,     0,     0,     0,    59,    20,    55,    57,    60,    63,
      64,    61,    62,    65,    24,    11,    22,    18,     0,    16,
       0,     0,     0,    34,     0,     0,     7,     0,     0,     0,
       0,     0,    51,    52,    53,    54,    48,    77,    47,    49,
      76,    75,     0,     0,     0,    58,     0,     0,    22,    14,
      22,     0,     0,    33,     0,     0,    29,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,     0,    17,     0,     0,    22,    35,
      31,    32,     0,     0,     0,    46,     0,    39,    40,    41,
      42,    43,    44,    38,    78,    83,     0,     0,    10,     0,
       0,     0,     0,     0,     0,    50,    82,     0,     9,    13,
       0,    73,     0,     0,     0,    37,    12,     0,     0,    66,
      74,     0,    69,    68,    81,     0,     0,     0,     0,    70,
      67,     0,    79,    72,     0,     0,     0,    80,     0,    71
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -76,   -76,   158,   -76,   -76,   -76,    -1,   -21,    92,    48,
     -33,   -76,   -76,   172,   -76,   -76,   140,   -76,   -76,   -26,
     -34,   -76,   -76,   -76,   -76,   -20,   -76,   -76,    52,    63,
     -75,   -76,   -76,   -76,   -76,   -76,   -76
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    76,    58,    59,    20,
      21,    22,    23,    24,    25,    34,    35,    26,    62,    44,
      77,    78,    79,    45,    46,   151,    48,   161,   162,   163,
     152,    49,    50,    80,    51,    52,    53
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      12,    14,    47,    10,    13,    19,    63,    29,    56,    17,
      15,    90,    27,     1,     2,   135,    30,    18,    28,    33,
      81,    43,    57,    86,    31,    57,    85,     1,     2,    57,
      11,    43,     3,    97,    98,    94,   100,   101,    69,    11,
      91,    82,    36,    11,    11,    43,     3,    11,     9,   112,
     113,    83,     9,    84,    87,   116,    88,   117,    32,    92,
       3,    93,    55,    95,    33,   124,   119,    60,   153,   127,
     128,   129,   130,   131,   132,   133,   134,    61,    87,   166,
     118,   126,   167,   107,   108,   141,   105,   106,   107,   108,
     136,    43,    87,    87,   145,   146,   175,   157,   158,    37,
      64,    65,    66,   179,    38,    39,    67,    40,    41,    42,
     154,    68,   165,   155,    57,    89,   103,   104,   105,   106,
     107,   108,   103,   104,   105,   106,   107,   108,    11,   109,
      99,   171,   160,   160,   174,   109,   102,   110,    87,   114,
     111,    43,    43,   120,   121,   138,   160,   160,   139,   140,
     147,    43,    43,    43,   143,   160,    43,   142,   148,   160,
     149,   150,    16,    37,   156,    43,    43,     0,    38,    39,
      43,    40,    41,    42,    43,   168,   178,    43,    43,   115,
     103,   104,   105,   106,   107,   108,   103,   104,   105,   106,
     107,   108,    11,   109,    37,    54,   157,   158,   159,    38,
      39,    37,    40,    41,    42,    96,    38,    39,   164,    40,
      41,    42,    37,   169,     0,     0,     0,    38,    39,   172,
      40,    41,    42,    11,   170,     0,     0,    37,     0,     0,
      11,   173,    38,    39,     0,    40,    41,    42,    37,     0,
       0,    11,     0,    38,    39,   177,    40,    41,    42,    37,
       0,     0,     0,     0,    38,    39,    11,    40,    41,    42,
       0,     0,     0,     0,   144,     0,     0,    11,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,    11,     0,
     122,   109,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,     0,   123,   109,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,     0,   125,   109,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,   137,   109,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,     0,     0,   176,   109,   103,   104,
     105,   106,   107,   108,    70,     0,     0,     0,     0,     0,
       0,   109,     0,    71,     0,    72,    73,    74,    75,    11
  };

  const short int
   Parser ::yycheck_[] =
  {
       1,     2,    22,     1,     1,     9,    32,     1,    27,     5,
       0,    27,     7,     3,     4,    27,    17,     6,    26,    20,
      41,    22,    41,    56,     8,    41,    46,     3,     4,    41,
      41,    32,    36,    67,    68,    37,    70,    71,    39,    41,
      61,    42,     6,    41,    41,    46,    36,    41,     0,    83,
      84,    26,     4,    28,    25,    88,    27,    90,    26,    25,
      36,    27,     8,    64,    65,    99,    92,     7,   143,   103,
     104,   105,   106,   107,   108,   109,   110,    26,    25,   154,
      27,   102,   157,    33,    34,   118,    31,    32,    33,    34,
     111,    92,    25,    25,    27,    27,   171,    14,    15,    12,
      26,    25,     8,   178,    17,    18,    26,    20,    21,    22,
     144,    26,    25,   147,    41,     8,    29,    30,    31,    32,
      33,    34,    29,    30,    31,    32,    33,    34,    41,    42,
      28,   165,   152,   153,   168,    42,    26,    25,    25,     7,
      26,   142,   143,    27,    27,     8,   166,   167,     7,     7,
      28,   152,   153,   154,    18,   175,   157,    13,     8,   179,
       8,     7,     4,    12,     8,   166,   167,    -1,    17,    18,
     171,    20,    21,    22,   175,    26,    13,   178,   179,    87,
      29,    30,    31,    32,    33,    34,    29,    30,    31,    32,
      33,    34,    41,    42,    12,    23,    14,    15,    16,    17,
      18,    12,    20,    21,    22,    65,    17,    18,    19,    20,
      21,    22,    12,   161,    -1,    -1,    -1,    17,    18,    19,
      20,    21,    22,    41,   161,    -1,    -1,    12,    -1,    -1,
      41,    16,    17,    18,    -1,    20,    21,    22,    12,    -1,
      -1,    41,    -1,    17,    18,    19,    20,    21,    22,    12,
      -1,    -1,    -1,    -1,    17,    18,    41,    20,    21,    22,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    41,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    -1,    41,    -1,
      27,    42,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    42,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    27,    42,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    42,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    42,    29,    30,
      31,    32,    33,    34,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    35,    -1,    37,    38,    39,    40,    41
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    36,    44,    45,    46,    47,    48,    52,
       1,    41,    49,     1,    49,     0,    45,     5,     6,     9,
      52,    53,    54,    55,    56,    57,    60,     7,    26,     1,
      49,     8,    26,    49,    58,    59,     6,    12,    17,    18,
      20,    21,    22,    49,    62,    66,    67,    68,    69,    74,
      75,    77,    78,    79,    56,     8,    27,    41,    50,    51,
       7,    26,    61,    62,    26,    25,     8,    26,    26,    49,
      26,    35,    37,    38,    39,    40,    49,    63,    64,    65,
      76,    50,    49,    26,    28,    68,    53,    25,    27,     8,
      27,    50,    25,    27,    37,    49,    59,    63,    63,    28,
      63,    63,    26,    29,    30,    31,    32,    33,    34,    42,
      25,    26,    63,    63,     7,    51,    53,    53,    27,    62,
      27,    27,    27,    27,    63,    27,    50,    63,    63,    63,
      63,    63,    63,    63,    63,    27,    50,    27,     8,     7,
       7,    53,    13,    18,    25,    27,    27,    28,     8,     8,
       7,    68,    73,    73,    63,    63,     8,    14,    15,    16,
      68,    70,    71,    72,    19,    25,    73,    73,    26,    71,
      72,    63,    19,    16,    63,    73,    27,    19,    13,    73
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    48,    49,    50,    50,    51,    52,
      53,    54,    54,    55,    55,    56,    56,    57,    58,    58,
      59,    59,    59,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    65,    65,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    71,    72,    73,    73,    74,    75,    76,    76,    77,
      77,    78,    79,    79
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     4,     8,
       7,     4,     9,     8,     5,     1,     1,     3,     1,     1,
       2,     1,     0,     1,     2,     1,     1,     2,     1,     3,
       1,     4,     4,     4,     1,     3,     3,     6,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     7,     8,     7,     1,
       2,     6,     3,     1,     2,     2,     2,     1,     3,     8,
      10,     7,     5,     4
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
  "MainProgram", "Subroutine", "Function", "Identifier", "ArgumentList",
  "Argument", "Type", "Body", "SpecificationConstruct",
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
       0,   153,   153,   157,   163,   166,   169,   174,   177,   182,
     185,   188,   193,   196,   199,   204,   209,   212,   218,   223,
     228,   233,   236,   241,   244,   250,   253,   258,   263,   266,
     272,   275,   278,   283,   288,   291,   297,   300,   305,   308,
     311,   314,   317,   320,   323,   326,   329,   332,   335,   338,
     343,   348,   351,   354,   357,   368,   371,   376,   379,   385,
     388,   391,   394,   397,   400,   403,   417,   420,   423,   428,
     431,   437,   442,   447,   450,   456,   461,   466,   469,   475,
     480,   486,   491,   494
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
#line 1971 "src/f_parser.cpp" // lalr1.cc:1167
#line 507 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   std::cerr << "Error: " << message << " at " << loc << "\n";
   //std::cerr << "Error: " << message << " at " << driver.location() << "\n";
}
