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
            strcpy($$.type, "STRING");\
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

    vector<string> reserved = {"int", "float", "char", "bool","string", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "progin", "progout"};


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
    BOOL = 264,                    /* BOOL  */
    VOID = 265,                    /* VOID  */
    RETURN = 266,                  /* RETURN  */
    INT_NUM = 267,                 /* INT_NUM  */
    FLOAT_NUM = 268,               /* FLOAT_NUM  */
    ID = 269,                      /* ID  */
    LEFTSHIFT = 270,               /* LEFTSHIFT  */
    RIGHTSHIFT = 271,              /* RIGHTSHIFT  */
    LE = 272,                      /* LE  */
    GE = 273,                      /* GE  */
    EQ = 274,                      /* EQ  */
    NE = 275,                      /* NE  */
    GT = 276,                      /* GT  */
    LT = 277,                      /* LT  */
    AND = 278,                     /* AND  */
    OR = 279,                      /* OR  */
    NOT = 280,                     /* NOT  */
    ADD = 281,                     /* ADD  */
    SUBTRACT = 282,                /* SUBTRACT  */
    DIVIDE = 283,                  /* DIVIDE  */
    MULTIPLY = 284,                /* MULTIPLY  */
    MODULO = 285,                  /* MODULO  */
    BITAND = 286,                  /* BITAND  */
    BITOR = 287,                   /* BITOR  */
    NEGATION = 288,                /* NEGATION  */
    XOR = 289,                     /* XOR  */
    STR = 290,                     /* STR  */
    CHARACTER = 291,               /* CHARACTER  */
    CC = 292,                      /* CC  */
    OC = 293,                      /* OC  */
    CS = 294,                      /* CS  */
    OS = 295,                      /* OS  */
    CF = 296,                      /* CF  */
    OF = 297,                      /* OF  */
    COMMA = 298,                   /* COMMA  */
    COLON = 299,                   /* COLON  */
    SCOL = 300,                    /* SCOL  */
    OUTPUT = 301,                  /* OUTPUT  */
    INPUT = 302,                   /* INPUT  */
    SWITCH = 303,                  /* SWITCH  */
    CASE = 304,                    /* CASE  */
    BREAK = 305,                   /* BREAK  */
    DEFAULT = 306,                 /* DEFAULT  */
    IF = 307,                      /* IF  */
    ELIF = 308,                    /* ELIF  */
    ELSE = 309,                    /* ELSE  */
    WHILE = 310,                   /* WHILE  */
    FOR = 311,                     /* FOR  */
    CONTINUE = 312,                /* CONTINUE  */
    TYPEOF = 313,                  /* TYPEOF  */
    ASSIGN = 314                   /* ASSIGN  */
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
#define BOOL 264
#define VOID 265
#define RETURN 266
#define INT_NUM 267
#define FLOAT_NUM 268
#define ID 269
#define LEFTSHIFT 270
#define RIGHTSHIFT 271
#define LE 272
#define GE 273
#define EQ 274
#define NE 275
#define GT 276
#define LT 277
#define AND 278
#define OR 279
#define NOT 280
#define ADD 281
#define SUBTRACT 282
#define DIVIDE 283
#define MULTIPLY 284
#define MODULO 285
#define BITAND 286
#define BITOR 287
#define NEGATION 288
#define XOR 289
#define STR 290
#define CHARACTER 291
#define CC 292
#define OC 293
#define CS 294
#define OS 295
#define CF 296
#define OF 297
#define COMMA 298
#define COLON 299
#define SCOL 300
#define OUTPUT 301
#define INPUT 302
#define SWITCH 303
#define CASE 304
#define BREAK 305
#define DEFAULT 306
#define IF 307
#define ELIF 308
#define ELSE 309
#define WHILE 310
#define FOR 311
#define CONTINUE 312
#define TYPEOF 313
#define ASSIGN 314

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

