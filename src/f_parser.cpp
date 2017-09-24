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
      case 40: // ExecutableProgram
      case 41: // Subprogram
      case 42: // MainProgram
      case 43: // Subroutine
      case 44: // Function
      case 45: // Identifier
      case 47: // Argument
      case 48: // Type
      case 49: // Body
      case 50: // SpecificationConstruct
      case 52: // Specification
      case 53: // DeclarationStatement
      case 55: // IdentifierDeclaration
      case 56: // ParameterStatement
      case 58: // AssignmentStatement
      case 59: // Expression
      case 60: // LogicalExpression
      case 61: // ExecutableConstruct
        value.move< AST::node_ptr > (that.value);
        break;

      case 46: // ArgumentList
      case 51: // SpecificationList
      case 54: // IdentifierDeclarationList
      case 57: // AssignmentStatementList
        value.move< AST::node_ptrs > (that.value);
        break;

      case 35: // "BOOLEAN value"
        value.move< Fortran::boolean > (that.value);
        break;

      case 33: // "INTEGER value"
        value.move< Fortran::integer > (that.value);
        break;

      case 28: // "+"
      case 29: // "-"
      case 30: // "*"
      case 31: // "/"
        value.move< Fortran::op::arithmetic > (that.value);
        break;

      case 38: // "COMPARISON operator"
        value.move< Fortran::op::comp > (that.value);
        break;

      case 34: // "REAL value"
        value.move< Fortran::real > (that.value);
        break;

      case 36: // "STRING value"
      case 37: // "ID identifier"
        value.move< Fortran::string > (that.value);
        break;

      case 32: // "TYPE identifier"
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
      case 40: // ExecutableProgram
      case 41: // Subprogram
      case 42: // MainProgram
      case 43: // Subroutine
      case 44: // Function
      case 45: // Identifier
      case 47: // Argument
      case 48: // Type
      case 49: // Body
      case 50: // SpecificationConstruct
      case 52: // Specification
      case 53: // DeclarationStatement
      case 55: // IdentifierDeclaration
      case 56: // ParameterStatement
      case 58: // AssignmentStatement
      case 59: // Expression
      case 60: // LogicalExpression
      case 61: // ExecutableConstruct
        value.copy< AST::node_ptr > (that.value);
        break;

      case 46: // ArgumentList
      case 51: // SpecificationList
      case 54: // IdentifierDeclarationList
      case 57: // AssignmentStatementList
        value.copy< AST::node_ptrs > (that.value);
        break;

      case 35: // "BOOLEAN value"
        value.copy< Fortran::boolean > (that.value);
        break;

      case 33: // "INTEGER value"
        value.copy< Fortran::integer > (that.value);
        break;

      case 28: // "+"
      case 29: // "-"
      case 30: // "*"
      case 31: // "/"
        value.copy< Fortran::op::arithmetic > (that.value);
        break;

      case 38: // "COMPARISON operator"
        value.copy< Fortran::op::comp > (that.value);
        break;

      case 34: // "REAL value"
        value.copy< Fortran::real > (that.value);
        break;

      case 36: // "STRING value"
      case 37: // "ID identifier"
        value.copy< Fortran::string > (that.value);
        break;

      case 32: // "TYPE identifier"
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
      case 40: // ExecutableProgram
      case 41: // Subprogram
      case 42: // MainProgram
      case 43: // Subroutine
      case 44: // Function
      case 45: // Identifier
      case 47: // Argument
      case 48: // Type
      case 49: // Body
      case 50: // SpecificationConstruct
      case 52: // Specification
      case 53: // DeclarationStatement
      case 55: // IdentifierDeclaration
      case 56: // ParameterStatement
      case 58: // AssignmentStatement
      case 59: // Expression
      case 60: // LogicalExpression
      case 61: // ExecutableConstruct
        yylhs.value.build< AST::node_ptr > ();
        break;

      case 46: // ArgumentList
      case 51: // SpecificationList
      case 54: // IdentifierDeclarationList
      case 57: // AssignmentStatementList
        yylhs.value.build< AST::node_ptrs > ();
        break;

      case 35: // "BOOLEAN value"
        yylhs.value.build< Fortran::boolean > ();
        break;

      case 33: // "INTEGER value"
        yylhs.value.build< Fortran::integer > ();
        break;

      case 28: // "+"
      case 29: // "-"
      case 30: // "*"
      case 31: // "/"
        yylhs.value.build< Fortran::op::arithmetic > ();
        break;

      case 38: // "COMPARISON operator"
        yylhs.value.build< Fortran::op::comp > ();
        break;

      case 34: // "REAL value"
        yylhs.value.build< Fortran::real > ();
        break;

      case 36: // "STRING value"
      case 37: // "ID identifier"
        yylhs.value.build< Fortran::string > ();
        break;

      case 32: // "TYPE identifier"
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
#line 128 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 712 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 3:
#line 132 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createRoot();
        yylhs.value.as< AST::node_ptr > ()->addChild(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 721 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 4:
#line 138 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 729 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 5:
#line 141 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 737 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 6:
#line 144 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 745 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 7:
#line 149 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<MainProgram>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 753 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 8:
#line 154 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 761 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 9:
#line 157 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 769 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 162 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 777 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 165 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
    }
