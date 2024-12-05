#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]){
    // Opening the input file
    FILE *input = fopen("AoC3_input.txt", "r");
    if (input == NULL){
        printf("Error: Unable to open the file\n");
        exit(-1);
    }

    // Compiling the regular expression
    char pattern[] = "mul\\([0-9]+,[0-9]+\\)";
    regex_t regex;
    regmatch_t match;
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        printf("Error compiling the regular expression\n");
        exit(-1);
    }

    // Reading and processing the lines
    char bin[10000];
    int res = 0;
    while(fgets(bin, sizeof(bin), input) != NULL){
        char *cursor = bin;
        while (regexec(&regex, cursor, 1, &match, 0) == 0) {
            int start = match.rm_so;
            int end = match.rm_eo;
            int a, b;
            sscanf(cursor + start, "mul(%d,%d)", &a, &b);
            res += a * b;
            cursor += end;
        }
    }

    // Printing the result
    printf("The result is: %d\n", res);

    // Free the regex resources
    regfree(&regex);

    return 0;
}