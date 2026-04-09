#include <stdio.h>
#include <stdlib.h>

void printArray(int *Array,int size);
int randAccess(int *Array,int size);
int* insert(int *Array,int size,int index,int value);
int* deleteElement(int *Array,int size,int index);
int find(int *Array,int size,int value);


int main(void)
{
    int * arr = (int *)malloc(sizeof(int)*5);
    //初始化
    //两种赋值,等价
    for(int i = 0; i <5; i++)
    {
        *(arr+i) = 0;
        printf("arr[%d] address: %p\n",i,arr+i);
    }
    printf("原数组:\n");
    printArray(arr,5);
    // for(int i = 0; i <5; i++)
    // {
    //     arr[i] = i;
    //     printf("arr[%d] address: %p\n",i,arr+i);
    // }
    // printArray(arr,5);
    
// 测试插入
    int *newArr = insert(arr, 5, 2, 99);
    printf("插入后:\n");
    printArray(newArr, 6);
    
    free(arr);
    
    free(newArr);
    
    return 0;


}





void printArray(int *Array,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i,Array[i]);
    }
}

int randAccess(int *Array,int size)
{
    //得到随机数
    int index = rand() % size;
    int random = Array[index];
    return random;
}

int* insert(int *Array,int size,int index,int value)
{
    if(index<0||index>size)
    {
       return NULL;
    }
    //统一按扩容考虑

    int * newArray = (int *)malloc(sizeof(int)*2*size);
    for(int i = 0; i < index; i++)
    {
        newArray[i] = Array[i];
    }

    newArray[index] = value;
    for(int i = index;i <size;i++)
    {
        newArray[i+1] = Array[i];
    }

    return newArray;
}

//删除
int* deleteElement(int *Array, int size, int index)
{
    if(index<0||index>=size){
       return NULL;
    }
    int * newArray = (int *) malloc(sizeof(int) * (size-1));
    for(int i = 0; i < index; i++){
        newArray[i] = Array[i];
    }
    for(int i = index; i<size-1; i++){
        newArray[i] = Array[i+1];
    }
    return newArray;
    
}

//查找
int find(int *Array,int size,int value)
{
    for(int i = 0; i < size; i++){
        if(Array[i] == value){
            return i;
        }
    }
    return -1;
}