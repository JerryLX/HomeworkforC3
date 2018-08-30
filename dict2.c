#include "dict2.h"
#include "util.h"
#include <string.h>
#include "list.h"
#include "athlete.h"

static void search_helper(Dict *dict, char *name, List* list){
    if(!dict)
        return;
    //printf("current: %s\n", dict->name);
    list->compare_count++;
    if(strcmp(name,dict->name)<0){
        search_helper(dict->ln, name, list);
    }
    else if(strcmp(name,dict->name)>0){
        search_helper(dict->rn, name,list);
    }
    else{
        ListNode *cur = dict->list.first;
        while(cur){
            insert_list(list, &(cur->athlete));
            cur = cur->next;
        }
    }
}

List* search(Dict *dict, char *name){
    List *list = safe_malloc(sizeof(List));
    search_helper(dict,name,list);
    return list;
}

Dict* insert(Dict *parent, Athlete* athlete){
    if(!parent){
        parent = safe_malloc(sizeof(Dict));
        parent->name = new_string(athlete->name);
        insert_list(&(parent->list),athlete);
    }
    else{
        if(strcmp(athlete->name, parent->name)<0){
            parent->ln = insert(parent->ln, athlete);
        }
        else if(strcmp(athlete->name, parent->name)>0){
            parent->rn = insert(parent->rn, athlete);
        }
        else{
            insert_list(&(parent->list), athlete);
        }
    }
    return parent;
}

void free_dict(Dict *dict){
    if(!dict)
        return;
    free_dict(dict->ln);
    free_dict(dict->rn);
    free_list_elements(&(dict->list));
    free(dict->name);
    free(dict);
}
