#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #define MAX_SIZE 100
/**
拉链寻址法
1.每个桶是一个链表
2.链表里边是键值对
3.链表里边是结构体
4.结构体里边是键值对
 */

typedef struct Pair 
{
    int key;
    char* value;
}Pair;

typedef struct Node 
{
    Pair *pair;
    struct Node *next;
}Node;

typedef struct LinkedHashMap
{
    int size;//键值对数量
    int capacity;//桶数量，即哈希表容量大小；
    double loadThreshold;//负载阙值，超过这个值就扩容
    int extendFactor;//扩容因子，扩容倍数
    Node ** buckets;//动态指针数组
}LinkedHashMap;

/*构造函数*/
LinkedHashMap* newLinkedHashMap()
{   
    //先动态分配内存
    LinkedHashMap * map = (LinkedHashMap*)malloc(sizeof(LinkedHashMap));
    //初始化
    map->size = 0;
    map->capacity = 4;
    map->buckets = (Node**)malloc(sizeof(Node*) * map->capacity);
    map->loadThreshold = 0.75;//参考java的hashmap
    map->extendFactor = 2;//扩容倍数
    //初始化每个桶
    for(int i = 0; i <map->capacity;i++)
    {
        map->buckets[i] = NULL;
    }
    return map;
}

/*析构函数*/
void deleteLinkedHashMap(LinkedHashMap* map)
{
    //释放每个桶
    for(int i = 0; i <map->capacity;i++)
    {
        Node * temp = map->buckets[i];
        //释放每个桶里的节点
        while(temp!=NULL)
        {
            //先保存下一个节点
            Node * next = temp->next;
            free(temp->pair->value);//有必要吗,如果没有malloc是否需要free？
            free(temp->pair);
            free(temp);
            temp = next;
        }
    }
    //由于构造函数中malloc了buckets，所以这里需要free
    free(map->buckets);
    free(map);
    // map = NULL;//注意这里map是函数参数，局部变量，修改它不会影响外部
}

/*哈希函数*/
int hashFunction(int key, LinkedHashMap * map)
{
    return abs(key)%map->capacity;
}

/*负载因子*/
double loadFactor(LinkedHashMap * map)
{
    return (double)map->size/(double)map->capacity;
}

/*扩容*/
void resize(LinkedHashMap* map)
{
    //暂存旧数据
    int oldCapacity = map->capacity;
    //思考为什么用二级指针？暂存原哈希表
    Node ** oldBuckets = map->buckets;

    //计算新容量
    map->capacity *= map->extendFactor;
    //重新分配
    //把新申请内存的地址写入buckets
    map->buckets = (Node**)malloc(sizeof(Node*) * map->capacity);
    //初始化新桶,思考为啥不能直接赋值？
    for(int i = 0; i <map->capacity; i++)
    {
        map->buckets[i] = NULL;
    }
    map->size = 0;
    //将旧的数据搬移
    for(int i = 0; i <oldCapacity; i++){
        Node * bucket = oldBuckets[i];
        //把每个桶里的链表搬进来
        while(bucket!=NULL)
        {   
            //先保存下个节点
            Node * next = bucket->next;
            put(map,bucket->pair->key,bucket->pair->value);
            //从里到外层层释放
            free(bucket->pair->value);
            free(bucket->pair);
            free(bucket);
            bucket = next;
        }
    }
    //释放旧的桶
    free(oldBuckets);
}




/*增*/
void put(LinkedHashMap * map, int key, const char* value)
{
    //当负载因子超过阙值时，扩容
    if(loadFactor(map) >= map->loadThreshold)
    {
        resize(map);
    }
    //计算哈希值
    int index = hashFunction(key,map);
    //遍历桶
    //1.若遇到相同key，为了保证唯一性，更新value
    Node * current = map->buckets[index];
    while(current!=NULL)
    {
        if(current->pair->key == key){
            //显释放旧内存
            free(current->pair->value);
            //再分配新内存
            //字符串深拷贝
            current->pair->value = malloc(strlen(value)+1);
            strcpy(current->pair->value,value);
            return; 
        }
        //没找到就继续遍历链表
        current = current->next;
    }
    //2.若没找到相同key,添加到链表头部
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->pair = (Pair*)malloc(sizeof(Pair));
    newNode->pair->key = key;
    newNode->pair->value = malloc(strlen(value)+1);
    strcpy(newNode->pair->value,value);
    //添加到头节点之前
    newNode->next = map->buckets[index];
    //将新节点地址写入桶
    map->buckets[index] = newNode;
    map->size++;
}

/*删除操作*/
void removeItem(LinkedHashMap * map, int key)
{
    //计算哈希值
    int index = hashFunction(key,map);
    //注意需要考虑前后位置，所以需要记录前一个节点
    Node * current = map->buckets[index];
    Node * prev = NULL;
    //遍历
    while(current!=NULL)
    {
        if(current->pair->key == key){
            //如果删除的是头节点
            if(prev == NULL){
                map->buckets[index] = current->next;
            }
            else{
                //删除中间节点
                prev->next = current->next;
            }
            //释放内存
            free(current->pair->value);
            free(current->pair);
            free(current);
            map->size--;
            return;            
        }
        //这一节点没找到就继续迭代
        prev = current;
        current = current->next;
    }
    //遍历完还没找到就返回
    printf("key %d not found\n",key);
}

char* get(LinkedHashMap* map,int key)
{
	int index = hashFunction(key,map);
	Node* current = map->buckets[index];

	while(current != NULL)
	{
		if(current->pair->key == key)
		{
			return current->pair->value;
		}
		current = current->next;
	}
	return NULL;//未找到
}