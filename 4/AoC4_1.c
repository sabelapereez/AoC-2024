#include <stdio.h>
#include <stdlib.h>

int check(char wordSearch[140][140], int i, int j, int stepi, int stepj){
    if (wordSearch[i][j] == 'X'){
        i += stepi;
        j += stepj;
        if(i >= 140 || j >= 140 || i < 0 || j < 0){
            return 0;
        }
        if(wordSearch[i][j] == 'M'){
            i += stepi;
            j += stepj;
            if(i >= 140 || j >= 140 || i < 0 || j < 0){
                return 0;
            }
            if(wordSearch[i][j] == 'A'){
                i += stepi;
                j += stepj;
                if(i >= 140 || j >= 140 || i < 0 || j < 0){
                    return 0;
                }
                if(wordSearch[i][j] == 'S'){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[]){
    // Opening the input file
    FILE *input = fopen("AoC4_input.txt", "r");
    //FILE *input = fopen("p.txt", "r");
    if (input == NULL){
        printf("Error: Unable to open the file\n");
        exit(-1);
    }

    // Reading the file
    char wordSearch[140][140];
    int a = 0;
    while(fgets(wordSearch[a], sizeof(wordSearch), input) != NULL){
        a++;
    }

    // Looking for the word
    int word = 0;
    for (int i = 0; i < 140; i++){
        for (int j = 0; j < 140; j++){
            if (check(wordSearch, i, j, 1, 0)){
                word++;
            }
            if (check(wordSearch, i, j, -1, 0)){
                word++;
            }
            if(check(wordSearch, i, j, 0, 1)){
                word++;
            }
            if(check(wordSearch, i, j, 0, -1)){
                word++;
            }
            if(check(wordSearch, i, j, 1, 1)){
                word++;
            }
            if(check(wordSearch, i, j, -1, -1)){
                word++;
            }
            if(check(wordSearch, i, j, 1, -1)){
                word++;
            }
            if(check(wordSearch, i, j, -1, 1)){
                word++;
            }
        }
    }

    // Printing the result
    printf("The result is: %d\n", word);

    return 0;
}