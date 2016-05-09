//
//  main.c
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/7/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include <stdio.h>
static void test(char testType[]){
    switch(testype){
        case linkedLists:
            testLinkedLists();
            break;
        case doublyLinkedLists:
            break;
    }
}

static void testLinkedLists(){
    List *linkedListOne = (List *) malloc(sizeof(List));
    List *linkedListTwo = (List *) malloc(sizeof(List));
    list_init(linkedListOne,destroy);
    list_init(linkedLisstTwo,destroy);
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
int main(int argc, const char * argv[]) {
    test(argv[1]);
}
