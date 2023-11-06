/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <vector>
    #include <string.h>
    #include <queue>
    #include <set>

    #define add_tac($$, $1, $2, $3) {strcpy($$.type, $1.type);\
        sprintf($$.lexeme, get_temp().c_str());\
        string lt=string($1.type);\
        string rt=string($3.type);\
        if((lt == "CHAR" && rt == "INT") || (rt == "CHAR" && lt == "INT")){\
            strcpy($$.type, "INT");\
        }\
        else if((lt == "FLOAT" && rt == "INT") || (rt == "FLOAT" && lt == "INT")){\
            strcpy($$.type, "FLOAT");\
        }\
        else if((lt == "FLOAT" && rt == "FLOAT") || (lt == "INT" && rt == "INT") || (lt == "CHAR" && rt == "CHAR")){\
            strcpy($$.type, $1.type);\
        }\
        else{\
            sem_errors.push_back("Cannot convert between CHAR and FLOAT in line : " + to_string(countn+1));\
        }}
    
    #include <iostream>
    #include <string>
    #include <unordered_map>
    #include<map>
    #include <stack>
    #include<algorithm>
    #include<fstream>

    using namespace std;

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int yytext();

    bool check_declaration(string variable);
    bool check_scope(string variable);
    bool multiple_declaration(string variable);
    bool is_reserved_word(string id);
    bool type_check(string type1, string type2);
    bool check_type(string l, string r);
    string get_temp();

    queue<string> free_temp;
    set<string> const_temps;
    void PrintStack(stack<int> s);

    struct var_info {
        string data_type;
        int scope;
        int size;   // for arrays
        int isArray;
        int line_number; 
    };

    vector<string> tac;
    map<string, string> temp_map;

    int variable_count = 0;
    int label_counter = 0;

    vector<string> sem_errors;

    int temp_index;
    int temp_label;

    stack<int> loop_continue, loop_break;
    stack<pair<string, vector<string>>> func_call_id;
    stack<int> scope_history;
    int scope_counter = 0;

    // for array declaration with initialization
    string curr_array;
    int arr_index=0;

    extern int countn;

    struct func_info{
        string return_type;
        int num_params;
        vector<string> param_types;
        unordered_map<string, struct var_info> symbol_table;
    };

    int has_return_stmt;

    unordered_map<string, struct func_info> func_table;
    string curr_func_name="global";
    vector<string> curr_func_param_type;

    vector<string> reserved = {"int", "float", "char", "string", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "progin", "progout"};


