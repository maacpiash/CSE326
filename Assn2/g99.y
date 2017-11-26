%{
	#include <math.h>
	#include <stdio.h>
	#include <stdlib.h>
	#define YYSTYPE double
%}

%token RLIT ILIT CLIT SLIT
%token PLUS MINUS TIMES DIVIDE REM
%token ASSIGN
%token LP RP LC RC LB RB
%token ID
%token ENDL SEMI
%token HASH LEXERR
%token IF THEN ELSE
%token CHAR INT FLOAT
%token WHILE
%token COMMA

%right ASSIGN
%left PLUS MINUS
%left TIMES DIVIDE REM
%left NEG

%start prog

%%

prog: STMTS { if (yychar == YYEOF) printf("\nAccepted!\n"); }
STMTS:	| STMT STMTS
STMT: DTYPE ID IDLIST SEMI
		| ID ASSIGN EXPR SEMI 
		| IF LP EXPR RP THEN BLOCK
		| IF LP EXPR RP THEN BLOCK ELSE BLOCK
		| WHILE LP EXPR RP BLOCK
BLOCK: LC STMTS RC
IDLIST: 
		| COMMA ID IDLIST
EXPR: TERM { $$ = $1; }
		| EXPR PLUS TERM { $$ = $1 + $3; }
		| EXPR MINUS TERM { $$ = $1 - $3; }
		| EXPR TIMES TERM { $$ = $1 * $3; }
		| EXPR DIVIDE TERM { $$ = $1 / $3; }
		| EXPR REM TERM { $$ = fmod($1 , $3); }
		| LP EXPR RP { $$ = $2; }
		| MINUS EXPR { $$ = (-1) * $2; }
TERM: ID { $$ = $1; }
		| CONST { $$ = $1; }
DTYPE: INT { $$ = $1; }
		| FLOAT { $$ = $1; }
		| CHAR { $$ = $1; }
CONST: ILIT { $$ = $1; }
		| RLIT { $$ = $1; }
		| CLIT { $$ = $1; }
		| SLIT { $$ = $1; }
OPTR: PLUS { $$ = $1; }
		| MINUS { $$ = $1; }
		| TIMES { $$ = $1; }
		| DIVIDE { $$ = $1; }
		| REM { $$ = $1; }



%%

extern int yylex(void);
extern int yyparse(void);

int yyerror(char *s) {
  printf("%s\n", s);
}

int yywrap(void) {
    return 1;
}

int main() {
	return yyparse();  
}