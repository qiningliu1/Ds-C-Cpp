/**
 * 这部分通过封装队列实现BFS
 */

#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define MAX_SIZE 1000

typedef struct 
{
	int front,rear;
	int capacity;
	// TreeNode* node;这种写法只能存储一个节点
	TreeNode** nodes;//指向节点指针数组
} queue;

// //法二，结构体内包含固定数组
// typedef struct
// {
// 	// TreeNode tArray[MAX_SIZE];//类比int arr[size];与int* arr[size]有何区别
// 	TreeNode* tArray[MAX_SIZE];//使用指针数组比对象数组更灵活
// 	int front,rear;
// } queue2;

//构造函数

queue* createQueue(int capacity)
{
	queue* newQueue = (queue*)malloc(sizeof(queue));//思考为何这样写
    if(newQueue == NULL) {
        printf("队列结构体内存分配失败\n");
        return NULL;
    }
	newQueue->front = 0;
	newQueue->rear = 0;
	newQueue->capacity = capacity;
	newQueue->nodes = (TreeNode**)malloc(sizeof(TreeNode*) * capacity);
    if(newQueue->nodes == NULL) {
        printf("队列数组内存分配失败\n");
        free(newQueue);
        return NULL;
    }
    return newQueue;
}

//析构函数
void destroy(queue* q)
{
	if(q!=NULL)
	{
		free(q->nodes);
		free(q);
		printf("队列已销\n");
	}

}



void enqueue(queue* q, TreeNode* node)
{
	if(q->rear >= q->capacity)
	{
		printf("队列已满\n");
		return;
	}
	q->nodes[q->rear++] = node;
}

TreeNode* dequeue(queue* q)
{
	if(q->front >= q->rear)
	{
		return NULL;
	}
	TreeNode* deq = q->nodes[q->front];
	q->front++;
	return deq;

}


int bfs_depth(TreeNode* root)
{
	if(root == NULL) {
        return 0;
    }
	queue* q = createQueue(MAX_SIZE);
	//入队
	// TreeNode** tArray = q->nodes;
	// tArray[(q->rear)++] = root;

	enqueue(q,root);


	//初始深度
	int depth = 1;

	printf("开始BFS遍历...\n");

	//开始遍历
	while(q->front < q->rear)
	{
		
		//当前这一层的元素数，且遍历内容不包括后续左右子树后入队的元素
		int size = q->rear - q->front;
		printf("第%d层有%d个节点\n", depth, size);
		for (int i = 0; i <size; ++i)
		{
			//出队检测
			TreeNode* current = dequeue(q);
			printf("  访问节点：%d\n", current->val);
			//如果是叶节点就返回
			if(current->left == NULL && current->right == NULL)
			{
				printf("找到叶子节点:%d,深度:%d\n", current->val, depth);
				destroy(q);
				// depth--;//思考下何时--
				return depth;
			}
			//把出队元素的左右子节点入队，为下一层遍历预备好
			if(current->left != NULL){
				enqueue(q,current->left);
			}
			if(current->right != NULL){
				enqueue(q,current->right);
			}
		}
		//出for循环结束遍历这一层
		depth++;
	}
	// 理论上不会到达这里（除非树为空）
    destroy(q);
    return depth - 1;
}

// 测试函数
void test_bfs_queue() {
    printf("=== BFS队列测试 ===\n");
    
    // 创建测试树
    //       3
    //      / \
    //     9   20
    //    /   /  \
    //   1   15   7
    TreeNode* root = newTreeNode(3);
    TreeNode* n9 = newTreeNode(9);
    TreeNode* n20 = newTreeNode(20);
    TreeNode* n1 = newTreeNode(1);
    TreeNode* n15 = newTreeNode(15);
    TreeNode* n7 = newTreeNode(7);
    
    root->left = n9;
    root->right = n20;
    n9->left = n1;
    n20->left = n15;
    n20->right = n7;
    
    printf("二叉树结构:\n");
    printf("       3\n");
    printf("      / \\\n");
    printf("     9   20\n");
    printf("    /   /  \\\n");
    printf("   1   15   7\n\n");
    
    int result = bfs_depth(root);
    printf("BFS最短路径深度：%d\n", result);
    
    // 释放树内存
    freeTreeNode(root);
}

int main() {
    test_bfs_queue();
    return 0;
}