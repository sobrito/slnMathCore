/* 
 * File:   Node.c
 * Author: Sileno Brito
 *
 * Created on 29 de Agosto de 2013, 15:43
 */
#include <ext/struct/Node.h>
#include <stdlib.h>

struct Node *createEmptyNode() {
    struct Node *node = NULL;
    if ((node = (struct Node *) malloc(sizeof *node)) == NULL) {
        perror("malloc");
        return NULL;
    }
    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    
    return node;
}
