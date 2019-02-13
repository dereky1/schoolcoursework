#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct room room;

struct room{
	int num;
	char* current;
	int n;
	int s;
	int e;
	int w;
};

int main()
{
	//struct room game = {0, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0};
	FILE* file;
	char command[64];
	char text[64];
	char filename[512];
	char line[256];
	int dungeon = 1;
	size_t size = 256;
	int running = 0;
	room rooms[256];
	int curr = 1;
	while(running == 0){
		fgets(text, 64, stdin);
		sscanf(text, "%s %s", &command, &filename);
	
		if(strcmp(command, "loaddungeon") == 0 && dungeon == 1){
			dungeon = 0;
			file = fopen(filename, "r");
			char desc[128];
			int rmnum;
			int north, south, east, west;
			int first = 0;
			while(fgets(line, 256, file) != NULL){
				sscanf(line, "%d $%[^'$']$ %d %d %d %d", &rmnum, &desc, &north, &south, &east, &west);
				if(first == 0){
					first = 1;
					rooms[1].num = rmnum;
					rooms[1].n = north;
					rooms[1].s = south;
					rooms[1].e = east;
					rooms[1].w = west;
					rooms[1].current = malloc(strlen(desc));
					strcpy(rooms[1].current, desc);
					printf("%s\n", rooms[1].current);
				}
				else{
					rooms[rmnum].num = rmnum;
					rooms[rmnum].n = north;
					rooms[rmnum].s = south;
					rooms[rmnum].e = east;
					rooms[rmnum].w = west;
					rooms[rmnum].current = malloc(strlen(desc)+1);
					strcpy(rooms[rmnum].current, desc);
				}
			}
		}
		else if(strcmp(command, "north") == 0){
			if(rooms[curr].n != -1){
				curr = rooms[curr].n;
				printf("%s\n", rooms[curr].current);
			}
			else	
				printf("The direction you are typing does not exist!\n");
		}	
		else if(strcmp(command, "south") == 0){
			if(rooms[curr].s != -1){
				curr = rooms[curr].s;
				printf("%s\n", rooms[curr].current);
			}
			else	
				printf("The direction you are typing does not exist!\n");
		}	
		else if(strcmp(command, "west") == 0){
			if(rooms[curr].w != -1){
				curr = rooms[curr].w;
				printf("%s\n", rooms[curr].current);
			}
			else	
				printf("The direction you are typing does not exist!\n");
		}	
		else if(strcmp(command, "east") == 0){
			if(rooms[curr].e != -1){
				curr = rooms[curr].e;
				printf("%s\n", rooms[curr].current);
			}
			else	
				printf("The direction you are typing does not exist!\n");
		}	
		else if(strcmp(command, "quit") == 0)
			return 0;
		else	
			printf("Invalid Command!\n");
	}	
	
	
	return 0;
}