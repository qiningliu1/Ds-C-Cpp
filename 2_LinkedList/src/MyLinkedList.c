#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"



int main()
{
    ListNode *head1;
    int length;
    printf("请输入链表长度：\n");
    scanf("%d", &length);

    head1 = createNode(1);
    ListNode *current = head1;
    for(int i = 1; i<length; i++)
    {
        ListNode *node = createNode(i+1);
        current->next = node;
        current = node;
    }

    printList(head1);
    freeList(head1);
    return 0;
}

