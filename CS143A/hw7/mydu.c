#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void recur(char* path)
{
	DIR *dir;
	struct dirent* direct;
	struct statvfs stats;
	struct stat fst;
	struct stat st;
	
	if(!(dir = opendir(path))){
		//printf("Error Opening Directory %s\n", path);
		return;
	}
	
	if(!(direct = readdir(dir))){
		printf("Error Reading Directory\n");
		exit(1);
	}
	
	/*int counter = 0;
	do{
		statvfs(direct->d_name, &stats);
		stat(direct->d_name, &st);
		printf("%d\t%s\n", st.st_blocks/2, path);
		if(S_ISDIR(st.st_mode)){
			char nx_path[1024];
			int len = snprintf(nx_path, sizeof(nx_path)-1, "%s/%s", path, direct->d_name);
			nx_path[len] = 0;
			if (strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
                continue;
			recur(nx_path);
			//printf("%d\t%s\n", st.st_blocks/2, nx_path);
		}
	}	while (direct = readdir(dir));*/
	
		stat(direct->d_name, &fst);
		printf("%d\t%s\n", fst.st_blocks/2, path);
		
	while (direct = readdir(dir)){
		statvfs(direct->d_name, &stats);
		stat(direct->d_name, &st);
		if(S_ISDIR(st.st_mode)){
				char nx_path[1024];
				int len = snprintf(nx_path, sizeof(nx_path)-1, "%s/%s", path, direct->d_name);
				nx_path[len] = 0;
				if (strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
					continue;
				recur(nx_path);
				//printf("%d\t%s\n", st.st_blocks/2, nx_path);
		}
		else{
			char n_path[1024];
			int len = snprintf(n_path, sizeof(n_path)-1, "%s/%s", path, direct->d_name);
			n_path[len] = 0;
			printf("%d\t%s\n", st.st_blocks/2, n_path);
		}
	}
	
	closedir(dir);
			
}

int main(int argc, char* args[])
{
	if(argc < 2){
		printf("Error: no input file specified\nUsage: mydu SamplePath\n");
		exit(1);
	}
	
	recur(args[1]);
	
	return 0;
}
