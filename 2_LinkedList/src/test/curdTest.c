#include <stdio.h>
#include <stdlib.h>
#include "../linked_list.h"
#include "../linkedList_function.c"

int main()
{
    printf("=== 链表功能测试 ===\n\n");
    
    // 1. 创建初始链表
    printf("1. 创建初始链表 [1,2,3,4]\n");
    ListNode *head = createNode(1);
    addLast(head, 2);
    addLast(head, 3);
    addLast(head, 4);
    printList(head);
    printf("\n");
    
    // 2. 测试头部插入
    printf("2. 头部插入 0\n");
    addFirst(&head, 0);  // 注意传递&head
    printList(head);
    printf("\n");
    
    // 3. 测试指定位置插入
    printf("3. 在索引2位置插入 99\n");
    addIndex(head, 2, 99);
    printList(head);
    printf("\n");
    
    // 4. 测试尾部插入
    printf("4. 尾部插入 5\n");
    addLast(head, 5);
    printList(head);
    printf("\n");
    
    // 5. 测试查询功能
    printf("5. 查询测试\n");
    printf("索引0的节点值: %d\n", get(head, 0)->val);
    printf("索引3的节点值: %d\n", get(head, 3)->val);
    printf("索引6的节点值: %d\n", get(head, 6)->val);
    printf("\n");
    
    // 6. 测试删除头节点
    printf("6. 删除头节点\n");
    removeFirst(&head);  // 注意传递&head
    printList(head);
    printf("\n");
    
    // 7. 测试删除指定位置
    printf("7. 删除索引2位置的节点\n");
    removeIndex(head, 2);
    printList(head);
    printf("\n");
    
    // 8. 测试删除尾节点
    printf("8. 删除尾节点\n");
    removeLast(head);
    printList(head);
    printf("\n");
    
    // 9. 边界测试
    printf("9. 边界测试\n");
    printf("尝试删除索引0（应该提示使用removeFirst）:\n");
    removeIndex(head, 0);
    
    printf("尝试访问超出范围的索引:\n");
    ListNode *result = get(head, 10);
    if(result == NULL) {
        printf("正确处理了索引超出范围的情况\n");
    }
    printf("\n");
    
    // 10. 最终状态
    printf("10. 最终链表状态:\n");
    printList(head);
    printf("\n");
    
    // 11. 清理内存
    printf("11. 清理内存\n");
    freeList(head);
    printf("内存清理完成\n");
    
    printf("\n=== 测试完成 ===\n");
    return 0;
}