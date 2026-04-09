#include "doubleList.hpp"
#include <stdexcept>



void DoubleList::addFirst(int val)
{   //h->1>2>3->l为例
    ListNode *newNode = new ListNode(val);
    ListNode *temp = head->next;
    newNode->next = temp;
    temp->prev = newNode;

    head->next = newNode;
    newNode->prev = head;

    size++;
};

void DoubleList::addIndex(int val, int index)
{
    if(index<0||index>size){
        throw std::out_of_range("Index out of range");
    }
    
    if(index == 0)
    {
        addFirst(val);
        return;
    }


    
    if(index==size){
        addLast(val);
        return;
    }

    ListNode * newNode = new ListNode(val);
    //找到index对应节点
    ListNode *temp = head;
    for(int i = 0;i<=index;i++){
        temp = temp->next;
    }
    //插入
    //prev->newNode->temp
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;

    size++;
}

void DoubleList::addLast(int val)
{
    ListNode * newNode = new ListNode(val);

    //<head>.....->temp->newNode-><last>
    last->prev->next = newNode;
    newNode->prev = last->prev;
    newNode->next = last;

    last->prev = newNode;
    size++;
}


//删除

int DoubleList::removeFirst()
{
    if(size<=0)
    {
        throw std::out_of_range("List is empty");
    }
    int val;
    ListNode *temp = head->next;
    val  = (*temp).val;

    
    head->next = (*temp).next;
    (*temp).next->prev = head;
    delete temp;//这个不是拷贝吗

    size--;
    return val;

}

int DoubleList::removeLast()
{
    if(size<=0){
        throw std::out_of_range("List is empty");
    }

    int val;
    ListNode *x = last->prev;
    ListNode *temp = x->prev;
    val = x->val;

    last->prev = temp;
    temp->next = last;

    delete x;//这个不是拷贝吗
    size--;
    return val;

    
}

int DoubleList::removeIndex(int index)
{
    if(index<0||index>=size)
    {
        throw std::out_of_range("Index out of range");
    }
    int val;
    ListNode *temp = head;
    for(int i = 0;i<=index;i++){
        temp = temp->next;
    }
    val = temp->val;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    size--;
    return val;
}