#line 171 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 357 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INCLUDE = 3,                    /* INCLUDE  */
  YYSYMBOL_HEADERFILE = 4,                 /* HEADERFILE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_INT_NUM = 11,                   /* INT_NUM  */
  YYSYMBOL_FLOAT_NUM = 12,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 13,                        /* ID  */
  YYSYMBOL_LEFTSHIFT = 14,                 /* LEFTSHIFT  */
  YYSYMBOL_RIGHTSHIFT = 15,                /* RIGHTSHIFT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GE = 17,                        /* GE  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_LT = 21,                        /* LT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 26,                  /* SUBTRACT  */
  YYSYMBOL_DIVIDE = 27,                    /* DIVIDE  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_MODULO = 29,                    /* MODULO  */
  YYSYMBOL_BITAND = 30,                    /* BITAND  */
  YYSYMBOL_BITOR = 31,                     /* BITOR  */
  YYSYMBOL_NEGATION = 32,                  /* NEGATION  */
  YYSYMBOL_XOR = 33,                       /* XOR  */
  YYSYMBOL_STR = 34,                       /* STR  */
  YYSYMBOL_CHARACTER = 35,                 /* CHARACTER  */
  YYSYMBOL_CC = 36,                        /* CC  */
  YYSYMBOL_OC = 37,                        /* OC  */
  YYSYMBOL_CS = 38,                        /* CS  */
  YYSYMBOL_OS = 39,                        /* OS  */
  YYSYMBOL_CF = 40,                        /* CF  */
  YYSYMBOL_OF = 41,                        /* OF  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_COLON = 43,                     /* COLON  */
  YYSYMBOL_SCOL = 44,                      /* SCOL  */
  YYSYMBOL_OUTPUT = 45,                    /* OUTPUT  */
  YYSYMBOL_INPUT = 46,                     /* INPUT  */
  YYSYMBOL_SWITCH = 47,                    /* SWITCH  */
  YYSYMBOL_CASE = 48,                      /* CASE  */
  YYSYMBOL_BREAK = 49,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 50,                   /* DEFAULT  */
  YYSYMBOL_IF = 51,                        /* IF  */
  YYSYMBOL_ELIF = 52,                      /* ELIF  */
  YYSYMBOL_ELSE = 53,                      /* ELSE  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_FOR = 55,                       /* FOR  */
  YYSYMBOL_CONTINUE = 56,                  /* CONTINUE  */
  YYSYMBOL_TYPEOF = 57,                    /* TYPEOF  */
  YYSYMBOL_ASSIGN = 58,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Code = 60,                      /* Code  */
  YYSYMBOL_headerfileInclude = 61,         /* headerfileInclude  */
  YYSYMBOL_Program = 62,                   /* Program  */
  YYSYMBOL_func_list = 63,                 /* func_list  */
  YYSYMBOL_func = 64,                      /* func  */
  YYSYMBOL_65_1 = 65,                      /* $@1  */
  YYSYMBOL_func_prefix = 66,               /* func_prefix  */
  YYSYMBOL_67_2 = 67,                      /* $@2  */
  YYSYMBOL_func_data_type = 68,            /* func_data_type  */
  YYSYMBOL_param_list = 69,                /* param_list  */
  YYSYMBOL_70_3 = 70,                      /* $@3  */
  YYSYMBOL_param = 71,                     /* param  */
  YYSYMBOL_stmt_list = 72,                 /* stmt_list  */
  YYSYMBOL_stmt = 73,                      /* stmt  */
  YYSYMBOL_declaration = 74,               /* declaration  */
  YYSYMBOL_75_4 = 75,                      /* $@4  */
  YYSYMBOL_arr_values = 76,                /* arr_values  */
  YYSYMBOL_77_5 = 77,                      /* $@5  */
  YYSYMBOL_return_stmt = 78,               /* return_stmt  */
  YYSYMBOL_data_type = 79,                 /* data_type  */
  YYSYMBOL_expr = 80,                      /* expr  */
  YYSYMBOL_postfix_expr = 81,              /* postfix_expr  */
  YYSYMBOL_unary_expr = 82,                /* unary_expr  */
  YYSYMBOL_primary_expr = 83,              /* primary_expr  */
  YYSYMBOL_unary_op = 84,                  /* unary_op  */
  YYSYMBOL_const = 85,                     /* const  */
  YYSYMBOL_assign = 86,                    /* assign  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_88_6 = 88,                      /* $@6  */
  YYSYMBOL_89_7 = 89,                      /* $@7  */
  YYSYMBOL_90_8 = 90,                      /* $@8  */
  YYSYMBOL_91_9 = 91,                      /* $@9  */
  YYSYMBOL_elif_stmt = 92,                 /* elif_stmt  */
  YYSYMBOL_93_10 = 93,                     /* $@10  */
  YYSYMBOL_94_11 = 94,                     /* $@11  */
  YYSYMBOL_95_12 = 95,                     /* $@12  */
  YYSYMBOL_96_13 = 96,                     /* $@13  */
  YYSYMBOL_else_stmt = 97,                 /* else_stmt  */
  YYSYMBOL_98_14 = 98,                     /* $@14  */
  YYSYMBOL_switch_stmt = 99,               /* switch_stmt  */
  YYSYMBOL_100_15 = 100,                   /* $@15  */
  YYSYMBOL_101_16 = 101,                   /* $@16  */
  YYSYMBOL_102_17 = 102,                   /* $@17  */
  YYSYMBOL_case_stmt_list = 103,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 104,                /* case_stmt  */
  YYSYMBOL_105_18 = 105,                   /* $@18  */
  YYSYMBOL_106_19 = 106,                   /* $@19  */
  YYSYMBOL_default_stmt = 107,             /* default_stmt  */
  YYSYMBOL_while_loop_stmt = 108,          /* while_loop_stmt  */
  YYSYMBOL_109_20 = 109,                   /* $@20  */
  YYSYMBOL_110_21 = 110,                   /* $@21  */
  YYSYMBOL_111_22 = 111,                   /* $@22  */
  YYSYMBOL_for_loop_stmt = 112,            /* for_loop_stmt  */
  YYSYMBOL_113_23 = 113,                   /* $@23  */
  YYSYMBOL_114_24 = 114,                   /* $@24  */
  YYSYMBOL_115_25 = 115,                   /* $@25  */
  YYSYMBOL_116_26 = 116,                   /* $@26  */
  YYSYMBOL_func_call = 117,                /* func_call  */
  YYSYMBOL_118_27 = 118,                   /* $@27  */
  YYSYMBOL_arg_list = 119,                 /* arg_list  */
  YYSYMBOL_arg = 120                       /* arg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   638

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   137,   137,   139,   140,   143,   145,   148,   152,   151,
     167,   166,   181,   185,   191,   191,   200,   206,   211,   217,
     218,   221,   222,   223,   224,   225,   226,   227,   228,   233,
     238,   239,   244,   252,   255,   258,   269,   278,   287,   294,
     304,   314,   320,   320,   329,   329,   337,   347,   356,   361,
     364,   367,   370,   373,   381,   387,   393,   423,   453,   459,
     465,   471,   477,   483,   493,   516,   539,   569,   575,   581,
     604,   652,   700,   705,   710,   714,   731,   737,   753,   770,
     776,   798,   804,   805,   806,   807,   810,   814,   818,   824,
     847,   861,   863,   865,   868,   877,   879,   865,   890,   895,
     904,   907,   890,   914,   917,   917,   918,   921,   926,   930,
     921,   940,   944,   947,   950,   947,   964,   965,   968,   974,
     986,   968,   998,  1002,  1016,  1021,   998,  1033,  1033,  1055,
    1063,  1071,  1074
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INCLUDE",
  "HEADERFILE", "INT", "CHAR", "FLOAT", "STRING", "VOID", "RETURN",
  "INT_NUM", "FLOAT_NUM", "ID", "LEFTSHIFT", "RIGHTSHIFT", "LE", "GE",
  "EQ", "NE", "GT", "LT", "AND", "OR", "NOT", "ADD", "SUBTRACT", "DIVIDE",
  "MULTIPLY", "MODULO", "BITAND", "BITOR", "NEGATION", "XOR", "STR",
  "CHARACTER", "CC", "OC", "CS", "OS", "CF", "OF", "COMMA", "COLON",
  "SCOL", "OUTPUT", "INPUT", "SWITCH", "CASE", "BREAK", "DEFAULT", "IF",
  "ELIF", "ELSE", "WHILE", "FOR", "CONTINUE", "TYPEOF", "ASSIGN",
  "$accept", "Code", "headerfileInclude", "Program", "func_list", "func",
  "$@1", "func_prefix", "$@2", "func_data_type", "param_list", "$@3",
  "param", "stmt_list", "stmt", "declaration", "$@4", "arr_values", "$@5",
  "return_stmt", "data_type", "expr", "postfix_expr", "unary_expr",
  "primary_expr", "unary_op", "const", "assign", "if_stmt", "$@6", "$@7",
  "$@8", "$@9", "elif_stmt", "$@10", "$@11", "$@12", "$@13", "else_stmt",
  "$@14", "switch_stmt", "$@15", "$@16", "$@17", "case_stmt_list",
  "case_stmt", "$@18", "$@19", "default_stmt", "while_loop_stmt", "$@20",
  "$@21", "$@22", "for_loop_stmt", "$@23", "$@24", "$@25", "$@26",
  "func_call", "$@27", "arg_list", "arg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-196)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    19,    39,  -196,    15,  -196,  -196,   164,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,    13,    43,  -196,  -196,  -196,
     178,    46,    63,    66,  -196,  -196,    -3,  -196,  -196,  -196,
    -196,  -196,   182,    49,    56,  -196,    52,  -196,  -196,    60,
      55,    91,    65,   178,  -196,    72,   117,    92,  -196,  -196,
    -196,     3,  -196,    87,  -196,  -196,  -196,  -196,  -196,    42,
     -27,    50,  -196,   499,   182,   182,    95,   384,   115,   124,
     101,  -196,   105,   107,     0,  -196,   113,  -196,  -196,  -196,
      85,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   285,   182,   182,   182,   182,   182,   182,   182,  -196,
    -196,  -196,  -196,   109,   122,   138,  -196,   142,   182,   309,
     499,   182,  -196,   127,   407,    -9,   147,   182,   182,  -196,
     499,   120,  -196,   154,  -196,   182,   609,   609,   604,   604,
     287,   287,   604,   604,   539,   519,     9,    53,    53,  -196,
    -196,  -196,   596,   559,   579,  -196,   133,  -196,   134,   222,
     334,   129,   499,   144,   150,   152,   153,   156,   182,  -196,
     430,   453,  -196,   163,   242,    42,  -196,  -196,  -196,   182,
    -196,   182,  -196,  -196,  -196,   359,   173,  -196,  -196,   182,
      -1,  -196,  -196,   499,  -196,   175,   179,   180,   185,   262,
    -196,  -196,   172,   183,  -196,  -196,  -196,   187,  -196,  -196,
    -196,   183,   178,   178,     0,    17,   193,   196,  -196,   214,
     234,   258,   259,   260,    17,   275,   265,  -196,  -196,  -196,
     277,   291,  -196,   178,  -196,   267,   300,  -196,    17,   307,
    -196,  -196,   292,  -196,  -196,   301,   321,   305,  -196,   178,
     178,   182,  -196,   326,  -196,   476,   178,  -196,  -196,   328,
     329,  -196,  -196,   178,   331,  -196,   267,  -196
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     7,     4,     1,     2,     5,     3,    50,
      53,    51,    52,    13,     6,     0,     0,    12,     8,    10,
      20,     0,     0,     0,    86,    87,    79,    84,    82,    83,
      85,    88,     0,     0,     0,   107,     0,    93,   118,     0,
       0,     0,     0,    20,    21,     0,     0,     0,    74,    72,
      73,     0,    80,     0,    25,    30,    26,    27,    76,    17,
       0,    79,    48,    47,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,    29,     0,     9,    19,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      79,    78,    22,     0,    14,     0,    37,     0,     0,     0,
      89,   131,    81,     0,     0,     0,     0,     0,     0,    92,
      91,     0,    35,     0,    36,     0,    70,    71,    58,    59,
      62,    63,    61,    60,    64,    65,    75,    54,    55,    57,
      56,    66,    67,    68,    69,    11,     0,    18,     0,     0,
       0,    77,   132,     0,   130,     0,     0,     0,     0,   108,
       0,     0,   122,     0,     0,    17,    38,    39,    77,     0,
     128,   131,    34,    33,    31,     0,     0,    94,   119,     0,
       0,    40,    15,    90,   129,     0,     0,     0,     0,     0,
      41,    42,     0,   112,    95,   120,   123,     0,    32,   113,
     109,   112,    20,    20,     0,     0,     0,   117,   111,     0,
       0,     0,     0,    44,     0,     0,     0,    96,   121,   124,
       0,     0,   114,    20,   110,   103,     0,    43,     0,     0,
     116,    98,   106,   125,    45,     0,     0,     0,    97,    20,
      20,     0,   104,     0,   115,     0,    20,   126,    99,     0,
       0,   105,   100,    20,     0,   101,   103,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,   365,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
     218,  -196,  -196,   -41,  -196,   -71,  -196,   165,  -196,  -196,
      -6,   -23,  -196,  -196,   340,  -196,  -195,   -70,  -196,  -196,
    -196,  -196,  -196,   139,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,   195,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
     223,  -196
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     7,    14,    20,    15,    21,    16,
     103,   146,   104,    42,    43,    44,   197,   212,   221,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    72,
     187,   202,   225,   232,   236,   250,   253,   256,   238,   246,
      55,    70,   176,   207,   200,   201,   206,   229,   216,    56,
      73,   188,   203,    57,   179,   204,   226,   239,    58,    66,
     153,   154
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,    17,    78,   119,   121,     9,    10,    11,    22,    67,
     213,    24,    25,    26,    24,    25,   100,   106,     1,   222,
     -82,   -82,   -82,     4,    27,    28,    29,   157,    24,    25,
     158,   107,    30,   213,  -127,    31,    64,    32,    31,     5,
      32,   109,   110,   190,   -82,   114,   -82,     9,    10,    11,
      12,   120,    31,   105,    18,    65,    19,   191,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   137,   138,
     139,   140,   141,   142,   143,   144,    60,    24,    25,    61,
      93,    94,    95,    59,   149,   150,    68,  -127,   152,   108,
      27,    28,    29,    69,   160,   161,    71,    74,    30,    75,
      62,    31,   164,    32,    76,    77,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    79,    91,    92,    93,
      94,    95,    96,    97,   123,    98,    24,    25,    61,   124,
      80,   102,   111,   119,   211,   175,    99,   115,   116,    27,
      28,    29,   117,   125,   118,   145,   183,    30,   152,   113,
      31,   147,    32,    24,    25,    61,   189,   122,   -16,   105,
     159,   209,   210,   155,   162,   163,    27,    28,    29,     9,
      10,    11,    12,    13,    30,   165,   148,    31,   166,    32,
     170,   120,   230,     9,    10,    11,    22,   169,    23,    24,
      25,    26,   171,    24,    25,    61,   172,   173,   243,   244,
     174,   180,    27,    28,    29,   249,    27,    28,    29,   186,
      30,   192,   254,    31,    30,    32,   198,    31,   245,    32,
     193,   194,   -49,    33,    34,    35,   195,    36,   205,    37,
     214,   199,    38,    39,    40,    41,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   215,    91,    92,    93,
      94,    95,    96,    97,   217,    98,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   167,    91,    92,    93,
      94,    95,    96,    97,   218,    98,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   181,    91,    92,    93,
      94,    95,    96,    97,   219,    98,    24,    25,    61,   220,
     -46,    81,    82,    83,    84,   224,   196,    87,    88,    27,
     136,    29,    91,    92,    93,    94,    95,    30,   223,   231,
      31,   227,    32,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   228,    91,    92,    93,    94,    95,    96,
      97,   233,    98,   235,   240,   237,   242,   151,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   241,    91,
      92,    93,    94,    95,    96,    97,   247,    98,   251,     8,
     252,   255,   168,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   182,    91,    92,    93,    94,    95,    96,
      97,   101,    98,   234,   184,   257,   208,   185,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      92,    93,    94,    95,    96,    97,     0,    98,     0,     0,
     112,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,    96,    97,     0,
      98,     0,     0,   156,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
      96,    97,     0,    98,     0,     0,   177,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,    94,    95,    96,    97,     0,    98,     0,     0,   178,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,    96,    97,     0,    98,
       0,     0,   248,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,    96,
      97,     0,    98,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,    91,    92,    93,    94,    95,    96,
      97,     0,    98,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      97,     0,    98,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    91,    92,    93,    94,    95,    96,
       0,     0,    98,    81,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    91,    92,    93,    94,    95,    96,
      81,    82,    83,    84,    85,    86,    87,    88,    81,    82,
       0,    91,    92,    93,    94,    95,     0,     0,     0,    91,
      92,    93,    94,    95,    91,    92,    93,    94,    95
};

static const yytype_int16 yycheck[] =
{
      23,     7,    43,    74,    74,     5,     6,     7,     8,    32,
     205,    11,    12,    13,    11,    12,    13,    44,     3,   214,
      11,    12,    13,     4,    24,    25,    26,    36,    11,    12,
      39,    58,    32,   228,    37,    35,    39,    37,    35,     0,
      37,    64,    65,    44,    35,    68,    37,     5,     6,     7,
       8,    74,    35,    59,    41,    58,    13,    58,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    13,    11,    12,    13,
      27,    28,    29,    37,   107,   108,    37,    37,   111,    39,
      24,    25,    26,    37,   117,   118,    44,    37,    32,    44,
      34,    35,   125,    37,    13,    40,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    44,    25,    26,    27,
      28,    29,    30,    31,    39,    33,    11,    12,    13,    44,
      13,    44,    37,   204,   204,   158,    44,    13,    37,    24,
      25,    26,    37,    58,    37,    36,   169,    32,   171,    34,
      35,    13,    37,    11,    12,    13,   179,    44,    36,   165,
      13,   202,   203,    36,    44,    11,    24,    25,    26,     5,
       6,     7,     8,     9,    32,    42,    34,    35,    44,    37,
      36,   204,   223,     5,     6,     7,     8,    58,    10,    11,
      12,    13,    42,    11,    12,    13,    44,    44,   239,   240,
      44,    38,    24,    25,    26,   246,    24,    25,    26,    36,
      32,    36,   253,    35,    32,    37,    44,    35,   241,    37,
      41,    41,    44,    45,    46,    47,    41,    49,    41,    51,
      37,    48,    54,    55,    56,    57,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    50,    25,    26,    27,
      28,    29,    30,    31,    40,    33,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    44,    25,    26,    27,
      28,    29,    30,    31,    40,    33,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    44,    25,    26,    27,
      28,    29,    30,    31,    36,    33,    11,    12,    13,    40,
      40,    14,    15,    16,    17,    40,    44,    20,    21,    24,
      25,    26,    25,    26,    27,    28,    29,    32,    43,    52,
      35,    44,    37,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    42,    25,    26,    27,    28,    29,    30,
      31,    41,    33,    36,    43,    53,    41,    38,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    37,    25,
      26,    27,    28,    29,    30,    31,    40,    33,    40,     4,
      41,    40,    38,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   165,    25,    26,    27,    28,    29,    30,
      31,    51,    33,   228,   171,   256,   201,    38,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      36,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    36,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    36,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    36,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    36,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    33,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      14,    15,    16,    17,    18,    19,    20,    21,    14,    15,
      -1,    25,    26,    27,    28,    29,    -1,    -1,    -1,    25,
      26,    27,    28,    29,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    60,    61,     4,     0,    62,    63,    61,     5,
       6,     7,     8,     9,    64,    66,    68,    79,    41,    13,
      65,    67,     8,    10,    11,    12,    13,    24,    25,    26,
      32,    35,    37,    45,    46,    47,    49,    51,    54,    55,
      56,    57,    72,    73,    74,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    99,   108,   112,   117,    37,
      13,    13,    34,    80,    39,    58,   118,    80,    37,    37,
     100,    44,    88,   109,    37,    44,    13,    40,    72,    44,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    25,    26,    27,    28,    29,    30,    31,    33,    44,
      13,    83,    44,    69,    71,    79,    44,    58,    39,    80,
      80,    37,    36,    34,    80,    13,    37,    37,    37,    74,
      80,    86,    44,    39,    44,    58,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    25,    80,    80,    80,
      80,    80,    80,    80,    80,    36,    70,    13,    34,    80,
      80,    38,    80,   119,   120,    36,    36,    36,    39,    13,
      80,    80,    44,    11,    80,    42,    44,    44,    38,    58,
      36,    42,    44,    44,    44,    80,   101,    36,    36,   113,
      38,    44,    69,    80,   119,    38,    36,    89,   110,    80,
      44,    58,    36,    41,    41,    41,    44,    75,    44,    48,
     103,   104,    90,   111,   114,    41,   105,   102,   103,    72,
      72,    86,    76,    85,    37,    50,   107,    40,    40,    36,
      40,    77,    85,    43,    40,    91,   115,    44,    42,   106,
      72,    52,    92,    41,    76,    36,    93,    53,    97,   116,
      43,    37,    41,    72,    72,    80,    98,    40,    36,    72,
      94,    40,    41,    95,    72,    40,    96,    92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    63,    63,    65,    64,
      67,    66,    68,    68,    70,    69,    69,    69,    71,    72,
      72,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    74,
      74,    74,    75,    74,    77,    76,    76,    78,    78,    78,
      79,    79,    79,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    83,
      83,    83,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    88,    89,    90,    91,    87,    93,    94,
      95,    96,    92,    92,    98,    97,    97,   100,   101,   102,
      99,   103,   103,   105,   106,   104,   107,   107,   109,   110,
     111,   108,   113,   114,   115,   116,   112,   118,   117,   119,
     119,   119,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     2,     0,     0,     5,
       0,     6,     1,     1,     0,     4,     1,     0,     2,     2,
       0,     1,     2,     2,     2,     1,     1,     1,     2,     2,
       1,     5,     8,     5,     5,     3,     3,     3,     5,     5,
       5,     6,     0,    11,     0,     4,     1,     2,     2,     0,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     4,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       6,     1,     1,     0,     0,     0,     0,    13,     0,     0,
       0,     0,    12,     0,     0,     5,     0,     0,     0,     0,
      11,     2,     0,     0,     0,     8,     3,     0,     0,     0,
       0,    10,     0,     0,     0,     0,    15,     0,     5,     3,
       1,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 6: /* func_list: func_list func  */
