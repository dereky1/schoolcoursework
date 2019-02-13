#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

void recur(char* path)
{
	DIR* dir;
	struct dirent* direct;
	struct stat st;
	struct group* grp;
	struct passwd* pwd;
	struct tm* time;
	int count = 0;
	
	if(!(dir = opendir(path))){
		//printf("Error Opening Directory\n");
		return;
	}
	
	if(!(direct = readdir(dir))){
		printf("Error Reading Directory\n");
		exit(1);
	}
	
	do{
		stat(direct->d_name, &st);
		if(count++ == 0)
			printf("%s:\ntotal: %d\n", path, st.st_blocks - 8);
		if (strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
			continue;
		
	// Print Mode
		printf((S_ISDIR(st.st_mode))?"d":"-");
		printf((st.st_mode & S_IRUSR)?"r":"-");
		printf((st.st_mode & S_IWUSR)?"w":"-");
		printf((st.st_mode & S_IXUSR)?"x":"-");
		printf((st.st_mode & S_IRGRP)?"r":"-");
		printf((st.st_mode & S_IWGRP)?"w":"-");
		printf((st.st_mode & S_IXGRP)?"x":"-");
		printf((st.st_mode & S_IROTH)?"r":"-");
		printf((st.st_mode & S_IWOTH)?"w:":"-");
		printf((st.st_mode & S_IXOTH)?"x ":"- ");
	// print links
		printf("%d ", st.st_nlink);
	//print user id and group id
		pwd = getpwuid(st.st_uid);
		printf("%s ", pwd->pw_name);
		grp = getgrgid(st.st_gid);
		printf("%s ", grp->gr_name);
	//print size
		printf("%5d ", st.st_size);
	//print time
		time = localtime(&st.st_mtime);
		switch(time->tm_mon){
		case 0:	printf("Jan "); break;
		case 1: printf("Feb "); break;
		case 2: printf("Mar "); break;
		case 3: printf("Apr "); break;
		case 4: printf("May "); break;
		case 5: printf("Jun "); break;
		case 6: printf("Jul "); break;
		case 7: printf("Aug "); break;
		case 8: printf("Sep "); break;
		case 9: printf("Oct "); break;
		case 10: printf("Nov "); break;
		case 11: printf("Dec "); break;
		}
		
		printf("%d ", time->tm_mday);
		if(time->tm_hour < 10)
			printf(" %d:", time->tm_hour);
		else	
			printf("%d:", time->tm_hour);
		
		if(time->tm_min < 10)
			printf("0%d %d ", time->tm_min, time->tm_year+1900);
		else
			printf("%d %d ", time->tm_min, time->tm_year+1900);
		printf("%s\n", direct->d_name);
	}	while (direct = readdir(dir));
	
	closedir(dir);
	
	if(!(dir = opendir(path))){
		printf("Error Opening Directory\n");
		exit(1);
	}
	
	if(!(direct = readdir(dir))){
		printf("Error Reading Directory\n");
		exit(1);
	}
	
	do{
		stat(direct->d_name, &st);
		if(S_ISDIR(st.st_mode)){
			char nx_path[1024];
			int len = snprintf(nx_path, sizeof(nx_path)-1, "%s/%s", path, direct->d_name);
			nx_path[len] = 0;
			if (strcmp(direct->d_name, ".") == 0 || strcmp(direct->d_name, "..") == 0)
				continue;
			recur(nx_path);
		}
	}	while (direct = readdir(dir));
	
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
