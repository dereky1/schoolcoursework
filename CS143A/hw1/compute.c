#include <stdio.h>
#include <stdlib.h>

int main(int argc ,char** args[] )
{
	if (argc > 1)
	{
		printf("Error: no input file specified\nUsage: compute < SampleInput\n");
		exit(1);
	}

	double average;
	double min;
	double max;
	double num;
	int count = 0;
	
	while(scanf("%lf", &num) != EOF)
	{	
		if(count == 0)
		{	
			min = num;	
			max = num;
		}
		else
		{
			if(num < min)
				min = num;
			else if(num > max)
				max = num;
		}
		average += num;
		count++;
	}
	
	if (count == 0)
	{
		printf("No numbers found in file!\n");
		exit(3);
	}

	average = average / count;
	printf("max: %lf\nmin: %lf\naverage: %lf\n", max, min, average);

	return 0;
}
