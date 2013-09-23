/* 
 * File:   Queue.h
 * Author: Sileno Brito
 *
 * Created on 2 de Setembro de 2013, 11:27
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include <ext/struct/Node.h>
#include <ext/struct/List.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct list queue;

    struct EngineQueue {
        queue * (*createEmpty)(int(*cmp)(void *a, void *b), char *(*toString)(void *a), void (*destroy)(void *a));
        int (*add)(queue *list, void *data);
        int (*edit)(queue *list, void *oldElement, void *newElement);
        int (*del)(queue *list);
        void (*walk)(queue *list, void (*fnct)(void *data, void *extra), void *extra);
        void * (*search)(queue *list, void *data);
        char * (*toString)(queue *list);
        void ** (*toArray)(queue *list, int * count);
        void (*fromArray)(queue *list, void **, int count);
        void (*destroy)(queue *list);
    } Queue;

    void initQueue();



#ifdef	__cplusplus
}
#endif

#endif	/* QUEUE_H */

