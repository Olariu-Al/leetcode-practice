#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdbool.h>
#define START_VALUE 100


bool isValid(char* s) {
	int currentsize=START_VALUE,cursor=0;
	char *stack=malloc(sizeof(char)*currentsize);
	for(int i=0;s[i];i++){
		if(s[i] == '[' || s[i] == '{' || s[i] == '('){
			if(cursor+1 == currentsize){
				currentsize*=2;
				stack=realloc(stack,sizeof(char)*currentsize);
			}
			stack[cursor++]=s[i];
		}
		else if(s[i] == ']'){
			if(cursor <= 0) return false;
			if(stack[--cursor] == '[') continue;
			return false;
		}
		else if(s[i] == ')') {
			if(cursor <= 0) return false;
			if(stack[--cursor] == '(') continue;
			return false;
		}
		else if(s[i] == '}'){
			if(cursor <= 0) return false;
			if(stack[--cursor] == '{') continue;
			return false;
		}
		else return false;
	}
	if (cursor != 0) return false;
	return true;
}

void printSolution(char *s,bool valid){
	fputs(s,stdout);
	if(valid) printf(" is valid\n");
	else printf(" is not valid\n");
}

int main(){
	char s1[]="()",s2[]="()[]{}",s3[]="(]",s4[]="([])",s5[]="([)]";
	printSolution(s1,isValid(s1));
	printSolution(s2,isValid(s2));
	printSolution(s3,isValid(s3));
	printSolution(s4,isValid(s4));
	printSolution(s5,isValid(s5));
}
