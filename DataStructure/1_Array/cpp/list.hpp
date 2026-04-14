#pragma once

class myArrayList
{
    private:
    int *arr;
    //记录当前元素个数
    int size;
    //记录当前容量
    int capacity;

    //默认初始容量
    static const int INIT_CAPACITY = 1;

    public:
    myArrayList()
    {
        this->arr = new int[INIT_CAPACITY];
        this->size = 0;
        this->capacity = INIT_CAPACITY;
    }
    myArrayList(int capacity):size(0),capacity(capacity)
    {
        this->arr = new int[capacity];
    }

    ~myArrayList()
    {
        if(arr!=nullptr)
        delete[] arr;
        arr = nullptr;
    }
    //检查索引越界
    //检查是否索引位置可以存在元素
    void checkElement(int index);
    //检查索引位置是否可以添加元素
    void checkPosition(int index);
    //扩容
    void reSize();


    //增
    void addFirst(int val);
    void addIndex(int val,int index);
    void addLast(int val);

    //删
    int removeFirst();
    int removeIndex(int index);
    int removeLast();

    //查
    int get(int index);

    //改
    void set(int index,int val);

    //工具方法
    int getSize();

    //判断空与否
    bool isEmpty();
    
    //打印
    void print();
};