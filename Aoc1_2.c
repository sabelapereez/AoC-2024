#include <stdio.h>
#include <stdlib.h>  

int main(int argc, char *argv[]){
    int similarityScore = 0;

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

    // Calculate the similarity score between the lines
    for (int i = 0; i < lines; i++){
        int num = 0;
        for(int j = 0; j < lines; j++){
            if (column1[i] == column2[j]){
                num++;
            }
        }
        similarityScore += num*column1[i];
    }

    printf("The similarity score is: %d\n", similarityScore);

    return 0;
}