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


// First part of user declarations.

#line 37 "parser.tab.c" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.tab.h"

// User implementation prologue.

#line 51 "parser.tab.c" // lalr1.cc:412
// Unqualified %code blocks.
#line 28 "parser.y" // lalr1.cc:413

    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    /* Include for all driver functions */
    #include "include/f_driver.hpp"

    #undef yylex
    #define yylex scanner.yylex

#line 65 "parser.tab.c" // lalr1.cc:413


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

#line 5 "parser.y" // lalr1.cc:479
namespace  Fortran  {
#line 151 "parser.tab.c" // lalr1.cc:479

  /// Build a parser object.
   Parser :: Parser  (Scanner &scanner_yyarg, Driver &driver_yyarg)
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

  inline
   Parser ::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
      switch (other.type_get ())
    {
      case 43: // "number number"
        value.copy< float > (other.value);
        break;

      case 42: // "integer number"
        value.copy< int > (other.value);
        break;

      case 44: // "id"
      case 45: // "string"
        value.copy< std::string > (other.value);
        break;

      default:
        break;
    }

  }


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
      switch (this->type_get ())
    {
      case 43: // "number number"
        value.copy< float > (v);
        break;

      case 42: // "integer number"
        value.copy< int > (v);
        break;

      case 44: // "id"
      case 45: // "string"
        value.copy< std::string > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const float v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const int v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
   Parser ::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  inline
   Parser ::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
    switch (yytype)
    {
      case 43: // "number number"
        value.template destroy< float > ();
        break;

      case 42: // "integer number"
        value.template destroy< int > ();
        break;

      case 44: // "id"
      case 45: // "string"
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  inline
  bool
   Parser ::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
   Parser ::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
      switch (this->type_get ())
    {
      case 43: // "number number"
        value.move< float > (s.value);
        break;

      case 42: // "integer number"
        value.move< int > (s.value);
        break;

      case 44: // "id"
      case 45: // "string"
        value.move< std::string > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
   Parser ::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
   Parser ::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
   Parser ::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
   Parser ::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
   Parser ::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
   Parser ::by_type::type_get () const
  {
    return type;
  }
  // Implementation of make_symbol for each symbol type.
   Parser ::symbol_type
   Parser ::make_PROGRAM (const location_type& l)
  {
    return symbol_type (token::PROGRAM, l);
  }

   Parser ::symbol_type
   Parser ::make_SUBROUTINE (const location_type& l)
  {
    return symbol_type (token::SUBROUTINE, l);
  }

   Parser ::symbol_type
   Parser ::make_FUNCTION (const location_type& l)
  {
    return symbol_type (token::FUNCTION, l);
  }

   Parser ::symbol_type
   Parser ::make_STOP (const location_type& l)
  {
    return symbol_type (token::STOP, l);
  }

   Parser ::symbol_type
   Parser ::make_RETURN (const location_type& l)
  {
    return symbol_type (token::RETURN, l);
  }

   Parser ::symbol_type
   Parser ::make_END (const location_type& l)
  {
    return symbol_type (token::END, l);
  }

   Parser ::symbol_type
   Parser ::make_PARAMETER (const location_type& l)
  {
    return symbol_type (token::PARAMETER, l);
  }

   Parser ::symbol_type
   Parser ::make_INTEGER (const location_type& l)
  {
    return symbol_type (token::INTEGER, l);
  }

   Parser ::symbol_type
   Parser ::make_REAL (const location_type& l)
  {
    return symbol_type (token::REAL, l);
  }

   Parser ::symbol_type
   Parser ::make_CYCLE (const location_type& l)
  {
    return symbol_type (token::CYCLE, l);
  }

   Parser ::symbol_type
   Parser ::make_EXIT (const location_type& l)
  {
    return symbol_type (token::EXIT, l);
  }

   Parser ::symbol_type
   Parser ::make_IF (const location_type& l)
  {
    return symbol_type (token::IF, l);
  }

   Parser ::symbol_type
   Parser ::make_ELSE (const location_type& l)
  {
    return symbol_type (token::ELSE, l);
  }

   Parser ::symbol_type
   Parser ::make_ELSEIF (const location_type& l)
  {
    return symbol_type (token::ELSEIF, l);
  }

   Parser ::symbol_type
   Parser ::make_ENDIF (const location_type& l)
  {
    return symbol_type (token::ENDIF, l);
  }

   Parser ::symbol_type
   Parser ::make_WHILE (const location_type& l)
  {
    return symbol_type (token::WHILE, l);
  }

   Parser ::symbol_type
   Parser ::make_DO (const location_type& l)
  {
    return symbol_type (token::DO, l);
  }

   Parser ::symbol_type
   Parser ::make_ENDDO (const location_type& l)
  {
    return symbol_type (token::ENDDO, l);
  }

   Parser ::symbol_type
   Parser ::make_PRINT (const location_type& l)
  {
    return symbol_type (token::PRINT, l);
  }

   Parser ::symbol_type
   Parser ::make_READ (const location_type& l)
  {
    return symbol_type (token::READ, l);
  }

   Parser ::symbol_type
   Parser ::make_CALL (const location_type& l)
  {
    return symbol_type (token::CALL, l);
  }

   Parser ::symbol_type
   Parser ::make_ERR (const location_type& l)
  {
    return symbol_type (token::ERR, l);
  }

   Parser ::symbol_type
   Parser ::make_EOL (const location_type& l)
  {
    return symbol_type (token::EOL, l);
  }

   Parser ::symbol_type
   Parser ::make_SUM (const location_type& l)
  {
    return symbol_type (token::SUM, l);
  }

   Parser ::symbol_type
   Parser ::make_SUB (const location_type& l)
  {
    return symbol_type (token::SUB, l);
  }

   Parser ::symbol_type
   Parser ::make_TIMES (const location_type& l)
  {
    return symbol_type (token::TIMES, l);
  }

   Parser ::symbol_type
   Parser ::make_DIV (const location_type& l)
  {
    return symbol_type (token::DIV, l);
  }

   Parser ::symbol_type
   Parser ::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::ASSIGN, l);
  }

   Parser ::symbol_type
   Parser ::make_EQ (const location_type& l)
  {
    return symbol_type (token::EQ, l);
  }

   Parser ::symbol_type
   Parser ::make_NE (const location_type& l)
  {
    return symbol_type (token::NE, l);
  }

   Parser ::symbol_type
   Parser ::make_GT (const location_type& l)
  {
    return symbol_type (token::GT, l);
  }

   Parser ::symbol_type
   Parser ::make_GE (const location_type& l)
  {
    return symbol_type (token::GE, l);
  }

   Parser ::symbol_type
   Parser ::make_LT (const location_type& l)
  {
    return symbol_type (token::LT, l);
  }

   Parser ::symbol_type
   Parser ::make_LE (const location_type& l)
  {
    return symbol_type (token::LE, l);
  }

   Parser ::symbol_type
   Parser ::make_TRUE (const location_type& l)
  {
    return symbol_type (token::TRUE, l);
  }

   Parser ::symbol_type
   Parser ::make_FALSE (const location_type& l)
  {
    return symbol_type (token::FALSE, l);
  }

   Parser ::symbol_type
   Parser ::make_COMMA (const location_type& l)
  {
    return symbol_type (token::COMMA, l);
  }

   Parser ::symbol_type
   Parser ::make_LP (const location_type& l)
  {
    return symbol_type (token::LP, l);
  }

   Parser ::symbol_type
   Parser ::make_RP (const location_type& l)
  {
    return symbol_type (token::RP, l);
  }

   Parser ::symbol_type
   Parser ::make_INT (const int& v, const location_type& l)
  {
    return symbol_type (token::INT, v, l);
  }

   Parser ::symbol_type
   Parser ::make_FLOAT (const float& v, const location_type& l)
  {
    return symbol_type (token::FLOAT, v, l);
  }

   Parser ::symbol_type
   Parser ::make_ID (const std::string& v, const location_type& l)
  {
    return symbol_type (token::ID, v, l);
  }

   Parser ::symbol_type
   Parser ::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::STRING, v, l);
  }



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
      case 43: // "number number"
        value.move< float > (that.value);
        break;

      case 42: // "integer number"
        value.move< int > (that.value);
        break;

      case 44: // "id"
      case 45: // "string"
        value.move< std::string > (that.value);
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
      case 43: // "number number"
        value.copy< float > (that.value);
        break;

      case 42: // "integer number"
        value.copy< int > (that.value);
        break;

      case 44: // "id"
      case 45: // "string"
        value.copy< std::string > (that.value);
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
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
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
      case 43: // "number number"
        yylhs.value.build< float > ();
        break;

      case 42: // "integer number"
        yylhs.value.build< int > ();
        break;

      case 44: // "id"
      case 45: // "string"
        yylhs.value.build< std::string > ();
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

