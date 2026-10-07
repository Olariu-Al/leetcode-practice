#include <stdio.h>
#include <stdlib.h>
#define STARTING_SIZE 1000
// varianta neoptimizata O(n^2)
int sizeofHash=STARTING_SIZE;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize=2;
	int *solutie=malloc(sizeof(int)*2);
	for(int i=0;i<numsSize;i++){
		for(int j=i+1;j<numsSize;j++){
			if((nums[i]+nums[j]) == target){
				solutie[0]=nums[i];
				solutie[1]=nums[j];
				return solutie;
			}
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
	free(solutie);
	solutie=twoSum(nums2,3,target2,&buffer);
	printSolution(nums2,3,target2,solutie);
	free(solutie);
	solutie=twoSum(nums3,2,target3,&buffer);
	printSolution(nums3,2,target3,solutie);
	free(solutie);
}