#line 145 "parser.y"
                                   {
    //printf("Hello");
}
#line 1718 "y.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 152 "parser.y"
                    {
                        has_return_stmt = 0;
                        scope_history.push(++scope_counter);
                    }
#line 1727 "y.tab.c"
    break;

  case 9: /* func: func_prefix OF $@1 stmt_list CF  */
#line 156 "parser.y"
                    {
                        if(func_table[curr_func_name].return_type != "void" && curr_func_name!="main" && has_return_stmt == 0){
                            sem_errors.push_back("Return stmt not there for function: " + curr_func_name);
                        }
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("end:\n");
                        has_return_stmt = 0;
                    }
#line 1741 "y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 167 "parser.y"
                    {   
                        if(func_table.find(string((yyvsp[0].node).lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string((yyvsp[0].node).lexeme));
                        }
                        tac.push_back(string((yyvsp[0].node).lexeme) + ": " + string((yyvsp[-1].node).type)); 
                        curr_func_name = string((yyvsp[0].node).lexeme);
                        func_table[curr_func_name]=func_table["global"];
                        
                    }
#line 1755 "y.tab.c"
    break;

  case 11: /* func_prefix: func_data_type ID $@2 OC param_list CC  */
#line 176 "parser.y"
                                     {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1764 "y.tab.c"
    break;

  case 12: /* func_data_type: data_type  */
#line 181 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        //printf("%s",string( $1.type));
                    }
#line 1773 "y.tab.c"
    break;

  case 13: /* func_data_type: VOID  */
#line 185 "parser.y"
                           {
                        sprintf((yyval.node).type, "void");
                        //printf("void");
                    }
#line 1782 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 191 "parser.y"
                          {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1792 "y.tab.c"
    break;

  case 15: /* param_list: param $@3 COMMA param_list  */
#line 196 "parser.y"
                                     {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                        if((yyval.node).nParams>20) sem_errors.push_back("No. of parameters exceeded for " + curr_func_name);
                    }
#line 1801 "y.tab.c"
    break;

  case 16: /* param_list: param  */
#line 200 "parser.y"
                            {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1812 "y.tab.c"
    break;

  case 17: /* param_list: %empty  */
#line 206 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1820 "y.tab.c"
    break;

  case 18: /* param: data_type ID  */
#line 211 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);                    }
#line 1829 "y.tab.c"
    break;

  case 28: /* stmt: BREAK SCOL  */
#line 228 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1839 "y.tab.c"
    break;

  case 29: /* stmt: CONTINUE SCOL  */
#line 233 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1849 "y.tab.c"
    break;

  case 31: /* stmt: INPUT OC ID CC SCOL  */
#line 239 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                        // check_scope(string($3.lexeme));
                    }
#line 1859 "y.tab.c"
    break;

  case 32: /* stmt: INPUT OC ID OS expr CS CC SCOL  */
#line 244 "parser.y"
                                                     {
                        check_declaration((yyvsp[-5].node).lexeme);
                        string temp = get_temp();
                        tac.push_back("input " + temp + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] = " + temp + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                        free_temp.push(temp);
                        // check_scope(string($3.lexeme));
                    }
#line 1872 "y.tab.c"
    break;

  case 33: /* stmt: OUTPUT OC expr CC SCOL  */
#line 252 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1880 "y.tab.c"
    break;

  case 34: /* stmt: OUTPUT OC STR CC SCOL  */
#line 255 "parser.y"
                                            {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " STRING");
                    }
#line 1888 "y.tab.c"
    break;

  case 35: /* stmt: TYPEOF ID SCOL  */
#line 258 "parser.y"
                                     {
                        char dtype[256]; // Choose an appropriate size for the array
                        strcpy(dtype, func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)].data_type.c_str());

                        // Print both the name of ID and its type
                        printf("Variable %s has type %s\n", (yyvsp[-1].node).lexeme, dtype);
                    }
