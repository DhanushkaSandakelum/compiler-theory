/* definitions */
%{     
    char *val;
    FILE *outputFile;
%}

/* Declare states */
%s A B DEAD  

/* Rules to find out integers, strings and print error if not */
/*
    1. Check WORD contains numbers 0-9 --> Then print <int - WORD>
    2. Check WORD contains characters a-z or A-Z --> Then print <str - WORD>
    3. Check WORD not matches any of those 2 conditions --> Then print <err - WORD>
*/
/*rules */
%%

<INITIAL>[0-9]+ BEGIN A;  { yymore();}
<INITIAL>[a-zA-Z]+ BEGIN B; {yymore();}

<A>[^ \t\r] BEGIN DEAD; {yymore();}
<A>[ \t\r] BEGIN INITIAL; {fprintf(outputFile, "int - %s ", yytext); }

<B>[^ \t\r] BEGIN DEAD; {yymore();}
<B>[ \t\r] BEGIN INITIAL; {fprintf(outputFile, "str - %s ", yytext); }

<DEAD>[^ \t\r] BEGIN DEAD; {yymore();}
<DEAD>[ \t\r] BEGIN INITIAL; { fprintf(outputFile, "err - %s", yytext);}

%%

yywrap() {}

/*
    1. Read input and output file
    2. Specify input options as read and output option as write
    3. Perform lexical analysis and read file and populate the content
*/
main(argc, argv)
int argc; char **argv;{
    if(argc > 1) {
        // Reading the input file name from input argument 1
        FILE *file;
        file = fopen(argv[1], "r");
        if(!file) {printf("Could not open the input file \n"); exit(1);}
        yyin = file;

        // Reading the output file name from input argument 2
        outputFile = fopen(argv[2], "w");
        if(!outputFile) {printf("Could not open the output file \n"); exit(1);}

        // Run lex rules to perform regex matches
        yylex();
    }
    else {
        printf("Invalid arguments\n");
    }
}