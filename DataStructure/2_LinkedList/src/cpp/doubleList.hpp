#pragma once

class DoubleList
{
    private:
    //链表中有节点,结构体其实是个类型，我们自己定义的类似int,char,float等
    struct ListNode{//cpp只定义结构体类型即可
        int val;
        ListNode *prev;
        ListNode *next;
    //结构体构造函数
    ListNode(int value):val(value),prev(nullptr),next(nullptr){}//结构体构造函数
    //注，编译器不会自动生成无参构造函数
    ListNode():val(0),prev(nullptr),next(nullptr){}

    };
    

    //头尾指针
    ListNode *head;
    ListNode *last;
    
    int size;

    public:
    //构造函数,创建一个空链表，其中头节点，尾节点和内部结构体（调用无参结构体构造函数）都为空
    //DoubleList():head(nullptr),last(nullptr),size(0){}

    //构造函数初始化虚拟头尾节点

    DoubleList():size(0)
    {

        this->head = new ListNode();
        this->last = new ListNode();
        head->next = last;
        last->prev = head;
        
    }

    ~DoubleList()
    {
        while(head!=nullptr){
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }
    }


    //增，现在可以直接访问类成员变量head和last
    void addFirst(int val);
    void addIndex(int val,int index);
    void addLast(int val);

    //删
    int removeFirst();
    int removeIndex(int index);
    int removeLast();

    //查
    ListNode * get(ListNode * head, int index);

    //改
    void set(ListNode * head, int index, int val);
    
};