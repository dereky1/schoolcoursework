//Derek Yang 63118832
#include <stdlib.h>
#include <stdio.h>

char disk[100];
int mem[100];

typedef struct{
  char* ptr;
  int size;
  int index;
} Xalloc_struct;

void disk_init(){
//mark all disk space as free.
	int i;
	for(i=0; i<100; ++i)
		disk[i] = 'e';

	int x;
	for(x=0; x<100; ++x)
		mem[x] = 0;

}

Xalloc_struct* Xalloc(int size){
//allocate the appropriate space and return a pointer to the first byte of that space in disk.  if there is not enough space, return NULL.
	Xalloc_struct* temp = malloc(sizeof(Xalloc_struct));
	int x;
	for(x=0; x<100; ++x){
		int seq = 0;
		if(mem[x] == 0){
			if(x+size < 100){
				int y;
				for(y=0; y<size; ++y){
					if(mem[x+y] == 0)
						seq++;
					else break;
				}
				if(seq >= size){	
					int z;
					for(z=0; z<size; ++z){
						mem[x+z] = 1;
						disk[x+z] = 'f';
					}		
					temp->ptr = &disk[x];
					temp->size = size;
					temp->index = x;
					return temp;
				}			
			}
			else break;
		}
	}
	return NULL;
}

int Xfree(void* ptr){
//free the space pointed to by ptr.  if the pointer is NULL do nothing.  return 0 on success and 1 on an error.
		
	if(ptr == NULL)
		return 1;
	 
	Xalloc_struct* temp = ptr;
	int index = temp->index;
	int x;  
	for(x=0; x<temp->size; ++x){	
		mem[index+x] = 0;
		disk[index+x] = 'e';
	}
	
	return 0;
}

void print_disk_map(){
//print as a series of 0 and 1 the status of the disk, for example if the first three bytes are allocated and the rest are free print 1110000000000. . .
	int x;
	for(x=0; x<100; ++x)
		printf("%d", mem[x]);
	printf("\n");
}

int main(){
  disk_init();

  Xalloc_struct* x = Xalloc(5);
//printf("Allocating X:5:\n");
 // print_disk_map();
  Xalloc_struct* y = Xalloc(10);
//printf("Allocating Y:10:\n");
 // print_disk_map();
  Xfree(x);	
//printf("Freeing X:5:\n");
 // print_disk_map();
  Xalloc_struct* z = Xalloc(2);
//printf("Allocating Z:2:\n");
 // print_disk_map();
  x = Xalloc(50);
//printf("Allocating X:50:\n");
 // print_disk_map();
  Xalloc_struct* a = Xalloc(100);
//printf("Allocating A:100:\n");
 // print_disk_map();
  Xfree(y);
//printf("Freeing Y:10:\n");
 // print_disk_map();
  y = Xalloc(5);
//printf("Allocating Y:5:\n");
 // print_disk_map();
  Xalloc_struct* b = Xalloc(4);
//printf("Allocating B:4:\n");
 // print_disk_map();
  Xfree(a);
//printf("Freeing A:100:\n");
  //print_disk_map();
  a = Xalloc(1);
//printf("Allocating A:1:\n");
  print_disk_map();

  return 0;

}
