/////// Derek Yang 63118832
/////// James Kim 59088715

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int block = 1;

unsigned char binarize(int num, int alloc, int mode)
{
	unsigned char bin;
	
	int i;
	for(i = 7; i >= 0 ; --i)
		bin = num >> i;

	bin <<= 1;
	if(mode == 0)
		bin |= alloc;	

	return bin;
}

unsigned char unbin(unsigned char c)
{
	unsigned char bin = c;
	bin >>= 1;
	return bin;
}

int is_alloc(unsigned char c)
{
	return (c & 1);
}

unsigned char* allocate(unsigned char *heap, int id, int blocks)
{
	unsigned char* temp = heap;
	int i=0;	
	
	if(blocks >= 128){
		printf("Not Enough Memory in Heap\n");
		return heap;
	}

	while(i <= 128 && (is_alloc(*(temp+i+1)) == 1 || (unbin(*(temp+i+1)) < blocks &&
		 unbin(*(temp+i+1)) != 0))){
		i += unbin(*(temp+i+1));
		if(i == 128){
			printf("Not Enough Memory in Heap\n");
			return heap;
		}
	}

	if(*(temp+i+blocks) == 0 && *(temp+i+blocks+1) == 0){
		*(temp+i+blocks) = 0;
		*(temp+i+blocks+1) = binarize(unbin(*(temp+i+1))-blocks, 0, 1);
	}

	*(temp+i) = (char)id;
	*(temp+i+1) = binarize(blocks, 1, 0);
	
	printf("%d\n", id);
	block++;
	return temp;
		
}

unsigned char* freebee(unsigned char *heap, unsigned char id)
{
	unsigned char* temp = heap;
	int i = 0;

	while(i < 128){
		if(*(temp+i) != id){
			i += unbin(*(temp+i+1));
		}
		else{
			*(temp+i+1) >>= 1;
			*(temp+i+1) <<= 1;
			int j;
			for(j = 2; j < unbin(*(temp+i+1)); ++j)
				*(temp+i+j) &= 0;
			printf("%d\n", id);
			return temp;
		}
	}
	
	printf("Block %d is not in the heap!\n", id);

	return temp;
}

void print_head(unsigned char *heap, unsigned char id)
{
	unsigned char* temp = heap;
	int i = 0;

	while(i < 128){
		if(*(temp+i) != id){
			i += unbin(*(temp+i+1));
		}
		else{
			printf("%02hhx%02hhx\n", *(temp+i), *(temp+1+i));
			return;
		}
	}

	printf("Block %d is not in the heap!\n", id);
	return;
}

void print_heap(unsigned char *heap, unsigned char id, int amount)
{
	unsigned char* temp = heap;
	int i = 0;

	while(i < 128){
		if(*(temp+i) != id){
			i += unbin(*(temp+i+1));
		}
		else{
			int j;
			for(j=2; j<amount+2; ++j)
				printf("%c", *(temp+i+j));
			printf("\n");
			return;
		}
	}

	printf("Block %d is not in the heap!\n", id);
	return; 	
}

unsigned char* write_heap(unsigned char *heap, unsigned char id, unsigned char sym, int amount)
{
	unsigned char* temp = heap;
	int i = 0;

	while(i < 128){
		if(*(temp+i) != id){
			i += unbin(*(temp+i+1));
		}
		else{	
			if(amount > unbin(*(temp+i+1))-2){
				printf("Write too big\n");
				return heap;
			}
			
			if(is_alloc(*(temp+i+1)) == 0){
				printf("Block is no longer allocated\n");
				return heap;
			}

			int j;
			for(j=2; j<amount+2; ++j){
				*(temp+i+j) = sym;
			}
			return temp;
		}
	}

	printf("Block %d is not in the heap!\n", id);
	return heap; 
}

void blocklist(unsigned char *heap)
{
	printf("Size Allocated Start             End\n");
	
	int i=0;
	int free;
	unsigned char size;
	unsigned char* temp = heap;
	
	while(i < 128 /*&& (is_alloc(*(temp+i+1)) == 1)*/){
		size = unbin(*(temp+i+1));
		free = is_alloc(*(temp+i+1));
		printf("%-4d %-9s %-17p %-9p\n", size, (free == 0) ? "no" : "yes", temp+i, temp+i+size-1);
		i += unbin(*(temp+i+1));
	}

	return;
}

int main()
{
	char line[256];
	char command[128];
	int num[3] = {-1,-1,-1};
	char sym[3] = {'0','0','0'};
	char* tok;
	unsigned char* heap = (char*) malloc(128 * sizeof(char));
	*heap = 0;
	*(heap+1) = binarize(128, 0, 1);	

	while(printf("> ")){
		fgets(line, 256, stdin);
		tok = strtok(line, " ");
		int count = 0; 
		while(tok != NULL){
			if(count == 0)
				sscanf(tok, "%s", command);
			else{
				sscanf(tok, "%c", &sym[count-1]);
				sscanf(tok, "%d", &num[count-1]);
			}
			tok = strtok(NULL, " ");
			count++;
		}
		
		if(strcmp(command, "allocate") == 0 && count == 2 && num[0] >= 0){
			heap = allocate(heap, block, num[0]+2);	
		} 
		else if(strcmp(command, "free") == 0 && count == 2 && num[0] >= 0){
			heap = freebee(heap, num[0]);
		}
		else if(strcmp(command, "printheader") == 0 && count == 2 && num[0] >= 0){
			print_head(heap, num[0]);
		}
		else if(strcmp(command, "printheap") == 0 && count == 3 && num[0] >= 0 && num[1] >= 0){
			print_heap(heap, num[0], num[1]);
		}
		else if(strcmp(command, "writeheap") == 0 && count == 4 && num[0] >= 0 && num[2] >= 0){
			heap = write_heap(heap, num[0], sym[1], num[2]);	
		}
		else if(strcmp(command, "blocklist") == 0 && count == 1){
			blocklist(heap);
		}
		else if(strcmp(command, "quit") == 0 && count == 1){
			exit(0);
		}
		else{
			printf("ERROR: Invalid Command!\n");
		}
	}
	
	return 0;
}