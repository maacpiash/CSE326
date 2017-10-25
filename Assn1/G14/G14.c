#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 65535

char* code;

int symbol(char c);

int main(void)
{
    FILE* fp = fopen("input.txt", "r");
    int index = 0;
    int total = 0;
    
    code = malloc(sizeof(char) * MAXLEN);
    char c;

    for(c = fgetc(fp); c != EOF; c = fgetc(fp)) {
        code[total++] = c;
    }
    fclose(fp);

    int id = 0;

    int maybe_int = 0;
    int maybe_real = 0;
    int donewithreal = 0;
    int maybe_id = 0;
    int maybe_char = 0;
    int maybe_str = 0;
    int maybe_hex = 0;

    int maybe_incr = 0;
    int maybe_decr = 0;
    int maybe_assn = 0;

    while (index < total) {
        //printf("\n%c\t", code[index]);

        if(!isdigit(code[index]) && code[index] != '.') {
            if(maybe_int) {
                printf("ILIT ");
                maybe_int = 0;
                maybe_real = 0;
                index++;
                continue;
            }
        }

        if(code[index] == ' ') {
            index++;
            continue;
        }
        if(code[index] == '\t') {
            printf("TAB ");
            index++;
            continue;
        }
        if(code[index] == '\r') {
            printf("CR ");
            index++;
            continue;
        }
        if(code[index] == '\\') {
            printf("BKSL ");
            index++;
            continue;
        }
        if(code[index] == '.') {
            if(!maybe_int) { // No digit before DOT
                printf("DOT ");
                index++;
                continue;
            } else {
                maybe_int = 0;
                maybe_real = 1;
                printf("RLIT ");
            }
        }

        if(isalpha(code[index]) || code[index] == '_') {
            if(code[index] == 'i' && code[index + 1] == 'f') {
                if(!isalpha(code[index + 2]) && !isdigit(code[index + 2]) && code[index + 2] != '_') {
                    printf("IF ");
                    index += 2;
                    continue;
                }
            } else if(code[index] == 'f' && code[index + 1] == 'o' && code[index + 2] == 'r') {
                if(!isalpha(code[index + 3]) && !isdigit(code[index + 3]) && code[index + 3] != '_') {
                    printf("FOR ");
                    index += 3;
                    continue;
                }
            } else if(code[index] == 'e' && code[index + 1] == 'l' && code[index + 2] == 's' && code[index + 3] == 'e') {
                if(!isalpha(code[index + 4]) && !isdigit(code[index + 5]) && code[index + 6] != '_') {
                    printf("ELSE ");
                    index += 4;
                    continue;
                }
            } else if(code[index] == 'i' && code[index + 1] == 'n' && code[index + 2] == 't') {
                if(!isalpha(code[index + 3]) && !isdigit(code[index + 3]) && code[index + 3] != '_') {
                    printf("INT ");
                    index += 3;
                    continue;
                }
            } else if(code[index] == 'c' && code[index + 1] == 'h' && code[index + 2] == 'a'  && code[index + 3] == 'r') {
                if(!isalpha(code[index + 4]) && !isdigit(code[index + 4]) && code[index + 4] != '_') {
                    printf("CHAR ");
                    index += 4;
                    continue;
                }
            } else if(code[index] == 'v' && code[index + 1] == 'o' && code[index + 2] == 'i'  && code[index + 3] == 'd') {
                if(!isalpha(code[index + 4]) && !isdigit(code[index + 4]) && code[index + 4] != '_') {
                    printf("VOID ");
                    index += 4;
                    continue;
                }
            } else if(code[index] == 'r' && code[index + 1] == 'e' && code[index + 2] == 'a'  && code[index + 3] == 'l') {
                if(!isalpha(code[index + 4]) && !isdigit(code[index + 4]) && code[index + 4] != '_') {
                    printf("REAL ");
                    index += 4;
                    continue;
                }
            } else if(code[index] == 'r' && code[index + 1] == 'e' && code[index + 2] == 't'  && code[index + 3] == 'u'  && code[index + 4] == 'r'  && code[index + 5] == 'n') {
                if(!isalpha(code[index + 6]) && !isdigit(code[index + 6]) && code[index + 6] != '_') {
                    printf("RETURN ");
                    index += 6;
                    continue;
                }
            } else {
                printf("ID%d ", ++id);
                while(isalpha(code[index]) || isdigit(code[index]) || code[index] == '_')
                    index++;
                continue;
            }

        } /*if not alpha*/
        else if(symbol(code[index])) {
            index++;
            continue;
        } else if(code[index] == '+') {
            if(code[index + 1] == '+') {
                printf("INC ");
                index += 2;
            } else {
                printf("PLUS ");
                index++;
            }

        }  else if(code[index] == '-') {
            if(code[index + 1] == '-') {
                printf("DEC ");
                index += 2;
            } else {
                printf("MINUS ");
                index++;
            }
        }

        else if(code[index] == '0' && code[index + 1] == 'x') {
            printf("HLIT ");
            index += 2;
            while(isdigit(code[index]) || code[index] == 'a' || code[index] == 'b' || code[index] == 'c'
                  || code[index] == 'd' || code[index] == 'e' || code[index] == 'f')
                    index++;
            continue;
        } else if(isdigit(code[index])) {
            if(!maybe_int && !maybe_real)
                maybe_int = 1;
            index++;
            //continue;
        } else if(code[index] == ':' && code[index + 1] == '=') {
            printf("ASSIGN ");
            index += 2;
            continue;
        } else if(code[index] == '"') {
            while(index < total) {
                index++;
                if(code[index] == '"') {
                    maybe_str = 1;
                    break;
                }
            }
            if (!maybe_str) {
                printf("DOUBLEQ ");
                index++;
            } else {
                printf("SLIT ");
                index++;
            }
            continue;

        } else if(code[index] == 39) {
            if(code[index + 2] == 39) {
                printf("CLIT ");
                index += 3;
            } else if(code[index]) {
                printf("SINGLEQ ");
                index++;
            }
            continue;
        } else {
            
            printf("ERROR ");
            //printf("\nProblem at character: %d\n", index);
            return 1;
        }
    }
    return 0;

}

int symbol(char c)
{
    if(c == '(')
        return printf("LPT ");
    if(c == ')')
        return printf("RPT ");
    if(c == '{')
        return printf("LCB ");
    if(c == '}')
        return printf("RCB ");
    if(c == '[')
        return printf("LSB ");
    if(c == ']')
        return printf("RSB ");
    if(c == ';')
        return printf("SEMI ");
    if(c == '*')
        return printf("PROD");
    if(c == '/')
        return printf("DIV");
    if(c == '%')
        return printf("REM");
    if(c == '\n' && c != ' ')
        return printf("NL\n");
    if(c == ';')
        return printf("SEMI ");
    return 0;

}

