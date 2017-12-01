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
        Mapper::get().reset_scope();
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
        std::string error_msg = "";
        bool any_error = false;

        // Check arguments declarations
        std::string ids = "";
        std::vector<std::string> args;
        for (auto& arg : yystack_[4].value.as< AST::node_ptrs > ()) {
            auto arg_entry = Mapper::get().lookup_var(arg->id());
            if (arg_entry) {
                args.emplace_back(arg->id());
            } else {
                ids += arg->id() + ", ";
                any_error = true;
            }
        }
        if (any_error) {
            error_msg += "argument [" + ids + "] were not defined in subroutine body";
        } else {
            Mapper::get().set_args(args);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
        }

        // Create fake node
        if(any_error) {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::get().reset_scope();
    }
#line 873 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 10:
#line 220 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Subroutine>(std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
        Mapper::get().reset_scope();
    }
#line 882 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 11:
#line 224 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
        std::string error_msg = "syntax error";
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
    }
#line 892 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 12:
#line 231 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        auto var_entry = Mapper::get().lookup_var(yystack_[6].value.as< AST::node_ptr > ()->id());
        if (var_entry) {
            
            // Check function return type
            if (var_entry->type() == yystack_[8].value.as< AST::node_ptr > ()->var_type()) {
                
                // Check arguments declarations
                std::string ids = "";
                std::vector<std::string> args;
                for (auto& arg : yystack_[4].value.as< AST::node_ptrs > ()) {
                    auto arg_entry = Mapper::get().lookup_var(arg->id());
                    if (arg_entry) {
                        args.emplace_back(arg->id());
                    } else {
                        ids += arg->id() + ", ";
                        any_error = true;
                    }
                }
                if (any_error) {
                    error_msg += "arguments [" + ids + "] were not defined in function body";
                } else {
                    Mapper::get().set_args(args);
                    Mapper::get().set_return_type(yystack_[8].value.as< AST::node_ptr > ()->var_type());
                    yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[8].value.as< AST::node_ptr > ()), std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptrs > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()));
                }
            } else {
                error_msg += "type mismatch between var id '" + yystack_[6].value.as< AST::node_ptr > ()->id() + "' and function return type.";
                any_error = true;
            }
        } else {
            error_msg += "function '" + yystack_[6].value.as< AST::node_ptr > ()->id() + "' was not defined in function body.";
            any_error = true;
        }

        // Create fake node
        if(any_error) {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
            driver.semantic_error(error_msg);
        }
        Mapper::get().reset_scope();
    }
#line 943 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 13:
#line 277 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;

        // Function id should be declared inside function body as a variable
        auto var_entry = Mapper::get().lookup_var(yystack_[5].value.as< AST::node_ptr > ()->id());
        if (var_entry) {

            // Check function return type
            if (var_entry->type() == yystack_[7].value.as< AST::node_ptr > ()->var_type()) {

                Mapper::get().set_return_type(yystack_[7].value.as< AST::node_ptr > ()->var_type());
                yylhs.value.as< AST::node_ptr > () = driver.createNode<Function>(std::move(yystack_[7].value.as< AST::node_ptr > ()), std::move(yystack_[5].value.as< AST::node_ptr > ()), node_ptrs{}, std::move(yystack_[2].value.as< AST::node_ptr > ()));
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
        Mapper::get().reset_scope();
    }
#line 977 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 14:
#line 306 "bison/f_parser.y" // lalr1.cc:859
    {
        yyerrok;
        std::string error_msg = "syntax error";
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
    }
#line 987 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 15:
#line 313 "bison/f_parser.y" // lalr1.cc:859
    {
        bool inserted = Mapper::get().create_scope(yystack_[0].value.as< Fortran::string > ());
        if (!inserted) {
            std::string error = "redefinition of function '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::FUNCTION);
        }
    }
#line 1002 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 16:
#line 325 "bison/f_parser.y" // lalr1.cc:859
    {
        bool inserted = Mapper::get().create_scope(yystack_[0].value.as< Fortran::string > ());
        if (!inserted) {
            std::string error = "redefinition of subroutine '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::SUBROUTINE);
        }
    }
#line 1017 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 17:
#line 337 "bison/f_parser.y" // lalr1.cc:859
    {
        bool inserted = Mapper::get().create_scope(yystack_[0].value.as< Fortran::string > ());
        if (!inserted) {
            std::string error = "redefinition of program '" + yystack_[0].value.as< Fortran::string > () + "'";
            driver.semantic_error(error);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error);
        } else {
            yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()), Fortran::symbol::type::PROGRAM);
        }
    }
