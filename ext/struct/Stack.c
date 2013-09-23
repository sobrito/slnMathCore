#include <ext/struct/Stack.h>
#include <ext/struct/LinkedList.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int stackDel(stack *list) {
    struct Node *node = NULL;
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == NULL) {
        return EXIT_FAILURE;
    }
    node = list->root;
    list->root = list->root->prev;
    list->destroy(node->data);
    free(node);
}

void initStack() {

    initLinkedList();
    Stack.createEmpty = LinkedList.createEmpty;

    Stack.add = LinkedList.add;
    Stack.edit = LinkedList.edit;
    Stack.del = stackDel;

    Stack.walk = LinkedList.walk;
    Stack.search = LinkedList.search;

    Stack.toString = LinkedList.toString;
    Stack.toArray = LinkedList.toArray;
    Stack.fromArray = LinkedList.fromArray;
    Stack.destroy = LinkedList.destroy;

}