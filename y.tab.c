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
        //string value;
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
    unordered_map<string, string>string_info;
    string curr_func_name="global";
    vector<string> curr_func_param_type;

    vector<string> reserved = {"int", "float", "char", "bool","string", "void", "if", "elif", "else", "for", "while", "break", "continue", "main", "return", "switch", "case", "progin", "progout"};


#line 173 "y.tab.c"

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
    FLEN = 314,                    /* FLEN  */
    ASSIGN = 315                   /* ASSIGN  */
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
#define FLEN 314
#define ASSIGN 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 103 "parser.y"

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

#line 363 "y.tab.c"

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
  YYSYMBOL_FLEN = 59,                      /* FLEN  */
  YYSYMBOL_ASSIGN = 60,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_Code = 62,                      /* Code  */
  YYSYMBOL_headerfileInclude = 63,         /* headerfileInclude  */
  YYSYMBOL_Program = 64,                   /* Program  */
  YYSYMBOL_func_list = 65,                 /* func_list  */
  YYSYMBOL_func = 66,                      /* func  */
  YYSYMBOL_67_1 = 67,                      /* $@1  */
  YYSYMBOL_func_prefix = 68,               /* func_prefix  */
  YYSYMBOL_69_2 = 69,                      /* $@2  */
  YYSYMBOL_func_data_type = 70,            /* func_data_type  */
  YYSYMBOL_param_list = 71,                /* param_list  */
  YYSYMBOL_72_3 = 72,                      /* $@3  */
  YYSYMBOL_param = 73,                     /* param  */
  YYSYMBOL_stmt_list = 74,                 /* stmt_list  */
  YYSYMBOL_stmt = 75,                      /* stmt  */
  YYSYMBOL_declaration = 76,               /* declaration  */
  YYSYMBOL_arr_values = 77,                /* arr_values  */
  YYSYMBOL_78_4 = 78,                      /* $@4  */
  YYSYMBOL_79_5 = 79,                      /* $@5  */
  YYSYMBOL_return_stmt = 80,               /* return_stmt  */
  YYSYMBOL_data_type = 81,                 /* data_type  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_postfix_expr = 83,              /* postfix_expr  */
  YYSYMBOL_unary_expr = 84,                /* unary_expr  */
  YYSYMBOL_primary_expr = 85,              /* primary_expr  */
  YYSYMBOL_unary_op = 86,                  /* unary_op  */
  YYSYMBOL_const = 87,                     /* const  */
  YYSYMBOL_assign = 88,                    /* assign  */
  YYSYMBOL_if_stmt = 89,                   /* if_stmt  */
  YYSYMBOL_90_6 = 90,                      /* $@6  */
  YYSYMBOL_91_7 = 91,                      /* $@7  */
  YYSYMBOL_92_8 = 92,                      /* $@8  */
  YYSYMBOL_93_9 = 93,                      /* $@9  */
  YYSYMBOL_elif_stmt = 94,                 /* elif_stmt  */
  YYSYMBOL_95_10 = 95,                     /* $@10  */
  YYSYMBOL_96_11 = 96,                     /* $@11  */
  YYSYMBOL_97_12 = 97,                     /* $@12  */
  YYSYMBOL_98_13 = 98,                     /* $@13  */
  YYSYMBOL_else_stmt = 99,                 /* else_stmt  */
  YYSYMBOL_100_14 = 100,                   /* $@14  */
  YYSYMBOL_switch_stmt = 101,              /* switch_stmt  */
  YYSYMBOL_102_15 = 102,                   /* $@15  */
  YYSYMBOL_103_16 = 103,                   /* $@16  */
  YYSYMBOL_104_17 = 104,                   /* $@17  */
  YYSYMBOL_case_stmt_list = 105,           /* case_stmt_list  */
  YYSYMBOL_case_stmt = 106,                /* case_stmt  */
  YYSYMBOL_107_18 = 107,                   /* $@18  */
  YYSYMBOL_108_19 = 108,                   /* $@19  */
  YYSYMBOL_default_stmt = 109,             /* default_stmt  */
  YYSYMBOL_while_loop_stmt = 110,          /* while_loop_stmt  */
  YYSYMBOL_111_20 = 111,                   /* $@20  */
  YYSYMBOL_112_21 = 112,                   /* $@21  */
  YYSYMBOL_113_22 = 113,                   /* $@22  */
  YYSYMBOL_for_loop_stmt = 114,            /* for_loop_stmt  */
  YYSYMBOL_115_23 = 115,                   /* $@23  */
  YYSYMBOL_116_24 = 116,                   /* $@24  */
  YYSYMBOL_117_25 = 117,                   /* $@25  */
  YYSYMBOL_118_26 = 118,                   /* $@26  */
  YYSYMBOL_func_call = 119,                /* func_call  */
  YYSYMBOL_120_27 = 120,                   /* $@27  */
  YYSYMBOL_arg_list = 121,                 /* arg_list  */
  YYSYMBOL_arg = 122                       /* arg  */
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
#define YYLAST   830

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   141,   142,   145,   148,   151,   155,   154,
     170,   169,   184,   188,   194,   194,   203,   209,   214,   221,
     222,   225,   226,   227,   228,   229,   230,   231,   232,   237,
     242,   243,   248,   256,   259,   262,   273,   282,   292,   295,
     305,   314,   322,   333,   343,   344,   362,   377,   385,   388,
     388,   396,   404,   404,   412,   423,   432,   437,   440,   443,
     446,   449,   452,   460,   466,   472,   502,   532,   538,   545,
     551,   558,   564,   571,   577,   584,   590,   597,   604,   614,
     637,   660,   690,   696,   702,   725,   773,   821,   826,   831,
     835,   852,   858,   874,   891,   897,   919,   925,   926,   927,
     928,   931,   935,   939,   949,   972,   986,   988,   990,   993,
    1002,  1004,   990,  1015,  1020,  1029,  1032,  1015,  1039,  1042,
    1042,  1043,  1046,  1051,  1055,  1046,  1065,  1069,  1072,  1075,
    1072,  1089,  1090,  1093,  1099,  1111,  1093,  1123,  1127,  1141,
    1146,  1123,  1158,  1158,  1180,  1188,  1196,  1199
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
  "ELIF", "ELSE", "WHILE", "FOR", "CONTINUE", "TYPEOF", "FLEN", "ASSIGN",
  "$accept", "Code", "headerfileInclude", "Program", "func_list", "func",
  "$@1", "func_prefix", "$@2", "func_data_type", "param_list", "$@3",
  "param", "stmt_list", "stmt", "declaration", "arr_values", "$@4", "$@5",
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

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-143)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,    14,    22,   -77,     7,   -77,   -77,   278,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,    -1,    41,   -77,   -77,
     -77,   213,    -2,    69,   438,   -77,   -77,    -9,   -77,   -77,
     -77,   -77,   -77,    21,    48,    58,    70,   -77,    64,   -77,
     -77,    89,    91,    79,    99,    98,   213,   -77,    97,   126,
     355,   -77,   -77,   -77,     1,   -77,   102,   -77,   -77,   -77,
     -77,   -77,    80,   -22,    90,   -77,   687,    21,    21,   113,
     572,   115,   119,   123,   442,   140,   128,   -77,   129,   133,
     268,   -77,   130,   159,   -77,   -77,   -77,    93,    21,    21,
      -6,   132,   136,   173,   286,   303,    21,    21,   473,    21,
      21,    21,    21,    21,    21,    21,   -77,   -77,   -77,   -77,
     145,   152,   163,   -77,   469,    21,   497,   687,    21,   -77,
     147,   148,   153,   157,   595,    55,   183,    21,    21,   -77,
     687,   156,   -77,   165,    16,   -77,   321,   189,    87,    87,
     166,    95,   167,    95,   169,   800,   170,   800,   172,    95,
     176,    95,   727,   707,     4,   151,   151,   -77,   -77,   -77,
     784,   747,   767,   -77,   174,   -77,   171,   375,   522,   155,
     687,   186,   185,    48,   -77,    48,   184,   188,   192,    21,
     -77,   618,   641,   -77,   181,   195,   203,   193,   395,   200,
     233,   234,   238,   239,   240,   242,    80,   -77,   -77,   -77,
      21,   -77,    21,   -77,   -77,   -77,   -77,   -77,   547,   225,
     -77,   -77,    21,   250,    37,   207,    10,   -77,   -77,   241,
     252,   253,   254,   255,   259,   -77,   687,   -77,   260,   237,
     261,   263,   415,   257,   -77,   -77,   -77,   270,   271,   -77,
     -77,   -77,   -77,   -77,   -77,   264,   265,   -77,   -77,   -77,
     -77,   273,   275,   -77,   -77,   -77,   265,   213,   213,   268,
     -77,   -77,   283,   272,   -77,   284,   285,   294,    13,   288,
     296,   -77,   -77,   -77,   -77,   213,   -77,   287,   300,   301,
     -77,   -77,   289,   -77,   305,   306,   308,   -77,   213,   213,
      21,   -77,   310,   -77,   664,   213,   -77,   -77,   311,   313,
     -77,   -77,   213,   312,   -77,   287,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     7,     4,     1,     2,     5,     3,    58,
      61,    59,    60,    62,    13,     6,     0,     0,    12,     8,
      10,    20,     0,     0,     0,   101,   102,    94,    99,    97,
      98,   100,   103,     0,     0,     0,     0,   122,     0,   108,
     133,     0,     0,     0,     0,     0,    20,    21,     0,     0,
       0,    89,    87,    88,     0,    95,     0,    25,    30,    26,
      27,    91,    17,     0,    94,    56,    55,     0,     0,     0,
       0,    52,     0,    49,     0,     0,     0,    28,     0,     0,
       0,    29,     0,     0,     9,    19,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    94,    93,    22,
       0,    14,     0,    40,     0,     0,     0,   104,   146,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   107,
     106,     0,    35,     0,     0,    36,     0,     0,    85,    86,
       0,    67,     0,    69,     0,    75,     0,    78,     0,    73,
       0,    71,    79,    80,    90,    63,    64,    66,    65,    81,
      82,    83,    84,    11,     0,    18,     0,     0,     0,    92,
     147,     0,   145,     0,    48,     0,     0,     0,     0,     0,
     123,     0,     0,   137,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    41,    42,    92,
       0,   143,   146,    53,    50,    34,    33,    31,     0,     0,
     109,   134,     0,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,    15,   105,   144,     0,     0,
       0,     0,     0,     0,    45,    46,    47,     0,     0,    68,
      70,    76,    77,    74,    72,     0,   127,   110,   135,   138,
      38,     0,     0,    32,   128,   124,   127,    20,    20,     0,
      39,    37,     0,   132,   126,     0,     0,     0,     0,     0,
       0,   111,   136,   139,   129,    20,   125,   118,     0,     0,
     131,   113,   121,   140,     0,     0,     0,   112,    20,    20,
       0,   119,     0,   130,     0,    20,   141,   114,     0,     0,
     120,   115,    20,     0,   116,   118,   117
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   352,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     162,   -77,   -77,   -45,   -77,   -76,   -41,   -77,   -77,   -77,
      -4,   -24,   -77,   -77,   307,   -77,   -32,   -75,   -77,   -77,
     -77,   -77,   -77,    59,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   104,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     161,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,     6,     7,    15,    21,    16,    22,    17,
     110,   164,   111,    45,    46,    47,    72,   122,   120,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    78,
     230,   257,   277,   282,   285,   299,   302,   305,   287,   295,
      58,    76,   209,   263,   255,   256,   262,   279,   270,    59,
      79,   231,   258,    60,   212,   259,   278,   288,    61,    69,
     171,   172
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    85,    73,    18,   129,   131,    25,    26,    64,    70,
       1,   129,   137,    25,    26,   107,   -97,   -97,     4,    28,
      29,    30,     5,   113,   237,    25,    26,    31,   185,  -142,
      32,    67,    33,    25,    26,    64,    62,    32,   114,    33,
     -97,    19,   -97,   116,   117,   238,    28,    29,    30,    32,
     124,    68,   186,   140,    31,    20,   130,    32,   112,    33,
      25,    26,    71,   130,   138,   139,   141,   143,   145,   147,
     149,   151,   152,   153,   155,   156,   157,   158,   159,   160,
     161,   162,   234,    63,    32,     9,    10,    11,    12,    13,
     167,   168,   178,    82,   170,   179,    74,   235,     9,    10,
      11,    23,    13,   181,   182,    25,    26,    27,    75,    77,
      88,    89,   188,    98,    99,   100,   101,   102,    28,    29,
      30,    98,    99,   100,   101,   102,    31,    80,  -142,    32,
     115,    33,   203,   134,   204,    34,    81,    83,   135,    84,
      87,    73,    86,    73,    25,    26,    64,   109,    25,    26,
      64,   118,    44,   136,   125,   208,   -54,    28,    29,    30,
     121,    28,    29,    30,   -51,    31,   126,   127,    32,    31,
      33,   128,    32,   133,    33,   132,   226,   165,   170,   100,
     101,   102,   163,   129,   267,    25,    26,    64,   232,   -16,
     173,   142,   112,   174,   176,   144,   175,   180,    28,    29,
      30,   183,   184,   189,   190,   191,    31,   192,   193,    32,
     194,    33,   265,   266,   195,   200,   197,   196,     9,    10,
      11,    23,    13,   201,    24,    25,    26,    27,   202,   205,
     280,   216,   146,   206,   214,   130,   274,   207,    28,    29,
      30,   213,   215,   292,   293,   218,    31,   219,   220,    32,
     298,    33,   221,   222,   223,    34,   224,   303,   -57,    35,
      36,    37,   229,    38,   233,    39,   294,   236,    40,    41,
      42,    43,    44,     9,    10,    11,    23,    13,   239,   246,
      25,    26,    27,     9,    10,    11,    12,    13,    14,   240,
     241,   242,   243,    28,    29,    30,   244,   245,    25,    26,
      64,    31,   250,   247,    32,   248,    33,   251,   252,   253,
      34,    28,    29,    30,   254,    25,    26,    64,   260,    31,
     261,   268,    32,   269,    33,   271,   272,    44,    28,    29,
      30,   273,   275,    25,    26,    64,    31,   276,   284,    32,
     281,    33,   283,   286,   290,   148,    28,    29,    30,   289,
     291,   296,   300,   304,    31,   301,     8,    32,   225,    33,
     264,   108,   150,   227,   306,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     187,    98,    99,   100,   101,   102,   103,   104,     0,   105,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     106,    98,    99,   100,   101,   102,   103,   104,     0,   105,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     198,    98,    99,   100,   101,   102,   103,   104,     0,   105,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
     217,    98,    99,   100,   101,   102,   103,   104,     0,   105,
      25,    26,    64,     0,    25,    26,    64,     0,     0,     0,
     249,     0,     0,    28,    29,    30,     0,    28,    29,    30,
       0,    31,     0,    65,    32,    31,    33,   123,    32,     0,
      33,    25,    26,    64,     0,    25,    26,    64,     0,     0,
       0,     0,     0,     0,    28,    29,    30,     0,    28,   154,
      30,     0,    31,     0,   166,    32,    31,    33,     0,    32,
       0,    33,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,     0,     0,     0,   169,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,     0,     0,
       0,   199,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,     0,     0,     0,     0,   228,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,     0,    98,    99,
     100,   101,   102,   103,   104,     0,   105,     0,     0,   119,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
       0,    98,    99,   100,   101,   102,   103,   104,     0,   105,
       0,     0,   177,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,     0,    98,    99,   100,   101,   102,   103,
     104,     0,   105,     0,     0,   210,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,    98,    99,   100,
     101,   102,   103,   104,     0,   105,     0,     0,   211,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     0,
      98,    99,   100,   101,   102,   103,   104,     0,   105,     0,
       0,   297,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
       0,   105,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
       0,   105,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    98,    99,   100,   101,   102,   103,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
      98,    99,   100,   101,   102,    88,    89,    90,    91,     0,
       0,    94,    95,     0,     0,     0,    98,    99,   100,   101,
     102
};