#line 785 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 170 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 793 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 175 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 801 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 178 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 810 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 184 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 818 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 189 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 826 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 194 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 834 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 199 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 842 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 202 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 850 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 207 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 858 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 210 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 867 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 216 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 875 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 219 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 883 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 224 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<DeclarationStatement>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 891 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 229 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 899 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 232 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 908 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 238 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 916 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 241 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 924 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 244 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 932 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 249 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 940 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 254 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 948 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 257 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 957 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 263 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 965 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 266 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 973 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 271 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 981 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 279 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<LogicalExpression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< Fortran::op::comp > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 989 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 282 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<LogicalExpression>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 997 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 311 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1005 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1009 "src/f_parser.cpp" // lalr1.cc:859
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


  const signed char  Parser ::yypact_ninf_ = -41;

  const signed char  Parser ::yytable_ninf_ = -1;

  const signed char
   Parser ::yypact_[] =
  {
       0,   -20,   -20,   -41,     2,   -41,   -41,   -41,   -41,    13,
     -41,    -2,     6,   -41,   -41,   -20,    14,   -20,    36,   -41,
      -2,   -41,   -41,   -41,   -17,    19,   -20,    20,    22,   -41,
      39,   -41,   -41,    -2,   -41,     3,   -41,   -13,     1,    12,
     -41,   -21,   -20,   -41,    41,    16,    -2,    -2,    17,    21,
      21,   -20,   -41,    23,    25,   -41,    44,   -41,    47,    48,
      -2,   -41,   -15,   -41,    24,   -41,   -41,   -41,   -41,    49,
      50,    52,    33,    21,   -41,   -41,    53,    21,    24,   -41,
      24
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,    16,     0,     3,     4,     5,     6,     0,
      12,    19,     0,     1,     2,     0,     0,     0,     0,    38,
      18,    20,    22,    23,     0,     0,     0,    27,    24,    25,
       0,    17,    21,    19,    15,     0,    13,     0,     0,     0,
      31,     0,     0,     7,     0,     0,    19,    19,     0,     0,
       0,     0,    30,     0,     0,    26,     0,    14,     0,     0,
      19,    37,     0,    35,    33,    32,    28,    29,     9,     0,
       0,     0,     0,     0,     8,    11,     0,     0,    36,    10,
      34
  };

  const signed char
   Parser ::yypgoto_[] =
  {
     -41,   -41,    59,   -41,   -41,   -41,    -1,    27,    26,    15,
     -25,   -41,   -41,    45,   -41,   -41,    28,   -41,   -41,    18,
     -40,   -41,   -41
  };

  const signed char
   Parser ::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,    27,    35,    36,    17,
      18,    19,    20,    21,    22,    28,    29,    23,    39,    40,
      62,    63,    31
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      11,    12,    13,     1,     2,     1,     2,    16,    44,    33,
      64,    72,    53,    47,    25,     9,    10,    10,    15,     9,
      34,    58,    59,    73,    34,    38,    49,    45,    50,    46,
       3,    24,     3,    78,     3,    71,    51,    80,    52,    26,
      54,    45,    30,    60,    37,    41,    42,    43,    56,    66,
      38,    67,    68,    34,    69,    70,    61,    74,    75,    76,
      77,    79,    73,    14,    48,    32,     0,     0,     0,    65,
      55,    57
  };

  const signed char
   Parser ::yycheck_[] =
  {
       1,     2,     0,     3,     4,     3,     4,     9,    33,    26,
      50,    26,    33,    26,    15,     0,    37,    37,     5,     4,
      37,    46,    47,    38,    37,    26,    25,    24,    27,    26,
      32,    25,    32,    73,    32,    60,    24,    77,    26,    25,
      41,    24,     6,    26,    25,    25,    24,     8,     7,    26,
      51,    26,     8,    37,     7,     7,    35,     8,     8,     7,
      27,     8,    38,     4,    37,    20,    -1,    -1,    -1,    51,
      42,    45
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,     3,     4,    32,    40,    41,    42,    43,    44,    48,
      37,    45,    45,     0,    41,     5,     9,    48,    49,    50,
      51,    52,    53,    56,    25,    45,    25,    45,    54,    55,
       6,    61,    52,    26,    37,    46,    47,    25,    45,    57,
      58,    25,    24,     8,    49,    24,    26,    26,    46,    25,
      27,    24,    26,    33,    45,    55,     7,    47,    49,    49,
      26,    35,    59,    60,    59,    58,    26,    26,     8,     7,
       7,    49,    26,    38,     8,     8,     7,    27,    59,     8,
      59
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    39,    40,    40,    41,    41,    41,    42,    43,    43,
      44,    44,    45,    46,    46,    47,    48,    49,    50,    50,
      51,    51,    52,    52,    53,    54,    54,    55,    55,    55,
      56,    57,    57,    58,    58,    59,    60,    60,    61
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     5,     8,     7,
       9,     8,     1,     1,     3,     1,     1,     2,     1,     0,
       1,     2,     1,     1,     2,     1,     3,     1,     4,     4,
       4,     1,     3,     3,     6,     1,     3,     1,     0
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
  "\"ELSE keyword\"", "\"ELSEIF keyword\"", "\"ENDIF keyword\"",
  "\"WHILE keyword\"", "\"DO keyword\"", "\"ENDDO keyword\"",
  "\"PRINT keyword\"", "\"READ keyword\"", "\"CALL keyword\"",
  "\"ERR keyword\"", "\"new line\"", "\"comma\"", "\"left parenthesis\"",
  "\"right parenthesis\"", "\"=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"TYPE identifier\"", "\"INTEGER value\"", "\"REAL value\"",
  "\"BOOLEAN value\"", "\"STRING value\"", "\"ID identifier\"",
  "\"COMPARISON operator\"", "$accept", "ExecutableProgram", "Subprogram",
  "MainProgram", "Subroutine", "Function", "Identifier", "ArgumentList",
  "Argument", "Type", "Body", "SpecificationConstruct",
  "SpecificationList", "Specification", "DeclarationStatement",
  "IdentifierDeclarationList", "IdentifierDeclaration",
  "ParameterStatement", "AssignmentStatementList", "AssignmentStatement",
  "Expression", "LogicalExpression", "ExecutableConstruct", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,   128,   128,   132,   138,   141,   144,   149,   154,   157,
     162,   165,   170,   175,   178,   184,   189,   194,   199,   202,
     207,   210,   216,   219,   224,   229,   232,   238,   241,   244,
     249,   254,   257,   263,   266,   271,   279,   282,   311
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
#line 1439 "src/f_parser.cpp" // lalr1.cc:1167
#line 438 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   //std::cerr << "Error: " << message << " at " << loc << "\n";
   std::cerr << "Error: " << message << " at " << driver.location() << "\n";
}
