#include <model/Math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int uadCompare(void *a, void *b) {
    struct uad *o1 = (struct uad *) a;
    struct uad *o2 = (struct uad *) b;

    if (o1 == NULL || o2 == NULL) {

    }
    if (o1->var == o2->var && o1->var == NULL) {
        if (o1->number == o2->number) {
            return 0;
        }
        return (o1->number < o2->number) ? 1 : -1;
    }
    if (o1->var == NULL) {
        return 1;
    } else if (o2->var == NULL) {
        return -1;
    }
    return strcmp(o1->var, o2->var);
}

char * uadToString(void *a) {
    struct uad *o1 = (struct uad *) a;
    return NULL;
}

void uadDestroy(void *a) {
    struct uad *o1 = (struct uad *) a;

}

struct uad *uadCreateEmpty() {
    struct uad *u = NULL;
    if ((u = (struct uad *) malloc(sizeof *u)) == NULL) {
        perror("malloc");
        return NULL;
    }

    u->composite = LinkedList.createEmpty(uadCompare, uadToString, uadDestroy);
}

void uadInit() {

}