static const yytype_int16 yycheck[] =
{
      24,    46,    34,     7,    80,    80,    12,    13,    14,    33,
       3,    87,    87,    12,    13,    14,    12,    13,     4,    25,
      26,    27,     0,    45,    14,    12,    13,    33,    12,    38,
      36,    40,    38,    12,    13,    14,    38,    36,    60,    38,
      36,    42,    38,    67,    68,    35,    25,    26,    27,    36,
      74,    60,    36,    59,    33,    14,    80,    36,    62,    38,
      12,    13,    14,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,    45,    14,    36,     5,     6,     7,     8,     9,
     114,   115,    37,    14,   118,    40,    38,    60,     5,     6,
       7,     8,     9,   127,   128,    12,    13,    14,    38,    45,
      15,    16,   136,    26,    27,    28,    29,    30,    25,    26,
      27,    26,    27,    28,    29,    30,    33,    38,    38,    36,
      40,    38,   173,    40,   175,    42,    45,    38,    45,    41,
      14,   173,    45,   175,    12,    13,    14,    45,    12,    13,
      14,    38,    59,    60,    14,   179,    41,    25,    26,    27,
      41,    25,    26,    27,    41,    33,    38,    38,    36,    33,
      38,    38,    36,    14,    38,    45,   200,    14,   202,    28,
      29,    30,    37,   259,   259,    12,    13,    14,   212,    37,
      43,    59,   196,    45,    37,    59,    43,    14,    25,    26,
      27,    45,    37,    14,    38,    38,    33,    38,    38,    36,
      38,    38,   257,   258,    38,    60,    45,    43,     5,     6,
       7,     8,     9,    37,    11,    12,    13,    14,    43,    45,
     275,    38,    59,    45,    39,   259,   268,    45,    25,    26,
      27,    60,    39,   288,   289,    45,    33,    14,    14,    36,
     295,    38,    14,    14,    14,    42,    14,   302,    45,    46,
      47,    48,    37,    50,    14,    52,   290,    60,    55,    56,
      57,    58,    59,     5,     6,     7,     8,     9,    37,    42,
      12,    13,    14,     5,     6,     7,     8,     9,    10,    37,
      37,    37,    37,    25,    26,    27,    37,    37,    12,    13,
      14,    33,    45,    42,    36,    42,    38,    37,    37,    45,
      42,    25,    26,    27,    49,    12,    13,    14,    45,    33,
      45,    38,    36,    51,    38,    41,    41,    59,    25,    26,
      27,    37,    44,    12,    13,    14,    33,    41,    37,    36,
      53,    38,    42,    54,    38,    59,    25,    26,    27,    44,
      42,    41,    41,    41,    33,    42,     4,    36,   196,    38,
     256,    54,    59,   202,   305,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      59,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      45,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      12,    13,    14,    -1,    12,    13,    14,    -1,    -1,    -1,
      45,    -1,    -1,    25,    26,    27,    -1,    25,    26,    27,
      -1,    33,    -1,    35,    36,    33,    38,    35,    36,    -1,
      38,    12,    13,    14,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    -1,    25,    26,
      27,    -1,    33,    -1,    35,    36,    33,    38,    -1,    36,
      -1,    38,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    39,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      -1,    39,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    -1,    -1,    -1,    39,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,    -1,    -1,    37,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      -1,    -1,    37,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    37,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    -1,    34,    -1,    -1,    37,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    37,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    -1,
      -1,    34,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    15,    16,    17,    18,    -1,
      -1,    21,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    62,    63,     4,     0,    64,    65,    63,     5,
       6,     7,     8,     9,    10,    66,    68,    70,    81,    42,
      14,    67,    69,     8,    11,    12,    13,    14,    25,    26,
      27,    33,    36,    38,    42,    46,    47,    48,    50,    52,
      55,    56,    57,    58,    59,    74,    75,    76,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   101,   110,
     114,   119,    38,    14,    14,    35,    82,    40,    60,   120,
      82,    14,    77,    87,    38,    38,   102,    45,    90,   111,
      38,    45,    14,    38,    41,    74,    45,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    26,    27,
      28,    29,    30,    31,    32,    34,    45,    14,    85,    45,
      71,    73,    81,    45,    60,    40,    82,    82,    38,    37,
      79,    41,    78,    35,    82,    14,    38,    38,    38,    76,
      82,    88,    45,    14,    40,    45,    60,    88,    82,    82,
      59,    82,    59,    82,    59,    82,    59,    82,    59,    82,
      59,    82,    82,    82,    26,    82,    82,    82,    82,    82,
      82,    82,    82,    37,    72,    14,    35,    82,    82,    39,
      82,   121,   122,    43,    45,    43,    37,    37,    37,    40,
      14,    82,    82,    45,    37,    12,    36,    59,    82,    14,
      38,    38,    38,    38,    38,    38,    43,    45,    45,    39,
      60,    37,    43,    77,    77,    45,    45,    45,    82,   103,
      37,    37,   115,    60,    39,    39,    38,    45,    45,    14,
      14,    14,    14,    14,    14,    71,    82,   121,    39,    37,
      91,   112,    82,    14,    45,    60,    60,    14,    35,    37,
      37,    37,    37,    37,    37,    37,    42,    42,    42,    45,
      45,    37,    37,    45,    49,   105,   106,    92,   113,   116,
      45,    45,   107,   104,   105,    74,    74,    88,    38,    51,
     109,    41,    41,    37,    87,    44,    41,    93,   117,   108,
      74,    53,    94,    42,    37,    95,    54,    99,   118,    44,
      38,    42,    74,    74,    82,   100,    41,    37,    74,    96,
      41,    42,    97,    74,    41,    98,    94
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    65,    65,    67,    66,
      69,    68,    70,    70,    72,    71,    71,    71,    73,    74,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    78,
      77,    77,    79,    77,    77,    80,    80,    80,    81,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    85,    85,    85,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    90,    91,
      92,    93,    89,    95,    96,    97,    98,    94,    94,   100,
      99,    99,   102,   103,   104,   101,   105,   105,   107,   108,
     106,   109,   109,   111,   112,   113,   110,   115,   116,   117,
     118,   114,   120,   119,   121,   121,   121,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     0,     1,     2,     0,     0,     5,
       0,     6,     1,     1,     0,     4,     1,     0,     2,     2,
       0,     1,     2,     2,     2,     1,     1,     1,     2,     2,
       1,     5,     8,     5,     5,     3,     3,     8,     7,     8,
       3,     5,     5,     5,     5,     6,     6,     6,     4,     0,
       4,     1,     0,     4,     1,     2,     2,     0,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     6,     3,
       6,     3,     6,     3,     6,     3,     6,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     1,     4,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     1,     1,     0,     0,
       0,     0,    13,     0,     0,     0,     0,    12,     0,     0,
       5,     0,     0,     0,     0,    11,     2,     0,     0,     0,
       8,     3,     0,     0,     0,     0,    10,     0,     0,     0,
       0,    15,     0,     5,     3,     1,     0,     1
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
#line 148 "parser.y"
                                   {
    //printf("Hello");
}
#line 1784 "y.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 155 "parser.y"
                    {
                        has_return_stmt = 0;
                        scope_history.push(++scope_counter);
                    }
#line 1793 "y.tab.c"
    break;

  case 9: /* func: func_prefix OF $@1 stmt_list CF  */
#line 159 "parser.y"
                    {
                        if(func_table[curr_func_name].return_type != "void" && curr_func_name!="main" && has_return_stmt == 0){
                            sem_errors.push_back("Return stmt not there for function: " + curr_func_name);
                        }
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("end:\n");
                        has_return_stmt = 0;
                    }
#line 1807 "y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 170 "parser.y"
                    {   
                        if(func_table.find(string((yyvsp[0].node).lexeme)) != func_table.end()){
                            sem_errors.push_back("Error: Duplicate function name - " + string((yyvsp[0].node).lexeme));
                        }
                        tac.push_back(string((yyvsp[0].node).lexeme) + ": " + string((yyvsp[-1].node).type)); 
                        curr_func_name = string((yyvsp[0].node).lexeme);
                        func_table[curr_func_name]=func_table["global"];
                        
                    }
#line 1821 "y.tab.c"
    break;

  case 11: /* func_prefix: func_data_type ID $@2 OC param_list CC  */
#line 179 "parser.y"
                                     {
                        func_table[curr_func_name].return_type = string((yyvsp[-5].node).type);
                        func_table[curr_func_name].num_params = (yyvsp[-1].node).nParams;
                    }
#line 1830 "y.tab.c"
    break;

  case 12: /* func_data_type: data_type  */
#line 184 "parser.y"
                              {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        //printf("%s",string( $1.type));
                    }
#line 1839 "y.tab.c"
    break;

  case 13: /* func_data_type: VOID  */
#line 188 "parser.y"
                           {
                        sprintf((yyval.node).type, "void");
                        //printf("void");
                    }
#line 1848 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 194 "parser.y"
                          {
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));                       
                    }
