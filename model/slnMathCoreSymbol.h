/* 
 * File:   slnMathCoreSymbol.h
 * Author: silenobrito
 *
 * Created on 12 de Agosto de 2013, 13:24
 */

#ifndef SLNMATHCORESYMBOL_H
#define	SLNMATHCORESYMBOL_H

#define SLN_MATH_CORE_DEFAULT_BASE 10.0
/**
 * Base na qual a unidade slnMathCoreSymbol está convertida
 */
#define SLN_MATH_CORE_DEFAULT_DIVISOR 1.0
/**
 * Divisor padrão da unidade slnMathCoreSymbol
 */
#define SLN_MATH_CORE_DEFAULT_EXP 1.0
/**
 * Expoente padrão da unidade slnMathCoreSymbol
 */

#ifdef	__cplusplus
extern "C" {
#endif
    struct slnMathCoreSymbol smcs;

    /**
     * 
     */
    struct slnMathCoreSymbol {
        /**
         * Divisor
         */
        struct slnMathCoreSymbol *divisor;
        /**
         * Base
         */
        struct slnMathCoreSymbol *base;
        /**
         * Expoente
         */
        struct slnMathCoreSymbol *exp;
        /**
         * Número
         */
        double number;
        /**
         * Sinal de positivo ou negativo
         */
        int positive;
        /**
         * Variável
         */
        char *var;
        /**
         * Atribuí um valor número à estrutura
         * @param e struct slnMathCoreSymbol * Estrutura de simbolo matemático
         * @param value double Valor a ser armazenado na estrutura
         * @return Retorna um ponteiro para a estrutura slnMathCoreSymbol ou NULL em caso de falha
         */
        struct slnMathCoreSymbol * (*setNumber)(struct slnMathCoreSymbol *e, double value);
        /**
         * Atribui uma variável à estrutura
         * @param struct slnMathCoreSymbol * Estrutura de simbolo matemático
         * @param value char * Variável a ser amazenada na estrutura
         * @return Retorna um ponteiro para a estrutura slnMathCoreSymbol ou NULL em caso de falha
         */
        struct slnMathCoreSymbol * (*setVariable)(struct slnMathCoreSymbol *e, char *variable);
        /**
         * Libera a memória alocada para a estrutura slnMathCoreSymbol
         * @param e Ponteiro para a astrutura slnMathCoreSymbol a ser liberada
         */
        void (*free)(struct slnMathCoreSymbol * e);
        /**
         * Clona as informações de uma estrutura slnMathCoreSymbol em outra
         * @param e Estrtura de origem struct slnMathCoreSymbol *, estrutura com os elementos a serem clonados
         * @param e Pointeiro para o endeço da estrutura de destino struct slnMathCoreSymbol *, estrutura que irá receber os elementos a serem clonados
         * @return Retorna EXIT_SUCCESS para execução correta ou EXIT_FAILURE em caso de falha
         */
        int(*clone)(struct slnMathCoreSymbol * source, struct slnMathCoreSymbol ** dest);
        /**
         * Destroi os valores da base, divisor, expoente e variável e seus elementos recursivos, mas não destroi a estrutura inicial
         * @param e struct slnMathCoreSymbol * Estrutura a ser limpa
         */
        void (*clear)(struct slnMathCoreSymbol * e);
        /**
         * Cria e inicializa uma estrtura slnMathCoreSymbol
         * @return struct slnMathCoreSymbol * Retorna um ponteiro para a estrutura slnMathCoreSymbol
         */
        struct slnMathCoreSymbol * (*new)();

        /**
         * Atribui um valor númerico e uma variável a estrutura
         */
        struct slnMathCoreSymbol *(*setValue)(struct slnMathCoreSymbol *e, double number, char *variable);
        char *(*toString)(struct slnMathCoreSymbol * e);
    };


    /**
     * Inicializa a estrutura slnMathCoreSymbol
     * @return Retorna EXIT_SUCCESS para execução correta ou EXIT_FAILURE em caso de falha
     */
    int smcs_init();


#ifdef	__cplusplus
}
#endif
#endif	/* SLNMATHCORESYMBOL_H */

