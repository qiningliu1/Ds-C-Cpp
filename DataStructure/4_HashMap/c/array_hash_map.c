#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // 定义哈希表大小
/*
定义键值对结构体
*/
typedef struct {
    int key;
    char * value;
} Pair;

//基于数组实现
typedef struct {
//这个结构体里边是一个数组，数组里边是Pair结构体
    Pair *buckets[MAX_SIZE];
} ArrayHashMap;

/*构造函数*/
ArrayHashMap* newArrayHashMap()
{
    ArrayHashMap *map = (ArrayHashMap*)malloc(sizeof(ArrayHashMap));
    //初始化赋值
    for(int i = 0; i <MAX_SIZE;i++){
        map->buckets[i] = NULL;
    }
    return map;
}

/*析构函数*/
void deleteArrayHashMap(ArrayHashMap * map)
{
    //释放每个桶
    for(int i = 0; i<MAX_SIZE;i++){
        if(map->buckets[i] != NULL){
            free(map->buckets[i]->value);
            free(map->buckets[i]);
        }
    }
    free(map);
    map = NULL;
}

/*哈希函数-简单的取模运算*/
int hashFunction(int key)
{
    return abs(key)%MAX_SIZE;
}




//增加键值对
void put(ArrayHashMap * map, int key, char * value)
{
    Pair *pair = (Pair*)malloc(sizeof(Pair));
    pair->key = key;
    
    //这只是复制指针,两个变量指向同一个内存地址，是浅拷贝
    //如果value修改或释放，你的数据就会出问题
    // pair->value = value;

    //深拷贝
    //strlen只计算可见字符，不包括结束符\0，必须+1为字符串结束符分配空间
    pair->value = (char*)malloc(strlen(value)+1);
    //将源字符串value复制到目标地址pair->value
    strcpy(pair->value,value);

    //加到数组里边
    //先计算索引
    int index = hashFunction(key);
    map->buckets[index] = pair;
}

/*删除操作*/
void removeItem(ArrayHashMap *map, int key)
{
    //先计算索引值
    int index = hashFunction(key);
    Pair *removed = map->buckets[index];
    free(removed->value);
    free(removed);
    map->buckets[index] = NULL;
}


