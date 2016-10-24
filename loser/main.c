#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	float begin;
	float end;
} team;

int main(int argc, char **argv) {
	int team_c, i, j;
	float begin, end, win_pct;
	char name[256], team_name[256], win_name[256];
	
	while(scanf("%u", &team_c) != EOF) {
		if(team_c == 0) {
			continue;
		}
		team *teams = calloc(team_c, sizeof(team));
		
		for(i = 0; i < team_c * 2; i++) {
			scanf("%256s%256s%f%f", &name, &team_name, &begin, &end);
			for(j = 0; j < team_c; j++) {
				if(teams[j].name == NULL) {
					teams[j].name = malloc(strlen(&team_name));
					strcpy(teams[j].name, &team_name);
					teams[j].begin = begin;
					teams[j].end = end;
					break;
				}
				if(strstr(teams[j].name, &team_name)) {
					teams[j].begin += begin;
					teams[j].end += end;
					break;
				}
			}
			assert(teams[j].name != NULL);
		}

		win_pct = 0;
		for(i = 0; i < team_c; i++) {
			float pct = 1 - (teams[i].end / teams[i].begin);
			// Second cond is to break ties
			if(pct > win_pct || (pct == win_pct && strcmp(&win_name, teams[i].name) > 0)) {
				win_pct = pct;
				strcpy(&win_name, teams[i].name);
			}
		}
		win_pct *= 100;
		printf("%s %.1f%%\n", &win_name, win_pct);
	}
}
