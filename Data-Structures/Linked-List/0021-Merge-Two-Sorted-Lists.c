#include <stdio.h>
#include <stdlib.h>
#include "../../lib/linked_list.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (!list1) return list2;
	else if(!list2) return list1;
	struct ListNode *cursor=(list1->value < list2->value)?list1:list2;
	struct ListNode *temp=cursor;
	if(list1->value < list2->value)	list1=list1->next;
	else list2=list2->next;
	while(list1 && list2){
		if(list1->value<=list2->value) {
			cursor->next=list1;
			list1=list1->next;
		}
		else{
			cursor->next=list2;
			list2=list2->next;
		}
		cursor=cursor->next;
	}
	if(list1){
		cursor->next=list1;
	}
	if(list2){
		cursor->next=list2;
	}
	return temp;
}

int main(){
	List *list1=NULL;
	List *list2=NULL;
	list1=addNode(list1,2);
	list1=addNode(list1,5);
	list1=addNode(list1,7);
	list2=addNode(list2,1);
	list2=addNode(list2,3);
	list2=addNode(list2,4);
	print_list(list1);
	print_list(list2);
	List *list_sorted=mergeTwoLists(list1,list2);
	print_list(list_sorted);
}
