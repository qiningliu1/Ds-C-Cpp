#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>
#include <stdlib.h>

/**二叉树节点结构体 */
typedef struct TreeNode
{
    int val;
    int height;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

/**构造函数 */
TreeNode * newTreeNode(int val){
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
	//malloc失败检查
	if(newNode == NULL)
	{
		printf("malloc failed\n");
		return NULL;
	}
	newNode->val = val;
	newNode->height = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/**析构函数 */
void freeTreeNode(TreeNode * root)
{
    if(root == NULL)
    {
        return;
    }
    freeTreeNode(root->left);
    freeTreeNode(root->right);
    free(root);
}

#endif