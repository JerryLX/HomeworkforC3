#ifdef STAGE1
#include "dict1.h"
#else
#include "dict2.h"
#endif

#include "util.h"
#include "list.h"
#include "athlete.h"
#include <stdio.h>
#include <stdlib.h>


Dict* makedict(const char *in_file){
    Dict *dict = NULL;
    FILE *fp = safe_fopen(in_file,"r");
    
    Athlete a;
    a.name = safe_malloc(MAX_ATHLETE_LEN);
    a.age = safe_malloc(MAX_ATHLETE_LEN);
    a.height = safe_malloc(MAX_ATHLETE_LEN);
    a.weight = safe_malloc(MAX_ATHLETE_LEN);
    a.team = safe_malloc(MAX_ATHLETE_LEN);
    a.noc = safe_malloc(MAX_ATHLETE_LEN);
    a.games = safe_malloc(MAX_ATHLETE_LEN);
    a.year = safe_malloc(MAX_ATHLETE_LEN);
    a.season = safe_malloc(MAX_ATHLETE_LEN);
    a.city = safe_malloc(MAX_ATHLETE_LEN);
    a.sport = safe_malloc(MAX_ATHLETE_LEN);
    a.event = safe_malloc(MAX_ATHLETE_LEN);
    a.medal = safe_malloc(MAX_ATHLETE_LEN);
    
    while(!feof(fp)){
        fscanf(fp, "%d,%[^,],%c,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", 
                &a.id, a.name, &a.sex, a.age,a.height,a.weight,a.team,a.noc,a.games,a.year,a.season,a.city,a.sport,a.event,a.medal);
        //printf("insert %s\n", a.name);
        dict = insert(dict, &a);
    }
    fclose(fp);
    free_athlete_elements(&a);
    return dict;
}

int main(int argc, char **argv){
	const char* in_file = NULL;
	const char* out_file = NULL;
    char name[MAX_ATHLETE_LEN];
    FILE *fp = NULL;
    Dict *dict = NULL;

    if(argc != 3){
        printf("USAGE: %s <in_file><out_file>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    in_file = argv[1];
    out_file = argv[2];
    
    fp = safe_fopen(out_file, "w");
    fclose(fp);
    dict = makedict(in_file);
    while(scanf("%[^\n]",name) != EOF){
        getchar();
        List* athletes = search(dict,name);
        ListNode* cur = athletes->first;
        if(!cur){
            fp = safe_fopen(out_file,"a");
            fprintf(fp, "%s --> NOTFOUND\n",name);
            fclose(fp);
        }
        while(cur){
            char buf[MAX_ATHLETE_LEN];
            to_string(&(cur->athlete), buf);
            cur = cur->next;
            fp = safe_fopen(out_file,"a");
            fprintf(fp, "%s --> %s\n",name, buf);
            fclose(fp);
        }
        printf("%s --> %d\n", name, athletes->compare_count);
        free_list(athletes);
        //printf("finish free\n");
    }
    free_dict(dict);
    //fclose(fp);
    return 0;
}
