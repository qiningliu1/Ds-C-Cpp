/**
演示buckets不同数组指针的区别
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * next;
} Node;

//1.固定数组
typedef struct {
    Node * buckets[5];
} FixedHashMap;

//2.动态指针
typedef struct {
    Node ** buckets;//动态桶数组
    int capacity;
}DynamicHashMap;

void testComparison()
{
    //创建测试节点
    Node * node1 = malloc(sizeof(Node));
    Node * node2 = (Node*)malloc(sizeof(Node));//与前者有无区别？
    // Node * node3 = (Node)malloc(sizeof(Node));//这个应该不行吧，右边是强转为Node类型，左边是指针地址类型
    
    printf("node1 address: %p\n",node1);
    printf("node2 address: %p\n",node2);

    node1->data = 1;
    (*node2).data = 2;

    //固定数组方式
    FixedHashMap fixedMap;
    printf("FixedHashMap size: %ld\n",sizeof(fixedMap));
    printf("FixedHashMap address: %p\n",&fixedMap);
    // fixedMap.buckets = (Node**)malloc(sizeof(Node*)*5);
    fixedMap.buckets[0] = node1;
    //对比指针
    FixedHashMap *fixedMapPtr = &fixedMap;
    // (fixedMapPtr->buckets[0]+1) = node2;为何报错
    fixedMapPtr->buckets[1] = node2;
    fixedMapPtr->buckets[2] = NULL;
    printf("fixedMapPtr address: %p\n",fixedMapPtr);//指针数组的地址
    printf("fixedMapPtr->buckets address: %p\n",fixedMapPtr->buckets);//与指针数组地址相同
    //注意buckets【0】与前者不同
    printf("fixedMapPtr->buckets[0] address: %p\n",fixedMapPtr->buckets[0]);//与指针数组地址相同，node1
    printf("fixedMapPtr->buckets[0]+1 address: %p\n",fixedMapPtr->buckets[0]+1);
// 类型：Node*，值：Node地址 + sizeof(Node)
//如果不好理解可以代换为int * +1进行类比
    
    //为啥计算出来地址16进制相差不是8对应一个Node*的大小？

    printf("fixedMapPtr->buckets[1] address: %p\n",fixedMapPtr->buckets[1]);
    printf("fixedMapPtr->buckets[2] address: %p\n",fixedMapPtr->buckets[2]);


printf("buckets[0]的地址: %p\n", &fixedMapPtr->buckets[0]); // 0xc13bfffab0
printf("buckets[1]的地址: %p\n", &fixedMapPtr->buckets[1]); // 0xc13bfffab8



    //动态指针方式
    DynamicHashMap dynamicMap;
    dynamicMap.capacity = 5;
    //思考下边两者区别
    // dynamicMap.buckets = malloc(sizeof(Node)*dynamicMap.capacity);
    dynamicMap.buckets = (Node**)malloc(sizeof(Node*)*dynamicMap.capacity);
    printf("DynamicHashMap size: %ld\n",sizeof(dynamicMap));//这里计算出来是16，并不是8（Node**） + 4（int）
    printf("DynamicHashMap address: %p\n",&dynamicMap);//随机地址，这是栈地址吧
    printf("DynamicHashMap buckets address: %p\n",dynamicMap.buckets);
    printf("DynamicHashMap buckets[0] address: %p\n",dynamicMap.buckets[0]);
    // &dynamicMap.buckets[0] = node1;//   这是啥

    //*dynamicMap.buckets[0] = node1;
    dynamicMap.buckets[0] = node1;
    dynamicMap.buckets[1] = node2;
    dynamicMap.buckets[2] = NULL;

    //访问方式对比
    printf("FixedHashMap[0] data: %d\n",fixedMap.buckets[0]->data);
    printf("dynamicHashMap[0] data: %d\n",dynamicMap.buckets[0]->data);

    //地址计算
    printf("固定数组: buckets地址 = %p, buckets+1地址 = %p\n",
    (Node*)fixedMap.buckets,(Node*)(fixedMap.buckets+1));//这里相差8字节，对应Node*大小
    
    printf("固定数组: buckets地址=%p, buckets[1]地址=%p\n", 
    (void*)fixedMap.buckets, (void*)&fixedMap.buckets[1]);

    printf("动态数组: buckets地址 = %p, buckets[0]地址 = %p\n",
    (void*)dynamicMap.buckets,(void*)&(dynamicMap.buckets[0]));
    free(node1);
    free(node2);
    free(dynamicMap.buckets);
}

void otherTest()
{
    //创建测试节点
    int a = 10;
    int *b = &a;
    int **b1 = &b;
    // int **c =&a;//报错
    
    //思考下边两者区别
    // int * a1[5] = malloc(sizeof(int)*5);//为啥报错
    
    //可以看看初始化后的区别
    // int a1[5];
    int a1[5] = {1,2,3,4,5};
    int *a2 = malloc(sizeof(int)*5);
    int **a3 = malloc(sizeof(int*)*5);//内存1
    //注意下边赋值后，上边动态分配的为内存泄漏
    a3 = &a2;//关键❌ 但内存泄漏！丢失了内存1的地址

    printf("a的值: %d\n",a);
    printf("a的地址: %p\n",&a);
    printf("b的值: %p\n",b);//a的地址
    printf("b自己地址: %p\n",&b);//b这个指针的地址
    printf("b1的值: %p\n",b1);//b这个指针的地址
    printf("b1解引用: %p\n",*b1);//a的地址

//如果a1初始化后，成员的地址是连续的
//如果a1未初始化，成员的地址是随机垃圾值
    printf("a1的值: %p\n",a1);//数组名，表示数组首元素地址
    printf("a1自己地址: %p\n",&a1);//还是数组地址
    printf("a1[0]地址: %p\n",&a1[0]);//数组首元素地址，随机垃圾值
    printf("a1[1]地址: %p\n",&a1[1]);//数组第二个元素地址，随机垃圾值
    printf("a1+1地址: %p\n",a1+1);//是数组名地址根据数组类型偏移
    printf("--------------------------------\n");
    printf("a2的值: %p\n",a2);//随机地址,分配在堆上
    printf("a2自己地址: %p\n",&a2);//a2这个指针的地址

    printf("--------------------------------\n");
    printf("a3的值: %p\n",a3);//被赋值为a2的地址
    printf("a3自己地址: %p\n",&a3);//a3这个指针的地址
    printf("a3解引用: %p\n",*a3);//透过a2这个指针的地址取到a2的内容
    printf("*a3+1地址: %p\n",*a3+1);//a2这个指针的地址+1，根据int类型偏移
    printf("*a3+1地址: %p\n",a3+1);// 类型：int**，值：(&a2)+8字节 ← 危险！指向无效内存
    printf("*a3+1地址: %p\n",*(a3+1));//解引用无效内存 ← 未定义行为！可能崩溃
    printf("a3解引用: %p\n",*a3);//不变
}


int main(void){
    testComparison();
    printf("--------------------------------\n");
    otherTest();
    return 0;
}