//
//  main.c
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/7/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include <stdio.h>
#include "linkedLists.h"
#include <string.h>

static List *makeLinkedList(){
    List *linkedListOne = (List *) malloc(sizeof(List));
    void (*fnPtr)(void *) = destroy;
    list_init(linkedListOne,fnPtr);
    ListElmt *listElmt;
    int i;
    for(i = 10; i > 0; i--){
        listElmt= (ListElmt *)malloc(sizeof(ListElmt));
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        list_ins_next(linkedListOne,listElmt,data);
    }
    return linkedListOne;
}

static void testReversingLinkedLists(){
    List *linkedList = makeLinkedList();
    toString(linkedList);
    printf("\n");
    reverseSubLinkedList(linkedList, 2, 2);
    toString(linkedList);
}

static void mergeLinkedLists(){
    List *linkedListTwo = (List *) malloc(sizeof(List));
    void (*fnPtr)(void *) = destroy;
    list_init(linkedListTwo,fnPtr);
    ListElmt *listElmt;
    int i;
    List *linkedListOne = makeLinkedList();
    for(i = 10; i > 0; i--){
        listElmt= (ListElmt *)malloc(sizeof(ListElmt));
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        list_ins_next(linkedListTwo,listElmt,data);
    }
    List *mergedList = merge_linked_lists(linkedListOne, linkedListTwo);
    ListElmt *j;
    for(j = mergedList->head; j != NULL; j = j->next){
        printf("%d\n",*((int *)(j->data)));
    }
}

static void test(char testType[]){
    if(!strcmp("mergeLinkedLists",testType)){
        mergeLinkedLists();
    }
    else if(!strcmp("reverseLinkedList",testType)){
        testReversingLinkedLists();
    }
}

int main(int argc, const char * argv[]) {
    test((char *)argv[1]);
}
