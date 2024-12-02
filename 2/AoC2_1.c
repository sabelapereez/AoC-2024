#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    // Opening the input file
    FILE *input = fopen("AoC2_input.txt", "r");
    if (input == NULL){
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    // Reading the lines if the input file
    char bin[50];
    char *temp = (char *)malloc(8);
    int a, b, safeReports = 0;
    
    while(fgets(bin, sizeof(bin), input) != NULL){
        // Process the line
        sscanf(bin, " %d %d", &a, &b);
        int isSafe = 1;
        int increasing = (b > a) ? 1 : 0;
        temp = strtok(bin, " ");
        temp = strtok(NULL, " ");
        while(temp != NULL){
            sscanf(temp, " %d", &b);
            // Process the number
            if((abs(b-a) < 1) || (abs(b-a) > 3)){
                isSafe = 0;
                break;
            }
            if(increasing && (b < a)){
                isSafe = 0;
                break;
            }
            if(!increasing && (b > a)){
                isSafe = 0;
                break;
            }
            a = b;
            temp = strtok(NULL, " ");
        }
        if(isSafe){
            safeReports++;
        }
    } 

    // Printing the results
    printf("The safe reports are %d.\n", safeReports);

    return 0;
}