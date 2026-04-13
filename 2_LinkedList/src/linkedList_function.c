#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void printList(ListNode *head)
{
    int i = 1;
    while (head!= NULL)
    {
        printf("第%d个节点的值为: %d\n", i, head->val);
        i++;
        head = head->next;
    } 
}

ListNode * createNode(int val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    //有可能内存碎片严重或者内存不足，导致分配失败
    if(node == NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(ListNode *head)
{
    while(head != NULL)
    {
        //每个节点都free掉，否则会造成内存泄漏
        ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}



//难点
//由于头节点head是一个指针，所以需要传入头节点的地址（指针自己的地址）
//这样才可以有效改变指针的值，不然我们只能拷贝一个指向同样head内容的指针
//但是无法改变指针本身
//注意传入的是头节点的地址，如果不用二级指针无法有效改变头节点
void addFirst(ListNode **head,int val)
{
    ListNode *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void addIndex(ListNode* head, int index,int val)
{
    ListNode *newNode = createNode(val);
    ListNode *current = head;
    //先找到前驱节点,从0开始往前走到index-2这个位置
    //想不明白可以先以index = 3为例写死
    for(int i = 0; i<index-1;i++)
    {
        current = current->next;
    }
    //注意连接顺序
    //新节点指向后继节点
    newNode->next = current->next;
    //前驱节点指向新节点
    current->next = newNode;
}

void addLast(ListNode* head,int val)
{
    ListNode *newNode = createNode(val);
    ListNode *current = head;
    //找到原始链表的尾节点
    while(current->next !=NULL)
    {
        current = current->next;
    }
    //前驱节点指向新节点
    current->next = newNode;
}




/**
删除节点
 */
void removeFirst(ListNode **head)
{
if(*head == NULL){
    printf("链表为空\n");
    return;//void函数不能return NULL
}
ListNode *temp = *head;
*head = (*head)->next;
free(temp);
}

void removeIndex(ListNode *head, int index)
{
    if(head == NULL){
    printf("链表为空\n");
    return;
}
 // ⚠️ 如果index=0，无法删除头节点
    if(index == 0) {
        printf("无法删除头节点,请使用removeFirst函数\n");
        return;
    }


    ListNode *current = head;
    //长度4，删除点假设是第3个，则需要找到第2个,前驱节点
    for(int i = 0; i<index-1;i++)
    {
        current = current->next;
    }
    //先储存这个前驱节点
    ListNode *prev = current;
    //储存删除节点
    ListNode *next = current->next;
    //前驱节点指向后继节点
    prev->next = current->next->next;
    //释放删除节点
    free(next);
}

void removeLast(ListNode *head)
{
    if(head == NULL){
    printf("链表为空\n");
    return;
    }

    // ⚠️ 如果只有一个节点，无法删除（因为会影响头指针）
    if(head->next == NULL) {
        printf("只有一个节点，无法删除，请使用removeFirst函数\n");
        return;
    }


    ListNode *current = head;
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    ListNode *prev = current;
    ListNode *temp = current->next;
    prev->next = NULL;
    //释放尾节点
    free(temp);
}

ListNode* get(ListNode *head, int index)
{
    if(head == NULL){
        printf("链表为空\n");
        return NULL;
    }
    ListNode *current = head;
    for(int i = 0; i < index; i++){
        if(current == NULL) {  // 添加边界检查
            printf("索引超出范围\n");
            return NULL;
        }
        current = current->next;
    }
    ListNode *temp = current;
    return temp;
}
