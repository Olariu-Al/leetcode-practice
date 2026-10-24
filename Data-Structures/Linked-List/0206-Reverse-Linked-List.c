#include <stdio.h>
#include <stdlib.h>
#include "../../lib/linked_list.h"

struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL) return NULL;
   struct ListNode *cursor=head->next;
   if(cursor == NULL){
   	 return head;
   }
   head->next=NULL;
   for(struct ListNode *cursorhead=cursor->next;cursorhead;cursorhead=cursorhead->next){
   	cursor->next=head;
   	head=cursor;
   	cursor=cursorhead;
   }
   cursor->next=head;
   return cursor;
}

int main(){
	List *list=NULL;
	list=addNode(list,1);
	list=addNode(list,2);
	list=addNode(list,3);
	list=addNode(list,4);
	list=addNode(list,5);
	print_list(list);
	list=reverseList(list);
	print_list(list);
}
