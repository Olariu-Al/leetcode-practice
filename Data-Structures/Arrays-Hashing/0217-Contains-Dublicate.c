#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_HASH 1000
// IT WORKS BUT SLOW, will try to improve it further later, by adding dynamic resizing and we will see
typedef struct hasherElement{
	int val;
	struct hasherElement *next;
}hash;

int getHash(int val){
	val=(val>=0) ? val:-val;
	return val%MAX_HASH;
}

hash *createNode(int value){
	hash *temporary=malloc(sizeof(hash));
	temporary->val=value;
	temporary->next=NULL;
	return temporary;
}

hash **isInMap(hash **map,int value,bool *test){
	int hasher=getHash(value);
	if(map[hasher] == NULL){
		map[hasher]=createNode(value);
		*test=false;
		return map;
	}
	hash *cursor;
	for(cursor=map[hasher];cursor->next;cursor=cursor->next){
		if(cursor->val == value){
			*test=true;
			return map; 
		}
	}
	if(cursor->val == value){
		*test=true;
		return map;
	}
	cursor->next=createNode(value);
	return map;
}

bool containsDuplicate(int* nums, int numsSize) {
    hash **map=calloc(MAX_HASH,sizeof(hash*));
    bool tester;
    for(int i=0;i<numsSize;i++){
    	map=isInMap(map,nums[i],&tester);
    	if(tester) return true;
    	printf("%d has no dublicates yet\n",nums[i]);
    }
    return false;
}

void printSolution(int *nums,int numsSize,bool dublicate){
	printf("[");
	for(int i=0;i<numsSize-1;i++){
		printf("%d,",nums[i]);
	}
	printf("%d]",nums[numsSize-1]);
	if(dublicate) printf("\nDoes contain dublicates!\n");
	else printf("\nDoes not contain dublicates!\n");
}

int main(){
	int example1[]={1,2,3,1}, example2[]={1,2,3,4}, example3[]={1,1,1,3,3,4,3,2,4,2}, example4[]={-1,6,7,-5,-5};
	int size1=4,size2=4,size3=10,size4=5;
	printSolution(example1,size1,containsDuplicate(example1,size1));
	printSolution(example2,size2,containsDuplicate(example2,size2));
	printSolution(example3,size3,containsDuplicate(example3,size3));
	printSolution(example4,size4,containsDuplicate(example4,size4));
}
