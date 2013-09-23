#include <model/slnMathCoreSymbol.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include <control/slnMathCoreFunctions.h>
#include <control/slnString.h>

char *slnMathCoreSymbolToString(struct slnMathCoreSymbol * e) {
    if (e == NULL) {
        return NULL;
    }

    return String.format("{\\frac{%0.lf}{%s}}%s^{%s}"
            , e->number
            , e->divisor == NULL ? "1" : smcs.toString(e->divisor)
            , e->var == NULL ? "" : e->var
            , e->exp == NULL ? "1" : smcs.toString(e->exp)
            );
}

/**
 * Cria e inicializa uma estrtura slnMathCoreSymbol
 * @return struct slnMathCoreSymbol * Retorna um ponteiro para a estrutura slnMathCoreSymbol
 */
struct slnMathCoreSymbol * slnMathCoreSymbolNew() {
    struct slnMathCoreSymbol *e = NULL;
    if ((e = (struct slnMathCoreSymbol *) malloc(sizeof *e)) == NULL) {
        perror("malloc");
        return NULL;
    }
    e->base = NULL;
    e->divisor = NULL;
    e->exp = NULL;
    e->number = 0.0;
    e->positive = 1;
    e->var = NULL;

    return e;
}

/**
 * Atribuí um valor número à estrutura
 * @param e struct slnMathCoreSymbol * Estrutura de simbolo matemático
 * @param value double Valor a ser armazenado na estrutura
 * @return Retorna um ponteiro para a estrutura slnMathCoreSymbol ou NULL em caso de falha
 */
struct slnMathCoreSymbol * slnMathCoreSymbolSetNumber(struct slnMathCoreSymbol *e, double value) {
    if (e == NULL) {
        return NULL;
    }
    e->number = value;
    return e;
}

/**
 * Atribui uma variável à estrutura
 * @param struct slnMathCoreSymbol * Estrutura de simbolo matemático
 * @param value char * Variável a ser amazenada na estrutura
 * @return Retorna um ponteiro para a estrutura slnMathCoreSymbol ou NULL em caso de falha
 */
struct slnMathCoreSymbol * slnMathCoreSymbolSetVariable(struct slnMathCoreSymbol *e, char *variable) {
    if (e == NULL) {
        return NULL;
    }
    if (e->var != NULL) {
        free(e->var);
    }
    e->var = variable == NULL ? NULL : strdup(variable);
    return e;
}

struct slnMathCoreSymbol * slnMathCoreSymbolSetValue(struct slnMathCoreSymbol *e, double number, char *variable) {
    if (e == NULL) {
        return NULL;
    }
    smcs.setNumber(e, number);
    smcs.setVariable(e, variable);

    return e;
}

/**
 * Libera a memória alocada para a estrutura slnMathCoreSymbol
 * @param e Ponteiro para a astrutura slnMathCoreSymbol a ser liberada
 */
void slnMathCoreSymbolFree(struct slnMathCoreSymbol *e) {
    if (e == NULL) {
        return;
    }
    smcs.clear(e);
    free(e);
}

/**
 * Destroi os valores da base, divisor, expoente e variável e seus elementos recursivos, mas não destroi a estrutura inicial
 * @param e struct slnMathCoreSymbol * Estrutura a ser limpa
 */
void slnMathCoreSymbolClear(struct slnMathCoreSymbol * e) {
    if (e == NULL) {
        return;
    }

    smcs.free(e->base);
    e->base = NULL;

    smcs.free(e->divisor);
    e->divisor = NULL;

    smcs.free(e->exp);
    e->exp = NULL;

    smcs.setVariable(e, NULL);
}

/**
 * Clona as informações de uma estrutura slnMathCoreSymbol em outra
 * @param e Estrtura de origem struct slnMathCoreSymbol *, estrutura com os elementos a serem clonados
 * @param e Pointeiro para o endeço da estrutura de destino struct slnMathCoreSymbol *, estrutura que irá receber os elementos a serem clonados
 * @return Retorna EXIT_SUCCESS para execução correta ou EXIT_FAILURE em caso de falha
 */
int slnMathCoreSymbolClone(struct slnMathCoreSymbol * src, struct slnMathCoreSymbol ** dest) {
    if (src == NULL) {
        return EXIT_FAILURE;
    }

    if (src == NULL) {
        smcs.setVariable((*dest), NULL);
    } else {
        memcpy((*dest), src, sizeof (*src));
    }
    return EXIT_SUCCESS;
}

/**
 * Inicializa a estrutura slnMathCoreSymbol
 * @param e Estrutura slnMathCoreSymbol a ser manipulada
 * @return Retorna EXIT_SUCCESS para execução correta ou EXIT_FAILURE em caso de falha
 */
int slnMathCoreSymbolInit(struct slnMathCoreSymbol *e) {

    e->setNumber = slnMathCoreSymbolSetNumber;
    e->setVariable = slnMathCoreSymbolSetVariable;
    e->free = slnMathCoreSymbolFree;
    e->new = slnMathCoreSymbolNew;
    e->clone = slnMathCoreSymbolClone;
    e->clear = slnMathCoreSymbolClear;
    e->toString = slnMathCoreSymbolToString;
    e->setValue = slnMathCoreSymbolSetValue;

    return EXIT_SUCCESS;
}

/**
 * Inicializa a estrutura slnMathCoreSymbol
 * @return Retorna EXIT_SUCCESS para execução correta ou EXIT_FAILURE em caso de falha
 */
int smcs_init() {
    return slnMathCoreSymbolInit(&smcs);
}