#line 359 "y.tab.c"

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
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_INT_NUM = 12,                   /* INT_NUM  */
  YYSYMBOL_FLOAT_NUM = 13,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_LEFTSHIFT = 15,                 /* LEFTSHIFT  */
  YYSYMBOL_RIGHTSHIFT = 16,                /* RIGHTSHIFT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NE = 20,                        /* NE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_ADD = 26,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 27,                  /* SUBTRACT  */
  YYSYMBOL_DIVIDE = 28,                    /* DIVIDE  */
  YYSYMBOL_MULTIPLY = 29,                  /* MULTIPLY  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_BITAND = 31,                    /* BITAND  */
  YYSYMBOL_BITOR = 32,                     /* BITOR  */
  YYSYMBOL_NEGATION = 33,                  /* NEGATION  */
  YYSYMBOL_XOR = 34,                       /* XOR  */
  YYSYMBOL_STR = 35,                       /* STR  */
  YYSYMBOL_CHARACTER = 36,                 /* CHARACTER  */
  YYSYMBOL_CC = 37,                        /* CC  */
  YYSYMBOL_OC = 38,                        /* OC  */
  YYSYMBOL_CS = 39,                        /* CS  */
  YYSYMBOL_OS = 40,                        /* OS  */
  YYSYMBOL_CF = 41,                        /* CF  */
  YYSYMBOL_OF = 42,                        /* OF  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_COLON = 44,                     /* COLON  */
  YYSYMBOL_SCOL = 45,                      /* SCOL  */
  YYSYMBOL_OUTPUT = 46,                    /* OUTPUT  */
  YYSYMBOL_INPUT = 47,                     /* INPUT  */
  YYSYMBOL_SWITCH = 48,                    /* SWITCH  */
  YYSYMBOL_CASE = 49,                      /* CASE  */
  YYSYMBOL_BREAK = 50,                     /* BREAK  */
  YYSYMBOL_DEFAULT = 51,                   /* DEFAULT  */
  YYSYMBOL_IF = 52,                        /* IF  */
  YYSYMBOL_ELIF = 53,                      /* ELIF  */
  YYSYMBOL_ELSE = 54,                      /* ELSE  */
  YYSYMBOL_WHILE = 55,                     /* WHILE  */
  YYSYMBOL_FOR = 56,                       /* FOR  */
  YYSYMBOL_CONTINUE = 57,                  /* CONTINUE  */
  YYSYMBOL_TYPEOF = 58,                    /* TYPEOF  */
  YYSYMBOL_ASSIGN = 59,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Code = 61,                      /* Code  */
  YYSYMBOL_headerfileInclude = 62,         /* headerfileInclude  */
  YYSYMBOL_Program = 63,                   /* Program  */
  YYSYMBOL_func_list = 64,                 /* func_list  */
  YYSYMBOL_func = 65,                      /* func  */
  YYSYMBOL_66_1 = 66,                      /* $@1  */
  YYSYMBOL_func_prefix = 67,               /* func_prefix  */
  YYSYMBOL_68_2 = 68,                      /* $@2  */
  YYSYMBOL_func_data_type = 69,            /* func_data_type  */
  YYSYMBOL_param_list = 70,                /* param_list  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_param = 72,                     /* param  */
  YYSYMBOL_stmt_list = 73,                 /* stmt_list  */
  YYSYMBOL_stmt = 74,                      /* stmt  */
  YYSYMBOL_declaration = 75,               /* declaration  */
  YYSYMBOL_76_4 = 76,                      /* $@4  */
  YYSYMBOL_arr_values = 77,                /* arr_values  */
  YYSYMBOL_78_5 = 78,                      /* $@5  */
  YYSYMBOL_return_stmt = 79,               /* return_stmt  */
  YYSYMBOL_data_type = 80,                 /* data_type  */
  YYSYMBOL_expr = 81,                      /* expr  */
  YYSYMBOL_postfix_expr = 82,              /* postfix_expr  */
  YYSYMBOL_unary_expr = 83,                /* unary_expr  */
  YYSYMBOL_primary_expr = 84,              /* primary_expr  */
  YYSYMBOL_unary_op = 85,                  /* unary_op  */
  YYSYMBOL_const = 86,                     /* const  */
  YYSYMBOL_assign = 87,                    /* assign  */
  YYSYMBOL_if_stmt = 88,                   /* if_stmt  */
  YYSYMBOL_89_6 = 89,                      /* $@6  */
  YYSYMBOL_90_7 = 90,                      /* $@7  */
  YYSYMBOL_91_8 = 91,                      /* $@8  */
  YYSYMBOL_92_9 = 92,                      /* $@9  */
  YYSYMBOL_elif_stmt = 93,                 /* elif_stmt  */
  YYSYMBOL_94_10 = 94,                     /* $@10  */
  YYSYMBOL_95_11 = 95,                     /* $@11  */
  YYSYMBOL_96_12 = 96,                     /* $@12  */
  YYSYMBOL_97_13 = 97,                     /* $@13  */
  YYSYMBOL_else_stmt = 98,                 /* else_stmt  */
  YYSYMBOL_99_14 = 99,                     /* $@14  */
  YYSYMBOL_switch_stmt = 100,              /* switch_stmt  */
  YYSYMBOL_101_15 = 101,                   /* $@15  */
  YYSYMBOL_102_16 = 102,                   /* $@16  */
  YYSYMBOL_103_17 = 103,                   /* $@17  */
  YYSYMBOL_case_stmt_list = 104,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 105,                /* case_stmt  */
  YYSYMBOL_106_18 = 106,                   /* $@18  */
  YYSYMBOL_107_19 = 107,                   /* $@19  */
  YYSYMBOL_default_stmt = 108,             /* default_stmt  */
  YYSYMBOL_while_loop_stmt = 109,          /* while_loop_stmt  */
  YYSYMBOL_110_20 = 110,                   /* $@20  */
  YYSYMBOL_111_21 = 111,                   /* $@21  */
  YYSYMBOL_112_22 = 112,                   /* $@22  */
  YYSYMBOL_for_loop_stmt = 113,            /* for_loop_stmt  */
  YYSYMBOL_114_23 = 114,                   /* $@23  */
  YYSYMBOL_115_24 = 115,                   /* $@24  */
  YYSYMBOL_116_25 = 116,                   /* $@25  */
  YYSYMBOL_117_26 = 117,                   /* $@26  */
  YYSYMBOL_func_call = 118,                /* func_call  */
  YYSYMBOL_119_27 = 119,                   /* $@27  */
  YYSYMBOL_arg_list = 120,                 /* arg_list  */
  YYSYMBOL_arg = 121                       /* arg  */
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
#define YYLAST   654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  133
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  259

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
      55,    56,    57,    58,    59
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
     364,   367,   370,   373,   376,   384,   390,   396,   426,   456,
     462,   468,   474,   480,   486,   496,   519,   542,   572,   578,
     584,   607,   655,   703,   708,   713,   717,   734,   740,   756,
     773,   779,   801,   807,   808,   809,   810,   813,   817,   821,
     827,   850,   864,   866,   868,   871,   880,   882,   868,   893,
     898,   907,   910,   893,   917,   920,   920,   921,   924,   929,
     933,   924,   943,   947,   950,   953,   950,   967,   968,   971,
     977,   989,   971,  1001,  1005,  1019,  1024,  1001,  1036,  1036,
    1058,  1066,  1074,  1077
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
  "HEADERFILE", "INT", "CHAR", "FLOAT", "STRING", "BOOL", "VOID", "RETURN",
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

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-129)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     9,    32,  -186,     5,  -186,  -186,   215,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,     7,    33,  -186,  -186,
    -186,   181,    17,    43,    65,  -186,  -186,   -26,  -186,  -186,
    -186,  -186,  -186,   288,    42,    48,  -186,    31,  -186,  -186,
      49,    36,    75,    52,   181,  -186,    54,    90,    91,  -186,
    -186,  -186,    -7,  -186,    60,  -186,  -186,  -186,  -186,  -186,
     195,    37,     0,  -186,   506,   288,   288,    78,   391,   114,
     110,    94,  -186,    99,   100,    10,  -186,    97,  -186,  -186,
    -186,   -20,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   292,   288,   288,   288,   288,   288,   288,   288,
    -186,  -186,  -186,  -186,   106,   107,   131,  -186,   141,   288,
     316,   506,   288,  -186,   120,   414,    16,   137,   288,   288,
    -186,   506,   118,  -186,   152,  -186,   288,   624,   624,   143,
     143,   619,   619,   143,   143,   546,   526,    14,   101,   101,
    -186,  -186,  -186,   603,   566,   586,  -186,   122,  -186,   130,
     225,   341,   119,   506,   146,   142,   135,   139,   151,   288,
    -186,   437,   460,  -186,   158,   245,   195,  -186,  -186,  -186,
     288,  -186,   288,  -186,  -186,  -186,   366,   154,  -186,  -186,
     288,    38,  -186,  -186,   506,  -186,   172,   168,   169,   171,
     265,  -186,  -186,   170,   167,  -186,  -186,  -186,   188,  -186,
    -186,  -186,   167,   181,   181,    10,    -2,   194,   183,  -186,
     209,   217,   198,   237,   257,    -2,   259,   266,  -186,  -186,
    -186,   263,   268,  -186,   181,  -186,   256,   270,  -186,    -2,
     279,  -186,  -186,   269,  -186,  -186,   276,   284,   285,  -186,
     181,   181,   288,  -186,   300,  -186,   483,   181,  -186,  -186,
     308,   287,  -186,  -186,   181,   310,  -186,   256,  -186
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     7,     4,     1,     2,     5,     3,    50,
      53,    51,    52,    54,    13,     6,     0,     0,    12,     8,
      10,    20,     0,     0,     0,    87,    88,    80,    85,    83,
      84,    86,    89,     0,     0,     0,   108,     0,    94,   119,
       0,     0,     0,     0,    20,    21,     0,     0,     0,    75,
      73,    74,     0,    81,     0,    25,    30,    26,    27,    77,
      17,     0,    80,    48,    47,     0,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,    29,     0,     9,    19,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    80,    79,    22,     0,    14,     0,    37,     0,     0,
       0,    90,   132,    82,     0,     0,     0,     0,     0,     0,
      93,    92,     0,    35,     0,    36,     0,    71,    72,    59,
      60,    63,    64,    62,    61,    65,    66,    76,    55,    56,
      58,    57,    67,    68,    69,    70,    11,     0,    18,     0,
       0,     0,    78,   133,     0,   131,     0,     0,     0,     0,
     109,     0,     0,   123,     0,     0,    17,    38,    39,    78,
       0,   129,   132,    34,    33,    31,     0,     0,    95,   120,
       0,     0,    40,    15,    91,   130,     0,     0,     0,     0,
       0,    41,    42,     0,   113,    96,   121,   124,     0,    32,
     114,   110,   113,    20,    20,     0,     0,     0,   118,   112,
       0,     0,     0,     0,    44,     0,     0,     0,    97,   122,
     125,     0,     0,   115,    20,   111,   104,     0,    43,     0,
       0,   117,    99,   107,   126,    45,     0,     0,     0,    98,
      20,    20,     0,   105,     0,   116,     0,    20,   127,   100,
       0,     0,   106,   101,    20,     0,   102,   104,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,   348,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
     187,  -186,  -186,   -42,  -186,   -72,  -186,   125,  -186,  -186,
      -6,   -24,  -186,  -186,   314,  -186,  -185,   -71,  -186,  -186,
    -186,  -186,  -186,   117,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,   174,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
     205,  -186
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     7,    15,    21,    16,    22,    17,
     104,   147,   105,    43,    44,    45,   198,   213,   222,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    73,
     188,   203,   226,   233,   237,   251,   254,   257,   239,   247,
      56,    71,   177,   208,   201,   202,   207,   230,   217,    57,
      74,   189,   204,    58,   180,   205,   227,   240,    59,    67,
     154,   155
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    18,    79,   120,   122,    25,    26,   101,     1,    68,
      25,    26,  -128,     4,    65,     9,    10,    11,    23,    13,
     124,   214,    25,    26,    27,   125,   -83,   -83,   -83,    32,
     223,    33,     5,    66,    32,    28,    29,    30,  -128,   126,
     109,   110,   111,    31,   214,   115,    32,    20,    33,    19,
     -83,   121,   -83,   158,   106,    60,   159,    61,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   138,   139,
     140,   141,   142,   143,   144,   145,    72,    25,    26,    62,
      69,    76,   107,   191,   150,   151,    70,    75,   153,    77,
      28,    29,    30,    78,   161,   162,   108,   192,    31,    80,
      63,    32,   165,    33,    81,   103,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   112,    92,    93,    94,
      95,    96,    97,    98,   116,    99,    25,    26,    62,    94,
      95,    96,   117,   120,   212,   176,   100,   118,   119,    28,
      29,    30,   123,   146,   -16,   148,   184,    31,   153,   114,
      32,   160,    33,    25,    26,    62,   190,   156,    82,    83,
     106,   210,   211,   163,   164,   166,    28,    29,    30,    92,
      93,    94,    95,    96,    31,   167,   149,    32,   170,    33,
     173,   121,   231,   171,   174,   172,     9,    10,    11,    23,
      13,   187,    24,    25,    26,    27,   175,   181,   244,   245,
       9,    10,    11,    12,    13,   250,    28,    29,    30,   193,
     194,   195,   255,   196,    31,   199,   200,    32,   246,    33,
       9,    10,    11,    12,    13,    14,   -49,    34,    35,    36,
     206,    37,   215,    38,   216,   220,    39,    40,    41,    42,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     218,    92,    93,    94,    95,    96,    97,    98,   219,    99,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     168,    92,    93,    94,    95,    96,    97,    98,   221,    99,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     182,    92,    93,    94,    95,    96,    97,    98,   -46,    99,
      25,    26,    62,   224,    25,    26,    62,   225,   228,   232,
     197,   229,   234,    28,    29,    30,   236,    28,   137,    30,
     241,    31,   242,   238,    32,    31,    33,   243,    32,   253,
      33,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   248,    92,    93,    94,    95,    96,    97,    98,   252,
      99,   256,     8,   183,   235,   152,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   102,    92,    93,    94,
      95,    96,    97,    98,   258,    99,   209,   185,     0,     0,
     169,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,    97,    98,     0,
      99,     0,     0,     0,     0,   186,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,    92,    93,    94,
      95,    96,    97,    98,     0,    99,     0,     0,   113,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
      92,    93,    94,    95,    96,    97,    98,     0,    99,     0,
       0,   157,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     0,    92,    93,    94,    95,    96,    97,    98,
       0,    99,     0,     0,   178,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,    93,    94,    95,
      96,    97,    98,     0,    99,     0,     0,   179,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,    92,
      93,    94,    95,    96,    97,    98,     0,    99,     0,     0,
     249,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,    97,    98,     0,
      99,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,    92,    93,    94,    95,    96,    97,    98,     0,
      99,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    98,     0,
      99,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    92,    93,    94,    95,    96,    97,     0,     0,
      99,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    92,    93,    94,    95,    96,    97,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    92,
      93,    94,    95,    96,    82,    83,    84,    85,     0,     0,
      88,    89,     0,     0,     0,    92,    93,    94,    95,    96,
      92,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      24,     7,    44,    75,    75,    12,    13,    14,     3,    33,
      12,    13,    38,     4,    40,     5,     6,     7,     8,     9,
      40,   206,    12,    13,    14,    45,    12,    13,    14,    36,
     215,    38,     0,    59,    36,    25,    26,    27,    38,    59,
      40,    65,    66,    33,   229,    69,    36,    14,    38,    42,
      36,    75,    38,    37,    60,    38,    40,    14,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,    45,    12,    13,    14,
      38,    45,    45,    45,   108,   109,    38,    38,   112,    14,
      25,    26,    27,    41,   118,   119,    59,    59,    33,    45,
      35,    36,   126,    38,    14,    45,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    38,    26,    27,    28,
      29,    30,    31,    32,    14,    34,    12,    13,    14,    28,
      29,    30,    38,   205,   205,   159,    45,    38,    38,    25,
      26,    27,    45,    37,    37,    14,   170,    33,   172,    35,
      36,    14,    38,    12,    13,    14,   180,    37,    15,    16,
     166,   203,   204,    45,    12,    43,    25,    26,    27,    26,
      27,    28,    29,    30,    33,    45,    35,    36,    59,    38,
      45,   205,   224,    37,    45,    43,     5,     6,     7,     8,
       9,    37,    11,    12,    13,    14,    45,    39,   240,   241,
       5,     6,     7,     8,     9,   247,    25,    26,    27,    37,
      42,    42,   254,    42,    33,    45,    49,    36,   242,    38,
       5,     6,     7,     8,     9,    10,    45,    46,    47,    48,
      42,    50,    38,    52,    51,    37,    55,    56,    57,    58,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      41,    26,    27,    28,    29,    30,    31,    32,    41,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      45,    26,    27,    28,    29,    30,    31,    32,    41,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      45,    26,    27,    28,    29,    30,    31,    32,    41,    34,
      12,    13,    14,    44,    12,    13,    14,    41,    45,    53,
      45,    43,    42,    25,    26,    27,    37,    25,    26,    27,
      44,    33,    38,    54,    36,    33,    38,    42,    36,    42,
      38,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    41,    26,    27,    28,    29,    30,    31,    32,    41,
      34,    41,     4,   166,   229,    39,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    52,    26,    27,    28,
      29,    30,    31,    32,   257,    34,   202,   172,    -1,    -1,
      39,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    -1,    39,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    37,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    37,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    37,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    37,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    -1,    34,    -1,    -1,
      37,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    -1,
      34,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    -1,    -1,
      34,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    15,    16,    17,    18,    -1,    -1,
      21,    22,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    61,    62,     4,     0,    63,    64,    62,     5,
       6,     7,     8,     9,    10,    65,    67,    69,    80,    42,
      14,    66,    68,     8,    11,    12,    13,    14,    25,    26,
      27,    33,    36,    38,    46,    47,    48,    50,    52,    55,
      56,    57,    58,    73,    74,    75,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,   100,   109,   113,   118,
      38,    14,    14,    35,    81,    40,    59,   119,    81,    38,
      38,   101,    45,    89,   110,    38,    45,    14,    41,    73,
      45,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    26,    27,    28,    29,    30,    31,    32,    34,
      45,    14,    84,    45,    70,    72,    80,    45,    59,    40,
      81,    81,    38,    37,    35,    81,    14,    38,    38,    38,
      75,    81,    87,    45,    40,    45,    59,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    26,    81,    81,
      81,    81,    81,    81,    81,    81,    37,    71,    14,    35,
      81,    81,    39,    81,   120,   121,    37,    37,    37,    40,
      14,    81,    81,    45,    12,    81,    43,    45,    45,    39,
      59,    37,    43,    45,    45,    45,    81,   102,    37,    37,
     114,    39,    45,    70,    81,   120,    39,    37,    90,   111,
      81,    45,    59,    37,    42,    42,    42,    45,    76,    45,
      49,   104,   105,    91,   112,   115,    42,   106,   103,   104,
      73,    73,    87,    77,    86,    38,    51,   108,    41,    41,
      37,    41,    78,    86,    44,    41,    92,   116,    45,    43,
     107,    73,    53,    93,    42,    77,    37,    94,    54,    98,
     117,    44,    38,    42,    73,    73,    81,    99,    41,    37,
      73,    95,    41,    42,    96,    73,    41,    97,    93
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    64,    64,    66,    65,
      68,    67,    69,    69,    71,    70,    70,    70,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    75,    78,    77,    77,    79,    79,    79,
      80,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    82,    82,    83,
      84,    84,    84,    85,    85,    85,    85,    86,    86,    86,
      87,    87,    87,    87,    89,    90,    91,    92,    88,    94,
      95,    96,    97,    93,    93,    99,    98,    98,   101,   102,
     103,   100,   104,   104,   106,   107,   105,   108,   108,   110,
     111,   112,   109,   114,   115,   116,   117,   113,   119,   118,
     120,   120,   120,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     2,     0,     0,     5,
       0,     6,     1,     1,     0,     4,     1,     0,     2,     2,
       0,     1,     2,     2,     2,     1,     1,     1,     2,     2,
       1,     5,     8,     5,     5,     3,     3,     3,     5,     5,
       5,     6,     0,    11,     0,     4,     1,     2,     2,     0,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     3,     1,     4,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     6,     1,     1,     0,     0,     0,     0,    13,     0,
       0,     0,     0,    12,     0,     0,     5,     0,     0,     0,
       0,    11,     2,     0,     0,     0,     8,     3,     0,     0,
       0,     0,    10,     0,     0,     0,     0,    15,     0,     5,
       3,     1,     0,     1
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
#line 1725 "y.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 152 "parser.y"
                    {
                        has_return_stmt = 0;
                        scope_history.push(++scope_counter);
                    }
