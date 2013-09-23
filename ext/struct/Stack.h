/* 
 * File:   Stack.h
 * Author: Sileno Brito
 *
 * Created on 2 de Setembro de 2013, 10:00
 */

#ifndef STACK_H
#define	STACK_H

#include <ext/struct/Node.h>
#include <ext/struct/List.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct list stack;

    struct EngineStack {
        stack * (*createEmpty)(int(*cmp)(void *a, void *b), char *(*toString)(void *a), void (*destroy)(void *a));
        int (*add)(stack *list, void *data);
        int (*edit)(stack *list, void *oldElement, void *newElement);
        int (*del)(stack *list);
        void (*walk)(stack *list, void (*fnct)(void *data, void *extra), void *extra);
        void * (*search)(stack *list, void *data);
        char * (*toString)(stack *list);
        void ** (*toArray)(stack *list, int * count);
        void (*fromArray)(stack *list, void **, int count);
        void (*destroy)(stack *list);
    } Stack;

    void initStack();


#ifdef	__cplusplus
}
#endif

#endif	/* STACK_H */

