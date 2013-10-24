/* 
 * File:   MathResult.h
 * Author: Sileno Brito
 *
 * Created on 9 de Outubro de 2013, 20:44
 */

#ifndef MATHRESULT_H
#define	MATHRESULT_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct MathResult {
        int operation;
        struct MathUnit *mathUnit;
        struct MathResult *mathResult;
    };
    /**
     * Fila
     */
    struct EngineMathResult{
        void (*add)(struct MathResult *result, int operation, struct MathUnit*);
        void (*del)(struct MathResult *result);
        struct MathUnit *(*get)(struct MathResult *result, int *operation);
    } ApiMathResult;

    void MathResultInit();
#ifdef	__cplusplus
}
#endif

#endif	/* MATHRESULT_H */