#line 1858 "y.tab.c"
    break;

  case 15: /* param_list: param $@3 COMMA param_list  */
#line 199 "parser.y"
                                     {
                        (yyval.node).nParams = (yyvsp[0].node).nParams + 1;
                        if((yyval.node).nParams>20) sem_errors.push_back("No. of parameters exceeded for " + curr_func_name);
                    }
#line 1867 "y.tab.c"
    break;

  case 16: /* param_list: param  */
#line 203 "parser.y"
                            {
                        (yyval.node).nParams = 1;
                        func_table[curr_func_name].param_types.push_back(string((yyvsp[0].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)] = { string((yyvsp[0].node).type), scope_counter+1, 0, 0, countn+1 };
                        tac.push_back("- arg " + string((yyvsp[0].node).type) + " " + string((yyvsp[0].node).lexeme));
                    }
#line 1878 "y.tab.c"
    break;

  case 17: /* param_list: %empty  */
#line 209 "parser.y"
                      {
                        (yyval.node).nParams = 0;
                    }
#line 1886 "y.tab.c"
    break;

  case 18: /* param: data_type ID  */
#line 214 "parser.y"
                                 {
                        (yyval.node).nParams = 1;
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);                   
                        }
#line 1896 "y.tab.c"
    break;

  case 28: /* stmt: BREAK SCOL  */
