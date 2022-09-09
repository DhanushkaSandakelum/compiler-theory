%{
    /* definitions */
%}


/*rules */
%%

[0-9]+          {printf("<INTEGER, %s> ", yytext);}
[a-zA-Z]+       {printf("<STRING, %s> ", yytext);}
[0-9]+.[0-9]+   {printf("<FLOAT, %s> ", yytext);}
[0-9]+.[0-9]+.[0-9]+   {printf("<ERROR, %s> ", yytext);}
[ \t\n]+        /* eat up whitespace */
.               printf( "<ERROR: %s>", yytext );

%%

yywrap() {}

main(argc, argv)
int argc; char **argv; {
    if(argc > 1) {
        FILE *file;
        file = fopen(argv[1], "r");

        if(!file) {printf("Could not open file \n"); exit(1);}
        yyin = file;
        yylex();
    }
    else {
        printf("Invalid arguments\n");
    }
}