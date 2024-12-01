/*
 * We could just do the difference between the numbers in the same line,
 * adding them in a variable to know the distances between both lines.
 * However, we'll do it as we are requested to.
 */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}    

int main(int argc, char *argv[]){
    // Opening the input file
    FILE *input = fopen("AoC1_input.txt", "r");
    if (input == NULL){
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    // Reading the lines if the input file
    char bin[20];
    int lines = 0;
    while(fgets(bin, sizeof(bin), input) != NULL){
        lines++;
    }   

    // Create the arrays to store the numbers
    int column1[lines];
    int column2[lines];

    // Reread the file to store the numbers in the arrays
    rewind(input);
    for (int i = 0; i < lines; i++){
        fscanf(input, "%d %d", &column1[i], &column2[i]);
    }

    // Order the arrays
    qsort(column1, lines, sizeof(int), compare);
    qsort(column2, lines, sizeof(int), compare);

    // Calculate the distance between the lines
    int distance = 0;
    for (int i = 0; i < lines; i++){
        distance += abs(column1[i] - column2[i]);
    }

    printf("The distance between the lines is: %d\n", distance);

    return 0;
}