#line 1900 "y.tab.c"
    break;

  case 36: /* declaration: data_type ID SCOL  */
#line 269 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        // if(multiple_declaration(string($2.lexeme))){
                        //     check_scope(string($2.lexeme));
                        // };
                        if(string((yyvsp[-2].node).lexeme)!="int")sem_errors.push_back(string((yyvsp[-2].node).lexeme)+" "+string((yyvsp[-1].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1914 "y.tab.c"
    break;

  case 37: /* declaration: STRING ID SCOL  */
#line 278 "parser.y"
                                     { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        // if(multiple_declaration(string($2.lexeme))){
                        //     check_scope(string($2.lexeme));
                        // };
                        //if(string($1.lexeme)!="int")sem_errors.push_back(string($1.lexeme)+" "+string($2.lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { "STRING", scope_counter, 0, 0, countn+1 };
                    }
#line 1928 "y.tab.c"
    break;

  case 38: /* declaration: STRING ID ASSIGN STR SCOL  */
#line 287 "parser.y"
                                                {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- STRING " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " STRING");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { "STRING", scope_counter, string((yyvsp[-1].node).lexeme).length(), 0, countn+1 };
                    }
#line 1940 "y.tab.c"
    break;

  case 39: /* declaration: STRING ID ASSIGN expr SCOL  */
#line 294 "parser.y"
                                                 {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + "STRING");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 1955 "y.tab.c"
    break;

  case 40: /* declaration: data_type ID ASSIGN expr SCOL  */
#line 304 "parser.y"
                                                    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 1970 "y.tab.c"
    break;

  case 41: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 314 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1981 "y.tab.c"
    break;

  case 42: /* $@4: %empty  */
#line 320 "parser.y"
                                                        {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 1993 "y.tab.c"
    break;

  case 44: /* $@5: %empty  */
#line 329 "parser.y"
                          {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                    }
#line 2005 "y.tab.c"
    break;

  case 46: /* arr_values: const  */
#line 337 "parser.y"
                            {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                        arr_index=0;
                    }
#line 2018 "y.tab.c"
    break;

  case 47: /* return_stmt: RETURN expr  */
#line 347 "parser.y"
                                {
                        //sem_errors.push_back($2.type);
                        check_type(func_table[curr_func_name].return_type, string((yyvsp[0].node).type));
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                        has_return_stmt = 1;

                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2031 "y.tab.c"
    break;

  case 48: /* return_stmt: RETURN STR  */
#line 356 "parser.y"
                               {
                        has_return_stmt = 1;
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2041 "y.tab.c"
    break;

  case 50: /* data_type: INT  */
#line 364 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 2049 "y.tab.c"
    break;

  case 51: /* data_type: FLOAT  */
#line 367 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 2057 "y.tab.c"
    break;

  case 52: /* data_type: STRING  */
#line 370 "parser.y"
                            {
                        strcpy((yyval.node).type, "STRING");
                    }
#line 2065 "y.tab.c"
    break;

  case 53: /* data_type: CHAR  */
#line 373 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 2073 "y.tab.c"
    break;

  case 54: /* expr: expr ADD expr  */
#line 381 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2084 "y.tab.c"
    break;

  case 55: /* expr: expr SUBTRACT expr  */
#line 387 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2095 "y.tab.c"
    break;

  case 56: /* expr: expr MULTIPLY expr  */
#line 393 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0=get_temp();
                        string t1=get_temp();
                        string t2=get_temp();
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = 0 " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " < " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + b +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " + " + t2 +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");

                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2130 "y.tab.c"
    break;

  case 57: /* expr: expr DIVIDE expr  */
#line 423 "parser.y"
                                       {
                       //if(atoi($3.lexeme)==0)  sem_errors.push_back("Line no " + to_string(countn+1) +" : " +" Divide by zero error"); 
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0=get_temp();
                        string t1=get_temp();
                        string t2=get_temp();
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = " + b + " " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " >= " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + t2 +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " - " + c +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2165 "y.tab.c"
    break;

  case 58: /* expr: expr LE expr  */
#line 453 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2176 "y.tab.c"
    break;

  case 59: /* expr: expr GE expr  */
#line 459 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2187 "y.tab.c"
    break;

  case 60: /* expr: expr LT expr  */
#line 465 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2198 "y.tab.c"
    break;

  case 61: /* expr: expr GT expr  */
#line 471 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2209 "y.tab.c"
    break;

  case 62: /* expr: expr EQ expr  */
#line 477 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2220 "y.tab.c"
    break;

  case 63: /* expr: expr NE expr  */
#line 483 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = get_temp();
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " == " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 

                        free_temp.push(temp);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2235 "y.tab.c"
    break;

  case 64: /* expr: expr AND expr  */
#line 493 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);
                        string l3 = "#L" + to_string(++label_counter);
                        string dtype = string((yyval.node).type);

                        tac.push_back("if " + string((yyvsp[-2].node).lexeme) + " GOTO " + l3 + " else GOTO " + l1);
                        tac.push_back(l3 + ":");
                        tac.push_back("if " + string((yyvsp[0].node).lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 1 " + dtype);
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 0 " + dtype);
                        tac.push_back(l2 + ":");

                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2263 "y.tab.c"
    break;

  case 65: /* expr: expr OR expr  */
#line 516 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);
                        string l3 = "#L" + to_string(++label_counter);
                        string dtype = string((yyval.node).type);

                        tac.push_back("if " + string((yyvsp[-2].node).lexeme) + " GOTO " + l0 + " else GOTO " + l3);
                        tac.push_back(l3 + ":");
                        tac.push_back("if " + string((yyvsp[0].node).lexeme) + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 1 " + dtype);
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");
                        tac.push_back(string((yyval.node).lexeme) + " = 0 " + dtype);
                        tac.push_back(l2 + ":");

                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2291 "y.tab.c"
    break;

  case 66: /* expr: expr MODULO expr  */
#line 539 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string t0=get_temp();
                        string t1=get_temp();
                        string t2=get_temp();
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = string((yyvsp[0].node).lexeme);
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = " + b + " " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " >= " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t0 + " = " + t0 + " - " + c +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + t0 +  "  " + dtype);

                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2326 "y.tab.c"
    break;

  case 67: /* expr: expr BITAND expr  */
#line 569 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2337 "y.tab.c"
    break;

  case 68: /* expr: expr BITOR expr  */
#line 575 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2348 "y.tab.c"
    break;

  case 69: /* expr: expr XOR expr  */
#line 581 "parser.y"
                                    {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string b_= get_temp();
                        string c = string((yyvsp[0].node).lexeme);
                        string c_= get_temp();

                        tac.push_back(b_ + " = ~ " + b + " " + string((yyvsp[-2].node).type));
                        tac.push_back(c_ + " = ~ " + c + " " + string((yyvsp[0].node).type));
                        string t1=get_temp();
                        string t2=get_temp();
                        tac.push_back(t1 + " = " + b + " & " + c_ + " " + string((yyval.node).type));
                        tac.push_back(t2 + " = " + b_ + " & " + c + " " + string((yyval.node).type));
                        tac.push_back(a + " = " + t1 + " | " + t2 + " " + string((yyval.node).type));

                        free_temp.push(b_);
                        free_temp.push(c_);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2376 "y.tab.c"
    break;

  case 70: /* expr: expr LEFTSHIFT expr  */
#line 604 "parser.y"
                                          {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string d = string((yyvsp[0].node).lexeme);
                        string t3 = get_temp();
                        string t4 = get_temp();
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);

                        string t0= get_temp();
                        string t1= get_temp();
                        string t2= get_temp();
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = get_temp();
                        tac.push_back(c + " = 2 INT");
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(t3 + " = 0 INT");
                        tac.push_back(l2 + ":");
                        tac.push_back(t4 + " = " + t3 + " < " + d + " INT");
                        tac.push_back("\nif " + t4 + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = 0 " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " < " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + b +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " + " + t2 +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");

                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                        free_temp.push(t3);
                        free_temp.push(t4);
                        free_temp.push(c);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2429 "y.tab.c"
    break;

  case 71: /* expr: expr RIGHTSHIFT expr  */
#line 652 "parser.y"
                                           {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string d = string((yyvsp[0].node).lexeme);
                        string t3 = get_temp();
                        string t4 = get_temp();
                        string l0 = "#L" + to_string(++label_counter);
                        string l1 = "#L" + to_string(++label_counter);
                        string l2 = "#L" + to_string(++label_counter);

                        string t0=get_temp();
                        string t1=get_temp();
                        string t2=get_temp();
                        string a = string((yyval.node).lexeme);
                        string b = string((yyvsp[-2].node).lexeme);
                        string c = get_temp();
                        tac.push_back(c + " = 2 INT");
                        string dtype = string((yyval.node).type);
                        
                        tac.push_back(t3 + " = 0 INT");
                        tac.push_back(l2 + ":");
                        tac.push_back(t4 + " = " + t3 + " < " + d + " INT");
                        tac.push_back("\nif " + t4 + " GOTO " + l0 + " else GOTO " + l1);
                        tac.push_back(l0 + ":");
                        tac.push_back(a + " = 0 " + dtype);
                        tac.push_back(t0 + " = " + b + " " + dtype);
                        tac.push_back(t2 + " = 1 " + dtype);
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(t1 + " = " + t0 + " >= " + c +  "  " + dtype);
                        tac.push_back("if " + t1 + " GOTO " + "#L" + to_string(label_counter+1) + " else GOTO " + "#L" + to_string(label_counter+2));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back(a + " = " + a + " + " + t2 +  "  " + dtype);
                        tac.push_back(t0 + " = " + t0 + " - " + c +  "  " + dtype);
                        tac.push_back("GOTO #L" + to_string(label_counter-1));
                        tac.push_back("#L" + to_string(++label_counter) + ":");
                        tac.push_back("GOTO " + l2);
                        tac.push_back(l1 + ":");

                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                        free_temp.push(t3);
                        free_temp.push(t4);
                        free_temp.push(c);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));

                        label_counter++;
                    }
#line 2482 "y.tab.c"
    break;

  case 72: /* expr: unary_expr  */
#line 700 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2492 "y.tab.c"
    break;

  case 73: /* expr: primary_expr  */
#line 705 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2502 "y.tab.c"
    break;

  case 74: /* expr: postfix_expr  */
#line 710 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2511 "y.tab.c"
    break;

  case 75: /* expr: expr ADD ADD  */
#line 714 "parser.y"
                                  {
                        // add_tac($$, $1, $2, $3)
                        string t0=get_temp();
                        string t1=get_temp();
                        string t2=get_temp();
                        string a = string((yyvsp[-2].node).lexeme);
                        tac.push_back(t1 + " = 1 "+ string((yyval.node).type));
                        tac.push_back(t2 + " = "+a+ " + " + t1+ " " +string((yyval.node).type));
                        tac.push_back(a+" = "+t2+ " " +string((yyval.node).type));
                        // tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($2.lexeme) + " " + "1" + " " + string($$.type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        free_temp.push(t0);
                        free_temp.push(t1);
                        free_temp.push(t2);
                    }
#line 2531 "y.tab.c"
    break;

  case 76: /* postfix_expr: func_call  */
#line 731 "parser.y"
                              {
                        //sem_errors.push_back("Hi");
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2541 "y.tab.c"
    break;

  case 77: /* postfix_expr: ID OS expr CS  */
#line 737 "parser.y"
                                  {
                        bool isString =0;
                        string dtype = func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].data_type;
                        if(dtype=="STRING"|| dtype=="STRING") isString=1;
                        if(check_declaration(string((yyvsp[-3].node).lexeme)) && !isString && func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) +" : " +string((yyvsp[-3].node).lexeme)+ " Variable is not an array from expr" + dtype ); 
                        }
                        check_scope(string((yyvsp[-3].node).lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)].data_type.c_str());
                        sprintf((yyval.node).lexeme, get_temp().c_str());
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-3].node).lexeme) + " [ " + string((yyvsp[-1].node).lexeme) + " ] " + string((yyval.node).type));
                        
                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2560 "y.tab.c"
    break;

  case 78: /* unary_expr: unary_op primary_expr  */
#line 753 "parser.y"
                                          {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, get_temp().c_str());
                        if(string((yyvsp[-1].node).lexeme) == "~" || string((yyvsp[-1].node).lexeme) == "-"){
                            tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        }
                        else if(string((yyvsp[-1].node).lexeme) == "+"){
                            tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        }
                        else{
                            tac.push_back(string((yyval.node).lexeme) + " = ~ " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        }

                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2580 "y.tab.c"
    break;

  case 79: /* primary_expr: ID  */
#line 770 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        // check_scope(string($1.lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2591 "y.tab.c"
    break;

  case 80: /* primary_expr: const  */
#line 776 "parser.y"
                            {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);

                        string t=get_temp();
                        sprintf((yyval.node).lexeme, t.c_str());
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type)); 
                        temp_map[string((yyvsp[0].node).lexeme)] = string((yyval.node).lexeme);

                        const_temps.insert(t);
                        // if(temp_map[string($1.lexeme)] == ""){
                        //     string t=get_temp();
                        //     sprintf($$.lexeme, t.c_str());
                        //     tac.push_back(string($$.lexeme) + " = " + string($1.lexeme) + " " + string($$.type)); 
                        //     temp_map[string($1.lexeme)] = string($$.lexeme);

                        //     const_temps.insert(t);
                        // }
                        // else{
                        //     //tac.push_back(temp_map[string($1.lexeme)] + " = " + string($1.lexeme) + " " + string($$.type)); 
                        //     strcpy($$.lexeme, temp_map[string($1.lexeme)].c_str());
                        // }
                    }
