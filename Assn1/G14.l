%{

#include <stdio.h>
#include <stdlib.h>

%}

letter 		[A-Za-z]
digit 		[0-9]
dot			[.]
singleq		[']
doubleq		["]
id 			{letter}({letter}|{digit})*
ilit 		({digit}+)
slit 		({doubleq}{letter}+{doubleq})
clit 		({singleq}{letter}{singleq}) 
rlit 		({digit}*{dot}{digit}+)
backsl		[\\]
bksl 		({backsl}{backsl})

%%

"\n"		 						{printf("NL ");}
"\t"	  	 						{printf("TAB ");}
"\r"	 	 						{printf("CR ");}
{backsl}	 	 					{printf("BACKSL ");}
{bksl}								{printf("BKSL ");}
if      			  				{printf("IF ");}
else      							{printf("ELSE ");}
for       							{printf("FOR ");}
return      						{printf("RETURN ");}
int      							{printf("INT ");}
real      							{printf("REAL ");}
char      							{printf("CHAR ");}
void      							{printf("VOID ");}
"+"									{printf("PLUS ");}
"-"									{printf("MINUS ");}
"*"									{printf("PROD ");}
"/"									{printf("DIV ");}
"%"									{printf("REM ");}
":="								{printf("ASSIGN ");}
"++"								{printf("INC ");}
"--"								{printf("DEC ");}
{ilit}								{printf("ILIT ");}
{rlit}								{printf("RLIT ");}
{clit}								{printf("CLIT ");}
{slit}								{printf("SLIT ");}
{dot}								{printf("DOT ");}
";"									{printf("SEMI ");}
"]"									{printf("RSB ");}
"["									{printf("LSB ");}
"}"									{printf("RCB ");}
"{"									{printf("LCB ");}
")"									{printf("RPT ");}
"("									{printf("LPT ");}
{id}								{printf("ID ");}
{singleq}							{printf("SINGLEQ ");}
{doubleq}							{printf("DOUBLEQ ");}

%%

int main(void)
{
   //yyparse();
   yylex();
   return 0;
}

int yywrap(void)
{  
   return 0;
}

int yyerror(void)
{
    printf("Error\n");
    exit(1);
}