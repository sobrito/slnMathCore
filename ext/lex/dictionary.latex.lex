%{
#include "dictionary.latex.tab.h"
#include <control/slnMathCoreFunctions.h>
#include <model/slnMathCoreSymbol.h>
#include <stdlib.h>
#include <stdio.h>

#define _POSIX_SOURCE 1

int ival;
char *sval;
double dval;
%}

%option nounput
%option noinput

e_letter        [a-zA-Z]
e_var           {e_letter}+
e_number        [0-9]
e_int           {e_number}+
e_real          {e_int}\.{e_int}
latex_vars      (\\alpha|\\beta|\\gamma|\\delta|\\epsilon|\\zeta|\\eta|\\varepsilon|\\theta|\\iota|\\kappa|\\vartheta|\\lambda|\\mu|\\nu|\\xi|\\rho|\\sigma|\\tau|\i|\\chi|\\psi|\\Theta|\\Lambda|\\Xi|\\Sigma|\\Upsilon|\\Phi|\\Psi|\\Omega)
e_pi            (\\Pi|\\pi|pi)
e_pow           (\*\*|\^)
e_sum           (\+|\\sum)
e_mult          (\*|\\mult)
e_percent       (\\%|%)
e_div           (\\div|\/)
%%
\(              return OPEN_PARENTHESIS;
\)              return CLOSE_PARENTHESIS;
\[              return OPEN_SQUARE_BRACKETS;
\]              return CLOSE_SQUARE_BRACKETS;
\{              return OPEN_CURLY_BRACKETS;
\}              return CLOSE_CURLY_BRACKETS;
\+              return ADD;
\-              return SUB;
\*              return MULT;
\\frac          return FRAC;
\\sum_          return LATEX_SUM;
{e_pow}         return POW;
(\\eq|=)        return EQ;
(\\leq|<=)      return LEQ;
(\\geq|>=)      return GEQ;
(\\neq|<>)      return NEQ;
(\\approx|~=)   return APPROX;
{e_percent}     return PERCENT;
\!              return FAT;
\infty          return INFINITY;
{latex_vars}    return LATEX_VAR;
{e_pi}          return PI;
{e_real}        return REAL;
{e_var}         return VAR;
{e_div}         return DIV;
.               ;
%%
