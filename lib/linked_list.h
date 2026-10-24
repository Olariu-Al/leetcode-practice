#ifndef	LINKED_LIST_H
#define LINKED_LIST_H
typedef struct ListNode {
    int value;
    struct ListNode *next;
} List;

void print_list(List*);
List* newNode(int);
List *addNode(List *,int);
List *addNodeAscending(List*,int);

#endif
