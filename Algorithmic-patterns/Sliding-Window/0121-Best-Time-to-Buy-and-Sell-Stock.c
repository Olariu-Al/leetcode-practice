#include <stdio.h>
//O(n) 
int maxProfit(int* prices, int pricesSize) {
	int max=0,min=1000000;
	for(int i=0;i<pricesSize;i++){
		min=(min<prices[i]) ? min:prices[i];
		if(max<prices[i]-min) max=prices[i]-min;
	}
	return max;
}

void printSolution(int *nums,int numsSize,int maxProf){
	printf("{");
	for(int i=0;i<numsSize-1;i++){
		printf("%d,",nums[i]);
	}
	printf("%d} || maxProfit: %d\n\n",nums[numsSize-1],maxProf);
}

int main(){
	int example1[]={7,1,5,3,6,4},size1=6,example2[]={7,6,4,3,1},size2=5;
	printSolution(example1,size1,maxProfit(example1,size1));
	printSolution(example2,size2,maxProfit(example2,size2));
}
