#ifndef __DICT2_H__
#define __DICT2_H__

#include "athlete.h"
#include "util.h"
#include "list.h"

typedef struct TreeNode{
    List list;
    char* name;
    struct TreeNode *ln;
    struct TreeNode *rn;
}Dict;

List* search(Dict *dict, char *name);
Dict* insert(Dict *dict, Athlete *athlete);
void free_dict(Dict *dict);

#endif
