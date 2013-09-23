/* 
 * File:   LinkedList.h
 * Author: Sileno Brito
 *
 * Created on 29 de Agosto de 2013, 15:33
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <ext/struct/Node.h>
#include <ext/struct/List.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct list linkedList;

    struct EngineLinkedList {
        linkedList * (*createEmpty)(int(*cmp)(void *a, void *b), char *(*toString)(void *a), void (*destroy)(void *a));
        int (*add)(linkedList *list, void *data);
        int (*edit)(linkedList *list, void *oldElement, void *newElement);
        int (*del)(linkedList *list, void *data);
        void (*walk)(linkedList *list, void (*fnct)(void *data, void *extra), void *extra);
        char * (*toString)(linkedList *list);
        void * (*search)(linkedList *list, void *data);
        void ** (*toArray)(linkedList *list, int * count);
        void (*fromArray)(linkedList *list, void **, int count);
        void (*destroy)(linkedList *list);

        int (*isEmpty)(linkedList *list);
        int (*isFirst)(linkedList *list);
        int (*isReady)(linkedList *list);
        int (*isLast)(linkedList *list);
        void * (*current)(linkedList *list);
        void * (*first)(linkedList *list);
        void * (*last)(linkedList *list);
        void * (*prev)(linkedList *list);
        void * (*next)(linkedList *list);

    } LinkedList;

    void initLinkedList();


#ifdef	__cplusplus
}
#endif

#endif	/* LINKEDLIST_H */