#line 2618 "y.tab.c"
    break;

  case 81: /* primary_expr: OC expr CC  */
#line 798 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2627 "y.tab.c"
    break;

  case 86: /* const: INT_NUM  */
#line 810 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2636 "y.tab.c"
    break;

  case 87: /* const: FLOAT_NUM  */
#line 814 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2645 "y.tab.c"
    break;

  case 88: /* const: CHARACTER  */
#line 818 "parser.y"
                                {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2654 "y.tab.c"
    break;

  case 89: /* assign: ID ASSIGN expr  */
#line 824 "parser.y"
                                   {
                        // printf($1.lexeme);
                        // printf($3.lexeme);
                        bool k= check_declaration(string((yyvsp[-2].node).lexeme));
                        if(k) {
                        if(func_table[curr_func_name].symbol_table.find(string((yyvsp[-2].node).lexeme))!=func_table[curr_func_name].symbol_table.end()){
                            char dtype[256]; // Choose an appropriate size for the array

                        // Then copy the C-string into the array
                        strcpy(dtype, func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type.c_str());

                            // printf(dtype);
                            // printf(string($3.type).c_str());
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        check_scope(string((yyvsp[-2].node).lexeme));
                        tac.push_back(string((yyvsp[-2].node).lexeme) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);

                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                        }
                        }
                        
                    }
#line 2681 "y.tab.c"
    break;

  case 90: /* assign: ID OS expr CS ASSIGN expr  */
#line 847 "parser.y"
                                              {
                        check_type(func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type, string((yyvsp[0].node).type));
                        bool isString =0;
                        string dtype = func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type;
                        if(dtype=="STRING"|| dtype=="STRING") isString=1;
                        if(check_declaration(string((yyvsp[-5].node).lexeme)) && !isString && func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].isArray == 0) { 
                            sem_errors.push_back("Line no " + to_string(countn+1) +" : " +string((yyvsp[-5].node).lexeme)+ " Variable is not an array from assign expr" + dtype); 
                        }
                        check_scope(string((yyvsp[-5].node).lexeme));
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);

                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2699 "y.tab.c"
    break;

  case 93: /* $@6: %empty  */
