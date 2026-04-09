#include <stdio.h>
#include <stdlib.h>
#include "btree.h"


#define MAX_SIZE 100

//全局变量
//辅助数组，用于存储遍历成员
int arr[MAX_SIZE];


/**层序遍历*/

int * levelOrder(TreeNode * root, int * size)
{
	//辅助队列
	int front, rear;
	TreeNode * node;
	TreeNode **queue;

	//初始化
	queue = (TreeNode**)malloc(sizeof(TreeNode*) * MAX_SIZE);
	front = 0, rear = 0;
	//加入根节点
	queue[rear++] = root;//等价queue[front] = root; rear++;

	//辅助打印数组
	int * arr;
	arr = (int*)malloc(sizeof(int) * MAX_SIZE);
	//数组索引初始化
	int index = 0;

	//开始遍历
	while(front < rear)//队列非空，一旦空说明遍历完成
	{
		//当前头节点
		node = queue[front];
		front++;

		//保存
        arr[index] = node->val;
        index++;

        //判断入队
        if(node->left != NULL)
        {
        queue[rear++] = node->left;
        }
        if(node->right != NULL)
        {
        queue[rear++] = node->right;
        }
	}

    //更新数组长度的值
    *size = index;
    // 只有在显著节省内存时才realloc
    if(index < MAX_SIZE / 2) {  // 节省超过50%时才优化
        int *temp = realloc(arr, sizeof(int) * index);
        if(temp != NULL) arr = temp;
    }

	free(queue);
	return arr;
}
