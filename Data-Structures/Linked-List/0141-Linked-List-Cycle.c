#include <stdio.h>
#include "../../lib/linked_list.h"
#include <stdbool.h>

bool hasCycle(struct ListNode *head) {
	if(!head) return false;
    struct ListNode *slow=head;
    struct ListNode *fast=head->next;
    while(fast && fast->next){
    	if(fast == slow) return true;
    	slow=slow->next;
    	fast=fast->next->next;
    }
    return false;
}

int main(){
	List *list1=NULL;
	List *temp=NULL;
	list1=addNode(list1,2);
	list1=addNode(list1,5);
	list1=addNode(list1,7);
	temp=list1->next->next;
	list1=addNode(list1,1);
	list1=addNode(list1,3);
	list1=addNode(list1,4);
	list1->next->next->next->next->next=temp;
	if(hasCycle(list1)) printf("Has Cycle\n");
	else printf("Doesnt Cycle\n");
}
