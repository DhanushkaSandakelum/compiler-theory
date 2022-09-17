/* definitions */
%{    
    char *val;
    FILE *outputFile;
%}

/* Declare states */
%s A B DEAD  


/*rules */
%%

<INITIAL>[0-9]+ BEGIN A;  { yymore();}
<INITIAL>[a-zA-Z]+ BEGIN B; {yymore();}

<A>[^ \t\r] BEGIN DEAD; {yymore();}
<A>[ \t\r] BEGIN INITIAL; {fprintf(outputFile, "int - %s ", yytext); }

<B>[^ \t\r] BEGIN DEAD; {yymore(); fprintf(outputFile, "err - %s", yytext);}
<B>[ \t\r] BEGIN INITIAL; {fprintf(outputFile, "str - %s ", yytext); }


<DEAD>[^ \t\r] BEGIN DEAD; {yymore(); fprintf(outputFile, "err - %s", yytext);}
<DEAD>[ \t\r] BEGIN INITIAL; 

%%

yywrap() {}

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