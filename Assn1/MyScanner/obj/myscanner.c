#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 65535

int main(void)
{
    FILE* fp = fopen("input.txt", "r");
    int index = 0;
    int total = 0;
    char* code = malloc(sizeof(char) * MAXLEN);
    for(c = fgetc(fp); c != EOF; c = fgetc(fp)) {}




    int maybe_int = 0;
    int maybe_real = 0;
    int maybe_id = 0;

    int maybe_incr = 0;
    int maybe_decr = 0;
    int maybe_assn = 0;
    int maybe_hex = 0;

    fclose(fp);
}
