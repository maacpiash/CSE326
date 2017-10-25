#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 255
#define ILIT 1
#define RLIT 2

int id;
// symbols;// = "(){}[].;+-*/%:=\'";

int isNumber(char* word)
{
    int len = strlen(word);
    int i;
    for(i = 0; i < len; i++)
        if((word[i] < 48 || word[i] > 57) && word[i] != '.')
            return 0;
    for(i = 0; i < len; i++)
        if(word[i] == '.')
            return RLIT;
    return ILIT;
}

void clear(int** variables)
{
    int i;
    for(i = 0; i < 9; i++)
        *variables[i] = 0;
}

int main()
{
    FILE* fp = fopen("input.txt", "r");
    int length;
    char word[MAXLEN];
    int* allres[10];
    id = 0;

    int maybe_int = 0;
    int maybe_real = 0;
    int maybe_id = 0;

    int maybe_incr = 0;
    int maybe_decr = 0;
    int maybe_assn = 0;
    int maybe_hex = 0;

    int maybe_res_if = 0; allres[0] = &maybe_res_if;
    int maybe_res_else = 0; allres[1] = &maybe_res_else;
    int maybe_res_for = 0; allres[2] = &maybe_res_for;
    int maybe_res_int = 0; allres[3] = &maybe_res_int;
    int maybe_res_char = 0; allres[4] = &maybe_res_char;
    int maybe_res_real = 0; allres[5] = &maybe_res_real;
    int maybe_res_void = 0; allres[6] = &maybe_res_void;
    int maybe_res_return = 0; allres[7] = &maybe_res_return;

    //int maybe_res__start = 0; allres[8] = &maybe_res__start;
    //int maybe_res__end = 0; allres[9] = &maybe_res__end;
    char c;// = fgetc(fp);

    for(c = fgetc(fp); c != EOF; c = fgetc(fp)) {
        printf("\n%c\t", c);

        /********** IF SPACE **********/
        if(c == ' ') {
            if(maybe_int) {
                if(maybe_real) {
                    printf("RLIT ");
                } else if(maybe_hex) {
                    printf("HLIT ");
                } else {
                    printf("ILIT ");
                }
                maybe_hex = 0;
                maybe_real = 0;
                maybe_int = 0;
            }
            if(maybe_res_char == 4) {
                printf("CHAR ");
                maybe_id = 0;
            }
            if(maybe_res_else == 4) {
                printf("ELSE ");
                maybe_id = 0;
            }
            if(maybe_res_for == 3) {
                printf("FOR ");
                maybe_id = 0;
            }
            if(maybe_res_if == 2) {
                printf("IF ");
                maybe_id = 0;
            }
            if(maybe_res_int == 3) {
                printf("INT ");
                maybe_id = 0;
            }
            if(maybe_res_real == 4) {
                printf("REAL ");
                maybe_id = 0;
            }
            if(maybe_res_return == 6) {
                printf("RETURN ");
                maybe_id = 0;
            }
            if(maybe_res_void == 4) {
                printf("VOID ");
                maybe_id = 0;
            }
            clear(allres);
            continue;
        }

        /********** IF LETTER **********/
        switch (c) {
        case 'i':
            if(maybe_res_if == 0) {
                maybe_res_if++;
            } else if(maybe_res_int == 0) {
                maybe_res_int++;
            } else if(maybe_res_void == 2) {
                maybe_res_void++;
                printf("%d\n", maybe_res_void);
            } else {
                clear(allres);
            }
            break;
        case 'f':
            if(maybe_res_if == 1) {
                maybe_res_if++;
            } else if(!maybe_res_for) {
                maybe_res_for++;
            } else {
                clear(allres);
            }
            break;
        case 'e':
            if(maybe_res_else == 0 || maybe_res_else == 3) {
                maybe_res_else++;
            } else if(maybe_res_real == 1) {
                maybe_res_real++;
            } else if(maybe_res_return == 1) {
                maybe_res_return++;
            } else {
                clear(allres);
            }
            break;
        case 'l':
            if(maybe_res_else == 1) {
                maybe_res_else++;
            } else if(maybe_res_real == 3) {
                maybe_res_real++;
            } else {
                clear(allres);
            }
            break;
        case 's':
            if(maybe_res_else == 2) {
                maybe_res_else++;
            } else {
                clear(allres);
            }
            break;
        case 'o':
            if(maybe_res_for == 1) {
                maybe_res_for++;
            } else if(maybe_res_void == 1) {
                maybe_res_void++;
                printf("%d\n", maybe_res_void);
            } else {
                clear(allres);
            }
            break;
        case 'r':
            if(maybe_res_char == 3) {
                maybe_res_char++;
            } else if(maybe_res_for == 2) {
                maybe_res_for++;
            } else if(!maybe_res_real) {
                maybe_res_real++;
            } else if(maybe_res_return == 0 || maybe_res_return == 4) {
                maybe_res_return++;
            } else {
                clear(allres);
            }
            break;
        case 'n':
            if(maybe_res_int == 1) {
                maybe_res_int++;
            } else if(maybe_res_return == 5) {
                maybe_res_return++;
            }
            break;
        case 't':
            if(maybe_res_int == 2) {
                maybe_res_int++;
            } else if(maybe_res_return == 2) {
                maybe_res_return++;
            } else {
                clear(allres);
            }
            break;
        case 'c':
            if(maybe_res_char == 0) {
                maybe_res_char++;
            } else {
                clear(allres);
            }
            break;

        case 'h':
            if(maybe_res_char == 1) {
                maybe_res_char++;
            } else {
                clear(allres);
            }
            break;
        case 'a':
            if(maybe_res_char == 2) {
                maybe_res_char++;
            } else if(maybe_res_real == 2) {
                maybe_res_real++;
            } else {
                clear(allres);
            }
            break;
        case 'v':
            if(!maybe_res_void) {
                maybe_res_void++;
                printf("%d\n", maybe_res_void);
            } else {
                clear(allres);
            }
            break;
        case 'd':
            if(maybe_res_void == 3) {
                maybe_res_void++;
                printf("%d\n", maybe_res_void);
            } else {
                clear(allres);
            }
            break;
        case 'u':
            if(maybe_res_return == 3) {
                maybe_res_return++;
            } else {
                clear(allres);
            }
            break;
        case 'x':
            if(maybe_hex) {
                maybe_hex++;
                maybe_id = 0;
            }
            break;
        default:
            clear(allres);
            if(maybe_hex == 2) {
                printf("HLIT ");
                maybe_hex++;
                maybe_id = 0;
            }

            break;
        }

        /********** IF NEWLINE **********/
        if(c == '\n') {
            if(maybe_real) {
                printf("RLIT ");
                maybe_real = 0;
                maybe_int = 0;
            } else {
                if(maybe_int)
                    printf("ILIT ");
            }
            if(maybe_id) {
                printf("ID%d ", ++id);
                maybe_id = 0;
            }
            maybe_int = 0;
            printf("NL ");
            continue;
        }

        if(!isdigit(c) && maybe_int && c != '.') {
            if(maybe_real) {
                printf("RLIT ");
                maybe_real = 0;
            } else if(!maybe_hex) {
                printf("ILIT ");
            }
        }

        if(isalpha(c) || c == '_') {
            maybe_id++;
        } else {
            if(maybe_id) {
                printf("ID%d ", ++id);
                maybe_id = 0;
            }
            /* NEW
            if(maybe_int) {
                if(maybe_real) {
                    printf("RLIT ");
                    maybe_real = 0;
                } else if(maybe_hex) {
                    printf("HLIT ");
                    maybe_hex = 0;
                } else {
                    printf("ILIT ");
                }
                maybe_int = 0;
            }
            // NEW*/
            if(maybe_int && !maybe_real)
                printf("ILIT ");
            if(c == '(')
                printf("LPT ");
            if(c == ')')
                printf("RPT ");
            if(c == '{')
                printf("LCB ");
                if(c == '}')
                printf("RCB ");
            if(c == '[')
                printf("LSB ");
            if(c == ']')
                printf("RSB ");
            if(c == ';')
                printf("SEMI ");
            if(c == '*')
                printf("PROD");
            if(c == '/')
                printf("DIV");
            if(c == '%')
                printf("REM");
            if(c == '.') {
                if(maybe_int) {
                    maybe_real++;
                } else {
                    printf("DOT ");
                    maybe_real = 0;
                }
            }
            if(c == ':')
                maybe_assn++;
            if(c == '=' && maybe_assn) {
                printf("ASSIGN ");
                maybe_assn--;
            }
            maybe_int = 0;
            maybe_id = 0;
        }


        if(isdigit(c) && !maybe_id) {
            if(c == '0')
                maybe_hex = 1;
            if(!maybe_hex)
                maybe_int = 1;
        }

        if(c == '+') {
            maybe_incr++;
            if(maybe_incr == 2) {
                printf("INC ");
                maybe_incr = 0;
            }
        }
        if(maybe_incr == 1 && c != '+') {
            printf("PLUS ");
            maybe_incr = 0;
        }
        if(c == '-') {
            maybe_decr++;
            if(maybe_decr == 2) {
                printf("DEC ");
                maybe_incr = 0;
            }
        }
        if(maybe_decr == 1 && c != '-') {
            printf("MINUS ");
            maybe_decr = 0;
        }

    }

    fclose(fp);

    return 0;
}
