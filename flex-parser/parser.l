%{
    /* definitions */
    char *val;
    FILE *outputFile;
%}


/*rules */
%%
[0-9]+          {fprintf(outputFile, "int - %s ", yytext);}
[a-zA-Z]+       {fprintf(outputFile, "str - %s ", yytext); }
[ \t\n]+        /* eat up whitespace */
.               {fprintf(outputFile, "err - %s ", yytext); }

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