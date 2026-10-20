#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target) {
	int lower=0,upper=numsSize-1,temp=(lower+upper)/2;
	if(nums[upper] == target) return upper;
	if(nums[lower] == target) return lower;
 	while(1){
		if(nums[temp]==target){
			return temp;
		}
		if(lower == temp || temp == upper) return -1;
		if(nums[temp] <target){
			lower=temp;
			temp=(lower+upper)/2;
		}
		else{
			upper=temp;
			temp=(lower+upper)/2;
		}
		printf("lower %d upper %d\n",lower,upper);
	}
}

void printSolution(int *nums,int numsSize,int target,int index){
	printf("{");
	int i;
	for(i=0;i<numsSize-1;i++){
		printf("%d, ",nums[i]);
	}
	printf("%d} and target %d\n",nums[i],target);
	if(index == -1){
		printf("The target doesnt exist\n");
	}
	else{
		printf("Target found at %d index\n",index);
	}
}

int main(){
	int example1[]={-1,0,3,5,9,12},target1=9,
		example2[]={-1,0,3,5,9,12},target2=2;
	printSolution(example1,6,target1,search(example1,6,target1));
	printSolution(example2,6,target2,search(example2,6,target2)); //hardcoded the sizes of the vectors
}