#line 1032 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 18:
#line 349 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 1040 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 19:
#line 354 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1048 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 20:
#line 357 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1057 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 21:
#line 363 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Identifier>(std::move(yystack_[0].value.as< Fortran::string > ()));
    }
#line 1065 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 22:
#line 368 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1073 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 23:
#line 371 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1082 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 24:
#line 377 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1090 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 25:
#line 380 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1098 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 26:
#line 385 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Type>(yystack_[0].value.as< Fortran::type > ());
    }
#line 1106 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 27:
#line 390 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Body>(std::move(yystack_[1].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1114 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 28:
#line 395 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1122 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 29:
#line 398 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<SpecificationConstruct>(node_ptrs{});
    }
#line 1130 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 30:
#line 403 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1138 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 31:
#line 406 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1147 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 32:
#line 412 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1155 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 33:
#line 415 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1163 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 34:
#line 420 "bison/f_parser.y" // lalr1.cc:859
    {
        bool any_error = false;
        for (auto& node : yystack_[0].value.as< AST::node_ptrs > ()) {
            auto entry = std::make_shared<Entry>(node->id(), yystack_[1].value.as< AST::node_ptr > ()->var_type(), node->struct_type());
            bool inserted = Mapper::get().insert(node->id(), entry);
            if (!inserted) {
                std::string error_msg = "redeclaration of variable '" + node->id() + "'";
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
#line 1186 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 35:
#line 440 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1194 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 36:
#line 443 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1203 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 37:
#line 449 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1211 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 38:
#line 452 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::integer > ());
    }
#line 1219 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 39:
#line 455 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IdentifierDeclaration>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptr > ()));
    }
#line 1227 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 40:
#line 460 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ParameterStatement>(std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1235 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 41:
#line 465 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1243 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 42:
#line 468 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1252 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 43:
#line 474 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;
        auto var_entry = Mapper::get().lookup_var(yystack_[2].value.as< AST::node_ptr > ()->id());
        if (var_entry) {
            if (var_entry->type() == yystack_[0].value.as< AST::node_ptr > ()->var_type()) {
                yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
            } else {
                error_msg += "type mismatch";
                any_error = true;
            }
        } else {
            error_msg += "variable '" + yystack_[2].value.as< AST::node_ptr > ()->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }
    }
#line 1277 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 44:
#line 494 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<AssignmentStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1285 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 45:
#line 499 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Comparison>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::comp > ());
    }
#line 1293 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 46:
#line 502 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1301 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 47:
#line 505 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1309 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 48:
#line 508 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1317 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 49:
#line 511 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::arithmetic > ());
    }
#line 1325 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 50:
#line 514 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1333 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 51:
#line 517 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1341 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 52:
#line 520 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Expression>(std::move(yystack_[0].value.as< AST::node_ptr > ()), yystack_[1].value.as< Fortran::op::logic > ());
    }
#line 1349 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 53:
#line 523 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[1].value.as< AST::node_ptr > ());
    }
#line 1357 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 54:
#line 526 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1365 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 55:
#line 529 "bison/f_parser.y" // lalr1.cc:859
    {
        auto var_entry = Mapper::get().lookup_var(yystack_[0].value.as< AST::node_ptr > ()->id());
        if (var_entry) {
            yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
        } else {
            std::string error_msg = "variable '" + yystack_[0].value.as< AST::node_ptr > ()->id() + "' not declared";
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }
    }
#line 1380 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 56:
#line 539 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1388 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 57:
#line 544 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;
        
        // Check if function is declared
        if (Mapper::get().lookup_fun(yystack_[3].value.as< AST::node_ptr > ()->id())) {

            auto args = Mapper::get().args(yystack_[3].value.as< AST::node_ptr > ()->id());

            // Check number of arguments equals the number of parameters
            if (args.size() == yystack_[1].value.as< AST::node_ptrs > ().size()) {

                // Check parameter types
                std::string params = "";
                for (unsigned int i = 0; i < yystack_[1].value.as< AST::node_ptrs > ().size(); i++) {
                    
                    // Check if parameter was declared in the current scope
                    auto param_entry = Mapper::get().lookup_var(yystack_[1].value.as< AST::node_ptrs > ()[i]->id());
                    if (param_entry) {
                        // Get the entry in the function scope
                        auto arg = Mapper::get().lookup_var(args[i], yystack_[3].value.as< AST::node_ptr > ()->id());
                        if (param_entry->type() != arg->type()) {
                            params += yystack_[1].value.as< AST::node_ptrs > ()[i]->id() + " ";
                            any_error = true;
                        }
                    } else {
                        error_msg += "param '" + yystack_[1].value.as< AST::node_ptrs > ()[i]->id() + "' not declared";
                        any_error = true;
                        break;    
                    }
                }
                if (any_error && params != "") {
                    error_msg += "type mismatch in function call with paramaters [" + params + "]";
                } else {
                    yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
                }
            } else {
                error_msg += "function '" + yystack_[3].value.as< AST::node_ptr > ()->id() + "' expects " + std::to_string(args.size()) + " parameters.";
                any_error = true;
            }
        } else {
            error_msg += "function '" + yystack_[3].value.as< AST::node_ptr > ()->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }
    }
