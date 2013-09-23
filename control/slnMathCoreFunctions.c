#include <control/slnMathCoreFunctions.h>
#include <control/slnString.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Verifica se as várias são iguais, verifica apenas a váriável, ignorando informações de base, divisor e expoente
 * @param a struct slnMathCoreSymbol * Elemento a
 * @param b struct slnMathCoreSymbol * Elemento b
 * @return int  Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
 */
int slnMathCoreFunctionsVariableIsEq(struct slnMathCoreSymbol *a,
        struct slnMathCoreSymbol * b) {
    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }
    if (a->var == NULL && b->var == NULL) {
        return EXIT_SUCCESS;
    }
    if (a->var == NULL || b->var == NULL) {
        return EXIT_FAILURE;
    }
    return strcmp(a->var, b->var) == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

/**
 * Verifica se os divisores são iguais, verifica o divisor , ignorando informações como variáveis, base e expoente
 * @param a struct slnMathCoreSymbol * Elemento a
 * @param b struct slnMathCoreSymbol * Elemento b
 * @return int  Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
 */
int slnMathCoreFunctionsDivisorIsEq(struct slnMathCoreSymbol *a,
        struct slnMathCoreSymbol * b) {
    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }
    if (a->divisor == NULL && b->divisor == NULL) {
        return EXIT_SUCCESS;
    }
    if (a->divisor == NULL || b->divisor == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.variableIsEq(a->divisor, b->divisor) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (a->divisor->number != b->divisor->number && a->divisor->var == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->divisor->exp, b->divisor->exp) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->divisor->base, b->divisor->base) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return smcf.divisorIsEq(a->divisor, b->divisor);
}

/**
 * Verifica se as bases são iguais, verifica apenas a base, ignorando informações como variáveis, divisor e expoente
 * @param a struct slnMathCoreSymbol * Elemento a
 * @param b struct slnMathCoreSymbol * Elemento b
 * @return int  Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
 */
int slnMathCoreFunctionsBaseIsEq(struct slnMathCoreSymbol *a,
        struct slnMathCoreSymbol * b) {
    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }
    if (a->base == NULL && b->base == NULL) {
        return EXIT_SUCCESS;
    }
    if (a->base == NULL || b->base == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.variableIsEq(a->base, b->base) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (a->base->number != b->base->number && a->base->var == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->base->exp, b->base->exp) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->base->divisor, b->base->divisor) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return (smcf.baseIsEq(a->base, b->base) == EXIT_FAILURE);

}

/**
 * Verifica se os expoentes são iguais, verifica o expoente , ignorando informações como variáveis, base e divisor
 * @param a struct slnMathCoreSymbol * Elemento a
 * @param b struct slnMathCoreSymbol * Elemento b
 * @return int  Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
 */
