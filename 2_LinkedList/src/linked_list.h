#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
struct Node{
    int data;
    struct Node* next; 
};


void printList(struct Node * head);

void add(struct Node** head,int data);
struct Node* remove(struct Node** head,int data);

int size(struct Node* head);

//c语言用int表示bool
int isEmpty(struct Node* head);


#endif
