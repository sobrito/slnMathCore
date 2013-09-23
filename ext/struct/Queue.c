#include <ext/struct/Queue.h>
#include <ext/struct/LinkedList.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int queueDel(queue *list) {
    struct Node *node = NULL;
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    if (list->root == NULL) {
        return EXIT_FAILURE;
    }
    node = list->root;
    list->root = list->root->prev == list->root ? NULL : list->root->next;
}

void initQueue() {
    initLinkedList();
    Queue.createEmpty = LinkedList.createEmpty;

    Queue.add = LinkedList.add;
    Queue.edit = LinkedList.edit;
    Queue.del = queueDel;

    Queue.walk = LinkedList.walk;
    Queue.search = LinkedList.search;

    Queue.toString = LinkedList.toString;
    Queue.toArray = LinkedList.toArray;
    Queue.fromArray = LinkedList.fromArray;
    Queue.destroy = LinkedList.destroy;

}