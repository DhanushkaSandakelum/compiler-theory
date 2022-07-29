#include<stdio.h>
#include<string.h>

int bufferLength = 255;
char buffer[255];

void main(int argc, char **argv){
    FILE *fp;

    ++argv;
    --argc;
    if(argc > 0){
        fp = fopen(argv[0], "r");
    } else {
        printf("%s\n", "Error: Name of the input file is not given");
        return;
    }

    // Read lines
    while (fgets(buffer, bufferLength, fp))
    {
        printf("%s", buffer);
    }
    
    return;
}