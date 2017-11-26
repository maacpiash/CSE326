/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     RLIT = 258,
     ILIT = 259,
     CLIT = 260,
     SLIT = 261,
     PLUS = 262,
     MINUS = 263,
     TIMES = 264,
     DIVIDE = 265,
     REM = 266,
     ASSIGN = 267,
     LP = 268,
     RP = 269,
     LC = 270,
     RC = 271,
     LB = 272,
     RB = 273,
     ID = 274,
     ENDL = 275,
     SEMI = 276,
     HASH = 277,
     LEXERR = 278,
     IF = 279,
     THEN = 280,
     ELSE = 281,
     CHAR = 282,
     INT = 283,
     FLOAT = 284,
     WHILE = 285,
     COMMA = 286,
     NEG = 287
   };
#endif
/* Tokens.  */
#define RLIT 258
#define ILIT 259
#define CLIT 260
#define SLIT 261
#define PLUS 262
#define MINUS 263
#define TIMES 264
#define DIVIDE 265
#define REM 266
#define ASSIGN 267
#define LP 268
#define RP 269
#define LC 270
#define RC 271
#define LB 272
#define RB 273
#define ID 274
#define ENDL 275
#define SEMI 276
#define HASH 277
#define LEXERR 278
#define IF 279
#define THEN 280
#define ELSE 281
#define CHAR 282
#define INT 283
#define FLOAT 284
#define WHILE 285
#define COMMA 286
#define NEG 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

