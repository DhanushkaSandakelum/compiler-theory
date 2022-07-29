// After compiler type readFile file1.txt at cmd
#include<stdio.h>

FILE *fp;

void read_code() {
    char code_line[100];
    int code_length = 100;
    printf("Reading the code \n");
    while (fgets(code_line, code_length, fp))
    {
        printf("%s", code_line);
    }    
}

void main(int argc, char **argv){
    ++argv;
    --argc;
    if(argc > 0){
        fp = fopen(argv[0], "r");
    } else {
        printf("%s\n", "Error: Input file name missing");
        return;
    }

    read_code();

    fclose(fp);
    return;
}