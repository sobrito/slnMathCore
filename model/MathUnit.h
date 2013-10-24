/* 
 * File:   Math.h
 * Author: Sileno Brito
 *
 * Created on 2 de Setembro de 2013, 16:45
 */

#ifndef MATH_H
#define	MATH_H
#include <ext/struct/LinkedList.h>
#ifdef	__cplusplus
extern "C" {
#endif

    /**
     *  Math Unit
     */
    struct MathUnit {
        long number;
  char *var;

        struct MathUnit *divisor;
        struct MathUnit *base;
        struct MathUnit *exp;
    };

    struct EngineUAD {
        struct MathUnit * (*createEmpty)();
        void(*setVar)(struct MathUnit* u, char *var);
        void(*setNumber)(struct MathUnit* u, long number);
        void(*setValue)(struct MathUnit* u, char *var, long number);
    } UAD;

    void uadInit();


#ifdef	__cplusplus
}
#endif

#endif	/* MATH_H */

