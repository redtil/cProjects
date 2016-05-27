//
//  linkedLists.c
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/8/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include "linkedLists.h"
#include "doublyLinkedLists.h"

void list_init(List *list, void (*destroy)(void *data)){
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}
void list_destroy(List *list){
    ListElmt *i;
    if(list->destroy != NULL){
        for(i = list->head; i != NULL; i = list_next(i) ){
            list->destroy(i);
        }
    }
    free(list);
}
void destroy(void * ptr){
    free(((ListElmt *)ptr)->data);
    free(ptr);
}

int list_ins_next(List *list, ListElmt *element, const void *data){
    if(list->tail != NULL){
        list->tail->next = element;
        element->data = (void *)data;
        element->next = NULL;
        list->tail = element;
    }
    else{
        list->head = element;
        list->tail = element;
        element->data = (void *)data;
        element->next = NULL;
    }
    list->size++;
//    printf("%d\n", *((int*)(element->data)));
    return 0;
}
int list_rem_next(List *list, ListElmt *element, void ** data){
    if(element != NULL && element->next != NULL){
        element->next = element->next->next;
        if(element->next == NULL)
            list->tail = element;
        list->size--;
        
    }
    else if(element == NULL)
    {
        list->head = list->head->next;
        list->size--;
    }
    return 0;
}
static int compareListElmt(ListElmt *listElmtOne, ListElmt* listElmtTwo){
    if(*((int*)listElmtOne->data) > *((int*)listElmtTwo->data)){
        return 1;
    }
    else if(*((int*)listElmtOne->data) < *((int*)listElmtTwo->data)){
        return -1;
    }
    else{
        return 0;
    }
}

static void insertAndMove(List *mergedList, ListElmt **listElmt, void *data){
    ListElmt *listElmtThis = (ListElmt *)malloc(sizeof(List));
    listElmtThis->data = (*listElmt)->data;
    list_ins_next(mergedList,listElmtThis,listElmtThis->data);
    *listElmt = (*listElmt)->next;
}
void toString(List *linkedList){
    ListElmt *i;
    for(i = linkedList->head; i != NULL; i = i->next){
        printf("%d\n", *((int*)(i->data)));
    }
}

//merging in this case is actually merge sort for linked lists.
List *merge_linked_lists(List *listOne, List *listTwo) {
    List *mergedList = (List *) malloc(sizeof(List));
    list_init(mergedList, destroy);
    if (listOne == NULL && listTwo == NULL)
        return NULL;
    else if (listOne == NULL)
        mergedList = listTwo;
    else if (listTwo == NULL)
        mergedList = listOne;
    else {
        ListElmt *listElmtOne = listOne->head;
        ListElmt *listElmtTwo = listTwo->head;
        while (listElmtOne != NULL || listElmtTwo != NULL) {
            int i;
            i = compareListElmt(listElmtOne, listElmtTwo);
            if (i > 0) {
                insertAndMove(mergedList, &listElmtOne, listElmtOne->data);
            }
            else if( i < 0){
                insertAndMove(mergedList, &listElmtTwo, listElmtTwo->data);
            }
            else{
                insertAndMove(mergedList, &listElmtOne, listElmtOne->data);
                insertAndMove(mergedList, &listElmtTwo, listElmtTwo->data);
            }
        }
        if (listElmtOne == NULL && listElmtTwo != NULL) {
            while (listElmtTwo != NULL) {
                insertAndMove(mergedList, &listElmtTwo, listElmtTwo->data);
            }
        }
        else {
            while (listElmtOne != NULL) {
                insertAndMove(mergedList, &listElmtOne, listElmtOne->data);
            }
        }
    }
    return mergedList;
}

void reverseLinkedList(List *linkedList){
    ListElmt *i, *j, *k, *temp;
    if(linkedList == NULL)
        return;
    i = NULL;
    j = linkedList->head;
    while(j != NULL){
        k = j->next;
        j->next = i;
        i = j;
        j = k;
    }
    temp = linkedList->head;
    linkedList->head = linkedList->tail;
    linkedList->tail = temp;
}

//merges two linked lists. This is not merge sort
void merge_linked_lists_two(List *listOne, List *listTwo, int mergePoint){
    ListElmt *ptr;
    int cnt = 0;
    for(ptr = listOne->head; ptr!= NULL; ptr = ptr->next){
        if(cnt == mergePoint) break;
        cnt++;
    }
    listTwo->tail->next = ptr;
    listTwo->tail = listOne->tail;
}

static void printListElmt(ListElmt *elmt){
    printf("%d",*((int*)(elmt->data)));
}

