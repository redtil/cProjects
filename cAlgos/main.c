//
//  main.c
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/7/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include <stdio.h>
#include "linkedLists.h"
#define linkedLists "linkedLists"
#define doublyLinkedLists "doublyLinkedLists"

static void testLinkedLists(){
    List *linkedListOne = (List *) malloc(sizeof(List));
    List *linkedListTwo = (List *) malloc(sizeof(List));
    (*fnPtr) = destroy;
    list_init(linkedListOne,fnPtr);
    list_init(linkedLisstTwo,fnPtr);
    ListElmt *listElmt;
    int i;
    for(i = 0; i < 5; i++){
        listElmt= (ListElmt *)malloc(sizeof(ListElmt));
        const int *data = i;
        list_ins_next(linkedListOne,listElmtOne,data);
    }
    for(i = 10; i > 0; i--){
        listElmt= (ListElmt *)malloc(sizeof(ListElmt));
        const int *data = i;
        list_ins_next(linkedListTwo,listElmt,data);
    }

    List *mergedList = merge_linked_lists(linkedListOne, linkedListTwo);
    ListElmt *i;
    for(i = mergedList->head; i != NULL; i = i->next){
        printf("%d\n",i->data);
    }
}

static void test(char testType[]){
    switch(testType){
        case linkedLists:
            testLinkedLists();
            break;
        case doublyLinkedLists:
            break;
    }
}

int main(int argc, const char * argv[]) {
    test(argv[1]);
}