#line 865 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2707 "y.tab.c"
    break;

  case 94: /* $@7: %empty  */
#line 868 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2720 "y.tab.c"
    break;

  case 95: /* $@8: %empty  */
#line 877 "parser.y"
                    {
                      scope_history.push(++scope_counter);  
                    }
#line 2728 "y.tab.c"
    break;

  case 96: /* $@9: %empty  */
#line 879 "parser.y"
                                   {  
                        scope_history.pop(); 
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2739 "y.tab.c"
    break;

  case 97: /* if_stmt: IF $@6 OC expr CC $@7 OF $@8 stmt_list CF $@9 elif_stmt else_stmt  */
#line 885 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-12].node).parentNext) + ":");
                    }
#line 2747 "y.tab.c"
    break;

  case 98: /* $@10: %empty  */
#line 890 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2757 "y.tab.c"
    break;

  case 99: /* $@11: %empty  */
#line 895 "parser.y"
                               {
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2770 "y.tab.c"
    break;

  case 100: /* $@12: %empty  */
#line 904 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2778 "y.tab.c"
    break;

  case 101: /* $@13: %empty  */
#line 907 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2789 "y.tab.c"
    break;

  case 104: /* $@14: %empty  */
#line 917 "parser.y"
                            {scope_history.push(++scope_counter);}
#line 2795 "y.tab.c"
    break;

  case 105: /* else_stmt: ELSE OF $@14 stmt_list CF  */
#line 917 "parser.y"
                                                                               {scope_history.pop(); --scope_counter;}
#line 2801 "y.tab.c"
    break;

  case 107: /* $@15: %empty  */
#line 921 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2811 "y.tab.c"
    break;

  case 108: /* $@16: %empty  */
#line 926 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type);
                    }
