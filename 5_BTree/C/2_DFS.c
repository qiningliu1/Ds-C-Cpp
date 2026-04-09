#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

#define MAX_SIZE 100

//全局变量
//辅助数组，用于存储遍历成员
int arr[MAX_SIZE];

/** 前序遍历 */

void preOrder(TreeNode* root, int *size)
{
	if(root == NULL)
	{
		return;
	}
	//前序位置
	//后++？
	arr[(*size)++] = root->val;
	preOrder(root->left,size);//这个size是多少
	preOrder(root->right,size); 
}

/**中序遍历*/

void inOrder(TreeNode* root, int * size)
{
	if(root == NULL)
	{
		return;
	}
	inOrder(root->left,size);
	//中序位置
	arr[(*size)++] = root->val;
	inOrder(root->right,size);
}

/**后序遍历*/

void postOrder(TreeNode * root, int * size)
{
	if(root == NULL)
	{
		return;
	}
	postOrder(root->left,size);
	postOrder(root->right,size);
	arr[(*size)++] = root->val;
}

int main(void)
{
    TreeNode *root = newTreeNode(1);
    TreeNode *left = newTreeNode(2);
    TreeNode *right = newTreeNode(3);
    root->left = left;
    root->right = right;
    
    int size = 0;  // 初始大小为0
    preOrder(root, &size);  // 传递 size 的地址
    
    printf("遍历结果: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // 输出: 遍历结果: 1 2 3
    
    return 0;
}