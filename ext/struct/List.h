/* 
 * File:   List.h
 * Author: Sileno Brito
 *
 * Created on 2 de Setembro de 2013, 11:31
 */

#ifndef LIST_H
#define	LIST_H

#include <ext/struct/Node.h>

#ifdef	__cplusplus
extern "C" {
#endif

    struct list {
        struct Node *cursor;
        struct Node *root;
        int(*cmp)(void *a, void *b);
        char *(*toString)(void *a);
        void (*destroy)(void *a);
    };


#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

