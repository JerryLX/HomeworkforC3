#include "athlete.h"
#include "util.h"
#include "list.h"
#include <string.h>

void free_list_elements(List *list){
    struct ListNode *cur = list->first;    
    while(cur){
        struct ListNode *next = cur->next;
        free_athlete_elements(&(cur->athlete));
        free(cur);
        cur = next;
    }
}

void free_list(List *list){
    free_list_elements(list);
    free(list);
}

void insert_list(List *list, Athlete* athlete){
    struct ListNode *new_node = safe_malloc(sizeof(struct ListNode));
    deepcopy_athlete(&(new_node->athlete),athlete);
    if(list->first){
        list->last->next = new_node;
        list->last = new_node;
    }
    else{
        list->first = list->last = new_node;
    }
}
