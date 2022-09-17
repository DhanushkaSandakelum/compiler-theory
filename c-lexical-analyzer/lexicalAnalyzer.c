#include<stdio.h>
#include<stdbool.h>  

/* OUTPUT PRINT AND WRITE TO FILE */
// For outputs
void outputToken(char type[], char lexeme[], FILE *outFile) {
    printf("<%s, %s>", type, lexeme);
    fprintf(outFile, "<%s, %s>", type, lexeme);
}


/* REGULAR EXPRESSIONS */
// Regex: Check digit for integer
bool isInteger(char lexeme[]) {
    int i = 0;
 
    while(lexeme[i] != '\0') {
        if(!(isdigit(lexeme[i]) > 0)) {
            return false;
        }
        i++;
    }

    return true;
}

// Regex: Check characters for string
bool isString(char lexeme[]) {
    int i = 0;
 
    while(lexeme[i] != '\0') {
        if(!(isalpha(lexeme[i]) > 0)) {
            return false;
        }
        i++;
    }

    return true;
}

// Regex: IF string contains both digits and characters, THEN print those integers and characters
bool mixMode(char lexeme[], FILE *outputFile) {
    int i = 0;

    int j = 0;
    char temp[50];

    // Making sure that lexeme is not contains a floating point
    // (Otherwise the matching will be stucked)
    i = 0;
    while(lexeme[i] != '\0') {
        if(lexeme[i] == '.') {
            return false;
        }
        i++;
    }
 
    i = 0;
    while(lexeme[i] != '\0') {
        // Subprocedure: Print the integer
        j = 0;
        if(isdigit(lexeme[i]) > 0) {
            while(isdigit(lexeme[i]) > 0) {
                temp[j++] = lexeme[i];
                i++;
            }     
            temp[j] = '\0';  
            if(isInteger(temp)) {
                outputToken("INTEGER", temp, outputFile);
            };
        }

        // Subprocedure: Print the string
        j = 0;
        if(isalpha(lexeme[i]) > 0) {
            while(isalpha(lexeme[i]) > 0) {
                temp[j++] = lexeme[i];
                i++;
            }     
            temp[j] = '\0';  
            if(isString(temp)) {
                outputToken("STRING", temp, outputFile);
            };       
        }
    }

    return true;
}

// Regex: Check digits and only one . for float
bool isFloat(char lexeme[]) {
    int floatingPointCount = 0;
    int i = 0;

    // Count the amount of floating points
    while(lexeme[i] != '\0') {
        if(lexeme[i] == '.') {
            floatingPointCount++;
        }  
        i++;      
    }
    
    
    // IF lexeme has only one floating point then its a valid match ELSE invalid
    if(floatingPointCount == 1) {
        int i = 0;
        while(lexeme[i] != '\0') {
            if (lexeme[i] == '.') {
                i++;
            }
            else if(!(isdigit(lexeme[i]) > 0)) {
                return false;
            }
            i++;
        }
    } 
    else {
        return false;
    }    

    return true;
}


/* DRIVER FUNCTION WITH PASSED ARGUMENTS */
/* Ex:- fileName.exe input.txt output.txt */
int main(argc, argv)
int argc; char **argv;{
    if(argc > 1) {
        // Reading the input file name from input argument 1
        FILE *inputFile;
        inputFile = fopen(argv[1], "r");
        if(!inputFile) {printf("Could not open the input file \n"); return 0;}

        // Reading the output file name from input argument 2
        FILE *outputFile;
        outputFile = fopen(argv[2], "w");
        if(!outputFile) {printf("Could not open the output file \n"); return 0;}

        // Splitting words
        char c;
        char lexeme[50];
        int i;

        while((c = fgetc(inputFile)) != EOF) {
            // If character is a space THEN eat all spaces
            if(isspace(c) > 0) {
                //while(isspace(c = fgetc(inputFile)) > 0);

                // Sentence Lexeme spliting via spaces
                lexeme[i] = '\0';
                i = 0;

                /* TESTING PURPOSES ONLY */
                //printf("\n%s\n", lexeme);

                /* REGEX MATCHING */
                if(isInteger(lexeme)) {
                    outputToken("INTEGER", lexeme, outputFile);
                }
                else if(isFloat(lexeme)) {
                    outputToken("FLOAT", lexeme, outputFile);
                }
                else if(isString(lexeme)) {
                    outputToken("STRING", lexeme, outputFile);
                }
                else if(mixMode(lexeme, outputFile)) {
                    //printf("<MIXMODE, %s> ", lexeme);
                    continue;
                }
                else {
                    outputToken("ERROR", lexeme, outputFile);
                }
            }
            else {
                // Populate lexeme
                lexeme[i++] = c;
            }

            // ungetc(c, inputFile);
        }
        

        fclose(inputFile);
        fclose(outputFile);
    }
    else {
        printf("Invalid arguments\n");
    }
}