#line 1734 "y.tab.c"
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
#line 1748 "y.tab.c"
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
#line 1762 "y.tab.c"
    break;

  case 11: /* func_prefix: func_data_type ID $@2 OC param_list CC  */
#line 176 "parser.y"
                                     {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1771 "y.tab.c"
    break;

  case 12: /* func_data_type: data_type  */
#line 181 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        //printf("%s",string( $1.type));
                    }
#line 1780 "y.tab.c"
    break;

  case 13: /* func_data_type: VOID  */
#line 185 "parser.y"
                           {
                        sprintf((yyval.node).type, "void");
                        //printf("void");
                    }
#line 1789 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 191 "parser.y"
                          {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1799 "y.tab.c"
    break;

  case 15: /* param_list: param $@3 COMMA param_list  */
#line 196 "parser.y"
                                     {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                        if((yyval.node).nParams>20) sem_errors.push_back("No. of parameters exceeded for " + curr_func_name);
                    }
#line 1808 "y.tab.c"
    break;

  case 16: /* param_list: param  */
#line 200 "parser.y"
                            {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1819 "y.tab.c"
    break;

  case 17: /* param_list: %empty  */
#line 206 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1827 "y.tab.c"
    break;

  case 18: /* param: data_type ID  */
#line 211 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);                    }
#line 1836 "y.tab.c"
    break;

  case 28: /* stmt: BREAK SCOL  */
#line 228 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1846 "y.tab.c"
    break;

  case 29: /* stmt: CONTINUE SCOL  */
#line 233 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1856 "y.tab.c"
    break;

  case 31: /* stmt: INPUT OC ID CC SCOL  */
#line 239 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                        // check_scope(string($3.lexeme));
                    }
#line 1866 "y.tab.c"
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
#line 1879 "y.tab.c"
    break;

  case 33: /* stmt: OUTPUT OC expr CC SCOL  */
#line 252 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1887 "y.tab.c"
    break;

  case 34: /* stmt: OUTPUT OC STR CC SCOL  */
#line 255 "parser.y"
                                            {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " STRING");
                    }
