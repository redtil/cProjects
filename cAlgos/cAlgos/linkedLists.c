//
//  linkedLists.c
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/8/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#include "linkedLists.h"
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
void destroy(){
    
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

List * merge_linked_lists(List *listOne, List *listTwo)
{
    List *mergedList = (List *)malloc(sizeof(List));
    list_init(List *mergedList, <#void (*destroy)(void *)#>);
    if(listOne == NULL && listTwo == NULL)
        return NULL;
    else if(listOne== NULL)

}
