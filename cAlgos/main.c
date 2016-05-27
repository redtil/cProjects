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
    merge_linked_lists_two(linkedListOne,linkedListTwo,3);
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

//merging like merge sort but for linked lists.
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

static void testIfListsMergedCycle(){
    List *linkedListA = makeLinkedList(10, FALSE);
    List *linkedListB = makeLinkedList(7, FALSE);
//    merge_linked_lists_two(linkedListA,linkedListB,9);
    Bool val = haveCommonElementThree(linkedListA,linkedListB);
    printf("%d\n",val);
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
    else if (!strcmp("checkIfMergedCycle", testType)){
        testIfListsMergedCycle();
    }
}

int main(int argc, const char * argv[]) {
    test((char *)argv[1]);
}
