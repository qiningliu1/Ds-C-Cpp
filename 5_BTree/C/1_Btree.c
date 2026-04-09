#include <stdio.h>
#include <stdlib.h>

/**二叉树节点结构体 */

typedef struct TreeNode{
    int val;
    int height;
    struct TreeNode * left;
    struct TreeNode * right;
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

int main(void)
{
	TreeNode *n1 = newTreeNode(1);
	TreeNode *n2 = newTreeNode(2);
    TreeNode *n3 = newTreeNode(3);
	TreeNode *n4 = newTreeNode(4);
	TreeNode *n5 = newTreeNode(5);

	//构建节点之间的引用
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2 ->right = n5;

	//插入与删除节点
	TreeNode * p = newTreeNode(0);
	n1->left = p;
	p->left = n2;

    //删除节点
	n1->left = n2;
	free(p);

}