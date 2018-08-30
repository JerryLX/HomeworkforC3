#include "athlete.h"
#include "util.h"
#include <stdio.h>


void deepcopy_athlete(Athlete *dst, Athlete *src){
    free_athlete_elements(dst);
    dst->id = src->id;
    dst->sex = src->sex;
    dst->age = new_string(src->age);
    dst->name = new_string(src->name);
    dst->height = new_string(src->height);
    dst->weight = new_string(src->weight);
    dst->team = new_string(src->team);
    dst->noc = new_string(src->noc);
    dst->games = new_string(src->games);
    dst->year = new_string(src->year);
    dst->season = new_string(src->season);
    dst->city = new_string(src->city);
    dst->sport = new_string(src->sport);
    dst->event = new_string(src->event);
    dst->medal = new_string(src->medal);
}

Athlete* new_athlete(Athlete *a){
    Athlete* na = safe_malloc(sizeof(Athlete));
    deepcopy_athlete(na, a);
    return na;
}

void to_string(Athlete *a, char *s){
    if(!a)
        snprintf(s, MAX_ATHLETE_LEN, "%s", "NOTFOUND");
    else
        snprintf(s, MAX_ATHLETE_LEN, "ID: %d Sex: %c || Age: %s || Height: %s || Weight: %s || Team: %s || NOC: %s || Games: %s || Year: %s|| Season: %s || City: %s || Sport: %s || Event: %s|| Medal: %s||",  
                a->id, a->sex, a->age, a->height, a->weight, a->team, a->noc, a->games, a->year, a->season, a->city,
                a->sport, a->event, a->medal);
}

void free_athlete_elements(Athlete* a){
    if(a->name){
        free(a->name);
        a->name = 0;
    }
    if(a->age){
        free(a->age);
        a->age = 0;
    }
    if(a->height){
        free(a->height);
        a->height = 0;
    }
    if(a->weight){
        free(a->weight);
        a->weight = 0;
    }
    if(a->team){
        free(a->team);
        a->team = 0;
    }
    if(a->noc){
        free(a->noc);
        a->noc = 0;
    }
    if(a->games){
        free(a->games);
        a->games = 0;
    }
    if(a->year){
        free(a->year);
        a->year = 0;
    }
    if(a->season){
        free(a->season);
        a->season = 0;
    }
    if(a->city){
        free(a->city);
        a->city = 0;
    }
    if(a->sport){
        free(a->sport);
        a->sport = 0;
    }
    if(a->event){
        free(a->event);
        a->event = 0;
    }
    if(a->medal){
        free(a->medal);
        a->medal = 0;
    }
}

void free_athlete(Athlete* a){
    free_athlete_elements(a);
    free(a);
}
