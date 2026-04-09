#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

/**
先展示DFS求最短路径
 */

#define MAX_SIZE 1000
#define MIN_DEPTH INT_MAX//给一个初始最大值，防止被覆盖

int minDepth = MIN_DEPTH;
int current_depth = 0;


int dfs_minDepth(TreeNode* root)
{
    if(root == NULL){
        return 0;
    }
    traverse(root);
    return minDepth;
}

void traverse(TreeNode* root)
{
    if(root == NULL)
    {
        return;
    }
    //前序位置
    //刚进入前序位置增加深度
    current_depth++;
    //如果是叶子节点，更新最小深度
    if(root->left == NULL && root->right == NULL)
    {
        minDepth = min(minDepth,current_depth);
        current_depth--;
        return;//叶节点直接返回
    }
    traverse(root->left);
    traverse(root->right);
    //后序位置，回到调用节点(上一层)，减少深度
    current_depth--;
}

/**
BFS求最短路径
 */

int bfs_minDepth(TreeNode* root)
{	
	if(root == NULL)
	{
		return 0;
	}
	//队列初始化
	//创建队列，用于存储TreeNOde*数组
    TreeNode** q = (TreeNode**)malloc(sizeof(TreeNode*) * MAX_SIZE);
    //内存分配失败
    if(q == NULL)
    {
        printf("内存分配失败\n");
        return -1;
    }
    int front = 0;
    int rear = 0;

    //加入根节点
    q[rear++] = root;
	//初始化深度，加入根节点为1
	int depth = 1; 

    

	while(front<rear)
	{
        //当前层队列大小
        int size = rear - front;

		//遍历当前层，注意此时这个size是这一层的原始情况
		for(int i = 0; i < size; i++)
		{
			//出队
			TreeNode* cur = q[front];
			front++;
			//判断是否到达叶节点
			if(cur->left == NULL && cur->right == NULL)
			{
                free(q);
				return depth;
			}
			//若不是叶子节点，入队
			if(cur->left != NULL)
			{
            q[rear++] = cur->left;
			}
			if(cur->right != NULL)
			{
            q[rear++] = cur->right;
			}
		}
		//这一层遍历完
		depth++;
	}

	free(q);
	return depth;

}
