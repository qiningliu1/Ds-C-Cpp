#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //bool类型
/**
 * 基于链表实现
 */

//注意语法定义要先声明才可以自引用
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *top;
    // ListNode *bottom; 栈不需要这个，因为栈是单向的
    int size;//栈的大小
} MyListStack;

//构造函数

ListNode* createNode(int val)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    if(node == NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

MyListStack* newListStack()
{
    //空壳

    MyListStack *stack = (MyListStack*)malloc(sizeof(MyListStack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

//析构函数
void deleteListStack(MyListStack*stack)
{
    //每个节点free掉
    while(stack->top)
    {
        ListNode *temp = stack->top->next;
        free(stack->top);
        stack->top = temp;
    }
    free(stack);//悬空指针
    stack = NULL;
}

//获取长度
int size(MyListStack *stack)
{
    return stack->size;
}

//判断栈是否为空
bool isEmpty(MyListStack *stack)
{
    return stack->size == 0;
}

//入栈
void push(MyListStack *stack, int val)
{
    ListNode *node = createNode(val);
    //node->top,新增节点指向栈顶
    node->next = stack->top;
    //调整栈顶指针
    stack->top = node;
    stack->size++;
}

//访问栈顶元素
int peek(MyListStack *stack)
{
    if(stack->top == NULL)
    {
        printf("栈为空\n");
        return -1;
    }
    return stack->top->val;
}

//出栈
int pop(MyListStack * stack)
{
    if(isEmpty(stack))
    {
        printf("栈为空\n");
        return -1;
    }
    //新栈顶元素
    ListNode * top = stack->top->next;
    //旧栈顶返回值
    int val = stack->top->val;
    free(stack->top);
    stack->top = top;
    stack->size--;
    return val;
}

void printStack(MyListStack * stack)
{
    if(isEmpty(stack))
    {
        printf("栈为空\n");
        printf("地址是%p\n", stack);
        return;
    }
    ListNode * current = stack->top;
    while(current!=NULL)
    {
        printf("当前值是%d\n",current -> val);
        printf("当前地址%p\n",current);
        current = current->next;
    }

}

int main(void)
{
    MyListStack *stack = newListStack();
    printf("栈顶值是%d\n",peek(stack));
    printf("栈顶地址是%p\n", stack->top);
    printf("ListNode* 大小: %zu 字节\n", sizeof(stack->top));//这个是ListNode*指针大小-8
    printf("ListNode* 大小: %zu 字节\n", sizeof(ListNode));//这个是结构体-16
    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);
    push(stack,5);
    printStack(stack);
    printf("栈顶元素是%d\n",peek(stack));
    printf("出栈元素是%d\n",pop(stack));
    printStack(stack);
    deleteListStack(stack);
    //一定记得置空，因为我们析构函数是一级指针，在函数内部置空，外部main还是悬空指针
    stack = NULL;
    printStack(stack);
    printf("地址是%p\n",stack);
    return 0;
}