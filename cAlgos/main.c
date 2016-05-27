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

static List *makeLinkedList(int size, Bool makeCycle){
    ListElmt *cycleStrtElmt;
    List *linkedListOne = (List *) malloc(sizeof(List));
    void (*fnPtr)(void *) = destroy;
    list_init(linkedListOne,fnPtr);
    ListElmt *listElmt;
    int i;
    for(i = size; i > 0; i--){
        listElmt= (ListElmt *)malloc(sizeof(ListElmt));
        int *data = (int *)malloc(sizeof(int));
        *data = i;
        list_ins_next(linkedListOne,listElmt,data);
        if(i == 3)
            cycleStrtElmt = linkedListOne->tail;
    }
    if(makeCycle){
        linkedListOne->tail->next = cycleStrtElmt;
    }
    return linkedListOne;
}


static void testIfListsMerged(){
    List *linkedListOne = makeLinkedList(10,FALSE);
    List *linkedListTwo = makeLinkedList(10,FALSE);
    ListElmt *ptr;
    for(ptr = linkedListOne->head; ptr!= NULL; ptr = ptr->next){
        if(*((int*)(ptr->data)) == 5)
            break;
    }
    linkedListTwo->tail->next = ptr;
    linkedListTwo->tail = linkedListOne->tail;
    Bool val = haveCommonElementTwo(linkedListOne,linkedListTwo);
    printf("%d",val);
}


static void testReversingLinkedLists(){
    List *linkedList = makeLinkedList(10,FALSE);
    toString(linkedList);
    printf("\n");
    reverseSubLinkedList(linkedList, 2, 2);
    toString(linkedList);
}

static void testMergingLinkedLists(){
    List *linkedListTwo = (List *) malloc(sizeof(List));
    void (*fnPtr)(void *) = destroy;
    list_init(linkedListTwo,fnPtr);
    ListElmt *listElmt;
    int i;
    List *linkedListOne = makeLinkedList(5,FALSE);
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

static void testIfCycle(){
    List *linkedList = makeLinkedList(10,TRUE);
    Bool val = checkIfCycle(linkedList);
    printf("%d\n", val);
}


static void test(char testType[]){
    if(!strcmp("mergeLinkedLists",testType)){
        testMergingLinkedLists();
    }
    else if(!strcmp("reverseLinkedList",testType)){
        testReversingLinkedLists();
    }
    else if(!strcmp("checkIfMerged",testType)){
        testIfListsMerged();
    }
    else if(!strcmp("checkIfCycle",testType)){
        testIfCycle();
    }
}

int main(int argc, const char * argv[]) {
    test((char *)argv[1]);
}