void reverseSubLinkedList(List *linkedList, int start, int end){
    if(start < 0 || end < 0 || start > end) return;
    if(start == end) return;
    ListElmt *beforeStartElmt, *startElmt, *endElmt, *afterEndElmt;
    ListElmt *ptr;
    ListElmt *i, *j, *k;
    int cnt = 1;
    beforeStartElmt = NULL;
    for(ptr = linkedList->head; (cnt < start) && (ptr!= NULL); ptr = ptr->next){
        if(cnt == start-1) beforeStartElmt = ptr;
        cnt++;
    }
    startElmt = ptr;
    i = startElmt;
    if(startElmt!= NULL)
        j = startElmt->next;
    while((j!= NULL) && (cnt<end)){
        k = j->next;
        endElmt = j;
        afterEndElmt = endElmt->next;
        j->next = i;
        i = j;
        j = k;
        cnt++;
    }

    startElmt->next = afterEndElmt;
    if(beforeStartElmt != NULL){
        beforeStartElmt->next = endElmt;
    }

    if(start == 1){
        linkedList->head = endElmt;
    }
    if(afterEndElmt == NULL){
        linkedList->tail = startElmt;
    }
}

//Using Floyd's Algorithm
Bool checkIfCycle(List *linkedList){
    if(linkedList == NULL || linkedList->head == NULL) return FALSE;
    ListElmt *i = linkedList->head;
    ListElmt *j = i;
    ListElmt *k = i;
    int cnt=0;
    while(k != NULL){
        i= i->next;
        j = k->next;
        if(j == NULL) return FALSE;
        k = j->next;
        if(i == k){
            return TRUE;
        }
        cnt++;
    }
    return FALSE;
}

Bool haveCommonElementOne(List *listOne, List *listTwo){
    ListElmt *ptr;
    ListElmt *endOne;
    ListElmt *endTwo;
    for(ptr = listOne->head; ptr != NULL; ptr=ptr->next){
        if(ptr->next == NULL){
            endOne = ptr;
        }
    }
    for(ptr = listTwo->head; ptr != NULL; ptr=ptr->next){
        if(ptr->next == NULL){
            endTwo = ptr;
        }
    }
    if(endOne == endTwo) return TRUE;
    return FALSE;
}

Bool haveCommonElementTwo(List *listOne, List *listTwo){
    ListElmt *ptr;
    ListElmt *aPtr;
    int cntOne = 0;
    int cntTwo = 0;
    int diff;
    int i;
    for(ptr = listOne->head; ptr != NULL; ptr = ptr->next){
        cntOne++;
    }
    for(ptr = listTwo->head; ptr != NULL; ptr = ptr->next){
        cntTwo++;
    }
    diff = abs(cntOne-cntTwo);
    if(cntOne > cntTwo)
        ptr = listOne->head;
    else
        ptr = listTwo->head;
    for(i = 0; i < diff; i++){
        ptr = ptr->next;
    }
    if(cntOne > cntTwo){
        for(aPtr = listTwo->head; aPtr != NULL; aPtr = aPtr->next){
            if(ptr == aPtr)
            {
                return TRUE;
            }
            else{
                ptr = ptr->next;
            }
        }
    }
    else{
        for(aPtr = listOne->head; aPtr!= NULL; aPtr = aPtr->next){
            if(ptr == aPtr)
            {
                return TRUE;
            }
            else{
                ptr = ptr->next;
            }
        }
    }
    return FALSE;
}

//linkedList must be a cyclic linkedList
ListElmt *getElmtCyclicList(List *linkedList){
    ListElmt *i = linkedList->head;
    ListElmt *j = i;
    ListElmt *k = i;
    while(k != NULL){
        i= i->next;
        j = k->next;
        k = j->next;
        if(i == k){
            return i;
        }
    }
    return NULL;

}
//one linked list having a cycle
Bool haveCommonElementThree(List *a, List *b){
    ListElmt *mergeListElmtA;
    ListElmt *mergeListElmtB;
    if(checkIfCycle(a) == 1){
       mergeListElmtA = getElmtCyclicList(a);
    }else{
        return haveCommonElementOne(a,b);
    }
    if(checkIfCycle(b) == 1){
        mergeListElmtB = getElmtCyclicList(b);
    }
    ListElmt *ptr = a->head;
    int cnt = 0;
    while(ptr != NULL){
        if(ptr == mergeListElmtB) return TRUE;
        if(ptr == mergeListElmtA) {
            cnt++;
            if(cnt == 2) return FALSE;
        }
        ptr = ptr->next;
    }
}


