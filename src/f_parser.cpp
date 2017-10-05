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
      case 41: // ExecutableProgram
      case 42: // Subprogram
      case 43: // MainProgram
      case 44: // Subroutine
      case 45: // Function
      case 46: // Identifier
      case 48: // Argument
      case 49: // Type
      case 50: // Body
      case 51: // SpecificationConstruct
      case 53: // Specification
      case 54: // DeclarationStatement
      case 56: // IdentifierDeclaration
      case 57: // ParameterStatement
      case 59: // AssignmentStatement
      case 60: // Expression
      case 61: // Literal
      case 62: // ExecutableConstruct
      case 64: // Statement
      case 65: // IfStatement
      case 67: // ElseIfStatement
      case 70: // ReadStatement
      case 71: // PrintStatement
      case 73: // DoStatement
      case 74: // WhileStatement
      case 75: // CallStatement
        value.move< AST::node_ptr > (that.value);
        break;

      case 47: // ArgumentList
      case 52: // SpecificationList
      case 55: // IdentifierDeclarationList
      case 58: // AssignmentStatementList
      case 63: // ExecutableList
      case 66: // ElseIfStatementList
      case 68: // ElseStatement
      case 69: // StatementList
      case 72: // PrintList
        value.move< AST::node_ptrs > (that.value);
        break;

      case 36: // "BOOLEAN value"
        value.move< Fortran::boolean > (that.value);
        break;

      case 34: // "INTEGER value"
        value.move< Fortran::integer > (that.value);
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        value.move< Fortran::op::arithmetic > (that.value);
        break;

      case 39: // "COMPARISON operator"
        value.move< Fortran::op::comp > (that.value);
        break;

      case 35: // "REAL value"
        value.move< Fortran::real > (that.value);
        break;

      case 37: // "STRING value"
      case 38: // "ID identifier"
        value.move< Fortran::string > (that.value);
        break;

      case 33: // "TYPE identifier"
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
      case 41: // ExecutableProgram
      case 42: // Subprogram
      case 43: // MainProgram
      case 44: // Subroutine
      case 45: // Function
      case 46: // Identifier
      case 48: // Argument
      case 49: // Type
      case 50: // Body
      case 51: // SpecificationConstruct
      case 53: // Specification
      case 54: // DeclarationStatement
      case 56: // IdentifierDeclaration
      case 57: // ParameterStatement
      case 59: // AssignmentStatement
      case 60: // Expression
      case 61: // Literal
      case 62: // ExecutableConstruct
      case 64: // Statement
      case 65: // IfStatement
      case 67: // ElseIfStatement
      case 70: // ReadStatement
      case 71: // PrintStatement
      case 73: // DoStatement
      case 74: // WhileStatement
      case 75: // CallStatement
        value.copy< AST::node_ptr > (that.value);
        break;

      case 47: // ArgumentList
      case 52: // SpecificationList
      case 55: // IdentifierDeclarationList
      case 58: // AssignmentStatementList
      case 63: // ExecutableList
      case 66: // ElseIfStatementList
      case 68: // ElseStatement
      case 69: // StatementList
      case 72: // PrintList
        value.copy< AST::node_ptrs > (that.value);
        break;

      case 36: // "BOOLEAN value"
        value.copy< Fortran::boolean > (that.value);
        break;

      case 34: // "INTEGER value"
        value.copy< Fortran::integer > (that.value);
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        value.copy< Fortran::op::arithmetic > (that.value);
        break;

      case 39: // "COMPARISON operator"
        value.copy< Fortran::op::comp > (that.value);
        break;

      case 35: // "REAL value"
        value.copy< Fortran::real > (that.value);
        break;

      case 37: // "STRING value"
      case 38: // "ID identifier"
        value.copy< Fortran::string > (that.value);
        break;

      case 33: // "TYPE identifier"
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
      case 41: // ExecutableProgram
      case 42: // Subprogram
      case 43: // MainProgram
      case 44: // Subroutine
      case 45: // Function
      case 46: // Identifier
      case 48: // Argument
      case 49: // Type
      case 50: // Body
      case 51: // SpecificationConstruct
      case 53: // Specification
      case 54: // DeclarationStatement
      case 56: // IdentifierDeclaration
      case 57: // ParameterStatement
      case 59: // AssignmentStatement
      case 60: // Expression
      case 61: // Literal
      case 62: // ExecutableConstruct
      case 64: // Statement
      case 65: // IfStatement
      case 67: // ElseIfStatement
      case 70: // ReadStatement
      case 71: // PrintStatement
      case 73: // DoStatement
      case 74: // WhileStatement
      case 75: // CallStatement
        yylhs.value.build< AST::node_ptr > ();
        break;

      case 47: // ArgumentList
      case 52: // SpecificationList
      case 55: // IdentifierDeclarationList
      case 58: // AssignmentStatementList
      case 63: // ExecutableList
      case 66: // ElseIfStatementList
      case 68: // ElseStatement
      case 69: // StatementList
      case 72: // PrintList
        yylhs.value.build< AST::node_ptrs > ();
        break;

      case 36: // "BOOLEAN value"
        yylhs.value.build< Fortran::boolean > ();
        break;

      case 34: // "INTEGER value"
        yylhs.value.build< Fortran::integer > ();
        break;

      case 29: // "+"
      case 30: // "-"
      case 31: // "*"
      case 32: // "/"
        yylhs.value.build< Fortran::op::arithmetic > ();
        break;

      case 39: // "COMPARISON operator"
        yylhs.value.build< Fortran::op::comp > ();
        break;

      case 35: // "REAL value"
        yylhs.value.build< Fortran::real > ();
        break;

      case 37: // "STRING value"
      case 38: // "ID identifier"
        yylhs.value.build< Fortran::string > ();
        break;

      case 33: // "TYPE identifier"
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
#line 147 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 751 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 151 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 760 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 157 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 768 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 160 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 776 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 163 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 784 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 168 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 792 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 173 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 800 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 176 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 808 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 181 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 816 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 184 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 824 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 189 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 832 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 194 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 840 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 197 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 849 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 203 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 857 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 208 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 865 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 213 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 873 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 218 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 881 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 221 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 889 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 226 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 897 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 229 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 906 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 235 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 914 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 238 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 922 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 243 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 930 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 248 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 938 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 251 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 947 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 257 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 955 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 260 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 963 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 263 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 971 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 268 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 979 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 273 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 987 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 276 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 996 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 282 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1004 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 285 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1012 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 290 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1020 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 293 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1028 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 296 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1036 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 299 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1044 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 302 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1052 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 305 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
    }