#line 1442 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 58:
#line 593 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;
        
        // Check if function is declared
        if (Mapper::get().lookup_fun(yystack_[2].value.as< AST::node_ptr > ()->id())) {

            auto args = Mapper::get().args();

            // Check arguments
            if (args.size() == 0) {
                yylhs.value.as< AST::node_ptr > () = driver.createNode<FunctionCall>(std::move(yystack_[2].value.as< AST::node_ptr > ()), node_ptrs{});
            } else {
                error_msg += "function '" + yystack_[2].value.as< AST::node_ptr > ()->id() + "' expects 0 parameters.";
                any_error = true;
            }
        } else {
            error_msg += "function '" + yystack_[2].value.as< AST::node_ptr > ()->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }

    }
#line 1473 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 59:
#line 621 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::integer > ());
    }
#line 1481 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 60:
#line 624 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::real > ());
    }
#line 1489 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 61:
#line 627 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::boolean > ());
    }
#line 1497 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 62:
#line 630 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<Literal>(yystack_[0].value.as< Fortran::string > ());
    }
#line 1505 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 63:
#line 635 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1513 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 64:
#line 638 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ExecutableConstruct>(node_ptrs{});
    }
#line 1521 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 65:
#line 643 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1529 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 66:
#line 646 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1538 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 67:
#line 652 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1546 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 68:
#line 655 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1554 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 69:
#line 658 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1562 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 70:
#line 661 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1570 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 71:
#line 664 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1578 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 72:
#line 667 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1586 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 73:
#line 670 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = std::move(yystack_[0].value.as< AST::node_ptr > ());
    }
#line 1594 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 74:
#line 684 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, node_ptrs{});
    }
#line 1602 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 75:
#line 687 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[5].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptrs > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1610 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 76:
#line 690 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<IfStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()), node_ptrs{}, std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1618 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 77:
#line 695 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1626 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 78:
#line 698 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1635 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 79:
#line 704 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ElseIfStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1643 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 80:
#line 709 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
    }
#line 1651 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 81:
#line 714 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1659 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 82:
#line 717 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[1].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1668 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 83:
#line 723 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<ReadStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1676 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 84:
#line 728 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<PrintStatement>(std::move(yystack_[0].value.as< AST::node_ptrs > ()));
    }
#line 1684 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 85:
#line 733 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = driver.createNodeList(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1692 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 86:
#line 736 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptrs > () = std::move(yystack_[2].value.as< AST::node_ptrs > ());
        yylhs.value.as< AST::node_ptrs > ().emplace_back(std::move(yystack_[0].value.as< AST::node_ptr > ()));
    }
#line 1701 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 87:
#line 742 "bison/f_parser.y" // lalr1.cc:859
    {
        std::string error_msg = "";
        bool any_error = false;

        // Check loop var type
        auto var_entry = Mapper::get().lookup_var(yystack_[8].value.as< AST::node_ptr > ()->id());
        if (var_entry) {
            
            // The loop variable must be an integer number
            if (var_entry->type() == Fortran::type::INTEGER) {

                // Check type matching
                if (yystack_[8].value.as< AST::node_ptr > ()->var_type() == yystack_[6].value.as< AST::node_ptr > ()->var_type() &&
                    yystack_[8].value.as< AST::node_ptr > ()->var_type() == yystack_[4].value.as< AST::node_ptr > ()->var_type() &&
                    yystack_[8].value.as< AST::node_ptr > ()->var_type() == yystack_[2].value.as< AST::node_ptr > ()->var_type()) {

                    yylhs.value.as< AST::node_ptr > () = driver.createNode<DoStatement>(std::move(yystack_[8].value.as< AST::node_ptr > ()),
                        std::move(yystack_[6].value.as< AST::node_ptr > ()), std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));

                } else {
                    error_msg += "type mismatch in do loop declaration";
                    any_error = true;
                }
            } else {
                error_msg += "do loop variable must be of type INTEGER";
                any_error = true;
            }
        } else {
            error_msg += "variable '" + yystack_[8].value.as< AST::node_ptr > ()->id() + "' not declared";
            any_error = true;
        }
        if (any_error) {
            driver.semantic_error(error_msg);
            yylhs.value.as< AST::node_ptr > () = driver.createNode<ErrorNode>(error_msg);
        }
    }
