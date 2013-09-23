/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_DICTIONARY_LATEX_TAB_H_INCLUDED
# define YY_YY_DICTIONARY_LATEX_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OPEN_PARENTHESIS = 258,
     CLOSE_PARENTHESIS = 259,
     OPEN_SQUARE_BRACKETS = 260,
     CLOSE_SQUARE_BRACKETS = 261,
     OPEN_CURLY_BRACKETS = 262,
     CLOSE_CURLY_BRACKETS = 263,
     APPROX = 264,
     NEQ = 265,
     GEQ = 266,
     LEQ = 267,
     EQ = 268,
     SUB = 269,
     ADD = 270,
     SQRT = 271,
     POW = 272,
     DIV = 273,
     MULT = 274,
     FRAC = 275,
     PERCENT = 276,
     LATEX_PROD = 277,
     LATEX_SUM = 278,
     FAT = 279,
     INFINITY = 280,
     REAL = 281,
     VAR = 282,
     PI = 283,
     LATEX_VAR = 284
   };
#endif
/* Tokens.  */
#define OPEN_PARENTHESIS 258
#define CLOSE_PARENTHESIS 259
#define OPEN_SQUARE_BRACKETS 260
#define CLOSE_SQUARE_BRACKETS 261
#define OPEN_CURLY_BRACKETS 262
#define CLOSE_CURLY_BRACKETS 263
#define APPROX 264
#define NEQ 265
#define GEQ 266
#define LEQ 267
#define EQ 268
#define SUB 269
#define ADD 270
#define SQRT 271
#define POW 272
#define DIV 273
#define MULT 274
#define FRAC 275
#define PERCENT 276
#define LATEX_PROD 277
#define LATEX_SUM 278
#define FAT 279
#define INFINITY 280
#define REAL 281
#define VAR 282
#define PI 283
#define LATEX_VAR 284



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_DICTIONARY_LATEX_TAB_H_INCLUDED  */