#line 1060 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 308 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1068 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 311 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1076 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 316 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1084 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 319 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1092 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 322 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1100 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 325 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::string > ());
    }
#line 1108 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 336 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1116 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 339 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1124 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 344 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1132 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 347 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1141 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 353 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1149 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 356 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1157 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 359 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1165 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 362 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1173 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 365 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1181 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 368 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1189 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 371 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1197 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 385 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1205 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 388 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1213 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 391 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1221 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 396 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1229 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 399 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1238 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 405 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1246 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 410 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1254 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 415 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1262 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 418 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1271 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 424 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ReadStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1279 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 429 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<PrintStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1287 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 434 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1295 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 437 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1304 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 443 "bison/f_parser.y" // lalr1.cc:859
    {
        node_ptr unitary = driver.createNode<Literal>(1);
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[6].value.as< AST::node_ptr > ()),
            std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(unitary), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1314 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 448 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[8].value.as< AST::node_ptr > ()),
            std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1323 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 454 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<WhileStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1331 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 459 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1339 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 462 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(node_ptrs{}));
    }
#line 1347 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1351 "src/f_parser.cpp" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -86;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short int
   Parser ::yypact_[] =
  {
      16,   -28,   -28,   -86,     5,   -86,   -86,   -86,   -86,    19,
     -86,    -3,     8,   -86,   -86,   -28,    31,   -28,    59,   189,
      -3,   -86,   -86,   -86,   -16,    40,   -28,    52,    63,   -86,
      76,    79,    99,   -28,   186,    88,   -28,    34,   -86,   -86,
     189,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,    -3,
     -86,    66,   -86,   -10,    73,   -86,    -5,   -28,   -86,   186,
     186,    64,   186,   -86,   -86,   -86,   -86,   -86,   227,   -86,
     104,   110,   118,   186,   186,   -86,   134,    88,    -3,    -3,
     111,   -28,   -86,   121,   122,   -86,   199,   205,   186,   216,
     186,   186,   186,   186,   186,   186,     4,   222,   227,   137,
     -86,   143,   145,    -3,   -86,   -86,   -86,   140,   136,    83,
     -86,    20,    20,   -86,   -86,   210,   227,   -86,   115,   128,
     -86,   149,   153,   164,   189,   189,   186,   -86,   186,   -86,
     -86,   170,   -86,   148,    51,    65,   227,   -86,   189,   154,
     -86,   -86,    61,   -86,   -86,   -86,   186,   155,   167,   186,
     -86,   -86,    89,   -86,   -86,   233,   178,   168,   -86,   189,
     189
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    16,     0,     3,     4,     5,     6,     0,
      12,    19,     0,     1,     2,     0,     0,     0,     0,    48,
      18,    20,    22,    23,     0,     0,     0,    27,    24,    25,
       0,     0,     0,     0,     0,     0,     0,     0,    51,    17,
      47,    49,    52,    55,    56,    53,    54,    57,    21,    19,
      15,     0,    13,     0,     0,    31,     0,     0,     7,     0,
       0,     0,     0,    43,    44,    45,    46,    41,    69,    42,
      68,    67,     0,     0,     0,    50,     0,     0,    19,    19,
       0,     0,    30,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      14,     0,     0,    19,    32,    28,    29,     0,     0,     0,
      40,    36,    37,    38,    39,    35,    70,    75,     0,     0,
       9,     0,     0,     0,     0,     0,     0,    74,     0,     8,
      11,     0,    65,     0,     0,     0,    34,    10,     0,     0,
      58,    66,     0,    61,    60,    73,     0,     0,     0,     0,
      62,    59,     0,    71,    64,     0,     0,     0,    72,     0,
      63
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -86,   -86,   187,   -86,   -86,   -86,    -1,   -32,   105,    54,
     -42,   -86,   -86,   172,   -86,   -86,   146,   -86,   -86,   -22,
     -47,   -86,   -86,   -86,   -17,   -86,   -86,    60,    62,   -85,
     -86,   -86,   -86,   -86,   -86,   -86
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    67,    51,    52,    17,
      18,    19,    20,    21,    22,    28,    29,    23,    54,    38,
      68,    69,    39,    40,   132,    42,   142,   143,   144,   133,
      43,    44,    70,    45,    46,    47
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      11,    12,    41,    71,    55,    13,    16,    76,     1,     2,
      10,    49,    86,    87,    25,    89,    27,    79,    37,     1,
       2,    80,    50,    75,    15,    37,    97,    98,    50,    83,
       3,   117,    61,    10,    24,    72,   101,   102,     3,    37,
     134,   109,    50,   111,   112,   113,   114,   115,   116,     3,
     147,    92,    93,   148,     9,    84,    27,    26,     9,   104,
      73,   123,    74,    31,   118,    30,    53,   156,    32,    33,
     145,    34,    35,    36,   160,   138,   139,    31,    56,   135,
      37,   136,    32,    33,    58,    34,    35,    36,    57,    10,
     146,    77,    88,    78,    90,    91,    92,    93,    81,   152,
      82,    31,   155,    10,    94,    59,    32,    33,   126,    34,
      35,    36,    90,    91,    92,    93,   141,   141,    90,    91,
      92,    93,    94,    37,    37,    60,    50,    10,    94,    95,
     141,   141,    37,    37,    37,    77,    77,    37,   103,   141,
      77,    99,   127,   141,    96,   120,    37,    37,   105,   106,
     121,    37,   122,   124,   125,    37,   128,   129,    37,    37,
      31,   130,   138,   139,   140,    32,    33,    31,    34,    35,
      36,   131,    32,    33,   153,    34,    35,    36,   137,    31,
     149,   159,   100,   154,    32,    33,    10,    34,    35,    36,
      31,    14,    48,    10,     0,    32,    33,   158,    34,    35,
      36,    31,   150,    85,   151,    10,    32,    33,     0,    34,
      35,    36,    62,     0,     0,     0,    10,     0,     0,     0,
      63,    64,    65,    66,    10,     0,   107,    10,    90,    91,
      92,    93,   108,     0,    90,    91,    92,    93,    94,    90,
      91,    92,    93,   110,    94,    90,    91,    92,    93,   119,
       0,    90,    91,    92,    93,    94,    90,    91,    92,    93,
     157,    94,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,    94
  };

  const short int
   Parser ::yycheck_[] =
  {
       1,     2,    19,    35,    26,     0,     9,    49,     3,     4,
      38,    27,    59,    60,    15,    62,    17,    27,    19,     3,
       4,    53,    38,    40,     5,    26,    73,    74,    38,    34,
      33,    27,    33,    38,    26,    36,    78,    79,    33,    40,
     125,    88,    38,    90,    91,    92,    93,    94,    95,    33,
     135,    31,    32,   138,     0,    56,    57,    26,     4,    81,
      26,   103,    28,    12,    96,     6,    26,   152,    17,    18,
      19,    20,    21,    22,   159,    14,    15,    12,    26,   126,
      81,   128,    17,    18,     8,    20,    21,    22,    25,    38,
      25,    25,    28,    27,    29,    30,    31,    32,    25,   146,
      27,    12,   149,    38,    39,    26,    17,    18,    25,    20,
      21,    22,    29,    30,    31,    32,   133,   134,    29,    30,
      31,    32,    39,   124,   125,    26,    38,    38,    39,    25,
     147,   148,   133,   134,   135,    25,    25,   138,    27,   156,
      25,     7,    27,   160,    26,     8,   147,   148,    27,    27,
       7,   152,     7,    13,    18,   156,    28,     8,   159,   160,
      12,     8,    14,    15,    16,    17,    18,    12,    20,    21,
      22,     7,    17,    18,    19,    20,    21,    22,     8,    12,
      26,    13,    77,    16,    17,    18,    38,    20,    21,    22,
      12,     4,    20,    38,    -1,    17,    18,    19,    20,    21,
      22,    12,   142,    57,   142,    38,    17,    18,    -1,    20,
      21,    22,    26,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    27,    38,    29,    30,
      31,    32,    27,    -1,    29,    30,    31,    32,    39,    29,
      30,    31,    32,    27,    39,    29,    30,    31,    32,    27,
      -1,    29,    30,    31,    32,    39,    29,    30,    31,    32,
      27,    39,    29,    30,    31,    32,    39,    -1,    -1,    -1,
      -1,    -1,    39
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    33,    41,    42,    43,    44,    45,    49,
      38,    46,    46,     0,    42,     5,     9,    49,    50,    51,
      52,    53,    54,    57,    26,    46,    26,    46,    55,    56,
       6,    12,    17,    18,    20,    21,    22,    46,    59,    62,
      63,    64,    65,    70,    71,    73,    74,    75,    53,    27,
      38,    47,    48,    26,    58,    59,    26,    25,     8,    26,
      26,    46,    26,    34,    35,    36,    37,    46,    60,    61,
      72,    47,    46,    26,    28,    64,    50,    25,    27,    27,
      47,    25,    27,    34,    46,    56,    60,    60,    28,    60,
      29,    30,    31,    32,    39,    25,    26,    60,    60,     7,
      48,    50,    50,    27,    59,    27,    27,    27,    27,    60,
      27,    60,    60,    60,    60,    60,    60,    27,    47,    27,
       8,     7,     7,    50,    13,    18,    25,    27,    28,     8,
       8,     7,    64,    69,    69,    60,    60,     8,    14,    15,
      16,    64,    66,    67,    68,    19,    25,    69,    69,    26,
      67,    68,    60,    19,    16,    60,    69,    27,    19,    13,
      69
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    42,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    49,    50,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      65,    66,    66,    67,    68,    69,    69,    70,    71,    72,
      72,    73,    73,    74,    75,    75
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     8,     7,
       9,     8,     1,     1,     3,     1,     1,     2,     1,     0,
       1,     2,     1,     1,     2,     1,     3,     1,     4,     4,
       4,     1,     3,     3,     6,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     7,     8,
       7,     1,     2,     6,     3,     1,     2,     2,     2,     1,
       3,     8,    10,     7,     5,     4
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
  "\"-\"", "\"*\"", "\"/\"", "\"TYPE identifier\"", "\"INTEGER value\"",
  "\"REAL value\"", "\"BOOLEAN value\"", "\"STRING value\"",
  "\"ID identifier\"", "\"COMPARISON operator\"", "$accept",
  "ExecutableProgram", "Subprogram", "MainProgram", "Subroutine",
  "Function", "Identifier", "ArgumentList", "Argument", "Type", "Body",
  "SpecificationConstruct", "SpecificationList", "Specification",
  "DeclarationStatement", "IdentifierDeclarationList",
  "IdentifierDeclaration", "ParameterStatement", "AssignmentStatementList",
  "AssignmentStatement", "Expression", "Literal", "ExecutableConstruct",
  "ExecutableList", "Statement", "IfStatement", "ElseIfStatementList",
  "ElseIfStatement", "ElseStatement", "StatementList", "ReadStatement",
  "PrintStatement", "PrintList", "DoStatement", "WhileStatement",
  "CallStatement", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   147,   147,   151,   157,   160,   163,   168,   173,   176,
     181,   184,   189,   194,   197,   203,   208,   213,   218,   221,
     226,   229,   235,   238,   243,   248,   251,   257,   260,   263,
     268,   273,   276,   282,   285,   290,   293,   296,   299,   302,
     305,   308,   311,   316,   319,   322,   325,   336,   339,   344,
     347,   353,   356,   359,   362,   365,   368,   371,   385,   388,
     391,   396,   399,   405,   410,   415,   418,   424,   429,   434,
     437,   443,   448,   454,   459,   462
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
#line 1863 "src/f_parser.cpp" // lalr1.cc:1167
#line 475 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   std::cerr << "Error: " << message << " at " << driver.location() << "\n";
}