#line 232 "parser.y"
                                 {
                        if(!loop_break.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_break.top()));
                        }
                    }
#line 1906 "y.tab.c"
    break;

  case 29: /* stmt: CONTINUE SCOL  */
#line 237 "parser.y"
                                    {
                        if(!loop_continue.empty()){
                            tac.push_back("GOTO #L" + to_string(loop_continue.top()));
                        }
                    }
#line 1916 "y.tab.c"
    break;

  case 31: /* stmt: INPUT OC ID CC SCOL  */
#line 243 "parser.y"
                                           {
                        check_declaration((yyvsp[-2].node).lexeme);
                        tac.push_back("input " + string((yyvsp[-2].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-2].node).lexeme)].data_type);
                        // check_scope(string($3.lexeme));
                    }
#line 1926 "y.tab.c"
    break;

  case 32: /* stmt: INPUT OC ID OS expr CS CC SCOL  */
#line 248 "parser.y"
                                                     {
                        check_declaration((yyvsp[-5].node).lexeme);
                        string temp = get_temp();
                        tac.push_back("input " + temp + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                        tac.push_back(string((yyvsp[-5].node).lexeme) + " [ " + string((yyvsp[-3].node).lexeme) + " ] = " + temp + " " + func_table[curr_func_name].symbol_table[string((yyvsp[-5].node).lexeme)].data_type);
                        free_temp.push(temp);
                        // check_scope(string($3.lexeme));
                    }
#line 1939 "y.tab.c"
    break;

  case 33: /* stmt: OUTPUT OC expr CC SCOL  */
#line 256 "parser.y"
                                             {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-2].node).type));
                    }
