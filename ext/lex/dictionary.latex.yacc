%{
#include <control/slnMathCoreFunctions.h>
#include <model/slnMathCoreSymbol.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef	__cplusplus
extern "C" {
#endif
    int yyerror(const char *message);
    int yylex(void);
#ifdef	__cplusplus
}
#endif

%}

%token  OPEN_PARENTHESIS CLOSE_PARENTHESIS OPEN_SQUARE_BRACKETS CLOSE_SQUARE_BRACKETS OPEN_CURLY_BRACKETS CLOSE_CURLY_BRACKETS
%start  expr
%left   EQ LEQ GEQ NEQ APPROX
%left   ADD SUB
%left   POW SQRT
%left   MULT DIV
%right  PERCENT FRAC
%right  LATEX_SUM LATEX_PROD
%right  FAT
%left   LATEX_VAR PI VAR REAL INFINITY
%%
expr        :   OPEN_PARENTHESIS expr CLOSE_PARENTHESIS {}
            |   OPEN_SQUARE_BRACKETS expr CLOSE_SQUARE_BRACKETS {}
            |   OPEN_CURLY_BRACKETS expr CLOSE_CURLY_BRACKETS {}
            |   expr EQ expr {}
            |   expr LEQ expr {}
            |   expr GEQ expr {}
            |   expr NEQ expr {}
            |   expr APPROX expr {}
            |   expr ADD expr {}
            |   expr SUB expr {}
            |   expr POW expr {}
            |   expr SQRT expr {}
            |   expr MULT expr {}
            |   expr DIV expr {}
            |   expr PERCENT {}
            |   FRAC OPEN_CURLY_BRACKETS expr CLOSE_CURLY_BRACKETS OPEN_CURLY_BRACKETS expr CLOSE_CURLY_BRACKETS{}
            |   LATEX_SUM OPEN_CURLY_BRACKETS VAR EQ POW expr CLOSE_CURLY_BRACKETS expr {}
            |   LATEX_PROD OPEN_CURLY_BRACKETS VAR EQ POW expr CLOSE_CURLY_BRACKETS expr {}
            |   expr FAT {}
            |   LATEX_VAR {}
            |   PI {}
            |   VAR {}
            |   REAL {}
            |   INFINITY {}
;

%%

int yyerror(const char *message) {
    fprintf(stderr, "%s\n", message);
    return EXIT_FAILURE;
}

int main(int argc, char ** argv) {
    if(smcf_init() == EXIT_FAILURE){
        return yyerror("Falha ao iniciar biblioteca de funcao");
    }
    if(smcs_init() == EXIT_FAILURE){
            return yyerror("Falha ao iniciar biblioteca de manipulacao");
    }
    return yyparse();
}
