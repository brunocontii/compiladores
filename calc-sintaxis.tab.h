/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED
# define YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "calc-sintaxis.y"

    #include "ast/ast.h"
    #include "table_of_symbols/table_symbols.h"

    typedef struct {
        char* name;
        Token token;
        Type type;
    } InfoTipo;

#line 60 "calc-sintaxis.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_BOOL = 259,              /* TOKEN_BOOL  */
    TOKEN_VOID = 260,              /* TOKEN_VOID  */
    TOKEN_MAIN = 261,              /* TOKEN_MAIN  */
    TOKEN_RETURN = 262,            /* TOKEN_RETURN  */
    TOKEN_OP_RES = 263,            /* TOKEN_OP_RES  */
    TOKEN_OP_MAS = 264,            /* TOKEN_OP_MAS  */
    TOKEN_OP_MULT = 265,           /* TOKEN_OP_MULT  */
    TOKEN_OP_DIV = 266,            /* TOKEN_OP_DIV  */
    TOKEN_IGUAL = 267,             /* TOKEN_IGUAL  */
    TOKEN_PYC = 268,               /* TOKEN_PYC  */
    TOKEN_PAR_A = 269,             /* TOKEN_PAR_A  */
    TOKEN_PAR_C = 270,             /* TOKEN_PAR_C  */
    TOKEN_LLA_A = 271,             /* TOKEN_LLA_A  */
    TOKEN_LLA_C = 272,             /* TOKEN_LLA_C  */
    TOKEN_VTRUE = 273,             /* TOKEN_VTRUE  */
    TOKEN_VFALSE = 274,            /* TOKEN_VFALSE  */
    TOKEN_OP_AND = 275,            /* TOKEN_OP_AND  */
    TOKEN_OP_OR = 276,             /* TOKEN_OP_OR  */
    TOKEN_OP_NOT = 277,            /* TOKEN_OP_NOT  */
    TOKEN_ID = 278,                /* TOKEN_ID  */
    TOKEN_NUM = 279,               /* TOKEN_NUM  */
    TRUE = 280                     /* TRUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "calc-sintaxis.y"

    int ival;
    char *sval;
    Node* node;
    InfoTipo tipo_info;

#line 109 "calc-sintaxis.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CALC_SINTAXIS_TAB_H_INCLUDED  */