#line 1004 "parser.tab.c" // lalr1.cc:859
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
   Parser ::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char  Parser ::yypact_ninf_ = -83;

  const signed char  Parser ::yytable_ninf_ = -1;

  const short int
   Parser ::yypact_[] =
  {
     -36,   -30,     8,   -83,   143,   -83,   -83,   -18,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -11,    18,    34,     2,    55,
       3,    56,    32,   -83,    32,    62,   -83,   -83,    57,   -83,
     -83,    28,   -83,    77,   -83,   159,   -83,   -83,   -83,   -83,
     -83,   159,   -83,    91,   -83,   159,   -83,   -83,   -83,   -83,
      56,    56,    92,    44,    95,    94,    44,    44,   -83,   -83,
      99,   -83,   -83,    11,   101,   -83,   102,   -83,   -83,   103,
     -83,   -83,   -15,    86,   -83,    81,   108,   112,   -83,   -83,
     -83,   109,   104,   -83,   -83,    36,   -83,   132,   159,    96,
     -83,    52,    66,   -83,    11,   124,   134,    78,   -83,   -83,
      -2,    24,    44,    44,    44,    44,     3,   128,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,    44,   -83,   -83,    48,
     -83,   141,    77,   -83,    44,    44,   -83,   -83,   159,   -83,
      44,   107,   -83,   -83,   143,   143,   154,    -9,    94,   -83,
     -83,   -83,    11,    79,   101,   101,   -83,   -83,   -83,   -83,
      11,   -83,    83,   144,   -83,   -19,    -4,   -83,     1,   -83,
     100,   123,    44,   -83,   -83,   -83,   -83,    44,   -83,   -83,
     -83,   -83,   -83,    44,   138,   -83,   140,   -83,    11,    11,
      51,   -83,   -83,    44,    11
  };

  const unsigned char
   Parser ::yydefact_[] =
  {
       0,     0,     0,     2,     0,     9,     1,     0,    26,    27,
      28,    29,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,   106,   107,     0,    17,
      19,    21,    23,     0,    22,    20,    42,    44,    45,    46,
      47,     0,    48,     0,    49,     0,    50,    51,    52,    11,
       0,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      64,    72,    65,    73,    55,    58,    69,    70,    15,    74,
      94,    95,     0,     0,    85,     0,     0,     0,     6,    18,
      24,    32,    25,    30,    43,     0,    75,     0,     0,     0,
     101,     0,     0,    13,    53,     0,     0,     0,    35,    66,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,    92,    93,    86,    87,     0,    76,   102,     0,
      10,     0,     0,    80,     0,     0,    77,    78,     0,    79,
       0,     0,    96,   103,     0,     0,     0,     0,     0,    34,
      61,    63,    67,     0,    56,    57,    59,    60,    71,    16,
      84,   105,     0,     0,    31,     0,     0,    81,     0,   100,
       0,     0,     0,    39,    37,    38,    36,     0,    62,   104,
      33,    82,    83,     0,     0,     7,     0,     8,    54,    68,
      98,    12,    14,     0,    99
  };

  const short int
   Parser ::yypgoto_[] =
  {
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -46,   -82,   -27,   -83,   -83,   173,   188,   -83,
      84,   -83,   -83,    67,   -83,    70,   -83,   -32,   -83,   -22,
      29,   -50,   -83,   -83,   -83,   113,   -83,   -83,   -83,    80,
     -83,   -83,   -83,   -83,   186,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83
  };

  const short int
   Parser ::yydefgoto_[] =
  {
      -1,     2,    12,     3,    13,    14,     4,    78,    15,   175,
      16,   177,    69,    28,    29,    30,    31,    32,    33,    82,
      83,    34,    97,    98,   164,    62,    35,    36,    37,    63,
      64,    65,   143,    38,    66,    67,    39,    40,    41,    86,
     126,   127,   128,   129,    73,   116,    74,    42,    43,    88,
     132,    44,    45,    90,    46,    47,    48
  };

  const unsigned char
   Parser ::yytable_[] =
  {
      72,    79,    72,    84,    91,    92,    99,   102,   103,    85,
       1,   102,   103,    89,     5,     6,   108,   109,   110,   111,
     112,   113,   102,   103,   102,   103,    49,   102,   103,    50,
      56,    94,    53,    58,    59,   100,   163,   102,   103,   140,
     173,   171,    54,    57,   172,    58,    59,    60,    61,   114,
     115,    56,   160,   161,   146,   147,   131,     7,    51,    56,
       8,     9,    10,    11,    57,   141,    58,    59,    60,    70,
      71,    56,    57,   152,    58,    59,    60,   102,   103,   142,
       8,     9,    10,    11,    57,    52,    58,    59,    60,   151,
     183,   107,    68,   134,   150,    55,    85,   123,   124,   125,
      68,    18,   155,   156,    77,   107,    76,   135,   158,     8,
       9,    10,    11,    19,    20,    21,    22,   138,   167,   139,
     168,    81,   107,    23,   169,    24,    25,    26,    27,   104,
     105,   144,   145,    79,    79,    87,    93,    95,    96,   101,
     178,   106,   107,   122,    18,   179,   117,   118,   119,   121,
     174,   180,     8,     9,    10,    11,    19,    20,    21,    22,
     120,   184,   130,   133,   137,   136,    23,    18,    24,    25,
      26,    27,   149,   176,   159,     8,     9,    10,    11,    19,
      20,    21,    22,   153,   162,   170,   181,    18,   182,    23,
      17,    24,    25,    26,    27,     8,     9,    10,    11,    19,
      20,    21,    22,    18,    80,   166,   154,   165,   157,    23,
      75,    24,    25,    26,    27,     0,    20,    21,    22,   148,
       0,     0,     0,     0,     0,    23,     0,    24,    25,    26,
      27
  };

  const short int
   Parser ::yycheck_[] =
  {
      22,    28,    24,    35,    50,    51,    56,    26,    27,    41,
      46,    26,    27,    45,    44,     7,    31,    32,    33,    34,
      35,    36,    26,    27,    26,    27,    44,    26,    27,    40,
      27,    53,    30,    42,    43,    57,    45,    26,    27,    41,
      39,    60,    40,    40,    48,    42,    43,    44,    45,    64,
      65,    27,   134,   135,   104,   105,    88,    49,    40,    27,
      52,    53,    54,    55,    40,    41,    42,    43,    44,    37,
      38,    27,    40,   119,    42,    43,    44,    26,    27,   101,
      52,    53,    54,    55,    40,    51,    42,    43,    44,    41,
      39,    39,    44,    41,   116,    40,   128,    61,    62,    63,
      44,    44,   124,   125,    47,    39,    44,    41,   130,    52,
      53,    54,    55,    56,    57,    58,    59,    39,    39,    41,
      41,    44,    39,    66,    41,    68,    69,    70,    71,    28,
      29,   102,   103,   160,   161,    44,    44,    42,    44,    40,
     162,    39,    39,    39,    44,   167,    60,    66,    40,    40,
      50,   173,    52,    53,    54,    55,    56,    57,    58,    59,
      48,   183,    30,    67,    30,    41,    66,    44,    68,    69,
      70,    71,    44,    50,    67,    52,    53,    54,    55,    56,
      57,    58,    59,    42,    30,    41,    48,    44,    48,    66,
       2,    68,    69,    70,    71,    52,    53,    54,    55,    56,
      57,    58,    59,    44,    31,   138,   122,   137,   128,    66,
      24,    68,    69,    70,    71,    -1,    57,    58,    59,   106,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,
      71
  };

  const unsigned char
   Parser ::yystos_[] =
  {
       0,    46,    73,    75,    78,    44,     7,    49,    52,    53,
      54,    55,    74,    76,    77,    80,    82,    90,    44,    56,
      57,    58,    59,    66,    68,    69,    70,    71,    85,    86,
      87,    88,    89,    90,    93,    98,    99,   100,   105,   108,
     109,   110,   119,   120,   123,   124,   126,   127,   128,    44,
      40,    40,    51,    30,    40,    40,    27,    40,    42,    43,
      44,    45,    97,   101,   102,   103,   106,   107,    44,    84,
      37,    38,   101,   116,   118,   116,    44,    47,    79,    86,
      89,    44,    91,    92,    99,    99,   111,    44,   121,    99,
     125,    84,    84,    44,   101,    42,    44,    94,    95,   103,
     101,    40,    26,    27,    28,    29,    39,    39,    31,    32,
      33,    34,    35,    36,    64,    65,   117,    60,    66,    40,
      48,    40,    39,    61,    62,    63,   112,   113,   114,   115,
      30,    99,   122,    67,    41,    41,    41,    30,    39,    41,
      41,    41,   101,   104,   102,   102,   103,   103,   107,    44,
     101,    41,    84,    42,    92,   101,   101,   111,   101,    67,
      85,    85,    30,    45,    96,    97,    95,    39,    41,    41,
      41,    60,    48,    39,    50,    81,    50,    83,   101,   101,
     101,    48,    48,    39,   101
  };

  const unsigned char
   Parser ::yyr1_[] =
  {
       0,    72,    73,    73,    74,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    95,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   104,   104,   105,
     106,   106,   107,   107,   108,   109,   110,   111,   111,   111,
     112,   113,   114,   115,   116,   116,   117,   117,   117,   117,
     117,   117,   117,   117,   118,   118,   119,   120,   121,   121,
     122,   123,   124,   125,   126,   126,   127,   128
  };

  const unsigned char
   Parser ::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     3,     6,     6,     2,
       2,     2,     2,     3,     2,     1,     3,     1,     2,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     3,     1,     4,     4,     1,     3,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     6,     1,     3,     3,     1,     3,
       3,     3,     4,     3,     1,     1,     2,     1,     3,     2,
       1,     3,     1,     1,     2,     2,     3,     2,     2,     2,
       1,     2,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     7,
       2,     2,     3,     2,     5,     4,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const  Parser ::yytname_[] =
  {
  "error", "$undefined", "\"program keyword\"", "\"subroutine  keyword\"",
  "\"function  keyword\"", "\"stop keyword\"", "\"return keyword\"",
  "\"end keyword\"", "\"parameter\"", "\"integer keyword\"",
  "\"real keyword\"", "\"cycle keyword\"", "\"exit keyword\"",
  "\"if keyword\"", "\"else keyword\"", "\"elseif keyword\"",
  "\"endif keyword\"", "\"while keyword\"", "\"do keyword\"",
  "\"enddo keyword\"", "\"print keyword\"", "\"read keyword\"",
  "\"call keyword\"", "\"error\"", "\"end of line\"", "\"end of file\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\".EQ.\"", "\".NE.\"",
  "\".GT.\"", "\".GE.\"", "\".LT.\"", "\".LE.\"", "\".TRUE.\"",
  "\".FALSE.\"", "\",\"", "\"(\"", "\")\"", "\"integer number\"",
  "\"number number\"", "\"id\"", "\"string\"", "\"PROGRAM\"", "\"STOP\"",
  "\"END\"", "\"SUBROUTINE\"", "\"RETURN\"", "\"FUNCTION\"", "\"INTEGER\"",
  "\"REAL\"", "\"CHARACTER\"", "\"LOGICAL\"", "\"PARAMETER\"", "\"PRINT\"",
  "\"READ\"", "\"IF\"", "\"THEN\"", "\"ENDIF\"", "\"ELSEIF\"", "\"ELSE\"",
  "\".AND.\"", "\".OR.\"", "\"DO\"", "\"ENDDO\"", "\"WHILE\"", "\"CALL\"",
  "\"CONTINUE\"", "\"EXIT\"", "$accept", "ExecutableProgram", "Subprogram",
  "MainProgram", "Subroutine", "Function", "MainProgramPrefix",
  "MainProgramSuffix", "SubroutinePrefix", "SubroutineSuffix",
  "FunctionPrefix", "FunctionSuffix", "ParameterList", "Body",
  "BodyConstruct", "SpecificationConstruct", "DeclarationConstruct",
  "Declaration", "Type", "IdentifierDeclarationList",
  "IdentifierDeclaration", "ParameterStatement", "ConstantList",
  "ConstantDefinition", "ConstantExpression", "Number",
  "ExecutableConstruct", "Statement", "AssignmentStatement", "Expression",
  "Factor", "Term", "ExpressionList", "PrintStatement", "PrintList",
  "PrintItem", "ReadStatement", "IfConstruct", "IfThenStatement",
  "ThenConstruct", "EndIfStatement", "ElseIfConstruct", "ElseIfStatement",
  "ElseConstruct", "LogicalExpression", "Op", "LogicalConstant",
  "DoConstruct", "DoStatement", "DoLoopControl", "EndDoStatement",
  "WhileConstruct", "WhileStatement", "EndWhileStatement", "CallStatement",
  "CycleStatement", "ExitStatement", YY_NULLPTR
  };


  const unsigned short int
   Parser ::yyrline_[] =
  {
       0,    95,    95,    96,   100,   101,   105,   109,   113,   117,
     121,   125,   129,   133,   137,   141,   142,   146,   147,   151,
     152,   156,   157,   161,   162,   166,   169,   170,   171,   172,
     176,   177,   181,   182,   186,   190,   191,   195,   199,   200,
     204,   205,   209,   210,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   226,   227,   231,   232,   233,   237,   238,
     239,   243,   244,   245,   246,   247,   248,   252,   253,   257,
     261,   262,   266,   267,   271,   275,   279,   283,   284,   285,
     289,   293,   297,   301,   305,   306,   310,   311,   312,   313,
     314,   315,   316,   317,   321,   322,   326,   330,   334,   335,
     339,   343,   347,   351,   355,   356,   360,   364
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

  // Symbol number corresponding to token number t.
  inline
   Parser ::token_number_type
   Parser ::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     7,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     2,     3,
       4,     5,     6,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
    };
    const unsigned int user_token_number_max_ = 326;
    const token_number_type undef_token_ = 1;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "parser.y" // lalr1.cc:1167
} //  Fortran 
#line 1501 "parser.tab.c" // lalr1.cc:1167
#line 367 "parser.y" // lalr1.cc:1168


void Fortran::Parser::error(const location_type &loc, const std::string &err_message) {
   std::cerr << "Error: " << err_message << " at " << loc << "\n";
}
