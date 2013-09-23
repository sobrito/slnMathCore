/* 
 * File:   LinkedList.c
 * Author: Sileno Brito
 *
 * Created on 29 de Agosto de 2013, 15:33
 */
#include <ext/struct/LinkedList.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int linkedListIsReady(linkedList *list) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == NULL) {
        return EXIT_FAILURE;
    }
    if (list->cursor == NULL) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void *linkedListPrev(linkedList *list) {
    if (linkedListIsReady(list) == EXIT_FAILURE) {
        return NULL;
    }
    list->cursor = list->cursor->prev;
    return list->cursor->data;
}

void *linkedListLast(linkedList *list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->root == NULL) {
        return NULL;
    }
    list->cursor = list->root->prev;
    return list->cursor->data;
}

void *linkedListFirst(linkedList *list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->root == NULL) {
        return NULL;
    }
    list->cursor = list->root;
    return list->cursor->data;
}

void *linkedListNext(linkedList *list) {
    if (linkedListIsReady(list) == EXIT_FAILURE) {
        return NULL;
    }

    list->cursor = list->cursor->next;
    return linkedListIsReady(list) == EXIT_SUCCESS ? list->cursor->data : NULL;
}

void *linkedListCurrent(linkedList *list) {
    if (linkedListIsReady(list) == EXIT_FAILURE) {
        return NULL;
    }
    return list->cursor->data;
}

int linkedListIsEmpty(linkedList *list) {
    if (list == NULL) {
        return EXIT_SUCCESS;
    }
    if (list->root == NULL) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int linkedListIsFirst(linkedList *list) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == NULL) {
        return EXIT_FAILURE;
    }
    if (list->cursor == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == list->cursor) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int linkedListIsLast(linkedList *list) {
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == NULL) {
        return EXIT_FAILURE;
    }
    if (list->cursor == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root->prev == list->cursor) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

int linkedListAdd(linkedList *list, void *data) {
    struct Node* newNode = NULL;
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    newNode = createEmptyNode();
    newNode->data = data;

    if (list->root == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        list->root = newNode;
        /**
         * Aponta o cursor para o primeiro registro
         */
        linkedListFirst(list);
    }
    list->root->prev->next = newNode;
    list->root->prev = newNode;

    return EXIT_SUCCESS;
}

struct Node * linkedListSearchNode(int (*cmp) (void *a, void *b), struct Node* node, void *data) {
    if (node == NULL) {
        return NULL;
    }
    if (cmp(node->data, data) == 0) {
        return node;
    }
    return linkedListSearchNode(cmp, node->next, data);
}

void * linkedListSearch(linkedList *list, void *data) {
    struct Node *node = NULL;
    if ((node = linkedListSearchNode(list->cmp, list->root, data)) == NULL) {
        return NULL;
    }

    return node->data;
}

int linkedListEdit(linkedList *list, void *oldElement, void *newElement) {
    struct Node *node = NULL;
    if ((node = linkedListSearchNode(list->cmp, list->root, oldElement)) == NULL) {
        return EXIT_FAILURE;
    }
    list->destroy(node->data);
    node->data = newElement;

    return EXIT_SUCCESS;
}

int linkedListDel(linkedList *list, void *data) {
    struct Node *node = NULL;
    if ((node = linkedListSearchNode(list->cmp, list->root, data)) == NULL) {
        return EXIT_FAILURE;
    }

    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }

    list->destroy(node->data);
    free(node);

    /**
     * Aponta o cursor para o primeiro registro
     */
    linkedListFirst(list);
    return EXIT_SUCCESS;
}

void linkedListWalk(linkedList *list, void (*fnct)(void *data, void *extra), void *extra) {
    for (linkedListFirst(list); linkedListIsReady(list) == EXIT_SUCCESS; linkedListNext(list)) {
        fnct(linkedListCurrent(list), extra);
    }
}

char *linkedListCreateString(char *(*toString)(void *a), struct Node* node) {
    char *tmp = NULL;
    char *str = NULL;
    char *out = NULL;

    size_t length = 0;

    if (node->next != NULL) {
        tmp = linkedListCreateString(toString, node->next);
    }

    str = toString(node->data);
    length = (tmp != NULL ? strlen(tmp) : 0) + strlen(str) + 1;

    if ((out = (char *) malloc(sizeof (char) * length)) == NULL) {
        perror("malloc");
        return NULL;
    }
    sprintf(out, "%s%s", str, tmp == NULL ? "\0" : tmp);
    if (str != NULL) free(str);
    return out;
}

char *linkedListToString(linkedList *list) {
    return linkedListCreateString(list->toString, list->root);
}

void linkedListCreateAndFillArray(struct Node *node, void ***array, int *count, size_t *index) {
    if (node == NULL) {
        if ((*count) == 0) {
            return;
        }
        if (((*array) = (void **) malloc((sizeof (void *)) * (*count))) == NULL) {
            perror("malloc");
            return;
        }
        return;
    }
    (*count)++;
    linkedListCreateAndFillArray(node->next, array, count, index);
    (*array)[(*index)++] = node->data;
}

/**
 * Cria um vetor com os dados da lista encadeada, mas não duplica a área de memória dos dados
 * @param list struct linkedList*
 * @param countint *
 * @return void **
 */
void **linkedListToArray(linkedList *list, int * count) {
    void **array = NULL;
    int index = 0;
    linkedListCreateAndFillArray(list->root, &array, count, &index);

    if (array == NULL) {
        return NULL;
    }
    return array;

}

void linkedListFromArray(linkedList *list, void ** array, int count) {
    int i;
    for (i = 0; i != count; i++) {
        linkedListAdd(list, array[i]);
    }
}

linkedList *linkedListCreateEmpty(int(*cmp)(void *a, void *b), char *(*toString)(void *a), void (*destroy)(void *a)) {
    linkedList *ll = NULL;
    if ((ll = (linkedList *) malloc(sizeof *ll)) == NULL) {
        perror("malloc");
        return NULL;
    }
    ll->cmp = cmp;
    ll->destroy = destroy;
    ll->toString = toString;

    ll->root = NULL;

    return ll;
}

void linkedListDestroyNode(void (*destroy)(void *a), struct Node* node) {
    if (node == NULL) {
        return;
    }
    linkedListDestroyNode(destroy, node->next);
    destroy(node->data);
    free(node);
}

void linkedListDestroy(linkedList *list) {
    if (list == NULL) {
        return;
    }
    linkedListDestroyNode(list->destroy, list->root);
    free(list);
}

void initLinkedList() {
    LinkedList.isFirst = linkedListIsFirst;
    LinkedList.isLast = linkedListIsLast;
    LinkedList.current = linkedListCurrent;
    LinkedList.next = linkedListNext;
    LinkedList.prev = linkedListPrev;
    LinkedList.first = linkedListFirst;
    LinkedList.last = linkedListLast;
    LinkedList.isReady = linkedListIsReady;

    LinkedList.isEmpty = linkedListIsEmpty;
    LinkedList.createEmpty = linkedListCreateEmpty;
    LinkedList.add = linkedListAdd;
    LinkedList.destroy = linkedListDestroy;
    LinkedList.edit = linkedListEdit;
    LinkedList.del = linkedListDel;
    LinkedList.search = linkedListSearch;
    LinkedList.walk = linkedListWalk;
    LinkedList.toArray = linkedListToArray;
    LinkedList.fromArray = linkedListFromArray;
    LinkedList.toString = linkedListToString;
}