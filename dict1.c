#include "dict1.h"
#include "util.h"
#include <string.h>
#include "list.h"

static Dict* search_one(Dict *dict, char *name, int* count){
    if(!dict)
        return 0;
    (*count)++;
    //printf("current:%s\n", dict->athlete.name);
    //printf("%d,%s\n",*count,dict->athlete.name);
    if(strcmp(dict->athlete.name, name)==0){
        //printf("equal\n");
        return dict;
    }
    else if(strcmp(dict->athlete.name, name) < 0){
        return search_one(dict->rn, name, count);
    }
    else
        return search_one(dict->ln, name, count);
}

List* search(Dict *dict, char *name){
    //printf("start search:%p,%p,%s",dict->ln,dict->rn,name);
    List *list = safe_malloc(sizeof(List));
    Dict *result = dict;
    while(result = search_one(result, name, &(list->compare_count))){
        //printf("%s\n",result->athlete.name);
        insert_list(list, &(result->athlete));
        result = result->ln;
        //printf("%p\n",result);
    }
    //printf("finish search\n");
    return list;
}

Dict* insert(Dict *parent, Athlete* athlete){
    //printf("start insert:%p,%s\n",parent,athlete->name);
    if(!parent){
        parent = safe_malloc(sizeof(Dict));
        deepcopy_athlete(&(parent->athlete), athlete);
    }
    else{
        if(strcmp(athlete->name,parent->athlete.name)<=0){
            parent->ln = insert(parent->ln, athlete);
        }
        else{
            parent->rn = insert(parent->rn, athlete);
        }
    }
    return parent;
}

void free_dict(Dict *dict){
    if(!dict)
        return;
    free_dict(dict->ln);
    free_dict(dict->rn);
    free_athlete_elements(&(dict->athlete));
    free(dict);
}
