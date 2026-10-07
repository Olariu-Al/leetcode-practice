#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STARTING_SIZE 3000
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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize=2; // it can ever only be 2 
	int count=0,sizeTracker=STARTING_SIZE,
		*solution=NULL;
	hash **map=calloc(STARTING_SIZE,sizeof(hash*));
	for(int i=0;i<numsSize;i++){
		count++;
		map=addInMap(map,nums[i],sizeTracker,i);
		printf("%d added in Map\n",nums[i]);
		if(checkInMap(map,target-nums[i],sizeTracker,i)){
			solution=getInMap(map,nums[i],target-nums[i],sizeTracker);
			return solution;
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
