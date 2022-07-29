#include<stdio.h>

void main(int argc, char **argv){
    char str[20];
    FILE * fp;
    int c;

    ++argv;
    --argc;

    if(argc > 0){
        fp = fopen(argv[0], "r");
    } else {
        printf("%s\n", "Error: Name of the input file is not given.");
        return;
    }

    int i = 1;
    while (!feof(fp))
    {
        // Read a sequesnce of characters
        // From the file until a space char occurs
        fscanf(fp, "%s", str);
        printf("%d - %s\n", i++, str);
    }

    fclose(fp);
}