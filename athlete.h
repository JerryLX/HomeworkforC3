#ifndef __ATHLETE_H__
#define __ATHLETE_H__

#define MAX_ATHLETE_LEN 512

typedef struct Athlete{
    int id;
    char *name;
    char sex;
    char *age;
    char *height;
    char *weight;
    char *team;
    char *noc;
    char *games;
    char *year;
    char *season;
    char *city;
    char *sport;
    char *event;
    char *medal;
}Athlete;

Athlete* new_athlete(Athlete *a);
void deepcopy_athlete(Athlete* dst, Athlete* src);
void to_string(Athlete *a, char *string);
void free_athlete(Athlete *a);
void free_athlete_elements(Athlete *a);

#endif
