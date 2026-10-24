#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


void print_list(List* start){
	for(;start;start=start->next){
		printf("%d->",start->value);
	}
	printf("NULL\n");
}

List* newNode(int value){
	List *temp=malloc(sizeof(List));
	temp->next=NULL;
	temp->value=value;
	return temp;
}

List *addNode(List *start,int value){
	if(start == NULL){
		return newNode(value);
	}
	List *temp=start;
	for(;start->next;start=start->next);
	start->next=newNode(value);
	return temp;
}

List *addNodeAscending(List *start,int value){
	if(start == NULL) return newNode(value);
	List *temp=start;
	if(start->value>value){
		temp=newNode(value);
		temp->next=start;
		return temp;
	}
	for(;start->next && start->next->value<value;start=start->next);
	if(start->next == NULL){
		start->next=newNode(value);
	}
	List *temp2=newNode(value);
	temp2->next=start->next;
	start->next=temp2;
	return temp;
}
