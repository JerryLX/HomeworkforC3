#ifndef __LIST_H__
#define __LIST_H__

#include "athlete.h"
#include "util.h"

typedef struct ListNode{
    Athlete athlete;
    struct ListNode *next;
}ListNode;

typedef struct List{
    struct ListNode *first;
    struct ListNode *last;
    int compare_count;
}List;

void free_list(List *list);
void free_list_elements(List *list);
void insert_list(List *list, Athlete* athlete);

#endif
