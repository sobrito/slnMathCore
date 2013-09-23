/* 
 * File:   slnMathCoreFunctions.h
 * Author: silenobrito
 *
 * Created on 12 de Agosto de 2013, 16:30
 */

#ifndef SLNMATHCOREFUNCTIONS_H
#define	SLNMATHCOREFUNCTIONS_H

#include <model/slnMathCoreSymbol.h>

#ifdef	__cplusplus
extern "C" {
#endif
    struct slnMathCoreFunctions smcf;

    struct slnMathCoreFunctions {
        /**
         * Verifica se as várias são iguais, verifica apenas a váriável, ignorando informações de base, divisor e expoente
         * @param a struct slnMathCoreSymbol * Elemento a
         * @param b struct slnMathCoreSymbol * Elemento b
         * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
         */
        int (*variableIsEq)(struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        /**
         * Verifica se os divisores são iguais, verifica o divisor , ignorando informações como variáveis, base e expoente
         * @param a struct slnMathCoreSymbol * Elemento a
         * @param b struct slnMathCoreSymbol * Elemento b
         * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
         */
        int (*divisorIsEq)(struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        /**
         * Verifica se as bases são iguais, verifica apenas a base, ignorando informações como variáveis, divisor e expoente
         * @param a struct slnMathCoreSymbol * Elemento a
         * @param b struct slnMathCoreSymbol * Elemento b
         * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
         */
        int (*baseIsEq)(struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b);
        /**
         * Verifica se os expoentes são iguais, verifica o expoente , ignorando informações como variáveis, base e divisor
         * @param a struct slnMathCoreSymbol * Elemento a
         * @param b struct slnMathCoreSymbol * Elemento b
         * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
         */
        int (*expIsEq)(struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b);
        /**
         * Verifica se os termos são iguais, realiza a comparação completa de  variáveis, base, divisor e expoente
         * @param a struct slnMathCoreSymbol * Elemento a
         * @param b struct slnMathCoreSymbol * Elemento b
         * @return int Retorna EXIT_SUCCESS se forem iguais ou EXIT_FAILURE se forem diferentes
         */
        int (*termIsEq)(struct slnMathCoreSymbol *a, struct slnMathCoreSymbol * b);
        int (*mult)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        int (*sqrt)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        /**
         * Realiza a soma de dois elementos do tipo struct slnMathCoreSymbol *
         * @param result struct slnMathCoreSymbol * Resultado
         * @param a struct slnMathCoreSymbol * Primeiro termo
         * @param b struct slnMathCoreSymbol * Segundo termo
         * @return
         */
        int (*add)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        /**
         * Realiza a subtração de dois elementos do tipo struct slnMathCoreSymbol *
         * @param result struct slnMathCoreSymbol * Resultado
         * @param a struct slnMathCoreSymbol * Minuendo
         * @param b struct slnMathCoreSymbol * Subtraendo
         * @return
         */
        int (*sub)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        int (*div)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        int (*pow)(struct slnMathCoreSymbol *result, struct slnMathCoreSymbol *a,
                struct slnMathCoreSymbol * b);
        int (*isPrime)(double number);
        int (*stringToFrac)(long int *dividend, long int *divisor, char *str);
        int (*doubleCompareTo)(double a, double b);
        double (*gcd)(double a, double b);
        double (*lcd)(double a, double b);
    };

    int smcf_init();

#ifdef	__cplusplus
}
#endif
int slnMathCoreFunctionsInit(struct slnMathCoreFunctions );
#endif	/* SLNMATHCOREFUNCTIONS_H */