#line 1895 "y.tab.c"
    break;

  case 35: /* stmt: TYPEOF ID SCOL  */
#line 258 "parser.y"
                                     {
                        char dtype[256]; // Choose an appropriate size for the array
                        strcpy(dtype, func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)].data_type.c_str());

                        // Print both the name of ID and its type
                        printf("Variable %s has type %s\n", (yyvsp[-1].node).lexeme, dtype);
                    }
#line 1907 "y.tab.c"
    break;

  case 36: /* declaration: data_type ID SCOL  */
#line 269 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        // if(multiple_declaration(string($2.lexeme))){
                        //     check_scope(string($2.lexeme));
                        // };
                        //if(string($1.lexeme)!="int")sem_errors.push_back(string($1.lexeme)+" "+string($2.lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1921 "y.tab.c"
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
#line 1935 "y.tab.c"
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
#line 1947 "y.tab.c"
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
#line 1962 "y.tab.c"
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
#line 1977 "y.tab.c"
    break;

  case 41: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 314 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 1988 "y.tab.c"
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
#line 2000 "y.tab.c"
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
#line 2012 "y.tab.c"
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
#line 2025 "y.tab.c"
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
#line 2038 "y.tab.c"
    break;

  case 48: /* return_stmt: RETURN STR  */
#line 356 "parser.y"
                               {
                        has_return_stmt = 1;
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2048 "y.tab.c"
    break;

  case 50: /* data_type: INT  */
#line 364 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 2056 "y.tab.c"
    break;

  case 51: /* data_type: FLOAT  */
#line 367 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 2064 "y.tab.c"
    break;

  case 52: /* data_type: STRING  */
#line 370 "parser.y"
                            {
                        strcpy((yyval.node).type, "STRING");
                    }
#line 2072 "y.tab.c"
    break;

  case 53: /* data_type: CHAR  */
#line 373 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 2080 "y.tab.c"
    break;

  case 54: /* data_type: BOOL  */
#line 376 "parser.y"
                           {
                        strcpy((yyval.node).type, "BOOL");
                    }
#line 2088 "y.tab.c"
    break;

  case 55: /* expr: expr ADD expr  */
#line 384 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2099 "y.tab.c"
    break;

  case 56: /* expr: expr SUBTRACT expr  */
#line 390 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2110 "y.tab.c"
    break;

  case 57: /* expr: expr MULTIPLY expr  */
#line 396 "parser.y"
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
#line 2145 "y.tab.c"
    break;

  case 58: /* expr: expr DIVIDE expr  */
#line 426 "parser.y"
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
#line 2180 "y.tab.c"
    break;

  case 59: /* expr: expr LE expr  */
#line 456 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2191 "y.tab.c"
    break;

  case 60: /* expr: expr GE expr  */
#line 462 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2202 "y.tab.c"
    break;

  case 61: /* expr: expr LT expr  */
#line 468 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2213 "y.tab.c"
    break;

  case 62: /* expr: expr GT expr  */
#line 474 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2224 "y.tab.c"
    break;

  case 63: /* expr: expr EQ expr  */
#line 480 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2235 "y.tab.c"
    break;

  case 64: /* expr: expr NE expr  */
#line 486 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = get_temp();
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " == " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 

                        free_temp.push(temp);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2250 "y.tab.c"
    break;

  case 65: /* expr: expr AND expr  */
#line 496 "parser.y"
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
#line 2278 "y.tab.c"
    break;

  case 66: /* expr: expr OR expr  */
#line 519 "parser.y"
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
#line 2306 "y.tab.c"
    break;

  case 67: /* expr: expr MODULO expr  */
#line 542 "parser.y"
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
#line 2341 "y.tab.c"
    break;

  case 68: /* expr: expr BITAND expr  */
#line 572 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2352 "y.tab.c"
    break;

  case 69: /* expr: expr BITOR expr  */
#line 578 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2363 "y.tab.c"
    break;

  case 70: /* expr: expr XOR expr  */
#line 584 "parser.y"
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
#line 2391 "y.tab.c"
    break;

  case 71: /* expr: expr LEFTSHIFT expr  */
#line 607 "parser.y"
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
#line 2444 "y.tab.c"
    break;

  case 72: /* expr: expr RIGHTSHIFT expr  */
#line 655 "parser.y"
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
#line 2497 "y.tab.c"
    break;

  case 73: /* expr: unary_expr  */
#line 703 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2507 "y.tab.c"
    break;

  case 74: /* expr: primary_expr  */
#line 708 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2517 "y.tab.c"
    break;

  case 75: /* expr: postfix_expr  */
#line 713 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2526 "y.tab.c"
    break;

  case 76: /* expr: expr ADD ADD  */
#line 717 "parser.y"
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
#line 2546 "y.tab.c"
    break;

  case 77: /* postfix_expr: func_call  */
#line 734 "parser.y"
                              {
                        //sem_errors.push_back("Hi");
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2556 "y.tab.c"
    break;

  case 78: /* postfix_expr: ID OS expr CS  */
#line 740 "parser.y"
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
#line 2575 "y.tab.c"
    break;

  case 79: /* unary_expr: unary_op primary_expr  */
#line 756 "parser.y"
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
#line 2595 "y.tab.c"
    break;

  case 80: /* primary_expr: ID  */
#line 773 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        // check_scope(string($1.lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2606 "y.tab.c"
    break;

  case 81: /* primary_expr: const  */
#line 779 "parser.y"
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
#line 2633 "y.tab.c"
    break;

  case 82: /* primary_expr: OC expr CC  */
#line 801 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2642 "y.tab.c"
    break;

  case 87: /* const: INT_NUM  */
#line 813 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2651 "y.tab.c"
    break;

  case 88: /* const: FLOAT_NUM  */
#line 817 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2660 "y.tab.c"
    break;

  case 89: /* const: CHARACTER  */
#line 821 "parser.y"
                                {
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2669 "y.tab.c"
    break;

  case 90: /* assign: ID ASSIGN expr  */
#line 827 "parser.y"
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
#line 2696 "y.tab.c"
    break;

  case 91: /* assign: ID OS expr CS ASSIGN expr  */
#line 850 "parser.y"
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
#line 2714 "y.tab.c"
    break;

  case 94: /* $@6: %empty  */
#line 868 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2722 "y.tab.c"
    break;

  case 95: /* $@7: %empty  */
#line 871 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2735 "y.tab.c"
    break;

  case 96: /* $@8: %empty  */
#line 880 "parser.y"
                    {
                      scope_history.push(++scope_counter);  
                    }
#line 2743 "y.tab.c"
    break;

  case 97: /* $@9: %empty  */
#line 882 "parser.y"
                                   {  
                        scope_history.pop(); 
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2754 "y.tab.c"
    break;

  case 98: /* if_stmt: IF $@6 OC expr CC $@7 OF $@8 stmt_list CF $@9 elif_stmt else_stmt  */
#line 888 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-12].node).parentNext) + ":");
                    }
#line 2762 "y.tab.c"
    break;

  case 99: /* $@10: %empty  */
#line 893 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2772 "y.tab.c"
    break;

  case 100: /* $@11: %empty  */
#line 898 "parser.y"
                               {
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2785 "y.tab.c"
    break;

  case 101: /* $@12: %empty  */
#line 907 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2793 "y.tab.c"
    break;

  case 102: /* $@13: %empty  */
#line 910 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2804 "y.tab.c"
    break;

  case 105: /* $@14: %empty  */
#line 920 "parser.y"
                            {scope_history.push(++scope_counter);}
#line 2810 "y.tab.c"
    break;

  case 106: /* else_stmt: ELSE OF $@14 stmt_list CF  */
#line 920 "parser.y"
                                                                               {scope_history.pop(); --scope_counter;}
#line 2816 "y.tab.c"
    break;

  case 108: /* $@15: %empty  */
#line 924 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2826 "y.tab.c"
    break;

  case 109: /* $@16: %empty  */
#line 929 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type);
                    }
#line 2835 "y.tab.c"
    break;

  case 110: /* $@17: %empty  */
#line 933 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 2844 "y.tab.c"
    break;

  case 111: /* switch_stmt: SWITCH $@15 OC ID $@16 CC OF case_stmt_list $@17 default_stmt CF  */
#line 937 "parser.y"
                                    {
                        tac.push_back(string((yyvsp[-10].node).parentNext) + ":");
                        loop_break.pop();
                    }
#line 2853 "y.tab.c"
    break;

  case 112: /* case_stmt_list: case_stmt case_stmt_list  */
#line 943 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 2862 "y.tab.c"
    break;

  case 114: /* $@18: %empty  */
#line 950 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 2870 "y.tab.c"
    break;

  case 115: /* $@19: %empty  */
#line 953 "parser.y"
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
#line 2885 "y.tab.c"
    break;

  case 116: /* case_stmt: CASE $@18 OC const $@19 CC COLON stmt_list  */
#line 963 "parser.y"
                                       {
                        tac.push_back(string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 2893 "y.tab.c"
    break;

  case 119: /* $@20: %empty  */
#line 971 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 2903 "y.tab.c"
    break;

  case 120: /* $@21: %empty  */
#line 977 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                        
                    }
#line 2920 "y.tab.c"
    break;

  case 121: /* $@22: %empty  */
#line 989 "parser.y"
                      {
                        scope_history.push(++scope_counter);
                    }
#line 2928 "y.tab.c"
    break;

  case 122: /* while_loop_stmt: WHILE $@20 OC expr CC $@21 OF $@22 stmt_list CF  */
#line 992 "parser.y"
                    {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-6].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2941 "y.tab.c"
    break;

  case 123: /* $@23: %empty  */
#line 1001 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 2950 "y.tab.c"
    break;

  case 124: /* $@24: %empty  */
#line 1005 "parser.y"
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
#line 2969 "y.tab.c"
    break;

  case 125: /* $@25: %empty  */
#line 1019 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 2978 "y.tab.c"
    break;

  case 126: /* $@26: %empty  */
#line 1024 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 2986 "y.tab.c"
    break;

  case 127: /* for_loop_stmt: FOR OC assign SCOL $@23 expr SCOL $@24 assign CC $@25 OF $@26 stmt_list CF  */
#line 1027 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-9].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 2999 "y.tab.c"
    break;

  case 128: /* $@27: %empty  */
#line 1036 "parser.y"
                       {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                    }
#line 3007 "y.tab.c"
    break;

  case 129: /* func_call: ID $@27 OC arg_list CC  */
#line 1039 "parser.y"
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
#line 3029 "y.tab.c"
    break;

  case 130: /* arg_list: arg COMMA arg_list  */
#line 1058 "parser.y"
                                       {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[-2].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3042 "y.tab.c"
    break;

  case 131: /* arg_list: arg  */
#line 1066 "parser.y"
                          {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[0].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3055 "y.tab.c"
    break;

  case 133: /* arg: expr  */
#line 1077 "parser.y"
                         {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 3063 "y.tab.c"
    break;


#line 3067 "y.tab.c"

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

#line 1082 "parser.y"


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
        sem_errors.push_back(variable + " Variable not declared in line " + to_string(countn+1) + " before usage.");
        return false;
    }
    return true;
}

bool check_scope(string variable){
    bool a = func_table[curr_func_name].symbol_table.find(variable) == func_table[curr_func_name].symbol_table.end();
    bool b = func_table["global"].symbol_table.find(variable) == func_table["global"].symbol_table.end();
    if(a&&b){
        sem_errors.push_back(variable + " Variable not declared in line " + to_string(countn+1) + " before usage.");
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
    // if(r == "FLOAT" && l == "CHAR"){
    //     sem_errors.push_back("Cannot convert type FLOAT to CHAR in line " + to_string(countn+1));
    //     return false;
    // }
    // if(l == "FLOAT" && r == "CHAR"){
    //     sem_errors.push_back("Cannot convert typr CHAR to FLOAT in line " + to_string(countn+1));
    //     return false;
    // }
    return 0;
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
    // if((type1 == "FLOAT" and type2 == "CHAR") or (type1 == "CHAR" and type2 == "FLOAT")) {
    //     return true;
    // }
    // return false;
    return 0;
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

