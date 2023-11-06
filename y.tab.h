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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INCLUDE = 258,                 /* INCLUDE  */
    HEADERFILE = 259,              /* HEADERFILE  */
    INT = 260,                     /* INT  */
    CHAR = 261,                    /* CHAR  */
    FLOAT = 262,                   /* FLOAT  */
    STRING = 263,                  /* STRING  */
    VOID = 264,                    /* VOID  */
    RETURN = 265,                  /* RETURN  */
    INT_NUM = 266,                 /* INT_NUM  */
    FLOAT_NUM = 267,               /* FLOAT_NUM  */
    ID = 268,                      /* ID  */
    LEFTSHIFT = 269,               /* LEFTSHIFT  */
    RIGHTSHIFT = 270,              /* RIGHTSHIFT  */
    LE = 271,                      /* LE  */
    GE = 272,                      /* GE  */
    EQ = 273,                      /* EQ  */
    NE = 274,                      /* NE  */
    GT = 275,                      /* GT  */
    LT = 276,                      /* LT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    ADD = 280,                     /* ADD  */
    SUBTRACT = 281,                /* SUBTRACT  */
    DIVIDE = 282,                  /* DIVIDE  */
    MULTIPLY = 283,                /* MULTIPLY  */
    MODULO = 284,                  /* MODULO  */
    BITAND = 285,                  /* BITAND  */
    BITOR = 286,                   /* BITOR  */
    NEGATION = 287,                /* NEGATION  */
    XOR = 288,                     /* XOR  */
    STR = 289,                     /* STR  */
    CHARACTER = 290,               /* CHARACTER  */
    CC = 291,                      /* CC  */
    OC = 292,                      /* OC  */
    CS = 293,                      /* CS  */
    OS = 294,                      /* OS  */
    CF = 295,                      /* CF  */
    OF = 296,                      /* OF  */
    COMMA = 297,                   /* COMMA  */
    COLON = 298,                   /* COLON  */
    SCOL = 299,                    /* SCOL  */
    OUTPUT = 300,                  /* OUTPUT  */
    INPUT = 301,                   /* INPUT  */
    SWITCH = 302,                  /* SWITCH  */
    CASE = 303,                    /* CASE  */
    BREAK = 304,                   /* BREAK  */
    DEFAULT = 305,                 /* DEFAULT  */
    IF = 306,                      /* IF  */
    ELIF = 307,                    /* ELIF  */
    ELSE = 308,                    /* ELSE  */
    WHILE = 309,                   /* WHILE  */
    FOR = 310,                     /* FOR  */
    CONTINUE = 311,                /* CONTINUE  */
    TYPEOF = 312,                  /* TYPEOF  */
    ASSIGN = 313                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INCLUDE 258
#define HEADERFILE 259
#define INT 260
#define CHAR 261
#define FLOAT 262
#define STRING 263
#define VOID 264
#define RETURN 265
#define INT_NUM 266
#define FLOAT_NUM 267
#define ID 268
#define LEFTSHIFT 269
#define RIGHTSHIFT 270
#define LE 271
#define GE 272
#define EQ 273
#define NE 274
#define GT 275
#define LT 276
#define AND 277
#define OR 278
#define NOT 279
#define ADD 280
#define SUBTRACT 281
#define DIVIDE 282
#define MULTIPLY 283
#define MODULO 284
#define BITAND 285
#define BITOR 286
#define NEGATION 287
#define XOR 288
#define STR 289
#define CHARACTER 290
#define CC 291
#define OC 292
#define CS 293
#define OS 294
#define CF 295
#define OF 296
#define COMMA 297
#define COLON 298
#define SCOL 299
#define OUTPUT 300
#define INPUT 301
#define SWITCH 302
#define CASE 303
#define BREAK 304
#define DEFAULT 305
#define IF 306
#define ELIF 307
#define ELSE 308
#define WHILE 309
#define FOR 310
#define CONTINUE 311
#define TYPEOF 312
#define ASSIGN 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 101 "parser.y"

    struct node { 
        char lexeme[100];
        int line_number;
        char type[100];
        char if_body[5];
        char elif_body[5];
		char else_body[5];
        char loop_body[5];
        char parentNext[5];
        char case_body[5];
        char id[5];
        char temp[5];
        int nParams;
    } node;

#line 200 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
