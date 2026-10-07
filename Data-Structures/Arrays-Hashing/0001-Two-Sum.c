#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STARTING_SIZE 100
#define RESIZE 0.75

typedef struct hashMap{
	int value;
	int key;
	struct hashMap* next;
}hash;

int getHash(int sizeTracker,int value){
	value=((value>=0) ? value:-value);
	return value%sizeTracker;
}

hash *newNode(int value,int key){
	hash *temp=malloc(sizeof(hash));
	temp->value=value;
	temp->key=key;
	temp->next=NULL;
	return temp;
}

bool checkInMap(hash **map,int target,int size,int curentKey){
	hash *curent=map[getHash(size,target)];
	for(;curent!=NULL && (curent->value != target || curent->key==curentKey);curent=curent->next);
	if(curent != NULL) return true;
	return false;
}

int *getInMap(hash **map,int number1,int number2,int size){
	int *solution=malloc(sizeof(int)*2),key1,key2;
	hash *cursor=map[getHash(size,number1)];
	for(;cursor->value != number1;cursor=cursor->next);
	key1=cursor->key;
	for(cursor=map[getHash(size,number2)];cursor->value != number2 || cursor->key==key1;cursor=cursor->next);
	key2=cursor->key;
	solution[0]=key1;
	solution[1]=key2;
	return solution;
}

hash **addInMap(hash **map,int value,int size,int key){
	hash *curent=map[getHash(size,value)];
	if(curent==NULL){
		map[getHash(size,value)]=newNode(value,key);
		return map;
	}
	for(;curent->next;curent=curent->next);
	curent->next=newNode(value,key);
	return map;
}

void freeList(hash *start){
	hash *temp=start;
	start=start->next;
	for(;start;start=start->next){
		free(temp);
		temp=start;
	}
	if(temp != NULL) free(temp);
}

void freeMap(hash **map,int size){
	for(int i=0;i<size;i++){
		if(map[i] == NULL) continue;
		freeList(map[i]);
	}
	free(map);
}

hash **resizeMap(hash **map,int size){
	int lastsize=size/2;
	hash *cursor=map[0];
	hash **newmap=calloc(size,sizeof(hash*));
	for(int i=0;i<lastsize;i++){
		cursor=map[i];
		for(cursor=map[i];cursor;cursor=cursor->next){
			newmap=addInMap(newmap,cursor->value,size,cursor->key);
		}
	}
	freeMap(map,lastsize);
	return newmap;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize=2; // it can ever only be 2 
	int count=0,sizeTracker=STARTING_SIZE,
		*solution=NULL;
	hash **map=calloc(STARTING_SIZE,sizeof(hash*));
	for(int i=0;i<numsSize;i++){
		count++;
		map=addInMap(map,nums[i],sizeTracker,i);
		if(checkInMap(map,target-nums[i],sizeTracker,i)){
			solution=getInMap(map,nums[i],target-nums[i],sizeTracker);
			freeMap(map,sizeTracker);
			return solution;
		}
		if (((double)count/(double)sizeTracker) > RESIZE){
			sizeTracker*=2;
			map=resizeMap(map,sizeTracker);
		}
	}
	return NULL;
}

void printSolution(int *nums,int numsSize,int target,int *two){
	printf("[");
	int i;
	for(i=0;i<numsSize-1;i++){
		printf("%d, ", nums[i]);
	}
	printf("%d]\n",nums[i]);
	printf("target:%d\n",target);
	if(!two) printf("No solution\n");
	printf("Solution:[%d,%d]\n",two[0],two[1]);
}

int main(){
	int nums1[]={2,7,11,15},nums2[]={3,2,4},nums3[]={3,3};
	int target1=9,target2=6,target3=6,buffer=2;
	int *solutie=NULL;
	solutie=twoSum(nums1,4,target1,&buffer);
	printSolution(nums1,4,target1,solutie);
	if(solutie != NULL) free(solutie);
	solutie=twoSum(nums2,3,target2,&buffer);
	printSolution(nums2,3,target2,solutie);
	if(solutie != NULL) free(solutie);
	solutie=twoSum(nums3,2,target3,&buffer);
	printSolution(nums3,2,target3,solutie);
	if(solutie != NULL) free(solutie);
}
