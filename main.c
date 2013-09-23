/*
 * main.c
 *
 *  Created on: 13/08/2013
 *      Author: silenobrito
 */

#include <ext/struct/LinkedList.h>
//#include <model/slnMathCoreSymbol.h>
//#include <control/slnMathCoreFunctions.h>
//#include <control/slnString.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//int init() {
//    avl_init();
//    smcf_init();
//    smcs_init();
//    string_init();
//    queue_init();
//}

int cmpString(void *a, void *b) {
    return strcmp((char *) a, (char *) b);
}

char *toStringString(void *a) {
    return (char *) strdup(a);
}

void destroyString(void *a) {
    if (a == NULL) {
        return;
    }
    free(a);
}

int main(int argc, char **argv) {

    //    struct slnAVL *list = NULL;

    //    init();
    
    char **nome = NULL;
    size_t count = 0;
    initLinkedList();
    
    linkedList *ll = LinkedList.createEmpty(cmpString, toStringString, destroyString);
    LinkedList.add(ll, strdup("Sileno"));
    LinkedList.add(ll, strdup("Icaro"));
    LinkedList.add(ll, strdup("Suziane"));
    LinkedList.add(ll, strdup("Jessica"));
    LinkedList.add(ll, strdup("Luciano"));
    LinkedList.add(ll, strdup("André"));

    for (LinkedList.first(ll); LinkedList.isReady(ll) == EXIT_SUCCESS; LinkedList.next(ll)) {
        fprintf(stdout, "nome: %s\n", (char *) LinkedList.current(ll));
    }
    nome = (char **) LinkedList.toArray(ll, &count);
    fprintf(stdout, "\tcount: %d\tnome: %s", count, nome[0]);
    LinkedList.destroy(ll);



    //    struct slnQueue * q = Queue.new();
    //    
    //    
    //    return EXIT_SUCCESS;
    //    
    //    char *out = NULL;
    //    struct slnMathCoreSymbol * e = NULL;
    //    e = smcs.new();
    //
    //    smcs.setValue(e, 20, "c");
    //    out = smcs.toString(e);
    //
    //    fprintf(stdout, "De volta a origem: %s\n", out);
    return EXIT_SUCCESS;
}
