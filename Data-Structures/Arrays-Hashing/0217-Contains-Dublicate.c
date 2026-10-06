#include <stdio.h>
#include <stdbool.h>
// O(n^2), will try to do in O(n) once i understand hashmaps

bool containsDuplicate(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
    	for(int j=i+1;j<numsSize;j++){
    		if(nums[i] == nums[j]){
    			return true;
    		}
    	}
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
	int example1[]={1,2,3,1}, example2[]={1,2,3,4}, example3[]={1,1,1,3,3,4,3,2,4,2};
	int size1=4,size2=4,size3=10;
	printSolution(example1,size1,containsDuplicate(example1,size1));
	printSolution(example2,size2,containsDuplicate(example2,size2));
	printSolution(example3,size3,containsDuplicate(example2,size3));
}
