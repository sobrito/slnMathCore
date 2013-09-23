/* 
 * File:   Node.h
 * Author: Sileno Brito
 *
 * Created on 29 de Agosto de 2013, 15:42
 */

#ifndef NODE_H
#define	NODE_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct Node {
        struct Node *prev;
        struct Node *next;
        void *data;
    };


    struct Node *createEmptyNode();

#ifdef	__cplusplus
}
#endif

#endif	/* NODE_H */

