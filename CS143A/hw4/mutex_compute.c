#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <float.h>

pthread_mutex_t lock;
int eof = 0;

typedef struct myStruct{
	double sum;
	double average;
	double min;
	double max;
	int count;
}myStruct;

void *thread_action(void *argu)
{	
	struct myStruct *args = (struct myStruct*)argu;

	double num;
	while(1){
		if(eof == 1)
			return NULL;
		pthread_mutex_lock(&lock);
		if(scanf("%lf", &num)==EOF){
			eof = 1;
			pthread_mutex_unlock(&lock);
			break;
		}
		pthread_mutex_unlock(&lock);	
	
		if(num<(*args).min)
			(*args).min = num;
		if(num>(*args).max)	
			(*args).max = num;
		
		(*args).sum += num;
		(*args).count++;	
	}	
	
	return NULL;
}


int main(int argc, char** args[])
{
	if(argc > 1){
		printf("Error: no input file specified\nUsage: compute < SampleInput\n");
		exit(1);
	}

	myStruct argu;
	argu.sum = 0;
	argu.min = 9999;
	argu.max = -9999;
	argu.average = 0;
	argu.count = 0;

	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;
	
	if(pthread_mutex_init(&lock, NULL) !=0){
		printf("Couldn't create lock!\n");
		exit(1);
	}

	if(pthread_create(&thread1, NULL, &thread_action, &argu)){
		printf("Couldn't create thread!\n");
		exit(1);
	}

	if(pthread_create(&thread2, NULL, &thread_action, &argu)){
		printf("Couldn't create thread!\n");
		exit(1);
	}

	if(pthread_create(&thread3, NULL, &thread_action, &argu)){
		printf("Couldn't create thread!\n");
		exit(1);
	}
	
	thread_action(&argu);


	if(pthread_join(thread1, NULL)){
		printf("Couldn't join first thread!");
		exit(1);
	}
	if(pthread_join(thread2, NULL)){
		printf("Couldn't join second thread!");
		exit(1);
	}
	if(pthread_join(thread3, NULL)){
		printf("Couldn't join last thread!");
		exit(1);
	}
	

	argu.average = argu.sum / argu.count;	


	printf("max: %lf\nmin: %lf\naverage: %lf\n", argu.max, argu.min, argu.average);
	pthread_mutex_destroy(&lock);

	return 0;
}
