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
    free((ListElmt *)ptr->data);
    free(ptr);
}

int list_ins_next(List *list, ListElmt *element, const void *data){
    if(list->tail != NULL){
        list->tail->next = element;
        element->data = (void *)data;
    }
    else{
        list->head = element;
        list->tail = element;
        element->data = (void *)data;
    }
    list->size++;
    return 0;
}
int list_rem_next(List *list, ListElmt *element, void ** data){
    if(element != NULL && element->next != NULL){
        element->next = element->next->next;
        if(ele  ment->next == NULL)
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
    if(listElmtOne->data > listElmtTwo->data){
        return 1;
    }
    else{
        return -1;
    }
}

static void insertAndMove(List *mergedList, ListElmt **listElmt, void *data){
    list_ins_next(mergedList,*listElmt,*listElmt->data);
    *listElmt = (*listElmt)->next;
}

List * merge_linked_lists(List *listOne, List *listTwo) {
    List *mergedList = (List *) malloc(sizeof(List));
    list_init(List * mergedList, <#void (*destroy)(void *)#>);
    if (listOne == NULL && listTwo == NULL)
        return NULL;
    else if (listOne == NULL)
        mergedList = listTwo;
    else if (listTwo == NULL)
        mergedList = listOne;
    else {
        ListElmt *listElmtOne = listOne->head;
        ListElmt *listElmtTwo = listTwo->head;
        int i;
        while (listElmtOne != NULL || listElmtTwo != NULL) {
            i = compareListElmt(listElmtOne, listElmtTwo);
            if (i > 0) {
                insertAndMove(mergedList, &listElmtOne, listElmtOne->data);
            }
            else {
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