#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <float.h>


typedef struct myStruct{
	double *nums;
	double average;
	double min;
	double max;
	int split;
	int part;
	int split_odd;
	int odd_parts;
	
}myStruct;

void *thread_action(void *argu)
{	
	struct myStruct *args = (struct myStruct*)argu;

	int split;
	if((*args).split_odd > 0)
		split = (*args).split + 1;
	else
		split = (*args).split;	

	int nums[split];
	int b = 0;
	int a;	
	for(a = (*args).part*split; a<((*args).part+1)*split; ++a){
		if((*args).split_odd  <= 0)
			nums[b] = (*args).nums[a+(1*(*args).odd_parts)];
		else
			nums[b] = (*args).nums[a];
		b++;		
	}

	double count = 0; 
	double sum = 0;

	int i;
	for(i=0; i<split; ++i){	
		if(nums[i]<(*args).min)
			(*args).min = nums[i];
		if(nums[i]>(*args).max)	
			(*args).max = nums[i];
		
		sum += nums[i];	
		count++;
	}	

	
	(*args).average += sum;
	(*args).part++;
	(*args).split_odd--;

	return NULL;
}


int main(int argc, char** args[])
{
	if(argc > 1){
		printf("Error: no input file specified\nUsage: compute < SampleInput\n");
		exit(1);
	}
	
	double num;
	double numArray[1000];
	int count = 0;
	
	while(scanf("%lf", &num) != EOF){
		numArray[count] = num;	
		count++;
	}	
	
	myStruct argu;
	argu.split_odd = count % 4;
	argu.odd_parts = count % 4;
	argu.split = count/4;
	argu.min = numArray[0];
	argu.max = numArray[0];
	argu.average = 0;
	argu.nums = numArray;
	argu.part = 0;

	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	pthread_t thread4;

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
	
	thread_action(&argu);
	argu.average /= count;	


	printf("max: %lf\nmin: %lf\naverage: %lf\n", argu.max, argu.min, argu.average);

	return 0;
}