#line 2820 "y.tab.c"
    break;

  case 109: /* $@17: %empty  */
#line 930 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2829 "y.tab.c"
    break;

  case 110: /* switch_stmt: SWITCH $@15 OC ID $@16 CC OF case_stmt_list $@17 default_stmt CF  */
#line 934 "parser.y"
                                    {
                        tac.push_back(string((yyvsp[-10].node).parentNext) + ":");
                        loop_break.pop();
                    }
#line 2838 "y.tab.c"
    break;

  case 111: /* case_stmt_list: case_stmt case_stmt_list  */
#line 940 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2847 "y.tab.c"
    break;

  case 113: /* $@18: %empty  */
#line 947 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2855 "y.tab.c"
    break;

  case 114: /* $@19: %empty  */
#line 950 "parser.y"
                             {
                        char* hold = const_cast<char*>(to_string(variable_count).c_str());
                        sprintf((yyvsp[0].node).temp, "%s", hold);
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                        tac.push_back("@t" + to_string(variable_count++) + " = " + "@t" + to_string(temp_index) + " == " + "@t" + string((yyvsp[0].node).temp) + " INT");
                        tac.push_back("if @t" + to_string(variable_count-1) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        tac.push_back("#L" + to_string(label_counter) + ":");
                        sprintf((yyvsp[0].node).case_body, "#L%d", label_counter++);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2870 "y.tab.c"
    break;

  case 115: /* case_stmt: CASE $@18 OC const $@19 CC COLON stmt_list  */
#line 960 "parser.y"
                                       {
                        tac.push_back(string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2878 "y.tab.c"
    break;

  case 118: /* $@20: %empty  */
#line 968 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2888 "y.tab.c"
    break;

  case 119: /* $@21: %empty  */
#line 974 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                        
                    }
#line 2905 "y.tab.c"
    break;

  case 120: /* $@22: %empty  */
#line 986 "parser.y"
                      {
                        scope_history.push(++scope_counter);
                    }
#line 2913 "y.tab.c"
    break;

  case 121: /* while_loop_stmt: WHILE $@20 OC expr CC $@21 OF $@22 stmt_list CF  */
#line 989 "parser.y"
                    {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-6].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2926 "y.tab.c"
    break;

  case 122: /* $@23: %empty  */
#line 998 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2935 "y.tab.c"
    break;

  case 123: /* $@24: %empty  */
#line 1002 "parser.y"
                              {  
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));

                        sprintf((yyvsp[-1].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[-1].node).loop_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2954 "y.tab.c"
    break;

  case 124: /* $@25: %empty  */
#line 1016 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2963 "y.tab.c"
    break;

  case 125: /* $@26: %empty  */
#line 1021 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2971 "y.tab.c"
    break;

  case 126: /* for_loop_stmt: FOR OC assign SCOL $@23 expr SCOL $@24 assign CC $@25 OF $@26 stmt_list CF  */
#line 1024 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-9].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2984 "y.tab.c"
    break;

  case 127: /* $@27: %empty  */
#line 1033 "parser.y"
                       {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                    }
#line 2992 "y.tab.c"
    break;

  case 128: /* func_call: ID $@27 OC arg_list CC  */
#line 1036 "parser.y"
                                    {
                        // char dtype[256]; // Choose an appropriate size for the array

                        // // Then copy the C-string into the array
                        // strcpy(dtype, func_table[curr_func_name].symbol_table[string($1.lexeme)].data_type.c_str());
                        // char debugInfo[] = "from func call";

                        // // Use sprintf to format and print the combined string
                        // char result[256]; // Choose a size that can hold the combined string
                        // sprintf(result, "%s %s\n", dtype, debugInfo);
                        // printf("%s", result);
                        strcpy((yyval.node).type, func_table[string((yyvsp[-4].node).lexeme)].return_type.c_str());
                        func_call_id.pop();
                        sprintf((yyval.node).lexeme, get_temp().c_str());

                        tac.push_back(string((yyval.node).lexeme) + " = @call " + string((yyvsp[-4].node).lexeme) + " " + func_table[string((yyvsp[-4].node).lexeme)].return_type + " " + to_string(func_table[string((yyvsp[-4].node).lexeme)].num_params));
                    }
#line 3014 "y.tab.c"
    break;

  case 129: /* arg_list: arg COMMA arg_list  */
#line 1055 "parser.y"
                                       {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[-2].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3027 "y.tab.c"
    break;

  case 130: /* arg_list: arg  */
#line 1063 "parser.y"
                          {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[0].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3040 "y.tab.c"
    break;

  case 132: /* arg: expr  */
#line 1074 "parser.y"
                         {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 3048 "y.tab.c"
    break;


#line 3052 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1079 "parser.y"


int main(int argc, char *argv[]) {
    /* yydebug = 1; */
    yyparse();
    for(auto item: sem_errors){
        cout << item << endl;
    }
    if(sem_errors.size() > 0)
        exit(0);
    for(auto x: tac)
        cout << x << endl;
    
}

bool check_declaration(string variable){
    bool a = func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end();
    bool b = func_table["global"].symbol_table.find(variable) == func_table["global"].symbol_table.end();
    if(a&&b){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

bool check_scope(string variable){
    bool a = func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end();
    bool b = func_table["global"].symbol_table.find(variable) == func_table["global"].symbol_table.end();
    if(a&&b){
        sem_errors.push_back("Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    if(curr_func_name=="global") return 1;
    int var_scope = func_table[curr_func_name].symbol_table[variable].scope;
    // int curr_scope = scope_counter;
    stack<int> temp_stack(scope_history);
    // cout << "variable: " << variable << endl;
    // cout << "var_scope: " << var_scope << endl;
    //PrintStack(temp_stack);
    //printf("\n");
    // cout << endl;
    while(!temp_stack.empty()){
        if(temp_stack.top() == var_scope){
            return true;
        }
        temp_stack.pop();
    }
    sem_errors.push_back("Scope of variable '" + variable +"' not matching in line " + to_string(countn+1) + ".");
    return true;
}

bool multiple_declaration(string variable){
    if((func_table[curr_func_name].symbol_table.find(variable) != func_table[curr_func_name].symbol_table.end())){
        sem_errors.push_back("redeclaration of '" + variable + "' in line " + to_string(countn+1));
        return true;
    }
    return false;
}

bool check_type(string l, string r){
    if(r == "FLOAT" && l == "CHAR"){
        sem_errors.push_back("Cannot convert type FLOAT to CHAR in line " + to_string(countn+1));
        return false;
    }
    if(l == "FLOAT" && r == "CHAR"){
        sem_errors.push_back("Cannot convert typr CHAR to FLOAT in line " + to_string(countn+1));
        return false;
    }
    return true;
}

bool is_reserved_word(string id){
    for(auto &item: id){
        item = tolower(item);
    }
    auto iterator = find(reserved.begin(), reserved.end(), id);
    if(iterator != reserved.end()){
        sem_errors.push_back("Reserved keyword used: '" + id + "' in line " + to_string(countn+1));
        return true;
    }
    return false;
}

bool type_check(string type1, string type2) {
    if((type1 == "FLOAT" and type2 == "CHAR") or (type1 == "CHAR" and type2 == "FLOAT")) {
        return true;
    }
    return false;
}

void yyerror(const char* msg) {
    sem_errors.push_back("syntax error in line " + to_string(countn+1));
    for(auto item: sem_errors)
        cout << item << endl;
    // fprintf(stderr, "%s\n", msg);
    cout << msg << endl;  // Print the actual error message

    exit(1);
}

string get_temp(){
    if(free_temp.empty()){
        return "@t" + to_string(variable_count++);
    }
    string t=free_temp.front();
    free_temp.pop(); 
    return t; 
}
void PrintStack(stack<int> s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    cout << x << ' ';
    PrintStack(s);
    s.push(x);
}


// check if void functions has return type
// deal with scope for function arguments
// deal with scope for arrays
// scope in switch statement

//Write documentation for the above code
//Write documentation for the above code
//The above code takes lexemes from the lexer and parses it to check for syntax errors and semantic errors
//

