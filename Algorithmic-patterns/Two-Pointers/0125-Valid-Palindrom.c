#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
	int size=strlen(s);
	char *start=s,*tail=(s+size-1); 
	for(int i=0;s[i];i++){
		if(!isalnum(*start)){
			if(start == tail) return true;
			start++;
			continue;
		}
		if(!isalnum(*tail)){
			tail--;
			continue;
		}
		if(start>tail) return true;
		if(tolower(*start) == tolower(*tail)){
			if(start == tail ){
				return true;
			}
			start++;
			tail--;
			continue;
		}
		else return false;
	}
	return true; 
}

void printSolution(char *s,bool valid){
	if(valid){
		fputs(s,stdout);
		printf("\nIS A VALID PALINDROM\n");
	}
	else{
		fputs(s,stdout);
		printf("\nIS NOT A VALID PALINDROM\n");
	}
}

int main(){
	char example1[]="A man, a plan, a canal: Panama";
	char example2[]="race a car";
	char example3[]=" ";
	printSolution(example1,isPalindrome(example1));
	printSolution(example2,isPalindrome(example2));
	printSolution(example3,isPalindrome(example3));
}
