#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>

/**
基础方法
 */
typedef struct ListNode
{
    int val;               // 节点值
    struct ListNode *next; // 指向下一节点的指针
} ListNode;

void printList(ListNode *);
ListNode * createNode(int val);
void freeList(ListNode *head);

/**
增删改查
 */
void addFirst(ListNode **head,int val);
void addIndex(ListNode* head, int index,int val);
void addLast(ListNode* last,int val);

void removeFirst(ListNode **head);
void removeIndex(ListNode *head,int index);
void removeLast(ListNode *head);

ListNode* get(ListNode *head, int index);

#endif