#line 1947 "y.tab.c"
    break;

  case 34: /* stmt: OUTPUT OC STR CC SCOL  */
#line 259 "parser.y"
                                            {
                        tac.push_back("output " + string((yyvsp[-2].node).lexeme) + " STRING");
                    }
#line 1955 "y.tab.c"
    break;

  case 35: /* stmt: TYPEOF ID SCOL  */
#line 262 "parser.y"
                                     {
                        char dtype[256]; // Choose an appropriate size for the array
                        strcpy(dtype, func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)].data_type.c_str());

                        // Print both the name of ID and its type
                        printf("Variable %s has type %s\n", (yyvsp[-1].node).lexeme, dtype);
                    }
#line 1967 "y.tab.c"
    break;

  case 36: /* declaration: data_type ID SCOL  */
#line 273 "parser.y"
                                      { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        // if(multiple_declaration(string($2.lexeme))){
                        //     check_scope(string($2.lexeme));
                        // };
                        //if(string($1.lexeme)!="int")sem_errors.push_back(string($1.lexeme)+" "+string($2.lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { string((yyvsp[-2].node).type), scope_counter, 0, 0, countn+1 };
                    }
#line 1981 "y.tab.c"
    break;

  case 37: /* declaration: data_type ID ASSIGN FLEN OC STR CC SCOL  */
#line 282 "parser.y"
                                                              {
                        string t0=get_temp();
                        func_table[curr_func_name].symbol_table[string((yyvsp[-6].node).lexeme)] = { "INT", scope_counter, 0, 0, countn+1 };
                        string_info[string((yyvsp[-6].node).lexeme)] = to_string(string((yyvsp[-2].node).lexeme).length()-2);
                        tac.push_back(string((yyvsp[-2].node).lexeme) + string_info[string((yyvsp[-6].node).lexeme)]);
                        tac.push_back(t0+" = "+ string_info[string((yyvsp[-6].node).lexeme)] + " INT ");
                        tac.push_back("- INT "+string((yyvsp[-6].node).lexeme));
                        tac.push_back(string((yyvsp[-6].node).lexeme) +" = " + t0 + " INT " );

                       }
#line 1996 "y.tab.c"
    break;

  case 38: /* declaration: FLEN OC ID CC ASSIGN ID SCOL  */
#line 292 "parser.y"
                                                   {
                        string_info[string((yyvsp[-4].node).lexeme)] = string((yyvsp[-1].node).lexeme);
                    }
#line 2004 "y.tab.c"
    break;

  case 39: /* declaration: data_type ID ASSIGN FLEN OC ID CC SCOL  */
#line 295 "parser.y"
                                                            {
                        string t0=get_temp();
                        //string_info[string($2.lexeme)] = string_info[string($6.lexeme)];
                        // tac.push_back(string($1.lexeme) + " "+ to_string(string_info[string($6.lexeme)]));
                        // tac.push_back(string($6.lexeme) + to_string(string_info[string($2.lexeme)]));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-6].node).lexeme)] = { "INT", scope_counter, 0, 0, countn+1 };
                        tac.push_back(t0+" = "+ string_info[string((yyvsp[-2].node).lexeme)] + " INT ");
                        tac.push_back("- INT "+string((yyvsp[-6].node).lexeme));
                        tac.push_back(string((yyvsp[-6].node).lexeme) +" = " + t0 + " INT " );
                    }
#line 2019 "y.tab.c"
    break;

  case 40: /* declaration: STRING ID SCOL  */
#line 305 "parser.y"
                                     { 
                        is_reserved_word(string((yyvsp[-1].node).lexeme));
                        // if(multiple_declaration(string($2.lexeme))){
                        //     check_scope(string($2.lexeme));
                        // };
                        //if(string($1.lexeme)!="int")sem_errors.push_back(string($1.lexeme)+" "+string($2.lexeme));
                        tac.push_back("- " + string((yyvsp[-2].node).type) + " " + string((yyvsp[-1].node).lexeme));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-1].node).lexeme)] = { "STRING", scope_counter, 0, 0, countn+1 };
                    }
#line 2033 "y.tab.c"
    break;

  case 41: /* declaration: STRING ID ASSIGN STR SCOL  */
#line 314 "parser.y"
                                                {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        string_info[string((yyvsp[-3].node).lexeme)]=to_string(string((yyvsp[-1].node).lexeme).length()-2);
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        tac.push_back("- STRING " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " STRING");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { "STRING", scope_counter, string((yyvsp[-1].node).lexeme).length(), 0, countn+1 };
                    }
#line 2046 "y.tab.c"
    break;

  case 42: /* declaration: STRING ID ASSIGN expr SCOL  */
#line 322 "parser.y"
                                                 {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        string_info[string((yyvsp[-3].node).lexeme)]=string_info[string((yyvsp[-1].node).lexeme)];
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + "STRING");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2062 "y.tab.c"
    break;

  case 43: /* declaration: data_type ID ASSIGN expr SCOL  */
#line 333 "parser.y"
                                                    {
                        is_reserved_word(string((yyvsp[-3].node).lexeme));
                        multiple_declaration(string((yyvsp[-3].node).lexeme));
                        check_type(string((yyvsp[-4].node).type), string((yyvsp[-1].node).type));
                        tac.push_back("- " + string((yyvsp[-4].node).type) + " " + string((yyvsp[-3].node).lexeme));
                        tac.push_back(string((yyvsp[-3].node).lexeme) + " = " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[-4].node).type));
                        func_table[curr_func_name].symbol_table[string((yyvsp[-3].node).lexeme)] = { string((yyvsp[-4].node).type), scope_counter, 0, 0, countn+1 };

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2077 "y.tab.c"
    break;

  case 45: /* declaration: data_type ID OS INT_NUM CS SCOL  */
