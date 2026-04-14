#include <iostream>
#include <stdexcept>
#include "list.hpp"

//检查索引越界
    //检查是否索引位置可以存在元素
void myArrayList::checkElement(int index)
{
    if(index<0 || index>=size)
    {
        throw std::out_of_range("Index out of range");
    }
};
    //检查索引位置是否可以添加元素
void myArrayList::checkPosition(int index)
{
    if(index<0 || index>size)
    {
        throw std::out_of_range("Index out of range");
    }
};

void myArrayList::reSize()
{
    if(size==capacity)
    {
        int *newArr = new int[capacity*2];
        //拷贝
        for(int i = 0; i < size; i++){
            newArr[i] = arr[i];
        }
        //先释放原指针指向旧的堆内存
        delete[] arr;
        arr = newArr;
        capacity *= 2;
    }
}


    //增
void myArrayList:: addFirst(int val)
{
    checkPosition(0);
    addIndex(val,0);
}

void myArrayList:: addIndex(int val,int index)
{   
    //看看索引是否越界
    checkPosition(index);
    //看看容量
    if(size == capacity)
    {
        reSize();
    }
    //data[index]->data[index+1]
    for(int i = size-1; i >=index ; i--)
    {
        arr[i+1] = arr[i];
    }
    //插入
    arr[index] = val;
    size++;
}
void myArrayList:: addLast(int val)
{
    checkPosition(size);
    addIndex(val,size);
}

    //删
int myArrayList:: removeFirst()
{
    checkElement(0);
    return removeIndex(0);
}
int myArrayList:: removeIndex(int index)
{
    checkElement(index);
    int val = arr[index];
    for(int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    size--;
    return val;
}
int myArrayList:: removeLast()
{
    checkElement(size-1);
    return removeIndex(size-1);
}

    //查
int myArrayList:: get(int index)
{
    checkElement(index);
    return arr[index];
}

    //改
void myArrayList:: set(int index,int val)
{
    checkElement(index);
    arr[index] = val;
}

    //工具方法
int myArrayList:: getSize()
{
    return size;
}

    //判断空与否
bool myArrayList:: isEmpty()
{
    return size == 0;
}
    
    //打印
void myArrayList:: print()
{   
    if(!isEmpty()){
        for(int i = 0; i <size; i++)
        {
            std::cout << "Index: " << i << "Value is " << arr[i] << std::endl;    
        }
    }
    else
    {
        std::cout << "The list is empty" << std::endl;
    }
}
