//
//  linkedLists.h
//  cAlgos
//
//  Created by Rediet Tilahun Desta on 5/8/16.
//  Copyright © 2016 Rediet Tilahun Desta. All rights reserved.
//

#ifndef linkedLists_h
#define linkedLists_h
#include <stdlib.h>
typedef struct ListElmt_{
    void *data;
    struct ListElmt_ *next;
} ListElmt;

typedef struct List_ {
    int size;
    int (*match) (const void *key1, const void *key2);
    void (*destroy) (void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

typedef enum{FALSE, TRUE} Bool;
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);
void destroy(void *ptr);
int list_ins_next(List *list, ListElmt *element, const void *data);
int list_rem_next(List *list, ListElmt *element, void ** data);
List *merge_linked_lists(List *listOne, List *listTwo);
void reverseLinkedList(List *linkedList);
void reverseSubLinkedList(List *linkedList, int start, int end);
Bool haveCommonElementOne(List *listOne, List *listTwo);
Bool haveCommonElementTwo(List *listOne, List *listTwo);
void toString(List *linkedList);
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif /* linkedLists_h */
