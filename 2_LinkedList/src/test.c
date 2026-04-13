/**
这个测试只用来体现二级指针的效果
以及演示地址分配
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;

void printList(ListNode *head);
ListNode * createNode(int val);
void freeList(ListNode *head);
void addFirst(ListNode **head,int val);

int main()
{
    ListNode *head1;
    int length;
    printf("请输入链表长度：\n");
    scanf("%d", &length);

    head1 = createNode(1);
    ListNode *current = head1;
    for(int i = 1; i<length; i++){
        ListNode *temp = createNode(i+1);
        current->next = temp;
        current = temp;
    }
    printList(head1);
    printf("--------------------------------\n");

    printf("添加前head1的地址是:%p\n", head1);
    printf("head1指针自己的值是:%p\n", &head1);
    addFirst(&head1,0);
    printf("添加完0后\n");
    printf("添加完后head1的地址是:%p\n", head1);
    printf("head1指针自己的值是:%p\n", &head1);
    printList(head1);


    freeList(head1);
    return 0;
}





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
        ListNode *temp = head;
        head = head->next;
        free(temp);
    }
}

//原先错误方法


// void addFirst(ListNode *head,int val)
// {
//     printf("head的地址是:%p\n", head);
//     printf("head指针自己的值是:%p\n", &head);
//     ListNode *newNode = createNode(val);
//     newNode->next = head;
//     head = newNode;//将新节点的值写入head指针但是没有改变原链表

//     printf("head此时在函数内的地址是:%p\n", head);
//     //相当于函数内head这个拷贝指针指向了另一个地址，但是原head指针的值没有改变
// }


//改进方法

void addFirst(ListNode **head,int val)
{   
    printf("head参数的地址是:%p\n", head);           // 指向main中head1变量的地址
    printf("*head指向的节点地址是:%p\n", *head);      // 节点地址
    printf("head指针自己的值是:%p\n", &head);

    ListNode *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;  // 修改main中head1的值
    
    printf("修改后*head指向的节点地址是:%p\n", *head);
}