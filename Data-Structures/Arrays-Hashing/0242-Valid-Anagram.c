#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_ALFABET 26

bool isAnagram(char* s, char* t) {
    int alfabet[MAX_ALFABET]={0},i;
    for(i=0;s[i] && t[i];i++){
    	alfabet[(s[i]-'a')]++;
    	alfabet[(t[i]-'a')]--;
    }
    if(s[i] || t[i]) return false;
    for(int i=0;i<MAX_ALFABET;i++){
    	if(alfabet[i] != 0) {
    		return false;
    	}
    }
    return true;
}

int main(){
	char t[]="anagrams";
	char s[]="nagaramt";
	if(isAnagram(t,s)) printf("They are an Anagram\n");
	else printf("They are not an Anagram\n");
}