int slnMathCoreFunctionsExpIsEq(struct slnMathCoreSymbol *a,
        struct slnMathCoreSymbol * b) {
    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }
    if (a->exp == NULL && b->exp == NULL) {
        return EXIT_SUCCESS;
    }
    if (a->exp == NULL || b->exp == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.variableIsEq(a->exp, b->exp) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (a->exp->number != b->exp->number && a->exp->var == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->exp->divisor, b->exp->divisor) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (smcf.termIsEq(a->exp->base, b->exp->base) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return smcf.divisorIsEq(a->exp, b->exp);
}

/**
 * Verifica se os termos são iguais, realiza a comparação completa de  variáveis, base, divisor e expoente 
 * @param a struct slnMathCoreSymbol * Elemento a
 * @param b struct slnMathCoreSymbol * Elemento b
 * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
 */
int slnMathCoreFunctionsTermIsEq(struct slnMathCoreSymbol *a,
        struct slnMathCoreSymbol * b) {
    if (a == NULL || b == NULL) {
        return EXIT_FAILURE;
    }
    if (smcf.variableIsEq(a, b) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (smcf.baseIsEq(a, b) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    if (smcf.divisorIsEq(a, b) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    return smcf.expIsEq(a, b);

}

int slnMathCoreFunctionsMult(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (a == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int slnMathCoreFunctionsSqrt(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (a == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * Realiza a soma de dois elementos do tipo struct slnMathCoreSymbol *
 * @param result struct slnMathCoreSymbol * Resultado
 * @param a struct slnMathCoreSymbol * Primeiro termo
 * @param b struct slnMathCoreSymbol * Segundo termo
 * @return 
 */
int slnMathCoreFunctionsAdd(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (smcf.termIsEq(a, b) == EXIT_SUCCESS) {
        smcs.clone(a, &result);
        result->number += b->number;

        smcs.clear(a);
        smcs.clear(b);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

/**
 * Realiza a subtração de dois elementos do tipo struct slnMathCoreSymbol *
 * @param result struct slnMathCoreSymbol * Resultado
 * @param a struct slnMathCoreSymbol * Minuendo
 * @param b struct slnMathCoreSymbol * Subtraendo
 * @return 
 */
int slnMathCoreFunctionsSub(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (smcf.termIsEq(a, b) == EXIT_SUCCESS) {
        smcs.clone(a, &result);
        result->number -= b->number;

        smcs.clear(a);
        smcs.clear(b);

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}

int slnMathCoreFunctionsDiv(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (a == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int slnMathCoreFunctionsPow(struct slnMathCoreSymbol *result,
        struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b) {
    if (a == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int slnMathCoreFunctionsDoubleCompareTo(double a, double b) {
    if (a == b) {
        return 0;
    }
    return a > b ? -1 : 1;
}

/**
 * Algoritmo de Euclides para encontrar o M�ximo divisor comum
 */
double slnMathCoreFunctionsCGD(double a, double b) {
    double divisor = a > b ? a : b;
    double dividend = a > b ? b : a;
    double z;
    do {
        z = fmod(dividend, divisor);
        dividend = divisor;
        divisor = z;
    } while (z != 0);

    return dividend;
}

/**
 * Converte uma String que estiver no formato decimal para fra��o
 */
int slnMathCoreFunctionsStringToFrac(long int *dividend, long int *divisor, char *str) {
    char *p1 = NULL;
    char *p2 = str == NULL ? NULL : strdup(str);

    if (str == NULL) {
        return EXIT_FAILURE;
    }

    if ((p1 = strchr(p2, '.')) == NULL) {
        p1 = strchr(p2, ',');
    }
    if (p1 != NULL) {
        *p1 = '\0';
    }

    (*dividend) = atol(String.format("%d%d", p2, p1 == NULL ? "" : p1 + 1));
    (*divisor) = atol(String.padRight("1", '0', p1 == NULL ? 1 : strlen(p1 + 1)));
    return EXIT_SUCCESS;

}

int slnMathCoreFunctionsIsPerfectPower(double n) {
    int a_min = 2;
    int a_max;
    int b_min = 2;
    int b_max = log2(n);
    int i, j;

    for (i = a_min; i != a_max; i++) {
        for (j = b_min; j != b_max; j++) {
            if (log(j) == n) {
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;

}

int slnMathCoreFunctionsIsPower(double n) {
    double a;
    //let a and n
    //if n=1 then a
    //else
    //  if n is even then (a^2)^\frac{n}{2}
    //  else a*a^(n-1) 
    if (n == 1) {
        return 1;
    }
    if (fmod(n, 2) == 0) {
        return a * pow(a, n - 1);
    }
    return pow(a, sqrt(pow(2, n)));
}

double slnMathCoreFunctionsLCD(double a, double b) {
    return a * b / smcf.gcd(a, b);
}

unsigned int slnMathCoreFunctionsGCD2(unsigned int x, unsigned int y) {
    unsigned int cf2;
    if (x == 0) {
        return y;
    }
    if (y == 0) {
        return x;
    }
    //    cf2 = ctz(x | y);
    //    x >>= ctz(x);
    while (1) {
        //        y >>= ctz(y);

        if (x == y) {
            break;
        }
        if (x > y) {
            //            std::swap(x, y);
        }
        if (x == 1) {
            break;
        }
        y -= x;
    }
    return x << cf2;
}

/**
 * Algoritmo de AKS
 * @see http://www.lockabit.coppe.ufrj.br/sites/lockabit.coppe.ufrj.br/files/publicacoes/lockabit/aks.pdf
 * @see http://www.bcc.ufla.br/monografias/2010/CLEBER_JOSE_BATISTA_JUNIOR.pdf
 * @see http://www.inf.ufpr.br/andre/files/Isis2008.pdf
 */
int slnMathCoreFunctionsIsPrime(double number) {

    double n = number;
    double a, b;
    double r;
    double q;
    double x;
    /**
     * Input: Integer n > 1
     1. if (n = ab with b > 1) then output COMPOSITE;
     2. r := 2;
     3. while (r < n) {
     4. if (gcd(n,r) is not 1) then output COMPOSITE;
     5. if (r is prime greater than 2) then {
     6. let q be the largest factor of r-1;
     7. if (q > 4sqrt(r)log n) and not(n(r-1)/q = 1 (mod r)) then
     8. break;
     9. r := r + 1;
     10. }
     11. for a := 1 to 2sqrt(r)log n {
     12. if not( (x-a)n = (xn-a) (mod xr-1,n))then output COMPOSITE;
     13. }
     14. output PRIME;
     */

    if (n <= 1) {
        return EXIT_FAILURE;
    }

    int sup = log(n) / log(2);
    for (b = 1; b != sup; b++) {

    }

    if (n == pow(a, b) && b > 1) {
        return EXIT_FAILURE;
    }
    r = 2;
    while (r < n) {
        /**
         * smcf.gcd Fun��o criada para calcular o MMC, baseada no Algoritmo de Euclides
         */
        if (smcf.gcd(n, r) != 1) {
            return EXIT_FAILURE;
        }
        /**
         * @todo Linha 5???
         * @todo Linha 6???
         */

        if (((q > 4 * sqrt(r) * log(n)) && fmod(pow(n, (r - 1) / q), r)) != 1) {
            break;
        }
        r += 1;
    }

    for (a = 1; a < 2 * sqrt(r) * log(n); a++) {
        if (pow(x - a, n) != ((pow(x, n) - a) * fmod((pow(x, r) - 1), n))) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }
}

int slnMathCoreFunctionsInit(struct slnMathCoreFunctions e) {

    e.doubleCompareTo = slnMathCoreFunctionsDoubleCompareTo;
    e.isPrime = slnMathCoreFunctionsIsPrime;
    e.variableIsEq = slnMathCoreFunctionsVariableIsEq;
    e.divisorIsEq = slnMathCoreFunctionsDivisorIsEq;
    e.baseIsEq = slnMathCoreFunctionsBaseIsEq;
    e.termIsEq = slnMathCoreFunctionsTermIsEq;
    e.expIsEq = slnMathCoreFunctionsExpIsEq;
    e.mult = slnMathCoreFunctionsMult;
    e.sqrt = slnMathCoreFunctionsSqrt;
    e.add = slnMathCoreFunctionsAdd;
    e.sub = slnMathCoreFunctionsSub;
    e.div = slnMathCoreFunctionsDiv;
    e.pow = slnMathCoreFunctionsPow;
    e.gcd = slnMathCoreFunctionsCGD;
    e.lcd = slnMathCoreFunctionsLCD;

    return EXIT_SUCCESS;
}

/**
 * Inicia a biblioteca de funções matemática
 * @return Retorna EXIT_SUCCESS se foi iniciada corretamente ou EXIT_FAILURE houve falha ao iniciar a biblioteca
 */
int smcf_init() {
    return slnMathCoreFunctionsInit(smcf);
}