#line 1742 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 88:
#line 780 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<WhileStatement>(std::move(yystack_[4].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1750 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 89:
#line 785 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[3].value.as< AST::node_ptr > ()), std::move(yystack_[1].value.as< AST::node_ptrs > ()));
    }
#line 1758 "src/f_parser.cpp" // lalr1.cc:859
    break;

  case 90:
#line 788 "bison/f_parser.y" // lalr1.cc:859
    {
        yylhs.value.as< AST::node_ptr > () = driver.createNode<CallStatement>(std::move(yystack_[2].value.as< AST::node_ptr > ()), std::move(node_ptrs{}));
    }
#line 1766 "src/f_parser.cpp" // lalr1.cc:859
    break;


#line 1770 "src/f_parser.cpp" // lalr1.cc:859
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
      33,     4,     8,   -92,    31,   -92,   -92,   -92,   -92,    13,
      37,   -92,     3,    44,   -92,    49,   -92,   -92,     9,    56,
      52,    47,   103,   175,     3,   -92,   -92,   -92,   110,   -16,
     118,   -92,   100,   -92,    47,   -92,   101,   112,   -92,   130,
     120,   121,    47,    95,   114,    47,    16,   -92,   -92,   175,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,     3,
     -92,    38,   -92,   136,   -12,    71,   -92,   -15,    47,   -92,
      95,    95,   129,    95,    95,   -92,   -92,   -92,   -92,   133,
     268,   -92,   -92,   135,   137,   140,    95,    95,   -92,   161,
     114,     3,   -92,     3,    80,    47,   -92,   143,   144,   -92,
     206,   220,    95,   234,   268,   191,    95,    95,    95,    95,
      95,    95,    95,    95,     0,   248,   268,   172,   -92,   181,
     182,     3,   -92,   -92,   -92,   178,   176,   177,   -92,   -92,
     -92,    83,   -92,   -92,    59,    59,   -26,   -26,   268,   268,
     212,   268,   -92,    92,   162,   -92,   193,   195,   197,   175,
     175,    95,   218,   -92,   -92,    95,   -92,   -92,   204,   -92,
      65,   131,   192,   -92,   268,   -92,   175,   173,   -92,   -92,
      57,   -92,   -92,   -92,    95,   157,    95,   -92,   -92,    82,
     -92,   262,   164,   187,   -92,   175,   175
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
      45,    86,    90,     0,     0,    10,     0,     0,     0,     0,
       0,     0,     0,    57,    89,     0,     9,    13,     0,    81,
       0,     0,     0,    23,    44,    12,     0,     0,    74,    82,
       0,    77,    76,    88,     0,     0,     0,    78,    75,     0,
      80,     0,     0,     0,    87,     0,    79
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -92,   -92,   209,   -92,   -92,   -92,   -92,   -92,   -92,   -21,
     -41,   124,   -92,    63,    66,   -53,   -92,   -92,   196,   -92,
     -92,   159,   -92,   -92,   -33,   -54,   -92,   -91,   -92,   -92,
     -19,   -92,   -92,    90,    99,   -90,   -92,   -92,   -92,   -92,
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
      36,    66,    46,    84,    50,    10,    89,   110,   111,    13,
      30,    59,    20,    46,   133,    93,   100,   101,    18,   103,
     104,    72,    97,    94,    85,    60,    35,   142,    46,    60,
      88,    16,   115,   116,     1,     2,     1,     2,   119,     3,
     120,    60,    86,    19,    87,    11,    98,    36,   127,    14,
      31,    28,   134,   135,   136,   137,   138,   139,   140,   141,
     161,   133,   122,    90,    33,    91,     9,     3,   148,     3,
       9,   166,   167,   143,    46,    29,   175,    40,    34,   166,
     167,   168,    41,    42,   130,    43,    44,    45,    35,   182,
     108,   109,   110,   111,    40,   186,    95,   162,    96,    41,
      42,   164,    43,    44,    45,    90,    35,   121,   152,    39,
     153,   106,   107,   108,   109,   110,   111,    90,    58,   154,
     179,    73,   181,    35,   112,    63,    64,    67,    46,    46,
      74,   130,    75,    76,    77,    78,    35,    68,    69,    46,
      46,   169,   169,    40,    92,    46,    70,    71,    41,    42,
     173,    43,    44,    45,    46,    60,   169,   102,    46,   105,
     113,    46,    90,   169,    46,    46,   114,   169,   117,    40,
     123,   124,    35,   180,    41,    42,    40,    43,    44,    45,
     145,    41,    42,   184,    43,    44,    45,    40,   146,   147,
     155,   149,    41,    42,   150,    43,    44,    45,    35,   176,
     185,   156,   151,   157,   158,    35,   106,   107,   108,   109,
     110,   111,   165,    17,   118,   163,    35,   174,   129,   112,
      57,   106,   107,   108,   109,   110,   111,    99,    75,    76,
      77,    78,    35,   125,   112,   106,   107,   108,   109,   110,
     111,   106,   107,   108,   109,   110,   111,   126,   112,   106,
     107,   108,   109,   110,   111,    75,    76,    77,    78,    35,
     177,   128,   112,   106,   107,   108,   109,   110,   111,   178,
       0,     0,     0,     0,     0,   144,   112,   106,   107,   108,
     109,   110,   111,     0,     0,     0,     0,     0,     0,   183,
     112,   106,   107,   108,   109,   110,   111,   106,   107,   108,
     109,   110,   111,     0,   112,     0,     0,     0,     0,     0,
     112
  };

  const short int
   Parser ::yycheck_[] =
  {
      21,    34,    23,    44,    23,     1,    59,    33,    34,     1,
       1,    27,     9,    34,   105,    27,    70,    71,     5,    73,
      74,    42,    37,    64,    45,    41,    41,    27,    49,    41,
      49,     0,    86,    87,     3,     4,     3,     4,    91,    36,
      93,    41,    26,     6,    28,    41,    67,    68,   102,    41,
      41,     7,   106,   107,   108,   109,   110,   111,   112,   113,
     150,   152,    95,    25,     8,    27,     0,    36,   121,    36,
       4,    14,    15,   114,    95,    26,   166,    12,    26,    14,
      15,    16,    17,    18,   105,    20,    21,    22,    41,   179,
      31,    32,    33,    34,    12,   185,    25,   151,    27,    17,
      18,   155,    20,    21,    22,    25,    41,    27,    25,     6,
      27,    29,    30,    31,    32,    33,    34,    25,     8,    27,
     174,    26,   176,    41,    42,     7,    26,    26,   149,   150,
      35,   152,    37,    38,    39,    40,    41,    25,     8,   160,
     161,   160,   161,    12,     8,   166,    26,    26,    17,    18,
      19,    20,    21,    22,   175,    41,   175,    28,   179,    26,
      25,   182,    25,   182,   185,   186,    26,   186,     7,    12,
      27,    27,    41,    16,    17,    18,    12,    20,    21,    22,
       8,    17,    18,    19,    20,    21,    22,    12,     7,     7,
      28,    13,    17,    18,    18,    20,    21,    22,    41,    26,
      13,     8,    25,     8,     7,    41,    29,    30,    31,    32,
      33,    34,     8,     4,    90,   152,    41,    25,    27,    42,
      24,    29,    30,    31,    32,    33,    34,    68,    37,    38,
      39,    40,    41,    27,    42,    29,    30,    31,    32,    33,
      34,    29,    30,    31,    32,    33,    34,    27,    42,    29,
      30,    31,    32,    33,    34,    37,    38,    39,    40,    41,
     170,    27,    42,    29,    30,    31,    32,    33,    34,   170,
      -1,    -1,    -1,    -1,    -1,    27,    42,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      42,    29,    30,    31,    32,    33,    34,    29,    30,    31,
      32,    33,    34,    -1,    42,    -1,    -1,    -1,    -1,    -1,
      42
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
      75,    76,    77,    19,    25,    78,    26,    76,    77,    68,
      16,    68,    78,    27,    19,    13,    78
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
      77,    78,    78,    79,    80,    81,    81,    82,    83,    84,
      84
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
       3,     1,     2,     2,     2,     1,     3,    10,     7,     5,
       4
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
     220,   224,   231,   277,   306,   313,   325,   337,   349,   354,
     357,   363,   368,   371,   377,   380,   385,   390,   395,   398,
     403,   406,   412,   415,   420,   440,   443,   449,   452,   455,
     460,   465,   468,   474,   494,   499,   502,   505,   508,   511,
     514,   517,   520,   523,   526,   529,   539,   544,   593,   621,
     624,   627,   630,   635,   638,   643,   646,   652,   655,   658,
     661,   664,   667,   670,   684,   687,   690,   695,   698,   704,
     709,   714,   717,   723,   728,   733,   736,   742,   780,   785,
     788
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
#line 2306 "src/f_parser.cpp" // lalr1.cc:1167
#line 801 "bison/f_parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location &loc, const std::string &message) {
   driver.printError(message);
}
