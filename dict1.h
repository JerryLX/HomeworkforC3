#ifndef __DICT1_H__
#define __DICT1_H__

#include "athlete.h"
#include "util.h"
#include "list.h"

typedef struct TreeNode{
    Athlete athlete;
    struct TreeNode *ln;
    struct TreeNode *rn;
}Dict;

List* search(Dict *dict, char *name);
Dict* insert(Dict *dict, Athlete *athlete);
void free_dict(Dict *dict);

#endif