#line 344 "parser.y"
                                                      {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                    }
#line 2088 "y.tab.c"
    break;

  case 46: /* declaration: data_type ID OS INT_NUM CS ASSIGN  */
#line 362 "parser.y"
                                                        {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 2100 "y.tab.c"
    break;

  case 47: /* declaration: data_type ID OS CHARACTER CS ASSIGN  */
#line 377 "parser.y"
                                                          {
                        is_reserved_word(string((yyvsp[-4].node).lexeme));
                        multiple_declaration(string((yyvsp[-4].node).lexeme));
                        tac.push_back("- " + string((yyvsp[-5].node).type) + " " + string((yyvsp[-4].node).lexeme) + " [ " + string((yyvsp[-2].node).lexeme) + " ] ");
                        func_table[curr_func_name].symbol_table[string((yyvsp[-4].node).lexeme)] = { string((yyvsp[-5].node).type), scope_counter, stoi(string((yyvsp[-2].node).lexeme)), 1, countn+1 };
                        curr_array = string((yyvsp[-4].node).lexeme);
                    }
#line 2112 "y.tab.c"
    break;

  case 49: /* $@4: %empty  */
#line 388 "parser.y"
                          {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                    }
#line 2124 "y.tab.c"
    break;

  case 51: /* arr_values: const  */
#line 396 "parser.y"
                            {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                        arr_index=0;
                    }
#line 2137 "y.tab.c"
    break;

  case 52: /* $@5: %empty  */
#line 404 "parser.y"
                       {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                    }
#line 2149 "y.tab.c"
    break;

  case 54: /* arr_values: ID  */
#line 412 "parser.y"
                         {
                        check_type(func_table[curr_func_name].symbol_table[curr_array].data_type, string((yyvsp[0].node).type));
                        tac.push_back(curr_array + " [ " + to_string(arr_index++) + " ] = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[curr_array].data_type);
                        if(arr_index > func_table[curr_func_name].symbol_table[curr_array].size){
                            sem_errors.push_back("Line no: " + to_string(func_table[curr_func_name].symbol_table[curr_array].line_number) + " error: too many initializers for "+curr_array+ "[" + to_string(func_table[curr_func_name].symbol_table[curr_array].size) + "]");
                        }
                        arr_index=0;
                    }
#line 2162 "y.tab.c"
    break;

  case 55: /* return_stmt: RETURN expr  */
#line 423 "parser.y"
                                {
                        //sem_errors.push_back($2.type);
                        check_type(func_table[curr_func_name].return_type, string((yyvsp[0].node).type));
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                        has_return_stmt = 1;

                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2175 "y.tab.c"
    break;

  case 56: /* return_stmt: RETURN STR  */
#line 432 "parser.y"
                               {
                        has_return_stmt = 1;
                        tac.push_back("return " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].return_type);
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2185 "y.tab.c"
    break;

  case 58: /* data_type: INT  */
#line 440 "parser.y"
                        {
                        strcpy((yyval.node).type, "INT");
                    }
#line 2193 "y.tab.c"
    break;

  case 59: /* data_type: FLOAT  */
#line 443 "parser.y"
                            {
                        strcpy((yyval.node).type, "FLOAT");
                    }
#line 2201 "y.tab.c"
    break;

  case 60: /* data_type: STRING  */
#line 446 "parser.y"
                            {
                        strcpy((yyval.node).type, "STRING");
                    }
#line 2209 "y.tab.c"
    break;

  case 61: /* data_type: CHAR  */
#line 449 "parser.y"
                           {
                        strcpy((yyval.node).type, "CHAR");
                    }
#line 2217 "y.tab.c"
    break;

  case 62: /* data_type: BOOL  */
#line 452 "parser.y"
                           {
                        strcpy((yyval.node).type, "BOOL");
                    }
#line 2225 "y.tab.c"
    break;

  case 63: /* expr: expr ADD expr  */
#line 460 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2236 "y.tab.c"
    break;

  case 64: /* expr: expr SUBTRACT expr  */
#line 466 "parser.y"
                                         {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2247 "y.tab.c"
    break;

  case 65: /* expr: expr MULTIPLY expr  */
#line 472 "parser.y"
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
#line 2282 "y.tab.c"
    break;

  case 66: /* expr: expr DIVIDE expr  */
#line 502 "parser.y"
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
#line 2317 "y.tab.c"
    break;

  case 67: /* expr: expr LE expr  */
#line 532 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2328 "y.tab.c"
    break;

  case 68: /* expr: expr LE FLEN OC ID CC  */
#line 538 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2340 "y.tab.c"
    break;

  case 69: /* expr: expr GE expr  */
#line 545 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2351 "y.tab.c"
    break;

  case 70: /* expr: expr GE FLEN OC ID CC  */
#line 551 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2363 "y.tab.c"
    break;

  case 71: /* expr: expr LT expr  */
#line 558 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2374 "y.tab.c"
    break;

  case 72: /* expr: expr LT FLEN OC ID CC  */
#line 564 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2386 "y.tab.c"
    break;

  case 73: /* expr: expr GT expr  */
#line 571 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2397 "y.tab.c"
    break;

  case 74: /* expr: expr GT FLEN OC ID CC  */
#line 577 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2409 "y.tab.c"
    break;

  case 75: /* expr: expr EQ expr  */
#line 584 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2420 "y.tab.c"
    break;

  case 76: /* expr: expr EQ FLEN OC ID CC  */
#line 590 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2432 "y.tab.c"
    break;

  case 77: /* expr: expr NE FLEN OC ID CC  */
#line 597 "parser.y"
                                            {
                        add_tac((yyval.node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-1].node))
                        string t0 = get_temp();
                        tac.push_back(t0+" = "+string_info[(yyvsp[-1].node).lexeme]+" INT");
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-5].node).lexeme) + " " + string((yyvsp[-4].node).lexeme) + " " + t0 + " " + "INT");

                    }
#line 2444 "y.tab.c"
    break;

  case 78: /* expr: expr NE expr  */
