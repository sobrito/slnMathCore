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
     *  Unit Arithmetic Data
     */
    struct uad {
        long number;
        char *var;

        struct uad *divisor;
        struct uad *base;
        struct uad *exp;

        linkedList *composite;
    };

    struct EngineUAD {
        struct uad * (*createEmpty)();
        void(*setVar)(struct uad* u, char *var);
        void(*setNumber)(struct uad* u, long number);
        void(*setValue)(struct uad* u, char *var, long number);
    } UAD;

    void uadInit();


#ifdef	__cplusplus
}
#endif

#endif	/* MATH_H */

