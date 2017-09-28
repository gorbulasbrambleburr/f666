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
#line 141 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 733 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 145 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 742 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 151 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 750 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 154 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 758 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 157 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 766 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 162 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 774 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 167 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 782 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 170 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 790 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 175 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 798 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 178 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 806 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 183 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 814 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 188 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 822 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 191 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 831 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 197 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 839 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 202 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 847 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 207 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 855 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 212 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 863 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 215 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 871 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 220 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 879 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 223 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 888 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 229 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 896 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 232 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 904 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 237 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 912 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 242 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 920 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 245 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 929 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 251 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 937 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 254 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 945 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 257 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 953 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 262 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 961 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 267 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 969 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 270 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 978 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 276 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 986 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 279 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 994 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 284 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1002 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 287 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1010 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 290 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1018 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 293 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1026 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 296 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1034 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 299 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1042 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 302 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1050 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 307 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1058 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 310 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1066 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 313 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1074 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 324 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1082 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 327 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1090 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 332 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1098 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 335 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1107 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 341 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1115 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 344 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1123 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 371 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1131 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 374 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1139 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 377 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1147 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 382 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1155 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 385 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1164 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 391 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1172 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 396 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1180 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 401 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1188 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 404 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1197 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1201 "src/f_parser.cpp" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -102;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
      19,   -29,   -29,  -102,     8,  -102,  -102,  -102,  -102,    20,
    -102,    10,    18,  -102,  -102,   -29,    21,   -29,    28,    -5,
      10,  -102,  -102,  -102,   -14,    48,   -29,    61,    68,  -102,
      89,    93,    43,  -102,  -102,    -5,  -102,  -102,  -102,    10,
    -102,    30,  -102,   -12,    83,  -102,    32,   -29,  -102,    65,
      65,    65,  -102,   102,    82,    10,    10,    87,   -29,  -102,
      86,    94,  -102,  -102,  -102,  -102,  -102,    29,  -102,    46,
      33,   114,  -102,   116,   117,    10,  -102,  -102,  -102,   112,
      65,    65,    65,    65,    65,    98,  -102,   119,   120,   122,
      -5,    84,    84,  -102,  -102,    75,    65,  -102,  -102,   123,
    -102,    15,    33,  -102,    -5,   104,  -102,  -102,   103,  -102,
    -102,    16,    65,  -102,  -102,  -102,    59,   121,    -5,    -5
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    16,     0,     3,     4,     5,     6,     0,
      12,    19,     0,     1,     2,     0,     0,     0,     0,    46,
      18,    20,    22,    23,     0,     0,     0,    27,    24,    25,
       0,     0,     0,    49,    17,    45,    47,    50,    21,    19,
      15,     0,    13,     0,     0,    31,     0,     0,     7,     0,
       0,     0,    48,     0,     0,    19,    19,     0,     0,    30,
       0,     0,    26,    42,    43,    44,    40,     0,    41,     0,
      33,     0,    14,     0,     0,    19,    32,    28,    29,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
       0,    36,    37,    38,    39,    35,     0,     8,    11,     0,
      58,     0,    34,    10,     0,     0,    51,    59,     0,    54,
      53,     0,     0,    55,    52,    57,     0,     0,     0,    56
  };

  const short int
   Parser ::yypgoto_[] =
  {
    -102,  -102,   128,  -102,  -102,  -102,    -1,    90,    81,    92,
     -35,  -102,  -102,   118,  -102,  -102,    95,  -102,  -102,   -16,
     -45,  -102,  -102,  -102,   -17,  -102,  -102,    31,    35,  -101
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    32,    41,    42,    17,
      18,    19,    20,    21,    22,    28,    29,    23,    44,    33,
      67,    68,    34,    35,   100,    37,   108,   109,   110,   101
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      11,    12,    36,   111,    53,    69,    70,    31,    13,    10,
      45,     1,     2,    39,    25,    56,    27,   119,    52,    16,
      73,    74,     1,     2,    40,    15,    40,    31,    31,   104,
     105,   106,   115,    10,    30,    91,    92,    93,    94,    95,
      89,     3,    76,     3,    24,    61,    27,    26,    66,    66,
      66,   102,     3,    10,    10,    54,    79,    55,    80,    81,
      82,    83,    80,    81,    82,    83,    60,   116,    84,    50,
      10,    51,    84,    85,    43,    80,    81,    82,    83,    66,
      66,    66,    66,    66,   107,    84,   117,    46,    80,    81,
      82,    83,     9,    47,   107,    66,     9,    48,    84,    63,
      64,    65,   107,    10,    80,    81,    82,    83,    58,    71,
      59,    66,    54,    77,    75,    82,    83,   104,   105,    49,
      40,    78,    86,    87,    88,    90,    96,    97,    98,    99,
     112,   103,    14,    57,   118,    72,     0,     0,    38,   113,
       0,     0,    62,   114
  };

  const signed char
   Parser ::yycheck_[] =
  {
       1,     2,    19,   104,    39,    50,    51,    12,     0,    38,
      26,     3,     4,    27,    15,    27,    17,   118,    35,     9,
      55,    56,     3,     4,    38,     5,    38,    12,    12,    14,
      15,    16,    16,    38,     6,    80,    81,    82,    83,    84,
      75,    33,    58,    33,    26,    46,    47,    26,    49,    50,
      51,    96,    33,    38,    38,    25,    27,    27,    29,    30,
      31,    32,    29,    30,    31,    32,    34,   112,    39,    26,
      38,    28,    39,    27,    26,    29,    30,    31,    32,    80,
      81,    82,    83,    84,   101,    39,    27,    26,    29,    30,
      31,    32,     0,    25,   111,    96,     4,     8,    39,    34,
      35,    36,   119,    38,    29,    30,    31,    32,    25,     7,
      27,   112,    25,    27,    27,    31,    32,    14,    15,    26,
      38,    27,     8,     7,     7,    13,    28,     8,     8,     7,
      26,     8,     4,    43,    13,    54,    -1,    -1,    20,   108,
      -1,    -1,    47,   108
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    33,    41,    42,    43,    44,    45,    49,
      38,    46,    46,     0,    42,     5,     9,    49,    50,    51,
      52,    53,    54,    57,    26,    46,    26,    46,    55,    56,
       6,    12,    46,    59,    62,    63,    64,    65,    53,    27,
      38,    47,    48,    26,    58,    59,    26,    25,     8,    26,
      26,    28,    64,    50,    25,    27,    27,    47,    25,    27,
      34,    46,    56,    34,    35,    36,    46,    60,    61,    60,
      60,     7,    48,    50,    50,    27,    59,    27,    27,    27,
      29,    30,    31,    32,    39,    27,     8,     7,     7,    50,
      13,    60,    60,    60,    60,    60,    28,     8,     8,     7,
      64,    69,    60,     8,    14,    15,    16,    64,    66,    67,
      68,    69,    26,    67,    68,    16,    60,    27,    13,    69
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    40,    41,    41,    42,    42,    42,    43,    44,    44,
      45,    45,    46,    47,    47,    48,    49,    50,    51,    51,
      52,    52,    53,    53,    54,    55,    55,    56,    56,    56,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    67,    68,    69,    69
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     8,     7,
       9,     8,     1,     1,     3,     1,     1,     2,     1,     0,
       1,     2,     1,     1,     2,     1,     3,     1,     4,     4,
       4,     1,     3,     3,     6,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     1,
       1,     7,     8,     7,     1,     2,     6,     3,     1,     2
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
  "ElseIfStatement", "ElseStatement", "StatementList", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   141,   141,   145,   151,   154,   157,   162,   167,   170,
     175,   178,   183,   188,   191,   197,   202,   207,   212,   215,
     220,   223,   229,   232,   237,   242,   245,   251,   254,   257,
     262,   267,   270,   276,   279,   284,   287,   290,   293,   296,
     299,   302,   307,   310,   313,   324,   327,   332,   335,   341,
     344,   371,   374,   377,   382,   385,   391,   396,   401,   404
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
#line 1662 "src/f_parser.cpp" // lalr1.cc:1167
#line 472 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   std::cerr << "Error: " << message << " at " << driver.location() << "\n";
}
