#include <model/MathUnit.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int uadCompare(void *a, void *b) {
    struct MathUnit *o1 = (struct MathUnit *) a;
    struct MathUnit *o2 = (struct MathUnit *) b;

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
    struct MathUnit *o1 = (struct MathUnit *) a;
    return NULL;
}

void uadDestroy(void *a) {
    struct MathUnit *o1 = (struct MathUnit *) a;

}

struct MathUnit *uadCreateEmpty() {
    struct MathUnit *u = NULL;
    if ((u = (struct MathUnit *) malloc(sizeof *u)) == NULL) {
        perror("malloc");
        return NULL;
    }

    u->composite = LinkedList.createEmpty(uadCompare, uadToString, uadDestroy);
}

void uadInit() {

}