#line 604 "parser.y"
                                   {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        string temp = get_temp();
                        tac.push_back(temp + " = " + string((yyvsp[-2].node).lexeme) + " == " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        tac.push_back(string((yyval.node).lexeme) + " = ~ " + temp + " " + string((yyval.node).type)); 

                        free_temp.push(temp);
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2459 "y.tab.c"
    break;

  case 79: /* expr: expr AND expr  */
#line 614 "parser.y"
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
#line 2487 "y.tab.c"
    break;

  case 80: /* expr: expr OR expr  */
#line 637 "parser.y"
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
#line 2515 "y.tab.c"
    break;

  case 81: /* expr: expr MODULO expr  */
#line 660 "parser.y"
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
#line 2550 "y.tab.c"
    break;

  case 82: /* expr: expr BITAND expr  */
#line 690 "parser.y"
                                       {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2561 "y.tab.c"
    break;

  case 83: /* expr: expr BITOR expr  */
#line 696 "parser.y"
                                      {
                        add_tac((yyval.node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node))
                        tac.push_back(string((yyval.node).lexeme) + " = " + string((yyvsp[-2].node).lexeme) + " " + string((yyvsp[-1].node).lexeme) + " " + string((yyvsp[0].node).lexeme) + " " + string((yyval.node).type));
                        if(const_temps.find(string((yyvsp[-2].node).lexeme)) == const_temps.end() && (yyvsp[-2].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-2].node).lexeme));
                        if(const_temps.find(string((yyvsp[0].node).lexeme)) == const_temps.end() && (yyvsp[0].node).lexeme[0] == '@') free_temp.push(string((yyvsp[0].node).lexeme));
                    }
#line 2572 "y.tab.c"
    break;

  case 84: /* expr: expr XOR expr  */
#line 702 "parser.y"
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
#line 2600 "y.tab.c"
    break;

  case 85: /* expr: expr LEFTSHIFT expr  */
#line 725 "parser.y"
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
#line 2653 "y.tab.c"
    break;

  case 86: /* expr: expr RIGHTSHIFT expr  */
#line 773 "parser.y"
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
#line 2706 "y.tab.c"
    break;

  case 87: /* expr: unary_expr  */
#line 821 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2716 "y.tab.c"
    break;

  case 88: /* expr: primary_expr  */
#line 826 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2726 "y.tab.c"
    break;

  case 89: /* expr: postfix_expr  */
#line 831 "parser.y"
                                   {
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2735 "y.tab.c"
    break;

  case 90: /* expr: expr ADD ADD  */
#line 835 "parser.y"
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
#line 2755 "y.tab.c"
    break;

  case 91: /* postfix_expr: func_call  */
#line 852 "parser.y"
                              {
                        //sem_errors.push_back("Hi");
                        strcpy((yyval.node).type, (yyvsp[0].node).type);
                        sprintf((yyval.node).lexeme, "%s", (yyvsp[0].node).lexeme);
                    }
#line 2765 "y.tab.c"
    break;

  case 92: /* postfix_expr: ID OS expr CS  */
#line 858 "parser.y"
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
#line 2784 "y.tab.c"
    break;

  case 93: /* unary_expr: unary_op primary_expr  */
#line 874 "parser.y"
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
#line 2804 "y.tab.c"
    break;

  case 94: /* primary_expr: ID  */
#line 891 "parser.y"
                       {
                        check_declaration(string((yyvsp[0].node).lexeme));
                        // check_scope(string($1.lexeme));
                        strcpy((yyval.node).type, func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type.c_str());
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2815 "y.tab.c"
    break;

  case 95: /* primary_expr: const  */
#line 897 "parser.y"
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
#line 2842 "y.tab.c"
    break;

  case 96: /* primary_expr: OC expr CC  */
#line 919 "parser.y"
                                 {
                        strcpy((yyval.node).type, (yyvsp[-1].node).type);
                        strcpy((yyval.node).lexeme, (yyvsp[-1].node).lexeme);
                    }
#line 2851 "y.tab.c"
    break;

  case 101: /* const: INT_NUM  */
#line 931 "parser.y"
                            {
                        strcpy((yyval.node).type, "INT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2860 "y.tab.c"
    break;

  case 102: /* const: FLOAT_NUM  */
#line 935 "parser.y"
                                {
                        strcpy((yyval.node).type, "FLOAT");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2869 "y.tab.c"
    break;

  case 103: /* const: CHARACTER  */
#line 939 "parser.y"
                                {
                        // printf("CHAR");
                        // printf("\n");
                        // printf($1.lexeme);
                        // printf("\n");
                        strcpy((yyval.node).type, "CHAR");
                        strcpy((yyval.node).lexeme, (yyvsp[0].node).lexeme);
                    }
#line 2882 "y.tab.c"
    break;

  case 104: /* assign: ID ASSIGN expr  */
#line 949 "parser.y"
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
#line 2909 "y.tab.c"
    break;

  case 105: /* assign: ID OS expr CS ASSIGN expr  */
#line 972 "parser.y"
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
#line 2927 "y.tab.c"
    break;

  case 108: /* $@6: %empty  */
#line 990 "parser.y"
                        {
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 2935 "y.tab.c"
    break;

  case 109: /* $@7: %empty  */
#line 993 "parser.y"
                               { 
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2948 "y.tab.c"
    break;

  case 110: /* $@8: %empty  */
#line 1002 "parser.y"
                    {
                      scope_history.push(++scope_counter);  
                    }
#line 2956 "y.tab.c"
    break;

  case 111: /* $@9: %empty  */
#line 1004 "parser.y"
                                   {  
                        scope_history.pop(); 
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 2967 "y.tab.c"
    break;

  case 112: /* if_stmt: IF $@6 OC expr CC $@7 OF $@8 stmt_list CF $@9 elif_stmt else_stmt  */
#line 1010 "parser.y"
                                         {   
                        tac.push_back(string((yyvsp[-12].node).parentNext) + ":");
                    }
#line 2975 "y.tab.c"
    break;

  case 113: /* $@10: %empty  */
#line 1015 "parser.y"
                         {
                        string str = tac[tac.size()-2].substr(5);
                        char* hold = const_cast<char*>(str.c_str());
                        sprintf((yyvsp[0].node).parentNext, "%s", hold);
                    }
#line 2985 "y.tab.c"
    break;

  case 114: /* $@11: %empty  */
#line 1020 "parser.y"
                               {
                        tac.push_back("if " + string((yyvsp[-1].node).lexeme) + " GOTO #L" + to_string(label_counter) + " else GOTO #L" + to_string(label_counter+1));
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 
                        tac.push_back(string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                    }
#line 2998 "y.tab.c"
    break;

  case 115: /* $@12: %empty  */
#line 1029 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 3006 "y.tab.c"
    break;

  case 116: /* $@13: %empty  */
#line 1032 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).parentNext));
                        tac.push_back(string((yyvsp[-6].node).else_body) + ":");
                    }
#line 3017 "y.tab.c"
    break;

  case 119: /* $@14: %empty  */
#line 1042 "parser.y"
                            {scope_history.push(++scope_counter);}
#line 3023 "y.tab.c"
    break;

  case 120: /* else_stmt: ELSE OF $@14 stmt_list CF  */
#line 1042 "parser.y"
                                                                               {scope_history.pop(); --scope_counter;}
#line 3029 "y.tab.c"
    break;

  case 122: /* $@15: %empty  */
#line 1046 "parser.y"
                           {
                        int temp_label = label_counter;
                        loop_break.push(temp_label);
                        sprintf((yyvsp[0].node).parentNext, "#L%d", label_counter++);
                    }
#line 3039 "y.tab.c"
    break;

  case 123: /* $@16: %empty  */
#line 1051 "parser.y"
                          {
                        temp_index = variable_count;
                        tac.push_back("@t" + to_string(variable_count++) + " = " + string((yyvsp[0].node).lexeme) + " " + func_table[curr_func_name].symbol_table[string((yyvsp[0].node).lexeme)].data_type);
                    }
#line 3048 "y.tab.c"
    break;

  case 124: /* $@17: %empty  */
#line 1055 "parser.y"
                                         {
                        // strcpy($8.id, $4.lexeme);
                        // strcpy($8.parentNext, $1.parentNext);
                    }
#line 3057 "y.tab.c"
    break;

  case 125: /* switch_stmt: SWITCH $@15 OC ID $@16 CC OF case_stmt_list $@17 default_stmt CF  */
#line 1059 "parser.y"
                                    {
                        tac.push_back(string((yyvsp[-10].node).parentNext) + ":");
                        loop_break.pop();
                    }
#line 3066 "y.tab.c"
    break;

  case 126: /* case_stmt_list: case_stmt case_stmt_list  */
#line 1065 "parser.y"
                                             {
                        strcpy((yyvsp[-1].node).id, (yyval.node).id);
                        strcpy((yyvsp[-1].node).parentNext, (yyval.node).parentNext);
                    }
#line 3075 "y.tab.c"
    break;

  case 128: /* $@18: %empty  */
#line 1072 "parser.y"
                         {
                        // tac.push_back(string($4.if_body) + ":");
                    }
#line 3083 "y.tab.c"
    break;

  case 129: /* $@19: %empty  */
#line 1075 "parser.y"
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
#line 3098 "y.tab.c"
    break;

  case 130: /* case_stmt: CASE $@18 OC const $@19 CC COLON stmt_list  */
#line 1085 "parser.y"
                                       {
                        tac.push_back(string((yyvsp[-4].node).parentNext) + ":");
                    }
#line 3106 "y.tab.c"
    break;

  case 133: /* $@20: %empty  */
#line 1093 "parser.y"
                          {
                        sprintf((yyvsp[0].node).loop_body, "#L%d", label_counter); 
                        loop_continue.push(label_counter++);
                        tac.push_back("\n" + string((yyvsp[0].node).loop_body) + ":");
                    }
#line 3116 "y.tab.c"
    break;

  case 134: /* $@21: %empty  */
#line 1099 "parser.y"
                    {
                        sprintf((yyvsp[-1].node).if_body, "#L%d", label_counter++); 

                        loop_break.push(label_counter);
                        sprintf((yyvsp[-1].node).else_body, "#L%d", label_counter++); 

                        tac.push_back("\nif " + string((yyvsp[-1].node).lexeme) + " GOTO " + string((yyvsp[-1].node).if_body) + " else GOTO " + string((yyvsp[-1].node).else_body));
                        tac.push_back("\n" + string((yyvsp[-1].node).if_body) + ":");

                        if(const_temps.find(string((yyvsp[-1].node).lexeme)) == const_temps.end() && (yyvsp[-1].node).lexeme[0] == '@') free_temp.push(string((yyvsp[-1].node).lexeme));
                        
                    }
#line 3133 "y.tab.c"
    break;

  case 135: /* $@22: %empty  */
#line 1111 "parser.y"
                      {
                        scope_history.push(++scope_counter);
                    }
#line 3141 "y.tab.c"
    break;

  case 136: /* while_loop_stmt: WHILE $@20 OC expr CC $@21 OF $@22 stmt_list CF  */
#line 1114 "parser.y"
                    {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-6].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 3154 "y.tab.c"
    break;

  case 137: /* $@23: %empty  */
#line 1123 "parser.y"
                                       {
                        sprintf((yyvsp[-3].node).loop_body, "#L%d", label_counter++); 
                        tac.push_back("\n" + string((yyvsp[-3].node).loop_body) + ":");
                    }
#line 3163 "y.tab.c"
    break;

  case 138: /* $@24: %empty  */
#line 1127 "parser.y"
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
#line 3182 "y.tab.c"
    break;

  case 139: /* $@25: %empty  */
#line 1141 "parser.y"
                              {
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-4].node).if_body) + ":");
                    }
#line 3191 "y.tab.c"
    break;

  case 140: /* $@26: %empty  */
#line 1146 "parser.y"
                    {
                        scope_history.push(++scope_counter);
                    }
#line 3199 "y.tab.c"
    break;

  case 141: /* for_loop_stmt: FOR OC assign SCOL $@23 expr SCOL $@24 assign CC $@25 OF $@26 stmt_list CF  */
#line 1149 "parser.y"
                                 {
                        scope_history.pop();
                        --scope_counter;
                        tac.push_back("GOTO " + string((yyvsp[-9].node).loop_body));
                        tac.push_back("\n" + string((yyvsp[-9].node).else_body) + ":");
                        loop_continue.pop();
                        loop_break.pop();
                    }
#line 3212 "y.tab.c"
    break;

  case 142: /* $@27: %empty  */
#line 1158 "parser.y"
                       {
                        func_call_id.push({string((yyvsp[0].node).lexeme), func_table[string((yyvsp[0].node).lexeme)].param_types});
                    }
#line 3220 "y.tab.c"
    break;

  case 143: /* func_call: ID $@27 OC arg_list CC  */
#line 1161 "parser.y"
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
#line 3242 "y.tab.c"
    break;

  case 144: /* arg_list: arg COMMA arg_list  */
#line 1180 "parser.y"
                                       {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[-2].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3255 "y.tab.c"
    break;

  case 145: /* arg_list: arg  */
#line 1188 "parser.y"
                          {
                        int sz = func_call_id.top().second.size();
                        string type = func_call_id.top().second[sz-1];
                        func_call_id.top().second.pop_back();
                        if(type_check(string((yyvsp[0].node).type), type)) {
                            sem_errors.push_back("datatype for argument not matched in line " + to_string(countn+1));
                        }
                    }
#line 3268 "y.tab.c"
    break;

  case 147: /* arg: expr  */
#line 1199 "parser.y"
                         {
                        tac.push_back("param " + string((yyvsp[0].node).lexeme) + " " + string((yyvsp[0].node).type));
                    }
#line 3276 "y.tab.c"
    break;


#line 3280 "y.tab.c"

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

#line 1204 "parser.y"


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

